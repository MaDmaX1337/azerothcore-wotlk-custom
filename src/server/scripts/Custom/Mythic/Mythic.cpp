
#include "Chat.h"
#include "Configuration/Config.h"
#include "Player.h"
#include "Creature.h"
#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Define.h"
#include "GossipDef.h"

#define MENU_ID 123 // Our menuID used to match the sent menu to select hook (playerscript)

class Mythic_Reward : public PlayerScript
{

public:
    Mythic_Reward() : PlayerScript("Mythic_Reward") {}

    // THE NEXUS - TIME GOAL
    uint32 RewardTimerTheNexusGold = 38 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerTheNexusSilver = 50 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerTheNexusBronze = 61 * MINUTE * IN_MILLISECONDS;

    // HALLS OF LIGHTNING - TIME GOAL
    uint32 RewardTimerHallsOfLightningGold = 37 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerHallsOfLightningSilver = 48 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerHallsOfLightningBronze = 60 * MINUTE * IN_MILLISECONDS;

    // HALLS OF STONE - TIME GOAL
    uint32 RewardTimerHallsOfStoneGold = 36 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerHallsOfStoneSilver = 46 * MINUTE * IN_MILLISECONDS;
    uint32 RewardTimerHallsOfStoneBronze = 58 * MINUTE * IN_MILLISECONDS;

    int itemReceived = 0;
    int hintMythicDungeon = 0;

    void OnLogin(Player* player) override
    {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Mythic+ Dungeon |rmodule.");
    }

    void OnMapChanged(Player* p) override {

        switch (p->GetMapId())
        {
        case 576:
            // THE NEXUS
            if (p->GetMap()->IsDungeon() && p->GetInstanceScript())
            {
                if (!p->GetItemByEntry(60000))
                {
                    p->AddItem(60000, 1);
                }
            }
            break;
        case 602:
            // HALLS OF LIGHTNING
            if (p->GetMap()->IsDungeon() && p->GetInstanceScript())
            {
                if (!p->GetItemByEntry(60000))
                {
                    p->AddItem(60000, 1);
                }
            }
            break;
        case 599:
            // HALLS OF STONE
            if (p->GetMap()->IsDungeon() && p->GetInstanceScript())
            {
                if (!p->GetItemByEntry(60000))
                {
                    p->AddItem(60000, 1);
                }
            }
            break;
        default:
            break;
        }
    }

    void OnUpdate(Player* p, uint32 p_time) override
    {
        // THE NEXUS
        if (p->GetMapId() == 576 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && hintMythicDungeon == 0)
        {
            ChatHandler(p->GetSession()).SendSysMessage("[The Nexus] Mythic+ Dungeon");
            ChatHandler(p->GetSession()).SendSysMessage("[The Nexus] Type .mythic [0-3] to start you jorney. GLHF!");
            hintMythicDungeon = 1;
        }

        if (p->GetMapId() == 576 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() == DUNGEON_DIFFICULTY_EPIC)
        {
            if (RewardTimerTheNexusGold >= p_time && p->GetInstanceScript()->GetBossState(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "The Nexus: Completed! Get Gold Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Gold Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerTheNexusSilver >= p_time && p->GetInstanceScript()->GetBossState(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "The Nexus: Completed! Get Silver Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Silver Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerTheNexusBronze >= p_time && p->GetInstanceScript()->GetBossState(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "The Nexus: Completed! Get Bronze Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Bronze Reward!");
                itemReceived = 1;
            } 
        }

        // HALLS OF LIGHTNING
        if (p->GetMapId() == 602 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && hintMythicDungeon == 0)
        {
            ChatHandler(p->GetSession()).SendSysMessage("[Halls of Lightning] Mythic+ Dungeon");
            ChatHandler(p->GetSession()).SendSysMessage("[Halls of Lightning] Type .mythic [0-3] to start you jorney. GLHF!");
            hintMythicDungeon = 1;
        }

        if (p->GetMapId() == 602 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() == DUNGEON_DIFFICULTY_EPIC)
        {
            if (RewardTimerHallsOfLightningGold >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Lightning: Completed! Get Gold Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Gold Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerHallsOfLightningSilver >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Lightning: Completed! Get Silver Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Silver Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerHallsOfLightningBronze >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Lightning: Completed! Get Bronze Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Bronze Reward!");
                itemReceived = 1;
            }
        }

        // HALLS OF STONE
        if (p->GetMapId() == 599 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && hintMythicDungeon == 0)
        {
            ChatHandler(p->GetSession()).SendSysMessage("[Halls of Stone] Mythic+ Dungeon");
            ChatHandler(p->GetSession()).SendSysMessage("[Halls of Stone] Type .mythic [0-3] to start you jorney. GLHF!");
            hintMythicDungeon = 1;
        }

        if (p->GetMapId() == 599 && p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() == DUNGEON_DIFFICULTY_EPIC)
        {
            if (RewardTimerHallsOfStoneGold >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Stone: Completed! Get Gold Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Gold Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerHallsOfStoneSilver >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Stone: Completed! Get Silver Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Silver Reward!");
                itemReceived = 1;
            }
            else if (RewardTimerHallsOfStoneBronze >= p_time && p->GetInstanceScript()->GetData(DONE) && itemReceived == 0)
            {
                ClearGossipMenuFor(p);                              // Clears old options
                AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Halls of Stone: Completed! Get Bronze Reward!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                // SetMenuId must be after clear menu and before send menu!!
                p->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
                SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, p->GetGUID());
                ChatHandler(p->GetSession()).SendSysMessage("Congratulation to Bronze Reward!");
                itemReceived = 1;
            }
        }
    }

    void OnGossipSelect(Player* p, uint32 menu_id, uint32 /*sender*/, uint32 action) override
    {
        if (menu_id != MENU_ID) // Not the menu coded here? stop.
            return;
        ClearGossipMenuFor(p);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 3:
            p->AddItem(60003, 1);
            ChatHandler(p->GetSession()).SendSysMessage("Reward Claimed!");
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            p->AddItem(60002, 1);
            ChatHandler(p->GetSession()).SendSysMessage("Reward Claimed!");
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            p->AddItem(60001, 1);
            ChatHandler(p->GetSession()).SendSysMessage("Reward Claimed!");
            break;
        default:
            p->AddItem(60001, 1);
            break;
        }
        CloseGossipMenuFor(p);
    }
};


class Mythic_Level_0 : public ItemScript
{
public:
    Mythic_Level_0() : ItemScript("Mythic_Level_0") { }

    bool OnUse(Player* p, Item* i, const SpellCastTargets&) override
    {
        if (p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() != DUNGEON_DIFFICULTY_EPIC)
        {
            ClearGossipMenuFor(p); // Clears old options
            AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Start Mythic+ Dungeon - Level: 0", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, i->GetGUID());
            return true;
        }
        else {
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon difficulty can only be changed once in the dungeon itself.");
            return false;
        }

        
    }

    void OnGossipSelect(Player* p, Item* i, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(p);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            p->SetDungeonDifficulty(DUNGEON_DIFFICULTY_EPIC);
            p->SendDungeonDifficulty(p->GetGroup());
            p->GetInstanceScript()->StartMythic(0);
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon Difficulty set to Mythic+ Level: 0");
            p->DestroyItemCount(i->GetEntry(), 1, true);
            break;
        }
        CloseGossipMenuFor(p);
    }
};
 

class Mythic_Level_1 : public ItemScript
{
public:
    Mythic_Level_1() : ItemScript("Mythic_Level_1") { }

    bool OnUse(Player* p, Item* i, const SpellCastTargets&) override
    {
        if (p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() != DUNGEON_DIFFICULTY_EPIC)
        {
            ClearGossipMenuFor(p); // Clears old options
            AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Start Mythic+ Dungeon - Level: 1", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, i->GetGUID());
            return true;
        }
        else {
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon difficulty can only be changed once in the dungeon itself.");
            return false;
        }
    }

    void OnGossipSelect(Player* p, Item* i, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(p);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            p->SetDungeonDifficulty(DUNGEON_DIFFICULTY_EPIC);
            p->SendDungeonDifficulty(p->GetGroup());
            p->GetInstanceScript()->StartMythic(1);
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon Difficulty set to Mythic+ Level: 1");
            p->DestroyItemCount(i->GetEntry(), 1, true);
            break;
        }
        CloseGossipMenuFor(p);
    }
};

class Mythic_Level_2 : public ItemScript
{
public:
    Mythic_Level_2() : ItemScript("Mythic_Level_2") { }

    bool OnUse(Player* p, Item* i, const SpellCastTargets&) override
    {
        if (p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() != DUNGEON_DIFFICULTY_EPIC)
        {
            ClearGossipMenuFor(p); // Clears old options
            AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Start Mythic+ Dungeon - Level: 2", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, i->GetGUID());
            return true;
        }
        else {
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon difficulty can only be changed once in the dungeon itself.");
            return false;
        }
    }

    void OnGossipSelect(Player* p, Item* i, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(p);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            p->SetDungeonDifficulty(DUNGEON_DIFFICULTY_EPIC);
            p->SendDungeonDifficulty(p->GetGroup());
            p->GetInstanceScript()->StartMythic(2);
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon Difficulty set to Mythic+ Level: 2");
            p->DestroyItemCount(i->GetEntry(), 1, true);
            break;
        }
        CloseGossipMenuFor(p);
    }
};

class Mythic_Level_3 : public ItemScript
{
public:
    Mythic_Level_3() : ItemScript("Mythic_Level_3") { }

    bool OnUse(Player* p, Item* i, const SpellCastTargets&) override
    {
        if (p->GetMap()->IsDungeon() && p->GetInstanceScript() && p->GetDungeonDifficulty() != DUNGEON_DIFFICULTY_EPIC)
        {
            ClearGossipMenuFor(p); // Clears old options
            AddGossipItemFor(p, GOSSIP_ICON_CHAT, "Start Mythic+ Dungeon - Level: 3", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(p, DEFAULT_GOSSIP_MESSAGE, i->GetGUID());
            return true;
        }
        else {
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon difficulty can only be changed once in the dungeon itself.");
            return false;
        }
    }

    void OnGossipSelect(Player* p, Item* i, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(p);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            p->SetDungeonDifficulty(DUNGEON_DIFFICULTY_EPIC);
            p->SendDungeonDifficulty(p->GetGroup());
            p->GetInstanceScript()->StartMythic(3);
            ChatHandler(p->GetSession()).PSendSysMessage("Dungeon Difficulty set to Mythic+ Level: 3");
            p->DestroyItemCount(i->GetEntry(), 1, true);
            break;
        }
        CloseGossipMenuFor(p);
    }
};

void AddMythicScripts()
{
    new Mythic_Reward();
    new Mythic_Level_0();
    new Mythic_Level_1();
    new Mythic_Level_2();
    new Mythic_Level_3();
}
