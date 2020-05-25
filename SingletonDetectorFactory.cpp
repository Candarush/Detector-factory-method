#include "SingletonDetectorFactory.hpp"

void Detector::Foo() const
{
    DetectorActions* detector = this->FactoryMethod();
    detector->Action();
    delete detector;
}

SingletonDetector* SingletonDetector::GetInstance()
{
    if(!instance)
        instance = new SingletonDetector();
    return instance;
}

SingletonDetector* SingletonDetector::instance = nullptr;

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
