#include <iostream>

#include "io_base.hpp"

class BaremetalIO: public IOBase
{
    private:
        uint64_t BaseAddr;
        uint64_t NpiBaseAddr;
    public:
        BaremetalIO() {std::cout << "BMetal Constructor" << std::endl;};
        ~BaremetalIO() {std::cout << "BMetal Destructor" << std::endl;};
        bool Init();
        bool Finish();
        bool IOWrite32();
        bool IORead32();
        bool IOMaskWrite32();
        bool IOMaskPoll32();
};

bool BaremetalIO::Init()
{
    BaseAddr = 0xDEADBEEF;
    NpiBaseAddr = 0xBADBEEF;

    std::cout << "Initialized Baremetal backend" << std::endl;

    return true;
}

bool BaremetalIO::Finish()
{
    std::cout << "Closing linux backend" << std::endl;
    return false;
}

bool BaremetalIO::IOWrite32()
{
    std::cout << "calling from BaremetalIO Write32" << std::endl;

    return true;
}

bool BaremetalIO::IORead32()
{
    std::cout << "Calling from BaremetalIO Read32" << std::endl;

    return true;
}

bool BaremetalIO::IOMaskWrite32()
{
    std::cout << "Calling from BaremetalIO MaskWrite32" << std::endl;

    return true;
}

bool BaremetalIO::IOMaskPoll32()
{
    std::cout << "Calling from BaremetalIO MaskPoll32" << std::endl;

    return true;
}