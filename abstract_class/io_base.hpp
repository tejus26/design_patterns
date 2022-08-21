#ifndef IO_BASE_H
#define IO_BASE_H


class IOBase
{
    public:
        IOBase() {std::cout << "Base Contruct" << std::endl;};
        ~IOBase() {std::cout << "Base Destruct" << std::endl;};
        virtual bool Init() = 0;
        virtual bool Finish() = 0;
        virtual bool IOWrite32() = 0;
        virtual bool IORead32() = 0;
        virtual bool IOMaskWrite32() = 0;
        virtual bool IOMaskPoll32() = 0;
};

#endif /* IO_BASE_H */