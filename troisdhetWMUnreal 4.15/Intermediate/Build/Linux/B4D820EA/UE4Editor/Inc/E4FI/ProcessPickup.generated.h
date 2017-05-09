// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef E4FI_ProcessPickup_generated_h
#error "ProcessPickup.generated.h already included, missing '#pragma once' in ProcessPickup.h"
#endif
#define E4FI_ProcessPickup_generated_h

#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetActive) \
	{ \
		P_GET_UBOOL(Z_Param_newPickupState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActive(Z_Param_newPickupState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsActive(); \
		P_NATIVE_END; \
	}


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetActive) \
	{ \
		P_GET_UBOOL(Z_Param_newPickupState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActive(Z_Param_newPickupState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsActive(); \
		P_NATIVE_END; \
	}


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAProcessPickup(); \
	friend E4FI_API class UClass* Z_Construct_UClass_AProcessPickup(); \
	public: \
	DECLARE_CLASS(AProcessPickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/E4FI"), NO_API) \
	DECLARE_SERIALIZER(AProcessPickup) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAProcessPickup(); \
	friend E4FI_API class UClass* Z_Construct_UClass_AProcessPickup(); \
	public: \
	DECLARE_CLASS(AProcessPickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/E4FI"), NO_API) \
	DECLARE_SERIALIZER(AProcessPickup) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProcessPickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProcessPickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcessPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcessPickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcessPickup(AProcessPickup&&); \
	NO_API AProcessPickup(const AProcessPickup&); \
public:


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcessPickup(AProcessPickup&&); \
	NO_API AProcessPickup(const AProcessPickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcessPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcessPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProcessPickup)


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProcessPickupMesh() { return STRUCT_OFFSET(AProcessPickup, ProcessPickupMesh); }


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_8_PROLOG
#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_PRIVATE_PROPERTY_OFFSET \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_RPC_WRAPPERS \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_INCLASS \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_PRIVATE_PROPERTY_OFFSET \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_INCLASS_NO_PURE_DECLS \
	troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID troisdhetWMUnreal_4_15_Source_E4FI_ProcessPickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
