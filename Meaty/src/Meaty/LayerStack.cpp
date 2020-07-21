#include "mtpch.h"
#include "LayerStack.h"

namespace Meaty
{
	Meaty::LayerStack::LayerStack()
	{
	}

	Meaty::LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			delete layer;
		}
	}

	void Meaty::LayerStack::PushLayer(Layer* layer)
	{
		layers.emplace(layers.begin() + LayerInsertIndex, layer);
		LayerInsertIndex++;
	}

	void Meaty::LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void Meaty::LayerStack::PopLayer(Layer* layer)
	{
		auto iterator = std::find(layers.begin(), layers.end(), layer);
		if (iterator != layers.end())
		{
			layers.erase(iterator);
			LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto iterator = std::find(layers.begin(), layers.end(), overlay);
		if (iterator != layers.end())
		{
			layers.erase(iterator);
		}
	}
}
