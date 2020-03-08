#pragma once
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define INVALID_PID -1
#define INVALID_MEMFILE -1
#define BAD_RETURN -1
#define MAX_FILENAME 256

namespace Mem
{
    unsigned int FileToArrayOfBytes(std::string filepath, char** pbuffer);
    namespace Ex
    {
        int GetProcessID(std::string processName);
        void ReadBuffer(int pid, off_t address, void* buffer, size_t size);
        void WriteBuffer(int pid, off_t address, void* value, size_t size);
        bool IsProcessRunning(int pid);
    }

    namespace In
    {
        int GetProcessID();
        bool ReadBuffer(off_t address, void* buffer, size_t size);
        bool WriteBuffer(off_t address, void* value, size_t size);
    }
}