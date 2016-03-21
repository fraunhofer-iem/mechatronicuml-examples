	/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Component of Type: aComponent
 * @details This files contains a description of the aComponent in form of the AComponentComponent
 * 			and all methods which can be executed on an Instance of this Component
 */
		#ifndef ACOMPONENTCOMPONENT_INTERFACE_H_
		#define ACOMPONENTCOMPONENT_INTERFACE_H_

#ifdef __cplusplus
  extern "C" {
#endif
				// Library
				#include "../types/standardTypes.h"
				#include "../types/customTypes.h"
					
					
				
			
				#include "../lib/clock.h"
			#include "../lib/Debug.h"
			#include "../lib/MiddlewareTypes.h"
			#include "../Middleware/MiddlewareCore.h"
				
			
	
			/**
			 * @brief Forward Declaration of the struct AComponentBehaviorStateChart which describes the behavior of AComponentComponent
			 * 
			 */
			 typedef struct AComponentBehaviorStateChart AComponentBehaviorStateChart;
			/**
			 * @brief Forward Declaration of the struct AComponentComponent
			 */
				typedef struct AComponentComponent AComponentComponent;
			
			/**
			*  
			* @brief Description for a ComponentInstance of Type: aComponent
			* @details This struct describes a specific Component Instances which is typed over the Component: aComponent
			*/
			struct AComponentComponent {
			
			
						AComponentBehaviorStateChart* stateChart;	/**< The AComponentBehaviorStateChart of the Component aComponent */
				
			
						
					
					
			
					AComponentComponent * next;/**< A Pointer to the next component part, if this component ist part of a multipart in the CIC */
					
				};
		
			/**
			* @brief This Methodes intializes the Component: aComponent
			* @details All struct members of the struct AComponentComponent are initialized
			* 
			* @param component The AComponentComponent to be initialized
			*/	
				void AComponentComponent_initialize(AComponentComponent* component);
	
			/**
			* @brief Creates a Instance of the Component: aComponent
			* @details Allocates Memory for the struct AComponentComponent
			* @return A Pointer to the new created AComponentComponent
			*/
				AComponentComponent* AComponentComponent_create();
	
			/**
			 * @brief Destroys a Component: aComponent
			 * @details Frees the Memory for the struct AComponentComponent
			 * 
			* @param component The specific AComponentComponent to be destroyed
			 */
				void AComponentComponent_destroy(AComponentComponent* component);
		
			
			/**
			* @brief Executes the next Step of the behavior an Instance of the Component: aComponent
			* @details The behavior of the Component:  aComponent is executed.
			*			
			* @param component The AComponentComponent whose behavior shall be checked
			*/
				void AComponentComponent_processStep(AComponentComponent* component);
		
			
		
			

		
/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Realtime-StateChart: AComponentBehavior
 * @details This files contains the description of the Realtime-StateChart: AComponentBehavior and its behavior which is executed
 */
	//ENUM
	/** 
	 * @brief This enum represents the States of the Realtime-StateChart: AComponentBehavior
	 */
		typedef enum {
			ACOMPONENTBEHAVIOR_INACTIVE,
			STATE_ACOMPONENTINIT /**< Represents the State: STATE_ACOMPONENTINIT of the Realtime-StateChart: AComponentBehavior */
			,
					STATE_ACOMPONENTINITSTART /**< Represents the State: STATE_ACOMPONENTINITSTART of the Realtime-StateChart: AComponentInit */
			,		STATE_ACOMPONENTINITCOMPOSITE /**< Represents the State: STATE_ACOMPONENTINITCOMPOSITE of the Realtime-StateChart: AComponentInit */
			,
					STATE_ACOMPONENTINITCOMPOSITEINNER1 /**< Represents the State: STATE_ACOMPONENTINITCOMPOSITEINNER1 of the Realtime-StateChart: AComponentInitComposite */
					,
							STATE_ACOMPONENTINITCOMPOSITEINNER1SOMESTATE /**< Represents the State: STATE_ACOMPONENTINITCOMPOSITEINNER1SOMESTATE of the Realtime-StateChart: AComponentInitCompositeInner1 */
			,		STATE_ACOMPONENTINITEND /**< Represents the State: STATE_ACOMPONENTINITEND of the Realtime-StateChart: AComponentInit */	
		}AComponentBehaviorState;
	
	
		/**
		 * 
		 * @brief Description of the Realtime-StateChart: AComponentBehavior
		 * @details This struct represents the  Realtime-StateChart: AComponentBehavior and its States
		 */
	struct AComponentBehaviorStateChart {	
			AComponentComponent * parentComponent;/**< A pointer to the parent ComponentInstance of Type: AComponentComponent , which has this Realtime-StateChart as its behavior */			
	
	
						AComponentBehaviorState currentStateOfAComponentBehavior;/**< The current State of the Realtime-StateChart: AComponentBehavior */
	
				AComponentBehaviorState currentStateOfAComponentInit;/**< Represents the state of region: AComponentInit */
				AComponentBehaviorState currentStateOfAComponentInitComposite;/**< Represents the state of region: AComponentInitComposite */
				AComponentBehaviorState currentStateOfAComponentInitCompositeInner1;/**< Represents the state of region: AComponentInitCompositeInner1 */
	
			bool_t AComponentBehavior_isExecutable;/**< Execution Verifier of RTSC: AComponentBehavior. This variable is used to ensure that a RTSC is executed only once per execution cycle */
				bool_t AComponentInit_isExecutable;/**< Execution Verifier of RTSC: AComponentInit. This variable is used to ensure that a RTSC is executed only once per execution cycle */
				bool_t AComponentInitComposite_isExecutable;/**< Execution Verifier of RTSC: AComponentInitComposite. This variable is used to ensure that a RTSC is executed only once per execution cycle */
				bool_t AComponentInitCompositeInner1_isExecutable;/**< Execution Verifier of RTSC: AComponentInitCompositeInner1. This variable is used to ensure that a RTSC is executed only once per execution cycle */
		
	
	
		
	
				int32_T i; /**< The Realtime-StateChart Variable: i of Type: int32; */
	
	
	
			
	
		} ;

//METHOD STUBS
	/**
	 * @brief Creates an Instance of the Realtime-StateChart: AComponentBehavior
	 * @details Allocates Memory for the struct AComponentBehaviorStateChart
	 * 
	 * @param parentComponent An Instance of the Component: AComponentComponent which behavior is described via this Realtime-StateChart
	 * @return A Pointer to the new created AComponentBehaviorStateChart
	 */
		AComponentBehaviorStateChart* AComponentBehaviorStateChart_create(AComponentComponent* parentComponent);
	/**
	 * @brief Initializes an Instance of the Realtime-StateChart: AComponentBehavior
	 * @details All struct members of the struct AComponentBehaviorStateChart are initialized,
	 *			and all Regions of the Realtime-StateChart are initialized, too.
	 * 
	 * @param rtsc The specific AComponentBehaviorStateChart to be initialized
	 */
		void AComponentBehaviorStateChart_initialize(AComponentBehaviorStateChart* rtsc);
	/**
	 * @brief Initializes the Region: AComponentInit of the Realtime-StateChart: AComponentBehavior
	 * @details The Member AComponentBehaviorStateChart::currentStateOfAComponentInit is initialized
	 * 
	 * @param stateChart The specific AComponentBehaviorStateChart whose Region shall be initialized
	 */
	
		void initializeAComponentInitRegion(AComponentBehaviorStateChart* stateChart);
	/**
	 * @brief Initializes the Region: AComponentInitComposite of the Realtime-StateChart: AComponentBehavior
	 * @details The Member AComponentBehaviorStateChart::currentStateOfAComponentInitComposite is initialized
	 * 
	 * @param stateChart The specific AComponentBehaviorStateChart whose Region shall be initialized
	 */
	
		void initializeAComponentInitCompositeRegion(AComponentBehaviorStateChart* stateChart);
	/**
	 * @brief Initializes the Region: AComponentInitCompositeInner1 of the Realtime-StateChart: AComponentBehavior
	 * @details The Member AComponentBehaviorStateChart::currentStateOfAComponentInitCompositeInner1 is initialized
	 * 
	 * @param stateChart The specific AComponentBehaviorStateChart whose Region shall be initialized
	 */
	
		void initializeAComponentInitCompositeInner1Region(AComponentBehaviorStateChart* stateChart);
	/**
	 * @brief Destroys the Realtime-StateChart: AComponentBehavior
	 * @details Frees the Memory for the struct AComponentBehaviorStateChart
	 * 
	 * @param rtsc The specific AComponentBehaviorStateChart to be destroyed
	 */	
		void AComponentBehaviorStateChart_destroy(AComponentBehaviorStateChart* rtsc);		
	/**
	 * @brief Executes the next Step of the Realtime-StateChart: AComponentBehavior
	 * 
	 * @param rtsc The specific AComponentBehaviorStateChart to be executed
	 */	
		void AComponentBehaviorStateChart_processStep(AComponentBehaviorStateChart* rtsc);

	/**
	 * @brief Leaves the Region: composite2 of the Realtime-StateChart: AComponentBehavior
	 * @details This method is called, whenever a the Region: composite2 is left.
	 * 			The correct State is set and all Exit-Events are executed.
	 *
	 * @param rtsc The specific AComponentBehaviorStateChart whose Region: composite2 shall be exit
	 */
		void AComponentInitCompositeInner1StateChart_exit(AComponentBehaviorStateChart* rtsc);
	/**
	 * @brief Leaves the Region: innerRegion of the Realtime-StateChart: AComponentBehavior
	 * @details This method is called, whenever a the Region: innerRegion is left.
	 * 			The correct State is set and all Exit-Events are executed.
	 *
	 * @param rtsc The specific AComponentBehaviorStateChart whose Region: innerRegion shall be exit
	 */
		void AComponentInitCompositeStateChart_exit(AComponentBehaviorStateChart* rtsc);
	/**
	 * @brief Leaves the Region: Region1 of the Realtime-StateChart: AComponentBehavior
	 * @details This method is called, whenever a the Region: Region1 is left.
	 * 			The correct State is set and all Exit-Events are executed.
	 *
	 * @param rtsc The specific AComponentBehaviorStateChart whose Region: Region1 shall be exit
	 */
		void AComponentInitStateChart_exit(AComponentBehaviorStateChart* rtsc);
			
	/**
	 * @brief Returns wether the Realtime-StateChart: AComponentBehavior is in a specific State
	 * 
	 * @param rtsc The specific Realtime-StateChart: AComponentBehaviorStateChart
	 * @param state One of the States of the Enum: AComponentBehaviorState
	 * 
	 * @return True, If the Realtime-StateChart is in the specific State, otherwise False
	 */	
		bool_t AComponentBehaviorStateChart_isInState(AComponentBehaviorStateChart* rtsc, AComponentBehaviorState state);




#ifdef __cplusplus
  }
#endif
		#endif /* ACOMPONENTCOMPONENT_INTERFACE_H_ */

