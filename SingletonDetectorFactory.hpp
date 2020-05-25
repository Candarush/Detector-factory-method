#pragma once
#include <stdio.h>

using namespace std;


class DetectorActions { // Хранит в себе методы детектора
    public:
        virtual ~DetectorActions() {}
        virtual void Action() const = 0;
};

class Detector {
    public:
        virtual ~Detector(){};
        virtual DetectorActions* FactoryMethod() const = 0;
    
        void Foo() const;
};

class SingletonDetector
{
    private:
        static SingletonDetector* instance;
        SingletonDetector& operator=(SingletonDetector&);
        SingletonDetector(const SingletonDetector&);
        SingletonDetector(){};
    public:
        Detector* object;
        static SingletonDetector* GetInstance();
};


class FakeDetector : public DetectorActions {
    public:
        void Action() const override;
};

class MegaDetector : public DetectorActions {
    public:
        void Action() const override;
};

class FakeDetectorCreator : public Detector {
    public:
        DetectorActions* FactoryMethod() const override;
};

class MegaDetectorCreator : public Detector {
    public:
        DetectorActions* FactoryMethod() const override;
};
