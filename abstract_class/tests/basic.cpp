#include <backend.hpp>

int main()
{
    Backend Be;

    Be.Init(LINUX_BACKEND);
    Be.Write32();
    Be.MaskWrite32();
    Be.SwitchBackend(BAREMETAL_BACKEND);
    Be.MaskPoll32();
    Be.Finish();
}