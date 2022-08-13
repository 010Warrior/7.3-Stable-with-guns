#pragma once

#include "patterns.h"
#include "util.h"

namespace Functions
{
    inline UFortEngine* GetEngine()
    {
        //MessageBoxA(0, "gettinenginee", 0, 0);
        static auto engine = UObject::FindObject<UFortEngine>("FortEngine_");
        //MessageBoxA(0, "AAAAAAA", std::to_string((uintptr_t)engine).c_str(), 0);
        return engine;
    }

    namespace Actor
    {
        inline __int64 (*GetNetMode)(__int64* a1);
    }

    namespace LocalPlayer
    {
        bool (*SpawnPlayActor)(ULocalPlayer* Player, const FString& URL, FString& OutError, UWorld* World);
    }

    namespace GC
    {
        __int64 (*CollectGarbage)(__int64 a1);
    }

    namespace AbilitySystemComponent
    {
        inline FGameplayAbilitySpecHandle* (*GiveAbility)(UAbilitySystemComponent* _this, FGameplayAbilitySpecHandle* outHandle, FGameplayAbilitySpec inSpec);
        inline bool (*InternalTryActivateAbility)(UAbilitySystemComponent* _this, FGameplayAbilitySpecHandle Handle, FPredictionKey InPredictionKey, UGameplayAbility** OutInstancedAbility, void* /* FOnGameplayAbilityEnded::FDelegate* */ OnGameplayAbilityEndedDelegate, FGameplayEventData* TriggerEventData);
        inline void (*MarkAbilitySpecDirty)(UAbilitySystemComponent* _this, FGameplayAbilitySpec& Spec);
    }

    namespace NetDriver
    {
        inline void* (*SetWorld)(UNetDriver* NetDriver, UWorld* World);
        inline bool (*InitListen)(UObject* Driver, void* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error);
        inline void (*TickFlush)(UNetDriver* NetDriver, float DeltaSeconds);
    }

    namespace ReplicationDriver
    {
        inline void (*ServerReplicateActors)(UReplicationDriver* ReplicationDriver);
    }

    namespace NetConnection
    {
        inline void (*ReceiveFString)(void* Bunch, FString& Str);
        inline void (*ReceiveUniqueIdRepl)(void* Bunch, FUniqueNetIdRepl& Str);
    }

    namespace OnlineSession
    {
        inline char (*KickPlayer)(AGameSession* a1, APlayerController*, FText a3);
    }

    namespace World
    {
        inline void (*WelcomePlayer)(UWorld* World, UNetConnection* Connection);
        inline void (*NotifyControlMessage)(UWorld* World, UNetConnection* Connection, uint8_t MessageType, void* Bunch);
        inline APlayerController* (*SpawnPlayActor)(UWorld* World, UPlayer* NewPlayer, ENetRole RemoteRole, FURL& URL, void* UniqueId, SDK::FString& Error, uint8_t NetPlayerIndex);
    }

    namespace Engine
    {
        inline void* (*NetDebug)(UObject* _this);
        inline UNetDriver* (*CreateNetDriver)(UEngine* Engine, UWorld* InWorld, FName NetDriverDefinition);
    }

    namespace FortWeapon
    {
        inline void* (*OnReload)(AFortWeapon* _this, int ammo_count);
    }

    void Initialize()
    {
        Offsets::Imagebase = (uintptr_t)GetModuleHandleA(0);
        MessageBoxA(0, "ImageBase", std::to_string((uintptr_t)Offsets::Imagebase).c_str(), 0);

        UObject::GObjects = Utils::FindPattern<decltype(UObject::GObjects)>(Patterns::GObjects, 3);
        MessageBoxA(0, "GObjects", std::to_string((uintptr_t)UObject::GObjects).c_str(), 0);

        FMemory_Free = Utils::FindPattern<decltype(FMemory_Free)>(Patterns::Free);
        MessageBoxA(0, "FMemory_Free", std::to_string((uintptr_t)FMemory_Free).c_str(), 0);

        FMemory_Malloc = Utils::FindPattern<decltype(FMemory_Malloc)>(Patterns::Malloc);
        MessageBoxA(0, "FMemory_Malloc", std::to_string((uintptr_t)FMemory_Malloc).c_str(), 0);

        FMemory_Realloc = Utils::FindPattern<decltype(FMemory_Realloc)>(Patterns::Realloc);
        MessageBoxA(0, "FMemory_Realloc", std::to_string((uintptr_t)FMemory_Realloc).c_str(), 0);

        FNameToString = Utils::FindPattern<decltype(FNameToString)>(Patterns::FNameToString);
        MessageBoxA(0, "FNameToString", std::to_string((uintptr_t)FNameToString).c_str(), 0);

        NetDriver::TickFlush = Utils::FindPattern<decltype(NetDriver::TickFlush)>(Patterns::TickFlush);
        MessageBoxA(0, "TickFlush", std::to_string((uintptr_t)NetDriver::TickFlush).c_str(), 0);

        Engine::CreateNetDriver = Utils::FindPattern<decltype(Engine::CreateNetDriver)>(Patterns::CreateNetDriver);
        MessageBoxA(0, "CreateNetDriver", std::to_string((uintptr_t)Engine::CreateNetDriver).c_str(), 0);

        NetDriver::SetWorld = Utils::FindPattern<decltype(NetDriver::SetWorld)>(Patterns::NetDriver_SetWorld);
        MessageBoxA(0, "NetDriver_SetWorld", std::to_string((uintptr_t)NetDriver::SetWorld).c_str(), 0);

        NetDriver::InitListen = Utils::FindPattern<decltype(NetDriver::InitListen)>(Patterns::InitListen);
        MessageBoxA(0, "InitListen", std::to_string((uintptr_t)NetDriver::InitListen).c_str(), 0);

        World::WelcomePlayer = Utils::FindPattern<decltype(World::WelcomePlayer)>(Patterns::WelcomePlayer);
        MessageBoxA(0, "WelcomePlayer", std::to_string((uintptr_t)World::WelcomePlayer).c_str(), 0);

        World::NotifyControlMessage = Utils::FindPattern<decltype(World::NotifyControlMessage)>(Patterns::World_NotifyControlMessage);
        MessageBoxA(0, "NotifyControlMessage", std::to_string((uintptr_t)World::NotifyControlMessage).c_str(), 0);

        World::SpawnPlayActor = Utils::FindPattern<decltype(World::SpawnPlayActor)>(Patterns::SpawnPlayActor);
        MessageBoxA(0, "SpawnPlayActor", std::to_string((uintptr_t)World::SpawnPlayActor).c_str(), 0);

        NetConnection::ReceiveUniqueIdRepl = Utils::FindPattern<decltype(NetConnection::ReceiveUniqueIdRepl)>(Patterns::ReceiveUniqueIdRepl);
        MessageBoxA(0, "ReceiveUniqueIdRepl", std::to_string((uintptr_t)NetConnection::ReceiveUniqueIdRepl).c_str(), 0);

        NetConnection::ReceiveFString = Utils::FindPattern<decltype(NetConnection::ReceiveFString)>(Patterns::ReceiveFString);
        MessageBoxA(0, "ReceiveFString", std::to_string((uintptr_t)NetConnection::ReceiveFString).c_str(), 0);

        OnlineSession::KickPlayer = Utils::FindPattern<decltype(OnlineSession::KickPlayer)>(Patterns::KickPlayer);
        MessageBoxA(0, "KickPlayer", std::to_string((uintptr_t)OnlineSession::KickPlayer).c_str(), 0);

        Actor::GetNetMode = Utils::FindPattern<decltype(Actor::GetNetMode)>(Patterns::GetNetMode);
        MessageBoxA(0, "GetNetMode", std::to_string((uintptr_t)Actor::GetNetMode).c_str(), 0);

        AbilitySystemComponent::GiveAbility = Utils::FindPattern<decltype(AbilitySystemComponent::GiveAbility)>(Patterns::GiveAbility);
        MessageBoxA(0, "GiveAbility", std::to_string((uintptr_t)AbilitySystemComponent::GiveAbility).c_str(), 0);

        AbilitySystemComponent::InternalTryActivateAbility = Utils::FindPattern<decltype(AbilitySystemComponent::InternalTryActivateAbility)>(Patterns::InternalTryActivateAbility);
        MessageBoxA(0, "InternalTryActivateAbility", std::to_string((uintptr_t)AbilitySystemComponent::InternalTryActivateAbility).c_str(), 0);

        AbilitySystemComponent::MarkAbilitySpecDirty = Utils::FindPattern<decltype(AbilitySystemComponent::MarkAbilitySpecDirty)>(Patterns::MarkAbilitySpecDirty);
        MessageBoxA(0, "MarkAbilitySpecDirty", std::to_string((uintptr_t)AbilitySystemComponent::MarkAbilitySpecDirty).c_str(), 0);

        LocalPlayer::SpawnPlayActor = Utils::FindPattern<decltype(LocalPlayer::SpawnPlayActor)>(Patterns::LocalPlayerSpawnPlayActor);
        MessageBoxA(0, "SpawnPlayActor", std::to_string((uintptr_t)LocalPlayer::SpawnPlayActor).c_str(), 0);

        GC::CollectGarbage = Utils::FindPattern<decltype(GC::CollectGarbage)>(Patterns::CollectGarbage, 0);
        MessageBoxA(0, "CollectGarbage", std::to_string((uintptr_t)GC::CollectGarbage).c_str(), 0);

        Engine::NetDebug = Utils::FindPattern<decltype(Engine::NetDebug)>(Patterns::NetDebug);
        MessageBoxA(0, "NetDebug", std::to_string((uintptr_t)Engine::NetDebug).c_str(), 0);

        FortWeapon::OnReload = Utils::FindPattern<decltype(FortWeapon::OnReload)>(Patterns::OnReload);
        MessageBoxA(0, "OnReload", std::to_string((uintptr_t)FortWeapon::OnReload).c_str(), 0);

        oProcessEvent = reinterpret_cast<decltype(oProcessEvent)>(GetEngine()->Vtable[0x40]);
        static void* ProcessEventHook(UObject * Object, UFunction * Function, void* Params); { if (Function->GetName().find("ServerAcknowledgePossession") { auto PlayerController = (APlayerController*)Object; PlayerController->AcknowledgedPawn = PlayerController->Pawn; } } static APlayerController* SpawnPlayActor(UWorld*, UNetConnection * Connection, ENetRole RemoteRole, FURL & InURL, void* UniqueId, FString & Error, uint8_t InNetPlayerIndex) {
            Pawn->bReplicateMovement = true; Pawn->OnRep_ReplicateMovent(); Pawn->OnRep_ReplicatedMovement(); Pawn->OnRep_ReplicatedBasedMovement(); // i think im too lazy to check the func name, if it throws an error change to OnRep_ReplicateBasedMovement(); }
        MessageBoxA(0, "oProcessEvent", std::to_string((uintptr_t)oProcessEvent).c_str(), 0);



        {
        }
    }
}
