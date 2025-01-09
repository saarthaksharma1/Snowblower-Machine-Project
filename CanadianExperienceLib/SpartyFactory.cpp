/**
 * @file SpartyFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"


/**
 * This is a factory method that creates our Harold actor.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> SpartyFactory::Create(std::wstring imagesDir)
{
    std::shared_ptr<Actor> actor = std::make_shared<Actor>(L"Sparty");

    auto torso = std::make_shared<ImageDrawable>(L"Torso", imagesDir +L"/sparty_torso.png");
    torso->SetCenter(wxPoint(69, 144));
    torso->SetPosition(wxPoint(0, -200));
    actor->SetRoot(torso);

    auto lleg = std::make_shared<ImageDrawable>(L"Left Leg", imagesDir +L"/sparty_lleg.png");
    lleg->SetCenter(wxPoint(40, 27));
    lleg->SetPosition(wxPoint(102 - 69, 180 - 144));
    torso->AddChild(lleg);

    auto rleg = std::make_shared<ImageDrawable>(L"Right Leg", imagesDir +L"/sparty_rleg.png");
    rleg->SetCenter(wxPoint(34, 27));
    rleg->SetPosition(wxPoint(36 - 69, 180 - 144));
    torso->AddChild(rleg);

    auto larm = std::make_shared<ImageDrawable>(L"Left Arm", imagesDir +L"/sparty_larm.png");
    larm->SetCenter(wxPoint(25, 26));
    larm->SetPosition(wxPoint(120 - 69, 22 - 144));
    torso->AddChild(larm);

    auto rarm = std::make_shared<ImageDrawable>(L"Right Arm", imagesDir +L"/sparty_rarm.png");
    rarm->SetCenter(wxPoint(89, 26));
    rarm->SetPosition(wxPoint(20 - 69, 22 - 144));
    torso->AddChild(rarm);

    auto headb = std::make_shared<ImageDrawable>(L"Head Bottom", imagesDir +L"/sparty_lhead.png");
    headb->SetCenter(wxPoint(53, 30));
    headb->SetPosition(wxPoint(0, 37 - 144));
    torso->AddChild(headb);

    auto usaflag = std::make_shared<ImageDrawable>(L"American Flag", imagesDir +L"/amflag.png");
    usaflag->SetCenter(wxPoint(109, 87));
    usaflag->SetPosition(wxPoint(0, 37 - 144));
    torso->AddChild(usaflag);

    auto headt = std::make_shared<HeadTop>(L"Head Top", imagesDir +L"/sparty_head.png");
    headt->SetCenter(wxPoint(59, 143));
    headt->SetPosition(wxPoint(0, -28));
    headb->AddChild(headt);
    headt->SetEyesCenter(wxPoint(54, 110));
    headt->GetLeftEye()->LoadImage(imagesDir +L"/sparty_leye.png");
    headt->GetLeftEye()->SetCenter(wxPoint(14, 14));
    headt->GetRightEye()->LoadImage(imagesDir +L"/sparty_reye.png");
    headt->GetRightEye()->SetCenter(wxPoint(17, 16));
    headt->SetInterocularDistance(30);

    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);
    actor->AddDrawable(torso);
    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);
    actor->AddDrawable(usaflag);

    return actor;
}