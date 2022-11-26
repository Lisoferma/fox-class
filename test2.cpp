#include "test.h"

using namespace std;

void testFoxConstructor() {
    {  
        Fox f;
        assert(f.getName()    == "Foxy");
        assert(f.isMale       == false);
        assert(f.getAge()     == 3);
        assert(f.getSpecies() == "vulpes vulpes");
        assert(f.prevailing—olor.red   == 207);
        assert(f.prevailing—olor.green == 87);
        assert(f.prevailing—olor.blue  == 0);
    }

    {   
        Fox* f = new Fox;
        assert(f->getName()    == "Foxy");
        assert(f->isMale       == false);
        assert(f->getAge()     == 3);
        assert(f->getSpecies() == "vulpes vulpes");
        assert(f->prevailing—olor.red   == 207);
        assert(f->prevailing—olor.green == 87);
        assert(f->prevailing—olor.blue  == 0);
    }

    {   
        Fox* f = new Fox("Autumn", true, 5, "vulpes lagopus", 255, 255, 255);
        assert(f->getName()    == "Autumn");
        assert(f->isMale       == true);
        assert(f->getAge()     == 5);
        assert(f->getSpecies() == "vulpes lagopus");
        assert(f->prevailing—olor.red   == 255);
        assert(f->prevailing—olor.green == 255);
        assert(f->prevailing—olor.blue  == 255);
    }

    {   Seconds s(0);
        assert(s.seconds() == 0);   }

    {
        Seconds s(42);
        assert(s.seconds() == 42);  }

    {
        Seconds s(59);
        assert(s.seconds() == 59);  }


    {   try {
        Seconds s(60);
        assert(0 && "s.setSeconds(60) Failed");
    }
    catch (SecondsException e) { ; } }


    {   try {
        Seconds s(100);
        assert(0 && "s.setSeconds(100) Failed");
    }
    catch (SecondsException e) { ; } }

    {   try {
        Seconds s(-1);
        assert(0 && "s.setSeconds(-1) Failed");
    }
    catch (SecondsException e) { ; } }

    {   try {
        Seconds s(-100);
        assert(0 && "s.setSeconds(-100) Failed");
    }
    catch (SecondsException e) { ; } }

    cout << "test_SimpleClass_constructor OK" << endl;
}