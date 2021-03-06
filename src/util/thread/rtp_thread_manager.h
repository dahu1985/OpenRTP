/*
 ============================================================================
 * Name        : rtp_thread_manager.h
 * Author      : weizhenwei, <weizhenwei1988@gmail.com>
 * Date        : 2016.10.04
 *
 * Copyright (c) 2016, weizhenwei
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the {organization} nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Description : thread manager header file.
 ============================================================================
 */

#ifndef SRC_UTIL_THREAD_RTP_THREAD_MANAGER_H
#define SRC_UTIL_THREAD_RTP_THREAD_MANAGER_H

#include <pthread.h>
#include <list>

#include "rtp_datatype.h"
#include "rtp_thread.h"
#include "rtp_thread_mutex.h"
#include "rtp_thread_utils.h"

namespace openrtp {

class RtpThreadManager;
extern RtpThreadManager *g_ThreadManager;

class RtpThreadManager {
public:
    RtpThreadManager();
    ~RtpThreadManager();

    RTP_RESULT addThread(RtpThreadType eType, RtpThreadRoutine pRoutine);
    RtpThread *getThread(RtpThreadType eType);
    RTP_RESULT spawnThread(RtpThreadType eType);
    RTP_RESULT spawnAllThreads();

    RTP_RESULT killThread(RtpThreadType eType);
    RTP_RESULT killAllThreads();

    void cleanThread(RtpThreadType eType);
    void cleanAllThreads();

    static RtpThreadManager *singleton();

private:
    static RtpThreadManager *s_ThreadManager;

    typedef std::list<RtpThread*> RtpThreadList;
    typedef std::list<RtpThread*>::iterator RtpThreadListIterator;

    RtpThreadList m_listThreadList;
    RtpThreadMutex m_mtxThreadManagerMutex;
};

}  // namespace openrtp

#endif  // SRC_UTIL_THREAD_RTP_THREAD_MANAGER_H

