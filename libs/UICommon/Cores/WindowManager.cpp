#include "WindowManager.h"

namespace uicommon::cores
{

static WindowManager* g_instance = nullptr;

WindowManager::WindowManager(QObject* parent)
    : QObject(parent)
{

}

WindowManager::~WindowManager()
{

}

WindowManager* WindowManager::initialize(QObject* parent) 
{
    if (g_instance == nullptr)
    {
        g_instance = new WindowManager();
    }
    return g_instance;
}

WindowManager &WindowManager::getInstance()
{
    if (g_instance == nullptr) {
        throw "WindowManager need to initialize first";
    }
    return *g_instance;
}

}
