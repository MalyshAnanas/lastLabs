#include<iostream>
#include "Log.h"

int main() {
    utilits::Log::SetFile("Text.txt");
    utilits::Log::SetLevel(utilits::Levels::Debug);
    utilits::Log::Write("Bup");
}