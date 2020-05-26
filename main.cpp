#include "SingletonDetectorFactory.hpp"

int main()
{
    SingletonDetector* singleton = SingletonDetector::GetInstance();
    singleton->GetObject(new FakeDetectorCreator()) -> Foo();
    singleton->GetObject(new MegaDetectorCreator()) -> Foo();

    delete singleton;
    return 0;
}
