//
// Created by Michal Přikryl on 16.08.2025.
// Copyright (c) 2025 slynxcz. All rights reserved.
//
#pragma once

#include <cstddef>

enum PresubmitResponse {
    kPRLocalError,
    kPRRemoteError,
    kPRDontUpload,
    kPRUploadCrashDumpAndMetadata,
    kPRUploadMetadataOnly,
};


PresubmitResponse PresubmitCrashDump(const char* path, char* tokenBuffer, size_t tokenBufferSize);