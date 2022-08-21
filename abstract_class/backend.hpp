#include "baremetal_backend.hpp"
#include "linux_backend.hpp"

enum {
    LINUX_BACKEND,
    BAREMETAL_BACKEND,
} BackendTypes;

class Backend
{
    private:
        IOBase *IOBackend;
    public:
        bool Init(int UsrBackend);
        bool Finish();
        bool Write32();
        bool Read32();
        bool MaskWrite32();
        bool MaskPoll32();
        bool SwitchBackend(int NewBackend);
};

bool Backend::Init(int UsrBackend)
{
    if (UsrBackend == LINUX_BACKEND) {
        IOBackend = new LinuxIO();
    } else if (UsrBackend == BAREMETAL_BACKEND) {
        IOBackend = new BaremetalIO();
    } else {
        std::cout << "No backend available" << std::endl;
        return false;
    }

    return IOBackend->Init();
}

bool Backend::Finish()
{
    bool ret = IOBackend->Finish();
    delete IOBackend;
    return ret;
}

bool Backend::Write32()
{
    return IOBackend->IOWrite32();
}

bool Backend::Read32()
{
    return IOBackend->IORead32();
}

bool Backend::MaskWrite32()
{
    return IOBackend->IOMaskWrite32();
}

bool Backend::MaskPoll32()
{
    return IOBackend->IOMaskPoll32();
}

bool Backend::SwitchBackend(int NewBackend)
{
    bool ret = IOBackend->Finish();
    delete IOBackend;

    if (NewBackend == LINUX_BACKEND) {
        IOBackend = new LinuxIO();
    } else if (NewBackend == BAREMETAL_BACKEND) {
        IOBackend = new BaremetalIO();
    } else {
        std::cout << "No backend available" << std::endl;
        return false;
    }

    return IOBackend->Init();
}