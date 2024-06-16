#include "Engine/Logger.hpp"
#include <Engine/Application.hpp>

void Engine::Init() {}

void Engine::Update() {}

void Engine::OnEvent(Event &e) { CORE_TRACE(e.GetStatus()); }