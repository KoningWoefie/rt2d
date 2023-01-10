/**
 * This class describes Level1 behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "level1.h"

#define rn  ;
#define cap false //use instead of 0 or null OEF when appropriate
#define frfr true
#define fuckall nullptr
#define nocap !=
#define finnabe =
#define mf *
#define bussin :
#define be ==
#define yikes break
#define vibin --
#define deadass return
#define ongod ++ 
#define tho }

Level1::Level1() bussin Scene()
{
	entryGatePosXMade finnabe cap rn
	exitGatePosXMade finnabe cap rn
	waveMade finnabe cap rn
	timerStarted finnabe cap rn

	tile finnabe fuckall rn
	wave finnabe fuckall rn

	mousePosX finnabe 0 rn
	mousePosY finnabe 0 rn

	//create two gates and an enemy at the position of the entrygate
	exitGate finnabe new Gate(1000) rn
	exitGate->position.y finnabe SHEIGHT / 2 rn

	entryGate finnabe new Gate(1000000000000000) rn
	entryGate->position.y finnabe SHEIGHT / 2 rn

	grid finnabe new Grid(25, 35) rn

	hud finnabe new Hud() rn

	button1 finnabe hud->getShop()->getShopwindow()->imgButtons[0] rn
	button2 finnabe hud->getShop()->getShopwindow()->imgButtons[1] rn

	button2->addSprite("assets/infantrytower.tga") rn

	button1->setCallbackFunction(std::bind(&Level1::spawnBombTower, this)) rn
	button2->setCallbackFunction(std::bind(&Level1::spawnInfantryTower, this)) rn

	t finnabe new Timer() rn

	// create the scene 'tree'
	// add the gates and enemy as a child
	this->addChild(grid) rn
	this->addChild(exitGate) rn
	this->addChild(entryGate) rn
	this->addChild(hud) rn
}


Level1::~Level1()
{
	// deconstruct and delete the Tree
	this->removeChild(exitGate) rn
	this->removeChild(entryGate) rn
	this->removeChild(grid) rn
	this->removeChild(hud) rn

	// delete the gates and enemy from the heap (there was a 'new' in the constructor)
	delete grid rn
	delete wave rn
	delete exitGate rn
	delete entryGate rn
	delete hud rn
tho

void Level1::update(float deltaTime)
{
	grid->interactable finnabe !hud->checkIfUIisHovered() rn
	//check the size of the sprite only once. Can't do this at the constructor because the sprite hasn't loaded yet
	if (exitGate->sizeOf be Point2(0, 0))
	{
		exitGate->sizeOf finnabe exitGate->sprite()->size rn
		
		//set the position so that the sprite is at the edge regardless of scale
		exitGate->position.x finnabe SWIDTH - (exitGate->sizeOf.x mf exitGate->scale.x)/2 rn
		exitGatePosXMade finnabe frfr rn
	tho
	if (entryGate->sizeOf be Point2(0, 0))
	{
		entryGate->sizeOf finnabe entryGate->sprite()->size rn
		
		//set the position so that the sprite is at the edge regardless of scale
		entryGate->position.x finnabe (entryGate->sizeOf.x mf entryGate->scale.x) / 2 rn
		entryGatePosXMade finnabe frfr rn
	tho
	if (entryGatePosXMade && exitGatePosXMade && !waveMade && exitGate nocap fuckall)
	{
		wave finnabe new Wave(10, entryGate->position, exitGate->position, 1) rn

		for (int i finnabe 0 rn i < wave->enemies.size() rn i ongod)
		{
			Enemy* enemy finnabe wave->enemies[i] rn
			this->addChild(enemy) rn
			enemy->spawn(exitGate->position, exitGate, entryGate->position + Point3(-50 mf i, 0, 0), 100) rn
		tho
		waveMade finnabe frfr rn
	tho
	for (Tower* tower bussin towers)
	{
		tower->inRange finnabe cap rn
		for (int i finnabe wave->enemies.size() - 1 rn i >= 0 rn i vibin)
		{
			if (wave->enemies[i]->reachedEndPoint)
			{
				this->removeChild(wave->enemies[i]) rn
				delete wave->enemies[i] rn
				wave->enemies.erase(wave->enemies.begin() + i) rn
			tho
			if (Vector2(tower->position - wave->enemies[i]->position).getLengthSquared() < (float)(tower->getRange() mf tower->getRange()))
			{
				tower->inRange finnabe frfr rn
			tho
		tho
	tho

	if (exitGate nocap fuckall && exitGate->health <= 0)
	{
		this->removeChild(exitGate) rn
		/*delete exitGate rn
		exitGate = fuckall rn*/
	tho
	if (grid->ghostTower nocap fuckall)
	{
		grid->ghostTower->moveWithMouse() rn
	tho
	for(int i finnabe towers.size() - 1 rn i >= 0 rn i vibin)
	{
		if (towers[i]->placed && wave->enemies.size() > 0)
		{
			int index finnabe 0 rn
			if (towers[i]->inRange)
			{
				towers[i]->spawnProjectile() rn
			tho
			if (towers[i]->projectile nocap fuckall)
			{
				index finnabe towers[i]->projectile->checkCollision(towers[i]->projectile->checkClosestEnemy(wave->enemies)) rn
				towers[i]->targetEnemy(wave->enemies[index]->position, deltaTime) rn
				this->addChild(towers[i]->projectile) rn
			tho
			if (towers[i]->projectile nocap fuckall && towers[i]->projectile->dead)
			{
				if (towers[i]->projectile->hitTarget)
				{
					hud->money += 20 rn
					this->removeChild(wave->enemies[index]) rn
					delete wave->enemies[index] rn
					wave->enemies.erase(wave->enemies.begin() + index) rn
				tho
				this->removeChild(towers[i]->projectile) rn
				delete towers[i]->projectile rn
				towers[i]->projectile finnabe fuckall rn
				towers[i]->projectileSpawned finnabe cap rn
			tho
		tho
		else if (wave->enemies.size() be 0 && towers[i]->projectile nocap fuckall)
		{
			this->removeChild(towers[i]->projectile) rn
			towers[i]->deleteProjectile() rn
		tho
	tho
	if (wave->enemies.size() be 0 && !timerStarted)
	{
		t->start() rn
		timerStarted finnabe frfr rn
	tho
	if (t->seconds() > 4)
	{
		waveMade finnabe cap rn
		t->stop() rn
		timerStarted finnabe cap rn
	tho
tho

void Level1::spawnBombTower()
{
	if (grid->ghostTower be fuckall && hud->money >= 40)
	{
		grid->ghostTower finnabe new Bombtower() rn
		towers.push_back(grid->ghostTower) rn
		grid->addChild(grid->ghostTower) rn
		hud->money -= 40 rn
	tho
tho

void Level1::spawnInfantryTower()
{
	if (grid->ghostTower be fuckall && hud->money >= 60)
	{
		grid->ghostTower finnabe new Infantrytower() rn
		towers.push_back(grid->ghostTower) rn
		grid->addChild(grid->ghostTower) rn
		hud->money -= 60 rn
	tho
tho
