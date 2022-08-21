#include <iostream>

#include "io_base.hpp"

class LinuxIO: public IOBase
{
    private:
        uint64_t BaseAddr;
        uint64_t NpiBaseAddr;
    public:
        LinuxIO() {std::cout << "Linux Constructor" << std::endl;};
        ~LinuxIO() {std::cout << "Linux Destructor" << std::endl;};
        bool Init();
        bool Finish();
        bool IOWrite32();
        bool IORead32();
        bool IOMaskWrite32();
        bool IOMaskPoll32();
};

bool LinuxIO::Init()
{
    BaseAddr = 0xDEADBEEF;
    NpiBaseAddr = 0xBADBEEF;

    std::cout << "Initialized Linux backend" << std::endl;

    return true;
}

bool LinuxIO::Finish()
{
    std::cout << "Closing linux backend" << std::endl;
    return false;
}

bool LinuxIO::IOWrite32()
{
    std::cout << "calling from LinuxIO Write32" << std::endl;

    return true;
}

bool LinuxIO::IORead32()
{
    std::cout << "Calling from LinuxIO Read32" << std::endl;

    return true;
}

bool LinuxIO::IOMaskWrite32()
{
    std::cout << "Calling from LinuxIO MaskWrite32" << std::endl;

    return true;
}

bool LinuxIO::IOMaskPoll32()
{
    std::cout << "Calling from LinuxIO MaskPoll32" << std::endl;

    return true;
}