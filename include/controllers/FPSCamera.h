#pragma once
#ifndef GLFPSCONTROLLER_H
#define GLFPSCONTROLLER_H

#include "../systems/KeyboardInputSystem.h"
#include "../systems/MouseInputSystem.h"
#include "../systems/IGLView.h"

class CameraMover;

namespace Sigma {
	namespace event {
		namespace handler {
			// A type of handler. This handler controls an OpenGL 6 DOF view.
			class FPSCamera : public IKeyboardEventHandler, public IMouseEventHandler, public Sigma::IGLView {
			public:
			    SET_COMPONENT_TYPENAME("FPS_CAMERA");

				FPSCamera(int entityID);

				/**
				 * \brief Triggered whenever a key state change event happens
				 *
				 * This method adjusts the view mover according to various key state changes.
				 * \param key The key for which the state change is happening
				 * \param state The new state of the key (KS_UP or KS_DOWN)
				 * \return void
				 */
				void KeyStateChange(const unsigned int key, const KEY_STATE state);
				virtual void MouseMove(float dx, float dy);
				virtual void MouseDown(Sigma::event::BUTTON btn) {}
				virtual void MouseUp(Sigma::event::BUTTON btn) {}

				const glm::mat4 GetViewMatrix();
				virtual void Move(float right, float up, float forward);
				virtual glm::vec3 Restrict(glm::vec3 rotation);

				/**
				 * \brief Sets the view mover for this event handler.
				 *
				 * The view mover does the moving.
				 * \param[in/out] ViewMover * m The view mover.
				 * \return    void 
				 */
				virtual void SetMover(CameraMover* m);
			private:
				CameraMover* mover; // The view mover component that applies the rotations and forces set in the trigger method.
                static const float SPEED_TRANSLATE, SPEED_ROTATE, BOOST_MULTIPLIER;
                glm::vec3 _translate, _rotate;
			};
		}
	}
}

#endif // GLFPSCONTROLLER_H

