#ifndef DEFAULTWEAPONDAMAGE_H
#define DEFAULTWEAPONDAMAGE_H

//TOOLS WEAPONS DAMAGE
static constexpr const unsigned int BaseDamage_STONE_PICK = 16;
static constexpr const unsigned int BaseDamage_STONE_HATCHET = 20;
static constexpr const unsigned int BaseDamage_TORCH = 15;
static constexpr const float BaseDamage_METAL_PICK = 34.3f;
static constexpr const unsigned int BaseDamage_METAL_HATCHET = 40;
static constexpr const unsigned int BaseDamage_METAL_SICKLE = 50;

//MELEE WEAPONS DAMAGE
static constexpr const unsigned int BaseDamage_PIKE = 55;
static constexpr const unsigned int BaseDamage_WOODEN_CLUB = 5;
static constexpr const unsigned int BaseTorpor_WOODEN_CLUB = 20;
static constexpr const unsigned int BaseDamage_METAL_SWORD = 90;
static constexpr const unsigned int BaseTorpor_ELECTRIC_PROD = 266;

//RANGED WEAPONS DAMAGE
static constexpr const unsigned int BaseDamage_SLINGSHOT = 14;
static constexpr const float BaseTorpor_SLINGSHOT = 23.8f;
static constexpr const unsigned int BaseDamage_WOODEN_BOW_STONE_ARROW = 55;
static constexpr const unsigned int BaseDamage_WOODEN_BOW_TRANQ_ARROW = 20;
static constexpr const unsigned int BaseTorpor_WOODEN_BOW_TRANQ_ARROW = 40;
static constexpr const unsigned int DotTorpor_WOODEN_BOW_TRANQ_ARROW = 50;  //over 4 seconds - doesn't stack
static constexpr const unsigned int BaseDamage_CROSSBOW_STONE_ARROW = 95;
static constexpr const unsigned int BaseDamage_CROSSBOW_TRANQ_ARROW = 35;
static constexpr const unsigned int BaseTorpor_CROSSBOW_TRANQ_ARROW = 70;
static constexpr const float DotTorpor_CROSSBOW_TRANQ_ARROW = 87.5f;  //over 4 seconds - doesn't stack
static constexpr const unsigned int BaseDamage_COMPOUND_BOW_STONE_ARROW = 55;
static constexpr const unsigned int BaseDamage_COMPOUND_BOW_METAL_ARROW = 202;
static constexpr const unsigned int BaseDamage_COMPOUND_BOW_TRANQ_ARROW = 20;
static constexpr const unsigned int BaseTorpor_COMPOUND_BOW_TRANQ_ARROW = 40;
static constexpr const unsigned int DotTorpor_COMPOUND_BOW_TRANQ_ARROW = 50;  //over 4 seconds - doesn't stack

//FIREARMS WEAPONS DAMAGE
static constexpr const unsigned int BaseDamage_SIMPLE_PISTOL = 63;
static constexpr const unsigned int BaseDamage_LONGNECK_RIFLE = 280;
static constexpr const unsigned int BaseDamage_LONGNECK_RIFLE_DART = 26;

//the dart torpor is based off the longneck base dart damage
//need functions addressed per shot instance
/*The target's torpor will increase by 600% of the damage dealt instantaneously, as well as an additional 250% of the over the next 5 seconds.*/
//static constexpr const unsigned int BaseTorpor_LONGNECK_RIFLE_DART = BaseDamage_LONGNECK_RIFLE_DART * 6;
//static constexpr const float DotTorpor_LONGNECK_RIFLE_DART = BaseTorpor_LONGNECK_RIFLE_DART * 2.5; //over 5 seconds - stacks 5s time per shot

static constexpr const unsigned int BaseDamage_SHOTGUN = 630; //if all 10 pellets hit
static constexpr const unsigned int BaseDamage_FABRICATED_PISTOL = 50;
static constexpr const unsigned int BaseDamage_PUMP_ACTION_SHOTGUN = 494; //if all 10 pellets hit
static constexpr const float BaseDamage_ASSAULT_RIFLE = 59.4f;
static constexpr const unsigned int BaseDamage_FABRICATED_SNIPER_RIFLE = 165;

//EXPLOSIVES WEAPONS DAMAGE
static constexpr const unsigned int BaseDamage_ROCKET_LAUNCHER = 1000;

#endif // DEFAULTWEAPONDAMAGE_H
