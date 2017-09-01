#include "scenemanager.h"

using std::string;

string SceneManager::GenerateScroll(const int& lvl) {
	int ss = 0;
	string scroll;
	switch (lvl) {
	case 1:
		scroll = "Level 1 Scroll of ";
		ss = randomNumber(1, 61);
		switch (ss) {
		case 1:
			scroll += "Alarm (ranger, wizard)";
			break;
		case 2:
			scroll += "Animal Friendship (bard, druid, ranger)";
			break;
		case 3:
			scroll += "Armor of Agathys (warlock)";
			break;
		case 4:
			scroll += "Arms of Hadar (warlock)";
			break;
		case 5:
			scroll += "Bane (bard, cleric)";
			break;
		case 6:
			scroll += "Bless (cleric, paladin)";
			break;
		case 7:
			scroll += "Burning Hands (sorcerer, wizard)";
			break;
		case 8:
			scroll += "Charm Person (bard, druid, sorcerer, warlock, wizard)";
			break;
		case 9:
			scroll += "Color Spray (sorcerer, wizard)";
			break;
		case 10:
			scroll += "Command (cleric, paladin)";
			break;
		case 11:
			scroll += "Compelled Duel (paladin)";
			break;
		case 12:
			scroll += "Comprehend Languages (bard, sorcerer, warlock, wizard)";
			break;
		case 13:
			scroll += "Create or Destroy Water (cleric, druid)";
			break;
		case 14:
			scroll += "Cure Wounds (bard, cleric, druid, paladin, ranger)";
			break;
		case 15:
			scroll += "Detect Evil and Good (cleric, paladin)";
			break;
		case 16:
			scroll += "Detect Magic (bard, cleric, druid, paladin, ranger, sorcerer, wizard)";
			break;
		case 17:
			scroll += "Detect Poison and Disease (cleric, druid, paladin, ranger)";
			break;
		case 18:
			scroll += "Disguise Self (bard, sorcerer, wizard)";
			break;
		case 19:
			scroll += "Dissonant Whispers (bard)";
			break;
		case 20:
			scroll += "Divine Favor (paladin)";
			break;
		case 21:
			scroll += "Ensnaring Strike (ranger)";
			break;
		case 22:
			scroll += "Entangle (druid)";
			break;
		case 23:
			scroll += "Expeditious Retreat (sorcerer, warlock, wizard)";
			break;
		case 24:
			scroll += "False Life (sorcerer, wizard)";
			break;
		case 25:
			scroll += "Faerie Fire (bard, druid)";
			break;
		case 26:
			scroll += "Feather Fall (bard, sorcerer, wizard)";
			break;
		case 27:
			scroll += "Find Familiar (wizard)";
			break;
		case 28:
			scroll += "Fog Cloud (druid, ranger, sorcerer, wizard)";
			break;
		case 29:
			scroll += "Goodberry (druid, ranger)";
			break;
		case 30:
			scroll += "Grease (wizard)";
			break;
		case 31:
			scroll += "Guiding Bolt (cleric)";
			break;
		case 32:
			scroll += "Hail of Thorns (ranger)";
			break;
		case 33:
			scroll += "Healing Word (bard, cleric, druid)";
			break;
		case 34:
			scroll += "Hellish Rebuke (warlock)";
			break;
		case 35:
			scroll += "Heroism (bard, paladin)";
			break;
		case 36:
			scroll += "Hex (warlock)";
			break;
		case 37:
			scroll += "Hunter's Mark (ranger)";
			break;
		case 38:
			scroll += "Identify (bard, wizard)";
			break;
		case 39:
			scroll += "Illusory Script (bard, warlock, wizard)";
			break;
		case 40:
			scroll += "Inflict Wounds (cleric)";
			break;
		case 41:
			scroll += "Jump (druid, ranger, sorcerer, wizard)";
			break;
		case 42:
			scroll += "Longstrider (bard, druid, ranger, wizard)";
			break;
		case 43:
			scroll += "Mage Armor (sorcerer, wizard)";
			break;
		case 44:
			scroll += "Magic Missle (sorcerer, wizard)";
			break;
		case 45:
			scroll += "Protection from Evil and Good (cleric, paladin, warlock, wizard)";
			break;
		case 46:
			scroll += "Purify Food and Drink (cleric, druid, paladin)";
			break;
		case 47:
			scroll += "Ray of Sickness (sorcerer, wizard)";
			break;
		case 48:
			scroll += "Searing Smite (paladin)";
			break;
		case 49:
			scroll += "Sanctuary (cleric)";
			break;
		case 50:
			scroll += "Shield (sorcerer, wizard)";
			break;
		case 51:
			scroll += "Shield of Faith (cleric, paladin)";
			break;
		case 52:
			scroll += "Silent Image (bard, sorcerer, wizard)";
			break;
		case 53:
			scroll += "Sleep (bard, sorcerer, wizard)";
			break;
		case 54:
			scroll += "Speak with Animals (bard, druid, ranger)";
			break;
		case 55:
			scroll += "Tasha's Hideous Laughter (bard, wizard)";
			break;
		case 56:
			scroll += "Tensor's Floating Disk (wizard)";
			break;
		case 57:
			scroll += "Thunderous Smite (paladin)";
			break;
		case 58:
			scroll += "Thunderwave (bard, druid, sorcerer, wizard)";
			break;
		case 59:
			scroll += "Unseen Servant (bard, warlock, wizard)";
			break;
		case 60:
			scroll += "Witch Bolt (sorcerer, warlock, wizard)";
			break;
		case 61:
			scroll += "Wrathful Smite (paladin)";
			break;
		}
		break;
	case 2:
		scroll = "Level 2 Scroll of ";
		ss = randomNumber(1, 59);
		switch (ss) {
		case 1:
			scroll += "Aid (cleric, paladin)";
			break;
		case 2:
			scroll += "Alter Self (sorcerer, wizard)";
			break;
		case 3:
			scroll += "Animal Messenger (bard, druid, ranger)";
			break;
		case 4:
			scroll += "Arcane Lock (wizard)";
			break;
		case 5:
			scroll += "Augury (cleric)";
			break;
		case 6:
			scroll += "Barkskin (druid, ranger)";
			break;
		case 7:
			scroll += "Beast Sense (druid, ranger)";
			break;
		case 8:
			scroll += "Blindness/Deafness (bard, cleric, sorcerer, wizard)";
			break;
		case 9:
			scroll += "Blur (sorcerer, wizard)";
			break;
		case 10:
			scroll += "Branding Smite (paladin)";
			break;
		case 11:
			scroll += "Calm Emotions (bard, cleric)";
			break;
		case 12:
			scroll += "Cloud of Daggers (bard, sorcerer, warlock, wizard)";
			break;
		case 13:
			scroll += "Continual Flame (cleric, wizard)";
			break;
		case 14:
			scroll += "Cordon of Arrows (ranger)";
			break;
		case 15:
			scroll += "Crown of Madness (bard, sorcerer, warlock, wizard)";
			break;
		case 16:
			scroll += "Darkness (sorcerer, warlock, wizard)";
			break;
		case 17:
			scroll += "Darkvision (druid, ranger, sorcerer, wizard)";
			break;
		case 18:
			scroll += "Detect Thoughts (bard, sorcerer, wizard)";
			break;
		case 19:
			scroll += "Enhance Ability (bard, cleric, druid, sorcerer)";
			break;
		case 20:
			scroll += "Enlarge/Reduce (sorcerer, wizard)";
			break;
		case 21:
			scroll += "Enthrall (bard, warlock)";
			break;
		case 22:
			scroll += "Find Steed (paladin)";
			break;
		case 23:
			scroll += "Find Traps (cleric, druid, ranger)";
			break;
		case 24:
			scroll += "Flame Blade (druid)";
			break;
		case 25:
			scroll += "Flaming Sphere (druid, wizard)";
			break;
		case 26:
			scroll += "Heat Metal (bard, druid)";
			break;
		case 27:
			scroll += "Hold Person (bard, druid, sorcerer, warlock)";
			break;
		case 28:
			scroll += "Gentle Repose (cleric)";
			break;
		case 29:
			scroll += "Gust of Wind (druid, sorcerer)";
			break;
		case 30:
			scroll += "Invisibility (bard, sorcerer, warlock, wizard)";
			break;
		case 31:
			scroll += "Knock (bard, sorcerer, wizard)";
			break;
		case 32:
			scroll += "Lesser Restoration (bard, cleric, druid, paladin, ranger)";
			break;
		case 33:
			scroll += "Levitate (sorcerer, wizard)";
			break;
		case 34:
			scroll += "Locate Animals or Plants (bard, druid, ranger)";
			break;
		case 35:
			scroll += "Locate Object (bard, cleric, druid, paladin, ranger, wizard)";
			break;
		case 36:
			scroll += "Magic Mouth (bard, wizard)";
			break;
		case 37:
			scroll += "Magic Weapon (paladin, wizard)";
			break;
		case 38:
			scroll += "Melf's Acid Arrow (wizard)";
			break;
		case 39:
			scroll += "Mirror Image (sorcerer, warlock, wizard)";
			break;
		case 40:
			scroll += "Misty Step (sorcerer, warlock, wizard)";
			break;
		case 41:
			scroll += "Moonbeam (druid)";
			break;
		case 42:
			scroll += "Nystul's Magic Aura (wizard)";
			break;
		case 43:
			scroll += "Pass without Trace (druid, ranger)";
			break;
		case 44:
			scroll += "Phantasmal Force (bard, sorcerer, wizard)";
			break;
		case 45:
			scroll += "Prayer of Healing (cleric)";
			break;
		case 46:
			scroll += "Protection of Poison (cleric, druid, poison, ranger)";
			break;
		case 47:
			scroll += "Ray of Enfeeblement (warlock, wizard)";
			break;
		case 48:
			scroll += "Rope Trick (wizard)";
			break;
		case 49:
			scroll += "Scorching Ray (sorcerer, wizard)";
			break;
		case 50:
			scroll += "See Invisibility (bard, sorcerer, wizard)";
			break;
		case 51:
			scroll += "Silence (bard, cleric, ranger)";
			break;
		case 52:
			scroll += "Silent Image (bard, sorcerer, wizard)";
			break;
		case 53:
			scroll += "Spider Climb (sorcerer, warlock, wizard)";
			break;
		case 54:
			scroll += "Spike Growth (druid, ranger)";
			break;
		case 55:
			scroll += "Spiritual Weapon (cleric)";
			break;
		case 56:
			scroll += "Suggestion (bard, sorcerer, warlock, wizard)";
			break;
		case 57:
			scroll += "Warding Bond (cleric)";
			break;
		case 58:
			scroll += "Web (sorcerer, wizard)";
			break;
		case 59:
			scroll += "Zone of Truth (bard, cleric, paladin)";
			break;
		}
		break;
	case 3:
		scroll = "Level 3 Scroll of ";
		ss = randomNumber(1, 50);
		switch (ss) {
		case 1:
			scroll += "Animate Dead (cleric, wizard)";
			break;
		case 2:
			scroll += "Aura of Vitality (paladin)";
			break;
		case 3:
			scroll += "Beacon of Hope (cleric)";
			break;
		case 4:
			scroll += "Bestow Curse (bard, cleric, wizard)";
			break;
		case 5:
			scroll += "Blinding Smite (paladin)";
			break;
		case 6:
			scroll += "Blink (sorcerer, wizard)";
			break;
		case 7:
			scroll += "Call Lightning (druid)";
			break;
		case 8:
			scroll += "Clairvoyance (bard, cleric, sorcerer, wizard)";
			break;
		case 9:
			scroll += "Conjure Animals (druid, ranger)";
			break;
		case 10:
			scroll += "Conjure Barrage (ranger)";
			break;
		case 11:
			scroll += "Counterspell (sorcerer, warlock, wizard)";
			break;
		case 12:
			scroll += "Create Food and Water (cleric, paladin)";
			break;
		case 13:
			scroll += "Crusader's Mantle (paladin)";
			break;
		case 14:
			scroll += "Daylight (cleric, druid, paladin, ranger, sorcerer)";
			break;
		case 15:
			scroll += "Dispel Magic (bard, cleric, druid, paladin, sorcerer, warlock, wizard)";
			break;
		case 16:
			scroll += "Elemental Weapon (paladin)";
			break;
		case 17:
			scroll += "Fear (bard, sorcerer, warlock, wizard)";
			break;
		case 18:
			scroll += "Feign Death (bard, cleric, druid, wizard)";
			break;
		case 19:
			scroll += "Fireball (sorcerer, wizard)";
			break;
		case 20:
			scroll += "Fly (sorcerer, warlock)";
			break;
		case 21:
			scroll += "Gaseous Form (sorcerer, warlock, wizard)";
			break;
		case 22:
			scroll += "Glyph of Warding (bard, cleric, wizard)";
			break;
		case 23:
			scroll += "Haste (sorcerer, wizard)";
			break;
		case 24:
			scroll += "Hunger of Hadar (warlock)";
			break;
		case 25:
			scroll += "Hypnotic Pattern (bard, sorcerer, warlock, wizard)";
			break;
		case 26:
			scroll += "Leomund's Tiny Hut (bard, wizard)";
			break;
		case 27:
			scroll += "Lightning Arrow (ranger)";
			break;
		case 28:
			scroll += "Lightning Bolt (sorcerer, wizard)";
			break;
		case 29:
			scroll += "Magic Circle (cleric, paladin, warlock, wizard)";
			break;
		case 30:
			scroll += "Major Image (bard, sorcerer, warlock, wizard)";
			break;
		case 31:
			scroll += "Mass Healing Word (cleric)";
			break;
		case 32:
			scroll += "Meld Into Stone (cleric, druid)";
			break;
		case 33:
			scroll += "Nondetection (bard, ranger, wizard)";
			break;
		case 34:
			scroll += "Phantom Steed (wizard)";
			break;
		case 35:
			scroll += "Plant Growth (bard, druid, ranger)";
			break;
		case 36:
			scroll += "Protection from Energy (cleric, druid, ranger, sorcerer, wizard)";
			break;
		case 37:
			scroll += "Remove Curse (cleric, paladin, warlock)";
			break;
		case 38:
			scroll += "Revivify (cleric, paladin)";
			break;
		case 39:
			scroll += "Sending (bard, cleric, wizard)";
			break;
		case 40:
			scroll += "Sleet Storm (druid, sorcerer, wizard)";
			break;
		case 41:
			scroll += "Slow (sorcerer, wizard)";
			break;
		case 42:
			scroll += "Speak with Dead (bard, cleric)";
			break;
		case 43:
			scroll += "Speak with Plants (bard, druid, ranger)";
			break;
		case 44:
			scroll += "Spirit Guardians (cleric)";
			break;
		case 45:
			scroll += "Stinking Cloud (bard, sorcerer, wizard)";
			break;
		case 46:
			scroll += "Tongues (bard, cleric, sorcerer, warlock, wizard)";
			break;
		case 47:
			scroll += "Vampiric Touch (warlock, wizard)";
			break;
		case 48:
			scroll += "Water Breathing (druid, ranger, sorcerer, wizard)";
			break;
		case 49:
			scroll += "Water Walk (cleric, druid, ranger, sorcerer)";
			break;
		case 50:
			scroll += "Wind Wall (druid, ranger)";
			break;
		}
		break;
	case 4:
		scroll = "Level 4 Scroll of ";
		ss = randomNumber(1, 34);
		switch (ss) {
		case 1:
			scroll += "Aura of Life (paladin)";
			break;
		case 2:
			scroll += "Aura of Purify (paladin)";
			break;
		case 3:
			scroll += "Arcane Eye (wizard)";
			break;
		case 4:
			scroll += "Banishment (cleric, paladin, sorcerer, warlock, wizard)";
			break;
		case 5:
			scroll += "Blight (druid, sorcerer, warlock, wizard)";
			break;
		case 6:
			scroll += "Compulsion (bard)";
			break;
		case 7:
			scroll += "Confusion (bard, druid, sorcerer, wizard)";
			break;
		case 8:
			scroll += "Conjure Minor Elementals (druid, wizard)";
			break;
		case 9:
			scroll += "Conjure Woodland Beings (druid, ranger)";
			break;
		case 10:
			scroll += "Control Water (druid, wizard)";
			break;
		case 11:
			scroll += "Control Weather (cleric)";
			break;
		case 12:
			scroll += "Death Ward (cleric)";
			break;
		case 13:
			scroll += "Dimension Door (bard, warlock, wizard)";
			break;
		case 14:
			scroll += "Divination (cleric)";
			break;
		case 15:
			scroll += "Dominate Beast (druid, sorcerer)";
			break;
		case 16:
			scroll += "Evard's Black Tentacles (wizard)";
			break;
		case 17:
			scroll += "Fabricate (wizard)";
			break;
		case 18:
			scroll += "Fire Shield (wizard)";
			break;
		case 19:
			scroll += "Grasping Vine (druid, ranger)";
			break;
		case 20:
			scroll += "Greater Invisibility (bard, sorcerer, wizard)";
			break;
		case 21:
			scroll += "Guardian of Faith (cleric)";
			break;
		case 22:
			scroll += "Hallucinatory Terrain (bard, druid, warlock, wizard)";
			break;
		case 23:
			scroll += "Ice Storm (druid, sorcerer, wizard)";
			break;
		case 24:
			scroll += "Leomund's Secret Chest (wizard)";
			break;
		case 25:
			scroll += "Locate Creature (bard, cleric, druid, paladin, ranger, wizard)";
			break;
		case 26:
			scroll += "Mordenkainen's Faithful Hound (wizard)";
			break;
		case 27:
			scroll += "Mordenkainen's Private Sanctum (wizard)";
			break;
		case 28:
			scroll += "Otiluke's Resilient Sphere (wizard)";
			break;
		case 29:
			scroll += "Phantasmal Killer (wizard)";
			break;
		case 30:
			scroll += "Polymorph (bard, sorcerer, wizard)";
			break;
		case 31:
			scroll += "Staggering Smite (paladin)";
			break;
		case 32:
			scroll += "Stone Shape (cleric, druid, wizard)";
			break;
		case 33:
			scroll += "Stoneskin (druid, ranger, sorcerer, wizard)";
			break;
		case 34:
			scroll += "Wall of Fire (druid, sorcerer, wizard)";
			break;
		}
		break;
	case 5:
		scroll = "Level 5 Scroll of ";
		ss = randomNumber(1, 42);
		switch (ss) {
		case 1:
			scroll += "Animate Objects (bard, sorcerer, wizard)";
			break;
		case 2:
			scroll += "Antilife Shell (druid)";
			break;
		case 3:
			scroll += "Awaken (bard, druid)";
			break;
		case 4:
			scroll += "Banishing Smite (paladin)";
			break;
		case 5:
			scroll += "Bigby's Hand (wizard)";
			break;
		case 6:
			scroll += "Circle of Power (paladin)";
			break;
		case 7:
			scroll += "Cloudkill (sorcerer, wizard)";
			break;
		case 8:
			scroll += "Commune (cleric)";
			break;
		case 9:
			scroll += "Commune with Nature (druid, ranger)";
			break;
		case 10:
			scroll += "Cone of Cold (sorcerer, wizard)";
			break;
		case 11:
			scroll += "Conjure ELemental (druid, wizard)";
			break;
		case 12:
			scroll += "Conjure Volley (ranger)";
			break;
		case 13:
			scroll += "Contact Other Plane (warlock, wizard)";
			break;
		case 14:
			scroll += "Contagion (cleric, druid)";
			break;
		case 15:
			scroll += "Creation (sorcerer, wizard)";
			break;
		case 16:
			scroll += "Destructive Smite (paladin)";
			break;
		case 17:
			scroll += "Dispel Evil and Good (cleric, paladin)";
			break;
		case 18:
			scroll += "Dominate Person (bard, sorcerer, wizard)";
			break;
		case 19:
			scroll += "Dream (bard, warlock, wizard)";
			break;
		case 20:
			scroll += "Flame Strike (cleric)";
			break;
		case 21:
			scroll += "Geas (bard, cleric, druid, paladin, wizard)";
			break;
		case 22:
			scroll += "Greater Restoration (bard, cleric, druid)";
			break;
		case 23:
			scroll += "Hallow (cleric)";
			break;
		case 24:
			scroll += "Hold Monster (bard, sorcerer, warlock, wizard)";
			break;
		case 25:
			scroll += "Insect Plague (cleric, druid, sorcerer)";
			break;
		case 26:
			scroll += "Legend Lore (bard, cleric, wizard)";
			break;
		case 27:
			scroll += "Mass Cure Wounds (bard, cleric)";
			break;
		case 28:
			scroll += "Mislead (bard, wizard)";
			break;
		case 29:
			scroll += "Modify Memory (bard, wizard)";
			break;
		case 30:
			scroll += "Passwall (wizard)";
			break;
		case 31:
			scroll += "Planar Binding (bard, cleric, druid, wizard)";
			break;
		case 32:
			scroll += "Raise Dead (bard, cleric, paladin)";
			break;
		case 33:
			scroll += "Rary's Telepathic Bond (wizard)";
			break;
		case 34:
			scroll += "Reincarnate (druid)";
			break;
		case 35:
			scroll += "Scrying (bard, cleric, druid, warlock, wizard)";
			break;
		case 36:
			scroll += "Seeming (bard, sorcerer, wizard)";
			break;
		case 37:
			scroll += "Swift Quiver (ranger)";
			break;
		case 38:
			scroll += "Telekinesis (sorcerer, wizard)";
			break;
		case 39:
			scroll += "Teleportation Circle (bard, sorcerer, wizard)";
			break;
		case 40:
			scroll += "Tree Stride (druid, ranger)";
			break;
		case 41:
			scroll += "Wall of Force (wizard)";
			break;
		case 42:
			scroll += "Wall of Stone (druid, sorcerer, wizard)";
			break;
		}
		break;
	case 6:
		scroll = "Level 6 Scroll of ";
		ss = randomNumber(1, 32);
		switch (ss) {
		case 1:
			scroll += "Arcane Gate (sorcerer, warlock, wizard)";
			break;
		case 2:
			scroll += "Blade Barrier (cleric)";
			break;
		case 3:
			scroll += "Chain Lightning (sorcerer, wizard)";
			break;
		case 4:
			scroll += "Circle of Death (sorcerer, warlock, wizard)";
			break;
		case 5:
			scroll += "Conjure Fey (druid, warlock)";
			break;
		case 6:
			scroll += "Contingency (wizard)";
			break;
		case 7:
			scroll += "Create Undead (cleric, warlock, wizard)";
			break;
		case 8:
			scroll += "Disintegrate (sorcerer, wizard)";
			break;
		case 9:
			scroll += "Drawmij's Instant Summons (wizard)";
			break;
		case 10:
			scroll += "Eyebit (bard, sorcerer, warlock, wizard)";
			break;
		case 11:
			scroll += "Find the Path (bard, cleric, druid)";
			break;
		case 12:
			scroll += "Flesh to Stone (warlock, wizard)";
			break;
		case 13:
			scroll += "Forbiddance (cleric)";
			break;
		case 14:
			scroll += "Globe of Invulnerability (sorcerer, wizard)";
			break;
		case 15:
			scroll += "Guards and Wards (bard, wizard)";
			break;
		case 16:
			scroll += "Harm (cleric)";
			break;
		case 17:
			scroll += "Heal (cleric, druid)";
			break;
		case 18:
			scroll += "Heroes' Feast (cleric, druid)";
			break;
		case 19:
			scroll += "Magic Jar (wizard)";
			break;
		case 20:
			scroll += "Mass Suggestion (bard, sorcerer, warlock, wizard)";
			break;
		case 21:
			scroll += "Move Earth (druid, sorcerer, wizard)";
			break;
		case 22:
			scroll += "Otiluke's Freezing Sphere (wizard)";
			break;
		case 23:
			scroll += "Otto's Irresistible Dance (bard, wizard)";
			break;
		case 24:
			scroll += "Planar Ally (cleric)";
			break;
		case 25:
			scroll += "Programmed Illusion (bard, wizard)";
			break;
		case 26:
			scroll += "Sunbeam (druid, sorcerer, wizard)";
			break;
		case 27:
			scroll += "Transport via Plants (druid)";
			break;
		case 28:
			scroll += "True Seeing (bard, cleric, sorcerer, warlock, wizard)";
			break;
		case 29:
			scroll += "Wall of Ice (wizard)";
			break;
		case 30:
			scroll += "Wall of Thorns (druid)";
			break;
		case 31:
			scroll += "Wind Walk (druid)";
			break;
		case 32:
			scroll += "Word of Recall (cleric)";
			break;
		}
		break;
	case 7:
		scroll = "Level 7 Scroll of ";
		ss = randomNumber(1, 20);
		switch (ss) {
		case 1:
			scroll += "Conjure Celestial (cleric)";
			break;
		case 2:
			scroll += "Delayed Blast Fireball (sorcerer, wizard)";
			break;
		case 3:
			scroll += "Divine Word (cleric)";
			break;
		case 4:
			scroll += "Etherealness (bard, cleric, sorcerer, wizard)";
			break;
		case 5:
			scroll += "Finger of Death (sorcerer, wizard)";
			break;
		case 6:
			scroll += "Fire Storm (cleric, druid, sorcerer)";
			break;
		case 7:
			scroll += "Forcecage (bard, wizard)";
			break;
		case 8:
			scroll += "Mirage Arcane (bard, druid, wizard)";
			break;
		case 9:
			scroll += "Mordenkainen's Magnificent Mansion (bard, wizard)";
			break;
		case 10:
			scroll += "Mordenkainen's Sword (bard, wizard)";
			break;
		case 11:
			scroll += "Plane Shift (cleric, druid, sorcerer, wizard)";
			break;
		case 12:
			scroll += "Prismatic Spray (sorcerer, wizard)";
			break;
		case 13:
			scroll += "Project Image (bard, wizard)";
			break;
		case 14:
			scroll += "Regenerate (bard, cleric, druid)";
			break;
		case 15:
			scroll += "Resurrection (bard, cleric)";
			break;
		case 16:
			scroll += "Reverse Gravity (druid, sorcerer, wizard)";
			break;
		case 17:
			scroll += "Sequester (wizard)";
			break;
		case 18:
			scroll += "Simulacrum (wizard)";
			break;
		case 19:
			scroll += "Symbol (bard, cleric, wizard)";
			break;
		case 20:
			scroll += "Teleport (bard, sorcerer, wizard)";
			break;
		}
		break;
	case 8:
		scroll = "Level 8 Scroll of ";
		ss = randomNumber(1, 19);
		switch (ss) {
		case 1:
			scroll += "Animal Shapes (druid)";
			break;
		case 2:
			scroll += "Antimagic Field (cleric, wizard)";
			break;
		case 3:
			scroll += "Antipathy/Sympathy (druid, wizard)";
			break;
		case 4:
			scroll += "Clone (wizard)";
			break;
		case 5:
			scroll += "Control Weather (cleric, druid, wizard)";
			break;
		case 6:
			scroll += "Demiplane (warlock, wizard)";
			break;
		case 7:
			scroll += "Dominate Monster (bard, sorcerer, warlock, wizard)";
			break;
		case 8:
			scroll += "Earthquake (cleric, druid, sorcerer)";
			break;
		case 9:
			scroll += "Feeblemind (bard, druid, warlock, wizard)";
			break;
		case 10:
			scroll += "Glibness (bard, warlock)";
			break;
		case 11:
			scroll += "Holy Aura (cleric)";
			break;
		case 12:
			scroll += "Incendiary Cloud (sorcerer, wizard)";
			break;
		case 13:
			scroll += "Maze (wizard)";
			break;
		case 14:
			scroll += "Mind Blank (bard, wizard)";
			break;
		case 15:
			scroll += "Power Word Stun (bard, sorcerer, warlock, wizard)";
			break;
		case 16:
			scroll += "Sunburst (druid, sorcerer, wizard)";
			break;
		case 17:
			scroll += "Telepathy (wizard)";
			break;
		case 18:
			scroll += "Trap the Soul (wizard)";
			break;
		case 19:
			scroll += "Tsunami (druid)";
			break;
		}
		break;
	case 9:
		scroll = "Level 9 Scroll of ";
		ss = randomNumber(1, 16);
		switch (ss) {
		case 1:
			scroll += "Astral Projection (cleric, warlock, wizard)";
			break;
		case 2:
			scroll += "Foresight (bard, druid, warlock, wizard)";
			break;
		case 3:
			scroll += "Gate (cleric, sorcerer, wizard)";
			break;
		case 4:
			scroll += "Imprisonment (warlock, wizard)";
			break;
		case 5:
			scroll += "Mass Heal (cleric)";
			break;
		case 6:
			scroll += "Meteor Swarm (sorcerer, wizard)";
			break;
		case 7:
			scroll += "Power Word Heal (bard)";
			break;
		case 8:
			scroll += "Power Word Kill (bard, sorcerer, warlock, wizard)";
			break;
		case 9:
			scroll += "Prismatic Wall (wizard)";
			break;
		case 10:
			scroll += "Shapechange (druid, wizard)";
			break;
		case 11:
			scroll += "Storm of Vengeance (druid)";
			break;
		case 12:
			scroll += "Time Stop (sorcerer, wizard)";
			break;
		case 13:
			scroll += "True Polymorph (bard, warlock, wizard)";
			break;
		case 14:
			scroll += "True Resurrection (cleric, druid)";
			break;
		case 15:
			scroll += "Weird (wizard)";
			break;
		case 16:
			scroll += "Wish (sorcerer, wizard)";
			break;
		}
		break;
	}
	return scroll;
}
