/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __KEYSTORE_H__
#define __KEYSTORE_H__

#include <stdint.h>

// note state values overlap with ResponseCode for the purposes of the state() API
enum State {
    STATE_NO_ERROR      = 1,
    STATE_LOCKED        = 2,
    STATE_UNINITIALIZED = 3,
};

enum ResponseCode {
    NO_ERROR          =  STATE_NO_ERROR, // 1
    LOCKED            =  STATE_LOCKED, // 2
    UNINITIALIZED     =  STATE_UNINITIALIZED, // 3
    SYSTEM_ERROR      =  4,
    PROTOCOL_ERROR    =  5,
    PERMISSION_DENIED =  6,
    KEY_NOT_FOUND     =  7,
    VALUE_CORRUPTED   =  8,
    UNDEFINED_ACTION  =  9,
    WRONG_PASSWORD_0  = 10,
    WRONG_PASSWORD_1  = 11,
    WRONG_PASSWORD_2  = 12,
    WRONG_PASSWORD_3  = 13, // MAX_RETRY = 4
};

enum CommandNames {
    TEST = 0,
    GET = 1,
    INSERT = 2,
    DELETE = 3,
    EXIST = 4,
    SAW = 5,
    RESET = 6,
    PASSWORD = 7,
    LOCK = 8,
    UNLOCK = 9,
    ZERO = 10,
};

typedef uint8_t command_code_t;

command_code_t CommandCodes[] = {
    't', // TEST
    'g', // GET
    'i', // INSERT
    'd', // DELETE
    'e', // EXIST
    's', // SAW
    'r', // RESET
    'p', // PASSWORD
    'l', // LOCK
    'u', // UNLOCK
    'z', // ZERO
};

#endif