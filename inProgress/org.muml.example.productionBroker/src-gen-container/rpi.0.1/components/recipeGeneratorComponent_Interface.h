	/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Component of Type: RecipeGenerator
 * @details This files contains a description of the RecipeGenerator in form of the RecipeGeneratorComponent
 * 			and all methods which can be executed on an Instance of this Component
 */
		#ifndef RECIPEGENERATORCOMPONENT_Interface_H_
		#define RECIPEGENERATORCOMPONENT_Interface_H_

#ifdef __cplusplus
  extern "C" {
#endif		// Library
	#include "../types/standardTypes.h"
	#include "../types/customTypes.h"
		#include "../lib/port.h"
		#include "../messages/messages_types.h"

	#include "../lib/clock.h"
	#include "../lib/Debug.h"


		

	//include Operation Repositories




		//#include "../RTSCs/recipeGeneratorReciepeGeneratorStateChart.h"
			/*****
 			 *
 			 *  Forward Delcaration of Container Functions
 			 *
 			 */		
					void MCC_RecipeGeneratorComponent_provideOrder_send_MessagesSimpleOrder_Messages_Message(Port* p, MessagesSimpleOrder_Messages_Message* msg);
			
			
			
	
			/*****
 			 *
 			 *  Component Functions
 			 *
 			 */
			/**
			 * @file 
			 * @author generated by Fraunhofer IEM 
			 * @brief Specification of Component of Type: RecipeGenerator
			 * @details This files contains a description of the RecipeGenerator in form of the RecipeGeneratorComponent
			 * 			and all methods which can be executed on an Instance of this Component
			 */
				
						/**
						 * @brief Forward Declaration of the struct RecipeGeneratorReciepeGeneratorStateChart which describes the behavior of RecipeGeneratorComponent
						 * 
						 */
						 typedef struct RecipeGeneratorReciepeGeneratorStateChart RecipeGeneratorReciepeGeneratorStateChart;
						/**
						 * @brief Forward Declaration of the struct RecipeGeneratorComponent
						 */
							typedef struct RecipeGeneratorComponent RecipeGeneratorComponent;
						
						/**
						*  
						* @brief Description for a ComponentInstance of Type: RecipeGenerator
						* @details This struct describes a specific Component Instances which is typed over the Component: RecipeGenerator
						*/
						struct RecipeGeneratorComponent {
						
								uint8_T ID;	
						
						
									RecipeGeneratorReciepeGeneratorStateChart* stateChart;	/**< The RecipeGeneratorReciepeGeneratorStateChart of the Component RecipeGenerator */
							
										Port provideOrderPort; /**< A  Component's Port: provideOrder */
						
									
								
								
						
								RecipeGeneratorComponent * next;/**< A Pointer to the next component part, if this component ist part of a multipart in the CIC */
								
							};
					
						/**
						* @brief This Methodes intializes the Component: RecipeGenerator
						* @details All struct members of the struct RecipeGeneratorComponent are initialized
						* 
						* @param component The RecipeGeneratorComponent to be initialized
						*/	
							void RecipeGeneratorComponent_initialize(RecipeGeneratorComponent* component);
				
						/**
						* @brief Creates a Instance of the Component: RecipeGenerator
						* @details Allocates Memory for the struct RecipeGeneratorComponent
						* @return A Pointer to the new created RecipeGeneratorComponent
						*/
							RecipeGeneratorComponent RecipeGeneratorComponent_create();
				
						/**
						 * @brief Destroys a Component: RecipeGenerator
						 * @details Frees the Memory for the struct RecipeGeneratorComponent
						 * 
						* @param component The specific RecipeGeneratorComponent to be destroyed
						 */
							void RecipeGeneratorComponent_destroy(RecipeGeneratorComponent* component);
					
						
						/**
						* @brief Executes the next Step of the behavior an Instance of the Component: RecipeGenerator
						* @details The behavior of the Component:  RecipeGenerator is executed.
						*			
						* @param component The RecipeGeneratorComponent whose behavior shall be checked
						*/
							void RecipeGeneratorComponent_processStep(RecipeGeneratorComponent* component);
						/**
								 * @brief Get the Port: provideOrder of an Instance of the Component: RecipeGenerator
								 * @details The Pointer RecipeGeneratorComponent::provideOrderPort is returned
								 * 
								 * @param component The specific Instance RecipeGeneratorComponent  of the Component: RecipeGenerator whose Port shall be returned
								 * @return A Pointer to the Port provideOrder of the struct RecipeGeneratorComponent
								 */
								Port* RecipeGeneratorComponent_getprovideOrder(RecipeGeneratorComponent* component);
					
						
		

	
	
			/*****
 			 *
 			 *  RealtimeStatechart Functions
 			 *
 			 */
			/**
			 * @file 
			 * @author generated by Fraunhofer IEM
			 * @brief Specification of Realtime-StateChart: RecipeGeneratorReciepeGenerator
			 * @details This files contains the description of the Realtime-StateChart: RecipeGeneratorReciepeGenerator and its behavior which is executed
			 */
			
			//ENUM
				/** 
				 * @brief This enum represents the States of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 */
					typedef enum {
						RECIPEGENERATORRECIEPEGENERATOR_INACTIVE,
						STATE_RECIPEGENERATORINIT /**< Represents the State: STATE_RECIPEGENERATORINIT of the Realtime-StateChart: RecipeGeneratorReciepeGenerator */
						,
								STATE_RECIPEGENERATORPROVIDEORDERINIT /**< Represents the State: STATE_RECIPEGENERATORPROVIDEORDERINIT of the Realtime-StateChart: RecipeGeneratorProvideOrderReciepeSender */
						,		STATE_RECIPEGENERATORINITINTERNALBEHAVIORSMALLAMOUNT /**< Represents the State: STATE_RECIPEGENERATORINITINTERNALBEHAVIORSMALLAMOUNT of the Realtime-StateChart: RecipeGeneratorInitInternalBehavior */
						,		STATE_RECIPEGENERATORINITINTERNALBEHAVIORHIGHAMOUNT /**< Represents the State: STATE_RECIPEGENERATORINITINTERNALBEHAVIORHIGHAMOUNT of the Realtime-StateChart: RecipeGeneratorInitInternalBehavior */	
					}RecipeGeneratorReciepeGeneratorState;
				
				
					/**
					 * 
					 * @brief Description of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
					 * @details This struct represents the  Realtime-StateChart: RecipeGeneratorReciepeGenerator and its States
					 */
				struct RecipeGeneratorReciepeGeneratorStateChart {	
						RecipeGeneratorComponent * parentComponent;/**< A pointer to the parent ComponentInstance of Type: RecipeGeneratorComponent , which has this Realtime-StateChart as its behavior */			
				
				
									RecipeGeneratorReciepeGeneratorState currentStateOfRecipeGeneratorReciepeGenerator;/**< The current State of the Realtime-StateChart: RecipeGeneratorReciepeGenerator */
				
							RecipeGeneratorReciepeGeneratorState currentStateOfRecipeGeneratorProvideOrderReciepeSender;/**< Represents the state of region: RecipeGeneratorProvideOrderReciepeSender */
							RecipeGeneratorReciepeGeneratorState currentStateOfRecipeGeneratorInitInternalBehavior;/**< Represents the state of region: RecipeGeneratorInitInternalBehavior */
				
						bool_t RecipeGeneratorReciepeGenerator_isExecutable;/**< Execution Verifier of RTSC: RecipeGeneratorReciepeGenerator. This variable is used to ensure that a RTSC is executed only once per execution cycle */
							bool_t RecipeGeneratorProvideOrderReciepeSender_isExecutable;/**< Execution Verifier of RTSC: RecipeGeneratorProvideOrderReciepeSender. This variable is used to ensure that a RTSC is executed only once per execution cycle */
							bool_t RecipeGeneratorInitInternalBehavior_isExecutable;/**< Execution Verifier of RTSC: RecipeGeneratorInitInternalBehavior. This variable is used to ensure that a RTSC is executed only once per execution cycle */
					
							Clock recipeGeneratorProvideOrderTimeSpanRecipeGeneratorProvideOrderReciepeSenderClock;/**< The Clock: RecipeGeneratorProvideOrderTimeSpanRecipeGeneratorProvideOrderReciepeSender */
							Clock recipeGeneratorInitInternalBehaviorLoadClockRecipeGeneratorInitInternalBehaviorClock;/**< The Clock: RecipeGeneratorInitInternalBehaviorLoadClockRecipeGeneratorInitInternalBehavior */
				
				
					
				
							int32_T produceIngredientID; /**< The Realtime-StateChart Variable: produceIngredientID of Type: int32; */
							int32_T amount; /**< The Realtime-StateChart Variable: amount of Type: int32; */
							int32_T currentOrderID; /**< The Realtime-StateChart Variable: currentOrderID of Type: int32; */
							int32_T speed; /**< The Realtime-StateChart Variable: speed of Type: int32; */
				
				
				
						
				
					} ;
			
			//METHOD STUBS
				/**
				 * @brief Creates an Instance of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details Allocates Memory for the struct RecipeGeneratorReciepeGeneratorStateChart
				 * 
				 * @param parentComponent An Instance of the Component: RecipeGeneratorComponent which behavior is described via this Realtime-StateChart
				 * @return A Pointer to the new created RecipeGeneratorReciepeGeneratorStateChart
				 */
					RecipeGeneratorReciepeGeneratorStateChart* RecipeGeneratorReciepeGeneratorStateChart_create(RecipeGeneratorComponent* parentComponent);
				/**
				 * @brief Initializes an Instance of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details All struct members of the struct RecipeGeneratorReciepeGeneratorStateChart are initialized,
				 *			and all Regions of the Realtime-StateChart are initialized, too.
				 * 
				 * @param rtsc The specific RecipeGeneratorReciepeGeneratorStateChart to be initialized
				 */
					void RecipeGeneratorReciepeGeneratorStateChart_initialize(RecipeGeneratorReciepeGeneratorStateChart* rtsc);
				/**
				 * @brief Initializes the Region: RecipeGeneratorProvideOrderReciepeSender of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details The Member RecipeGeneratorReciepeGeneratorStateChart::currentStateOfRecipeGeneratorProvideOrderReciepeSender is initialized
				 * 
				 * @param stateChart The specific RecipeGeneratorReciepeGeneratorStateChart whose Region shall be initialized
				 */
				
					void initializeRecipeGeneratorProvideOrderReciepeSenderRegion(RecipeGeneratorReciepeGeneratorStateChart* stateChart);
				/**
				 * @brief Initializes the Region: RecipeGeneratorInitInternalBehavior of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details The Member RecipeGeneratorReciepeGeneratorStateChart::currentStateOfRecipeGeneratorInitInternalBehavior is initialized
				 * 
				 * @param stateChart The specific RecipeGeneratorReciepeGeneratorStateChart whose Region shall be initialized
				 */
				
					void initializeRecipeGeneratorInitInternalBehaviorRegion(RecipeGeneratorReciepeGeneratorStateChart* stateChart);
				/**
				 * @brief Destroys the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details Frees the Memory for the struct RecipeGeneratorReciepeGeneratorStateChart
				 * 
				 * @param rtsc The specific RecipeGeneratorReciepeGeneratorStateChart to be destroyed
				 */	
					void RecipeGeneratorReciepeGeneratorStateChart_destroy(RecipeGeneratorReciepeGeneratorStateChart* rtsc);		
				/**
				 * @brief Executes the next Step of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * 
				 * @param rtsc The specific RecipeGeneratorReciepeGeneratorStateChart to be executed
				 */	
					void RecipeGeneratorReciepeGeneratorStateChart_processStep(RecipeGeneratorReciepeGeneratorStateChart* rtsc);
			
				/**
				 * @brief Leaves the Region: internalBehavior of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details This method is called, whenever a the Region: internalBehavior is left.
				 * 			The correct State is set and all Exit-Events are executed.
				 *
				 * @param rtsc The specific RecipeGeneratorReciepeGeneratorStateChart whose Region: internalBehavior shall be exit
				 */
					void RecipeGeneratorInitInternalBehaviorStateChart_exit(RecipeGeneratorReciepeGeneratorStateChart* rtsc);
				/**
				 * @brief Leaves the Region: reciepeSender of the Realtime-StateChart: RecipeGeneratorReciepeGenerator
				 * @details This method is called, whenever a the Region: reciepeSender is left.
				 * 			The correct State is set and all Exit-Events are executed.
				 *
				 * @param rtsc The specific RecipeGeneratorReciepeGeneratorStateChart whose Region: reciepeSender shall be exit
				 */
					void RecipeGeneratorProvideOrderReciepeSenderStateChart_exit(RecipeGeneratorReciepeGeneratorStateChart* rtsc);
						
				/**
				 * @brief Returns wether the Realtime-StateChart: RecipeGeneratorReciepeGenerator is in a specific State
				 * 
				 * @param rtsc The specific Realtime-StateChart: RecipeGeneratorReciepeGeneratorStateChart
				 * @param state One of the States of the Enum: RecipeGeneratorReciepeGeneratorState
				 * 
				 * @return True, If the Realtime-StateChart is in the specific State, otherwise False
				 */	
					bool_t RecipeGeneratorReciepeGeneratorStateChart_isInState(RecipeGeneratorReciepeGeneratorStateChart* rtsc, RecipeGeneratorReciepeGeneratorState state);





#ifdef __cplusplus
  }
#endif
		#endif /* RECIPEGENERATORCOMPONENT_Interface_H_ */
