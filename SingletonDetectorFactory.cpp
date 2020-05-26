#include "SingletonDetectorFactory.hpp"

void Detector::Foo() const
{
    DetectorActions* detector = FactoryMethod();
    detector->Action();
    delete detector;
}

SingletonDetector* SingletonDetector::GetInstance()
{
    if(!instance)
        instance = new SingletonDetector();
    return instance;
}

Detector* SingletonDetector::GetObject(Detector* detector)
{
    if (!object)
        object = detector;
    return object;
}

SingletonDetector::~SingletonDetector()
{
    delete object;
    delete instance;
};

SingletonDetector* SingletonDetector::instance = nullptr;
Detector* SingletonDetector::object = nullptr;

void FakeDetector::Action() const
{
    printf("Сработал FakeDetector!\n");
}

void MegaDetector::Action() const
{
    printf("Сработал MegaDetector!\n");
}

DetectorActions* FakeDetectorCreator::FactoryMethod() const
{
    return new FakeDetector();
}

DetectorActions* MegaDetectorCreator::FactoryMethod() const
{
    return new MegaDetector();
}
