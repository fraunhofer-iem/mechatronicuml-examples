

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from MUML_DDS.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef MUML_DDSPlugin_1362042836_h
#define MUML_DDSPlugin_1362042836_h

#include "MUML_DDS.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define DDS_MAIN_LED_VOLTAGEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DDS_MAIN_LED_VOLTAGEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDS_MAIN_LED_VOLTAGEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define DDS_MAIN_LED_VOLTAGEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDS_MAIN_LED_VOLTAGEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DDS_MAIN_LED_VOLTAGE*
DDS_MAIN_LED_VOLTAGEPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DDS_MAIN_LED_VOLTAGE*
DDS_MAIN_LED_VOLTAGEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DDS_MAIN_LED_VOLTAGE*
DDS_MAIN_LED_VOLTAGEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPluginSupport_copy_data(
    DDS_MAIN_LED_VOLTAGE *out,
    const DDS_MAIN_LED_VOLTAGE *in);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPluginSupport_destroy_data_w_params(
    DDS_MAIN_LED_VOLTAGE *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPluginSupport_destroy_data_ex(
    DDS_MAIN_LED_VOLTAGE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPluginSupport_destroy_data(
    DDS_MAIN_LED_VOLTAGE *sample);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPluginSupport_print_data(
    const DDS_MAIN_LED_VOLTAGE *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DDS_MAIN_LED_VOLTAGEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DDS_MAIN_LED_VOLTAGEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DDS_MAIN_LED_VOLTAGEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DDS_MAIN_LED_VOLTAGEPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE *out,
    const DDS_MAIN_LED_VOLTAGE *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DDS_MAIN_LED_VOLTAGE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDS_MAIN_LED_VOLTAGEPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DDS_MAIN_LED_VOLTAGE *sample); 

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDS_MAIN_LED_VOLTAGEPlugin_deserialize_from_cdr_buffer(
    DDS_MAIN_LED_VOLTAGE *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
DDS_MAIN_LED_VOLTAGEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DDS_MAIN_LED_VOLTAGE * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DDS_MAIN_LED_VOLTAGEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDS_MAIN_LED_VOLTAGEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DDS_MAIN_LED_VOLTAGE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DDS_MAIN_LED_VOLTAGEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDS_MAIN_LED_VOLTAGEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DDS_MAIN_LED_VOLTAGE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DDS_MAIN_LED_VOLTAGEPlugin_new(void);

NDDSUSERDllExport extern void
DDS_MAIN_LED_VOLTAGEPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* MUML_DDSPlugin_1362042836_h */

