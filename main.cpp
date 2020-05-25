#include "SingletonDetectorFactory.hpp"

int main()
{
    SingletonDetector* singleton = SingletonDetector::GetInstance();
    singleton->object = new FakeDetectorCreator();
    singleton->object -> Foo();
    singleton->object = new MegaDetectorCreator();
    singleton->object -> Foo();

    delete singleton->object;
    delete singleton;
    return 0;
}
