//
// Created by Michal Přikryl on 12.06.2025.
// Copyright (c) 2025 slynxcz. All rights reserved.
//
#pragma once

#ifndef _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

#include <ISmmPlugin.h>
#include <igameevents.h>
#include <sh_vector.h>
#include <iserver.h>

class AcceleratorCS2 : public ISmmPlugin, public IMetamodListener
{
public:
    bool Load(PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late);
    bool Unload(char* error, size_t maxlen);
public:
    const char* GetAuthor();
    const char* GetName();
    const char* GetDescription();
    const char* GetURL();
    const char* GetLicense();
    const char* GetVersion();
    const char* GetDate();
    const char* GetLogTag();
private: // Hooks
    void GameFrame(bool simulating, bool bFirstTick, bool bLastTick);
    void StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);
};

#endif //_INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

PLUGIN_GLOBALVARS();
