#pragma once

#include "SFML/Graphics.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.hpp

#include "graphics/Sprite.hpp"

namespace cdc
{
	class Entity;

	///<summary>One frame of animation.</summary>
	class AnimationFrame
	{
	public:
		AnimationFrame(sf::Sprite sprite, sf::Time timePerFrame) :
			sprite(sprite),
			timePerFrame(timePerFrame) {}

		sf::Sprite sprite;
		const sf::Time timePerFrame;
		sf::Time timeRemaining;

	private:
		AnimationFrame& operator=(const AnimationFrame&);
	};

	///<summary>Abstract sprite implementation.</summary>
	class AbstractSprite :
		public Sprite
	{
	public:
		AbstractSprite(Entity& entity, bool isMovable);
		virtual ~AbstractSprite();

		virtual bool isDestroyed() const override;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		virtual void update(const sf::Time& deltaTime) override;

	protected:
		///<summary>Adds one animation frame.</summary>
		///<param name="frame">The frame to add.</frame>
		void addFrame(AnimationFrame frame);

		///<summary>Sets the current animation frame.</summary>
		///<param name="index">The index of the frame that will be drawn.</param>
		void setCurrentFrame(int index);

		///<summary></summary>
		///<param name="border">Sets the border that is displayed when the entity is selected.</param>
		///<param name="drawAdjustmentX">The x draw adjustment for the border image, compared to the normal image.</param>
		///<param name="drawAdjustmentZ">The z draw adjustment for the border image, compared to the normal image.</param>
		void setSelectionBorder(sf::Sprite border, int drawAdjustmentX, int drawAdjustmentZ);

	private:
		AbstractSprite& operator=(AbstractSprite& rhs);

		Entity& entity;

		std::vector<AnimationFrame> frames;
		int currentFrame;

		sf::Sprite selectionBorder;
		int borderDrawAdjustmentX;
		int borderDrawAdjustmentZ;

		bool movable;
	};
}