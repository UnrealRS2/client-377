//
// Created by tyler on 9/28/2025.
//

#pragma once
#include <memory>
#include <thread>
#include <windows.h>

namespace nullpops::util {
    struct Runnable {
        virtual void run() = 0;
        virtual ~Runnable() = default;
    };

    // Thread wrapper
    class Thread {
    public:
        explicit Thread(std::shared_ptr<Runnable> task)
            : m_task(std::move(task)) {}

        void start() {
            m_thread = std::thread([t = m_task]() { t->run(); });
            if (m_thread.joinable()) {
                m_thread.detach();
            }
        }

        // Optional: set priority (platform-dependent)
        void setPriority(int priority) {
            if (m_thread.native_handle()) {
                ::SetThreadPriority(m_thread.native_handle(), priorityToWin(priority));
            }
        }

    private:
        std::shared_ptr<Runnable> m_task;
        std::thread m_thread{};
        static int priorityToWin(int javaPriority) {
            // Map Java 1-10 priority to Win32 THREAD_PRIORITY_* constants
            // Java: 1=MIN, 5=NORM, 10=MAX
            switch (javaPriority) {
                case 1: return THREAD_PRIORITY_LOWEST;
                case 10: return THREAD_PRIORITY_HIGHEST;
                default: return THREAD_PRIORITY_NORMAL;
            }
        }
    };

    inline void startThread(std::shared_ptr<Runnable> task, int priority = 5) {
        auto t = std::make_shared<Thread>(task);
        t->setPriority(priority);
        t->start();
    }
}
