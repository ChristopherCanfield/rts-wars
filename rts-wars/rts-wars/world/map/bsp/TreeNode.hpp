#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <memory>

// Christopher D. Canfield
// March 2014
// TreeNode.hpp

namespace cdc
{
	namespace bsp
	{
		enum class Axis
		{
			X, Z
		};

		///<summary>A node in a bsp tree.</summary>
		class TreeNode
		{
		public:
			typedef std::shared_ptr<TreeNode> SharedPtr;

			TreeNode(int point, Axis axis);
			~TreeNode();

			///<summary>Gets the first child, or null if there isn't one.</summary>
			///<returns>The first child, or null if there isn't one.</returns>
			TreeNode* getChild1() const;

			///<summary>Sets the first child.</summary>
			///<param name="child">Pointer to the child.</param>
			void setChild1(TreeNode::SharedPtr child);

			///<summary>Gets the second child, or null if there isn't one.</summary>
			///<returns>The second child, or null if there isn't one.</returns>
			TreeNode* getChild2() const;

			///<summary>Sets the second child.</summary>
			///<param name="child">Pointer to the child.</param>
			void setChild2(TreeNode::SharedPtr child);

			///<summary>Returns the node's point. This may be extended along the x or z axis
			/// depending on the value returned by getAxis().</summary>
			///<returns>The node's point.</returns>
			int getPoint() const;

			///<summary>Returns the axis of the node.</summary>
			///<returns>The axis of the node.</returns>
			Axis getAxis() const;

		private:
			int point;
			Axis axis;

			TreeNode::SharedPtr child1;
			TreeNode::SharedPtr child2;
		};
	}
}