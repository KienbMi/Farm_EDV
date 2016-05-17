#pragma once
#include "Kleintier.h"
#include "Tier.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
//ijlkjjkljsdfsdfsdfsdfsdf
class Farm
{
private:   
    Kleintier huehner;
    vector<Tier> tiere;
    vector<Tier>::iterator it;
	float preis_milch;                // VK-Preis pro Liter Milch
	float preis_ei;			      	  // VK-Preis pro Ei

public:
    Farm();
    void loadTiere();
    void saveTiere();
    void inputErtragTiere();
    void editBestandTiere();
    void printStatistikTiere();
    ~Farm();
};

