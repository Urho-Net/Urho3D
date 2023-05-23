// GENERATED FILE, DO NOT MODIFY

int Animation_GetType (int);
int Animation_GetTypeName (int);
int Animation_GetTypeStatic ();
int Animation_GetTypeNameStatic ();
int Animation_Animation (int);
void Animation_RegisterObject (int);
int Animation_BeginLoad_File (int,int);
int Animation_BeginLoad_MemoryBuffer (int,int);
int Animation_Save_File (int,int);
int Animation_Save_MemoryBuffer (int,int);
void Animation_SetAnimationName (int,int);
void Animation_SetLength (int,float);
int Animation_CreateTrack (int,int);
int Animation_RemoveTrack (int,int);
void Animation_RemoveAllTracks (int);
void Animation_AddTrigger_0 (int,float,int,int);
void Animation_AddTrigger_1 (int,float,int,int);
void Animation_AddTrigger_2 (int,float,int,int);
void Animation_AddTrigger_3 (int,float,int,int);
void Animation_AddTrigger_4 (int,float,int,int);
void Animation_AddTrigger_5 (int,float,int,int);
void Animation_AddTrigger_6 (int,float,int,int);
void Animation_AddTrigger_7 (int,float,int,int);
void Animation_AddTrigger_8 (int,float,int,int);
void Animation_AddTrigger_9 (int,float,int,int);
void Animation_AddTrigger_10 (int,float,int,int);
void Animation_AddTrigger_11 (int,float,int,int);
void Animation_AddTrigger_12 (int,float,int,float);
void Animation_AddTrigger_13 (int,float,int,int);
void Animation_AddTrigger_14 (int,float,int,int);
void Animation_RemoveTrigger (int,int);
void Animation_RemoveAllTriggers (int);
void Animation_SetNumTriggers (int,int);
int Animation_Clone (int,int);
int Animation_GetAnimationName (int);
int Animation_GetAnimationNameHash (int);
float Animation_GetLength (int);
int Animation_GetNumTracks (int);
int Animation_GetTrack (int,int);
int Animation_GetTrack0 (int,int);
int Animation_GetTrack1 (int,int);
int Animation_GetNumTriggers (int);
int Animation_GetTrigger (int,int);
int ApplicationProxy_ApplicationProxy (int,int,int,int,int,int);
int Urho_GetPlatform ();
int Application_GetEngine (int);
int Application_GetType (int);
int Application_GetTypeName (int);
int Application_GetTypeStatic ();
int Application_GetTypeNameStatic ();
int Application_Run (int);
void Application_ErrorExit (int,int);
int AttributeInfo_GetType (int);
int AttributeInfo_GetName (int);
int BillboardSet_GetType (int);
int BillboardSet_GetTypeName (int);
int BillboardSet_GetTypeStatic ();
int BillboardSet_GetTypeNameStatic ();
int BillboardSet_BillboardSet (int);
void BillboardSet_RegisterObject (int);
int BillboardSet_GetUpdateGeometryType (int);
void BillboardSet_SetMaterial (int,int);
void BillboardSet_SetNumBillboards (int,int);
void BillboardSet_SetRelative (int,int);
void BillboardSet_SetScaled (int,int);
void BillboardSet_SetSorted (int,int);
void BillboardSet_SetFixedScreenSize (int,int);
void BillboardSet_SetFaceCameraMode (int,int);
void BillboardSet_SetMinAngle (int,float);
void BillboardSet_SetAnimationLodBias (int,float);
void BillboardSet_Commit (int);
int BillboardSet_GetMaterial (int);
int BillboardSet_GetNumBillboards (int);
int BillboardSet_GetBillboard (int,int);
int BillboardSet_IsRelative (int);
int BillboardSet_IsScaled (int);
int BillboardSet_IsSorted (int);
int BillboardSet_IsFixedScreenSize (int);
int BillboardSet_GetFaceCameraMode (int);
float BillboardSet_GetMinAngle (int);
float BillboardSet_GetAnimationLodBias (int);
int BillboardSet_GetMaterialAttr (int);
void Camera_SetViewOverrideFlags (int,int);
int Camera_GetViewOverrideFlags (int);
int Camera_GetType (int);
int Camera_GetTypeName (int);
int Camera_GetTypeStatic ();
int Camera_GetTypeNameStatic ();
int Camera_Camera (int);
void Camera_RegisterObject (int);
void Camera_DrawDebugGeometry (int,int,int);
void Camera_SetNearClip (int,float);
void Camera_SetFarClip (int,float);
void Camera_SetFov (int,float);
void Camera_SetOrthoSize (int,float);
void Camera_SetOrthoSize0 (int,int);
void Camera_SetAspectRatio (int,float);
void Camera_SetFillMode (int,int);
void Camera_SetZoom (int,float);
void Camera_SetLodBias (int,float);
void Camera_SetViewMask (int,int);
void Camera_SetOrthographic (int,int);
void Camera_SetAutoAspectRatio (int,int);
void Camera_SetProjectionOffset (int,int);
void Camera_SetUseReflection (int,int);
void Camera_SetReflectionPlane (int,int);
void Camera_SetUseClipping (int,int);
void Camera_SetClipPlane (int,int);
void Camera_SetFlipVertical (int,int);
void Camera_SetProjection (int,int);
float Camera_GetFarClip (int);
float Camera_GetNearClip (int);
float Camera_GetFov (int);
float Camera_GetOrthoSize (int);
float Camera_GetAspectRatio (int);
float Camera_GetZoom (int);
float Camera_GetLodBias (int);
int Camera_GetViewMask (int);
int Camera_GetFillMode (int);
int Camera_IsOrthographic (int);
int Camera_GetAutoAspectRatio (int);
int Camera_GetFrustum (int);
int Camera_GetProjection (int);
int Camera_GetGPUProjection (int);
int Camera_GetView (int);
float Camera_GetHalfViewSize (int);
int Camera_GetSplitFrustum (int,float,float);
int Camera_GetViewSpaceFrustum (int);
int Camera_GetViewSpaceSplitFrustum (int,float,float);
int Camera_GetScreenRay (int,float,float);
int Camera_WorldToScreenPoint (int,int);
int Camera_ScreenToWorldPoint (int,int);
int Camera_GetProjectionOffset (int);
int Camera_GetUseReflection (int);
int Camera_GetReflectionPlane (int);
int Camera_GetUseClipping (int);
int Camera_GetClipPlane (int);
int Camera_GetFlipVertical (int);
int Camera_GetReverseCulling (int);
float Camera_GetDistance (int,int);
float Camera_GetDistanceSquared (int,int);
float Camera_GetLodDistance (int,float,float,float);
int Camera_GetFaceCameraRotation (int,int,int,int,float);
int Camera_GetEffectiveWorldTransform (int);
int Camera_IsProjectionValid (int);
void Camera_SetAspectRatioInternal (int,float);
void Camera_SetOrthoSizeAttr (int,float);
void Camera_SetReflectionPlaneAttr (int,int);
int Camera_GetReflectionPlaneAttr (int);
void Camera_SetClipPlaneAttr (int,int);
int Camera_GetClipPlaneAttr (int);
int Component_GetType (int);
int Component_GetTypeName (int);
int Component_GetTypeStatic ();
int Component_GetTypeNameStatic ();
int Component_Component (int);
void Component_RegisterObject (int);
void Component_OnSetEnabled (int);
int Component_Save_File (int,int);
int Component_Save_MemoryBuffer (int,int);
int Component_SaveXML (int,int);
void Component_MarkNetworkUpdate (int);
void Component_DrawDebugGeometry (int,int,int);
void Component_SetEnabled (int,int);
void Component_Remove (int);
int Component_GetID (int);
int Component_IsReplicated (int);
int Component_GetNode (int);
int Component_GetScene (int);
int Component_IsEnabled (int);
int Component_IsEnabledEffective (int);
int Component_GetComponent (int,int);
void Component_AddReplicationState (int,int);
void Component_PrepareNetworkUpdate (int);
void Component_CleanupConnection (int,int);
int Component_GetVar0 (int,int);
void Component_SetVar_0 (int,int,int);
void Component_SetVar_1 (int,int,int);
void Component_SetVar_2 (int,int,int);
void Component_SetVar_3 (int,int,int);
void Component_SetVar_4 (int,int,int);
void Component_SetVar_5 (int,int,int);
void Component_SetVar_6 (int,int,int);
void Component_SetVar_7 (int,int,int);
void Component_SetVar_8 (int,int,int);
void Component_SetVar_9 (int,int,int);
void Component_SetVar_10 (int,int,int);
void Component_SetVar_11 (int,int,int);
void Component_SetVar_12 (int,int,float);
void Component_SetVar_13 (int,int,int);
void Component_SetVar_14 (int,int,int);
void Component_SetVar1_0 (int,int,int);
void Component_SetVar1_1 (int,int,int);
void Component_SetVar1_2 (int,int,int);
void Component_SetVar1_3 (int,int,int);
void Component_SetVar1_4 (int,int,int);
void Component_SetVar1_5 (int,int,int);
void Component_SetVar1_6 (int,int,int);
void Component_SetVar1_7 (int,int,int);
void Component_SetVar1_8 (int,int,int);
void Component_SetVar1_9 (int,int,int);
void Component_SetVar1_10 (int,int,int);
void Component_SetVar1_11 (int,int,int);
void Component_SetVar1_12 (int,int,float);
void Component_SetVar1_13 (int,int,int);
void Component_SetVar1_14 (int,int,int);
int Component_HasVar (int,int);
int Component_HasVar2 (int,int);
int AttributeVector_GetSize (int);
int AttributeVector_Attribute_GetType (int,int);
int AttributeVector_Attribute_GetName (int,int);
int AttributeVector_Attribute_GetMode (int,int);
void AttributeVector_Attribute_GetEnumNames (int,int,int);
int AttributeVector_Attribute_GetDefaultValue (int,int);
int Context_GetAttributes (int,int);
int Context_Context ();
int Context_CreateObject (int,int);
void Context_RegisterFactory (int,int);
void Context_RegisterSubsystem (int,int);
void Context_RemoveSubsystem (int,int);
void Context_RemoveAllAttributes (int,int);
int Context_RequireSDL (int,int);
void Context_ReleaseSDL (int);
void Context_CopyBaseAttributes (int,int,int);
int Context_GetSubsystem (int,int);
void Context_SetGlobalVar_0 (int,int,int);
void Context_SetGlobalVar_1 (int,int,int);
void Context_SetGlobalVar_2 (int,int,int);
void Context_SetGlobalVar_3 (int,int,int);
void Context_SetGlobalVar_4 (int,int,int);
void Context_SetGlobalVar_5 (int,int,int);
void Context_SetGlobalVar_6 (int,int,int);
void Context_SetGlobalVar_7 (int,int,int);
void Context_SetGlobalVar_8 (int,int,int);
void Context_SetGlobalVar_9 (int,int,int);
void Context_SetGlobalVar_10 (int,int,int);
void Context_SetGlobalVar_11 (int,int,int);
void Context_SetGlobalVar_12 (int,int,float);
void Context_SetGlobalVar_13 (int,int,int);
void Context_SetGlobalVar_14 (int,int,int);
int Context_GetEventSender (int);
int Context_GetEventHandler (int);
int Context_GetTypeName (int,int);
int Context_GetEventReceivers (int,int,int);
int Context_GetEventReceivers0 (int,int);
void Context_RegisterPlugin (int,int);
void Context_RemovePlugin (int,int);
int Context_GetPlugin (int,int);
int Context_PostCommandToPlugin (int,int,int);
void Context_PopulateByCategory (int,int);
int Context_GetObjectCountInLastPopulatedCetegory (int);
int Context_GetObjectInLastPopulatedCetegory (int,int);
void Context_ClearLastPopulatedCategory (int);
int Context_GetCetegoriesSize (int);
int Context_GetCategory (int,int);
void Controls_Destroy (int);
int Controls_Create ();
int Controls_GetButtons (int);
void Controls_SetButtons (int,int);
float Controls_GetYaw (int);
void Controls_SetYaw (int,float);
float Controls_GetPitch (int);
void Controls_SetPitch (int,float);
void Controls_Reset (int);
void Controls_Set (int,int,int);
int Controls_IsDown (int,int);
int sqlite3_connection_finalize (int);
int sqlite3_connection_column_count (int);
int sqlite3_connection_column_name (int,int);
int sqlite3_connection_column_step (int);
int sqlite3_connection_column_type (int,int);
int sqlite3_connection_column_int (int,int);
double sqlite3_connection_column_double (int,int);
int sqlite3_connection_column_decltype (int,int);
int sqlite3_connection_column_text (int,int);
int sqlite3_connection_prepare (int,int);
int sqlite3_connection_changes (int);
int DbConnection_GetSQLite3Implementation (int);
int DbConnection_GetType (int);
int DbConnection_GetTypeName (int);
int DbConnection_GetTypeStatic ();
int DbConnection_GetTypeNameStatic ();
int DbConnection_DbConnection (int,int);
void DbConnection_Finalize (int);
int DbConnection_GetConnectionString (int);
int DbConnection_IsConnected (int);
int Dynamic_CreateBuffer (int,int);
int Dynamic_CreateFromType (int,int);
int Dynamic_CreateVariant (int);
int Dynamic_CreateBool (int);
int Dynamic_CreateInt (int);
int Dynamic_CreateUInt (int);
int Dynamic_CreateInt64 (int64_t);
int Dynamic_CreateUInt64 (uint64_t);
int Dynamic_CreateFloat (float);
int Dynamic_CreateVector2 (int);
int Dynamic_CreateVector3 (int);
int Dynamic_CreateVector4 (int);
int Dynamic_CreateQuaternion (int);
int Dynamic_CreateColor (int);
int Dynamic_CreateDouble (double);
int Dynamic_CreateString (int);
int Dynamic_GetString (int);
int Dynamic_CreateIntVector2 (int);
int Dynamic_CreateIntVector3 (int);
int Dynamic_CreateIntRect (int);
int Dynamic_CreateRect (int);
int Dynamic_CreateMatrix3 (int);
int Dynamic_GetMatrix3 (int);
int Dynamic_CreateMatrix4 (int);
int Dynamic_GetMatrix4 (int);
int Dynamic_CreateMatrix3x4 (int);
int Dynamic_GetMatrix3x4 (int);
void Dynamic_Dispose (int);
int Dynamic_GetBuffer (int,int);
int Dynamic_CreateResourceRef (int,int);
int Dynamic_GetResourceRef (int);
int Dynamic_CreateResourceRefList (int,int);
void Dynamic_ResourceRefList_AddName (int,int);
int Dynamic_CreateVariantVector (int);
void Dynamic_VariantVector_AddVariant (int,int,int);
void Dynamic_GetRetVariant (int,int);
int Frustum_GetVertices (int,int);
int Frustum_GetPlanes (int,int);
int Frustum_Frustum ();
int Frustum_Frustum0 (int);
void Frustum_Define (int,float,float,float,float,float,int);
void Frustum_Define1 (int,int,int,int);
void Frustum_Define2 (int,int,int);
void Frustum_Define3 (int,int);
void Frustum_DefineOrtho (int,float,float,float,float,float,int);
void Frustum_DefineSplit (int,int,float,float);
void Frustum_Transform (int,int);
void Frustum_Transform4 (int,int);
int Frustum_IsInside (int,int);
int Frustum_IsInside5 (int,int);
int Frustum_IsInsideFast (int,int);
int Frustum_IsInside6 (int,int);
int Frustum_IsInsideFast7 (int,int);
float Frustum_Distance (int,int);
int Frustum_Transformed (int,int);
int Frustum_Transformed8 (int,int);
int Frustum_Projected (int,int);
void Frustum_UpdatePlanes (int);
int GPUObject_GPUObject (int);
void GPUObject_OnDeviceLost (int);
void GPUObject_OnDeviceReset (int);
void GPUObject_Release (int);
void GPUObject_ClearDataLost (int);
int GPUObject_GetGraphics (int);
int GPUObject_GetGPUObject (int);
int GPUObject_GetGPUObjectName (int);
int GPUObject_IsDataLost (int);
int GPUObject_HasPendingData (int);
int Graphics_GetSdlWindow (int);
int Graphics_GetMultiSampleLevels (int,int);
int Graphics_GetType (int);
int Graphics_GetTypeName (int);
int Graphics_GetTypeStatic ();
int Graphics_GetTypeNameStatic ();
int Graphics_Graphics (int);
void Graphics_SetExternalWindow (int,int);
void Graphics_SetWindowTitle (int,int);
void Graphics_SetWindowIcon (int,int);
void Graphics_SetWindowPosition (int,int);
void Graphics_SetWindowPosition0 (int,int,int);
int Graphics_SetScreenMode (int,int,int);
int Graphics_SetMode (int,int,int,int,int,int,int,int,int,int,int,int);
int Graphics_SetMode1 (int,int,int);
void Graphics_SetSRGB (int,int);
void Graphics_SetDither (int,int);
void Graphics_SetFlushGPU (int,int);
void Graphics_SetOrientations (int,int);
int Graphics_ToggleFullscreen (int);
void Graphics_Close (int);
int Graphics_TakeScreenShot (int,int);
int Graphics_BeginFrame (int);
void Graphics_EndFrame (int);
int Graphics_ResolveToTexture (int,int,int);
int Graphics_ResolveToTexture2 (int,int);
int Graphics_ResolveToTexture3 (int,int);
void Graphics_Draw (int,int,int,int);
void Graphics_Draw4 (int,int,int,int,int,int);
void Graphics_Draw5 (int,int,int,int,int,int,int);
void Graphics_DrawInstanced (int,int,int,int,int,int,int);
void Graphics_DrawInstanced6 (int,int,int,int,int,int,int,int);
void Graphics_SetVertexBuffer (int,int);
void Graphics_SetIndexBuffer (int,int);
void Graphics_SetShaders (int,int,int);
void Graphics_SetShaderParameter (int,int,int,int);
void Graphics_SetShaderParameter7 (int,int,float);
void Graphics_SetShaderParameter8 (int,int,int);
void Graphics_SetShaderParameter9 (int,int,int);
void Graphics_SetShaderParameter10 (int,int,int);
void Graphics_SetShaderParameter11 (int,int,int);
void Graphics_SetShaderParameter12 (int,int,int);
void Graphics_SetShaderParameter13 (int,int,int);
void Graphics_SetShaderParameter14 (int,int,int);
void Graphics_SetShaderParameter15 (int,int,int);
void Graphics_SetShaderParameter16 (int,int,int);
int Graphics_NeedParameterUpdate (int,int,int);
int Graphics_HasShaderParameter (int,int);
int Graphics_HasTextureUnit (int,int);
void Graphics_ClearParameterSource (int,int);
void Graphics_ClearParameterSources (int);
void Graphics_ClearTransformSources (int);
void Graphics_SetTexture (int,int,int);
void Graphics_SetTextureParametersDirty (int);
void Graphics_SetDefaultTextureFilterMode (int,int);
void Graphics_SetDefaultTextureAnisotropy (int,int);
void Graphics_ResetRenderTargets (int);
void Graphics_ResetRenderTarget (int,int);
void Graphics_ResetDepthStencil (int);
void Graphics_SetRenderTarget (int,int,int);
void Graphics_SetRenderTarget17 (int,int,int);
void Graphics_SetDepthStencil (int,int);
void Graphics_SetDepthStencil18 (int,int);
void Graphics_SetViewport (int,int);
void Graphics_SetBlendMode (int,int,int);
void Graphics_SetColorWrite (int,int);
void Graphics_SetCullMode (int,int);
void Graphics_SetDepthBias (int,float,float);
void Graphics_SetDepthTest (int,int);
void Graphics_SetDepthWrite (int,int);
void Graphics_SetFillMode (int,int);
void Graphics_SetLineAntiAlias (int,int);
void Graphics_SetScissorTest (int,int,int);
void Graphics_SetStencilTest (int,int,int,int,int,int,int,int,int);
void Graphics_SetClipPlane (int,int,int,int,int);
void Graphics_BeginDumpShaders (int,int);
void Graphics_EndDumpShaders (int);
void Graphics_PrecacheShaders_File (int,int);
void Graphics_PrecacheShaders_MemoryBuffer (int,int);
void Graphics_SetShaderCacheDir (int,int);
int Graphics_IsInitialized (int);
int Graphics_GetImpl (int);
int Graphics_GetExternalWindow (int);
int Graphics_GetWindowTitle (int);
int Graphics_GetApiName (int);
int Graphics_GetWindowPosition (int);
int Graphics_GetWidth (int);
int Graphics_GetHeight (int);
int Graphics_GetMultiSample (int);
int Graphics_GetSize (int);
int Graphics_GetFullscreen (int);
int Graphics_GetBorderless (int);
int Graphics_GetResizable (int);
int Graphics_GetHighDPI (int);
int Graphics_GetVSync (int);
int Graphics_GetRefreshRate (int);
int Graphics_GetMonitor (int);
int Graphics_GetTripleBuffer (int);
int Graphics_GetSRGB (int);
int Graphics_GetDither (int);
int Graphics_GetFlushGPU (int);
int Graphics_GetOrientations (int);
int Graphics_IsDeviceLost (int);
int Graphics_GetNumPrimitives (int);
int Graphics_GetNumBatches (int);
int Graphics_GetDummyColorFormat (int);
int Graphics_GetShadowMapFormat (int);
int Graphics_GetHiresShadowMapFormat (int);
int Graphics_GetInstancingSupport (int);
int Graphics_GetDrawBuffersSupport (int);
int Graphics_GetLightPrepassSupport (int);
int Graphics_GetDeferredSupport (int);
int Graphics_GetHardwareShadowSupport (int);
int Graphics_GetReadableDepthSupport (int);
int Graphics_GetSRGBSupport (int);
int Graphics_GetSRGBWriteSupport (int);
int Graphics_FindBestResolutionIndex (int,int,int,int,int);
int Graphics_GetDesktopResolution (int,int);
int Graphics_GetMonitorCount (int);
int Graphics_GetCurrentMonitor (int);
int Graphics_GetMaximized (int);
int Graphics_GetDisplayDPI (int,int);
int Graphics_GetFormat (int,int);
int Graphics_GetShader (int,int,int,int);
int Graphics_GetVertexBuffer (int,int);
int Graphics_GetIndexBuffer (int);
int Graphics_GetVertexShader (int);
int Graphics_GetPixelShader (int);
int Graphics_GetTextureUnit (int,int);
int Graphics_GetTextureUnitName (int,int);
int Graphics_GetTexture (int,int);
int Graphics_GetDefaultTextureFilterMode (int);
int Graphics_GetDefaultTextureAnisotropy (int);
int Graphics_GetRenderTarget (int,int);
int Graphics_GetDepthStencil (int);
int Graphics_GetViewport (int);
int Graphics_GetBlendMode (int);
int Graphics_GetAlphaToCoverage (int);
int Graphics_GetColorWrite (int);
int Graphics_GetCullMode (int);
float Graphics_GetDepthConstantBias (int);
float Graphics_GetDepthSlopeScaledBias (int);
int Graphics_GetDepthTest (int);
int Graphics_GetDepthWrite (int);
int Graphics_GetFillMode (int);
int Graphics_GetLineAntiAlias (int);
int Graphics_GetStencilTest (int);
int Graphics_GetScissorTest (int);
int Graphics_GetScissorRect (int);
int Graphics_GetStencilTestMode (int);
int Graphics_GetStencilPass (int);
int Graphics_GetStencilFail (int);
int Graphics_GetStencilZFail (int);
int Graphics_GetStencilRef (int);
int Graphics_GetStencilCompareMask (int);
int Graphics_GetStencilWriteMask (int);
int Graphics_GetUseClipPlane (int);
int Graphics_GetShaderCacheDir (int);
int Graphics_GetRenderTargetDimensions (int);
void Graphics_OnWindowResized (int);
void Graphics_OnWindowMoved (int);
void Graphics_Maximize (int);
void Graphics_Minimize (int);
void Graphics_Raise (int);
void Graphics_AddGPUObject (int,int);
void Graphics_RemoveGPUObject (int,int);
int Graphics_ReserveScratchBuffer (int,int);
void Graphics_FreeScratchBuffer (int,int);
void Graphics_CleanupScratchBuffers (int);
int Graphics_GetRendererName (int);
int Graphics_GetVersionString (int);
int Graphics_glOESStandardDerivativesSupport (int);
int Graphics_clipDistanceEXTSupport (int);
int Graphics_clipDistanceAPPLESupport (int);
int Graphics_GetAlphaFormat ();
int Graphics_GetLuminanceFormat ();
int Graphics_GetLuminanceAlphaFormat ();
int Graphics_GetRGBFormat ();
int Graphics_GetRGBAFormat ();
int Graphics_GetRGBA16Format ();
int Graphics_GetRGBAFloat16Format ();
int Graphics_GetRGBAFloat32Format ();
int Graphics_GetRG16Format ();
int Graphics_GetRGFloat16Format ();
int Graphics_GetRGFloat32Format ();
int Graphics_GetFloat16Format ();
int Graphics_GetFloat32Format ();
int Graphics_GetLinearDepthFormat ();
int Graphics_GetDepthStencilFormat ();
int Graphics_GetReadableDepthFormat ();
int Graphics_GetFormat19 (int);
int Graphics_GetPixelUVOffset ();
int Graphics_GetMaxBones ();
int IndexBuffer_CastToGPUObject (int);
int IndexBuffer_GetType (int);
int IndexBuffer_GetTypeName (int);
int IndexBuffer_GetTypeStatic ();
int IndexBuffer_GetTypeNameStatic ();
int IndexBuffer_IndexBuffer (int,int);
void IndexBuffer_OnDeviceLost (int);
void IndexBuffer_Release (int);
void IndexBuffer_SetShadowed (int,int);
int IndexBuffer_SetSize (int,int,int,int);
int IndexBuffer_SetData (int,int);
int IndexBuffer_SetDataRange (int,int,int,int,int);
int IndexBuffer_Lock (int,int,int,int);
void IndexBuffer_Unlock (int);
int IndexBuffer_IsShadowed (int);
int IndexBuffer_IsDynamic (int);
int IndexBuffer_IsLocked (int);
int IndexBuffer_GetIndexCount (int);
int IndexBuffer_GetIndexSize (int);
int IndexBuffer_GetShadowData (int);
int Input_GetType (int);
int Input_GetTypeName (int);
int Input_GetTypeStatic ();
int Input_GetTypeNameStatic ();
int Input_Input (int);
void Input_Update (int);
void Input_SetToggleFullscreen (int,int);
void Input_SetMouseVisible (int,int,int);
void Input_ResetMouseVisible (int);
void Input_SetMouseGrabbed (int,int,int);
void Input_ResetMouseGrabbed (int);
void Input_SetMouseMode (int,int,int);
void Input_ResetMouseMode (int);
int Input_AddScreenJoystick (int,int,int);
int Input_RemoveScreenJoystick (int,int);
void Input_SetScreenJoystickVisible (int,int,int);
void Input_SetScreenKeyboardVisible (int,int);
void Input_SetTouchEmulation (int,int);
int Input_RecordGesture (int);
int Input_SaveGestures_File (int,int);
int Input_SaveGestures_MemoryBuffer (int,int);
int Input_SaveGesture_File (int,int,int);
int Input_SaveGesture_MemoryBuffer (int,int,int);
int Input_LoadGestures_File (int,int);
int Input_LoadGestures_MemoryBuffer (int,int);
int Input_RemoveGesture (int,int);
void Input_RemoveAllGestures (int);
void Input_SetMousePosition (int,int);
void Input_CenterMousePosition (int);
int Input_GetKeyFromName (int,int);
int Input_GetKeyFromScancode (int,int);
int Input_GetKeyName (int,int);
int Input_GetScancodeFromKey (int,int);
int Input_GetScancodeFromName (int,int);
int Input_GetScancodeName (int,int);
int Input_GetKeyDown (int,int);
int Input_GetKeyPress (int,int);
int Input_GetScancodeDown (int,int);
int Input_GetScancodePress (int,int);
int Input_GetQualifierDown (int,int);
int Input_GetQualifierPress (int,int);
int Input_GetMousePosition (int);
int Input_GetMouseMove (int);
int Input_GetMouseMoveX (int);
int Input_GetMouseMoveY (int);
int Input_GetMouseMoveWheel (int);
int Input_GetInputScale (int);
int Input_GetNumTouches (int);
int Input_GetTouch (int,int);
int Input_GetNumJoysticks (int);
int Input_GetJoystick (int,int);
int Input_GetJoystickByIndex (int,int);
int Input_GetJoystickByName (int,int);
int Input_GetToggleFullscreen (int);
int Input_IsScreenJoystickVisible (int,int);
int Input_GetScreenKeyboardSupport (int);
int Input_IsScreenKeyboardVisible (int);
int Input_GetTouchEmulation (int);
int Input_IsMouseVisible (int);
int Input_IsMouseGrabbed (int);
int Input_IsMouseLocked (int);
int Input_GetMouseMode (int);
int Input_HasFocus (int);
int Input_IsMinimized (int);
void Input_MapCtrlQualifierToCommandKey (int,int);
int Input_IsMapCtrlQualifierToCommandKey (int);
int Input_GetMouseButtonDown (int,int);
int Input_GetMouseButtonPress (int,int);
void KinematicCharacterController_GetTransform (int,int,int);
int KinematicCharacterController_GetType (int);
int KinematicCharacterController_GetTypeName (int);
int KinematicCharacterController_GetTypeStatic ();
int KinematicCharacterController_GetTypeNameStatic ();
int KinematicCharacterController_KinematicCharacterController (int);
void KinematicCharacterController_RegisterObject (int);
void KinematicCharacterController_ApplyAttributes (int);
int KinematicCharacterController_GetPosition (int);
int KinematicCharacterController_GetRotation (int);
void KinematicCharacterController_SetTransform (int,int,int);
void KinematicCharacterController_SetCollisionLayer (int,int);
int KinematicCharacterController_GetCollisionLayer (int);
void KinematicCharacterController_SetCollisionMask (int,int);
int KinematicCharacterController_GetCollisionMask (int);
void KinematicCharacterController_SetCollisionLayerAndMask (int,int,int);
void KinematicCharacterController_SetGravity (int,int);
int KinematicCharacterController_GetGravity (int);
void KinematicCharacterController_SetLinearDamping (int,float);
float KinematicCharacterController_GetLinearDamping (int);
void KinematicCharacterController_SetAngularDamping (int,float);
float KinematicCharacterController_GetAngularDamping (int);
void KinematicCharacterController_SetStepHeight (int,float);
float KinematicCharacterController_GetStepHeight (int);
void KinematicCharacterController_SetMaxJumpHeight (int,float);
float KinematicCharacterController_GetMaxJumpHeight (int);
void KinematicCharacterController_SetFallSpeed (int,float);
float KinematicCharacterController_GetFallSpeed (int);
void KinematicCharacterController_SetJumpSpeed (int,float);
float KinematicCharacterController_GetJumpSpeed (int);
void KinematicCharacterController_SetMaxSlope (int,float);
float KinematicCharacterController_GetMaxSlope (int);
void KinematicCharacterController_SetWalkDirection (int,int);
int KinematicCharacterController_OnGround (int);
void KinematicCharacterController_Jump (int,int);
void KinematicCharacterController_ApplyImpulse (int,int);
int KinematicCharacterController_CanJump (int);
void KinematicCharacterController_SetAngularVelocity (int,int);
int KinematicCharacterController_GetAngularVelocity (int);
void KinematicCharacterController_SetLinearVelocity (int,int);
int KinematicCharacterController_GetLinearVelocity (int);
void KinematicCharacterController_Warp (int,int);
void KinematicCharacterController_DrawDebugGeometry (int);
int LogicComponent_GetType (int);
int LogicComponent_GetTypeName (int);
int LogicComponent_GetTypeStatic ();
int LogicComponent_GetTypeNameStatic ();
int LogicComponent_LogicComponent (int);
void LogicComponent_OnSetEnabled (int);
void LogicComponent_Start (int);
void LogicComponent_DelayedStart (int);
void LogicComponent_Stop (int);
void LogicComponent_Update (int,float);
void LogicComponent_PostUpdate (int,float);
void LogicComponent_FixedUpdate (int,float);
void LogicComponent_FixedPostUpdate (int,float);
int LogicComponent_IsDelayedStartCalled (int);
int Material_GetShaderParameterKeysSize (int);
void Material_GetShaderParameterGetKeys (int,int);
int Material_GetMaterialShaderParameterPtr (int,int);
int Material_GetShaderParameterColor (int,int);
int Material_GetType (int);
int Material_GetTypeName (int);
int Material_GetTypeStatic ();
int Material_GetTypeNameStatic ();
int Material_Material (int);
void Material_RegisterObject (int);
int Material_BeginLoad_File (int,int);
int Material_BeginLoad_MemoryBuffer (int,int);
int Material_EndLoad (int);
int Material_Save_File (int,int);
int Material_Save_MemoryBuffer (int,int);
int Material_Load (int,int);
int Material_Save0 (int,int);
void Material_SetNumTechniques (int,int);
void Material_SetTechnique (int,int,int,int,float);
void Material_SetVertexShaderDefines (int,int);
void Material_SetPixelShaderDefines (int,int);
void Material_SetShaderParameter_0 (int,int,int);
void Material_SetShaderParameter_1 (int,int,int);
void Material_SetShaderParameter_2 (int,int,int);
void Material_SetShaderParameter_3 (int,int,int);
void Material_SetShaderParameter_4 (int,int,int);
void Material_SetShaderParameter_5 (int,int,int);
void Material_SetShaderParameter_6 (int,int,int);
void Material_SetShaderParameter_7 (int,int,int);
void Material_SetShaderParameter_8 (int,int,int);
void Material_SetShaderParameter_9 (int,int,int);
void Material_SetShaderParameter_10 (int,int,int);
void Material_SetShaderParameter_11 (int,int,int);
void Material_SetShaderParameter_12 (int,int,float);
void Material_SetShaderParameter_13 (int,int,int);
void Material_SetShaderParameter_14 (int,int,int);
void Material_SetShaderParameterAnimation (int,int,int,int,float);
void Material_SetShaderParameterAnimationWrapMode (int,int,int);
void Material_SetShaderParameterAnimationSpeed (int,int,float);
void Material_SetTexture (int,int,int);
void Material_SetUVTransform (int,int,float,int);
void Material_SetUVTransform1 (int,int,float,float);
void Material_SetCullMode (int,int);
void Material_SetShadowCullMode (int,int);
void Material_SetFillMode (int,int);
void Material_SetDepthBias (int,int);
void Material_SetAlphaToCoverage (int,int);
void Material_SetLineAntiAlias (int,int);
void Material_SetRenderOrder (int,int);
void Material_SetOcclusion (int,int);
void Material_SetScene (int,int);
void Material_RemoveShaderParameter (int,int);
void Material_ReleaseShaders (int);
int Material_Clone (int,int);
void Material_SortTechniques (int);
void Material_MarkForAuxView (int,int);
int Material_GetNumTechniques (int);
int Material_GetTechnique (int,int);
int Material_GetTechniqueOriginal (int,int);
float Material_GetTechniqueLodDistance (int,int);
int Material_GetTechniqueQualityLevel (int,int);
int Material_GetPass (int,int,int);
int Material_GetTexture (int,int);
int Material_GetVertexShaderDefines (int);
int Material_GetPixelShaderDefines (int);
int Material_GetShaderParameterPtr (int,int);
int Material_GetShaderParameterAnimation (int,int);
int Material_GetShaderParameterAnimationWrapMode (int,int);
float Material_GetShaderParameterAnimationSpeed (int,int);
int Material_GetCullMode (int);
int Material_GetShadowCullMode (int);
int Material_GetFillMode (int);
int Material_GetDepthBias (int);
int Material_GetAlphaToCoverage (int);
int Material_GetLineAntiAlias (int);
int Material_GetRenderOrder (int);
int Material_GetAuxViewFrameNumber (int);
int Material_GetOcclusion (int);
int Material_GetSpecular (int);
int Material_GetScene (int);
int Material_GetShaderParameterHash (int);
int Material_GetTextureUnitName (int);
int Material_ParseShaderParameterValue (int);
int MemoryBuffer_MemoryBuffer (int,int);
int MemoryBuffer_GetData (int,int);
int MemoryBuffer_GetSize (int);
int MemoryBuffer_Dispose (int);
int MemoryBuffer_GetString (int);
int Model_Clone_EmptyName (int);
int Model_GetSkeleton (int);
int Model_GetType (int);
int Model_GetTypeName (int);
int Model_GetTypeStatic ();
int Model_GetTypeNameStatic ();
int Model_Model (int);
void Model_RegisterObject (int);
int Model_BeginLoad_File (int,int);
int Model_BeginLoad_MemoryBuffer (int,int);
int Model_EndLoad (int);
int Model_Save_File (int,int);
int Model_Save_MemoryBuffer (int,int);
void Model_SetBoundingBox (int,int);
void Model_SetNumGeometries (int,int);
int Model_SetNumGeometryLodLevels (int,int,int);
int Model_SetGeometry (int,int,int,int);
int Model_SetGeometryCenter (int,int,int);
int Model_Clone (int,int);
int Model_GetBoundingBox (int);
int Model_GetVertexBuffers (int);
int Model_GetIndexBuffers (int);
int Model_GetNumGeometries (int);
int Model_GetNumGeometryLodLevels (int,int);
int Model_GetGeometry (int,int,int);
int Model_GetGeometryCenter (int,int);
int Model_GetNumMorphs (int);
int Model_GetMorph (int,int);
int Model_GetMorph0 (int,int);
int Model_GetMorph1 (int,int);
int Model_GetMorphRangeStart (int,int);
int Model_GetMorphRangeCount (int,int);
int Model_AddVertexBuffer (int,int,int,int);
int Model_AddIndexBuffer (int,int);
void Model_ClearGeometryBoneMappings (int);
void Model_AddGeometryBoneMapping (int,int,int);
int urho_node_get_components (int,int,int,int);
int Node_GetChildrenWithTag (int,int,int,int);
void Node_RemoveComponent22 (int,int);
int Node_GetVar (int,int);
int Node_GetTags (int);
int Node_GetVars (int);
int Node_GetType (int);
int Node_GetTypeName (int);
int Node_GetTypeStatic ();
int Node_GetTypeNameStatic ();
int Node_Node (int);
void Node_RegisterObject (int);
int Node_Load_File (int,int);
int Node_Load_MemoryBuffer (int,int);
int Node_LoadXML_File (int,int);
int Node_LoadXML_MemoryBuffer (int,int);
int Node_LoadJSON_File (int,int);
int Node_LoadJSON_MemoryBuffer (int,int);
int Node_LoadXML0 (int,int);
int Node_Save_File (int,int);
int Node_Save_MemoryBuffer (int,int);
int Node_SaveXML (int,int);
void Node_ApplyAttributes (int);
int Node_SaveDefaultAttributes (int);
void Node_MarkNetworkUpdate (int);
void Node_AddReplicationState (int,int);
int Node_SaveXML1_File (int,int,int);
int Node_SaveXML1_MemoryBuffer (int,int,int);
int Node_SaveJSON_File (int,int,int);
int Node_SaveJSON_MemoryBuffer (int,int,int);
void Node_SetName (int,int);
void Node_AddTag (int,int);
int Node_RemoveTag (int,int);
void Node_RemoveAllTags (int);
void Node_SetPosition (int,int);
void Node_SetPosition2D (int,int);
void Node_SetPosition2D2 (int,float,float);
void Node_SetRotation (int,int);
void Node_SetRotation2D (int,float);
void Node_SetDirection (int,int);
void Node_SetScale (int,float);
void Node_SetScale3 (int,int);
void Node_SetScale2D (int,int);
void Node_SetScale2D4 (int,float,float);
void Node_SetTransform (int,int,int);
void Node_SetTransform5 (int,int,int,float);
void Node_SetTransform6 (int,int,int,int);
void Node_SetTransform7 (int,int);
void Node_SetTransform2D (int,int,float);
void Node_SetTransform2D8 (int,int,float,float);
void Node_SetTransform2D9 (int,int,float,int);
void Node_SetWorldPosition (int,int);
void Node_SetWorldPosition2D (int,int);
void Node_SetWorldPosition2D10 (int,float,float);
void Node_SetWorldRotation (int,int);
void Node_SetWorldRotation2D (int,float);
void Node_SetWorldDirection (int,int);
void Node_SetWorldScale (int,float);
void Node_SetWorldScale11 (int,int);
void Node_SetWorldScale2D (int,int);
void Node_SetWorldScale2D12 (int,float,float);
void Node_SetWorldTransform (int,int,int);
void Node_SetWorldTransform13 (int,int,int,float);
void Node_SetWorldTransform14 (int,int,int,int);
void Node_SetWorldTransform15 (int,int);
void Node_SetWorldTransform2D (int,int,float);
void Node_SetWorldTransform2D16 (int,int,float,float);
void Node_SetWorldTransform2D17 (int,int,float,int);
void Node_Translate (int,int,int);
void Node_Translate2D (int,int,int);
void Node_Rotate (int,int,int);
void Node_Rotate2D (int,float,int);
void Node_RotateAround (int,int,int,int);
void Node_RotateAround2D (int,int,float,int);
void Node_Pitch (int,float,int);
void Node_Yaw (int,float,int);
void Node_Roll (int,float,int);
int Node_LookAt (int,int,int,int);
void Node_Scale (int,float);
void Node_Scale18 (int,int);
void Node_Scale2D (int,int);
void Node_SetEnabled (int,int);
void Node_SetDeepEnabled (int,int);
void Node_ResetDeepEnabled (int);
void Node_SetEnabledRecursive (int,int);
void Node_SetOwner (int,int);
void Node_MarkDirty (int);
int Node_CreateChild (int,int,int,int,int);
int Node_CreateTemporaryChild (int,int,int,int);
void Node_AddChild (int,int,int);
void Node_RemoveChild (int,int);
void Node_RemoveAllChildren (int);
void Node_RemoveChildren (int,int,int,int);
int Node_CreateComponent (int,int,int,int);
int Node_GetOrCreateComponent (int,int,int,int);
int Node_CloneComponent (int,int,int);
int Node_CloneComponent19 (int,int,int,int);
void Node_RemoveComponent (int,int);
void Node_RemoveComponents (int,int,int);
void Node_RemoveComponents20 (int,int);
void Node_RemoveAllComponents (int);
void Node_ReorderComponent (int,int,int);
int Node_Clone (int,int);
void Node_Remove (int);
void Node_SetParent (int,int);
void Node_SetVar_0 (int,int,int);
void Node_SetVar_1 (int,int,int);
void Node_SetVar_2 (int,int,int);
void Node_SetVar_3 (int,int,int);
void Node_SetVar_4 (int,int,int);
void Node_SetVar_5 (int,int,int);
void Node_SetVar_6 (int,int,int);
void Node_SetVar_7 (int,int,int);
void Node_SetVar_8 (int,int,int);
void Node_SetVar_9 (int,int,int);
void Node_SetVar_10 (int,int,int);
void Node_SetVar_11 (int,int,int);
void Node_SetVar_12 (int,int,float);
void Node_SetVar_13 (int,int,int);
void Node_SetVar_14 (int,int,int);
void Node_SetVar21_0 (int,int,int);
void Node_SetVar21_1 (int,int,int);
void Node_SetVar21_2 (int,int,int);
void Node_SetVar21_3 (int,int,int);
void Node_SetVar21_4 (int,int,int);
void Node_SetVar21_5 (int,int,int);
void Node_SetVar21_6 (int,int,int);
void Node_SetVar21_7 (int,int,int);
void Node_SetVar21_8 (int,int,int);
void Node_SetVar21_9 (int,int,int);
void Node_SetVar21_10 (int,int,int);
void Node_SetVar21_11 (int,int,int);
void Node_SetVar21_12 (int,int,float);
void Node_SetVar21_13 (int,int,int);
void Node_SetVar21_14 (int,int,int);
void Node_AddListener (int,int);
void Node_RemoveListener (int,int);
int Node_GetID (int);
int Node_IsReplicated (int);
int Node_GetName (int);
int Node_GetNameHash (int);
int Node_HasTag (int,int);
int Node_GetParent (int);
int Node_GetScene (int);
int Node_IsChildOf (int,int);
int Node_IsEnabled (int);
int Node_IsEnabledSelf (int);
int Node_GetOwner (int);
int Node_GetPosition (int);
int Node_GetPosition2D (int);
int Node_GetRotation (int);
float Node_GetRotation2D (int);
int Node_GetDirection (int);
int Node_GetUp (int);
int Node_GetRight (int);
int Node_GetScale (int);
int Node_GetScale2D (int);
int Node_GetTransform (int);
int Node_GetWorldPosition (int);
int Node_GetWorldPosition2D (int);
int Node_GetWorldRotation (int);
float Node_GetWorldRotation2D (int);
int Node_GetWorldDirection (int);
int Node_GetWorldUp (int);
int Node_GetWorldRight (int);
int Node_GetWorldScale (int);
int Node_GetSignedWorldScale (int);
int Node_GetWorldScale2D (int);
int Node_GetWorldTransform (int);
int Node_LocalToWorld (int,int);
int Node_LocalToWorld22 (int,int);
int Node_LocalToWorld2D (int,int);
int Node_WorldToLocal (int,int);
int Node_WorldToLocal23 (int,int);
int Node_WorldToLocal2D (int,int);
int Node_IsDirty (int);
int Node_GetNumChildren (int,int);
int Node_GetChildren (int);
int Node_GetChild (int,int);
int Node_GetChild24 (int,int,int);
int Node_GetChild25 (int,int,int);
int Node_GetNumComponents (int);
int Node_GetNumNetworkComponents (int);
int Node_GetComponents (int);
int Node_GetComponent (int,int,int);
int Node_GetParentComponent (int,int,int);
int Node_HasComponent (int,int);
int Node_GetVar26 (int,int);
void Node_SetID (int,int);
void Node_SetScene (int,int);
void Node_ResetScene (int);
void Node_SetNetPositionAttr (int,int);
int Node_GetNetPositionAttr (int);
void Node_PrepareNetworkUpdate (int);
void Node_CleanupConnection (int,int);
void Node_MarkReplicationDirty (int);
int Node_CreateChild27 (int,int,int,int);
void Node_AddComponent (int,int,int,int);
int Node_GetNumPersistentChildren (int);
int Node_GetNumPersistentComponents (int);
void Node_SetPositionSilent (int,int);
void Node_SetRotationSilent (int,int);
void Node_SetScaleSilent (int,int);
void Node_SetTransformSilent (int,int,int,int);
int Node_HasVar (int,int);
int Node_HasVar28 (int,int);
void FreeBuffer (int);
int urho_subscribe_global_event (int,int,int,int);
int urho_subscribe_event (int,int,int,int);
int UrhoObject_GetType (int);
int UrhoObject_GetTypeName (int);
int UrhoObject_GetTypeInfo (int);
int UrhoObject_GetTypeInfoStatic ();
int UrhoObject_IsInstanceOf (int,int);
int UrhoObject_IsInstanceOf0 (int,int);
void UrhoObject_SubscribeToEvent (int,int,int);
void UrhoObject_SubscribeToEvent1 (int,int,int,int);
void UrhoObject_UnsubscribeFromEvent (int,int);
void UrhoObject_UnsubscribeFromEvent2 (int,int,int);
void UrhoObject_UnsubscribeFromEvents (int,int);
void UrhoObject_UnsubscribeFromAllEvents (int);
void UrhoObject_SendEvent (int,int);
int UrhoObject_GetContext (int);
void UrhoObject_SetGlobalVar_0 (int,int,int);
void UrhoObject_SetGlobalVar_1 (int,int,int);
void UrhoObject_SetGlobalVar_2 (int,int,int);
void UrhoObject_SetGlobalVar_3 (int,int,int);
void UrhoObject_SetGlobalVar_4 (int,int,int);
void UrhoObject_SetGlobalVar_5 (int,int,int);
void UrhoObject_SetGlobalVar_6 (int,int,int);
void UrhoObject_SetGlobalVar_7 (int,int,int);
void UrhoObject_SetGlobalVar_8 (int,int,int);
void UrhoObject_SetGlobalVar_9 (int,int,int);
void UrhoObject_SetGlobalVar_10 (int,int,int);
void UrhoObject_SetGlobalVar_11 (int,int,int);
void UrhoObject_SetGlobalVar_12 (int,int,float);
void UrhoObject_SetGlobalVar_13 (int,int,int);
void UrhoObject_SetGlobalVar_14 (int,int,int);
int UrhoObject_GetSubsystem (int,int);
int UrhoObject_GetEventSender (int);
int UrhoObject_GetEventHandler (int);
int UrhoObject_HasSubscribedToEvent (int,int);
int UrhoObject_HasSubscribedToEvent3 (int,int,int);
int UrhoObject_HasEventHandlers (int);
int UrhoObject_GetCategory (int);
void UrhoObject_SetBlockEvents (int,int);
int UrhoObject_GetBlockEvents (int);
int UrhoObject_PostCommandToPlugin (int,int,int);
int UrhoObject_PostCommandToPlugin4 (int,int,int,int);
int Octree_Raycast (int,int,int,float,int,int,int,int);
int Octree_GetType (int);
int Octree_GetTypeName (int);
int Octree_GetTypeStatic ();
int Octree_GetTypeNameStatic ();
int Octree_Octree (int);
void Octree_RegisterObject (int);
void Octree_DrawDebugGeometry (int,int,int);
void Octree_SetSize (int,int,int);
void Octree_AddManualDrawable (int,int);
void Octree_RemoveManualDrawable (int,int);
int Octree_GetNumLevels (int);
void Octree_QueueUpdate (int,int);
void Octree_CancelUpdate (int,int);
void Octree_DrawDebugGeometry0 (int,int);
int Polyhedron_Polyhedron ();
int Polyhedron_Polyhedron0 (int);
int Polyhedron_Polyhedron1 (int);
int Polyhedron_Polyhedron2 (int);
void Polyhedron_Define (int,int);
void Polyhedron_Define3 (int,int);
void Polyhedron_AddFace (int,int,int,int);
void Polyhedron_AddFace4 (int,int,int,int,int);
void Polyhedron_Clip (int,int);
void Polyhedron_Clip5 (int,int);
void Polyhedron_Clip6 (int,int);
void Polyhedron_Clear (int);
void Polyhedron_Transform (int,int);
void Polyhedron_Transform7 (int,int);
int Polyhedron_Transformed (int,int);
int Polyhedron_Transformed8 (int,int);
int Polyhedron_Empty (int);
void Profiler_BeginBlock (int,int);
int Profiler_GetType (int);
int Profiler_GetTypeName (int);
int Profiler_GetTypeStatic ();
int Profiler_GetTypeNameStatic ();
int Profiler_Profiler (int);
void Profiler_EndBlock (int);
void Profiler_BeginFrame (int);
void Profiler_EndFrame (int);
void Profiler_BeginInterval (int);
int Profiler_PrintData (int,int,int,int);
int Profiler_GetCurrentBlock (int);
int Profiler_GetRootBlock (int);
int RefCount_RefCount ();
void TryDeleteRefCounted (int);
int RefCounted_RefCounted ();
void RefCounted_AddRef (int);
void RefCounted_ReleaseRef (int);
int RefCounted_Refs (int);
int RefCounted_WeakRefs (int);
int RefCounted_RefCountPtr (int);
int RenderPath_RenderPath ();
int RenderPath_Clone (int);
int RenderPath_Load (int,int);
int RenderPath_Append (int,int);
void RenderPath_SetEnabled (int,int,int);
int RenderPath_IsEnabled (int,int);
int RenderPath_IsAdded (int,int);
void RenderPath_ToggleEnabled (int,int);
void RenderPath_RemoveRenderTarget (int,int);
void RenderPath_RemoveRenderTarget0 (int,int);
void RenderPath_RemoveRenderTargets (int,int);
void RenderPath_SetCommand (int,int,int);
void RenderPath_AddCommand (int,int);
void RenderPath_InsertCommand (int,int,int);
void RenderPath_RemoveCommand (int,int);
void RenderPath_RemoveCommands (int,int);
void RenderPath_SetShaderParameter_0 (int,int,int);
void RenderPath_SetShaderParameter_1 (int,int,int);
void RenderPath_SetShaderParameter_2 (int,int,int);
void RenderPath_SetShaderParameter_3 (int,int,int);
void RenderPath_SetShaderParameter_4 (int,int,int);
void RenderPath_SetShaderParameter_5 (int,int,int);
void RenderPath_SetShaderParameter_6 (int,int,int);
void RenderPath_SetShaderParameter_7 (int,int,int);
void RenderPath_SetShaderParameter_8 (int,int,int);
void RenderPath_SetShaderParameter_9 (int,int,int);
void RenderPath_SetShaderParameter_10 (int,int,int);
void RenderPath_SetShaderParameter_11 (int,int,int);
void RenderPath_SetShaderParameter_12 (int,int,float);
void RenderPath_SetShaderParameter_13 (int,int,int);
void RenderPath_SetShaderParameter_14 (int,int,int);
int RenderPath_GetNumRenderTargets (int);
int RenderPath_GetNumCommands (int);
int RenderPath_GetCommand (int,int);
int SDL_SendWindowEvent (int,int,int,int);
int SDL_SendAppEvent (int);
int SDL_SendKeyboardKey (int,int);
void SDL_SetMainReady ();
void SDL_AudioQuit ();
void SDL_Quit ();
int Scene_LoadXMLFromCache (int,int,int);
int Scene_GetType (int);
int Scene_GetTypeName (int);
int Scene_GetTypeStatic ();
int Scene_GetTypeNameStatic ();
int Scene_Scene (int);
void Scene_RegisterObject (int);
int Scene_Load_File (int,int);
int Scene_Load_MemoryBuffer (int,int);
int Scene_Save_File (int,int);
int Scene_Save_MemoryBuffer (int,int);
int Scene_LoadXML (int,int);
void Scene_MarkNetworkUpdate (int);
void Scene_AddReplicationState (int,int);
int Scene_LoadXML0_File (int,int);
int Scene_LoadXML0_MemoryBuffer (int,int);
int Scene_LoadJSON_File (int,int);
int Scene_LoadJSON_MemoryBuffer (int,int);
int Scene_SaveXML_File (int,int,int);
int Scene_SaveXML_MemoryBuffer (int,int,int);
int Scene_SaveJSON_File (int,int,int);
int Scene_SaveJSON_MemoryBuffer (int,int,int);
int Scene_LoadAsync (int,int,int);
int Scene_LoadAsyncXML (int,int,int);
int Scene_LoadAsyncJSON (int,int,int);
int Scene_LoadAsyncNodeXML (int,int,int);
int Scene_LoadAsyncNodeXML1 (int,int,int);
int Scene_LoadAsyncNodeJSON (int,int,int);
int Scene_LoadAsyncNodeJSON2 (int,int,int);
int Scene_LoadAsyncNode (int,int,int);
int Scene_LoadAsyncNode3 (int,int,int);
void Scene_StopAsyncLoading (int);
int Scene_Instantiate_File (int,int,int,int,int);
int Scene_Instantiate_MemoryBuffer (int,int,int,int,int);
int Scene_InstantiateXML (int,int,int,int,int);
int Scene_InstantiateXML4_File (int,int,int,int,int);
int Scene_InstantiateXML4_MemoryBuffer (int,int,int,int,int);
int Scene_InstantiateJSON_File (int,int,int,int,int);
int Scene_InstantiateJSON_MemoryBuffer (int,int,int,int,int);
void Scene_Clear (int,int,int);
void Scene_SetUpdateEnabled (int,int);
void Scene_SetTimeScale (int,float);
void Scene_SetElapsedTime (int,float);
void Scene_SetSmoothingConstant (int,float);
void Scene_SetSnapThreshold (int,float);
void Scene_SetAsyncLoadingMs (int,int);
void Scene_SetAsyncIntervalMs (int,int);
void Scene_AddRequiredPackageFile (int,int);
void Scene_ClearRequiredPackageFiles (int);
void Scene_RegisterVar (int,int);
void Scene_UnregisterVar (int,int);
void Scene_UnregisterAllVars (int);
int Scene_GetNode (int,int);
int Scene_GetComponent (int,int);
int Scene_IsUpdateEnabled (int);
int Scene_IsAsyncLoading (int);
float Scene_GetAsyncProgress (int);
int Scene_GetAsyncLoadMode (int);
int Scene_GetFileName (int);
int Scene_GetChecksum (int);
float Scene_GetTimeScale (int);
float Scene_GetElapsedTime (int);
float Scene_GetSmoothingConstant (int);
float Scene_GetSnapThreshold (int);
int Scene_GetAsyncLoadingMs (int);
int Scene_GetAsyncIntervalMs (int);
int Scene_GetRequiredPackageFiles (int);
int Scene_GetVarName (int,int);
void Scene_Update (int,float);
void Scene_BeginThreadedUpdate (int);
void Scene_EndThreadedUpdate (int);
void Scene_DelayedMarkedDirty (int,int);
int Scene_IsThreadedUpdate (int);
int Scene_GetFreeNodeID (int,int);
int Scene_GetFreeComponentID (int,int);
int Scene_IsReplicatedID (int);
void Scene_NodeTagAdded (int,int,int);
void Scene_NodeTagRemoved (int,int,int);
void Scene_SetVarNamesAttr (int,int);
int Scene_GetVarNamesAttr (int);
void Scene_PrepareNetworkUpdate (int);
void Scene_CleanupConnection (int,int);
void Scene_MarkNetworkUpdate5 (int,int);
void Scene_MarkNetworkUpdate6 (int,int);
void Scene_MarkReplicationDirty (int,int);
int Serializable_SetAttribute_Variant (int,int,int);
int Serializable_SetAttribute_Variant2 (int,int,int);
int Serializable_SetAttribute_Variant3 (int,int,int);
int Serializable_SetAttribute_Variant4 (int,int,int);
int Serializable_GetAttributes (int);
int Serializable_GetType (int);
int Serializable_GetTypeName (int);
int Serializable_GetTypeStatic ();
int Serializable_GetTypeNameStatic ();
int Serializable_Serializable (int);
int Serializable_Load_File (int,int);
int Serializable_Load_MemoryBuffer (int,int);
int Serializable_Save_File (int,int);
int Serializable_Save_MemoryBuffer (int,int);
int Serializable_LoadXML (int,int);
int Serializable_SaveXML (int,int);
void Serializable_ApplyAttributes (int);
int Serializable_SaveDefaultAttributes (int);
void Serializable_MarkNetworkUpdate (int);
int Serializable_SetAttribute_0 (int,int,int);
int Serializable_SetAttribute_1 (int,int,int);
int Serializable_SetAttribute_2 (int,int,int);
int Serializable_SetAttribute_3 (int,int,int);
int Serializable_SetAttribute_4 (int,int,int);
int Serializable_SetAttribute_5 (int,int,int);
int Serializable_SetAttribute_6 (int,int,int);
int Serializable_SetAttribute_7 (int,int,int);
int Serializable_SetAttribute_8 (int,int,int);
int Serializable_SetAttribute_9 (int,int,int);
int Serializable_SetAttribute_10 (int,int,int);
int Serializable_SetAttribute_11 (int,int,int);
int Serializable_SetAttribute_12 (int,int,float);
int Serializable_SetAttribute_13 (int,int,int);
int Serializable_SetAttribute_14 (int,int,int);
int Serializable_SetAttribute0_0 (int,int,int);
int Serializable_SetAttribute0_1 (int,int,int);
int Serializable_SetAttribute0_2 (int,int,int);
int Serializable_SetAttribute0_3 (int,int,int);
int Serializable_SetAttribute0_4 (int,int,int);
int Serializable_SetAttribute0_5 (int,int,int);
int Serializable_SetAttribute0_6 (int,int,int);
int Serializable_SetAttribute0_7 (int,int,int);
int Serializable_SetAttribute0_8 (int,int,int);
int Serializable_SetAttribute0_9 (int,int,int);
int Serializable_SetAttribute0_10 (int,int,int);
int Serializable_SetAttribute0_11 (int,int,int);
int Serializable_SetAttribute0_12 (int,int,float);
int Serializable_SetAttribute0_13 (int,int,int);
int Serializable_SetAttribute0_14 (int,int,int);
void Serializable_SetInstanceDefault (int,int);
void Serializable_ResetToDefault (int);
void Serializable_RemoveInstanceDefault (int);
void Serializable_SetTemporary (int,int);
void Serializable_SetInterceptNetworkUpdate (int,int,int);
void Serializable_AllocateNetworkState (int);
void Serializable_WriteInitialDeltaUpdate_File (int,int,int);
void Serializable_WriteInitialDeltaUpdate_MemoryBuffer (int,int,int);
void Serializable_WriteLatestDataUpdate_File (int,int,int);
void Serializable_WriteLatestDataUpdate_MemoryBuffer (int,int,int);
int Serializable_ReadDeltaUpdate_File (int,int);
int Serializable_ReadDeltaUpdate_MemoryBuffer (int,int);
int Serializable_ReadLatestDataUpdate_File (int,int);
int Serializable_ReadLatestDataUpdate_MemoryBuffer (int,int);
int Serializable_GetAttribute (int,int);
int Serializable_GetAttribute1 (int,int);
int Serializable_GetAttributeDefault (int,int);
int Serializable_GetAttributeDefault2 (int,int);
int Serializable_GetNumAttributes (int);
int Serializable_GetNumNetworkAttributes (int);
int Serializable_IsTemporary (int);
int Serializable_GetInterceptNetworkUpdate (int,int);
int Serializable_GetNetworkState (int);
int Skeleton_GetBone0 (int,int);
int Skeleton_Load_File (int,int);
int Skeleton_Load_MemoryBuffer (int,int);
int Skeleton_Save_File (int,int);
int Skeleton_Save_MemoryBuffer (int,int);
void Skeleton_SetRootBoneIndex (int,int);
void Skeleton_ClearBones (int);
void Skeleton_Reset (int);
int Skeleton_GetNumBones (int);
int Skeleton_GetRootBone (int);
int Skeleton_GetBoneIndex (int,int);
int Skeleton_GetBoneIndex0 (int,int);
int Skeleton_GetBoneParent (int,int);
int Skeleton_GetBone (int,int);
void Skeleton_ResetSilent (int);
int Skeleton_CreateBone (int);
int AnimatedModel_GetSkeleton (int);
int AnimatedModel_GetType (int);
int AnimatedModel_GetTypeName (int);
int AnimatedModel_GetTypeStatic ();
int AnimatedModel_GetTypeNameStatic ();
int AnimatedModel_AnimatedModel (int);
void AnimatedModel_RegisterObject (int);
int AnimatedModel_Load_File (int,int);
int AnimatedModel_Load_MemoryBuffer (int,int);
int AnimatedModel_LoadXML (int,int);
void AnimatedModel_ApplyAttributes (int);
int AnimatedModel_GetUpdateGeometryType (int);
void AnimatedModel_DrawDebugGeometry (int,int,int);
void AnimatedModel_SetModel (int,int,int);
int AnimatedModel_AddAnimationState (int,int);
void AnimatedModel_RemoveAnimationState (int,int);
void AnimatedModel_RemoveAnimationState0 (int,int);
void AnimatedModel_RemoveAnimationState1 (int,int);
void AnimatedModel_RemoveAnimationState2 (int,int);
void AnimatedModel_RemoveAnimationState3 (int,int);
void AnimatedModel_RemoveAllAnimationStates (int);
void AnimatedModel_SetAnimationLodBias (int,float);
void AnimatedModel_SetUpdateInvisible (int,int);
void AnimatedModel_SetMorphWeight (int,int,float);
void AnimatedModel_SetMorphWeight4 (int,int,float);
void AnimatedModel_SetMorphWeight5 (int,int,float);
void AnimatedModel_ResetMorphWeights (int);
void AnimatedModel_ApplyAnimation (int);
int AnimatedModel_GetAnimationStates (int);
int AnimatedModel_GetNumAnimationStates (int);
int AnimatedModel_GetAnimationState (int,int);
int AnimatedModel_GetAnimationState6 (int,int);
int AnimatedModel_GetAnimationState7 (int,int);
int AnimatedModel_GetAnimationState8 (int,int);
float AnimatedModel_GetAnimationLodBias (int);
int AnimatedModel_GetUpdateInvisible (int);
int AnimatedModel_GetMorphVertexBuffers (int);
int AnimatedModel_GetNumMorphs (int);
float AnimatedModel_GetMorphWeight (int,int);
float AnimatedModel_GetMorphWeight9 (int,int);
float AnimatedModel_GetMorphWeight10 (int,int);
int AnimatedModel_IsMaster (int);
int AnimatedModel_GetModelAttr (int);
void AnimatedModel_UpdateBoneBoundingBox (int);
void String_FreeNativeString (int);
int urho_stringhash_from_string (int);
int StringVector_Create ();
int StringVector_GetSize (int);
int StringVector_GetString (int,int);
void StringVector_AddString (int,int);
int StringVector_SetString (int,int,int);
void StringVector_Empty (int);
void StringVector_Delete (int);
int Matrix3x4_Create (int,int,int);
int Matrix3x4_Multiply (int,int);
int Matrix3x4_Translation (int);
int Matrix3x4_Rotation (int);
int JoystickState_GetNumButtons (int);
int JoystickState_GetButtonDown (int,int);
int JoystickState_GetNumHats (int);
int JoystickState_GetHatPosition (int,int);
int JoystickState_GetNumAxes (int);
float JoystickState_GetAxisPosition (int,int);
void RenderPathCommand_SetShaderParameter_float (int,int,float);
void RenderPathCommand_SetShaderParameter_Matrix4 (int,int,int);
void RenderPathCommand_SetOutput (int,int,int);
void AnimationTrack_PushAnimationKeyFrame (int,int);
void Console_OpenConsoleWindow ();
int Console_GetConsoleInput ();
int UrhoConsole_GetType (int);
int UrhoConsole_GetTypeName (int);
int UrhoConsole_GetTypeStatic ();
int UrhoConsole_GetTypeNameStatic ();
int UrhoConsole_Console (int);
void UrhoConsole_SetDefaultStyle (int,int);
void UrhoConsole_SetVisible (int,int);
void UrhoConsole_Toggle (int);
void UrhoConsole_SetAutoVisibleOnError (int,int);
void UrhoConsole_SetCommandInterpreter (int,int);
void UrhoConsole_SetNumBufferedRows (int,int);
void UrhoConsole_SetNumRows (int,int);
void UrhoConsole_SetNumHistoryRows (int,int);
void UrhoConsole_SetFocusOnShow (int,int);
void UrhoConsole_AddAutoComplete (int,int);
void UrhoConsole_RemoveAutoComplete (int,int);
void UrhoConsole_UpdateElements (int);
int UrhoConsole_GetDefaultStyle (int);
int UrhoConsole_GetBackground (int);
int UrhoConsole_GetLineEdit (int);
int UrhoConsole_GetCloseButton (int);
int UrhoConsole_IsVisible (int);
int UrhoConsole_IsAutoVisibleOnError (int);
int UrhoConsole_GetCommandInterpreter (int);
int UrhoConsole_GetNumBufferedRows (int);
int UrhoConsole_GetNumRows (int);
void UrhoConsole_CopySelectedRows (int);
int UrhoConsole_GetNumHistoryRows (int);
int UrhoConsole_GetHistoryPosition (int);
int UrhoConsole_GetHistoryRow (int,int);
int UrhoConsole_GetFocusOnShow (int);
int VariantMap_VariantMap ();
void VariantMap_Dispose (int);
int VariantMap_Erase (int,int);
int VariantMap_Erase2 (int,int);
int urho_map_get_variantmap (int,int);
int urho_map_get_ptr (int,int);
int urho_map_get_buffer (int,int,int);
int urho_map_get_String (int,int);
int urho_map_get_StringHash (int,int);
int urho_map_get_bool (int,int);
int urho_map_get_int (int,int);
float urho_map_get_float (int,int);
int urho_map_get_uint (int,int);
int urho_map_get_Vector3 (int,int);
int urho_map_get_IntVector2 (int,int);
int urho_map_get_Variant (int,int);
int urho_map_contains_value (int,int);
void urho_map_get_value (int,int,int);
void urho_map_set_value (int,int,int);
void urho_map_set_value_ptr (int,int,int);
int urho_map_get_keys_size (int);
int urho_map_keys_get_key (int,int);
void urho_map_keys_get_keys (int,int);
void VoidPtr_Free (int);
void delete_vector3_pointer (int);
int VGComponent_GetType (int);
int VGComponent_GetTypeName (int);
int VGComponent_GetTypeStatic ();
int VGComponent_GetTypeNameStatic ();
void VGComponent_RegisterObject (int);
int VGComponent_VGComponent (int);
int VGComponent_Create (int,int);
int VGComponent_CreateChild (int,int);
int VGComponent_GetChild (int,int,int);
int VGComponent_GetName (int);
void VGComponent_BeginDraw (int);
void VGComponent_EndDraw (int);
void VGComponent_SetPosition (int,int);
void VGComponent_SetPosition0 (int,float,float);
void VGComponent_SetHotSpot (int,int);
void VGComponent_SetHotSpot1 (int,float,float);
void VGComponent_SetScale (int,int);
void VGComponent_SetScale2 (int,float,float);
void VGComponent_SetScale3 (int,float);
void VGComponent_SetRotation (int,float);
int VGComponent_GetHotSpot (int);
void VGComponent_GetTransformPositionRotation (int,int);
void VGComponent_GetTransformScale (int,int);
void VGComponent_GlobalCompositeOperation (int,int);
void VGComponent_GlobalCompositeBlendFunc (int,int,int);
void VGComponent_GlobalCompositeBlendFuncSeparate (int,int,int,int,int);
int VGComponent_RGB (int,int,int,int);
int VGComponent_RGBf (int,float,float,float);
int VGComponent_RGBA (int,int,int,int,int);
int VGComponent_RGBAf (int,float,float,float,float);
int VGComponent_LerpRGBA (int,int,int,float);
int VGComponent_TransRGBA (int,int,int);
int VGComponent_TransRGBAf (int,int,float);
int VGComponent_HSL (int,float,float,float);
int VGComponent_HSLA (int,float,float,float,int);
void VGComponent_SaveState (int);
void VGComponent_RestoreState (int);
void VGComponent_ResetState (int);
void VGComponent_ShapeAntiAlias (int,int);
void VGComponent_StrokeColor (int,int);
void VGComponent_StrokePaint (int,int);
void VGComponent_FillColor (int,int);
void VGComponent_FillPaint (int,int);
void VGComponent_MiterLimit (int,float);
void VGComponent_StrokeWidth (int,float);
void VGComponent_LineCap (int,int);
void VGComponent_LineJoin (int,int);
void VGComponent_GlobalAlpha (int,float);
void VGComponent_ResetTransform (int);
void VGComponent_Transform (int,float,float,float,float,float,float);
void VGComponent_Translate (int,float,float);
void VGComponent_Rotate (int,float);
void VGComponent_SkewX (int,float);
void VGComponent_SkewY (int,float);
void VGComponent_Scale (int,float,float);
void VGComponent_CurrentTransform (int,int);
void VGComponent_TransformIdentity (int,int);
void VGComponent_TransformTranslate (int,int,float,float);
void VGComponent_TransformScale (int,int,float,float);
void VGComponent_TransformRotate (int,int,float);
void VGComponent_TransformSkewX (int,int,float);
void VGComponent_TransformSkewY (int,int,float);
void VGComponent_TransformMultiply (int,int,int);
void VGComponent_TransformPremultiply (int,int,int);
int VGComponent_TransformInverse (int,int,int);
void VGComponent_TransformPoint (int,int,int,int,float,float);
float VGComponent_DegToRad (int,float);
float VGComponent_RadToDeg (int,float);
int VGComponent_CreateImageMem (int,int,int,int);
int VGComponent_CreateImageRGBA (int,int,int,int,int);
void VGComponent_UpdateImage (int,int,int);
void VGComponent_ImageSize (int,int,int,int);
void VGComponent_DeleteImage (int,int);
int VGComponent_LinearGradient (int,float,float,float,float,int,int);
int VGComponent_BoxGradient (int,float,float,float,float,float,float,int,int);
int VGComponent_RadialGradient (int,float,float,float,float,int,int);
int VGComponent_ImagePattern (int,float,float,float,float,float,int,float);
void VGComponent_Scissor (int,float,float,float,float);
void VGComponent_IntersectScissor (int,float,float,float,float);
void VGComponent_ResetScissor (int);
void VGComponent_BeginPath (int);
void VGComponent_MoveTo (int,float,float);
void VGComponent_LineTo (int,float,float);
void VGComponent_BezierTo (int,float,float,float,float,float,float);
void VGComponent_QuadTo (int,float,float,float,float);
void VGComponent_ArcTo (int,float,float,float,float,float);
void VGComponent_ClosePath (int);
void VGComponent_PathWinding (int,int);
void VGComponent_Arc (int,float,float,float,float,float,int);
void VGComponent_Rect (int,float,float,float,float);
void VGComponent_RoundedRect (int,float,float,float,float,float);
void VGComponent_RoundedRectVarying (int,float,float,float,float,float,float,float,float);
void VGComponent_Ellipse (int,float,float,float,float);
void VGComponent_Circle (int,float,float,float);
void VGComponent_Arc4 (int,float,float,float,int);
void VGComponent_Rect5 (int,float,float);
void VGComponent_RoundedRect6 (int,float,float,float);
void VGComponent_RoundedRectVarying7 (int,float,float,float,float,float,float);
void VGComponent_Ellipse8 (int,float,float);
void VGComponent_Circle9 (int,float);
void VGComponent_Fill (int);
void VGComponent_Stroke (int);
int VGComponent_AddFallbackFontId (int,int,int);
void VGComponent_ResetFallbackFontsId (int,int);
void VGComponent_FontSize (int,float);
void VGComponent_FontBlur (int,float);
void VGComponent_TextLetterSpacing (int,float);
void VGComponent_TextLineHeight (int,float);
void VGComponent_TextAlign (int,int);
void VGComponent_FontFaceId (int,int);
void VGComponent_TextMetrics (int,int,int,int);
void VGComponent_FontFace (int,int);
float VGComponent_Text (int,float,float,int);
void VGComponent_TextBox (int,float,float,float,int);
int VGComponent_TextBreakLines (int,int,float,int);
float VGComponent_TextBounds (int,float,float,int,int);
void VGComponent_TextBoxBounds (int,float,float,float,int,int);
int VGComponent_TextGlyphPositions (int,float,float,int,int,int);
int VGElement_GetType (int);
int VGElement_GetTypeName (int);
int VGElement_GetTypeStatic ();
int VGElement_GetTypeNameStatic ();
void VGElement_RegisterObject (int);
int VGElement_VGElement (int);
int VGElement_GetRenderTarget (int);
void VGElement_OnResize (int,int,int);
void VGElement_BeginRender (int);
void VGElement_EndRender (int);
int VGElement_GetSize (int);
void VGElement_SetClearColor (int,int);
int VGElement_GetClearColor (int);
void VGElement_BeginFrame (int,float,float,float);
void VGElement_CancelFrame (int);
void VGElement_EndFrame (int);
void VGElement_GlobalCompositeOperation (int,int);
void VGElement_GlobalCompositeBlendFunc (int,int,int);
void VGElement_GlobalCompositeBlendFuncSeparate (int,int,int,int,int);
int VGElement_RGB (int,int,int,int);
int VGElement_RGBf (int,float,float,float);
int VGElement_RGBA (int,int,int,int,int);
int VGElement_RGBAf (int,float,float,float,float);
int VGElement_LerpRGBA (int,int,int,float);
int VGElement_TransRGBA (int,int,int);
int VGElement_TransRGBAf (int,int,float);
int VGElement_HSL (int,float,float,float);
int VGElement_HSLA (int,float,float,float,int);
void VGElement_SaveState (int);
void VGElement_RestoreState (int);
void VGElement_ResetState (int);
void VGElement_ShapeAntiAlias (int,int);
void VGElement_StrokeColor (int,int);
void VGElement_StrokePaint (int,int);
void VGElement_FillColor (int,int);
void VGElement_FillPaint (int,int);
void VGElement_MiterLimit (int,float);
void VGElement_StrokeWidth (int,float);
void VGElement_LineCap (int,int);
void VGElement_LineJoin (int,int);
void VGElement_GlobalAlpha (int,float);
void VGElement_ResetTransform (int);
void VGElement_Transform (int,float,float,float,float,float,float);
void VGElement_Translate (int,float,float);
void VGElement_Rotate (int,float);
void VGElement_SkewX (int,float);
void VGElement_SkewY (int,float);
void VGElement_Scale (int,float,float);
void VGElement_CurrentTransform (int,int);
void VGElement_TransformIdentity (int,int);
void VGElement_TransformTranslate (int,int,float,float);
void VGElement_TransformScale (int,int,float,float);
void VGElement_TransformRotate (int,int,float);
void VGElement_TransformSkewX (int,int,float);
void VGElement_TransformSkewY (int,int,float);
void VGElement_TransformMultiply (int,int,int);
void VGElement_TransformPremultiply (int,int,int);
int VGElement_TransformInverse (int,int,int);
void VGElement_TransformPoint (int,int,int,int,float,float);
float VGElement_DegToRad (int,float);
float VGElement_RadToDeg (int,float);
int VGElement_CreateImageMem (int,int,int,int);
int VGElement_CreateImageRGBA (int,int,int,int,int);
void VGElement_UpdateImage (int,int,int);
void VGElement_ImageSize (int,int,int,int);
void VGElement_DeleteImage (int,int);
int VGElement_LinearGradient (int,float,float,float,float,int,int);
int VGElement_BoxGradient (int,float,float,float,float,float,float,int,int);
int VGElement_RadialGradient (int,float,float,float,float,int,int);
int VGElement_ImagePattern (int,float,float,float,float,float,int,float);
void VGElement_Scissor (int,float,float,float,float);
void VGElement_IntersectScissor (int,float,float,float,float);
void VGElement_ResetScissor (int);
void VGElement_BeginPath (int);
void VGElement_MoveTo (int,float,float);
void VGElement_LineTo (int,float,float);
void VGElement_BezierTo (int,float,float,float,float,float,float);
void VGElement_QuadTo (int,float,float,float,float);
void VGElement_ArcTo (int,float,float,float,float,float);
void VGElement_ClosePath (int);
void VGElement_PathWinding (int,int);
void VGElement_Arc (int,float,float,float,float,float,int);
void VGElement_Rect (int,float,float,float,float);
void VGElement_RoundedRect (int,float,float,float,float,float);
void VGElement_RoundedRectVarying (int,float,float,float,float,float,float,float,float);
void VGElement_Ellipse (int,float,float,float,float);
void VGElement_Circle (int,float,float,float);
void VGElement_Fill (int);
void VGElement_Stroke (int);
int VGElement_AddFallbackFontId (int,int,int);
void VGElement_ResetFallbackFontsId (int,int);
void VGElement_FontSize (int,float);
void VGElement_FontBlur (int,float);
void VGElement_TextLetterSpacing (int,float);
void VGElement_TextLineHeight (int,float);
void VGElement_TextAlign (int,int);
void VGElement_FontFaceId (int,int);
void VGElement_TextMetrics (int,int,int,int);
void VGElement_FontFace (int,int);
float VGElement_Text (int,float,float,int);
void VGElement_TextBox (int,float,float,float,int);
int VGElement_TextBreakLines (int,int,float,int);
float VGElement_TextBounds (int,float,float,int,int);
void VGElement_TextBoxBounds (int,float,float,float,int,int);
int VGElement_TextGlyphPositions (int,float,float,int,int,int);
int VGFrameBuffer_GetType (int);
int VGFrameBuffer_GetTypeName (int);
int VGFrameBuffer_GetTypeStatic ();
int VGFrameBuffer_GetTypeNameStatic ();
void VGFrameBuffer_RegisterObject (int);
int VGFrameBuffer_Current ();
int VGFrameBuffer_VGFrameBuffer (int,int,int);
int VGFrameBuffer_VGFrameBuffer0 (int);
int VGFrameBuffer_CreateFrameBuffer (int,int,int);
void VGFrameBuffer_Bind (int);
void VGFrameBuffer_UnBind (int);
int VGFrameBuffer_GetRenderTarget (int);
int VGFrameBuffer_GetSize (int);
void VGFrameBuffer_SetClearColor (int,int);
int VGFrameBuffer_GetClearColor (int);
void VGFrameBuffer_EnableRenderEvents (int);
void VGFrameBuffer_DisbaleRenderEvents (int);
void VGFrameBuffer_BeginFrame (int);
void VGFrameBuffer_CancelFrame (int);
void VGFrameBuffer_EndFrame (int);
void VGFrameBuffer_GlobalCompositeOperation (int,int);
void VGFrameBuffer_GlobalCompositeBlendFunc (int,int,int);
void VGFrameBuffer_GlobalCompositeBlendFuncSeparate (int,int,int,int,int);
int VGFrameBuffer_RGB (int,int,int,int);
int VGFrameBuffer_RGBf (int,float,float,float);
int VGFrameBuffer_RGBA (int,int,int,int,int);
int VGFrameBuffer_RGBAf (int,float,float,float,float);
int VGFrameBuffer_LerpRGBA (int,int,int,float);
int VGFrameBuffer_TransRGBA (int,int,int);
int VGFrameBuffer_TransRGBAf (int,int,float);
int VGFrameBuffer_HSL (int,float,float,float);
int VGFrameBuffer_HSLA (int,float,float,float,int);
void VGFrameBuffer_SaveState (int);
void VGFrameBuffer_RestoreState (int);
void VGFrameBuffer_ResetState (int);
void VGFrameBuffer_ShapeAntiAlias (int,int);
void VGFrameBuffer_StrokeColor (int,int);
void VGFrameBuffer_StrokePaint (int,int);
void VGFrameBuffer_FillColor (int,int);
void VGFrameBuffer_FillPaint (int,int);
void VGFrameBuffer_MiterLimit (int,float);
void VGFrameBuffer_StrokeWidth (int,float);
void VGFrameBuffer_LineCap (int,int);
void VGFrameBuffer_LineJoin (int,int);
void VGFrameBuffer_GlobalAlpha (int,float);
void VGFrameBuffer_ResetTransform (int);
void VGFrameBuffer_Transform (int,float,float,float,float,float,float);
void VGFrameBuffer_Translate (int,float,float);
void VGFrameBuffer_Rotate (int,float);
void VGFrameBuffer_SkewX (int,float);
void VGFrameBuffer_SkewY (int,float);
void VGFrameBuffer_Scale (int,float,float);
void VGFrameBuffer_CurrentTransform (int,int);
void VGFrameBuffer_TransformIdentity (int,int);
void VGFrameBuffer_TransformTranslate (int,int,float,float);
void VGFrameBuffer_TransformScale (int,int,float,float);
void VGFrameBuffer_TransformRotate (int,int,float);
void VGFrameBuffer_TransformSkewX (int,int,float);
void VGFrameBuffer_TransformSkewY (int,int,float);
void VGFrameBuffer_TransformMultiply (int,int,int);
void VGFrameBuffer_TransformPremultiply (int,int,int);
int VGFrameBuffer_TransformInverse (int,int,int);
void VGFrameBuffer_TransformPoint (int,int,int,int,float,float);
float VGFrameBuffer_DegToRad (int,float);
float VGFrameBuffer_RadToDeg (int,float);
int VGFrameBuffer_CreateImageMem (int,int,int,int);
int VGFrameBuffer_CreateImageRGBA (int,int,int,int,int);
void VGFrameBuffer_UpdateImage (int,int,int);
void VGFrameBuffer_ImageSize (int,int,int,int);
void VGFrameBuffer_DeleteImage (int,int);
int VGFrameBuffer_LinearGradient (int,float,float,float,float,int,int);
int VGFrameBuffer_BoxGradient (int,float,float,float,float,float,float,int,int);
int VGFrameBuffer_RadialGradient (int,float,float,float,float,int,int);
int VGFrameBuffer_ImagePattern (int,float,float,float,float,float,int,float);
void VGFrameBuffer_Scissor (int,float,float,float,float);
void VGFrameBuffer_IntersectScissor (int,float,float,float,float);
void VGFrameBuffer_ResetScissor (int);
void VGFrameBuffer_BeginPath (int);
void VGFrameBuffer_MoveTo (int,float,float);
void VGFrameBuffer_LineTo (int,float,float);
void VGFrameBuffer_BezierTo (int,float,float,float,float,float,float);
void VGFrameBuffer_QuadTo (int,float,float,float,float);
void VGFrameBuffer_ArcTo (int,float,float,float,float,float);
void VGFrameBuffer_ClosePath (int);
void VGFrameBuffer_PathWinding (int,int);
void VGFrameBuffer_Arc (int,float,float,float,float,float,int);
void VGFrameBuffer_Rect (int,float,float,float,float);
void VGFrameBuffer_RoundedRect (int,float,float,float,float,float);
void VGFrameBuffer_RoundedRectVarying (int,float,float,float,float,float,float,float,float);
void VGFrameBuffer_Ellipse (int,float,float,float,float);
void VGFrameBuffer_Circle (int,float,float,float);
void VGFrameBuffer_Fill (int);
void VGFrameBuffer_Stroke (int);
int VGFrameBuffer_AddFallbackFontId (int,int,int);
void VGFrameBuffer_ResetFallbackFontsId (int,int);
void VGFrameBuffer_FontSize (int,float);
void VGFrameBuffer_FontBlur (int,float);
void VGFrameBuffer_TextLetterSpacing (int,float);
void VGFrameBuffer_TextLineHeight (int,float);
void VGFrameBuffer_TextAlign (int,int);
void VGFrameBuffer_FontFaceId (int,int);
void VGFrameBuffer_TextMetrics (int,int,int,int);
void VGFrameBuffer_FontFace (int,int);
float VGFrameBuffer_Text (int,float,float,int);
void VGFrameBuffer_TextBox (int,float,float,float,int);
int VGFrameBuffer_TextBreakLines (int,int,float,int);
float VGFrameBuffer_TextBounds (int,float,float,int,int);
void VGFrameBuffer_TextBoxBounds (int,float,float,float,int,int);
int VGFrameBuffer_TextGlyphPositions (int,float,float,int,int,int);
int VGTextRowBuffer_GetType (int);
int VGTextRowBuffer_GetTypeName (int);
int VGTextRowBuffer_GetTypeStatic ();
int VGTextRowBuffer_GetTypeNameStatic ();
int VGTextRowBuffer_VGTextRowBuffer (int);
void VGTextRowBuffer_Clear (int);
void VGTextRowBuffer_AddRow (int,int);
int VGTextRowBuffer_GetSize (int);
int VGTextRowBuffer_GetRowData (int,int,int);
int VGTextRowBuffer_GetRowText (int,int);
float VGTextRowBuffer_GetRowMin (int,int);
float VGTextRowBuffer_GetRowMax (int,int);
float VGTextRowBuffer_GetRowWidth (int,int);
int Variant_GetTypeName (int);
int Variant_GetVariantMap (int);
int Variant_GetString (int);
int Variant_ToString (int);
int Variant_GetBuffer (int,int);
int Variant_GetResourceRefName (int);
int Variant_GetResourceRefType (int);
int Variant_VariantVector_GetVariant (int,int);
int Variant_VariantVector_GetSize (int);
int Variant_StringVector_GetString (int,int);
int Variant_StringVector_GetSize (int);
int Variant_ResourceRefList_GetType (int);
int Variant_ResourceRefList_Names_GetSize (int);
int Variant_ResourceRefList_Names_GetNameAt (int,int);
int Variant_EqualityOperator (int,int);
void Variant_GetRetVariant (int,int);
int VertexBuffer_GetElementMask (int);
int VertexBuffer_CastToGPUObject (int);
int VertexBuffer_GetType (int);
int VertexBuffer_GetTypeName (int);
int VertexBuffer_GetTypeStatic ();
int VertexBuffer_GetTypeNameStatic ();
int VertexBuffer_VertexBuffer (int,int);
void VertexBuffer_OnDeviceLost (int);
void VertexBuffer_Release (int);
void VertexBuffer_SetShadowed (int,int);
int VertexBuffer_SetSize (int,int,int,int);
int VertexBuffer_SetSize0 (int,int,int,int,int);
int VertexBuffer_SetData (int,int);
int VertexBuffer_SetDataRange (int,int,int,int,int);
int VertexBuffer_Lock (int,int,int,int);
void VertexBuffer_Unlock (int);
int VertexBuffer_IsShadowed (int);
int VertexBuffer_IsDynamic (int);
int VertexBuffer_IsLocked (int);
int VertexBuffer_GetVertexCount (int);
int VertexBuffer_GetVertexSize (int);
int VertexBuffer_GetElement (int,int,int);
int VertexBuffer_GetElement1 (int,int,int,int);
int VertexBuffer_HasElement (int,int,int);
int VertexBuffer_HasElement2 (int,int,int,int);
int VertexBuffer_GetElementOffset (int,int,int);
int VertexBuffer_GetElementOffset3 (int,int,int,int);
int VertexBuffer_GetShadowData (int);
uint64_t VertexBuffer_GetBufferHash (int,int);
int VertexBuffer_GetVertexSize4 (int);
int Viewport_GetType (int);
int Viewport_GetTypeName (int);
int Viewport_GetTypeStatic ();
int Viewport_GetTypeNameStatic ();
int Viewport_Viewport (int);
int Viewport_Viewport0 (int,int,int,int);
int Viewport_Viewport1 (int,int,int,int,int);
void Viewport_SetScene (int,int);
void Viewport_SetCamera (int,int);
void Viewport_SetRect (int,int);
void Viewport_SetRenderPath (int,int);
int Viewport_SetRenderPath2 (int,int);
void Viewport_SetDrawDebug (int,int);
void Viewport_SetCullCamera (int,int);
int Viewport_GetScene (int);
int Viewport_GetCamera (int);
int Viewport_GetView (int);
int Viewport_GetRect (int);
int Viewport_GetRenderPath (int);
int Viewport_GetDrawDebug (int);
int Viewport_GetCullCamera (int);
int Viewport_GetScreenRay (int,int,int);
int Viewport_WorldToScreenPoint (int,int);
int Viewport_ScreenToWorldPoint (int,int,int,float);
void Viewport_AllocateView (int);
void Viewport_SetClearColor (int,int);
int float_convert_to_string (float);
int double_convert_to_string (double);
int Quaternion_FromLookRotation (int,int,int);
void RegisterMonoNativeCallbacks (int);
void urho_unsubscribe (int);
int VectorSharedPtr_Count (int);
int VectorSharedPtr_GetIdx (int,int);
int PodVectorUint_Count (int);
int PodVectorUint_GetIdx (int,int);
int Animatable_GetType (int);
int Animatable_GetTypeName (int);
int Animatable_GetTypeStatic ();
int Animatable_GetTypeNameStatic ();
void Animatable_RegisterObject (int);
int Animatable_LoadXML (int,int);
int Animatable_SaveXML (int,int);
void Animatable_SetAnimationEnabled (int,int);
void Animatable_SetAnimationTime (int,float);
void Animatable_SetObjectAnimation (int,int);
void Animatable_SetAttributeAnimation (int,int,int,int,float);
void Animatable_SetAttributeAnimationWrapMode (int,int,int);
void Animatable_SetAttributeAnimationSpeed (int,int,float);
void Animatable_SetAttributeAnimationTime (int,int,float);
void Animatable_RemoveObjectAnimation (int);
void Animatable_RemoveAttributeAnimation (int,int);
int Animatable_GetAnimationEnabled (int);
int Animatable_GetObjectAnimation (int);
int Animatable_GetAttributeAnimation (int,int);
int Animatable_GetAttributeAnimationWrapMode (int,int);
float Animatable_GetAttributeAnimationSpeed (int,int);
float Animatable_GetAttributeAnimationTime (int,int);
int Animatable_GetObjectAnimationAttr (int);
int AnimationController_GetType (int);
int AnimationController_GetTypeName (int);
int AnimationController_GetTypeStatic ();
int AnimationController_GetTypeNameStatic ();
int AnimationController_AnimationController (int);
void AnimationController_RegisterObject (int);
void AnimationController_OnSetEnabled (int);
void AnimationController_Update (int,float);
int AnimationController_Play (int,int,int,int,float);
int AnimationController_PlayExclusive (int,int,int,int,float);
int AnimationController_Stop (int,int,float);
void AnimationController_StopLayer (int,int,float);
void AnimationController_StopAll (int,float);
int AnimationController_Fade (int,int,float,float);
int AnimationController_FadeOthers (int,int,float,float);
int AnimationController_SetLayer (int,int,int);
int AnimationController_SetStartBone (int,int,int);
int AnimationController_SetTime (int,int,float);
int AnimationController_SetWeight (int,int,float);
int AnimationController_SetLooped (int,int,int);
int AnimationController_SetSpeed (int,int,float);
int AnimationController_SetAutoFade (int,int,float);
int AnimationController_SetRemoveOnCompletion (int,int,int);
int AnimationController_SetBlendMode (int,int,int);
int AnimationController_IsPlaying (int,int);
int AnimationController_IsPlaying0 (int,int);
int AnimationController_IsFadingIn (int,int);
int AnimationController_IsFadingOut (int,int);
int AnimationController_IsAtEnd (int,int);
int AnimationController_GetLayer (int,int);
int AnimationController_GetStartBone (int,int);
int AnimationController_GetStartBoneName (int,int);
float AnimationController_GetTime (int,int);
float AnimationController_GetWeight (int,int);
int AnimationController_IsLooped (int,int);
int AnimationController_GetBlendMode (int,int);
float AnimationController_GetLength (int,int);
float AnimationController_GetSpeed (int,int);
float AnimationController_GetFadeTarget (int,int);
float AnimationController_GetFadeTime (int,int);
float AnimationController_GetAutoFade (int,int);
int AnimationController_GetRemoveOnCompletion (int,int);
int AnimationController_GetAnimationState (int,int);
int AnimationController_GetAnimationState1 (int,int);
int AnimationState_AnimationState (int,int);
int AnimationState_AnimationState0 (int,int);
void AnimationState_SetStartBone (int,int);
void AnimationState_SetLooped (int,int);
void AnimationState_SetWeight (int,float);
void AnimationState_SetBlendMode (int,int);
void AnimationState_SetTime (int,float);
void AnimationState_SetBoneWeight (int,int,float,int);
void AnimationState_SetBoneWeight1 (int,int,float,int);
void AnimationState_SetBoneWeight2 (int,int,float,int);
void AnimationState_AddWeight (int,float);
void AnimationState_AddTime (int,float);
void AnimationState_SetLayer (int,int);
int AnimationState_GetAnimation (int);
int AnimationState_GetModel (int);
int AnimationState_GetNode (int);
int AnimationState_GetStartBone (int);
float AnimationState_GetBoneWeight (int,int);
float AnimationState_GetBoneWeight3 (int,int);
float AnimationState_GetBoneWeight4 (int,int);
int AnimationState_GetTrackIndex (int,int);
int AnimationState_GetTrackIndex5 (int,int);
int AnimationState_GetTrackIndex6 (int,int);
int AnimationState_IsEnabled (int);
int AnimationState_IsLooped (int);
float AnimationState_GetWeight (int);
int AnimationState_GetBlendMode (int);
float AnimationState_GetTime (int);
float AnimationState_GetLength (int);
int AnimationState_GetLayer (int);
void AnimationState_Apply (int);
int AreaAllocator_AreaAllocator ();
int AreaAllocator_AreaAllocator0 (int,int,int);
int AreaAllocator_AreaAllocator1 (int,int,int,int,int);
void AreaAllocator_Reset (int,int,int,int,int,int);
int AreaAllocator_Allocate (int,int,int,int,int);
int AreaAllocator_GetWidth (int);
int AreaAllocator_GetHeight (int);
int AreaAllocator_GetFastMode (int);
void AttributeAccessor_Set_0 (int,int,int);
void AttributeAccessor_Set_1 (int,int,int);
void AttributeAccessor_Set_2 (int,int,int);
void AttributeAccessor_Set_3 (int,int,int);
void AttributeAccessor_Set_4 (int,int,int);
void AttributeAccessor_Set_5 (int,int,int);
void AttributeAccessor_Set_6 (int,int,int);
void AttributeAccessor_Set_7 (int,int,int);
void AttributeAccessor_Set_8 (int,int,int);
void AttributeAccessor_Set_9 (int,int,int);
void AttributeAccessor_Set_10 (int,int,int);
void AttributeAccessor_Set_11 (int,int,int);
void AttributeAccessor_Set_12 (int,int,float);
void AttributeAccessor_Set_13 (int,int,int);
void AttributeAccessor_Set_14 (int,int,int);
int Automation_GetType (int);
int Automation_GetTypeName (int);
int Automation_GetTypeStatic ();
int Automation_GetTypeNameStatic ();
int Automation_Automation (int);
int Automation_IsAvaliable (int);
void Automation_MouseClick (int,int);
void Automation_MousePress (int,int);
void Automation_MouseRelease (int,int);
void Automation_MouseScrollH (int,int);
void Automation_MouseScrollV (int,int);
int Automation_MouseGetPos (int);
void Automation_MouseSetPos (int,int);
void Automation_MouseSetPos0 (int,int,int);
int Automation_MouseGetState (int,int);
void Automation_KeyboardClick (int,int);
void Automation_KeyboardPress (int,int);
void Automation_KeyboardRelease (int,int);
int Automation_KeyboardGetState (int,int);
int Automation_GetScreenBounds (int);
int ConstantBuffer_CastToGPUObject (int);
int ConstantBuffer_GetType (int);
int ConstantBuffer_GetTypeName (int);
int ConstantBuffer_GetTypeStatic ();
int ConstantBuffer_GetTypeNameStatic ();
int ConstantBuffer_ConstantBuffer (int);
void ConstantBuffer_Release (int);
int ConstantBuffer_SetSize (int,int);
void ConstantBuffer_SetParameter (int,int,int,int);
void ConstantBuffer_SetVector3ArrayParameter (int,int,int,int);
void ConstantBuffer_Apply (int);
int ConstantBuffer_GetSize (int);
int ConstantBuffer_IsDirty (int);
int ConvexData_ConvexData (int,int);
int ConvexData_ConvexData0 (int);
int CustomGeometry_GetType (int);
int CustomGeometry_GetTypeName (int);
int CustomGeometry_GetTypeStatic ();
int CustomGeometry_GetTypeNameStatic ();
int CustomGeometry_CustomGeometry (int);
void CustomGeometry_RegisterObject (int);
int CustomGeometry_GetLodGeometry (int,int,int);
int CustomGeometry_GetNumOccluderTriangles (int);
int CustomGeometry_DrawOcclusion (int,int);
void CustomGeometry_Clear (int);
void CustomGeometry_SetNumGeometries (int,int);
void CustomGeometry_SetDynamic (int,int);
void CustomGeometry_BeginGeometry (int,int,int);
void CustomGeometry_DefineVertex (int,int);
void CustomGeometry_DefineNormal (int,int);
void CustomGeometry_DefineColor (int,int);
void CustomGeometry_DefineTexCoord (int,int);
void CustomGeometry_DefineTangent (int,int);
void CustomGeometry_DefineGeometry (int,int,int,int,int,int,int,int);
void CustomGeometry_Commit (int);
void CustomGeometry_SetMaterial (int,int);
int CustomGeometry_SetMaterial0 (int,int,int);
int CustomGeometry_GetNumGeometries (int);
int CustomGeometry_GetNumVertices (int,int);
int CustomGeometry_IsDynamic (int);
int CustomGeometry_GetMaterial (int,int);
int CustomGeometry_GetVertex (int,int,int);
int Database_GetType (int);
int Database_GetTypeName (int);
int Database_GetTypeStatic ();
int Database_GetTypeNameStatic ();
int Database_Database (int);
int Database_GetAPI ();
int Database_Connect (int,int);
void Database_Disconnect (int,int);
int Database_IsPooling (int);
int Database_GetPoolSize (int);
void Database_SetPoolSize (int,int);
int DebugHud_GetType (int);
int DebugHud_GetTypeName (int);
int DebugHud_GetTypeStatic ();
int DebugHud_GetTypeNameStatic ();
int DebugHud_DebugHud (int);
void DebugHud_Update (int);
void DebugHud_SetDefaultStyle (int,int);
void DebugHud_SetMode (int,int);
void DebugHud_SetProfilerMaxDepth (int,int);
void DebugHud_SetProfilerInterval (int,float);
void DebugHud_SetUseRendererStats (int,int);
void DebugHud_Toggle (int,int);
void DebugHud_ToggleAll (int);
int DebugHud_GetDefaultStyle (int);
int DebugHud_GetStatsText (int);
int DebugHud_GetModeText (int);
int DebugHud_GetProfilerText (int);
int DebugHud_GetMemoryText (int);
int DebugHud_GetMode (int);
int DebugHud_GetProfilerMaxDepth (int);
float DebugHud_GetProfilerInterval (int);
int DebugHud_GetUseRendererStats (int);
void DebugHud_SetAppStats (int,int,int);
int DebugHud_ResetAppStats (int,int);
void DebugHud_ClearAppStats (int);
int DebugRenderer_GetType (int);
int DebugRenderer_GetTypeName (int);
int DebugRenderer_GetTypeStatic ();
int DebugRenderer_GetTypeNameStatic ();
int DebugRenderer_DebugRenderer (int);
void DebugRenderer_RegisterObject (int);
void DebugRenderer_SetLineAntiAlias (int,int);
void DebugRenderer_SetView (int,int);
void DebugRenderer_AddLine (int,int,int,int,int);
void DebugRenderer_AddLine0 (int,int,int,int,int);
void DebugRenderer_AddTriangle (int,int,int,int,int,int);
void DebugRenderer_AddTriangle1 (int,int,int,int,int,int);
void DebugRenderer_AddPolygon (int,int,int,int,int,int,int);
void DebugRenderer_AddPolygon2 (int,int,int,int,int,int,int);
void DebugRenderer_AddNode (int,int,float,int);
void DebugRenderer_AddBoundingBox (int,int,int,int,int);
void DebugRenderer_AddBoundingBox3 (int,int,int,int,int,int);
void DebugRenderer_AddFrustum (int,int,int,int);
void DebugRenderer_AddPolyhedron (int,int,int,int);
void DebugRenderer_AddSphere (int,int,int,int);
void DebugRenderer_AddSphereSector (int,int,int,float,int,int,int);
void DebugRenderer_AddCylinder (int,int,float,float,int,int);
void DebugRenderer_AddTriangleMesh (int,int,int,int,int,int,int,int,int,int);
void DebugRenderer_AddTriangleMesh4 (int,int,int,int,int,int,int,int,int,int,int);
void DebugRenderer_AddCircle (int,int,int,float,int,int,int);
void DebugRenderer_AddCross (int,int,float,int,int);
void DebugRenderer_AddQuad (int,int,float,float,int,int);
void DebugRenderer_Render (int);
int DebugRenderer_GetLineAntiAlias (int);
int DebugRenderer_GetView (int);
int DebugRenderer_GetProjection (int);
int DebugRenderer_GetFrustum (int);
int DebugRenderer_IsInside (int,int);
int DebugRenderer_HasContent (int);
int DecalSet_GetType (int);
int DecalSet_GetTypeName (int);
int DecalSet_GetTypeStatic ();
int DecalSet_GetTypeNameStatic ();
int DecalSet_DecalSet (int);
void DecalSet_RegisterObject (int);
void DecalSet_ApplyAttributes (int);
void DecalSet_OnSetEnabled (int);
int DecalSet_GetUpdateGeometryType (int);
void DecalSet_SetMaterial (int,int);
void DecalSet_SetMaxVertices (int,int);
void DecalSet_SetMaxIndices (int,int);
void DecalSet_SetOptimizeBufferSize (int,int);
int DecalSet_AddDecal (int,int,int,int,float,float,float,int,int,float,float,int);
void DecalSet_RemoveDecals (int,int);
void DecalSet_RemoveAllDecals (int);
int DecalSet_GetMaterial (int);
int DecalSet_GetNumDecals (int);
int DecalSet_GetNumVertices (int);
int DecalSet_GetNumIndices (int);
int DecalSet_GetMaxVertices (int);
int DecalSet_GetMaxIndices (int);
int DecalSet_GetOptimizeBufferSize (int);
int DecalSet_GetMaterialAttr (int);
int Drawable_GetType (int);
int Drawable_GetTypeName (int);
int Drawable_GetTypeStatic ();
int Drawable_GetTypeNameStatic ();
void Drawable_RegisterObject (int);
void Drawable_OnSetEnabled (int);
int Drawable_GetUpdateGeometryType (int);
int Drawable_GetLodGeometry (int,int,int);
int Drawable_GetNumOccluderTriangles (int);
int Drawable_DrawOcclusion (int,int);
void Drawable_DrawDebugGeometry (int,int,int);
void Drawable_SetDrawDistance (int,float);
void Drawable_SetShadowDistance (int,float);
void Drawable_SetLodBias (int,float);
void Drawable_SetViewMask (int,int);
void Drawable_SetLightMask (int,int);
void Drawable_SetShadowMask (int,int);
void Drawable_SetZoneMask (int,int);
void Drawable_SetMaxLights (int,int);
void Drawable_SetCastShadows (int,int);
void Drawable_SetOccluder (int,int);
void Drawable_SetOccludee (int,int);
void Drawable_MarkForUpdate (int);
int Drawable_GetBoundingBox (int);
int Drawable_GetWorldBoundingBox (int);
int Drawable_GetDrawableFlags (int);
float Drawable_GetDrawDistance (int);
float Drawable_GetShadowDistance (int);
float Drawable_GetLodBias (int);
int Drawable_GetViewMask (int);
int Drawable_GetLightMask (int);
int Drawable_GetShadowMask (int);
int Drawable_GetZoneMask (int);
int Drawable_GetMaxLights (int);
int Drawable_GetCastShadows (int);
int Drawable_IsOccluder (int);
int Drawable_IsOccludee (int);
int Drawable_IsInView (int);
int Drawable_IsInView0 (int,int);
void Drawable_SetZone (int,int,int);
void Drawable_SetSortValue (int,float);
void Drawable_SetMinMaxZ (int,float,float);
void Drawable_MarkInView (int,int);
void Drawable_LimitLights (int);
void Drawable_LimitVertexLights (int,int);
void Drawable_SetBasePass (int,int);
int Drawable_GetOctant (int);
int Drawable_GetZone (int);
int Drawable_IsZoneDirty (int);
float Drawable_GetDistance (int);
float Drawable_GetLodDistance (int);
float Drawable_GetSortValue (int);
int Drawable_HasBasePass (int,int);
int Drawable_GetFirstLight (int);
float Drawable_GetMinZ (int);
float Drawable_GetMaxZ (int);
void Drawable_AddLight (int,int);
void Drawable_AddVertexLight (int,int);
int Engine_GetType (int);
int Engine_GetTypeName (int);
int Engine_GetTypeStatic ();
int Engine_GetTypeNameStatic ();
int Engine_Engine (int);
void Engine_RunFrame (int);
int Engine_CreateConsole (int);
int Engine_CreateDebugHud (int);
void Engine_SetMinFps (int,int);
void Engine_SetMaxFps (int,int);
void Engine_SetMaxInactiveFps (int,int);
void Engine_SetTimeStepSmoothing (int,int);
void Engine_SetPauseMinimized (int,int);
void Engine_SetAutoExit (int,int);
void Engine_SetNextTimeStep (int,float);
void Engine_Exit (int);
void Engine_DumpProfiler (int);
void Engine_DumpResources (int,int);
void Engine_DumpMemory (int);
float Engine_GetNextTimeStep (int);
int Engine_GetMinFps (int);
int Engine_GetMaxFps (int);
int Engine_GetMaxInactiveFps (int);
int Engine_GetTimeStepSmoothing (int);
int Engine_GetPauseMinimized (int);
int Engine_GetAutoExit (int);
int Engine_IsInitialized (int);
int Engine_IsExiting (int);
int Engine_IsHeadless (int);
void Engine_Update (int);
void Engine_Render (int);
void Engine_ApplyFrameLimit (int);
int EventReceiverGroup_EventReceiverGroup ();
void EventReceiverGroup_BeginSendEvent (int);
void EventReceiverGroup_EndSendEvent (int);
void EventReceiverGroup_Add (int,int);
void EventReceiverGroup_Remove (int,int);
int GImpactMeshData_GImpactMeshData (int,int);
int GImpactMeshData_GImpactMeshData0 (int);
int Geometry_GetType (int);
int Geometry_GetTypeName (int);
int Geometry_GetTypeStatic ();
int Geometry_GetTypeNameStatic ();
int Geometry_Geometry (int);
int Geometry_SetNumVertexBuffers (int,int);
int Geometry_SetVertexBuffer (int,int,int);
void Geometry_SetIndexBuffer (int,int);
int Geometry_SetDrawRange (int,int,int,int,int);
int Geometry_SetDrawRange0 (int,int,int,int,int,int,int);
void Geometry_SetLodDistance (int,float);
void Geometry_Draw (int,int);
int Geometry_GetVertexBuffers (int);
int Geometry_GetNumVertexBuffers (int);
int Geometry_GetVertexBuffer (int,int);
int Geometry_GetIndexBuffer (int);
int Geometry_GetPrimitiveType (int);
int Geometry_GetIndexStart (int);
int Geometry_GetIndexCount (int);
int Geometry_GetVertexStart (int);
int Geometry_GetVertexCount (int);
float Geometry_GetLodDistance (int);
int Geometry_GetBufferHash (int);
float Geometry_GetHitDistance (int,int,int,int);
int Geometry_IsInside (int,int);
int Geometry_IsEmpty (int);
int HeightfieldData_HeightfieldData (int,int);
int HierarchyContainer_GetType (int);
int HierarchyContainer_GetTypeName (int);
int HierarchyContainer_GetTypeStatic ();
int HierarchyContainer_GetTypeNameStatic ();
int HierarchyContainer_HierarchyContainer (int,int,int);
void HierarchyContainer_RegisterObject (int);
void HierarchyContainer_InsertChild (int,int,int);
int IKConstraint_GetType (int);
int IKConstraint_GetTypeName (int);
int IKConstraint_GetTypeStatic ();
int IKConstraint_GetTypeNameStatic ();
int IKConstraint_IKConstraint (int);
void IKConstraint_RegisterObject (int);
float IKConstraint_GetStiffness (int);
void IKConstraint_SetStiffness (int,float);
float IKConstraint_GetStretchiness (int);
void IKConstraint_SetStretchiness (int,float);
int IKConstraint_GetLengthConstraints (int);
void IKConstraint_SetLengthConstraints (int,int);
int IKEffector_GetType (int);
int IKEffector_GetTypeName (int);
int IKEffector_GetTypeStatic ();
int IKEffector_GetTypeNameStatic ();
int IKEffector_IKEffector (int);
void IKEffector_RegisterObject (int);
int IKEffector_GetFeature (int,int);
void IKEffector_SetFeature (int,int,int);
int IKEffector_GetTargetNode (int);
void IKEffector_SetTargetNode (int,int);
int IKEffector_GetTargetName (int);
void IKEffector_SetTargetName (int,int);
int IKEffector_GetTargetPosition (int);
void IKEffector_SetTargetPosition (int,int);
int IKEffector_GetTargetRotation (int);
void IKEffector_SetTargetRotation (int,int);
int IKEffector_GetTargetRotationEuler (int);
void IKEffector_SetTargetRotationEuler (int,int);
int IKEffector_GetChainLength (int);
void IKEffector_SetChainLength (int,int);
float IKEffector_GetWeight (int);
void IKEffector_SetWeight (int,float);
float IKEffector_GetRotationWeight (int);
void IKEffector_SetRotationWeight (int,float);
float IKEffector_GetRotationDecay (int);
void IKEffector_SetRotationDecay (int,float);
void IKEffector_DrawDebugGeometry (int,int);
void IKEffector_DrawDebugGeometry0 (int,int,int);
int IKEffector_GetFEATURE_WEIGHT_NLERP (int);
int IKEffector_GetFEATURE_INHERIT_PARENT_ROTATION (int);
void IKEffector_SetFEATURE_WEIGHT_NLERP (int,int);
void IKEffector_SetFEATURE_INHERIT_PARENT_ROTATION (int,int);
int IKSolver_GetType (int);
int IKSolver_GetTypeName (int);
int IKSolver_GetTypeStatic ();
int IKSolver_GetTypeNameStatic ();
int IKSolver_IKSolver (int);
void IKSolver_RegisterObject (int);
int IKSolver_GetAlgorithm (int);
void IKSolver_SetAlgorithm (int,int);
int IKSolver_GetFeature (int,int);
void IKSolver_SetFeature (int,int,int);
int IKSolver_GetMaximumIterations (int);
void IKSolver_SetMaximumIterations (int,int);
float IKSolver_GetTolerance (int);
void IKSolver_SetTolerance (int,float);
void IKSolver_RebuildChainTrees (int);
void IKSolver_RecalculateSegmentLengths (int);
void IKSolver_CalculateJointRotations (int);
void IKSolver_Solve (int);
void IKSolver_ApplyOriginalPoseToScene (int);
void IKSolver_ApplySceneToOriginalPose (int);
void IKSolver_ApplyActivePoseToScene (int);
void IKSolver_ApplySceneToActivePose (int);
void IKSolver_ApplyOriginalPoseToActivePose (int);
void IKSolver_DrawDebugGeometry (int,int);
void IKSolver_DrawDebugGeometry0 (int,int,int);
int IKSolver_GetFEATURE_JOINT_ROTATIONS (int);
int IKSolver_GetFEATURE_TARGET_ROTATIONS (int);
int IKSolver_GetFEATURE_UPDATE_ORIGINAL_POSE (int);
int IKSolver_GetFEATURE_UPDATE_ACTIVE_POSE (int);
int IKSolver_GetFEATURE_USE_ORIGINAL_POSE (int);
int IKSolver_GetFEATURE_CONSTRAINTS (int);
int IKSolver_GetFEATURE_AUTO_SOLVE (int);
void IKSolver_SetFEATURE_JOINT_ROTATIONS (int,int);
void IKSolver_SetFEATURE_TARGET_ROTATIONS (int,int);
void IKSolver_SetFEATURE_UPDATE_ORIGINAL_POSE (int,int);
void IKSolver_SetFEATURE_UPDATE_ACTIVE_POSE (int,int);
void IKSolver_SetFEATURE_USE_ORIGINAL_POSE (int,int);
void IKSolver_SetFEATURE_CONSTRAINTS (int,int);
void IKSolver_SetFEATURE_AUTO_SOLVE (int,int);
int JsonBuilder_GetType (int);
int JsonBuilder_GetTypeName (int);
int JsonBuilder_GetTypeStatic ();
int JsonBuilder_GetTypeNameStatic ();
int JsonBuilder_JsonBuilder (int);
int Light_GetType (int);
int Light_GetTypeName (int);
int Light_GetTypeStatic ();
int Light_GetTypeNameStatic ();
int Light_Light (int);
void Light_RegisterObject (int);
void Light_DrawDebugGeometry (int,int,int);
void Light_SetLightType (int,int);
void Light_SetPerVertex (int,int);
void Light_SetColor (int,int);
void Light_SetTemperature (int,float);
void Light_SetRadius (int,float);
void Light_SetLength (int,float);
void Light_SetUsePhysicalValues (int,int);
void Light_SetSpecularIntensity (int,float);
void Light_SetBrightness (int,float);
void Light_SetRange (int,float);
void Light_SetFov (int,float);
void Light_SetAspectRatio (int,float);
void Light_SetFadeDistance (int,float);
void Light_SetShadowFadeDistance (int,float);
void Light_SetShadowBias (int,int);
void Light_SetShadowCascade (int,int);
void Light_SetShadowFocus (int,int);
void Light_SetShadowIntensity (int,float);
void Light_SetShadowResolution (int,float);
void Light_SetShadowNearFarRatio (int,float);
void Light_SetShadowMaxExtrusion (int,float);
void Light_SetRampTexture (int,int);
void Light_SetShapeTexture (int,int);
int Light_GetLightType (int);
int Light_GetPerVertex (int);
int Light_GetColor (int);
float Light_GetTemperature (int);
float Light_GetRadius (int);
float Light_GetLength (int);
int Light_GetUsePhysicalValues (int);
int Light_GetColorFromTemperature (int);
float Light_GetSpecularIntensity (int);
float Light_GetBrightness (int);
int Light_GetEffectiveColor (int);
float Light_GetEffectiveSpecularIntensity (int);
float Light_GetRange (int);
float Light_GetFov (int);
float Light_GetAspectRatio (int);
float Light_GetFadeDistance (int);
float Light_GetShadowFadeDistance (int);
int Light_GetShadowBias (int);
int Light_GetShadowCascade (int);
int Light_GetShadowFocus (int);
float Light_GetShadowIntensity (int);
float Light_GetShadowResolution (int);
float Light_GetShadowNearFarRatio (int);
float Light_GetShadowMaxExtrusion (int);
int Light_GetRampTexture (int);
int Light_GetShapeTexture (int);
int Light_GetFrustum (int);
int Light_GetViewSpaceFrustum (int,int);
int Light_GetNumShadowSplits (int);
int Light_IsNegative (int);
void Light_SetIntensitySortValue (int,float);
void Light_SetIntensitySortValue0 (int,int);
void Light_SetLightQueue (int,int);
int Light_GetVolumeTransform (int,int);
int Light_GetLightQueue (int);
float Light_GetIntensityDivisor (int,float);
int Light_GetRampTextureAttr (int);
int Light_GetShapeTextureAttr (int);
int Light_GetFullscreenQuadTransform (int);
int Time_GetType (int);
int Time_GetTypeName (int);
int Time_GetTypeStatic ();
int Time_GetTypeNameStatic ();
int Time_Time (int);
void Time_BeginFrame (int,float);
void Time_EndFrame (int);
void Time_SetTimerPeriod (int,int);
int Time_GetFrameNumber (int);
float Time_GetTimeStep (int);
int Time_GetTimerPeriod (int);
float Time_GetElapsedTime (int);
float Time_GetFramesPerSecond (int);
int Time_GetSystemTime ();
int Time_GetTimeSinceEpoch ();
int Time_GetTimeStamp ();
void Time_Sleep (int);
int WorkQueue_GetType (int);
int WorkQueue_GetTypeName (int);
int WorkQueue_GetTypeStatic ();
int WorkQueue_GetTypeNameStatic ();
int WorkQueue_WorkQueue (int);
void WorkQueue_CreateThreads (int,int);
int WorkQueue_GetFreeItem (int);
void WorkQueue_Pause (int);
void WorkQueue_Resume (int);
void WorkQueue_Complete (int,int);
void WorkQueue_SetTolerance (int,int);
void WorkQueue_SetNonThreadedWorkMs (int,int);
int WorkQueue_GetNumThreads (int);
int WorkQueue_IsCompleted (int,int);
int WorkQueue_IsCompleting (int);
int WorkQueue_GetTolerance (int);
int WorkQueue_GetNonThreadedWorkMs (int);
int Terrain_GetType (int);
int Terrain_GetTypeName (int);
int Terrain_GetTypeStatic ();
int Terrain_GetTypeNameStatic ();
int Terrain_Terrain (int);
void Terrain_RegisterObject (int);
void Terrain_ApplyAttributes (int);
void Terrain_OnSetEnabled (int);
void Terrain_SetPatchSize (int,int);
void Terrain_SetSpacing (int,int);
void Terrain_SetMaxLodLevels (int,int);
void Terrain_SetOcclusionLodLevel (int,int);
void Terrain_SetSmoothing (int,int);
int Terrain_SetHeightMap (int,int);
void Terrain_SetMaterial (int,int);
void Terrain_SetNorthNeighbor (int,int);
void Terrain_SetSouthNeighbor (int,int);
void Terrain_SetWestNeighbor (int,int);
void Terrain_SetEastNeighbor (int,int);
void Terrain_SetNeighbors (int,int,int,int,int);
void Terrain_SetDrawDistance (int,float);
void Terrain_SetShadowDistance (int,float);
void Terrain_SetLodBias (int,float);
void Terrain_SetViewMask (int,int);
void Terrain_SetLightMask (int,int);
void Terrain_SetShadowMask (int,int);
void Terrain_SetZoneMask (int,int);
void Terrain_SetMaxLights (int,int);
void Terrain_SetCastShadows (int,int);
void Terrain_SetOccluder (int,int);
void Terrain_SetOccludee (int,int);
void Terrain_ApplyHeightMap (int);
int Terrain_GetPatchSize (int);
int Terrain_GetSpacing (int);
int Terrain_GetNumVertices (int);
int Terrain_GetNumPatches (int);
int Terrain_GetMaxLodLevels (int);
int Terrain_GetOcclusionLodLevel (int);
int Terrain_GetSmoothing (int);
int Terrain_GetHeightMap (int);
int Terrain_GetMaterial (int);
int Terrain_GetPatch (int,int);
int Terrain_GetPatch0 (int,int,int);
int Terrain_GetNeighborPatch (int,int,int);
float Terrain_GetHeight (int,int);
int Terrain_GetNormal (int,int);
int Terrain_WorldToHeightMap (int,int);
int Terrain_HeightMapToWorld (int,int);
int Terrain_GetNorthNeighbor (int);
int Terrain_GetSouthNeighbor (int);
int Terrain_GetWestNeighbor (int);
int Terrain_GetEastNeighbor (int);
float Terrain_GetDrawDistance (int);
float Terrain_GetShadowDistance (int);
float Terrain_GetLodBias (int);
int Terrain_GetViewMask (int);
int Terrain_GetLightMask (int);
int Terrain_GetShadowMask (int);
int Terrain_GetZoneMask (int);
int Terrain_GetMaxLights (int);
int Terrain_IsVisible (int);
int Terrain_GetCastShadows (int);
int Terrain_IsOccluder (int);
int Terrain_IsOccludee (int);
void Terrain_CreatePatchGeometry (int,int);
void Terrain_UpdatePatchLod (int,int);
void Terrain_SetPatchSizeAttr (int,int);
void Terrain_SetMaxLodLevelsAttr (int,int);
void Terrain_SetOcclusionLodLevelAttr (int,int);
int Terrain_GetHeightMapAttr (int);
int Terrain_GetMaterialAttr (int);
int Renderer_GetType (int);
int Renderer_GetTypeName (int);
int Renderer_GetTypeStatic ();
int Renderer_GetTypeNameStatic ();
int Renderer_Renderer (int);
void Renderer_SetNumViewports (int,int);
void Renderer_SetViewport (int,int,int);
void Renderer_SetDefaultRenderPath (int,int);
void Renderer_SetDefaultRenderPath0 (int,int);
void Renderer_SetDefaultTechnique (int,int);
void Renderer_SetHDRRendering (int,int);
void Renderer_SetSpecularLighting (int,int);
void Renderer_SetTextureAnisotropy (int,int);
void Renderer_SetTextureFilterMode (int,int);
void Renderer_SetTextureQuality (int,int);
void Renderer_SetMaterialQuality (int,int);
void Renderer_SetDrawShadows (int,int);
void Renderer_SetShadowMapSize (int,int);
void Renderer_SetShadowQuality (int,int);
void Renderer_SetShadowSoftness (int,float);
void Renderer_SetVSMShadowParameters (int,float,float);
void Renderer_SetVSMMultiSample (int,int);
void Renderer_SetReuseShadowMaps (int,int);
void Renderer_SetMaxShadowMaps (int,int);
void Renderer_SetDynamicInstancing (int,int);
void Renderer_SetNumExtraInstancingBufferElements (int,int);
void Renderer_SetMinInstances (int,int);
void Renderer_SetMaxSortedInstances (int,int);
void Renderer_SetMaxOccluderTriangles (int,int);
void Renderer_SetOcclusionBufferSize (int,int);
void Renderer_SetOccluderSizeThreshold (int,float);
void Renderer_SetThreadedOcclusion (int,int);
void Renderer_SetMobileShadowBiasMul (int,float);
void Renderer_SetMobileShadowBiasAdd (int,float);
void Renderer_SetMobileNormalOffsetMul (int,float);
void Renderer_ReloadShaders (int);
void Renderer_ApplyShadowMapFilter (int,int,int,float);
int Renderer_GetNumViewports (int);
int Renderer_GetViewport (int,int);
int Renderer_GetViewportForScene (int,int,int);
int Renderer_GetDefaultRenderPath (int);
int Renderer_GetDefaultTechnique (int);
int Renderer_GetHDRRendering (int);
int Renderer_GetSpecularLighting (int);
int Renderer_GetDrawShadows (int);
int Renderer_GetTextureAnisotropy (int);
int Renderer_GetTextureFilterMode (int);
int Renderer_GetTextureQuality (int);
int Renderer_GetMaterialQuality (int);
int Renderer_GetShadowMapSize (int);
int Renderer_GetShadowQuality (int);
float Renderer_GetShadowSoftness (int);
int Renderer_GetVSMShadowParameters (int);
int Renderer_GetVSMMultiSample (int);
int Renderer_GetReuseShadowMaps (int);
int Renderer_GetMaxShadowMaps (int);
int Renderer_GetDynamicInstancing (int);
int Renderer_GetNumExtraInstancingBufferElements (int);
int Renderer_GetMinInstances (int);
int Renderer_GetMaxSortedInstances (int);
int Renderer_GetMaxOccluderTriangles (int);
int Renderer_GetOcclusionBufferSize (int);
float Renderer_GetOccluderSizeThreshold (int);
int Renderer_GetThreadedOcclusion (int);
float Renderer_GetMobileShadowBiasMul (int);
float Renderer_GetMobileShadowBiasAdd (int);
float Renderer_GetMobileNormalOffsetMul (int);
int Renderer_GetNumViews (int);
int Renderer_GetNumPrimitives (int);
int Renderer_GetNumBatches (int);
int Renderer_GetNumGeometries (int,int);
int Renderer_GetNumLights (int,int);
int Renderer_GetNumShadowMaps (int,int);
int Renderer_GetNumOccluders (int,int);
int Renderer_GetDefaultZone (int);
int Renderer_GetDefaultMaterial (int);
int Renderer_GetDefaultLightRamp (int);
int Renderer_GetDefaultLightSpot (int);
int Renderer_GetFaceSelectCubeMap (int);
int Renderer_GetIndirectionCubeMap (int);
int Renderer_GetInstancingBuffer (int);
void Renderer_Update (int,float);
void Renderer_Render (int);
void Renderer_DrawDebugGeometry (int,int);
void Renderer_QueueRenderSurface (int,int);
void Renderer_QueueViewport (int,int,int);
int Renderer_GetLightGeometry (int,int);
int Renderer_GetQuadGeometry (int);
int Renderer_GetShadowMap (int,int,int,int,int);
int Renderer_GetScreenBuffer (int,int,int,int,int,int,int,int,int,int);
int Renderer_GetDepthStencil (int,int,int,int,int);
int Renderer_GetOcclusionBuffer (int,int);
int Renderer_GetShadowCamera (int);
void Renderer_StorePreparedView (int,int,int);
int Renderer_GetPreparedView (int,int);
void Renderer_SetCullMode (int,int,int);
int Renderer_ResizeInstancingBuffer (int,int);
void Renderer_OptimizeLightByScissor (int,int,int);
void Renderer_OptimizeLightByStencil (int,int,int);
int Renderer_GetActualView (int);
int View_GetType (int);
int View_GetTypeName (int);
int View_GetTypeStatic ();
int View_GetTypeNameStatic ();
int View_View (int);
int View_Define (int,int,int);
void View_Render (int);
int View_GetGraphics (int);
int View_GetRenderer (int);
int View_GetScene (int);
int View_GetOctree (int);
int View_GetCamera (int);
int View_GetCullCamera (int);
int View_GetRenderTarget (int);
int View_GetDrawDebug (int);
int View_GetViewRect (int);
int View_GetViewSize (int);
int View_GetOcclusionBuffer (int);
int View_GetNumActiveOccluders (int);
int View_GetSourceView (int);
void View_SetGlobalShaderParameters (int);
void View_SetCameraShaderParameters (int,int);
void View_SetCommandShaderParameters (int,int);
void View_SetGBufferShaderParameters (int,int,int);
void View_DrawFullscreenQuad (int,int);
int View_FindNamedTexture (int,int,int,int);
void View_SetClearColor (int,int);
int SmoothedTransform_GetType (int);
int SmoothedTransform_GetTypeName (int);
int SmoothedTransform_GetTypeStatic ();
int SmoothedTransform_GetTypeNameStatic ();
int SmoothedTransform_SmoothedTransform (int);
void SmoothedTransform_RegisterObject (int);
void SmoothedTransform_Update (int,float,float);
void SmoothedTransform_SetTargetPosition (int,int);
void SmoothedTransform_SetTargetRotation (int,int);
void SmoothedTransform_SetTargetWorldPosition (int,int);
void SmoothedTransform_SetTargetWorldRotation (int,int);
int SmoothedTransform_GetTargetPosition (int);
int SmoothedTransform_GetTargetRotation (int);
int SmoothedTransform_GetTargetWorldPosition (int);
int SmoothedTransform_GetTargetWorldRotation (int);
int SmoothedTransform_IsInProgress (int);
int ObjectAnimation_GetType (int);
int ObjectAnimation_GetTypeName (int);
int ObjectAnimation_GetTypeStatic ();
int ObjectAnimation_GetTypeNameStatic ();
int ObjectAnimation_ObjectAnimation (int);
void ObjectAnimation_RegisterObject (int);
int ObjectAnimation_BeginLoad_File (int,int);
int ObjectAnimation_BeginLoad_MemoryBuffer (int,int);
int ObjectAnimation_Save_File (int,int);
int ObjectAnimation_Save_MemoryBuffer (int,int);
int ObjectAnimation_LoadXML (int,int);
int ObjectAnimation_SaveXML (int,int);
void ObjectAnimation_AddAttributeAnimation (int,int,int,int,float);
void ObjectAnimation_RemoveAttributeAnimation (int,int);
void ObjectAnimation_RemoveAttributeAnimation0 (int,int);
int ObjectAnimation_GetAttributeAnimation (int,int);
int ObjectAnimation_GetAttributeAnimationWrapMode (int,int);
float ObjectAnimation_GetAttributeAnimationSpeed (int,int);
int ObjectAnimation_GetAttributeAnimationInfo (int,int);
int ObjectFactory_CreateObject (int);
int ObjectFactory_GetContext (int);
int ObjectFactory_GetTypeInfo (int);
int ObjectFactory_GetType (int);
int ObjectFactory_GetTypeName (int);
int OcclusionBuffer_GetType (int);
int OcclusionBuffer_GetTypeName (int);
int OcclusionBuffer_GetTypeStatic ();
int OcclusionBuffer_GetTypeNameStatic ();
int OcclusionBuffer_OcclusionBuffer (int);
int OcclusionBuffer_SetSize (int,int,int,int);
void OcclusionBuffer_SetView (int,int);
void OcclusionBuffer_SetMaxTriangles (int,int);
void OcclusionBuffer_SetCullMode (int,int);
void OcclusionBuffer_Reset (int);
void OcclusionBuffer_Clear (int);
int OcclusionBuffer_AddTriangles (int,int,int,int,int,int);
int OcclusionBuffer_AddTriangles0 (int,int,int,int,int,int,int,int);
void OcclusionBuffer_DrawTriangles (int);
void OcclusionBuffer_BuildDepthHierarchy (int);
void OcclusionBuffer_ResetUseTimer (int);
int OcclusionBuffer_GetBuffer (int);
int OcclusionBuffer_GetView (int);
int OcclusionBuffer_GetProjection (int);
int OcclusionBuffer_GetWidth (int);
int OcclusionBuffer_GetHeight (int);
int OcclusionBuffer_GetNumTriangles (int);
int OcclusionBuffer_GetMaxTriangles (int);
int OcclusionBuffer_GetCullMode (int);
int OcclusionBuffer_IsThreaded (int);
int OcclusionBuffer_IsVisible (int,int);
int OcclusionBuffer_GetUseTimer (int);
int ParticleEffect_GetType (int);
int ParticleEffect_GetTypeName (int);
int ParticleEffect_GetTypeStatic ();
int ParticleEffect_GetTypeNameStatic ();
int ParticleEffect_ParticleEffect (int);
void ParticleEffect_RegisterObject (int);
int ParticleEffect_BeginLoad_File (int,int);
int ParticleEffect_BeginLoad_MemoryBuffer (int,int);
int ParticleEffect_EndLoad (int);
int ParticleEffect_Save_File (int,int);
int ParticleEffect_Save_MemoryBuffer (int,int);
int ParticleEffect_Save0 (int,int);
int ParticleEffect_Load (int,int);
void ParticleEffect_SetMaterial (int,int);
void ParticleEffect_SetNumParticles (int,int);
void ParticleEffect_SetUpdateInvisible (int,int);
void ParticleEffect_SetRelative (int,int);
void ParticleEffect_SetScaled (int,int);
void ParticleEffect_SetSorted (int,int);
void ParticleEffect_SetFixedScreenSize (int,int);
void ParticleEffect_SetAnimationLodBias (int,float);
void ParticleEffect_SetEmitterType (int,int);
void ParticleEffect_SetEmitterSize (int,int);
void ParticleEffect_SetMinDirection (int,int);
void ParticleEffect_SetMaxDirection (int,int);
void ParticleEffect_SetConstantForce (int,int);
void ParticleEffect_SetDampingForce (int,float);
void ParticleEffect_SetActiveTime (int,float);
void ParticleEffect_SetInactiveTime (int,float);
void ParticleEffect_SetMinEmissionRate (int,float);
void ParticleEffect_SetMaxEmissionRate (int,float);
void ParticleEffect_SetMinParticleSize (int,int);
void ParticleEffect_SetMaxParticleSize (int,int);
void ParticleEffect_SetMinTimeToLive (int,float);
void ParticleEffect_SetMaxTimeToLive (int,float);
void ParticleEffect_SetMinVelocity (int,float);
void ParticleEffect_SetMaxVelocity (int,float);
void ParticleEffect_SetMinRotation (int,float);
void ParticleEffect_SetMaxRotation (int,float);
void ParticleEffect_SetMinRotationSpeed (int,float);
void ParticleEffect_SetMaxRotationSpeed (int,float);
void ParticleEffect_SetSizeAdd (int,float);
void ParticleEffect_SetSizeMul (int,float);
void ParticleEffect_SetFaceCameraMode (int,int);
void ParticleEffect_AddColorTime (int,int,float);
void ParticleEffect_RemoveColorFrame (int,int);
void ParticleEffect_SetColorFrame (int,int,int);
void ParticleEffect_SetNumColorFrames (int,int);
void ParticleEffect_SortColorFrames (int);
void ParticleEffect_RemoveTextureFrame (int,int);
void ParticleEffect_SetTextureFrame (int,int,int);
void ParticleEffect_SetNumTextureFrames (int,int);
void ParticleEffect_SortTextureFrames (int);
int ParticleEffect_Clone (int,int);
int ParticleEffect_GetMaterial (int);
int ParticleEffect_GetNumParticles (int);
int ParticleEffect_GetUpdateInvisible (int);
int ParticleEffect_IsRelative (int);
int ParticleEffect_IsScaled (int);
int ParticleEffect_IsSorted (int);
int ParticleEffect_IsFixedScreenSize (int);
float ParticleEffect_GetAnimationLodBias (int);
int ParticleEffect_GetEmitterType (int);
int ParticleEffect_GetEmitterSize (int);
int ParticleEffect_GetMinDirection (int);
int ParticleEffect_GetMaxDirection (int);
int ParticleEffect_GetConstantForce (int);
float ParticleEffect_GetDampingForce (int);
float ParticleEffect_GetActiveTime (int);
float ParticleEffect_GetInactiveTime (int);
float ParticleEffect_GetMinEmissionRate (int);
float ParticleEffect_GetMaxEmissionRate (int);
int ParticleEffect_GetMinParticleSize (int);
int ParticleEffect_GetMaxParticleSize (int);
float ParticleEffect_GetMinTimeToLive (int);
float ParticleEffect_GetMaxTimeToLive (int);
float ParticleEffect_GetMinVelocity (int);
float ParticleEffect_GetMaxVelocity (int);
float ParticleEffect_GetMinRotation (int);
float ParticleEffect_GetMaxRotation (int);
float ParticleEffect_GetMinRotationSpeed (int);
float ParticleEffect_GetMaxRotationSpeed (int);
float ParticleEffect_GetSizeAdd (int);
float ParticleEffect_GetSizeMul (int);
int ParticleEffect_GetNumColorFrames (int);
int ParticleEffect_GetColorFrame (int,int);
int ParticleEffect_GetNumTextureFrames (int);
int ParticleEffect_GetTextureFrame (int,int);
int ParticleEffect_GetFaceCameraMode (int);
int ParticleEffect_GetRandomDirection (int);
int ParticleEffect_GetRandomSize (int);
float ParticleEffect_GetRandomVelocity (int);
float ParticleEffect_GetRandomTimeToLive (int);
float ParticleEffect_GetRandomRotationSpeed (int);
float ParticleEffect_GetRandomRotation (int);
int ParticleEmitter_GetType (int);
int ParticleEmitter_GetTypeName (int);
int ParticleEmitter_GetTypeStatic ();
int ParticleEmitter_GetTypeNameStatic ();
int ParticleEmitter_ParticleEmitter (int);
void ParticleEmitter_RegisterObject (int);
void ParticleEmitter_OnSetEnabled (int);
void ParticleEmitter_SetEffect (int,int);
void ParticleEmitter_SetNumParticles (int,int);
void ParticleEmitter_SetEmitting (int,int);
void ParticleEmitter_SetSerializeParticles (int,int);
void ParticleEmitter_SetAutoRemoveMode (int,int);
void ParticleEmitter_ResetEmissionTimer (int);
void ParticleEmitter_RemoveAllParticles (int);
void ParticleEmitter_Reset (int);
void ParticleEmitter_ApplyEffect (int);
int ParticleEmitter_GetEffect (int);
int ParticleEmitter_GetNumParticles (int);
int ParticleEmitter_IsEmitting (int);
int ParticleEmitter_GetSerializeParticles (int);
int ParticleEmitter_GetAutoRemoveMode (int);
int ParticleEmitter_GetEffectAttr (int);
int Pass_Pass (int);
void Pass_SetBlendMode (int,int);
void Pass_SetCullMode (int,int);
void Pass_SetDepthTestMode (int,int);
void Pass_SetLightingMode (int,int);
void Pass_SetDepthWrite (int,int);
void Pass_SetAlphaToCoverage (int,int);
void Pass_SetIsDesktop (int,int);
void Pass_SetVertexShader (int,int);
void Pass_SetPixelShader (int,int);
void Pass_SetVertexShaderDefines (int,int);
void Pass_SetPixelShaderDefines (int,int);
void Pass_SetVertexShaderDefineExcludes (int,int);
void Pass_SetPixelShaderDefineExcludes (int,int);
void Pass_ReleaseShaders (int);
void Pass_MarkShadersLoaded (int,int);
int Pass_GetName (int);
int Pass_GetIndex (int);
int Pass_GetBlendMode (int);
int Pass_GetCullMode (int);
int Pass_GetDepthTestMode (int);
int Pass_GetLightingMode (int);
int Pass_GetShadersLoadedFrameNumber (int);
int Pass_GetDepthWrite (int);
int Pass_GetAlphaToCoverage (int);
int Pass_IsDesktop (int);
int Pass_GetVertexShader (int);
int Pass_GetPixelShader (int);
int Pass_GetVertexShaderDefines (int);
int Pass_GetPixelShaderDefines (int);
int Pass_GetVertexShaderDefineExcludes (int);
int Pass_GetPixelShaderDefineExcludes (int);
int Pass_GetEffectiveVertexShaderDefines (int);
int Pass_GetEffectivePixelShaderDefines (int);
int Plugin_GetType (int);
int Plugin_GetTypeName (int);
int Plugin_GetTypeStatic ();
int Plugin_GetTypeNameStatic ();
int Plugin_Plugin (int);
int Plugin_LoadAndroidPlugin (int);
void Plugin_sendEvent (int,int);
void Plugin_OnPluginEvent (int);
int RenderSurface_RenderSurface (int);
void RenderSurface_SetNumViewports (int,int);
void RenderSurface_SetViewport (int,int,int);
void RenderSurface_SetUpdateMode (int,int);
void RenderSurface_SetLinkedRenderTarget (int,int);
void RenderSurface_SetLinkedDepthStencil (int,int);
void RenderSurface_QueueUpdate (int);
void RenderSurface_Release (int);
int RenderSurface_CreateRenderBuffer (int,int,int,int,int);
int RenderSurface_GetWidth (int);
int RenderSurface_GetHeight (int);
int RenderSurface_GetUsage (int);
int RenderSurface_GetMultiSample (int);
int RenderSurface_GetAutoResolve (int);
int RenderSurface_GetNumViewports (int);
int RenderSurface_GetViewport (int,int);
int RenderSurface_GetUpdateMode (int);
int RenderSurface_GetLinkedRenderTarget (int);
int RenderSurface_GetLinkedDepthStencil (int);
int RenderSurface_IsUpdateQueued (int);
void RenderSurface_ResetUpdateQueued (int);
int RenderSurface_GetParentTexture (int);
int RenderSurface_GetSurface (int);
int RenderSurface_GetRenderTargetView (int);
int RenderSurface_GetReadOnlyView (int);
int RenderSurface_GetTarget (int);
int RenderSurface_GetRenderBuffer (int);
int RenderSurface_IsResolveDirty (int);
void RenderSurface_SetResolveDirty (int,int);
int ResourceWithMetadata_GetType (int);
int ResourceWithMetadata_GetTypeName (int);
int ResourceWithMetadata_GetTypeStatic ();
int ResourceWithMetadata_GetTypeNameStatic ();
int ResourceWithMetadata_ResourceWithMetadata (int);
void ResourceWithMetadata_AddMetadata_0 (int,int,int);
void ResourceWithMetadata_AddMetadata_1 (int,int,int);
void ResourceWithMetadata_AddMetadata_2 (int,int,int);
void ResourceWithMetadata_AddMetadata_3 (int,int,int);
void ResourceWithMetadata_AddMetadata_4 (int,int,int);
void ResourceWithMetadata_AddMetadata_5 (int,int,int);
void ResourceWithMetadata_AddMetadata_6 (int,int,int);
void ResourceWithMetadata_AddMetadata_7 (int,int,int);
void ResourceWithMetadata_AddMetadata_8 (int,int,int);
void ResourceWithMetadata_AddMetadata_9 (int,int,int);
void ResourceWithMetadata_AddMetadata_10 (int,int,int);
void ResourceWithMetadata_AddMetadata_11 (int,int,int);
void ResourceWithMetadata_AddMetadata_12 (int,int,float);
void ResourceWithMetadata_AddMetadata_13 (int,int,int);
void ResourceWithMetadata_AddMetadata_14 (int,int,int);
void ResourceWithMetadata_RemoveMetadata (int,int);
void ResourceWithMetadata_RemoveAllMetadata (int);
int ResourceWithMetadata_HasMetadata (int);
int RibbonTrail_GetType (int);
int RibbonTrail_GetTypeName (int);
int RibbonTrail_GetTypeStatic ();
int RibbonTrail_GetTypeNameStatic ();
int RibbonTrail_RibbonTrail (int);
void RibbonTrail_RegisterObject (int);
void RibbonTrail_OnSetEnabled (int);
int RibbonTrail_GetUpdateGeometryType (int);
void RibbonTrail_SetMaterial (int,int);
void RibbonTrail_SetVertexDistance (int,float);
void RibbonTrail_SetWidth (int,float);
void RibbonTrail_SetStartColor (int,int);
void RibbonTrail_SetEndColor (int,int);
void RibbonTrail_SetStartScale (int,float);
void RibbonTrail_SetEndScale (int,float);
void RibbonTrail_SetTrailType (int,int);
void RibbonTrail_SetBaseVelocity (int,int);
void RibbonTrail_SetSorted (int,int);
void RibbonTrail_SetLifetime (int,float);
void RibbonTrail_SetEmitting (int,int);
void RibbonTrail_SetUpdateInvisible (int,int);
void RibbonTrail_SetTailColumn (int,int);
void RibbonTrail_SetAnimationLodBias (int,float);
void RibbonTrail_Commit (int);
int RibbonTrail_GetMaterial (int);
int RibbonTrail_GetMaterialAttr (int);
float RibbonTrail_GetVertexDistance (int);
float RibbonTrail_GetWidth (int);
int RibbonTrail_GetStartColor (int);
int RibbonTrail_GetEndColor (int);
float RibbonTrail_GetStartScale (int);
float RibbonTrail_GetEndScale (int);
int RibbonTrail_IsSorted (int);
float RibbonTrail_GetLifetime (int);
float RibbonTrail_GetAnimationLodBias (int);
int RibbonTrail_GetTrailType (int);
int RibbonTrail_GetBaseVelocity (int);
int RibbonTrail_GetTailColumn (int);
int RibbonTrail_IsEmitting (int);
int RibbonTrail_GetUpdateInvisible (int);
int SceneResolver_SceneResolver ();
void SceneResolver_Reset (int);
void SceneResolver_AddNode (int,int,int);
void SceneResolver_AddComponent (int,int,int);
void SceneResolver_Resolve (int);
int Shader_GetType (int);
int Shader_GetTypeName (int);
int Shader_GetTypeStatic ();
int Shader_GetTypeNameStatic ();
int Shader_Shader (int);
void Shader_RegisterObject (int);
int Shader_BeginLoad_File (int,int);
int Shader_BeginLoad_MemoryBuffer (int,int);
int Shader_EndLoad (int);
int Shader_GetVariation (int,int,int);
int Shader_GetSourceCode (int,int);
int Shader_GetTimeStamp (int);
int ShaderParameterAnimationInfo_ShaderParameterAnimationInfo (int,int,int,int,float);
int ShaderParameterAnimationInfo_GetName (int);
int ShaderPrecache_GetType (int);
int ShaderPrecache_GetTypeName (int);
int ShaderPrecache_GetTypeStatic ();
int ShaderPrecache_GetTypeNameStatic ();
int ShaderPrecache_ShaderPrecache (int,int);
void ShaderPrecache_StoreShaders (int,int,int);
void ShaderPrecache_LoadShaders_File (int,int);
void ShaderPrecache_LoadShaders_MemoryBuffer (int,int);
int ShaderProgram_CastToGPUObject (int);
int ShaderProgram_ShaderProgram (int,int,int);
int ShaderVariation_CastToGPUObject (int);
int ShaderVariation_ShaderVariation (int,int);
void ShaderVariation_Release (int);
int ShaderVariation_Create (int);
void ShaderVariation_SetName (int,int);
void ShaderVariation_SetDefines (int,int);
int ShaderVariation_GetOwner (int);
int ShaderVariation_GetShaderType (int);
int ShaderVariation_GetName (int);
int ShaderVariation_GetFullName (int);
int ShaderVariation_HasParameter (int,int);
int ShaderVariation_HasTextureUnit (int,int);
uint64_t ShaderVariation_GetElementHash (int);
int ShaderVariation_GetDefines (int);
int ShaderVariation_GetCompilerOutput (int);
int ShaderVariation_GetConstantBufferSizes (int);
int ShaderVariation_GetDefinesClipPlane (int);
int Skybox_GetType (int);
int Skybox_GetTypeName (int);
int Skybox_GetTypeStatic ();
int Skybox_GetTypeNameStatic ();
int Skybox_Skybox (int);
void Skybox_RegisterObject (int);
int Sphere_Sphere ();
int Sphere_Sphere0 (int);
int Sphere_Sphere1 (int,float);
int Sphere_Sphere2 (int,int);
int Sphere_Sphere3 (int);
int Sphere_Sphere4 (int);
int Sphere_Sphere5 (int);
void Sphere_Define (int,int);
void Sphere_Define6 (int,int,float);
void Sphere_Define7 (int,int,int);
void Sphere_Define8 (int,int);
void Sphere_Define9 (int,int);
void Sphere_Define10 (int,int);
void Sphere_Merge (int,int);
void Sphere_Merge11 (int,int,int);
void Sphere_Merge12 (int,int);
void Sphere_Merge13 (int,int);
void Sphere_Merge14 (int,int);
void Sphere_Merge15 (int,int);
void Sphere_Clear (int);
int Sphere_Defined (int);
int Sphere_IsInside (int,int);
int Sphere_IsInside16 (int,int);
int Sphere_IsInsideFast (int,int);
int Sphere_IsInside17 (int,int);
int Sphere_IsInsideFast18 (int,int);
float Sphere_Distance (int,int);
int Sphere_GetLocalPoint (int,float,float);
int Sphere_GetPoint (int,float,float);
int Sphere_GetCenter (int);
float Sphere_GetRadius (int);
void Sphere_SetRadius (int,float);
int Spline_Spline ();
int Spline_Spline0 (int);
int Spline_GetInterpolationMode (int);
int Spline_GetKnot (int,int);
int Spline_GetPoint (int,float);
void Spline_SetInterpolationMode (int,int);
void Spline_SetKnot_0 (int,int,int);
void Spline_SetKnot_1 (int,int,int);
void Spline_SetKnot_2 (int,int,int);
void Spline_SetKnot_3 (int,int,int);
void Spline_SetKnot_4 (int,int,int);
void Spline_SetKnot_5 (int,int,int);
void Spline_SetKnot_6 (int,int,int);
void Spline_SetKnot_7 (int,int,int);
void Spline_SetKnot_8 (int,int,int);
void Spline_SetKnot_9 (int,int,int);
void Spline_SetKnot_10 (int,int,int);
void Spline_SetKnot_11 (int,int,int);
void Spline_SetKnot_12 (int,float,int);
void Spline_SetKnot_13 (int,int,int);
void Spline_SetKnot_14 (int,int,int);
void Spline_AddKnot_0 (int,int);
void Spline_AddKnot_1 (int,int);
void Spline_AddKnot_2 (int,int);
void Spline_AddKnot_3 (int,int);
void Spline_AddKnot_4 (int,int);
void Spline_AddKnot_5 (int,int);
void Spline_AddKnot_6 (int,int);
void Spline_AddKnot_7 (int,int);
void Spline_AddKnot_8 (int,int);
void Spline_AddKnot_9 (int,int);
void Spline_AddKnot_10 (int,int);
void Spline_AddKnot_11 (int,int);
void Spline_AddKnot_12 (int,float);
void Spline_AddKnot_13 (int,int);
void Spline_AddKnot_14 (int,int);
void Spline_AddKnot1_0 (int,int,int);
void Spline_AddKnot1_1 (int,int,int);
void Spline_AddKnot1_2 (int,int,int);
void Spline_AddKnot1_3 (int,int,int);
void Spline_AddKnot1_4 (int,int,int);
void Spline_AddKnot1_5 (int,int,int);
void Spline_AddKnot1_6 (int,int,int);
void Spline_AddKnot1_7 (int,int,int);
void Spline_AddKnot1_8 (int,int,int);
void Spline_AddKnot1_9 (int,int,int);
void Spline_AddKnot1_10 (int,int,int);
void Spline_AddKnot1_11 (int,int,int);
void Spline_AddKnot1_12 (int,float,int);
void Spline_AddKnot1_13 (int,int,int);
void Spline_AddKnot1_14 (int,int,int);
void Spline_RemoveKnot (int);
void Spline_RemoveKnot2 (int,int);
void Spline_Clear (int);
int SplinePath_GetType (int);
int SplinePath_GetTypeName (int);
int SplinePath_GetTypeStatic ();
int SplinePath_GetTypeNameStatic ();
int SplinePath_SplinePath (int);
void SplinePath_RegisterObject (int);
void SplinePath_ApplyAttributes (int);
void SplinePath_DrawDebugGeometry (int,int,int);
void SplinePath_AddControlPoint (int,int,int);
void SplinePath_RemoveControlPoint (int,int);
void SplinePath_ClearControlPoints (int);
void SplinePath_SetInterpolationMode (int,int);
void SplinePath_SetSpeed (int,float);
void SplinePath_SetPosition (int,float);
void SplinePath_SetControlledNode (int,int);
int SplinePath_GetInterpolationMode (int);
float SplinePath_GetSpeed (int);
float SplinePath_GetLength (int);
int SplinePath_GetPosition (int);
int SplinePath_GetControlledNode (int);
int SplinePath_GetPoint (int,float);
void SplinePath_Move (int,float);
void SplinePath_Reset (int);
int SplinePath_IsFinished (int);
void SplinePath_SetControlledIdAttr (int,int);
int SplinePath_GetControlledIdAttr (int);
int StaticModel_GetType (int);
int StaticModel_GetTypeName (int);
int StaticModel_GetTypeStatic ();
int StaticModel_GetTypeNameStatic ();
int StaticModel_StaticModel (int);
void StaticModel_RegisterObject (int);
int StaticModel_GetLodGeometry (int,int,int);
int StaticModel_GetNumOccluderTriangles (int);
int StaticModel_DrawOcclusion (int,int);
void StaticModel_SetModel (int,int);
void StaticModel_SetMaterial (int,int);
int StaticModel_SetMaterial0 (int,int,int);
void StaticModel_SetOcclusionLodLevel (int,int);
void StaticModel_ApplyMaterialList (int,int);
int StaticModel_GetModel (int);
int StaticModel_GetNumGeometries (int);
int StaticModel_GetMaterial (int);
int StaticModel_GetMaterial1 (int,int);
int StaticModel_GetOcclusionLodLevel (int);
int StaticModel_IsInside (int,int);
int StaticModel_IsInsideLocal (int,int);
int StaticModel_GetModelAttr (int);
int StaticModelGroup_GetType (int);
int StaticModelGroup_GetTypeName (int);
int StaticModelGroup_GetTypeStatic ();
int StaticModelGroup_GetTypeNameStatic ();
int StaticModelGroup_StaticModelGroup (int);
void StaticModelGroup_RegisterObject (int);
void StaticModelGroup_ApplyAttributes (int);
int StaticModelGroup_GetNumOccluderTriangles (int);
int StaticModelGroup_DrawOcclusion (int,int);
void StaticModelGroup_AddInstanceNode (int,int);
void StaticModelGroup_RemoveInstanceNode (int,int);
void StaticModelGroup_RemoveAllInstanceNodes (int);
int StaticModelGroup_GetNumInstanceNodes (int);
int StaticModelGroup_GetInstanceNode (int,int);
int Technique_GetType (int);
int Technique_GetTypeName (int);
int Technique_GetTypeStatic ();
int Technique_GetTypeNameStatic ();
int Technique_Technique (int);
void Technique_RegisterObject (int);
int Technique_BeginLoad_File (int,int);
int Technique_BeginLoad_MemoryBuffer (int,int);
void Technique_SetIsDesktop (int,int);
int Technique_CreatePass (int,int);
void Technique_RemovePass (int,int);
void Technique_ReleaseShaders (int);
int Technique_Clone (int,int);
int Technique_IsDesktop (int);
int Technique_IsSupported (int);
int Technique_HasPass (int,int);
int Technique_HasPass0 (int,int);
int Technique_GetPass (int,int);
int Technique_GetPass1 (int,int);
int Technique_GetSupportedPass (int,int);
int Technique_GetSupportedPass2 (int,int);
int Technique_GetNumPasses (int);
int Technique_CloneWithDefines (int,int,int);
int Technique_GetPassIndex (int);
int TerrainPatch_GetType (int);
int TerrainPatch_GetTypeName (int);
int TerrainPatch_GetTypeStatic ();
int TerrainPatch_GetTypeNameStatic ();
int TerrainPatch_TerrainPatch (int);
void TerrainPatch_RegisterObject (int);
int TerrainPatch_GetUpdateGeometryType (int);
int TerrainPatch_GetLodGeometry (int,int,int);
int TerrainPatch_GetNumOccluderTriangles (int);
int TerrainPatch_DrawOcclusion (int,int);
void TerrainPatch_DrawDebugGeometry (int,int,int);
void TerrainPatch_SetOwner (int,int);
void TerrainPatch_SetNeighbors (int,int,int,int,int);
void TerrainPatch_SetMaterial (int,int);
void TerrainPatch_SetBoundingBox (int,int);
void TerrainPatch_SetCoordinates (int,int);
void TerrainPatch_ResetLod (int);
int TerrainPatch_GetGeometry (int);
int TerrainPatch_GetMaxLodGeometry (int);
int TerrainPatch_GetOcclusionGeometry (int);
int TerrainPatch_GetVertexBuffer (int);
int TerrainPatch_GetOwner (int);
int TerrainPatch_GetNorthPatch (int);
int TerrainPatch_GetSouthPatch (int);
int TerrainPatch_GetWestPatch (int);
int TerrainPatch_GetEastPatch (int);
int TerrainPatch_GetCoordinates (int);
int TerrainPatch_GetLodLevel (int);
int Texture_CastToGPUObject (int);
int Texture_GetType (int);
int Texture_GetTypeName (int);
int Texture_GetTypeStatic ();
int Texture_GetTypeNameStatic ();
int Texture_Texture (int);
void Texture_SetNumLevels (int,int);
void Texture_SetFilterMode (int,int);
void Texture_SetAddressMode (int,int,int);
void Texture_SetAnisotropy (int,int);
void Texture_SetShadowCompare (int,int);
void Texture_SetBorderColor (int,int);
void Texture_SetSRGB (int,int);
void Texture_SetBackupTexture (int,int);
void Texture_SetMipsToSkip (int,int,int);
int Texture_GetFormat (int);
int Texture_IsCompressed (int);
int Texture_GetLevels (int);
int Texture_GetWidth (int);
int Texture_GetHeight (int);
int Texture_GetDepth (int);
int Texture_GetFilterMode (int);
int Texture_GetAddressMode (int,int);
int Texture_GetAnisotropy (int);
int Texture_GetShadowCompare (int);
int Texture_GetBorderColor (int);
int Texture_GetSRGB (int);
int Texture_GetMultiSample (int);
int Texture_GetAutoResolve (int);
int Texture_IsResolveDirty (int);
int Texture_GetLevelsDirty (int);
int Texture_GetBackupTexture (int);
int Texture_GetMipsToSkip (int,int);
int Texture_GetLevelWidth (int,int);
int Texture_GetLevelHeight (int,int);
int Texture_GetLevelDepth (int,int);
int Texture_GetUsage (int);
int Texture_GetDataSize (int,int,int);
int Texture_GetDataSize0 (int,int,int,int);
int Texture_GetRowDataSize (int,int);
int Texture_GetComponents (int);
int Texture_GetParametersDirty (int);
void Texture_SetParameters (int,int);
void Texture_SetParameters1 (int,int);
void Texture_SetParametersDirty (int);
void Texture_UpdateParameters (int);
int Texture_GetShaderResourceView (int);
int Texture_GetSampler (int);
int Texture_GetResolveTexture (int);
int Texture_GetSRGBFormat (int,int);
void Texture_SetResolveDirty (int,int);
void Texture_SetLevelsDirty (int);
void Texture_RegenerateLevels (int);
int Texture_CheckMaxLevels (int,int,int);
int Texture_CheckMaxLevels2 (int,int,int,int);
int Texture2DArray_GetType (int);
int Texture2DArray_GetTypeName (int);
int Texture2DArray_GetTypeStatic ();
int Texture2DArray_GetTypeNameStatic ();
int Texture2DArray_Texture2DArray (int);
void Texture2DArray_RegisterObject (int);
int Texture2DArray_BeginLoad_File (int,int);
int Texture2DArray_BeginLoad_MemoryBuffer (int,int);
int Texture2DArray_EndLoad (int);
void Texture2DArray_OnDeviceLost (int);
void Texture2DArray_OnDeviceReset (int);
void Texture2DArray_Release (int);
void Texture2DArray_SetLayers (int,int);
int Texture2DArray_SetSize (int,int,int,int,int,int);
int Texture2DArray_SetData (int,int,int,int,int,int,int,int);
int Texture2DArray_SetData0_File (int,int,int);
int Texture2DArray_SetData0_MemoryBuffer (int,int,int);
int Texture2DArray_SetData1 (int,int,int,int);
int Texture2DArray_GetLayers (int);
int Texture2DArray_GetData (int,int,int,int);
int Texture2DArray_GetRenderSurface (int);
int Texture3D_GetType (int);
int Texture3D_GetTypeName (int);
int Texture3D_GetTypeStatic ();
int Texture3D_GetTypeNameStatic ();
int Texture3D_Texture3D (int);
void Texture3D_RegisterObject (int);
int Texture3D_BeginLoad_File (int,int);
int Texture3D_BeginLoad_MemoryBuffer (int,int);
int Texture3D_EndLoad (int);
void Texture3D_Release (int);
int Texture3D_SetSize (int,int,int,int,int,int);
int Texture3D_SetData (int,int,int,int,int,int,int,int,int);
int Texture3D_SetData0 (int,int,int);
int Texture3D_GetData (int,int,int);
int TextureCube_GetType (int);
int TextureCube_GetTypeName (int);
int TextureCube_GetTypeStatic ();
int TextureCube_GetTypeNameStatic ();
int TextureCube_TextureCube (int);
void TextureCube_RegisterObject (int);
int TextureCube_BeginLoad_File (int,int);
int TextureCube_BeginLoad_MemoryBuffer (int,int);
int TextureCube_EndLoad (int);
void TextureCube_Release (int);
int TextureCube_SetSize (int,int,int,int,int);
int TextureCube_SetData (int,int,int,int,int,int,int,int);
int TextureCube_SetData0_File (int,int,int);
int TextureCube_SetData0_MemoryBuffer (int,int,int);
int TextureCube_SetData1 (int,int,int,int);
int TextureCube_GetData (int,int,int,int);
int TextureCube_GetImage (int,int);
int TextureCube_GetRenderSurface (int,int);
int TriangleMeshData_TriangleMeshData (int,int);
int TriangleMeshData_TriangleMeshData0 (int);
int UIComponent_GetType (int);
int UIComponent_GetTypeName (int);
int UIComponent_GetTypeStatic ();
int UIComponent_GetTypeNameStatic ();
int UIComponent_UIComponent (int);
void UIComponent_RegisterObject (int);
int UIComponent_GetRoot (int);
int UIComponent_GetMaterial (int);
int UIComponent_GetTexture (int);
void UIComponent_SetViewportIndex (int,int);
int UISelectable_GetType (int);
int UISelectable_GetTypeName (int);
int UISelectable_GetTypeStatic ();
int UISelectable_GetTypeNameStatic ();
void UISelectable_RegisterObject (int);
void UISelectable_SetSelectionColor (int,int);
void UISelectable_SetHoverColor (int,int);
int UISelectable_GetSelectionColor (int);
int UISelectable_GetHoverColor (int);
int UISelectable_UISelectable (int);
int UnknownComponent_UnknownComponent (int);
void UnknownComponent_RegisterObject (int);
int UnknownComponent_GetType (int);
int UnknownComponent_GetTypeName (int);
int UnknownComponent_Load_File (int,int);
int UnknownComponent_Load_MemoryBuffer (int,int);
int UnknownComponent_LoadXML (int,int);
int UnknownComponent_Save_File (int,int);
int UnknownComponent_Save_MemoryBuffer (int,int);
int UnknownComponent_SaveXML (int,int);
void UnknownComponent_SetTypeName (int,int);
void UnknownComponent_SetType (int,int);
int UnknownComponent_GetUseXML (int);
int UnknownComponent_GetTypeStatic ();
int UnknownComponent_GetTypeNameStatic ();
int VGCanvas_GetType (int);
int VGCanvas_GetTypeName (int);
int VGCanvas_GetTypeStatic ();
int VGCanvas_GetTypeNameStatic ();
int VGCanvas_VGCanvas (int);
void VGCanvas_RegisterObject (int);
int VGTextRow_GetType (int);
int VGTextRow_GetTypeName (int);
int VGTextRow_GetTypeStatic ();
int VGTextRow_GetTypeNameStatic ();
int VGTextRow_VGTextRow (int);
int VGTextRow_VGTextRow0 (int,int,float,float,float);
int VGTextRow_GetText (int);
void VGTextRow_SetText (int,int);
float VGTextRow_GetWidth (int);
void VGTextRow_SetWidth (int,float);
float VGTextRow_GetMin (int);
void VGTextRow_SetMin (int,float);
float VGTextRow_GetMax (int);
void VGTextRow_SetMax (int,float);
int ValueAnimation_GetType (int);
int ValueAnimation_GetTypeName (int);
int ValueAnimation_GetTypeStatic ();
int ValueAnimation_GetTypeNameStatic ();
int ValueAnimation_ValueAnimation (int);
void ValueAnimation_RegisterObject (int);
int ValueAnimation_BeginLoad_File (int,int);
int ValueAnimation_BeginLoad_MemoryBuffer (int,int);
int ValueAnimation_Save_File (int,int);
int ValueAnimation_Save_MemoryBuffer (int,int);
int ValueAnimation_LoadXML (int,int);
int ValueAnimation_SaveXML (int,int);
void ValueAnimation_SetOwner (int,int);
void ValueAnimation_SetInterpolationMethod (int,int);
void ValueAnimation_SetSplineTension (int,float);
void ValueAnimation_SetValueType (int,int);
int ValueAnimation_SetKeyFrame_0 (int,float,int);
int ValueAnimation_SetKeyFrame_1 (int,float,int);
int ValueAnimation_SetKeyFrame_2 (int,float,int);
int ValueAnimation_SetKeyFrame_3 (int,float,int);
int ValueAnimation_SetKeyFrame_4 (int,float,int);
int ValueAnimation_SetKeyFrame_5 (int,float,int);
int ValueAnimation_SetKeyFrame_6 (int,float,int);
int ValueAnimation_SetKeyFrame_7 (int,float,int);
int ValueAnimation_SetKeyFrame_8 (int,float,int);
int ValueAnimation_SetKeyFrame_9 (int,float,int);
int ValueAnimation_SetKeyFrame_10 (int,float,int);
int ValueAnimation_SetKeyFrame_11 (int,float,int);
int ValueAnimation_SetKeyFrame_12 (int,float,float);
int ValueAnimation_SetKeyFrame_13 (int,float,int);
int ValueAnimation_SetKeyFrame_14 (int,float,int);
int ValueAnimation_IsValid (int);
int ValueAnimation_GetOwner (int);
int ValueAnimation_GetInterpolationMethod (int);
float ValueAnimation_GetSplineTension (int);
int ValueAnimation_GetValueType (int);
float ValueAnimation_GetBeginTime (int);
float ValueAnimation_GetEndTime (int);
int ValueAnimation_GetAnimationValue (int,float);
int ValueAnimation_HasEventFrames (int);
int ValueAnimationInfo_ValueAnimationInfo (int,int,float);
int ValueAnimationInfo_ValueAnimationInfo0 (int,int,int,float);
int ValueAnimationInfo_Update (int,float);
int ValueAnimationInfo_SetTime (int,float);
void ValueAnimationInfo_SetWrapMode (int,int);
void ValueAnimationInfo_SetSpeed (int,float);
int ValueAnimationInfo_GetTarget (int);
int ValueAnimationInfo_GetAnimation (int);
int ValueAnimationInfo_GetWrapMode (int);
float ValueAnimationInfo_GetTime (int);
float ValueAnimationInfo_GetSpeed (int);
int VectorGraphics_GetType (int);
int VectorGraphics_GetTypeName (int);
int VectorGraphics_GetTypeStatic ();
int VectorGraphics_GetTypeNameStatic ();
int VectorGraphics_VectorGraphics (int);
void VectorGraphics_Initialize (int);
void VectorGraphics_Clear (int);
int VectorGraphics_GetNVGContext (int);
int VectorGraphics_GetCurrentFrameBuffer (int);
int VectorGraphics_CreateFont (int,int,int);
int VectorGraphics_CreateFontAtIndex (int,int,int,int);
int VectorGraphics_CreateFontMem (int,int,int,int);
int VectorGraphics_CreateFontMemAtIndex (int,int,int,int,int);
int VectorGraphics_FindFont (int,int);
int VectorGraphics_AddFallbackFontId (int,int,int);
void VectorGraphics_ResetFallbackFontsId (int,int);
int VectorGraphics_AddFallbackFont (int,int,int);
void VectorGraphics_ResetFallbackFonts (int,int);
int VectorGraphics_CreateImage (int,int,int);
int VectorGraphics_CreateImageMem (int,int,int,int);
int VectorGraphics_LoadSVGImage (int,int,float,float,int);
float VectorGraphics_GetSVGHeight (int,int);
float VectorGraphics_GetSVGWidth (int,int);
void VectorGraphics_GetSVGSize (int,int,int,int);
int VectorGraphics_CreateImageRGBA (int,int,int,int,int);
void VectorGraphics_UpdateImage (int,int,int);
void VectorGraphics_ImageSize (int,int,int,int);
void VectorGraphics_DeleteImage (int,int);
int VectorGraphics_LoadSVGIntoTexture (int,int);
int Zone_GetType (int);
int Zone_GetTypeName (int);
int Zone_GetTypeStatic ();
int Zone_GetTypeNameStatic ();
int Zone_Zone (int);
void Zone_RegisterObject (int);
void Zone_DrawDebugGeometry (int,int,int);
void Zone_SetBoundingBox (int,int);
void Zone_SetAmbientColor (int,int);
void Zone_SetFogColor (int,int);
void Zone_SetFogStart (int,float);
void Zone_SetFogEnd (int,float);
void Zone_SetFogHeight (int,float);
void Zone_SetFogHeightScale (int,float);
void Zone_SetPriority (int,int);
void Zone_SetHeightFog (int,int);
void Zone_SetOverride (int,int);
void Zone_SetAmbientGradient (int,int);
void Zone_SetZoneTexture (int,int);
int Zone_GetInverseWorldTransform (int);
int Zone_GetAmbientColor (int);
int Zone_GetAmbientStartColor (int);
int Zone_GetAmbientEndColor (int);
int Zone_GetFogColor (int);
float Zone_GetFogStart (int);
float Zone_GetFogEnd (int);
float Zone_GetFogHeight (int);
float Zone_GetFogHeightScale (int);
int Zone_GetPriority (int);
int Zone_GetHeightFog (int);
int Zone_GetOverride (int);
int Zone_GetAmbientGradient (int);
int Zone_GetZoneTexture (int);
int Zone_IsInside (int,int);
int Zone_GetZoneTextureAttr (int);
int urho_navigationmesh_findpath (int,int,int,int);
int NavigationMesh_GetType (int);
int NavigationMesh_GetTypeName (int);
int NavigationMesh_GetTypeStatic ();
int NavigationMesh_GetTypeNameStatic ();
int NavigationMesh_NavigationMesh (int);
void NavigationMesh_RegisterObject (int);
void NavigationMesh_DrawDebugGeometry (int,int,int);
void NavigationMesh_SetTileSize (int,int);
void NavigationMesh_SetCellSize (int,float);
void NavigationMesh_SetCellHeight (int,float);
void NavigationMesh_SetAgentHeight (int,float);
void NavigationMesh_SetAgentRadius (int,float);
void NavigationMesh_SetAgentMaxClimb (int,float);
void NavigationMesh_SetAgentMaxSlope (int,float);
void NavigationMesh_SetRegionMinSize (int,float);
void NavigationMesh_SetRegionMergeSize (int,float);
void NavigationMesh_SetEdgeMaxLength (int,float);
void NavigationMesh_SetEdgeMaxError (int,float);
void NavigationMesh_SetDetailSampleDistance (int,float);
void NavigationMesh_SetDetailSampleMaxError (int,float);
void NavigationMesh_SetPadding (int,int);
void NavigationMesh_SetAreaCost (int,int,float);
int NavigationMesh_Allocate (int,int,int);
int NavigationMesh_Build (int);
int NavigationMesh_Build0 (int,int);
int NavigationMesh_Build1 (int,int,int);
void NavigationMesh_RemoveTile (int,int);
void NavigationMesh_RemoveAllTiles (int);
int NavigationMesh_HasTile (int,int);
int NavigationMesh_GetTileBoundingBox (int,int);
int NavigationMesh_GetTileIndex (int,int);
int NavigationMesh_FindNearestPoint (int,int,int,int,int);
int NavigationMesh_MoveAlongSurface (int,int,int,int,int,int);
int NavigationMesh_GetRandomPoint (int,int,int);
int NavigationMesh_GetRandomPointInCircle (int,int,float,int,int,int);
float NavigationMesh_GetDistanceToWall (int,int,float,int,int,int,int);
int NavigationMesh_Raycast (int,int,int,int,int,int);
void NavigationMesh_DrawDebugGeometry2 (int,int);
int NavigationMesh_GetMeshName (int);
void NavigationMesh_SetMeshName (int,int);
int NavigationMesh_GetTileSize (int);
float NavigationMesh_GetCellSize (int);
float NavigationMesh_GetCellHeight (int);
float NavigationMesh_GetAgentHeight (int);
float NavigationMesh_GetAgentRadius (int);
float NavigationMesh_GetAgentMaxClimb (int);
float NavigationMesh_GetAgentMaxSlope (int);
float NavigationMesh_GetRegionMinSize (int);
float NavigationMesh_GetRegionMergeSize (int);
float NavigationMesh_GetEdgeMaxLength (int);
float NavigationMesh_GetEdgeMaxError (int);
float NavigationMesh_GetDetailSampleDistance (int);
float NavigationMesh_GetDetailSampleMaxError (int);
int NavigationMesh_GetPadding (int);
float NavigationMesh_GetAreaCost (int,int);
int NavigationMesh_IsInitialized (int);
int NavigationMesh_GetBoundingBox (int);
int NavigationMesh_GetWorldBoundingBox (int);
int NavigationMesh_GetNumTiles (int);
void NavigationMesh_SetPartitionType (int,int);
int NavigationMesh_GetPartitionType (int);
void NavigationMesh_SetDrawOffMeshConnections (int,int);
int NavigationMesh_GetDrawOffMeshConnections (int);
void NavigationMesh_SetDrawNavAreas (int,int);
int NavigationMesh_GetDrawNavAreas (int);
int CrowdAgent_GetType (int);
int CrowdAgent_GetTypeName (int);
int CrowdAgent_GetTypeStatic ();
int CrowdAgent_GetTypeNameStatic ();
int CrowdAgent_CrowdAgent (int);
void CrowdAgent_RegisterObject (int);
void CrowdAgent_ApplyAttributes (int);
void CrowdAgent_OnSetEnabled (int);
void CrowdAgent_DrawDebugGeometry (int,int);
void CrowdAgent_DrawDebugGeometry0 (int,int,int);
void CrowdAgent_SetTargetPosition (int,int);
void CrowdAgent_SetTargetVelocity (int,int);
void CrowdAgent_ResetTarget (int);
void CrowdAgent_SetUpdateNodePosition (int,int);
void CrowdAgent_SetMaxAccel (int,float);
void CrowdAgent_SetMaxSpeed (int,float);
void CrowdAgent_SetRadius (int,float);
void CrowdAgent_SetHeight (int,float);
void CrowdAgent_SetQueryFilterType (int,int);
void CrowdAgent_SetObstacleAvoidanceType (int,int);
void CrowdAgent_SetNavigationQuality (int,int);
void CrowdAgent_SetNavigationPushiness (int,int);
int CrowdAgent_GetPosition (int);
int CrowdAgent_GetDesiredVelocity (int);
int CrowdAgent_GetActualVelocity (int);
int CrowdAgent_GetTargetPosition (int);
int CrowdAgent_GetTargetVelocity (int);
int CrowdAgent_GetRequestedTargetType (int);
int CrowdAgent_GetAgentState (int);
int CrowdAgent_GetTargetState (int);
int CrowdAgent_GetUpdateNodePosition (int);
int CrowdAgent_GetAgentCrowdId (int);
float CrowdAgent_GetMaxAccel (int);
float CrowdAgent_GetMaxSpeed (int);
float CrowdAgent_GetRadius (int);
float CrowdAgent_GetHeight (int);
int CrowdAgent_GetQueryFilterType (int);
int CrowdAgent_GetObstacleAvoidanceType (int);
int CrowdAgent_GetNavigationQuality (int);
int CrowdAgent_GetNavigationPushiness (int);
int CrowdAgent_HasRequestedTarget (int);
int CrowdAgent_HasArrived (int);
int CrowdAgent_IsInCrowd (int);
int CrowdManager_GetType (int);
int CrowdManager_GetTypeName (int);
int CrowdManager_GetTypeStatic ();
int CrowdManager_GetTypeNameStatic ();
int CrowdManager_CrowdManager (int);
void CrowdManager_RegisterObject (int);
void CrowdManager_ApplyAttributes (int);
void CrowdManager_DrawDebugGeometry (int,int,int);
void CrowdManager_DrawDebugGeometry0 (int,int);
void CrowdManager_SetCrowdTarget (int,int,int);
void CrowdManager_SetCrowdVelocity (int,int,int);
void CrowdManager_ResetCrowdTarget (int,int);
void CrowdManager_SetMaxAgents (int,int);
void CrowdManager_SetMaxAgentRadius (int,float);
void CrowdManager_SetNavigationMesh (int,int);
void CrowdManager_SetIncludeFlags (int,int,int);
void CrowdManager_SetExcludeFlags (int,int,int);
void CrowdManager_SetAreaCost (int,int,int,float);
void CrowdManager_SetObstacleAvoidanceParams (int,int,int);
int CrowdManager_FindNearestPoint (int,int,int,int);
int CrowdManager_MoveAlongSurface (int,int,int,int,int);
int CrowdManager_GetRandomPoint (int,int,int);
int CrowdManager_GetRandomPointInCircle (int,int,float,int,int);
float CrowdManager_GetDistanceToWall (int,int,float,int,int,int);
int CrowdManager_Raycast (int,int,int,int,int);
int CrowdManager_GetMaxAgents (int);
float CrowdManager_GetMaxAgentRadius (int);
int CrowdManager_GetNavigationMesh (int);
int CrowdManager_GetNumQueryFilterTypes (int);
int CrowdManager_GetNumAreas (int,int);
int CrowdManager_GetIncludeFlags (int,int);
int CrowdManager_GetExcludeFlags (int,int);
float CrowdManager_GetAreaCost (int,int,int);
int CrowdManager_GetNumObstacleAvoidanceTypes (int);
int CrowdManager_GetObstacleAvoidanceParams (int,int);
int DynamicNavigationMesh_GetType (int);
int DynamicNavigationMesh_GetTypeName (int);
int DynamicNavigationMesh_GetTypeStatic ();
int DynamicNavigationMesh_GetTypeNameStatic ();
int DynamicNavigationMesh_DynamicNavigationMesh (int);
void DynamicNavigationMesh_RegisterObject (int);
int DynamicNavigationMesh_Allocate (int,int,int);
int DynamicNavigationMesh_Build (int);
int DynamicNavigationMesh_Build0 (int,int);
int DynamicNavigationMesh_Build1 (int,int,int);
int DynamicNavigationMesh_IsObstacleInTile (int,int,int);
void DynamicNavigationMesh_RemoveTile (int,int);
void DynamicNavigationMesh_RemoveAllTiles (int);
void DynamicNavigationMesh_DrawDebugGeometry (int,int,int);
void DynamicNavigationMesh_DrawDebugGeometry2 (int,int);
void DynamicNavigationMesh_SetMaxObstacles (int,int);
void DynamicNavigationMesh_SetMaxLayers (int,int);
int DynamicNavigationMesh_GetMaxObstacles (int);
int DynamicNavigationMesh_GetMaxLayers (int);
void DynamicNavigationMesh_SetDrawObstacles (int,int);
int DynamicNavigationMesh_GetDrawObstacles (int);
int NavArea_GetType (int);
int NavArea_GetTypeName (int);
int NavArea_GetTypeStatic ();
int NavArea_GetTypeNameStatic ();
int NavArea_NavArea (int);
void NavArea_RegisterObject (int);
void NavArea_DrawDebugGeometry (int,int,int);
int NavArea_GetAreaID (int);
void NavArea_SetAreaID (int,int);
int NavArea_GetBoundingBox (int);
void NavArea_SetBoundingBox (int,int);
int NavArea_GetWorldBoundingBox (int);
int Navigable_GetType (int);
int Navigable_GetTypeName (int);
int Navigable_GetTypeStatic ();
int Navigable_GetTypeNameStatic ();
int Navigable_Navigable (int);
void Navigable_RegisterObject (int);
void Navigable_SetRecursive (int,int);
int Navigable_IsRecursive (int);
int Obstacle_GetType (int);
int Obstacle_GetTypeName (int);
int Obstacle_GetTypeStatic ();
int Obstacle_GetTypeNameStatic ();
int Obstacle_Obstacle (int);
void Obstacle_RegisterObject (int);
void Obstacle_OnSetEnabled (int);
float Obstacle_GetHeight (int);
void Obstacle_SetHeight (int,float);
float Obstacle_GetRadius (int);
void Obstacle_SetRadius (int,float);
int Obstacle_GetObstacleID (int);
void Obstacle_DrawDebugGeometry (int,int,int);
void Obstacle_DrawDebugGeometry0 (int,int);
int OffMeshConnection_GetType (int);
int OffMeshConnection_GetTypeName (int);
int OffMeshConnection_GetTypeStatic ();
int OffMeshConnection_GetTypeNameStatic ();
int OffMeshConnection_OffMeshConnection (int);
void OffMeshConnection_RegisterObject (int);
void OffMeshConnection_ApplyAttributes (int);
void OffMeshConnection_DrawDebugGeometry (int,int,int);
void OffMeshConnection_SetEndPoint (int,int);
void OffMeshConnection_SetRadius (int,float);
void OffMeshConnection_SetBidirectional (int,int);
void OffMeshConnection_SetMask (int,int);
void OffMeshConnection_SetAreaID (int,int);
int OffMeshConnection_GetEndPoint (int);
float OffMeshConnection_GetRadius (int);
int OffMeshConnection_IsBidirectional (int);
int OffMeshConnection_GetMask (int);
int OffMeshConnection_GetAreaID (int);
int Image_GetDataBytes (int,int);
int Image_SavePNG2 (int,int);
int Image_GetType (int);
int Image_GetTypeName (int);
int Image_GetTypeStatic ();
int Image_GetTypeNameStatic ();
int Image_Image (int);
void Image_RegisterObject (int);
int Image_BeginLoad_File (int,int);
int Image_BeginLoad_MemoryBuffer (int,int);
int Image_Save_File (int,int);
int Image_Save_MemoryBuffer (int,int);
int Image_SaveFile (int,int);
int Image_SetSize (int,int,int,int);
int Image_SetSize0 (int,int,int,int,int);
void Image_SetData (int,int);
void Image_SetData1 (int,int,int);
void Image_SetPixel (int,int,int,int);
void Image_SetPixel2 (int,int,int,int,int);
void Image_SetPixelInt (int,int,int,int);
void Image_SetPixelInt3 (int,int,int,int,int);
int Image_LoadColorLUT_File (int,int);
int Image_LoadColorLUT_MemoryBuffer (int,int);
int Image_FlipHorizontal (int);
int Image_FlipVertical (int);
int Image_Resize (int,int,int);
void Image_Clear (int,int);
void Image_ClearInt (int,int);
int Image_SaveBMP (int,int);
int Image_SavePNG (int,int);
int Image_SaveTGA (int,int);
int Image_SaveJPG (int,int,int);
int Image_SaveDDS (int,int);
int Image_SaveWEBP (int,int,float);
int Image_IsCubemap (int);
int Image_IsArray (int);
int Image_IsSRGB (int);
int Image_GetPixel (int,int,int);
int Image_GetPixel4 (int,int,int,int);
int Image_GetPixelInt (int,int,int);
int Image_GetPixelInt5 (int,int,int,int);
int Image_GetPixelBilinear (int,float,float);
int Image_GetPixelTrilinear (int,float,float,float);
int Image_GetWidth (int);
int Image_GetHeight (int);
int Image_GetDepth (int);
int Image_GetComponents (int);
int Image_GetData (int);
int Image_IsCompressed (int);
int Image_GetCompressedFormat (int);
int Image_GetNumCompressedLevels (int);
int Image_GetNextLevel (int);
int Image_GetNextSibling (int);
int Image_ConvertToRGBA (int);
int Image_GetCompressedLevel (int,int);
int Image_GetDecompressedImage (int);
int Image_GetSubimage (int,int);
void Image_PrecalculateLevels (int);
int Image_HasAlphaChannel (int);
int Image_SetSubimage (int,int,int);
void Image_CleanupLevels (int);
int ResourceCache_GetFilesInResourceDirs (int,int,int,int);
int ResourceCache_GetFromResultFileInResourceDirs (int,int);
void ResourceCache_ClearVectorResultFilesInResourceDirs (int);
int ResourceCache_GetResourceDirsCount (int);
int ResourceCache_GetResourceDir (int,int);
int ResourceCache_GetType (int);
int ResourceCache_GetTypeName (int);
int ResourceCache_GetTypeStatic ();
int ResourceCache_GetTypeNameStatic ();
int ResourceCache_ResourceCache (int);
int ResourceCache_AddResourceDir (int,int,int);
int ResourceCache_AddPackageFile (int,int,int);
int ResourceCache_AddPackageFile0 (int,int,int);
int ResourceCache_AddManualResource (int,int);
void ResourceCache_RemoveResourceDir (int,int);
void ResourceCache_RemovePackageFile (int,int,int,int);
void ResourceCache_RemovePackageFile1 (int,int,int,int);
void ResourceCache_ReleaseResource (int,int,int,int);
void ResourceCache_ReleaseResources (int,int,int);
void ResourceCache_ReleaseResources2 (int,int,int,int);
void ResourceCache_ReleaseResources3 (int,int,int);
void ResourceCache_ReleaseAllResources (int,int);
int ResourceCache_ReloadResource (int,int);
void ResourceCache_ReloadResourceWithDependencies (int,int);
void ResourceCache_SetMemoryBudget (int,int,uint64_t);
void ResourceCache_SetAutoReloadResources (int,int);
void ResourceCache_SetReturnFailedResources (int,int);
void ResourceCache_SetSearchPackagesFirst (int,int);
void ResourceCache_SetFinishBackgroundResourcesMs (int,int);
void ResourceCache_AddResourceRouter (int,int,int);
void ResourceCache_RemoveResourceRouter (int,int);
int ResourceCache_GetFile (int,int,int);
int ResourceCache_GetResource (int,int,int,int);
int ResourceCache_GetTempResource (int,int,int,int);
int ResourceCache_BackgroundLoadResource (int,int,int,int,int);
int ResourceCache_GetNumBackgroundLoadResources (int);
int ResourceCache_GetExistingResource (int,int,int);
int ResourceCache_GetPackageFiles (int);
int ResourceCache_Exists (int,int);
uint64_t ResourceCache_GetMemoryBudget (int,int);
uint64_t ResourceCache_GetMemoryUse (int,int);
uint64_t ResourceCache_GetTotalMemoryUse (int);
int ResourceCache_GetResourceFileName (int,int);
int ResourceCache_GetAutoReloadResources (int);
int ResourceCache_GetReturnFailedResources (int);
int ResourceCache_GetSearchPackagesFirst (int);
int ResourceCache_GetFinishBackgroundResourcesMs (int);
int ResourceCache_GetResourceRouter (int,int);
int ResourceCache_GetPreferredResourceDir (int,int);
int ResourceCache_SanitateResourceName (int,int);
int ResourceCache_SanitateResourceDirName (int,int);
void ResourceCache_StoreResourceDependency (int,int,int);
void ResourceCache_ResetDependencies (int,int);
int ResourceCache_PrintMemoryUsage (int);
int XmlElement_XMLElement ();
int XmlElement_XMLElement0 (int);
int XmlElement_CreateChild (int,int);
int XmlElement_GetOrCreateChild (int,int);
int XmlElement_AppendChild (int,int,int);
int XmlElement_Remove (int);
int XmlElement_RemoveChild (int,int);
int XmlElement_RemoveChild1 (int,int);
int XmlElement_RemoveChildren (int,int);
int XmlElement_RemoveAttribute (int,int);
int XmlElement_SetValue (int,int);
int XmlElement_SetAttribute (int,int,int);
int XmlElement_SetAttribute2 (int,int);
int XmlElement_SetBool (int,int,int);
int XmlElement_SetBoundingBox (int,int);
int XmlElement_SetBoundingBox3 (int,int,int);
int XmlElement_SetBuffer (int,int,int,int);
int XmlElement_SetColor (int,int,int);
int XmlElement_SetFloat (int,int,float);
int XmlElement_SetDouble (int,int,double);
int XmlElement_SetUInt (int,int,int);
int XmlElement_SetInt (int,int,int);
int XmlElement_SetUInt64 (int,int,uint64_t);
int XmlElement_SetInt64 (int,int,int64_t);
int XmlElement_SetIntRect (int,int,int);
int XmlElement_SetIntVector2 (int,int,int);
int XmlElement_SetQuaternion (int,int,int);
int XmlElement_SetString (int,int,int);
int XmlElement_SetVariant_0 (int,int);
int XmlElement_SetVariant_1 (int,int);
int XmlElement_SetVariant_2 (int,int);
int XmlElement_SetVariant_3 (int,int);
int XmlElement_SetVariant_4 (int,int);
int XmlElement_SetVariant_5 (int,int);
int XmlElement_SetVariant_6 (int,int);
int XmlElement_SetVariant_7 (int,int);
int XmlElement_SetVariant_8 (int,int);
int XmlElement_SetVariant_9 (int,int);
int XmlElement_SetVariant_10 (int,int);
int XmlElement_SetVariant_11 (int,int);
int XmlElement_SetVariant_12 (int,float);
int XmlElement_SetVariant_13 (int,int);
int XmlElement_SetVariant_14 (int,int);
int XmlElement_SetVariantValue_0 (int,int);
int XmlElement_SetVariantValue_1 (int,int);
int XmlElement_SetVariantValue_2 (int,int);
int XmlElement_SetVariantValue_3 (int,int);
int XmlElement_SetVariantValue_4 (int,int);
int XmlElement_SetVariantValue_5 (int,int);
int XmlElement_SetVariantValue_6 (int,int);
int XmlElement_SetVariantValue_7 (int,int);
int XmlElement_SetVariantValue_8 (int,int);
int XmlElement_SetVariantValue_9 (int,int);
int XmlElement_SetVariantValue_10 (int,int);
int XmlElement_SetVariantValue_11 (int,int);
int XmlElement_SetVariantValue_12 (int,float);
int XmlElement_SetVariantValue_13 (int,int);
int XmlElement_SetVariantValue_14 (int,int);
int XmlElement_SetVector2 (int,int,int);
int XmlElement_SetVector3 (int,int,int);
int XmlElement_SetVector4 (int,int,int);
int XmlElement_SetVectorVariant_0 (int,int,int);
int XmlElement_SetVectorVariant_1 (int,int,int);
int XmlElement_SetVectorVariant_2 (int,int,int);
int XmlElement_SetVectorVariant_3 (int,int,int);
int XmlElement_SetVectorVariant_4 (int,int,int);
int XmlElement_SetVectorVariant_5 (int,int,int);
int XmlElement_SetVectorVariant_6 (int,int,int);
int XmlElement_SetVectorVariant_7 (int,int,int);
int XmlElement_SetVectorVariant_8 (int,int,int);
int XmlElement_SetVectorVariant_9 (int,int,int);
int XmlElement_SetVectorVariant_10 (int,int,int);
int XmlElement_SetVectorVariant_11 (int,int,int);
int XmlElement_SetVectorVariant_12 (int,int,float);
int XmlElement_SetVectorVariant_13 (int,int,int);
int XmlElement_SetVectorVariant_14 (int,int,int);
int XmlElement_SetMatrix3 (int,int,int);
int XmlElement_SetMatrix3x4 (int,int,int);
int XmlElement_SetMatrix4 (int,int,int);
int XmlElement_IsNull (int);
int XmlElement_NotNull (int);
int XmlElement_GetName (int);
int XmlElement_HasChild (int,int);
int XmlElement_GetChild (int,int);
int XmlElement_GetNext (int,int);
int XmlElement_GetParent (int);
int XmlElement_GetNumAttributes (int);
int XmlElement_HasAttribute (int,int);
int XmlElement_GetValue (int);
int XmlElement_GetAttribute (int,int);
int XmlElement_GetAttributeLower (int,int);
int XmlElement_GetAttributeUpper (int,int);
int XmlElement_GetBool (int,int);
int XmlElement_GetBuffer (int,int,int,int);
int XmlElement_GetBoundingBox (int);
int XmlElement_GetBoundingBox4 (int,int);
int XmlElement_GetColor (int,int);
float XmlElement_GetFloat (int,int);
double XmlElement_GetDouble (int,int);
int XmlElement_GetUInt (int,int);
int XmlElement_GetInt (int,int);
uint64_t XmlElement_GetUInt64 (int,int);
int64_t XmlElement_GetInt64 (int,int);
int XmlElement_GetIntRect (int,int);
int XmlElement_GetIntVector2 (int,int);
int XmlElement_GetIntVector3 (int,int);
int XmlElement_GetRect (int,int);
int XmlElement_GetQuaternion (int,int);
int XmlElement_GetVariant (int);
int XmlElement_GetVariantValue (int,int);
int XmlElement_GetResourceRef (int);
int XmlElement_GetResourceRefList (int);
int XmlElement_GetVector2 (int,int);
int XmlElement_GetVector3 (int,int);
int XmlElement_GetVector4 (int,int);
int XmlElement_GetVector (int,int);
int XmlElement_GetVectorVariant (int,int);
int XmlElement_GetMatrix3 (int,int);
int XmlElement_GetMatrix3x4 (int,int);
int XmlElement_GetMatrix4 (int,int);
int XmlElement_GetFile (int);
int XmlElement_GetXPathResultSet (int);
int XmlElement_GetXPathResultIndex (int);
int XmlElement_NextResult (int);
int JsonFile_GetType (int);
int JsonFile_GetTypeName (int);
int JsonFile_GetTypeStatic ();
int JsonFile_GetTypeNameStatic ();
int JsonFile_JSONFile (int);
void JsonFile_RegisterObject (int);
int JsonFile_BeginLoad_File (int,int);
int JsonFile_BeginLoad_MemoryBuffer (int,int);
int JsonFile_Save_File (int,int);
int JsonFile_Save_MemoryBuffer (int,int);
int JsonFile_Save0_File (int,int,int);
int JsonFile_Save0_MemoryBuffer (int,int,int);
int JsonFile_FromString (int,int);
int JsonFile_ToString (int,int);
int JsonFile_GetString (int,int);
int JsonFile_GetInt (int,int);
int JsonFile_GetUInt (int,int);
float JsonFile_GetFloat (int,int);
double JsonFile_GetDouble (int,int);
int JsonFile_GetBool (int,int);
void JsonFile_SetString (int,int,int);
void JsonFile_SetInt (int,int,int);
void JsonFile_SetUInt (int,int,int);
void JsonFile_SetFloat (int,int,float);
void JsonFile_SetDouble (int,int,double);
void JsonFile_SetBool (int,int,int);
int Localization_GetType (int);
int Localization_GetTypeName (int);
int Localization_GetTypeStatic ();
int Localization_GetTypeNameStatic ();
int Localization_Localization (int);
int Localization_GetNumLanguages (int);
int Localization_GetLanguageIndex (int);
int Localization_GetLanguageIndex0 (int,int);
int Localization_GetLanguage (int);
int Localization_GetLanguage1 (int,int);
void Localization_SetLanguage (int,int);
void Localization_SetLanguage2 (int,int);
int Localization_Get (int,int);
void Localization_Reset (int);
void Localization_LoadJSONFile (int,int,int);
int Resource_GetType (int);
int Resource_GetTypeName (int);
int Resource_GetTypeStatic ();
int Resource_GetTypeNameStatic ();
int Resource_Resource (int);
int Resource_Load_File (int,int);
int Resource_Load_MemoryBuffer (int,int);
int Resource_BeginLoad_File (int,int);
int Resource_BeginLoad_MemoryBuffer (int,int);
int Resource_EndLoad (int);
int Resource_Save_File (int,int);
int Resource_Save_MemoryBuffer (int,int);
int Resource_LoadFile (int,int);
int Resource_SaveFile (int,int);
void Resource_SetName (int,int);
void Resource_SetMemoryUse (int,int);
void Resource_ResetUseTimer (int);
void Resource_SetAsyncLoadState (int,int);
int Resource_GetName (int);
int Resource_GetNameHash (int);
int Resource_GetMemoryUse (int);
int Resource_GetUseTimer (int);
int Resource_GetAsyncLoadState (int);
int PListFile_GetType (int);
int PListFile_GetTypeName (int);
int PListFile_GetTypeStatic ();
int PListFile_GetTypeNameStatic ();
int PListFile_PListFile (int);
void PListFile_RegisterObject (int);
int PListFile_BeginLoad_File (int,int);
int PListFile_BeginLoad_MemoryBuffer (int,int);
int XmlFile_GetType (int);
int XmlFile_GetTypeName (int);
int XmlFile_GetTypeStatic ();
int XmlFile_GetTypeNameStatic ();
int XmlFile_XMLFile (int);
void XmlFile_RegisterObject (int);
int XmlFile_BeginLoad_File (int,int);
int XmlFile_BeginLoad_MemoryBuffer (int,int);
int XmlFile_Save_File (int,int);
int XmlFile_Save_MemoryBuffer (int,int);
int XmlFile_Save0_File (int,int,int);
int XmlFile_Save0_MemoryBuffer (int,int,int);
int XmlFile_FromString (int,int);
int XmlFile_CreateRoot (int,int);
int XmlFile_GetOrCreateRoot (int,int);
int XmlFile_GetRoot (int,int);
int XmlFile_ToString (int,int);
void XmlFile_Patch (int,int);
void XmlFile_Patch1 (int,int);
void FileSelector_SetFilters (int,int,int);
int FileSelector_GetType (int);
int FileSelector_GetTypeName (int);
int FileSelector_GetTypeStatic ();
int FileSelector_GetTypeNameStatic ();
int FileSelector_FileSelector (int);
void FileSelector_RegisterObject (int);
void FileSelector_SetDefaultStyle (int,int);
void FileSelector_SetTitle (int,int);
void FileSelector_SetButtonTexts (int,int,int);
void FileSelector_SetPath (int,int);
void FileSelector_SetFileName (int,int);
void FileSelector_SetDirectoryMode (int,int);
void FileSelector_UpdateElements (int);
int FileSelector_GetDefaultStyle (int);
int FileSelector_GetWindow (int);
int FileSelector_GetTitleText (int);
int FileSelector_GetFileList (int);
int FileSelector_GetPathEdit (int);
int FileSelector_GetFileNameEdit (int);
int FileSelector_GetFilterList (int);
int FileSelector_GetOKButton (int);
int FileSelector_GetCancelButton (int);
int FileSelector_GetCloseButton (int);
int FileSelector_GetTitle (int);
int FileSelector_GetPath (int);
int FileSelector_GetFileName (int);
int FileSelector_GetFilter (int);
int FileSelector_GetFilterIndex (int);
int FileSelector_GetDirectoryMode (int);
int ListView_GetSelections (int);
void ListView_SetSelections (int,int,int);
int ListView_GetType (int);
int ListView_GetTypeName (int);
int ListView_GetTypeStatic ();
int ListView_GetTypeNameStatic ();
int ListView_ListView (int);
void ListView_RegisterObject (int);
void ListView_OnResize (int,int,int);
void ListView_UpdateInternalLayout (int);
void ListView_DisableInternalLayoutUpdate (int);
void ListView_EnableInternalLayoutUpdate (int);
int ListView_AddItem (int,int);
int ListView_InsertItem (int,int,int,int);
void ListView_RemoveItem (int,int,int);
void ListView_RemoveItem0 (int,int);
void ListView_RemoveAllItems (int);
void ListView_SetSelection (int,int);
void ListView_AddSelection (int,int);
void ListView_RemoveSelection (int,int);
void ListView_ToggleSelection (int,int);
void ListView_ChangeSelection (int,int,int);
void ListView_ClearSelection (int);
void ListView_SetHighlightMode (int,int);
void ListView_SetMultiselect (int,int);
void ListView_SetHierarchyMode (int,int);
void ListView_SetBaseIndent (int,int);
void ListView_SetClearSelectionOnDefocus (int,int);
void ListView_SetSelectOnClickEnd (int,int);
void ListView_Expand (int,int,int,int);
void ListView_ToggleExpand (int,int,int);
int ListView_GetNumItems (int);
int ListView_GetItem (int,int);
int ListView_FindItem (int,int);
int ListView_GetSelection (int);
void ListView_CopySelectedItemsToClipboard (int);
int ListView_GetSelectedItem (int);
int ListView_IsSelected (int,int);
int ListView_IsExpanded (int,int);
int ListView_GetHighlightMode (int);
int ListView_GetMultiselect (int);
int ListView_GetClearSelectionOnDefocus (int);
int ListView_GetSelectOnClickEnd (int);
int ListView_GetHierarchyMode (int);
int ListView_GetBaseIndent (int);
void ListView_EnsureItemVisibility (int,int);
void ListView_EnsureItemVisibility1 (int,int);
int ListView_GetEnsureItemVisibilityOnFcousChanged (int);
void ListView_SetEnsureItemVisibilityOnFcousChanged (int,int);
void UI_LoadLayoutToElement (int,int,int,int);
int UI_GetType (int);
int UI_GetTypeName (int);
int UI_GetTypeStatic ();
int UI_GetTypeNameStatic ();
int UI_UI (int);
void UI_SetCursor (int,int);
void UI_SetFocusElement (int,int,int);
int UI_SetModalElement (int,int,int);
void UI_Clear (int);
void UI_Update (int,float);
void UI_RenderUpdate (int);
void UI_Render (int,int);
void UI_DebugDraw (int,int);
int UI_LoadLayout_File (int,int,int);
int UI_LoadLayout_MemoryBuffer (int,int,int);
int UI_LoadLayout0 (int,int,int);
int UI_SaveLayout_File (int,int,int);
int UI_SaveLayout_MemoryBuffer (int,int,int);
void UI_SetClipboardText (int,int);
void UI_SetDoubleClickInterval (int,float);
void UI_SetMaxDoubleClickDistance (int,float);
void UI_SetDragBeginInterval (int,float);
void UI_SetDragBeginDistance (int,int);
void UI_SetDefaultToolTipDelay (int,float);
void UI_SetMaxFontTextureSize (int,int);
void UI_SetNonFocusedMouseWheel (int,int);
void UI_SetUseSystemClipboard (int,int);
void UI_SetUseScreenKeyboard (int,int);
void UI_SetUseMutableGlyphs (int,int);
void UI_SetForceAutoHint (int,int);
void UI_SetFontHintLevel (int,int);
void UI_SetFontSubpixelThreshold (int,float);
void UI_SetFontOversampling (int,int);
void UI_SetScale (int,float);
void UI_SetWidth (int,float);
void UI_SetHeight (int,float);
void UI_SetCustomSize (int,int);
void UI_SetCustomSize1 (int,int,int);
int UI_GetRoot (int);
int UI_GetRootModalElement (int);
int UI_GetCursor (int);
int UI_GetCursorPosition (int);
int UI_GetElementAt (int,int,int);
int UI_GetElementAt2 (int,int,int,int);
int UI_GetElementAt3 (int,int,int,int);
int UI_ConvertSystemToUI (int,int);
int UI_ConvertUIToSystem (int,int);
int UI_GetFocusElement (int);
int UI_GetFrontElement (int);
int UI_GetNumDragElements (int);
int UI_GetDragElement (int,int);
int UI_GetClipboardText (int);
float UI_GetDoubleClickInterval (int);
float UI_GetMaxDoubleClickDistance (int);
float UI_GetDragBeginInterval (int);
int UI_GetDragBeginDistance (int);
float UI_GetDefaultToolTipDelay (int);
int UI_GetMaxFontTextureSize (int);
int UI_IsNonFocusedMouseWheel (int);
int UI_GetUseSystemClipboard (int);
int UI_GetUseScreenKeyboard (int);
int UI_GetUseMutableGlyphs (int);
int UI_GetForceAutoHint (int);
int UI_GetFontHintLevel (int);
float UI_GetFontSubpixelThreshold (int);
int UI_GetFontOversampling (int);
int UI_HasModalElement (int);
int UI_IsDragging (int);
float UI_GetScale (int);
int UI_GetCustomSize (int);
void UI_SetElementRenderTexture (int,int,int);
void UIElement_SetVar_IntPtr (int,int,int);
int UIElement_GetTags (int);
int UIElement_GetVars (int);
int UIElement_GetType (int);
int UIElement_GetTypeName (int);
int UIElement_GetTypeStatic ();
int UIElement_GetTypeNameStatic ();
int UIElement_UIElement (int);
void UIElement_RegisterObject (int);
void UIElement_ApplyAttributes (int);
int UIElement_LoadXML (int,int);
int UIElement_LoadXML0 (int,int,int);
int UIElement_LoadChildXML (int,int,int);
int UIElement_SaveXML (int,int);
void UIElement_Update (int,float);
int UIElement_IsWithinScissor (int,int);
int UIElement_GetScreenPosition (int);
void UIElement_OnTextInput (int,int);
void UIElement_OnResize (int,int,int);
void UIElement_OnPositionSet (int,int);
void UIElement_OnSetEditable (int);
void UIElement_OnIndentSet (int);
int UIElement_ScreenToElement (int,int);
int UIElement_ElementToScreen (int,int);
int UIElement_IsWheelHandler (int);
int UIElement_LoadXML1_File (int,int);
int UIElement_LoadXML1_MemoryBuffer (int,int);
int UIElement_SaveXML2_File (int,int,int);
int UIElement_SaveXML2_MemoryBuffer (int,int,int);
int UIElement_FilterAttributes (int,int);
void UIElement_SetName (int,int);
void UIElement_SetPosition (int,int);
void UIElement_SetPosition3 (int,int,int);
void UIElement_SetSize (int,int);
void UIElement_SetSize4 (int,int,int);
void UIElement_SetWidth (int,int);
void UIElement_SetHeight (int,int);
void UIElement_SetMinSize (int,int);
void UIElement_SetMinSize5 (int,int,int);
void UIElement_SetMinWidth (int,int);
void UIElement_SetMinHeight (int,int);
void UIElement_SetMaxSize (int,int);
void UIElement_SetMaxSize6 (int,int,int);
void UIElement_SetMaxWidth (int,int);
void UIElement_SetMaxHeight (int,int);
void UIElement_SetFixedSize (int,int);
void UIElement_SetFixedSize7 (int,int,int);
void UIElement_SetFixedWidth (int,int);
void UIElement_SetFixedHeight (int,int);
void UIElement_SetAlignment (int,int,int);
void UIElement_SetHorizontalAlignment (int,int);
void UIElement_SetVerticalAlignment (int,int);
void UIElement_SetEnableAnchor (int,int);
void UIElement_SetMinAnchor (int,int);
void UIElement_SetMinAnchor8 (int,float,float);
void UIElement_SetMaxAnchor (int,int);
void UIElement_SetMaxAnchor9 (int,float,float);
void UIElement_SetMinOffset (int,int);
void UIElement_SetMaxOffset (int,int);
void UIElement_SetPivot (int,int);
void UIElement_SetPivot10 (int,float,float);
void UIElement_SetClipBorder (int,int);
void UIElement_SetColor (int,int);
void UIElement_SetColor11 (int,int,int);
void UIElement_SetPriority (int,int);
void UIElement_SetOpacity (int,float);
void UIElement_SetBringToFront (int,int);
void UIElement_SetBringToBack (int,int);
void UIElement_SetClipChildren (int,int);
void UIElement_SetSortChildren (int,int);
void UIElement_SetUseDerivedOpacity (int,int);
void UIElement_SetEnabled (int,int);
void UIElement_SetDeepEnabled (int,int);
void UIElement_ResetDeepEnabled (int);
void UIElement_SetEnabledRecursive (int,int);
void UIElement_SetEditable (int,int);
void UIElement_SetFocus (int,int);
void UIElement_SetSelected (int,int);
void UIElement_SetVisible (int,int);
void UIElement_SetFocusMode (int,int);
void UIElement_SetDragDropMode (int,int);
int UIElement_SetStyle (int,int,int);
int UIElement_SetStyle12 (int,int);
int UIElement_SetStyleAuto (int,int);
void UIElement_SetDefaultStyle (int,int);
void UIElement_SetLayout (int,int,int,int);
void UIElement_SetLayoutMode (int,int);
void UIElement_SetLayoutSpacing (int,int);
void UIElement_SetLayoutBorder (int,int);
void UIElement_SetLayoutFlexScale (int,int);
void UIElement_SetIndent (int,int);
void UIElement_SetIndentSpacing (int,int);
void UIElement_UpdateLayout (int);
void UIElement_DisableLayoutUpdate (int);
void UIElement_EnableLayoutUpdate (int);
void UIElement_BringToFront (int);
int UIElement_CreateChild (int,int,int,int);
void UIElement_AddChild (int,int);
void UIElement_InsertChild (int,int,int);
void UIElement_RemoveChild (int,int,int);
void UIElement_RemoveChildAtIndex (int,int);
void UIElement_RemoveAllChildren (int);
void UIElement_Remove (int);
int UIElement_FindChild (int,int);
void UIElement_SetParent (int,int,int);
void UIElement_SetVar_0 (int,int,int);
void UIElement_SetVar_1 (int,int,int);
void UIElement_SetVar_2 (int,int,int);
void UIElement_SetVar_3 (int,int,int);
void UIElement_SetVar_4 (int,int,int);
void UIElement_SetVar_5 (int,int,int);
void UIElement_SetVar_6 (int,int,int);
void UIElement_SetVar_7 (int,int,int);
void UIElement_SetVar_8 (int,int,int);
void UIElement_SetVar_9 (int,int,int);
void UIElement_SetVar_10 (int,int,int);
void UIElement_SetVar_11 (int,int,int);
void UIElement_SetVar_12 (int,int,float);
void UIElement_SetVar_13 (int,int,int);
void UIElement_SetVar_14 (int,int,int);
void UIElement_SetVar13_0 (int,int,int);
void UIElement_SetVar13_1 (int,int,int);
void UIElement_SetVar13_2 (int,int,int);
void UIElement_SetVar13_3 (int,int,int);
void UIElement_SetVar13_4 (int,int,int);
void UIElement_SetVar13_5 (int,int,int);
void UIElement_SetVar13_6 (int,int,int);
void UIElement_SetVar13_7 (int,int,int);
void UIElement_SetVar13_8 (int,int,int);
void UIElement_SetVar13_9 (int,int,int);
void UIElement_SetVar13_10 (int,int,int);
void UIElement_SetVar13_11 (int,int,int);
void UIElement_SetVar13_12 (int,int,float);
void UIElement_SetVar13_13 (int,int,int);
void UIElement_SetVar13_14 (int,int,int);
void UIElement_SetInternal (int,int);
void UIElement_SetTraversalMode (int,int);
void UIElement_SetElementEventSender (int,int);
void UIElement_AddTag (int,int);
int UIElement_RemoveTag (int,int);
void UIElement_RemoveAllTags (int);
int UIElement_GetName (int);
int UIElement_GetPosition (int);
int UIElement_GetSize (int);
int UIElement_GetWidth (int);
int UIElement_GetHeight (int);
int UIElement_GetMinSize (int);
int UIElement_GetMinWidth (int);
int UIElement_GetMinHeight (int);
int UIElement_GetMaxSize (int);
int UIElement_GetMaxWidth (int);
int UIElement_GetMaxHeight (int);
int UIElement_IsFixedSize (int);
int UIElement_IsFixedWidth (int);
int UIElement_IsFixedHeight (int);
int UIElement_GetChildOffset (int);
int UIElement_GetHorizontalAlignment (int);
int UIElement_GetVerticalAlignment (int);
int UIElement_GetEnableAnchor (int);
int UIElement_GetMinAnchor (int);
int UIElement_GetMaxAnchor (int);
int UIElement_GetMinOffset (int);
int UIElement_GetMaxOffset (int);
int UIElement_GetPivot (int);
int UIElement_GetClipBorder (int);
int UIElement_GetColor (int,int);
int UIElement_GetPriority (int);
float UIElement_GetOpacity (int);
float UIElement_GetDerivedOpacity (int);
int UIElement_GetBringToFront (int);
int UIElement_GetBringToBack (int);
int UIElement_GetClipChildren (int);
int UIElement_GetSortChildren (int);
int UIElement_GetUseDerivedOpacity (int);
int UIElement_HasFocus (int);
int UIElement_IsChildOf (int,int);
int UIElement_IsEnabled (int);
int UIElement_IsEnabledSelf (int);
int UIElement_IsEditable (int);
int UIElement_IsSelected (int);
int UIElement_IsVisible (int);
int UIElement_IsVisibleEffective (int);
int UIElement_IsHovering (int);
int UIElement_IsInternal (int);
int UIElement_HasColorGradient (int);
int UIElement_GetFocusMode (int);
int UIElement_GetDragDropMode (int);
int UIElement_GetAppliedStyle (int);
int UIElement_GetDefaultStyle (int,int);
int UIElement_GetLayoutMode (int);
int UIElement_GetLayoutSpacing (int);
int UIElement_GetLayoutBorder (int);
int UIElement_GetLayoutFlexScale (int);
int UIElement_GetNumChildren (int,int);
int UIElement_GetChild (int,int);
int UIElement_GetChild14 (int,int,int);
int UIElement_GetChildren (int);
int UIElement_GetParent (int);
int UIElement_GetRoot (int);
int UIElement_GetDerivedColor (int);
int UIElement_GetVar (int,int);
int UIElement_GetVar15 (int,int);
int UIElement_HasTag (int,int);
int UIElement_GetDragButtonCount (int);
int UIElement_IsInside (int,int,int);
int UIElement_IsInsideCombined (int,int,int);
int UIElement_GetCombinedScreenRect (int);
void UIElement_SortChildren (int);
int UIElement_GetLayoutElementMaxSize (int);
int UIElement_GetIndent (int);
int UIElement_GetIndentSpacing (int);
int UIElement_GetIndentWidth (int);
void UIElement_SetChildOffset (int,int);
void UIElement_SetHovering (int,int);
int UIElement_GetColorAttr (int);
int UIElement_GetTraversalMode (int);
int UIElement_IsElementEventSender (int);
int UIElement_GetElementEventSender (int);
int UIElement_GetEffectiveMinSize (int);
void UIElement_SetRenderTexture (int,int);
int BorderImage_GetType (int);
int BorderImage_GetTypeName (int);
int BorderImage_GetTypeStatic ();
int BorderImage_GetTypeNameStatic ();
int BorderImage_BorderImage (int);
void BorderImage_RegisterObject (int);
void BorderImage_SetTexture (int,int);
void BorderImage_SetImageRect (int,int);
void BorderImage_SetFullImageRect (int);
void BorderImage_SetBorder (int,int);
void BorderImage_SetImageBorder (int,int);
void BorderImage_SetHoverOffset (int,int);
void BorderImage_SetHoverOffset0 (int,int,int);
void BorderImage_SetDisabledOffset (int,int);
void BorderImage_SetDisabledOffset1 (int,int,int);
void BorderImage_SetBlendMode (int,int);
void BorderImage_SetTiled (int,int);
void BorderImage_SetMaterial (int,int);
int BorderImage_GetTexture (int);
int BorderImage_GetImageRect (int);
int BorderImage_GetBorder (int);
int BorderImage_GetImageBorder (int);
int BorderImage_GetHoverOffset (int);
int BorderImage_GetDisabledOffset (int);
int BorderImage_GetBlendMode (int);
int BorderImage_IsTiled (int);
int BorderImage_GetMaterial (int);
int BorderImage_GetTextureAttr (int);
int BorderImage_GetMaterialAttr (int);
int Button_GetType (int);
int Button_GetTypeName (int);
int Button_GetTypeStatic ();
int Button_GetTypeNameStatic ();
int Button_Button (int);
void Button_RegisterObject (int);
void Button_Update (int,float);
void Button_SetPressedOffset (int,int);
void Button_SetPressedOffset0 (int,int,int);
void Button_SetPressedChildOffset (int,int);
void Button_SetPressedChildOffset1 (int,int,int);
void Button_SetRepeat (int,float,float);
void Button_SetRepeatDelay (int,float);
void Button_SetRepeatRate (int,float);
int Button_GetPressedOffset (int);
int Button_GetPressedChildOffset (int);
float Button_GetRepeatDelay (int);
float Button_GetRepeatRate (int);
int Button_IsPressed (int);
int CheckBox_GetType (int);
int CheckBox_GetTypeName (int);
int CheckBox_GetTypeStatic ();
int CheckBox_GetTypeNameStatic ();
int CheckBox_CheckBox (int);
void CheckBox_RegisterObject (int);
void CheckBox_SetChecked (int,int);
void CheckBox_SetCheckedOffset (int,int);
void CheckBox_SetCheckedOffset0 (int,int,int);
int CheckBox_IsChecked (int);
int CheckBox_GetCheckedOffset (int);
int Cursor_GetType (int);
int Cursor_GetTypeName (int);
int Cursor_GetTypeStatic ();
int Cursor_GetTypeNameStatic ();
int Cursor_Cursor (int);
void Cursor_RegisterObject (int);
void Cursor_DefineShape (int,int,int,int,int);
void Cursor_DefineShape0 (int,int,int,int,int);
void Cursor_SetShape (int,int);
void Cursor_SetShape1 (int,int);
void Cursor_SetUseSystemShapes (int,int);
int Cursor_GetShape (int);
int Cursor_GetUseSystemShapes (int);
void Cursor_ApplyOSCursorShape (int);
int DropDownList_GetType (int);
int DropDownList_GetTypeName (int);
int DropDownList_GetTypeStatic ();
int DropDownList_GetTypeNameStatic ();
int DropDownList_DropDownList (int);
void DropDownList_RegisterObject (int);
void DropDownList_ApplyAttributes (int);
void DropDownList_OnShowPopup (int);
void DropDownList_OnHidePopup (int);
void DropDownList_OnSetEditable (int);
void DropDownList_AddItem (int,int);
void DropDownList_InsertItem (int,int,int);
void DropDownList_RemoveItem (int,int);
void DropDownList_RemoveItem0 (int,int);
void DropDownList_RemoveAllItems (int);
void DropDownList_SetSelection (int,int);
void DropDownList_SetPlaceholderText (int,int);
void DropDownList_SetResizePopup (int,int);
int DropDownList_GetNumItems (int);
int DropDownList_GetItem (int,int);
int DropDownList_GetSelection (int);
int DropDownList_GetSelectedItem (int);
int DropDownList_GetListView (int);
int DropDownList_GetPlaceholder (int);
int DropDownList_GetPlaceholderText (int);
int DropDownList_GetResizePopup (int);
void DropDownList_SetSelectionAttr (int,int);
int Font_GetType (int);
int Font_GetTypeName (int);
int Font_GetTypeStatic ();
int Font_GetTypeNameStatic ();
int Font_Font (int);
void Font_RegisterObject (int);
int Font_BeginLoad_File (int,int);
int Font_BeginLoad_MemoryBuffer (int,int);
int Font_SaveXML_File (int,int,int,int,int);
int Font_SaveXML_MemoryBuffer (int,int,int,int,int);
void Font_SetAbsoluteGlyphOffset (int,int);
void Font_SetScaledGlyphOffset (int,int);
int Font_GetFace (int,float);
int Font_GetFontType (int);
int Font_IsSDFFont (int);
int Font_GetAbsoluteGlyphOffset (int);
int Font_GetScaledGlyphOffset (int);
int Font_GetTotalGlyphOffset (int,float);
void Font_ReleaseFaces (int);
int FontFace_Load (int,int,int,float);
int FontFace_GetGlyph (int,int);
int FontFace_HasMutableGlyphs (int);
float FontFace_GetKerning (int,int,int);
int FontFace_IsDataLost (int);
float FontFace_GetPointSize (int);
float FontFace_GetRowHeight (int);
int FontFace_GetTextures (int);
int FontFaceBitmap_FontFaceBitmap (int);
int FontFaceBitmap_Load (int,int,int,float);
int FontFaceBitmap_Load0 (int,int,int);
int FontFaceBitmap_Save_File (int,int,int,int);
int FontFaceBitmap_Save_MemoryBuffer (int,int,int,int);
int FontFaceFreeType_FontFaceFreeType (int);
int FontFaceFreeType_Load (int,int,int,float);
int FontFaceFreeType_GetGlyph (int,int);
int FontFaceFreeType_HasMutableGlyphs (int);
int LineEdit_GetType (int);
int LineEdit_GetTypeName (int);
int LineEdit_GetTypeStatic ();
int LineEdit_GetTypeNameStatic ();
int LineEdit_LineEdit (int);
void LineEdit_RegisterObject (int);
void LineEdit_ApplyAttributes (int);
void LineEdit_Update (int,float);
void LineEdit_OnTextInput (int,int);
void LineEdit_SetText (int,int);
void LineEdit_SetCursorPosition (int,int);
void LineEdit_SetCursorBlinkRate (int,float);
void LineEdit_SetMaxLength (int,int);
void LineEdit_SetEchoCharacter (int,int);
void LineEdit_SetCursorMovable (int,int);
void LineEdit_SetTextSelectable (int,int);
void LineEdit_SetTextCopyable (int,int);
int LineEdit_GetText (int);
int LineEdit_GetCursorPosition (int);
float LineEdit_GetCursorBlinkRate (int);
int LineEdit_GetMaxLength (int);
int LineEdit_GetEchoCharacter (int);
int LineEdit_IsCursorMovable (int);
int LineEdit_IsTextSelectable (int);
int LineEdit_IsTextCopyable (int);
int LineEdit_GetTextElement (int);
int LineEdit_GetCursor (int);
int Menu_GetType (int);
int Menu_GetTypeName (int);
int Menu_GetTypeStatic ();
int Menu_GetTypeNameStatic ();
int Menu_Menu (int);
void Menu_RegisterObject (int);
int Menu_LoadXML (int,int,int);
int Menu_SaveXML (int,int);
void Menu_Update (int,float);
void Menu_OnShowPopup (int);
void Menu_OnHidePopup (int);
void Menu_SetPopup (int,int);
void Menu_SetPopupOffset (int,int);
void Menu_SetPopupOffset0 (int,int,int);
void Menu_ShowPopup (int,int);
void Menu_SetAccelerator (int,int,int);
int Menu_GetPopup (int);
int Menu_GetPopupOffset (int);
int Menu_GetShowPopup (int);
int Menu_GetAcceleratorKey (int);
int Menu_GetAcceleratorQualifiers (int);
int MessageBox_GetType (int);
int MessageBox_GetTypeName (int);
int MessageBox_GetTypeStatic ();
int MessageBox_GetTypeNameStatic ();
int MessageBox_MessageBox (int,int,int,int,int);
void MessageBox_RegisterObject (int);
void MessageBox_SetTitle (int,int);
void MessageBox_SetMessage (int,int);
int MessageBox_GetTitle (int);
int MessageBox_GetMessage (int);
int MessageBox_GetWindow (int);
int Slider_GetType (int);
int Slider_GetTypeName (int);
int Slider_GetTypeStatic ();
int Slider_GetTypeNameStatic ();
int Slider_Slider (int);
void Slider_RegisterObject (int);
void Slider_Update (int,float);
void Slider_OnResize (int,int,int);
void Slider_SetOrientation (int,int);
void Slider_SetRange (int,float);
void Slider_SetValue (int,float);
void Slider_ChangeValue (int,float);
void Slider_SetRepeatRate (int,float);
int Slider_GetOrientation (int);
float Slider_GetRange (int);
float Slider_GetValue (int);
int Slider_GetKnob (int);
float Slider_GetRepeatRate (int);
int ScrollBar_GetType (int);
int ScrollBar_GetTypeName (int);
int ScrollBar_GetTypeStatic ();
int ScrollBar_GetTypeNameStatic ();
int ScrollBar_ScrollBar (int);
void ScrollBar_RegisterObject (int);
void ScrollBar_ApplyAttributes (int);
void ScrollBar_OnResize (int,int,int);
void ScrollBar_OnSetEditable (int);
void ScrollBar_SetOrientation (int,int);
void ScrollBar_SetRange (int,float);
void ScrollBar_SetValue (int,float);
void ScrollBar_ChangeValue (int,float);
void ScrollBar_SetScrollStep (int,float);
void ScrollBar_SetStepFactor (int,float);
void ScrollBar_StepBack (int);
void ScrollBar_StepForward (int);
int ScrollBar_GetOrientation (int);
float ScrollBar_GetRange (int);
float ScrollBar_GetValue (int);
float ScrollBar_GetScrollStep (int);
float ScrollBar_GetStepFactor (int);
float ScrollBar_GetEffectiveScrollStep (int);
int ScrollBar_GetBackButton (int);
int ScrollBar_GetForwardButton (int);
int ScrollBar_GetSlider (int);
int ScrollView_GetType (int);
int ScrollView_GetTypeName (int);
int ScrollView_GetTypeStatic ();
int ScrollView_GetTypeNameStatic ();
int ScrollView_ScrollView (int);
void ScrollView_RegisterObject (int);
void ScrollView_Update (int,float);
void ScrollView_ApplyAttributes (int);
void ScrollView_OnResize (int,int,int);
int ScrollView_IsWheelHandler (int);
void ScrollView_SetContentElement (int,int);
void ScrollView_SetViewPosition (int,int);
void ScrollView_SetViewPosition0 (int,int,int);
void ScrollView_SetScrollBarsVisible (int,int,int);
void ScrollView_SetHorizontalScrollBarVisible (int,int);
void ScrollView_SetVerticalScrollBarVisible (int,int);
void ScrollView_SetScrollBarsAutoVisible (int,int);
void ScrollView_SetScrollStep (int,float);
void ScrollView_SetPageStep (int,float);
void ScrollView_SetScrollDeceleration (int,float);
void ScrollView_SetScrollSnapEpsilon (int,float);
void ScrollView_SetAutoDisableChildren (int,int);
void ScrollView_SetAutoDisableThreshold (int,float);
int ScrollView_GetViewPosition (int);
int ScrollView_GetContentElement (int);
int ScrollView_GetHorizontalScrollBar (int);
int ScrollView_GetVerticalScrollBar (int);
int ScrollView_GetScrollPanel (int);
int ScrollView_GetScrollBarsAutoVisible (int);
int ScrollView_GetHorizontalScrollBarVisible (int);
int ScrollView_GetVerticalScrollBarVisible (int);
float ScrollView_GetScrollStep (int);
float ScrollView_GetPageStep (int);
float ScrollView_GetScrollDeceleration (int);
float ScrollView_GetScrollSnapEpsilon (int);
int ScrollView_GetAutoDisableChildren (int);
float ScrollView_GetAutoDisableThreshold (int);
void ScrollView_SetViewPositionAttr (int,int);
int Window_GetType (int);
int Window_GetTypeName (int);
int Window_GetTypeStatic ();
int Window_GetTypeNameStatic ();
int Window_Window (int);
void Window_RegisterObject (int);
void Window_SetMovable (int,int);
void Window_SetResizable (int,int);
void Window_SetFixedWidthResizing (int,int);
void Window_SetFixedHeightResizing (int,int);
void Window_SetResizeBorder (int,int);
void Window_SetModal (int,int);
void Window_SetModalShadeColor (int,int);
void Window_SetModalFrameColor (int,int);
void Window_SetModalFrameSize (int,int);
void Window_SetModalAutoDismiss (int,int);
int Window_IsMovable (int);
int Window_IsResizable (int);
int Window_GetFixedWidthResizing (int);
int Window_GetFixedHeightResizing (int);
int Window_GetResizeBorder (int);
int Window_IsModal (int);
int Window_GetModalShadeColor (int);
int Window_GetModalFrameColor (int);
int Window_GetModalFrameSize (int);
int Window_GetModalAutoDismiss (int);
int Sprite_GetType (int);
int Sprite_GetTypeName (int);
int Sprite_GetTypeStatic ();
int Sprite_GetTypeNameStatic ();
int Sprite_Sprite (int);
void Sprite_RegisterObject (int);
int Sprite_IsWithinScissor (int,int);
int Sprite_GetScreenPosition (int);
void Sprite_OnPositionSet (int,int);
int Sprite_ScreenToElement (int,int);
int Sprite_ElementToScreen (int,int);
void Sprite_SetPosition (int,int);
void Sprite_SetPosition0 (int,float,float);
void Sprite_SetHotSpot (int,int);
void Sprite_SetHotSpot1 (int,int,int);
void Sprite_SetScale (int,int);
void Sprite_SetScale2 (int,float,float);
void Sprite_SetScale3 (int,float);
void Sprite_SetRotation (int,float);
void Sprite_SetTexture (int,int);
void Sprite_SetImageRect (int,int);
void Sprite_SetFullImageRect (int);
void Sprite_SetBlendMode (int,int);
int Sprite_GetPosition (int);
int Sprite_GetHotSpot (int);
int Sprite_GetScale (int);
float Sprite_GetRotation (int);
int Sprite_GetTexture (int);
int Sprite_GetImageRect (int);
int Sprite_GetBlendMode (int);
int Sprite_GetTextureAttr (int);
int Sprite_GetTransform (int);
int Text_GetType (int);
int Text_GetTypeName (int);
int Text_GetTypeStatic ();
int Text_GetTypeNameStatic ();
int Text_Text (int);
void Text_RegisterObject (int);
void Text_ApplyAttributes (int);
void Text_OnResize (int,int,int);
void Text_OnIndentSet (int);
int Text_SetFont (int,int,float);
int Text_SetFont0 (int,int,float);
int Text_SetFontSize (int,float);
void Text_SetText (int,int);
void Text_SetTextAlignment (int,int);
void Text_SetRowSpacing (int,float);
void Text_SetWordwrap (int,int);
void Text_SetAutoLocalizable (int,int);
void Text_SetSelection (int,int,int);
void Text_ClearSelection (int);
void Text_SetTextEffect (int,int);
void Text_SetEffectShadowOffset (int,int);
void Text_SetEffectStrokeThickness (int,int);
void Text_SetEffectRoundStroke (int,int);
void Text_SetEffectColor (int,int);
int Text_GetFont (int);
float Text_GetFontSize (int);
int Text_GetText (int);
int Text_GetTextAlignment (int);
float Text_GetRowSpacing (int);
int Text_GetWordwrap (int);
int Text_GetAutoLocalizable (int);
int Text_GetSelectionStart (int);
int Text_GetSelectionLength (int);
int Text_GetTextEffect (int);
int Text_GetEffectShadowOffset (int);
int Text_GetEffectStrokeThickness (int);
int Text_GetEffectRoundStroke (int);
int Text_GetEffectColor (int);
float Text_GetRowHeight (int);
int Text_GetNumRows (int);
int Text_GetNumChars (int);
float Text_GetRowWidth (int,int);
int Text_GetCharPosition (int,int);
int Text_GetCharSize (int,int);
void Text_SetEffectDepthBias (int,float);
float Text_GetEffectDepthBias (int);
int Text_GetFontAttr (int);
void Text_SetTextAttr (int,int);
int Text_GetTextAttr (int);
int Text3D_GetType (int);
int Text3D_GetTypeName (int);
int Text3D_GetTypeStatic ();
int Text3D_GetTypeNameStatic ();
int Text3D_Text3D (int);
void Text3D_RegisterObject (int);
void Text3D_ApplyAttributes (int);
int Text3D_GetUpdateGeometryType (int);
int Text3D_SetFont (int,int,float);
int Text3D_SetFont0 (int,int,float);
int Text3D_SetFontSize (int,float);
void Text3D_SetMaterial (int,int);
void Text3D_SetText (int,int);
void Text3D_SetAlignment (int,int,int);
void Text3D_SetHorizontalAlignment (int,int);
void Text3D_SetVerticalAlignment (int,int);
void Text3D_SetTextAlignment (int,int);
void Text3D_SetRowSpacing (int,float);
void Text3D_SetWordwrap (int,int);
void Text3D_SetTextEffect (int,int);
void Text3D_SetEffectShadowOffset (int,int);
void Text3D_SetEffectStrokeThickness (int,int);
void Text3D_SetEffectRoundStroke (int,int);
void Text3D_SetEffectColor (int,int);
void Text3D_SetEffectDepthBias (int,float);
void Text3D_SetWidth (int,int);
void Text3D_SetColor (int,int);
void Text3D_SetColor1 (int,int,int);
void Text3D_SetOpacity (int,float);
void Text3D_SetFixedScreenSize (int,int);
void Text3D_SetFaceCameraMode (int,int);
int Text3D_GetFont (int);
float Text3D_GetFontSize (int);
int Text3D_GetMaterial (int);
int Text3D_GetText (int);
int Text3D_GetTextAlignment (int);
int Text3D_GetHorizontalAlignment (int);
int Text3D_GetVerticalAlignment (int);
float Text3D_GetRowSpacing (int);
int Text3D_GetWordwrap (int);
int Text3D_GetTextEffect (int);
int Text3D_GetEffectShadowOffset (int);
int Text3D_GetEffectStrokeThickness (int);
int Text3D_GetEffectRoundStroke (int);
int Text3D_GetEffectColor (int);
float Text3D_GetEffectDepthBias (int);
int Text3D_GetWidth (int);
int Text3D_GetHeight (int);
int Text3D_GetRowHeight (int);
int Text3D_GetNumRows (int);
int Text3D_GetNumChars (int);
int Text3D_GetRowWidth (int,int);
int Text3D_GetCharPosition (int,int);
int Text3D_GetCharSize (int,int);
int Text3D_GetColor (int,int);
float Text3D_GetOpacity (int);
int Text3D_IsFixedScreenSize (int);
int Text3D_GetFaceCameraMode (int);
int Text3D_GetFontAttr (int);
int Text3D_GetMaterialAttr (int);
void Text3D_SetTextAttr (int,int);
int Text3D_GetTextAttr (int);
int Text3D_GetColorAttr (int);
int ToolTip_GetType (int);
int ToolTip_GetTypeName (int);
int ToolTip_GetTypeStatic ();
int ToolTip_GetTypeNameStatic ();
int ToolTip_ToolTip (int);
void ToolTip_RegisterObject (int);
void ToolTip_Update (int,float);
void ToolTip_Reset (int);
void ToolTip_AddAltTarget (int,int);
void ToolTip_SetDelay (int,float);
float ToolTip_GetDelay (int);
int UIBatch_UIBatch ();
void UIBatch_SetColor (int,int,int);
void UIBatch_SetDefaultColor (int);
void UIBatch_AddQuad (int,float,float,float,float,int,int,int,int);
void UIBatch_AddQuad0 (int,int,int,int,int,int,int,int,int,int);
void UIBatch_AddQuad1 (int,int,int,int,int,int,int,int,int,int);
void UIBatch_AddQuad2 (int,int,int,int,int,int,int,int,int,int);
void UIBatch_AddQuad3 (int,int,int,int,int,int,int,int,int,int,int,int,int,int);
int UIBatch_GetInterpolatedColor (int,float,float);
int View3D_GetType (int);
int View3D_GetTypeName (int);
int View3D_GetTypeStatic ();
int View3D_GetTypeNameStatic ();
int View3D_View3D (int);
void View3D_RegisterObject (int);
void View3D_OnResize (int,int,int);
void View3D_SetView (int,int,int,int);
void View3D_SetFormat (int,int);
void View3D_SetAutoUpdate (int,int);
void View3D_QueueUpdate (int);
int View3D_GetFormat (int);
int View3D_GetAutoUpdate (int);
int View3D_GetScene (int);
int View3D_GetCameraNode (int);
int View3D_GetRenderTexture (int);
int View3D_GetDepthTexture (int);
int View3D_GetViewport (int);
int File_GetSize (int);
int File_WriteLine (int,int);
int File_ReadLine (int);
int File_GetType (int);
int File_GetTypeName (int);
int File_GetTypeStatic ();
int File_GetTypeNameStatic ();
int File_File (int);
int File_File0 (int,int,int);
int File_File1 (int,int,int);
int File_Read (int,int,int);
int File_Seek (int,int);
int File_Write (int,int,int);
int File_GetChecksum (int);
int File_Open (int,int,int);
int File_Open2 (int,int,int);
void File_Close (int);
void File_Flush (int);
int File_GetMode (int);
int File_IsOpen (int);
int File_GetHandle (int);
int File_IsPackaged (int);
int File_GetName (int);
int Log_GetType (int);
int Log_GetTypeName (int);
int Log_GetTypeStatic ();
int Log_GetTypeNameStatic ();
int Log_Log (int);
void Log_Open (int,int);
void Log_Close (int);
void Log_SetLevel (int,int);
void Log_SetTimeStamp (int,int);
void Log_SetQuiet (int,int);
int Log_GetLevel (int);
int Log_GetTimeStamp (int);
int Log_GetLastMessage (int);
int Log_IsQuiet (int);
void Log_Write (int,int);
void Log_WriteRaw (int,int);
int FileSystem_GetType (int);
int FileSystem_GetTypeName (int);
int FileSystem_GetTypeStatic ();
int FileSystem_GetTypeNameStatic ();
int FileSystem_FileSystem (int);
int FileSystem_SetCurrentDir (int,int);
int FileSystem_CreateDir (int,int);
void FileSystem_SetExecuteConsoleCommands (int,int);
int FileSystem_SystemCommand (int,int,int);
int FileSystem_SystemCommandAsync (int,int);
int FileSystem_SystemOpen (int,int,int);
int FileSystem_Copy (int,int,int);
int FileSystem_Rename (int,int,int);
int FileSystem_Delete (int,int);
void FileSystem_RegisterPath (int,int);
int FileSystem_SetLastModifiedTime (int,int,int);
int FileSystem_GetCurrentDir (int);
int FileSystem_GetExecuteConsoleCommands (int);
int FileSystem_HasRegisteredPaths (int);
int FileSystem_CheckAccess (int,int);
int FileSystem_GetLastModifiedTime (int,int);
int FileSystem_FileExists (int,int);
int FileSystem_DirExists (int,int);
int FileSystem_GetProgramDir (int);
int FileSystem_GetUserDocumentsDir (int);
int FileSystem_GetAppPreferencesDir (int,int,int);
int FileSystem_GetTemporaryDir (int);
int FileWatcher_GetType (int);
int FileWatcher_GetTypeName (int);
int FileWatcher_GetTypeStatic ();
int FileWatcher_GetTypeNameStatic ();
int FileWatcher_FileWatcher (int);
void FileWatcher_ThreadFunction (int);
int FileWatcher_StartWatching (int,int,int);
void FileWatcher_StopWatching (int);
void FileWatcher_SetDelay (int,float);
void FileWatcher_AddChange (int,int);
int FileWatcher_GetPath (int);
float FileWatcher_GetDelay (int);
int PackageFile_GetType (int);
int PackageFile_GetTypeName (int);
int PackageFile_GetTypeStatic ();
int PackageFile_GetTypeNameStatic ();
int PackageFile_PackageFile (int);
int PackageFile_PackageFile0 (int,int,int);
int PackageFile_Open (int,int,int);
int PackageFile_Exists (int,int);
int PackageFile_GetEntry (int,int);
int PackageFile_GetName (int);
int PackageFile_GetNameHash (int);
int PackageFile_GetNumFiles (int);
int PackageFile_GetTotalSize (int);
int PackageFile_GetTotalDataSize (int);
int PackageFile_GetChecksum (int);
int PackageFile_IsCompressed (int);
void Drawable2D_SetSourceBatchesVertices (int,int,int);
int Drawable2D_GetType (int);
int Drawable2D_GetTypeName (int);
int Drawable2D_GetTypeStatic ();
int Drawable2D_GetTypeNameStatic ();
void Drawable2D_RegisterObject (int);
void Drawable2D_OnSetEnabled (int);
void Drawable2D_SetLayer (int,int);
void Drawable2D_SetOrderInLayer (int,int);
int Drawable2D_GetLayer (int);
int Drawable2D_GetOrderInLayer (int);
void Drawable2D_SetSourceBatches (int,int,int);
void Drawable2D_SetSourceBatchesDirty (int);
void Drawable2D_SetMonoUpdateSourceBatches (int,int);
int PhysicsWorld2D_GetRigidBodies (int,int,int,int);
int PhysicsWorld2D_GetType (int);
int PhysicsWorld2D_GetTypeName (int);
int PhysicsWorld2D_GetTypeStatic ();
int PhysicsWorld2D_GetTypeNameStatic ();
int PhysicsWorld2D_PhysicsWorld2D (int);
void PhysicsWorld2D_RegisterObject (int);
void PhysicsWorld2D_DrawDebugGeometry (int,int,int);
void PhysicsWorld2D_Update (int,float);
void PhysicsWorld2D_DrawDebugGeometry0 (int);
void PhysicsWorld2D_SetUpdateEnabled (int,int);
void PhysicsWorld2D_SetDrawShape (int,int);
void PhysicsWorld2D_SetDrawJoint (int,int);
void PhysicsWorld2D_SetDrawAabb (int,int);
void PhysicsWorld2D_SetDrawPair (int,int);
void PhysicsWorld2D_SetDrawCenterOfMass (int,int);
void PhysicsWorld2D_SetAllowSleeping (int,int);
void PhysicsWorld2D_SetWarmStarting (int,int);
void PhysicsWorld2D_SetContinuousPhysics (int,int);
void PhysicsWorld2D_SetSubStepping (int,int);
void PhysicsWorld2D_SetGravity (int,int);
void PhysicsWorld2D_SetAutoClearForces (int,int);
void PhysicsWorld2D_SetVelocityIterations (int,int);
void PhysicsWorld2D_SetPositionIterations (int,int);
void PhysicsWorld2D_AddRigidBody (int,int);
void PhysicsWorld2D_RemoveRigidBody (int,int);
int PhysicsWorld2D_GetRigidBody (int,int,int);
int PhysicsWorld2D_GetRigidBody1 (int,int,int,int);
int PhysicsWorld2D_IsUpdateEnabled (int);
int PhysicsWorld2D_GetDrawShape (int);
int PhysicsWorld2D_GetDrawJoint (int);
int PhysicsWorld2D_GetDrawAabb (int);
int PhysicsWorld2D_GetDrawPair (int);
int PhysicsWorld2D_GetDrawCenterOfMass (int);
int PhysicsWorld2D_GetAllowSleeping (int);
int PhysicsWorld2D_GetWarmStarting (int);
int PhysicsWorld2D_GetContinuousPhysics (int);
int PhysicsWorld2D_GetSubStepping (int);
int PhysicsWorld2D_GetAutoClearForces (int);
int PhysicsWorld2D_GetGravity (int);
int PhysicsWorld2D_GetVelocityIterations (int);
int PhysicsWorld2D_GetPositionIterations (int);
void PhysicsWorld2D_SetApplyingTransforms (int,int);
int PhysicsWorld2D_IsApplyingTransforms (int);
int StaticSprite2D_GetType (int);
int StaticSprite2D_GetTypeName (int);
int StaticSprite2D_GetTypeStatic ();
int StaticSprite2D_GetTypeNameStatic ();
int StaticSprite2D_StaticSprite2D (int);
void StaticSprite2D_RegisterObject (int);
void StaticSprite2D_SetSprite (int,int);
void StaticSprite2D_SetBlendMode (int,int);
void StaticSprite2D_SetFlip (int,int,int,int);
void StaticSprite2D_SetFlipX (int,int);
void StaticSprite2D_SetFlipY (int,int);
void StaticSprite2D_SetSwapXY (int,int);
void StaticSprite2D_SetColor (int,int);
void StaticSprite2D_SetAlpha (int,float);
void StaticSprite2D_SetUseHotSpot (int,int);
void StaticSprite2D_SetUseDrawRect (int,int);
void StaticSprite2D_SetUseTextureRect (int,int);
void StaticSprite2D_SetHotSpot (int,int);
void StaticSprite2D_SetCustomMaterial (int,int);
int StaticSprite2D_GetSprite (int);
int StaticSprite2D_GetBlendMode (int);
int StaticSprite2D_GetFlipX (int);
int StaticSprite2D_GetFlipY (int);
int StaticSprite2D_GetSwapXY (int);
int StaticSprite2D_GetColor (int);
float StaticSprite2D_GetAlpha (int);
int StaticSprite2D_GetUseHotSpot (int);
int StaticSprite2D_GetUseDrawRect (int);
int StaticSprite2D_GetUseTextureRect (int);
int StaticSprite2D_GetHotSpot (int);
int StaticSprite2D_GetCustomMaterial (int);
int StaticSprite2D_GetSpriteAttr (int);
int StaticSprite2D_GetCustomMaterialAttr (int);
void StaticSprite2D_SetMonoWorldBoundingBoxUpdate (int,int);
int Texture2D_GetType (int);
int Texture2D_GetTypeName (int);
int Texture2D_GetTypeStatic ();
int Texture2D_GetTypeNameStatic ();
int Texture2D_Texture2D (int);
void Texture2D_RegisterObject (int);
int Texture2D_BeginLoad_File (int,int);
int Texture2D_BeginLoad_MemoryBuffer (int,int);
int Texture2D_EndLoad (int);
void Texture2D_Release (int);
int Texture2D_SetSize (int,int,int,int,int,int,int);
int Texture2D_SetData (int,int,int,int,int,int,int);
int Texture2D_SetData0 (int,int,int);
int Texture2D_GetData (int,int,int);
int Texture2D_GetImage (int,int);
int Texture2D_GetImage1 (int);
int Texture2D_GetRenderSurface (int);
int AnimatedSprite2D_GetType (int);
int AnimatedSprite2D_GetTypeName (int);
int AnimatedSprite2D_GetTypeStatic ();
int AnimatedSprite2D_GetTypeNameStatic ();
int AnimatedSprite2D_AnimatedSprite2D (int);
void AnimatedSprite2D_RegisterObject (int);
void AnimatedSprite2D_OnSetEnabled (int);
void AnimatedSprite2D_SetAnimationSet (int,int);
void AnimatedSprite2D_SetEntity (int,int);
void AnimatedSprite2D_SetAnimation (int,int,int);
void AnimatedSprite2D_SetLoopMode (int,int);
void AnimatedSprite2D_SetSpeed (int,float);
int AnimatedSprite2D_GetAnimationSet (int);
int AnimatedSprite2D_GetEntity (int);
int AnimatedSprite2D_GetAnimation (int);
int AnimatedSprite2D_GetLoopMode (int);
float AnimatedSprite2D_GetSpeed (int);
int AnimatedSprite2D_GetAnimationSetAttr (int);
void AnimatedSprite2D_SetAnimationAttr (int,int);
int AnimationSet2D_GetType (int);
int AnimationSet2D_GetTypeName (int);
int AnimationSet2D_GetTypeStatic ();
int AnimationSet2D_GetTypeNameStatic ();
int AnimationSet2D_AnimationSet2D (int);
void AnimationSet2D_RegisterObject (int);
int AnimationSet2D_BeginLoad_File (int,int);
int AnimationSet2D_BeginLoad_MemoryBuffer (int,int);
int AnimationSet2D_EndLoad (int);
int AnimationSet2D_GetNumAnimations (int);
int AnimationSet2D_GetAnimation (int,int);
int AnimationSet2D_HasAnimation (int,int);
int AnimationSet2D_GetSprite (int);
int AnimationSet2D_GetSpriterFileSprite (int,int,int);
int CollisionBox2D_GetType (int);
int CollisionBox2D_GetTypeName (int);
int CollisionBox2D_GetTypeStatic ();
int CollisionBox2D_GetTypeNameStatic ();
int CollisionBox2D_CollisionBox2D (int);
void CollisionBox2D_RegisterObject (int);
void CollisionBox2D_SetSize (int,int);
void CollisionBox2D_SetSize0 (int,float,float);
void CollisionBox2D_SetCenter (int,int);
void CollisionBox2D_SetCenter1 (int,float,float);
void CollisionBox2D_SetAngle (int,float);
int CollisionBox2D_GetSize (int);
int CollisionBox2D_GetCenter (int);
float CollisionBox2D_GetAngle (int);
int CollisionChain2D_GetType (int);
int CollisionChain2D_GetTypeName (int);
int CollisionChain2D_GetTypeStatic ();
int CollisionChain2D_GetTypeNameStatic ();
int CollisionChain2D_CollisionChain2D (int);
void CollisionChain2D_RegisterObject (int);
void CollisionChain2D_SetLoop (int,int);
void CollisionChain2D_SetVertexCount (int,int);
void CollisionChain2D_SetVertex (int,int,int);
int CollisionChain2D_GetLoop (int);
int CollisionChain2D_GetVertexCount (int);
int CollisionChain2D_GetVertex (int,int);
int CollisionCircle2D_GetType (int);
int CollisionCircle2D_GetTypeName (int);
int CollisionCircle2D_GetTypeStatic ();
int CollisionCircle2D_GetTypeNameStatic ();
int CollisionCircle2D_CollisionCircle2D (int);
void CollisionCircle2D_RegisterObject (int);
void CollisionCircle2D_SetRadius (int,float);
void CollisionCircle2D_SetCenter (int,int);
void CollisionCircle2D_SetCenter0 (int,float,float);
float CollisionCircle2D_GetRadius (int);
int CollisionCircle2D_GetCenter (int);
int CollisionEdge2D_GetType (int);
int CollisionEdge2D_GetTypeName (int);
int CollisionEdge2D_GetTypeStatic ();
int CollisionEdge2D_GetTypeNameStatic ();
int CollisionEdge2D_CollisionEdge2D (int);
void CollisionEdge2D_RegisterObject (int);
void CollisionEdge2D_SetVertex1 (int,int);
void CollisionEdge2D_SetVertex2 (int,int);
void CollisionEdge2D_SetVertices (int,int,int);
int CollisionEdge2D_GetVertex1 (int);
int CollisionEdge2D_GetVertex2 (int);
int CollisionPolygon2D_GetType (int);
int CollisionPolygon2D_GetTypeName (int);
int CollisionPolygon2D_GetTypeStatic ();
int CollisionPolygon2D_GetTypeNameStatic ();
int CollisionPolygon2D_CollisionPolygon2D (int);
void CollisionPolygon2D_RegisterObject (int);
void CollisionPolygon2D_SetVertexCount (int,int);
void CollisionPolygon2D_SetVertex (int,int,int);
int CollisionPolygon2D_GetVertexCount (int);
int CollisionPolygon2D_GetVertex (int,int);
int CollisionShape2D_GetType (int);
int CollisionShape2D_GetTypeName (int);
int CollisionShape2D_GetTypeStatic ();
int CollisionShape2D_GetTypeNameStatic ();
void CollisionShape2D_RegisterObject (int);
void CollisionShape2D_OnSetEnabled (int);
void CollisionShape2D_SetTrigger (int,int);
void CollisionShape2D_SetCategoryBits (int,int);
void CollisionShape2D_SetMaskBits (int,int);
void CollisionShape2D_SetGroupIndex (int,int);
void CollisionShape2D_SetDensity (int,float);
void CollisionShape2D_SetFriction (int,float);
void CollisionShape2D_SetRestitution (int,float);
void CollisionShape2D_CreateFixture (int);
void CollisionShape2D_ReleaseFixture (int);
int CollisionShape2D_IsTrigger (int);
int CollisionShape2D_GetCategoryBits (int);
int CollisionShape2D_GetMaskBits (int);
int CollisionShape2D_GetGroupIndex (int);
float CollisionShape2D_GetDensity (int);
float CollisionShape2D_GetFriction (int);
float CollisionShape2D_GetRestitution (int);
float CollisionShape2D_GetMass (int);
float CollisionShape2D_GetInertia (int);
int CollisionShape2D_GetMassCenter (int);
int Constraint2D_GetType (int);
int Constraint2D_GetTypeName (int);
int Constraint2D_GetTypeStatic ();
int Constraint2D_GetTypeNameStatic ();
int Constraint2D_Constraint2D (int);
void Constraint2D_RegisterObject (int);
void Constraint2D_ApplyAttributes (int);
void Constraint2D_OnSetEnabled (int);
void Constraint2D_CreateJoint (int);
void Constraint2D_ReleaseJoint (int);
void Constraint2D_SetOtherBody (int,int);
void Constraint2D_SetCollideConnected (int,int);
void Constraint2D_SetAttachedConstraint (int,int);
int Constraint2D_GetOwnerBody (int);
int Constraint2D_GetOtherBody (int);
int Constraint2D_GetCollideConnected (int);
int Constraint2D_GetAttachedConstraint (int);
int ConstraintDistance2D_GetType (int);
int ConstraintDistance2D_GetTypeName (int);
int ConstraintDistance2D_GetTypeStatic ();
int ConstraintDistance2D_GetTypeNameStatic ();
int ConstraintDistance2D_ConstraintDistance2D (int);
void ConstraintDistance2D_RegisterObject (int);
void ConstraintDistance2D_SetOwnerBodyAnchor (int,int);
void ConstraintDistance2D_SetOtherBodyAnchor (int,int);
void ConstraintDistance2D_SetFrequencyHz (int,float);
void ConstraintDistance2D_SetDampingRatio (int,float);
void ConstraintDistance2D_SetLength (int,float);
int ConstraintDistance2D_GetOwnerBodyAnchor (int);
int ConstraintDistance2D_GetOtherBodyAnchor (int);
float ConstraintDistance2D_GetFrequencyHz (int);
float ConstraintDistance2D_GetDampingRatio (int);
float ConstraintDistance2D_GetLength (int);
int ConstraintFriction2D_GetType (int);
int ConstraintFriction2D_GetTypeName (int);
int ConstraintFriction2D_GetTypeStatic ();
int ConstraintFriction2D_GetTypeNameStatic ();
int ConstraintFriction2D_ConstraintFriction2D (int);
void ConstraintFriction2D_RegisterObject (int);
void ConstraintFriction2D_SetAnchor (int,int);
void ConstraintFriction2D_SetMaxForce (int,float);
void ConstraintFriction2D_SetMaxTorque (int,float);
int ConstraintFriction2D_GetAnchor (int);
float ConstraintFriction2D_GetMaxForce (int);
float ConstraintFriction2D_GetMaxTorque (int);
int ConstraintGear2D_GetType (int);
int ConstraintGear2D_GetTypeName (int);
int ConstraintGear2D_GetTypeStatic ();
int ConstraintGear2D_GetTypeNameStatic ();
int ConstraintGear2D_ConstraintGear2D (int);
void ConstraintGear2D_RegisterObject (int);
void ConstraintGear2D_SetOwnerConstraint (int,int);
void ConstraintGear2D_SetOtherConstraint (int,int);
void ConstraintGear2D_SetRatio (int,float);
int ConstraintGear2D_GetOwnerConstraint (int);
int ConstraintGear2D_GetOtherConstraint (int);
float ConstraintGear2D_GetRatio (int);
int ConstraintMotor2D_GetType (int);
int ConstraintMotor2D_GetTypeName (int);
int ConstraintMotor2D_GetTypeStatic ();
int ConstraintMotor2D_GetTypeNameStatic ();
int ConstraintMotor2D_ConstraintMotor2D (int);
void ConstraintMotor2D_RegisterObject (int);
void ConstraintMotor2D_SetLinearOffset (int,int);
void ConstraintMotor2D_SetAngularOffset (int,float);
void ConstraintMotor2D_SetMaxForce (int,float);
void ConstraintMotor2D_SetMaxTorque (int,float);
void ConstraintMotor2D_SetCorrectionFactor (int,float);
int ConstraintMotor2D_GetLinearOffset (int);
float ConstraintMotor2D_GetAngularOffset (int);
float ConstraintMotor2D_GetMaxForce (int);
float ConstraintMotor2D_GetMaxTorque (int);
float ConstraintMotor2D_GetCorrectionFactor (int);
int ConstraintMouse2D_GetType (int);
int ConstraintMouse2D_GetTypeName (int);
int ConstraintMouse2D_GetTypeStatic ();
int ConstraintMouse2D_GetTypeNameStatic ();
int ConstraintMouse2D_ConstraintMouse2D (int);
void ConstraintMouse2D_RegisterObject (int);
void ConstraintMouse2D_SetTarget (int,int);
void ConstraintMouse2D_SetMaxForce (int,float);
void ConstraintMouse2D_SetFrequencyHz (int,float);
void ConstraintMouse2D_SetDampingRatio (int,float);
int ConstraintMouse2D_GetTarget (int);
float ConstraintMouse2D_GetMaxForce (int);
float ConstraintMouse2D_GetFrequencyHz (int);
float ConstraintMouse2D_GetDampingRatio (int);
int ConstraintPrismatic2D_GetType (int);
int ConstraintPrismatic2D_GetTypeName (int);
int ConstraintPrismatic2D_GetTypeStatic ();
int ConstraintPrismatic2D_GetTypeNameStatic ();
int ConstraintPrismatic2D_ConstraintPrismatic2D (int);
void ConstraintPrismatic2D_RegisterObject (int);
void ConstraintPrismatic2D_SetAnchor (int,int);
void ConstraintPrismatic2D_SetAxis (int,int);
void ConstraintPrismatic2D_SetEnableLimit (int,int);
void ConstraintPrismatic2D_SetLowerTranslation (int,float);
void ConstraintPrismatic2D_SetUpperTranslation (int,float);
void ConstraintPrismatic2D_SetEnableMotor (int,int);
void ConstraintPrismatic2D_SetMaxMotorForce (int,float);
void ConstraintPrismatic2D_SetMotorSpeed (int,float);
int ConstraintPrismatic2D_GetAnchor (int);
int ConstraintPrismatic2D_GetAxis (int);
int ConstraintPrismatic2D_GetEnableLimit (int);
float ConstraintPrismatic2D_GetLowerTranslation (int);
float ConstraintPrismatic2D_GetUpperTranslation (int);
int ConstraintPrismatic2D_GetEnableMotor (int);
float ConstraintPrismatic2D_GetMaxMotorForce (int);
float ConstraintPrismatic2D_GetMotorSpeed (int);
int ConstraintPulley2D_GetType (int);
int ConstraintPulley2D_GetTypeName (int);
int ConstraintPulley2D_GetTypeStatic ();
int ConstraintPulley2D_GetTypeNameStatic ();
int ConstraintPulley2D_ConstraintPulley2D (int);
void ConstraintPulley2D_RegisterObject (int);
void ConstraintPulley2D_SetOwnerBodyGroundAnchor (int,int);
void ConstraintPulley2D_SetOtherBodyGroundAnchor (int,int);
void ConstraintPulley2D_SetOwnerBodyAnchor (int,int);
void ConstraintPulley2D_SetOtherBodyAnchor (int,int);
void ConstraintPulley2D_SetRatio (int,float);
int ConstraintPulley2D_GetOwnerBodyGroundAnchor (int);
int ConstraintPulley2D_GetOtherBodyGroundAnchor (int);
int ConstraintPulley2D_GetOwnerBodyAnchor (int);
int ConstraintPulley2D_GetOtherBodyAnchor (int);
float ConstraintPulley2D_GetRatio (int);
int ConstraintRevolute2D_GetType (int);
int ConstraintRevolute2D_GetTypeName (int);
int ConstraintRevolute2D_GetTypeStatic ();
int ConstraintRevolute2D_GetTypeNameStatic ();
int ConstraintRevolute2D_ConstraintRevolute2D (int);
void ConstraintRevolute2D_RegisterObject (int);
void ConstraintRevolute2D_SetAnchor (int,int);
void ConstraintRevolute2D_SetEnableLimit (int,int);
void ConstraintRevolute2D_SetLowerAngle (int,float);
void ConstraintRevolute2D_SetUpperAngle (int,float);
void ConstraintRevolute2D_SetEnableMotor (int,int);
void ConstraintRevolute2D_SetMotorSpeed (int,float);
void ConstraintRevolute2D_SetMaxMotorTorque (int,float);
int ConstraintRevolute2D_GetAnchor (int);
int ConstraintRevolute2D_GetEnableLimit (int);
float ConstraintRevolute2D_GetLowerAngle (int);
float ConstraintRevolute2D_GetUpperAngle (int);
int ConstraintRevolute2D_GetEnableMotor (int);
float ConstraintRevolute2D_GetMotorSpeed (int);
float ConstraintRevolute2D_GetMaxMotorTorque (int);
int ConstraintRope2D_GetType (int);
int ConstraintRope2D_GetTypeName (int);
int ConstraintRope2D_GetTypeStatic ();
int ConstraintRope2D_GetTypeNameStatic ();
int ConstraintRope2D_ConstraintRope2D (int);
void ConstraintRope2D_RegisterObject (int);
void ConstraintRope2D_SetOwnerBodyAnchor (int,int);
void ConstraintRope2D_SetOtherBodyAnchor (int,int);
void ConstraintRope2D_SetMaxLength (int,float);
int ConstraintRope2D_GetOwnerBodyAnchor (int);
int ConstraintRope2D_GetOtherBodyAnchor (int);
float ConstraintRope2D_GetMaxLength (int);
int ConstraintWeld2D_GetType (int);
int ConstraintWeld2D_GetTypeName (int);
int ConstraintWeld2D_GetTypeStatic ();
int ConstraintWeld2D_GetTypeNameStatic ();
int ConstraintWeld2D_ConstraintWeld2D (int);
void ConstraintWeld2D_RegisterObject (int);
void ConstraintWeld2D_SetAnchor (int,int);
void ConstraintWeld2D_SetFrequencyHz (int,float);
void ConstraintWeld2D_SetDampingRatio (int,float);
int ConstraintWeld2D_GetAnchor (int);
float ConstraintWeld2D_GetFrequencyHz (int);
float ConstraintWeld2D_GetDampingRatio (int);
int ConstraintWheel2D_GetType (int);
int ConstraintWheel2D_GetTypeName (int);
int ConstraintWheel2D_GetTypeStatic ();
int ConstraintWheel2D_GetTypeNameStatic ();
int ConstraintWheel2D_ConstraintWheel2D (int);
void ConstraintWheel2D_RegisterObject (int);
void ConstraintWheel2D_SetAnchor (int,int);
void ConstraintWheel2D_SetAxis (int,int);
void ConstraintWheel2D_SetEnableMotor (int,int);
void ConstraintWheel2D_SetMaxMotorTorque (int,float);
void ConstraintWheel2D_SetMotorSpeed (int,float);
void ConstraintWheel2D_SetFrequencyHz (int,float);
void ConstraintWheel2D_SetDampingRatio (int,float);
int ConstraintWheel2D_GetAnchor (int);
int ConstraintWheel2D_GetAxis (int);
int ConstraintWheel2D_GetEnableMotor (int);
float ConstraintWheel2D_GetMaxMotorTorque (int);
float ConstraintWheel2D_GetMotorSpeed (int);
float ConstraintWheel2D_GetFrequencyHz (int);
float ConstraintWheel2D_GetDampingRatio (int);
int ParticleEffect2D_GetType (int);
int ParticleEffect2D_GetTypeName (int);
int ParticleEffect2D_GetTypeStatic ();
int ParticleEffect2D_GetTypeNameStatic ();
int ParticleEffect2D_ParticleEffect2D (int);
void ParticleEffect2D_RegisterObject (int);
int ParticleEffect2D_BeginLoad_File (int,int);
int ParticleEffect2D_BeginLoad_MemoryBuffer (int,int);
int ParticleEffect2D_EndLoad (int);
int ParticleEffect2D_Save_File (int,int);
int ParticleEffect2D_Save_MemoryBuffer (int,int);
void ParticleEffect2D_SetSprite (int,int);
void ParticleEffect2D_SetSourcePositionVariance (int,int);
void ParticleEffect2D_SetSpeed (int,float);
void ParticleEffect2D_SetSpeedVariance (int,float);
void ParticleEffect2D_SetParticleLifeSpan (int,float);
void ParticleEffect2D_SetParticleLifespanVariance (int,float);
void ParticleEffect2D_SetAngle (int,float);
void ParticleEffect2D_SetAngleVariance (int,float);
void ParticleEffect2D_SetGravity (int,int);
void ParticleEffect2D_SetRadialAcceleration (int,float);
void ParticleEffect2D_SetTangentialAcceleration (int,float);
void ParticleEffect2D_SetRadialAccelVariance (int,float);
void ParticleEffect2D_SetTangentialAccelVariance (int,float);
void ParticleEffect2D_SetStartColor (int,int);
void ParticleEffect2D_SetStartColorVariance (int,int);
void ParticleEffect2D_SetFinishColor (int,int);
void ParticleEffect2D_SetFinishColorVariance (int,int);
void ParticleEffect2D_SetMaxParticles (int,int);
void ParticleEffect2D_SetStartParticleSize (int,float);
void ParticleEffect2D_SetStartParticleSizeVariance (int,float);
void ParticleEffect2D_SetFinishParticleSize (int,float);
void ParticleEffect2D_SetFinishParticleSizeVariance (int,float);
void ParticleEffect2D_SetDuration (int,float);
void ParticleEffect2D_SetEmitterType (int,int);
void ParticleEffect2D_SetMaxRadius (int,float);
void ParticleEffect2D_SetMaxRadiusVariance (int,float);
void ParticleEffect2D_SetMinRadius (int,float);
void ParticleEffect2D_SetMinRadiusVariance (int,float);
void ParticleEffect2D_SetRotatePerSecond (int,float);
void ParticleEffect2D_SetRotatePerSecondVariance (int,float);
void ParticleEffect2D_SetBlendMode (int,int);
void ParticleEffect2D_SetRotationStart (int,float);
void ParticleEffect2D_SetRotationStartVariance (int,float);
void ParticleEffect2D_SetRotationEnd (int,float);
void ParticleEffect2D_SetRotationEndVariance (int,float);
int ParticleEffect2D_Clone (int,int);
int ParticleEffect2D_GetSprite (int);
int ParticleEffect2D_GetSourcePositionVariance (int);
float ParticleEffect2D_GetSpeed (int);
float ParticleEffect2D_GetSpeedVariance (int);
float ParticleEffect2D_GetParticleLifeSpan (int);
float ParticleEffect2D_GetParticleLifespanVariance (int);
float ParticleEffect2D_GetAngle (int);
float ParticleEffect2D_GetAngleVariance (int);
int ParticleEffect2D_GetGravity (int);
float ParticleEffect2D_GetRadialAcceleration (int);
float ParticleEffect2D_GetTangentialAcceleration (int);
float ParticleEffect2D_GetRadialAccelVariance (int);
float ParticleEffect2D_GetTangentialAccelVariance (int);
int ParticleEffect2D_GetStartColor (int);
int ParticleEffect2D_GetStartColorVariance (int);
int ParticleEffect2D_GetFinishColor (int);
int ParticleEffect2D_GetFinishColorVariance (int);
int ParticleEffect2D_GetMaxParticles (int);
float ParticleEffect2D_GetStartParticleSize (int);
float ParticleEffect2D_GetStartParticleSizeVariance (int);
float ParticleEffect2D_GetFinishParticleSize (int);
float ParticleEffect2D_GetFinishParticleSizeVariance (int);
float ParticleEffect2D_GetDuration (int);
int ParticleEffect2D_GetEmitterType (int);
float ParticleEffect2D_GetMaxRadius (int);
float ParticleEffect2D_GetMaxRadiusVariance (int);
float ParticleEffect2D_GetMinRadius (int);
float ParticleEffect2D_GetMinRadiusVariance (int);
float ParticleEffect2D_GetRotatePerSecond (int);
float ParticleEffect2D_GetRotatePerSecondVariance (int);
int ParticleEffect2D_GetBlendMode (int);
float ParticleEffect2D_GetRotationStart (int);
float ParticleEffect2D_GetRotationStartVariance (int);
float ParticleEffect2D_GetRotationEnd (int);
float ParticleEffect2D_GetRotationEndVariance (int);
int ParticleEmitter2D_GetType (int);
int ParticleEmitter2D_GetTypeName (int);
int ParticleEmitter2D_GetTypeStatic ();
int ParticleEmitter2D_GetTypeNameStatic ();
int ParticleEmitter2D_ParticleEmitter2D (int);
void ParticleEmitter2D_RegisterObject (int);
void ParticleEmitter2D_OnSetEnabled (int);
void ParticleEmitter2D_SetEffect (int,int);
void ParticleEmitter2D_SetSprite (int,int);
void ParticleEmitter2D_SetBlendMode (int,int);
void ParticleEmitter2D_SetMaxParticles (int,int);
void ParticleEmitter2D_SetEmitting (int,int);
int ParticleEmitter2D_GetEffect (int);
int ParticleEmitter2D_GetSprite (int);
int ParticleEmitter2D_GetBlendMode (int);
int ParticleEmitter2D_GetMaxParticles (int);
int ParticleEmitter2D_GetParticleEffectAttr (int);
int ParticleEmitter2D_GetSpriteAttr (int);
int ParticleEmitter2D_IsEmitting (int);
int PropertySet2D_PropertySet2D ();
void PropertySet2D_Load (int,int);
int PropertySet2D_HasProperty (int,int);
int PropertySet2D_GetProperty (int,int);
int Renderer2D_GetType (int);
int Renderer2D_GetTypeName (int);
int Renderer2D_GetTypeStatic ();
int Renderer2D_GetTypeNameStatic ();
int Renderer2D_Renderer2D (int);
void Renderer2D_RegisterObject (int);
int Renderer2D_GetUpdateGeometryType (int);
void Renderer2D_AddDrawable (int,int);
void Renderer2D_RemoveDrawable (int,int);
int Renderer2D_GetMaterial (int,int,int);
int Renderer2D_CheckVisibility (int,int);
int RigidBody2D_GetType (int);
int RigidBody2D_GetTypeName (int);
int RigidBody2D_GetTypeStatic ();
int RigidBody2D_GetTypeNameStatic ();
int RigidBody2D_RigidBody2D (int);
void RigidBody2D_RegisterObject (int);
void RigidBody2D_OnSetEnabled (int);
void RigidBody2D_SetBodyType (int,int);
void RigidBody2D_SetMass (int,float);
void RigidBody2D_SetInertia (int,float);
void RigidBody2D_SetMassCenter (int,int);
void RigidBody2D_SetUseFixtureMass (int,int);
void RigidBody2D_SetLinearDamping (int,float);
void RigidBody2D_SetAngularDamping (int,float);
void RigidBody2D_SetAllowSleep (int,int);
void RigidBody2D_SetFixedRotation (int,int);
void RigidBody2D_SetBullet (int,int);
void RigidBody2D_SetGravityScale (int,float);
void RigidBody2D_SetAwake (int,int);
void RigidBody2D_SetLinearVelocity (int,int);
void RigidBody2D_SetAngularVelocity (int,float);
void RigidBody2D_ApplyForce (int,int,int,int);
void RigidBody2D_ApplyForceToCenter (int,int,int);
void RigidBody2D_ApplyTorque (int,float,int);
void RigidBody2D_ApplyLinearImpulse (int,int,int,int);
void RigidBody2D_ApplyLinearImpulseToCenter (int,int,int);
void RigidBody2D_ApplyAngularImpulse (int,float,int);
void RigidBody2D_CreateBody (int);
void RigidBody2D_ReleaseBody (int);
void RigidBody2D_ApplyWorldTransform (int);
void RigidBody2D_ApplyWorldTransform0 (int,int,int);
void RigidBody2D_AddCollisionShape2D (int,int);
void RigidBody2D_RemoveCollisionShape2D (int,int);
void RigidBody2D_AddConstraint2D (int,int);
void RigidBody2D_RemoveConstraint2D (int,int);
int RigidBody2D_GetBodyType (int);
float RigidBody2D_GetMass (int);
float RigidBody2D_GetInertia (int);
int RigidBody2D_GetMassCenter (int);
int RigidBody2D_GetUseFixtureMass (int);
float RigidBody2D_GetLinearDamping (int);
float RigidBody2D_GetAngularDamping (int);
int RigidBody2D_IsAllowSleep (int);
int RigidBody2D_IsFixedRotation (int);
int RigidBody2D_IsBullet (int);
float RigidBody2D_GetGravityScale (int);
int RigidBody2D_IsAwake (int);
int RigidBody2D_GetLinearVelocity (int);
float RigidBody2D_GetAngularVelocity (int);
int Sprite2D_GetType (int);
int Sprite2D_GetTypeName (int);
int Sprite2D_GetTypeStatic ();
int Sprite2D_GetTypeNameStatic ();
int Sprite2D_Sprite2D (int);
void Sprite2D_RegisterObject (int);
int Sprite2D_BeginLoad_File (int,int);
int Sprite2D_BeginLoad_MemoryBuffer (int,int);
int Sprite2D_EndLoad (int);
void Sprite2D_SetTexture (int,int);
void Sprite2D_SetRectangle (int,int);
void Sprite2D_SetHotSpot (int,int);
void Sprite2D_SetOffset (int,int);
void Sprite2D_SetTextureEdgeOffset (int,float);
void Sprite2D_SetSpriteSheet (int,int);
int Sprite2D_GetTexture (int);
int Sprite2D_GetRectangle (int);
int Sprite2D_GetHotSpot (int);
int Sprite2D_GetOffset (int);
float Sprite2D_GetTextureEdgeOffset (int);
int Sprite2D_GetSpriteSheet (int);
int Sprite2D_SaveToResourceRef (int);
int SpriteSheet2D_GetType (int);
int SpriteSheet2D_GetTypeName (int);
int SpriteSheet2D_GetTypeStatic ();
int SpriteSheet2D_GetTypeNameStatic ();
int SpriteSheet2D_SpriteSheet2D (int);
void SpriteSheet2D_RegisterObject (int);
int SpriteSheet2D_BeginLoad_File (int,int);
int SpriteSheet2D_BeginLoad_MemoryBuffer (int,int);
int SpriteSheet2D_EndLoad (int);
void SpriteSheet2D_SetTexture (int,int);
void SpriteSheet2D_DefineSprite (int,int,int,int,int);
int SpriteSheet2D_GetTexture (int);
int SpriteSheet2D_GetSprite (int,int);
int Tile2D_Tile2D ();
int Tile2D_GetGid (int);
int Tile2D_GetFlipX (int);
int Tile2D_GetFlipY (int);
int Tile2D_GetSwapXY (int);
int Tile2D_GetSprite (int);
int Tile2D_HasProperty (int,int);
int Tile2D_GetProperty (int,int);
int TileMap2D_GetType (int);
int TileMap2D_GetTypeName (int);
int TileMap2D_GetTypeStatic ();
int TileMap2D_GetTypeNameStatic ();
int TileMap2D_TileMap2D (int);
void TileMap2D_RegisterObject (int);
void TileMap2D_DrawDebugGeometry (int,int,int);
void TileMap2D_SetTmxFile (int,int);
void TileMap2D_DrawDebugGeometry0 (int);
int TileMap2D_GetTmxFile (int);
int TileMap2D_GetInfo (int);
int TileMap2D_GetNumLayers (int);
int TileMap2D_GetLayer (int,int);
int TileMap2D_TileIndexToPosition (int,int,int);
int TileMap2D_PositionToTileIndex (int,int,int,int);
int TileMap2D_GetTmxFileAttr (int);
int TileMapLayer2D_GetType (int);
int TileMapLayer2D_GetTypeName (int);
int TileMapLayer2D_GetTypeStatic ();
int TileMapLayer2D_GetTypeNameStatic ();
int TileMapLayer2D_TileMapLayer2D (int);
void TileMapLayer2D_RegisterObject (int);
void TileMapLayer2D_DrawDebugGeometry (int,int,int);
void TileMapLayer2D_Initialize (int,int,int);
void TileMapLayer2D_SetDrawOrder (int,int);
void TileMapLayer2D_SetVisible (int,int);
int TileMapLayer2D_GetTileMap (int);
int TileMapLayer2D_GetTmxLayer (int);
int TileMapLayer2D_GetDrawOrder (int);
int TileMapLayer2D_IsVisible (int);
int TileMapLayer2D_HasProperty (int,int);
int TileMapLayer2D_GetProperty (int,int);
int TileMapLayer2D_GetLayerType (int);
int TileMapLayer2D_GetWidth (int);
int TileMapLayer2D_GetHeight (int);
int TileMapLayer2D_GetTileNode (int,int,int);
int TileMapLayer2D_GetTile (int,int,int);
int TileMapLayer2D_GetNumObjects (int);
int TileMapLayer2D_GetObject (int,int);
int TileMapLayer2D_GetObjectNode (int,int);
int TileMapLayer2D_GetImageNode (int);
int TileMapObject2D_TileMapObject2D ();
int TileMapObject2D_GetObjectType (int);
int TileMapObject2D_GetName (int);
int TileMapObject2D_GetType (int);
int TileMapObject2D_GetPosition (int);
int TileMapObject2D_GetSize (int);
int TileMapObject2D_GetNumPoints (int);
int TileMapObject2D_GetPoint (int,int);
int TileMapObject2D_GetTileGid (int);
int TileMapObject2D_GetTileFlipX (int);
int TileMapObject2D_GetTileFlipY (int);
int TileMapObject2D_GetTileSwapXY (int);
int TileMapObject2D_GetTileSprite (int);
int TileMapObject2D_HasProperty (int,int);
int TileMapObject2D_GetProperty (int,int);
int TmxFile2D_GetType (int);
int TmxFile2D_GetTypeName (int);
int TmxFile2D_GetTypeStatic ();
int TmxFile2D_GetTypeNameStatic ();
int TmxFile2D_TmxFile2D (int);
void TmxFile2D_RegisterObject (int);
int TmxFile2D_BeginLoad_File (int,int);
int TmxFile2D_BeginLoad_MemoryBuffer (int,int);
int TmxFile2D_EndLoad (int);
int TmxFile2D_SetInfo (int,int,int,int,float,float);
void TmxFile2D_AddLayer (int,int,int);
int TmxFile2D_GetInfo (int);
int TmxFile2D_GetTileSprite (int,int);
int TmxFile2D_GetTilePropertySet (int,int);
int TmxFile2D_GetNumLayers (int);
int TmxFile2D_GetLayer (int,int);
void TmxFile2D_SetSpriteTextureEdgeOffset (int,float);
float TmxFile2D_GetSpriteTextureEdgeOffset (int);
int TmxImageLayer2D_TmxImageLayer2D (int);
int TmxImageLayer2D_Load (int,int,int);
int TmxImageLayer2D_GetPosition (int);
int TmxImageLayer2D_GetSource (int);
int TmxImageLayer2D_GetSprite (int);
int TmxLayer2D_TmxLayer2D (int,int);
int TmxLayer2D_GetTmxFile (int);
int TmxLayer2D_GetType (int);
int TmxLayer2D_GetName (int);
int TmxLayer2D_GetWidth (int);
int TmxLayer2D_GetHeight (int);
int TmxLayer2D_IsVisible (int);
int TmxLayer2D_HasProperty (int,int);
int TmxLayer2D_GetProperty (int,int);
int TmxObjectGroup2D_TmxObjectGroup2D (int);
int TmxObjectGroup2D_Load (int,int,int);
int TmxObjectGroup2D_GetNumObjects (int);
int TmxObjectGroup2D_GetObject (int,int);
int TmxTileLayer2D_TmxTileLayer2D (int);
int TmxTileLayer2D_Load (int,int,int);
int TmxTileLayer2D_GetTile (int,int,int);
int Connection_GetControls (int);
int Connection_SetControls (int,int);
void Connection_SendRemoteEvent (int,int,int,int);
void Connection_SendRemoteEvent2 (int,int,int,int,int);
int Connection_GetType (int);
int Connection_GetTypeName (int);
int Connection_GetTypeStatic ();
int Connection_GetTypeNameStatic ();
int Connection_GetPacketType (int,int,int);
void Connection_SendMessage (int,int,int,int,int,int,int);
void Connection_SetScene (int,int);
void Connection_SetPosition (int,int);
void Connection_SetRotation (int,int);
void Connection_SetConnectPending (int,int);
void Connection_SetLogStatistics (int,int);
void Connection_Disconnect (int,int);
void Connection_SendServerUpdate (int);
void Connection_SendClientUpdate (int);
void Connection_SendRemoteEvents (int);
void Connection_SendPackages (int);
void Connection_SendBuffer (int,int);
void Connection_SendAllBuffers (int);
void Connection_ProcessPendingLatestData (int);
void Connection_Ban (int);
int Connection_GetScene (int);
int Connection_GetTimeStamp (int);
int Connection_GetPosition (int);
int Connection_GetRotation (int);
int Connection_IsClient (int);
int Connection_IsConnected (int);
int Connection_IsConnectPending (int);
int Connection_IsSceneLoaded (int);
int Connection_GetLogStatistics (int);
int Connection_GetAddress (int);
int Connection_GetPort (int);
float Connection_GetRoundTripTime (int);
int Connection_GetLastHeardTime (int);
float Connection_GetBytesInPerSec (int);
float Connection_GetBytesOutPerSec (int);
int Connection_GetPacketsInPerSec (int);
int Connection_GetPacketsOutPerSec (int);
int Connection_ToString (int);
int Connection_GetNumDownloads (int);
int Connection_GetDownloadName (int);
float Connection_GetDownloadProgress (int);
void Connection_SendPackageToClient (int,int);
void Connection_ConfigureNetworkSimulator (int,int,float);
void Connection_SetPacketSizeLimit (int,int);
int Network_Connect (int,int,int,int);
int Network_GetClientConnections (int,int);
int Network_GetInterfaceBroadcastAddress (int);
int Network_GetType (int);
int Network_GetTypeName (int);
int Network_GetTypeStatic ();
int Network_GetTypeNameStatic ();
int Network_Network (int);
void Network_DiscoverHosts (int,int);
void Network_SetPassword (int,int);
void Network_SetNATServerInfo (int,int,int);
void Network_Disconnect (int,int);
int Network_StartServer (int,int,int);
void Network_StopServer (int);
void Network_StartNATClient (int);
int Network_GetGUID (int);
void Network_BroadcastMessage (int,int,int,int,int,int,int);
void Network_SetUpdateFps (int,int);
void Network_SetSimulatedLatency (int,int);
void Network_SetSimulatedPacketLoss (int,float);
void Network_RegisterRemoteEvent (int,int);
void Network_UnregisterRemoteEvent (int,int);
void Network_UnregisterAllRemoteEvents (int);
void Network_SetPackageCacheDir (int,int);
void Network_SendPackageToClients (int,int,int);
void Network_BanAddress (int,int);
int Network_GetUpdateFps (int);
int Network_GetSimulatedLatency (int);
float Network_GetSimulatedPacketLoss (int);
int Network_GetServerConnection (int);
int Network_IsServerRunning (int);
int Network_CheckRemoteEvent (int,int);
int Network_GetPackageCacheDir (int);
void Network_Update (int,float);
void Network_PostUpdate (int,float);
void HttpRequest_ThreadFunction (int);
int HttpRequest_Read (int,int,int);
int HttpRequest_Seek (int,int);
int HttpRequest_IsEof (int);
int HttpRequest_GetURL (int);
int HttpRequest_GetVerb (int);
int HttpRequest_GetError (int);
int HttpRequest_GetState (int);
int HttpRequest_GetAvailableSize (int);
int HttpRequest_IsOpen (int);
int NetworkPriority_GetType (int);
int NetworkPriority_GetTypeName (int);
int NetworkPriority_GetTypeStatic ();
int NetworkPriority_GetTypeNameStatic ();
int NetworkPriority_NetworkPriority (int);
void NetworkPriority_RegisterObject (int);
void NetworkPriority_SetBasePriority (int,float);
void NetworkPriority_SetDistanceFactor (int,float);
void NetworkPriority_SetMinPriority (int,float);
void NetworkPriority_SetAlwaysUpdateOwner (int,int);
float NetworkPriority_GetBasePriority (int);
float NetworkPriority_GetDistanceFactor (int);
float NetworkPriority_GetMinPriority (int);
int NetworkPriority_GetAlwaysUpdateOwner (int);
int NetworkPriority_CheckUpdate (int,float,int);
int CollisionShape_GetType (int);
int CollisionShape_GetTypeName (int);
int CollisionShape_GetTypeStatic ();
int CollisionShape_GetTypeNameStatic ();
int CollisionShape_CollisionShape (int);
void CollisionShape_RegisterObject (int);
void CollisionShape_ApplyAttributes (int);
void CollisionShape_OnSetEnabled (int);
void CollisionShape_DrawDebugGeometry (int,int,int);
void CollisionShape_SetBox (int,int,int,int);
void CollisionShape_SetSphere (int,float,int,int);
void CollisionShape_SetStaticPlane (int,int,int);
void CollisionShape_SetCylinder (int,float,float,int,int);
void CollisionShape_SetCapsule (int,float,float,int,int);
void CollisionShape_SetCone (int,float,float,int,int);
void CollisionShape_SetTriangleMesh (int,int,int,int,int,int);
void CollisionShape_SetCustomTriangleMesh (int,int,int,int,int);
void CollisionShape_SetConvexHull (int,int,int,int,int,int);
void CollisionShape_SetCustomConvexHull (int,int,int,int,int);
void CollisionShape_SetGImpactMesh (int,int,int,int,int,int);
void CollisionShape_SetCustomGImpactMesh (int,int,int,int,int);
void CollisionShape_SetTerrain (int,int);
void CollisionShape_SetShapeType (int,int);
void CollisionShape_SetSize (int,int);
void CollisionShape_SetPosition (int,int);
void CollisionShape_SetRotation (int,int);
void CollisionShape_SetTransform (int,int,int);
void CollisionShape_SetMargin (int,float);
void CollisionShape_SetModel (int,int);
void CollisionShape_SetLodLevel (int,int);
int CollisionShape_GetPhysicsWorld (int);
int CollisionShape_GetShapeType (int);
int CollisionShape_GetSize (int);
int CollisionShape_GetPosition (int);
int CollisionShape_GetRotation (int);
float CollisionShape_GetMargin (int);
int CollisionShape_GetModel (int);
int CollisionShape_GetLodLevel (int);
int CollisionShape_GetWorldBoundingBox (int);
void CollisionShape_NotifyRigidBody (int,int);
int CollisionShape_GetModelAttr (int);
void CollisionShape_ReleaseShape (int);
int Constraint_GetType (int);
int Constraint_GetTypeName (int);
int Constraint_GetTypeStatic ();
int Constraint_GetTypeNameStatic ();
int Constraint_Constraint (int);
void Constraint_RegisterObject (int);
void Constraint_ApplyAttributes (int);
void Constraint_OnSetEnabled (int);
void Constraint_DrawDebugGeometry (int,int,int);
void Constraint_SetConstraintType (int,int);
void Constraint_SetOtherBody (int,int);
void Constraint_SetPosition (int,int);
void Constraint_SetRotation (int,int);
void Constraint_SetAxis (int,int);
void Constraint_SetOtherPosition (int,int);
void Constraint_SetOtherRotation (int,int);
void Constraint_SetOtherAxis (int,int);
void Constraint_SetWorldPosition (int,int);
void Constraint_SetHighLimit (int,int);
void Constraint_SetLowLimit (int,int);
void Constraint_SetERP (int,float);
void Constraint_SetCFM (int,float);
void Constraint_SetDisableCollision (int,int);
int Constraint_GetPhysicsWorld (int);
int Constraint_GetConstraintType (int);
int Constraint_GetOwnBody (int);
int Constraint_GetOtherBody (int);
int Constraint_GetPosition (int);
int Constraint_GetRotation (int);
int Constraint_GetOtherPosition (int);
int Constraint_GetOtherRotation (int);
int Constraint_GetWorldPosition (int);
int Constraint_GetHighLimit (int);
int Constraint_GetLowLimit (int);
float Constraint_GetERP (int);
float Constraint_GetCFM (int);
int Constraint_GetDisableCollision (int);
void Constraint_ReleaseConstraint (int);
void Constraint_ApplyFrames (int);
int CustomRaycastVehicle_GetType (int);
int CustomRaycastVehicle_GetTypeName (int);
int CustomRaycastVehicle_GetTypeStatic ();
int CustomRaycastVehicle_GetTypeNameStatic ();
int CustomRaycastVehicle_CustomRaycastVehicle (int);
void CustomRaycastVehicle_RegisterObject (int);
void CustomRaycastVehicle_ResetSuspension (int);
void CustomRaycastVehicle_SetVehicleCenterOfMass (int,int);
int CustomRaycastVehicle_GetVehicleCenterOfMass (int);
float CustomRaycastVehicle_GetSteeringValue (int,int);
void CustomRaycastVehicle_SetSteeringValue (int,float,int);
void CustomRaycastVehicle_ApplyEngineForce (int,float,int);
void CustomRaycastVehicle_SetBrake (int,float,int);
int CustomRaycastVehicle_GetWheelPositionWS (int,int);
int CustomRaycastVehicle_GetWheelPositionLS (int,int);
int CustomRaycastVehicle_GetWheelRotation (int,int);
void CustomRaycastVehicle_UpdateWheelTransform (int,int,int);
void CustomRaycastVehicle_AddWheel (int,int,int,int,float,float,int);
int CustomRaycastVehicle_GetNumWheels (int);
int CustomRaycastVehicle_GetForwardVector (int);
float CustomRaycastVehicle_GetCurrentSpeedKmHour (int);
int CustomRaycastVehicle_GetCompoundLocalExtents (int);
int CustomRaycastVehicle_GetCompooundLocalExtentsCenter (int);
int CustomRaycastVehicle_GetCompoundLocalAabbMin (int);
int CustomRaycastVehicle_GetCompoundLocalAabbMax (int);
void CustomRaycastVehicle_CompoundScaleLocalAabbMin (int,int);
void CustomRaycastVehicle_CompoundScaleLocalAabbMax (int,int);
void CustomRaycastVehicle_SetWheelSuspensionStiffness (int,int,float);
float CustomRaycastVehicle_GetWheelSuspensionStiffness (int,int);
void CustomRaycastVehicle_SetWheelDampingRelaxation (int,int,float);
float CustomRaycastVehicle_GetWheelDampingRelaxation (int,int);
void CustomRaycastVehicle_SetWheelDampingCompression (int,int,float);
float CustomRaycastVehicle_GetWheelDampingCompression (int,int);
void CustomRaycastVehicle_SetWheelFrictionSlip (int,int,float);
float CustomRaycastVehicle_GetWheelFrictionSlip (int,int);
void CustomRaycastVehicle_SetWheelRollInfluence (int,int,float);
float CustomRaycastVehicle_GetWheelRollInfluence (int,int);
void CustomRaycastVehicle_SetSideFrictionStiffness (int,int,float);
float CustomRaycastVehicle_GetSideFrictionStiffness (int,int);
int CustomRaycastVehicle_GetChassisConnectionPointCS (int,int);
int CustomRaycastVehicle_IsWheelInContact (int,int);
int CustomRaycastVehicle_GetContactPointWS (int,int);
int CustomRaycastVehicle_GetContactNormalWS (int,int);
void CustomRaycastVehicle_SetSkidInfoCumulative (int,int,float);
float CustomRaycastVehicle_GetSkidInfoCumulative (int,int);
float CustomRaycastVehicle_GetWheelsRadius (int,int);
void CustomRaycastVehicle_SetSkidInfo (int,int,float);
float CustomRaycastVehicle_GetSkidInfo (int,int);
void CustomRaycastVehicle_SetDeltaRotation (int,int,float);
float CustomRaycastVehicle_GetDeltaRotation (int,int);
void CustomRaycastVehicle_SetRotation (int,int,float);
float CustomRaycastVehicle_GetRotation (int,int);
int CustomRaycastVehicle_GetWheelAxleWS (int,int);
void CustomRaycastVehicle_SetRollInfluence (int,int,float);
float CustomRaycastVehicle_GetRollInfluence (int,int);
int PhysicsWorld_GetType (int);
int PhysicsWorld_GetTypeName (int);
int PhysicsWorld_GetTypeStatic ();
int PhysicsWorld_GetTypeNameStatic ();
int PhysicsWorld_PhysicsWorld (int);
void PhysicsWorld_RegisterObject (int);
void PhysicsWorld_setDebugMode (int,int);
int PhysicsWorld_getDebugMode (int);
void PhysicsWorld_DrawDebugGeometry (int,int,int);
void PhysicsWorld_Update (int,float);
void PhysicsWorld_UpdateCollisions (int);
void PhysicsWorld_SetFps (int,int);
void PhysicsWorld_SetGravity (int,int);
void PhysicsWorld_SetMaxSubSteps (int,int);
void PhysicsWorld_SetNumIterations (int,int);
void PhysicsWorld_SetUpdateEnabled (int,int);
void PhysicsWorld_SetInterpolation (int,int);
void PhysicsWorld_SetInternalEdge (int,int);
void PhysicsWorld_SetSplitImpulse (int,int);
void PhysicsWorld_SetMaxNetworkAngularVelocity (int,float);
void PhysicsWorld_RaycastSingle (int,int,int,float,int);
void PhysicsWorld_RaycastSingleSegmented (int,int,int,float,float,int,float);
void PhysicsWorld_SphereCast (int,int,int,float,float,int);
void PhysicsWorld_ConvexCast (int,int,int,int,int,int,int,int);
void PhysicsWorld_RemoveCachedGeometry (int,int);
int PhysicsWorld_GetGravity (int);
int PhysicsWorld_GetMaxSubSteps (int);
int PhysicsWorld_GetNumIterations (int);
int PhysicsWorld_IsUpdateEnabled (int);
int PhysicsWorld_GetInterpolation (int);
int PhysicsWorld_GetInternalEdge (int);
int PhysicsWorld_GetSplitImpulse (int);
int PhysicsWorld_GetFps (int);
float PhysicsWorld_GetMaxNetworkAngularVelocity (int);
void PhysicsWorld_AddRigidBody (int,int);
void PhysicsWorld_RemoveRigidBody (int,int);
void PhysicsWorld_AddCollisionShape (int,int);
void PhysicsWorld_RemoveCollisionShape (int,int);
void PhysicsWorld_AddConstraint (int,int);
void PhysicsWorld_RemoveConstraint (int,int);
void PhysicsWorld_DrawDebugGeometry0 (int,int);
void PhysicsWorld_SetDebugRenderer (int,int);
void PhysicsWorld_SetDebugDepthTest (int,int);
void PhysicsWorld_CleanupGeometryCache (int);
void PhysicsWorld_SetApplyingTransforms (int,int);
int PhysicsWorld_IsApplyingTransforms (int);
int PhysicsWorld_IsSimulating (int);
int RaycastVehicle_GetType (int);
int RaycastVehicle_GetTypeName (int);
int RaycastVehicle_GetTypeStatic ();
int RaycastVehicle_GetTypeNameStatic ();
void RaycastVehicle_RegisterObject (int);
void RaycastVehicle_OnSetEnabled (int);
void RaycastVehicle_ApplyAttributes (int);
void RaycastVehicle_AddWheel (int,int,int,int,float,float,int);
void RaycastVehicle_ResetSuspension (int);
void RaycastVehicle_UpdateWheelTransform (int,int,int);
void RaycastVehicle_SetSteeringValue (int,int,float);
void RaycastVehicle_SetWheelSuspensionStiffness (int,int,float);
void RaycastVehicle_SetWheelMaxSuspensionForce (int,int,float);
void RaycastVehicle_SetWheelDampingRelaxation (int,int,float);
void RaycastVehicle_SetWheelDampingCompression (int,int,float);
void RaycastVehicle_SetWheelFrictionSlip (int,int,float);
void RaycastVehicle_SetWheelRollInfluence (int,int,float);
void RaycastVehicle_SetEngineForce (int,int,float);
void RaycastVehicle_SetBrake (int,int,float);
void RaycastVehicle_SetWheelRadius (int,int,float);
void RaycastVehicle_ResetWheels (int);
void RaycastVehicle_SetWheelSkidInfo (int,int,float);
int RaycastVehicle_WheelIsGrounded (int,int);
void RaycastVehicle_SetMaxSuspensionTravel (int,int,float);
void RaycastVehicle_SetWheelDirection (int,int,int);
void RaycastVehicle_SetWheelAxle (int,int,int);
void RaycastVehicle_SetMaxSideSlipSpeed (int,float);
void RaycastVehicle_SetWheelSkidInfoCumulative (int,int,float);
void RaycastVehicle_SetInAirRPM (int,float);
void RaycastVehicle_Init (int);
void RaycastVehicle_FixedUpdate (int,float);
void RaycastVehicle_FixedPostUpdate (int,float);
void RaycastVehicle_PostUpdate (int,float);
int RaycastVehicle_GetWheelPosition (int,int);
int RaycastVehicle_GetWheelRotation (int,int);
int RaycastVehicle_GetWheelConnectionPoint (int,int);
int RaycastVehicle_GetNumWheels (int);
int RaycastVehicle_GetWheelNode (int,int);
float RaycastVehicle_GetSteeringValue (int,int);
float RaycastVehicle_GetWheelSuspensionStiffness (int,int);
float RaycastVehicle_GetWheelMaxSuspensionForce (int,int);
float RaycastVehicle_GetWheelDampingRelaxation (int,int);
float RaycastVehicle_GetWheelDampingCompression (int,int);
float RaycastVehicle_GetWheelFrictionSlip (int,int);
float RaycastVehicle_GetWheelRollInfluence (int,int);
float RaycastVehicle_GetEngineForce (int,int);
float RaycastVehicle_GetBrake (int,int);
float RaycastVehicle_GetWheelRadius (int,int);
void RaycastVehicle_SetWheelRestLength (int,int,float);
float RaycastVehicle_GetWheelRestLength (int,int);
float RaycastVehicle_GetMaxSuspensionTravel (int,int);
int RaycastVehicle_GetWheelAxle (int,int);
float RaycastVehicle_GetWheelSideSlipSpeed (int,int);
float RaycastVehicle_GetMaxSideSlipSpeed (int);
float RaycastVehicle_GetWheelSkidInfo (int,int);
int RaycastVehicle_GetWheelDirection (int,int);
float RaycastVehicle_GetWheelSkidInfoCumulative (int,int);
int RaycastVehicle_IsFrontWheel (int,int);
int RaycastVehicle_GetContactPosition (int,int);
int RaycastVehicle_GetContactNormal (int,int);
float RaycastVehicle_GetInAirRPM (int);
int RaycastVehicle_GetCoordinateSystem (int);
int RigidBody_GetType (int);
int RigidBody_GetTypeName (int);
int RigidBody_GetTypeStatic ();
int RigidBody_GetTypeNameStatic ();
int RigidBody_RigidBody (int);
void RigidBody_RegisterObject (int);
void RigidBody_ApplyAttributes (int);
void RigidBody_OnSetEnabled (int);
void RigidBody_DrawDebugGeometry (int,int,int);
void RigidBody_SetMass (int,float);
void RigidBody_SetPosition (int,int);
void RigidBody_SetRotation (int,int);
void RigidBody_SetTransform (int,int,int);
void RigidBody_SetLinearVelocity (int,int);
void RigidBody_SetLinearFactor (int,int);
void RigidBody_SetLinearRestThreshold (int,float);
void RigidBody_SetLinearDamping (int,float);
void RigidBody_SetAngularVelocity (int,int);
void RigidBody_SetAngularFactor (int,int);
void RigidBody_SetAngularRestThreshold (int,float);
void RigidBody_SetAngularDamping (int,float);
void RigidBody_SetFriction (int,float);
void RigidBody_SetAnisotropicFriction (int,int);
void RigidBody_SetRollingFriction (int,float);
void RigidBody_SetRestitution (int,float);
void RigidBody_SetContactProcessingThreshold (int,float);
void RigidBody_SetCcdRadius (int,float);
void RigidBody_SetCcdMotionThreshold (int,float);
void RigidBody_SetUseGravity (int,int);
void RigidBody_SetGravityOverride (int,int);
void RigidBody_SetKinematic (int,int);
void RigidBody_SetTrigger (int,int);
void RigidBody_SetCollisionLayer (int,int);
void RigidBody_SetCollisionMask (int,int);
void RigidBody_SetCollisionLayerAndMask (int,int,int);
void RigidBody_SetCollisionEventMode (int,int);
void RigidBody_ApplyForce (int,int);
void RigidBody_ApplyForce0 (int,int,int);
void RigidBody_ApplyTorque (int,int);
void RigidBody_ApplyImpulse (int,int);
void RigidBody_ApplyImpulse1 (int,int,int);
void RigidBody_ApplyTorqueImpulse (int,int);
void RigidBody_ResetForces (int);
void RigidBody_Activate (int);
void RigidBody_ReAddBodyToWorld (int);
void RigidBody_DisableMassUpdate (int);
void RigidBody_EnableMassUpdate (int);
int RigidBody_GetPhysicsWorld (int);
float RigidBody_GetMass (int);
int RigidBody_GetPosition (int);
int RigidBody_GetRotation (int);
int RigidBody_GetLinearVelocity (int);
int RigidBody_GetLinearFactor (int);
int RigidBody_GetVelocityAtPoint (int,int);
float RigidBody_GetLinearRestThreshold (int);
float RigidBody_GetLinearDamping (int);
int RigidBody_GetAngularVelocity (int);
int RigidBody_GetAngularFactor (int);
float RigidBody_GetAngularRestThreshold (int);
float RigidBody_GetAngularDamping (int);
float RigidBody_GetFriction (int);
int RigidBody_GetAnisotropicFriction (int);
float RigidBody_GetRollingFriction (int);
float RigidBody_GetRestitution (int);
float RigidBody_GetContactProcessingThreshold (int);
float RigidBody_GetCcdRadius (int);
float RigidBody_GetCcdMotionThreshold (int);
int RigidBody_GetUseGravity (int);
int RigidBody_GetGravityOverride (int);
int RigidBody_GetCenterOfMass (int);
int RigidBody_IsKinematic (int);
int RigidBody_IsTrigger (int);
int RigidBody_IsActive (int);
int RigidBody_GetCollisionLayer (int);
int RigidBody_GetCollisionMask (int);
int RigidBody_GetCollisionEventMode (int);
void RigidBody_ApplyWorldTransform (int,int,int);
void RigidBody_UpdateMass (int);
void RigidBody_UpdateGravity (int);
void RigidBody_AddConstraint (int,int);
void RigidBody_RemoveConstraint (int,int);
void RigidBody_ReleaseBody (int);
int BufferedSoundStream_BufferedSoundStream ();
int BufferedSoundStream_GetData (int,int,int);
void BufferedSoundStream_AddData (int,int,int);
void BufferedSoundStream_Clear (int);
int BufferedSoundStream_GetBufferNumBytes (int);
float BufferedSoundStream_GetBufferLength (int);
int Audio_GetType (int);
int Audio_GetTypeName (int);
int Audio_GetTypeStatic ();
int Audio_GetTypeNameStatic ();
int Audio_Audio (int);
int Audio_SetMode (int,int,int,int,int);
void Audio_Update (int,float);
int Audio_Play (int);
void Audio_Stop (int);
void Audio_SetMasterGain (int,int,float);
void Audio_PauseSoundType (int,int);
void Audio_ResumeSoundType (int,int);
void Audio_ResumeAll (int);
void Audio_SetListener (int,int);
void Audio_StopSound (int,int);
int Audio_GetSampleSize (int);
int Audio_GetMixRate (int);
int Audio_GetInterpolation (int);
int Audio_IsStereo (int);
int Audio_IsPlaying (int);
int Audio_IsInitialized (int);
float Audio_GetMasterGain (int,int);
int Audio_IsSoundTypePaused (int,int);
int Audio_GetListener (int);
int Audio_HasMasterGain (int,int);
void Audio_AddSoundSource (int,int);
void Audio_RemoveSoundSource (int,int);
float Audio_GetSoundSourceMasterGain (int,int);
void Audio_MixOutput (int,int,int);
int Audio_RefreshMode (int);
void Audio_Close (int);
int OggVorbisSoundStream_OggVorbisSoundStream (int);
int OggVorbisSoundStream_Seek (int,int);
int OggVorbisSoundStream_GetData (int,int,int);
int Sound_GetType (int);
int Sound_GetTypeName (int);
int Sound_GetTypeStatic ();
int Sound_GetTypeNameStatic ();
int Sound_Sound (int);
void Sound_RegisterObject (int);
int Sound_BeginLoad_File (int,int);
int Sound_BeginLoad_MemoryBuffer (int,int);
int Sound_LoadRaw_File (int,int);
int Sound_LoadRaw_MemoryBuffer (int,int);
int Sound_LoadWav_File (int,int);
int Sound_LoadWav_MemoryBuffer (int,int);
int Sound_LoadOggVorbis_File (int,int);
int Sound_LoadOggVorbis_MemoryBuffer (int,int);
void Sound_SetSize (int,int);
void Sound_SetData (int,int,int);
void Sound_SetFormat (int,int,int,int);
void Sound_SetLooped (int,int);
void Sound_SetLoop (int,int,int);
int Sound_GetDecoderStream (int);
int Sound_GetStart (int);
int Sound_GetRepeat (int);
int Sound_GetEnd (int);
float Sound_GetLength (int);
int Sound_GetDataSize (int);
int Sound_GetSampleSize (int);
float Sound_GetFrequency (int);
int Sound_GetIntFrequency (int);
int Sound_IsLooped (int);
int Sound_IsSixteenBit (int);
int Sound_IsStereo (int);
int Sound_IsCompressed (int);
void Sound_FixInterpolation (int);
int SoundListener_GetType (int);
int SoundListener_GetTypeName (int);
int SoundListener_GetTypeStatic ();
int SoundListener_GetTypeNameStatic ();
int SoundListener_SoundListener (int);
void SoundListener_RegisterObject (int);
int SoundSource_GetType (int);
int SoundSource_GetTypeName (int);
int SoundSource_GetTypeStatic ();
int SoundSource_GetTypeNameStatic ();
int SoundSource_SoundSource (int);
void SoundSource_RegisterObject (int);
void SoundSource_Seek (int,float);
void SoundSource_Play (int,int);
void SoundSource_Play0 (int,int,float);
void SoundSource_Play1 (int,int,float,float);
void SoundSource_Play2 (int,int,float,float,float);
void SoundSource_Play3 (int,int);
void SoundSource_Stop (int);
void SoundSource_SetSoundType (int,int);
void SoundSource_SetFrequency (int,float);
void SoundSource_SetGain (int,float);
void SoundSource_SetAttenuation (int,float);
void SoundSource_SetPanning (int,float);
void SoundSource_SetAutoRemoveMode (int,int);
void SoundSource_SetPlayPosition (int,int);
int SoundSource_GetSound (int);
int SoundSource_GetPlayPosition (int);
int SoundSource_GetSoundType (int);
float SoundSource_GetTimePosition (int);
float SoundSource_GetFrequency (int);
float SoundSource_GetGain (int);
float SoundSource_GetAttenuation (int);
float SoundSource_GetPanning (int);
int SoundSource_GetAutoRemoveMode (int);
int SoundSource_IsPlaying (int);
void SoundSource_Update (int,float);
void SoundSource_Mix (int,int,int,int,int,int);
void SoundSource_UpdateMasterGain (int);
void SoundSource_SetPositionAttr (int,int);
int SoundSource_GetSoundAttr (int);
void SoundSource_SetPlayingAttr (int,int);
int SoundSource_GetPositionAttr (int);
int SoundSource3D_GetType (int);
int SoundSource3D_GetTypeName (int);
int SoundSource3D_GetTypeStatic ();
int SoundSource3D_GetTypeNameStatic ();
int SoundSource3D_SoundSource3D (int);
void SoundSource3D_RegisterObject (int);
void SoundSource3D_DrawDebugGeometry (int,int,int);
void SoundSource3D_Update (int,float);
void SoundSource3D_SetDistanceAttenuation (int,float,float,float);
void SoundSource3D_SetAngleAttenuation (int,float,float);
void SoundSource3D_SetNearDistance (int,float);
void SoundSource3D_SetFarDistance (int,float);
void SoundSource3D_SetInnerAngle (int,float);
void SoundSource3D_SetOuterAngle (int,float);
void SoundSource3D_SetRolloffFactor (int,float);
void SoundSource3D_CalculateAttenuation (int);
float SoundSource3D_GetNearDistance (int);
float SoundSource3D_GetFarDistance (int);
float SoundSource3D_GetInnerAngle (int);
float SoundSource3D_GetOuterAngle (int);
float SoundSource3D_RollAngleoffFactor (int);
int SoundStream_Seek (int,int);
int SoundStream_GetData (int,int,int);
void SoundStream_SetFormat (int,int,int,int);
void SoundStream_SetStopAtEnd (int,int);
int SoundStream_GetSampleSize (int);
float SoundStream_GetFrequency (int);
int SoundStream_GetIntFrequency (int);
int SoundStream_GetStopAtEnd (int);
int SoundStream_IsSixteenBit (int);
int SoundStream_IsStereo (int);
static PinvokeImport Urho3D_imports [] = {
{"Animation_GetType", Animation_GetType},
{"Animation_GetTypeName", Animation_GetTypeName},
{"Animation_GetTypeStatic", Animation_GetTypeStatic},
{"Animation_GetTypeNameStatic", Animation_GetTypeNameStatic},
{"Animation_Animation", Animation_Animation},
{"Animation_RegisterObject", Animation_RegisterObject},
{"Animation_BeginLoad_File", Animation_BeginLoad_File},
{"Animation_BeginLoad_MemoryBuffer", Animation_BeginLoad_MemoryBuffer},
{"Animation_Save_File", Animation_Save_File},
{"Animation_Save_MemoryBuffer", Animation_Save_MemoryBuffer},
{"Animation_SetAnimationName", Animation_SetAnimationName},
{"Animation_SetLength", Animation_SetLength},
{"Animation_CreateTrack", Animation_CreateTrack},
{"Animation_RemoveTrack", Animation_RemoveTrack},
{"Animation_RemoveAllTracks", Animation_RemoveAllTracks},
{"Animation_AddTrigger_0", Animation_AddTrigger_0},
{"Animation_AddTrigger_1", Animation_AddTrigger_1},
{"Animation_AddTrigger_2", Animation_AddTrigger_2},
{"Animation_AddTrigger_3", Animation_AddTrigger_3},
{"Animation_AddTrigger_4", Animation_AddTrigger_4},
{"Animation_AddTrigger_5", Animation_AddTrigger_5},
{"Animation_AddTrigger_6", Animation_AddTrigger_6},
{"Animation_AddTrigger_7", Animation_AddTrigger_7},
{"Animation_AddTrigger_8", Animation_AddTrigger_8},
{"Animation_AddTrigger_9", Animation_AddTrigger_9},
{"Animation_AddTrigger_10", Animation_AddTrigger_10},
{"Animation_AddTrigger_11", Animation_AddTrigger_11},
{"Animation_AddTrigger_12", Animation_AddTrigger_12},
{"Animation_AddTrigger_13", Animation_AddTrigger_13},
{"Animation_AddTrigger_14", Animation_AddTrigger_14},
{"Animation_RemoveTrigger", Animation_RemoveTrigger},
{"Animation_RemoveAllTriggers", Animation_RemoveAllTriggers},
{"Animation_SetNumTriggers", Animation_SetNumTriggers},
{"Animation_Clone", Animation_Clone},
{"Animation_GetAnimationName", Animation_GetAnimationName},
{"Animation_GetAnimationNameHash", Animation_GetAnimationNameHash},
{"Animation_GetLength", Animation_GetLength},
{"Animation_GetNumTracks", Animation_GetNumTracks},
{"Animation_GetTrack", Animation_GetTrack},
{"Animation_GetTrack0", Animation_GetTrack0},
{"Animation_GetTrack1", Animation_GetTrack1},
{"Animation_GetNumTriggers", Animation_GetNumTriggers},
{"Animation_GetTrigger", Animation_GetTrigger},
{"ApplicationProxy_ApplicationProxy", ApplicationProxy_ApplicationProxy},
{"Urho_GetPlatform", Urho_GetPlatform},
{"Application_GetEngine", Application_GetEngine},
{"Application_GetType", Application_GetType},
{"Application_GetTypeName", Application_GetTypeName},
{"Application_GetTypeStatic", Application_GetTypeStatic},
{"Application_GetTypeNameStatic", Application_GetTypeNameStatic},
{"Application_Run", Application_Run},
{"Application_ErrorExit", Application_ErrorExit},
{"AttributeInfo_GetType", AttributeInfo_GetType},
{"AttributeInfo_GetName", AttributeInfo_GetName},
{"BillboardSet_GetType", BillboardSet_GetType},
{"BillboardSet_GetTypeName", BillboardSet_GetTypeName},
{"BillboardSet_GetTypeStatic", BillboardSet_GetTypeStatic},
{"BillboardSet_GetTypeNameStatic", BillboardSet_GetTypeNameStatic},
{"BillboardSet_BillboardSet", BillboardSet_BillboardSet},
{"BillboardSet_RegisterObject", BillboardSet_RegisterObject},
{"BillboardSet_GetUpdateGeometryType", BillboardSet_GetUpdateGeometryType},
{"BillboardSet_SetMaterial", BillboardSet_SetMaterial},
{"BillboardSet_SetNumBillboards", BillboardSet_SetNumBillboards},
{"BillboardSet_SetRelative", BillboardSet_SetRelative},
{"BillboardSet_SetScaled", BillboardSet_SetScaled},
{"BillboardSet_SetSorted", BillboardSet_SetSorted},
{"BillboardSet_SetFixedScreenSize", BillboardSet_SetFixedScreenSize},
{"BillboardSet_SetFaceCameraMode", BillboardSet_SetFaceCameraMode},
{"BillboardSet_SetMinAngle", BillboardSet_SetMinAngle},
{"BillboardSet_SetAnimationLodBias", BillboardSet_SetAnimationLodBias},
{"BillboardSet_Commit", BillboardSet_Commit},
{"BillboardSet_GetMaterial", BillboardSet_GetMaterial},
{"BillboardSet_GetNumBillboards", BillboardSet_GetNumBillboards},
{"BillboardSet_GetBillboard", BillboardSet_GetBillboard},
{"BillboardSet_IsRelative", BillboardSet_IsRelative},
{"BillboardSet_IsScaled", BillboardSet_IsScaled},
{"BillboardSet_IsSorted", BillboardSet_IsSorted},
{"BillboardSet_IsFixedScreenSize", BillboardSet_IsFixedScreenSize},
{"BillboardSet_GetFaceCameraMode", BillboardSet_GetFaceCameraMode},
{"BillboardSet_GetMinAngle", BillboardSet_GetMinAngle},
{"BillboardSet_GetAnimationLodBias", BillboardSet_GetAnimationLodBias},
{"BillboardSet_GetMaterialAttr", BillboardSet_GetMaterialAttr},
{"Camera_SetViewOverrideFlags", Camera_SetViewOverrideFlags},
{"Camera_GetViewOverrideFlags", Camera_GetViewOverrideFlags},
{"Camera_GetType", Camera_GetType},
{"Camera_GetTypeName", Camera_GetTypeName},
{"Camera_GetTypeStatic", Camera_GetTypeStatic},
{"Camera_GetTypeNameStatic", Camera_GetTypeNameStatic},
{"Camera_Camera", Camera_Camera},
{"Camera_RegisterObject", Camera_RegisterObject},
{"Camera_DrawDebugGeometry", Camera_DrawDebugGeometry},
{"Camera_SetNearClip", Camera_SetNearClip},
{"Camera_SetFarClip", Camera_SetFarClip},
{"Camera_SetFov", Camera_SetFov},
{"Camera_SetOrthoSize", Camera_SetOrthoSize},
{"Camera_SetOrthoSize0", Camera_SetOrthoSize0},
{"Camera_SetAspectRatio", Camera_SetAspectRatio},
{"Camera_SetFillMode", Camera_SetFillMode},
{"Camera_SetZoom", Camera_SetZoom},
{"Camera_SetLodBias", Camera_SetLodBias},
{"Camera_SetViewMask", Camera_SetViewMask},
{"Camera_SetOrthographic", Camera_SetOrthographic},
{"Camera_SetAutoAspectRatio", Camera_SetAutoAspectRatio},
{"Camera_SetProjectionOffset", Camera_SetProjectionOffset},
{"Camera_SetUseReflection", Camera_SetUseReflection},
{"Camera_SetReflectionPlane", Camera_SetReflectionPlane},
{"Camera_SetUseClipping", Camera_SetUseClipping},
{"Camera_SetClipPlane", Camera_SetClipPlane},
{"Camera_SetFlipVertical", Camera_SetFlipVertical},
{"Camera_SetProjection", Camera_SetProjection},
{"Camera_GetFarClip", Camera_GetFarClip},
{"Camera_GetNearClip", Camera_GetNearClip},
{"Camera_GetFov", Camera_GetFov},
{"Camera_GetOrthoSize", Camera_GetOrthoSize},
{"Camera_GetAspectRatio", Camera_GetAspectRatio},
{"Camera_GetZoom", Camera_GetZoom},
{"Camera_GetLodBias", Camera_GetLodBias},
{"Camera_GetViewMask", Camera_GetViewMask},
{"Camera_GetFillMode", Camera_GetFillMode},
{"Camera_IsOrthographic", Camera_IsOrthographic},
{"Camera_GetAutoAspectRatio", Camera_GetAutoAspectRatio},
{"Camera_GetFrustum", Camera_GetFrustum},
{"Camera_GetProjection", Camera_GetProjection},
{"Camera_GetGPUProjection", Camera_GetGPUProjection},
{"Camera_GetView", Camera_GetView},
{"Camera_GetHalfViewSize", Camera_GetHalfViewSize},
{"Camera_GetSplitFrustum", Camera_GetSplitFrustum},
{"Camera_GetViewSpaceFrustum", Camera_GetViewSpaceFrustum},
{"Camera_GetViewSpaceSplitFrustum", Camera_GetViewSpaceSplitFrustum},
{"Camera_GetScreenRay", Camera_GetScreenRay},
{"Camera_WorldToScreenPoint", Camera_WorldToScreenPoint},
{"Camera_ScreenToWorldPoint", Camera_ScreenToWorldPoint},
{"Camera_GetProjectionOffset", Camera_GetProjectionOffset},
{"Camera_GetUseReflection", Camera_GetUseReflection},
{"Camera_GetReflectionPlane", Camera_GetReflectionPlane},
{"Camera_GetUseClipping", Camera_GetUseClipping},
{"Camera_GetClipPlane", Camera_GetClipPlane},
{"Camera_GetFlipVertical", Camera_GetFlipVertical},
{"Camera_GetReverseCulling", Camera_GetReverseCulling},
{"Camera_GetDistance", Camera_GetDistance},
{"Camera_GetDistanceSquared", Camera_GetDistanceSquared},
{"Camera_GetLodDistance", Camera_GetLodDistance},
{"Camera_GetFaceCameraRotation", Camera_GetFaceCameraRotation},
{"Camera_GetEffectiveWorldTransform", Camera_GetEffectiveWorldTransform},
{"Camera_IsProjectionValid", Camera_IsProjectionValid},
{"Camera_SetAspectRatioInternal", Camera_SetAspectRatioInternal},
{"Camera_SetOrthoSizeAttr", Camera_SetOrthoSizeAttr},
{"Camera_SetReflectionPlaneAttr", Camera_SetReflectionPlaneAttr},
{"Camera_GetReflectionPlaneAttr", Camera_GetReflectionPlaneAttr},
{"Camera_SetClipPlaneAttr", Camera_SetClipPlaneAttr},
{"Camera_GetClipPlaneAttr", Camera_GetClipPlaneAttr},
{"Component_GetType", Component_GetType},
{"Component_GetTypeName", Component_GetTypeName},
{"Component_GetTypeStatic", Component_GetTypeStatic},
{"Component_GetTypeNameStatic", Component_GetTypeNameStatic},
{"Component_Component", Component_Component},
{"Component_RegisterObject", Component_RegisterObject},
{"Component_OnSetEnabled", Component_OnSetEnabled},
{"Component_Save_File", Component_Save_File},
{"Component_Save_MemoryBuffer", Component_Save_MemoryBuffer},
{"Component_SaveXML", Component_SaveXML},
{"Component_MarkNetworkUpdate", Component_MarkNetworkUpdate},
{"Component_DrawDebugGeometry", Component_DrawDebugGeometry},
{"Component_SetEnabled", Component_SetEnabled},
{"Component_Remove", Component_Remove},
{"Component_GetID", Component_GetID},
{"Component_IsReplicated", Component_IsReplicated},
{"Component_GetNode", Component_GetNode},
{"Component_GetScene", Component_GetScene},
{"Component_IsEnabled", Component_IsEnabled},
{"Component_IsEnabledEffective", Component_IsEnabledEffective},
{"Component_GetComponent", Component_GetComponent},
{"Component_AddReplicationState", Component_AddReplicationState},
{"Component_PrepareNetworkUpdate", Component_PrepareNetworkUpdate},
{"Component_CleanupConnection", Component_CleanupConnection},
{"Component_GetVar0", Component_GetVar0},
{"Component_SetVar_0", Component_SetVar_0},
{"Component_SetVar_1", Component_SetVar_1},
{"Component_SetVar_2", Component_SetVar_2},
{"Component_SetVar_3", Component_SetVar_3},
{"Component_SetVar_4", Component_SetVar_4},
{"Component_SetVar_5", Component_SetVar_5},
{"Component_SetVar_6", Component_SetVar_6},
{"Component_SetVar_7", Component_SetVar_7},
{"Component_SetVar_8", Component_SetVar_8},
{"Component_SetVar_9", Component_SetVar_9},
{"Component_SetVar_10", Component_SetVar_10},
{"Component_SetVar_11", Component_SetVar_11},
{"Component_SetVar_12", Component_SetVar_12},
{"Component_SetVar_13", Component_SetVar_13},
{"Component_SetVar_14", Component_SetVar_14},
{"Component_SetVar1_0", Component_SetVar1_0},
{"Component_SetVar1_1", Component_SetVar1_1},
{"Component_SetVar1_2", Component_SetVar1_2},
{"Component_SetVar1_3", Component_SetVar1_3},
{"Component_SetVar1_4", Component_SetVar1_4},
{"Component_SetVar1_5", Component_SetVar1_5},
{"Component_SetVar1_6", Component_SetVar1_6},
{"Component_SetVar1_7", Component_SetVar1_7},
{"Component_SetVar1_8", Component_SetVar1_8},
{"Component_SetVar1_9", Component_SetVar1_9},
{"Component_SetVar1_10", Component_SetVar1_10},
{"Component_SetVar1_11", Component_SetVar1_11},
{"Component_SetVar1_12", Component_SetVar1_12},
{"Component_SetVar1_13", Component_SetVar1_13},
{"Component_SetVar1_14", Component_SetVar1_14},
{"Component_HasVar", Component_HasVar},
{"Component_HasVar2", Component_HasVar2},
{"AttributeVector_GetSize", AttributeVector_GetSize},
{"AttributeVector_Attribute_GetType", AttributeVector_Attribute_GetType},
{"AttributeVector_Attribute_GetName", AttributeVector_Attribute_GetName},
{"AttributeVector_Attribute_GetMode", AttributeVector_Attribute_GetMode},
{"AttributeVector_Attribute_GetEnumNames", AttributeVector_Attribute_GetEnumNames},
{"AttributeVector_Attribute_GetDefaultValue", AttributeVector_Attribute_GetDefaultValue},
{"Context_GetAttributes", Context_GetAttributes},
{"Context_Context", Context_Context},
{"Context_CreateObject", Context_CreateObject},
{"Context_RegisterFactory", Context_RegisterFactory},
{"Context_RegisterSubsystem", Context_RegisterSubsystem},
{"Context_RemoveSubsystem", Context_RemoveSubsystem},
{"Context_RemoveAllAttributes", Context_RemoveAllAttributes},
{"Context_RequireSDL", Context_RequireSDL},
{"Context_ReleaseSDL", Context_ReleaseSDL},
{"Context_CopyBaseAttributes", Context_CopyBaseAttributes},
{"Context_GetSubsystem", Context_GetSubsystem},
{"Context_SetGlobalVar_0", Context_SetGlobalVar_0},
{"Context_SetGlobalVar_1", Context_SetGlobalVar_1},
{"Context_SetGlobalVar_2", Context_SetGlobalVar_2},
{"Context_SetGlobalVar_3", Context_SetGlobalVar_3},
{"Context_SetGlobalVar_4", Context_SetGlobalVar_4},
{"Context_SetGlobalVar_5", Context_SetGlobalVar_5},
{"Context_SetGlobalVar_6", Context_SetGlobalVar_6},
{"Context_SetGlobalVar_7", Context_SetGlobalVar_7},
{"Context_SetGlobalVar_8", Context_SetGlobalVar_8},
{"Context_SetGlobalVar_9", Context_SetGlobalVar_9},
{"Context_SetGlobalVar_10", Context_SetGlobalVar_10},
{"Context_SetGlobalVar_11", Context_SetGlobalVar_11},
{"Context_SetGlobalVar_12", Context_SetGlobalVar_12},
{"Context_SetGlobalVar_13", Context_SetGlobalVar_13},
{"Context_SetGlobalVar_14", Context_SetGlobalVar_14},
{"Context_GetEventSender", Context_GetEventSender},
{"Context_GetEventHandler", Context_GetEventHandler},
{"Context_GetTypeName", Context_GetTypeName},
{"Context_GetEventReceivers", Context_GetEventReceivers},
{"Context_GetEventReceivers0", Context_GetEventReceivers0},
{"Context_RegisterPlugin", Context_RegisterPlugin},
{"Context_RemovePlugin", Context_RemovePlugin},
{"Context_GetPlugin", Context_GetPlugin},
{"Context_PostCommandToPlugin", Context_PostCommandToPlugin},
{"Context_PopulateByCategory", Context_PopulateByCategory},
{"Context_GetObjectCountInLastPopulatedCetegory", Context_GetObjectCountInLastPopulatedCetegory},
{"Context_GetObjectInLastPopulatedCetegory", Context_GetObjectInLastPopulatedCetegory},
{"Context_ClearLastPopulatedCategory", Context_ClearLastPopulatedCategory},
{"Context_GetCetegoriesSize", Context_GetCetegoriesSize},
{"Context_GetCategory", Context_GetCategory},
{"Controls_Destroy", Controls_Destroy},
{"Controls_Create", Controls_Create},
{"Controls_GetButtons", Controls_GetButtons},
{"Controls_SetButtons", Controls_SetButtons},
{"Controls_GetYaw", Controls_GetYaw},
{"Controls_SetYaw", Controls_SetYaw},
{"Controls_GetPitch", Controls_GetPitch},
{"Controls_SetPitch", Controls_SetPitch},
{"Controls_Reset", Controls_Reset},
{"Controls_Set", Controls_Set},
{"Controls_IsDown", Controls_IsDown},
{"sqlite3_connection_finalize", sqlite3_connection_finalize},
{"sqlite3_connection_column_count", sqlite3_connection_column_count},
{"sqlite3_connection_column_name", sqlite3_connection_column_name},
{"sqlite3_connection_column_step", sqlite3_connection_column_step},
{"sqlite3_connection_column_type", sqlite3_connection_column_type},
{"sqlite3_connection_column_int", sqlite3_connection_column_int},
{"sqlite3_connection_column_double", sqlite3_connection_column_double},
{"sqlite3_connection_column_decltype", sqlite3_connection_column_decltype},
{"sqlite3_connection_column_text", sqlite3_connection_column_text},
{"sqlite3_connection_prepare", sqlite3_connection_prepare},
{"sqlite3_connection_changes", sqlite3_connection_changes},
{"DbConnection_GetSQLite3Implementation", DbConnection_GetSQLite3Implementation},
{"DbConnection_GetType", DbConnection_GetType},
{"DbConnection_GetTypeName", DbConnection_GetTypeName},
{"DbConnection_GetTypeStatic", DbConnection_GetTypeStatic},
{"DbConnection_GetTypeNameStatic", DbConnection_GetTypeNameStatic},
{"DbConnection_DbConnection", DbConnection_DbConnection},
{"DbConnection_Finalize", DbConnection_Finalize},
{"DbConnection_GetConnectionString", DbConnection_GetConnectionString},
{"DbConnection_IsConnected", DbConnection_IsConnected},
{"Dynamic_CreateBuffer", Dynamic_CreateBuffer},
{"Dynamic_CreateFromType", Dynamic_CreateFromType},
{"Dynamic_CreateVariant", Dynamic_CreateVariant},
{"Dynamic_CreateBool", Dynamic_CreateBool},
{"Dynamic_CreateInt", Dynamic_CreateInt},
{"Dynamic_CreateUInt", Dynamic_CreateUInt},
{"Dynamic_CreateInt64", Dynamic_CreateInt64},
{"Dynamic_CreateUInt64", Dynamic_CreateUInt64},
{"Dynamic_CreateFloat", Dynamic_CreateFloat},
{"Dynamic_CreateVector2", Dynamic_CreateVector2},
{"Dynamic_CreateVector3", Dynamic_CreateVector3},
{"Dynamic_CreateVector4", Dynamic_CreateVector4},
{"Dynamic_CreateQuaternion", Dynamic_CreateQuaternion},
{"Dynamic_CreateColor", Dynamic_CreateColor},
{"Dynamic_CreateDouble", Dynamic_CreateDouble},
{"Dynamic_CreateString", Dynamic_CreateString},
{"Dynamic_GetString", Dynamic_GetString},
{"Dynamic_CreateIntVector2", Dynamic_CreateIntVector2},
{"Dynamic_CreateIntVector3", Dynamic_CreateIntVector3},
{"Dynamic_CreateIntRect", Dynamic_CreateIntRect},
{"Dynamic_CreateRect", Dynamic_CreateRect},
{"Dynamic_CreateMatrix3", Dynamic_CreateMatrix3},
{"Dynamic_GetMatrix3", Dynamic_GetMatrix3},
{"Dynamic_CreateMatrix4", Dynamic_CreateMatrix4},
{"Dynamic_GetMatrix4", Dynamic_GetMatrix4},
{"Dynamic_CreateMatrix3x4", Dynamic_CreateMatrix3x4},
{"Dynamic_GetMatrix3x4", Dynamic_GetMatrix3x4},
{"Dynamic_Dispose", Dynamic_Dispose},
{"Dynamic_GetBuffer", Dynamic_GetBuffer},
{"Dynamic_CreateResourceRef", Dynamic_CreateResourceRef},
{"Dynamic_GetResourceRef", Dynamic_GetResourceRef},
{"Dynamic_CreateResourceRefList", Dynamic_CreateResourceRefList},
{"Dynamic_ResourceRefList_AddName", Dynamic_ResourceRefList_AddName},
{"Dynamic_CreateVariantVector", Dynamic_CreateVariantVector},
{"Dynamic_VariantVector_AddVariant", Dynamic_VariantVector_AddVariant},
{"Dynamic_GetRetVariant", Dynamic_GetRetVariant},
{"Frustum_GetVertices", Frustum_GetVertices},
{"Frustum_GetPlanes", Frustum_GetPlanes},
{"Frustum_Frustum", Frustum_Frustum},
{"Frustum_Frustum0", Frustum_Frustum0},
{"Frustum_Define", Frustum_Define},
{"Frustum_Define1", Frustum_Define1},
{"Frustum_Define2", Frustum_Define2},
{"Frustum_Define3", Frustum_Define3},
{"Frustum_DefineOrtho", Frustum_DefineOrtho},
{"Frustum_DefineSplit", Frustum_DefineSplit},
{"Frustum_Transform", Frustum_Transform},
{"Frustum_Transform4", Frustum_Transform4},
{"Frustum_IsInside", Frustum_IsInside},
{"Frustum_IsInside5", Frustum_IsInside5},
{"Frustum_IsInsideFast", Frustum_IsInsideFast},
{"Frustum_IsInside6", Frustum_IsInside6},
{"Frustum_IsInsideFast7", Frustum_IsInsideFast7},
{"Frustum_Distance", Frustum_Distance},
{"Frustum_Transformed", Frustum_Transformed},
{"Frustum_Transformed8", Frustum_Transformed8},
{"Frustum_Projected", Frustum_Projected},
{"Frustum_UpdatePlanes", Frustum_UpdatePlanes},
{"GPUObject_GPUObject", GPUObject_GPUObject},
{"GPUObject_OnDeviceLost", GPUObject_OnDeviceLost},
{"GPUObject_OnDeviceReset", GPUObject_OnDeviceReset},
{"GPUObject_Release", GPUObject_Release},
{"GPUObject_ClearDataLost", GPUObject_ClearDataLost},
{"GPUObject_GetGraphics", GPUObject_GetGraphics},
{"GPUObject_GetGPUObject", GPUObject_GetGPUObject},
{"GPUObject_GetGPUObjectName", GPUObject_GetGPUObjectName},
{"GPUObject_IsDataLost", GPUObject_IsDataLost},
{"GPUObject_HasPendingData", GPUObject_HasPendingData},
{"Graphics_GetSdlWindow", Graphics_GetSdlWindow},
{"Graphics_GetMultiSampleLevels", Graphics_GetMultiSampleLevels},
{"Graphics_GetType", Graphics_GetType},
{"Graphics_GetTypeName", Graphics_GetTypeName},
{"Graphics_GetTypeStatic", Graphics_GetTypeStatic},
{"Graphics_GetTypeNameStatic", Graphics_GetTypeNameStatic},
{"Graphics_Graphics", Graphics_Graphics},
{"Graphics_SetExternalWindow", Graphics_SetExternalWindow},
{"Graphics_SetWindowTitle", Graphics_SetWindowTitle},
{"Graphics_SetWindowIcon", Graphics_SetWindowIcon},
{"Graphics_SetWindowPosition", Graphics_SetWindowPosition},
{"Graphics_SetWindowPosition0", Graphics_SetWindowPosition0},
{"Graphics_SetScreenMode", Graphics_SetScreenMode},
{"Graphics_SetMode", Graphics_SetMode},
{"Graphics_SetMode1", Graphics_SetMode1},
{"Graphics_SetSRGB", Graphics_SetSRGB},
{"Graphics_SetDither", Graphics_SetDither},
{"Graphics_SetFlushGPU", Graphics_SetFlushGPU},
{"Graphics_SetOrientations", Graphics_SetOrientations},
{"Graphics_ToggleFullscreen", Graphics_ToggleFullscreen},
{"Graphics_Close", Graphics_Close},
{"Graphics_TakeScreenShot", Graphics_TakeScreenShot},
{"Graphics_BeginFrame", Graphics_BeginFrame},
{"Graphics_EndFrame", Graphics_EndFrame},
{"Graphics_ResolveToTexture", Graphics_ResolveToTexture},
{"Graphics_ResolveToTexture2", Graphics_ResolveToTexture2},
{"Graphics_ResolveToTexture3", Graphics_ResolveToTexture3},
{"Graphics_Draw", Graphics_Draw},
{"Graphics_Draw4", Graphics_Draw4},
{"Graphics_Draw5", Graphics_Draw5},
{"Graphics_DrawInstanced", Graphics_DrawInstanced},
{"Graphics_DrawInstanced6", Graphics_DrawInstanced6},
{"Graphics_SetVertexBuffer", Graphics_SetVertexBuffer},
{"Graphics_SetIndexBuffer", Graphics_SetIndexBuffer},
{"Graphics_SetShaders", Graphics_SetShaders},
{"Graphics_SetShaderParameter", Graphics_SetShaderParameter},
{"Graphics_SetShaderParameter7", Graphics_SetShaderParameter7},
{"Graphics_SetShaderParameter8", Graphics_SetShaderParameter8},
{"Graphics_SetShaderParameter9", Graphics_SetShaderParameter9},
{"Graphics_SetShaderParameter10", Graphics_SetShaderParameter10},
{"Graphics_SetShaderParameter11", Graphics_SetShaderParameter11},
{"Graphics_SetShaderParameter12", Graphics_SetShaderParameter12},
{"Graphics_SetShaderParameter13", Graphics_SetShaderParameter13},
{"Graphics_SetShaderParameter14", Graphics_SetShaderParameter14},
{"Graphics_SetShaderParameter15", Graphics_SetShaderParameter15},
{"Graphics_SetShaderParameter16", Graphics_SetShaderParameter16},
{"Graphics_NeedParameterUpdate", Graphics_NeedParameterUpdate},
{"Graphics_HasShaderParameter", Graphics_HasShaderParameter},
{"Graphics_HasTextureUnit", Graphics_HasTextureUnit},
{"Graphics_ClearParameterSource", Graphics_ClearParameterSource},
{"Graphics_ClearParameterSources", Graphics_ClearParameterSources},
{"Graphics_ClearTransformSources", Graphics_ClearTransformSources},
{"Graphics_SetTexture", Graphics_SetTexture},
{"Graphics_SetTextureParametersDirty", Graphics_SetTextureParametersDirty},
{"Graphics_SetDefaultTextureFilterMode", Graphics_SetDefaultTextureFilterMode},
{"Graphics_SetDefaultTextureAnisotropy", Graphics_SetDefaultTextureAnisotropy},
{"Graphics_ResetRenderTargets", Graphics_ResetRenderTargets},
{"Graphics_ResetRenderTarget", Graphics_ResetRenderTarget},
{"Graphics_ResetDepthStencil", Graphics_ResetDepthStencil},
{"Graphics_SetRenderTarget", Graphics_SetRenderTarget},
{"Graphics_SetRenderTarget17", Graphics_SetRenderTarget17},
{"Graphics_SetDepthStencil", Graphics_SetDepthStencil},
{"Graphics_SetDepthStencil18", Graphics_SetDepthStencil18},
{"Graphics_SetViewport", Graphics_SetViewport},
{"Graphics_SetBlendMode", Graphics_SetBlendMode},
{"Graphics_SetColorWrite", Graphics_SetColorWrite},
{"Graphics_SetCullMode", Graphics_SetCullMode},
{"Graphics_SetDepthBias", Graphics_SetDepthBias},
{"Graphics_SetDepthTest", Graphics_SetDepthTest},
{"Graphics_SetDepthWrite", Graphics_SetDepthWrite},
{"Graphics_SetFillMode", Graphics_SetFillMode},
{"Graphics_SetLineAntiAlias", Graphics_SetLineAntiAlias},
{"Graphics_SetScissorTest", Graphics_SetScissorTest},
{"Graphics_SetStencilTest", Graphics_SetStencilTest},
{"Graphics_SetClipPlane", Graphics_SetClipPlane},
{"Graphics_BeginDumpShaders", Graphics_BeginDumpShaders},
{"Graphics_EndDumpShaders", Graphics_EndDumpShaders},
{"Graphics_PrecacheShaders_File", Graphics_PrecacheShaders_File},
{"Graphics_PrecacheShaders_MemoryBuffer", Graphics_PrecacheShaders_MemoryBuffer},
{"Graphics_SetShaderCacheDir", Graphics_SetShaderCacheDir},
{"Graphics_IsInitialized", Graphics_IsInitialized},
{"Graphics_GetImpl", Graphics_GetImpl},
{"Graphics_GetExternalWindow", Graphics_GetExternalWindow},
{"Graphics_GetWindowTitle", Graphics_GetWindowTitle},
{"Graphics_GetApiName", Graphics_GetApiName},
{"Graphics_GetWindowPosition", Graphics_GetWindowPosition},
{"Graphics_GetWidth", Graphics_GetWidth},
{"Graphics_GetHeight", Graphics_GetHeight},
{"Graphics_GetMultiSample", Graphics_GetMultiSample},
{"Graphics_GetSize", Graphics_GetSize},
{"Graphics_GetFullscreen", Graphics_GetFullscreen},
{"Graphics_GetBorderless", Graphics_GetBorderless},
{"Graphics_GetResizable", Graphics_GetResizable},
{"Graphics_GetHighDPI", Graphics_GetHighDPI},
{"Graphics_GetVSync", Graphics_GetVSync},
{"Graphics_GetRefreshRate", Graphics_GetRefreshRate},
{"Graphics_GetMonitor", Graphics_GetMonitor},
{"Graphics_GetTripleBuffer", Graphics_GetTripleBuffer},
{"Graphics_GetSRGB", Graphics_GetSRGB},
{"Graphics_GetDither", Graphics_GetDither},
{"Graphics_GetFlushGPU", Graphics_GetFlushGPU},
{"Graphics_GetOrientations", Graphics_GetOrientations},
{"Graphics_IsDeviceLost", Graphics_IsDeviceLost},
{"Graphics_GetNumPrimitives", Graphics_GetNumPrimitives},
{"Graphics_GetNumBatches", Graphics_GetNumBatches},
{"Graphics_GetDummyColorFormat", Graphics_GetDummyColorFormat},
{"Graphics_GetShadowMapFormat", Graphics_GetShadowMapFormat},
{"Graphics_GetHiresShadowMapFormat", Graphics_GetHiresShadowMapFormat},
{"Graphics_GetInstancingSupport", Graphics_GetInstancingSupport},
{"Graphics_GetDrawBuffersSupport", Graphics_GetDrawBuffersSupport},
{"Graphics_GetLightPrepassSupport", Graphics_GetLightPrepassSupport},
{"Graphics_GetDeferredSupport", Graphics_GetDeferredSupport},
{"Graphics_GetHardwareShadowSupport", Graphics_GetHardwareShadowSupport},
{"Graphics_GetReadableDepthSupport", Graphics_GetReadableDepthSupport},
{"Graphics_GetSRGBSupport", Graphics_GetSRGBSupport},
{"Graphics_GetSRGBWriteSupport", Graphics_GetSRGBWriteSupport},
{"Graphics_FindBestResolutionIndex", Graphics_FindBestResolutionIndex},
{"Graphics_GetDesktopResolution", Graphics_GetDesktopResolution},
{"Graphics_GetMonitorCount", Graphics_GetMonitorCount},
{"Graphics_GetCurrentMonitor", Graphics_GetCurrentMonitor},
{"Graphics_GetMaximized", Graphics_GetMaximized},
{"Graphics_GetDisplayDPI", Graphics_GetDisplayDPI},
{"Graphics_GetFormat", Graphics_GetFormat},
{"Graphics_GetShader", Graphics_GetShader},
{"Graphics_GetVertexBuffer", Graphics_GetVertexBuffer},
{"Graphics_GetIndexBuffer", Graphics_GetIndexBuffer},
{"Graphics_GetVertexShader", Graphics_GetVertexShader},
{"Graphics_GetPixelShader", Graphics_GetPixelShader},
{"Graphics_GetTextureUnit", Graphics_GetTextureUnit},
{"Graphics_GetTextureUnitName", Graphics_GetTextureUnitName},
{"Graphics_GetTexture", Graphics_GetTexture},
{"Graphics_GetDefaultTextureFilterMode", Graphics_GetDefaultTextureFilterMode},
{"Graphics_GetDefaultTextureAnisotropy", Graphics_GetDefaultTextureAnisotropy},
{"Graphics_GetRenderTarget", Graphics_GetRenderTarget},
{"Graphics_GetDepthStencil", Graphics_GetDepthStencil},
{"Graphics_GetViewport", Graphics_GetViewport},
{"Graphics_GetBlendMode", Graphics_GetBlendMode},
{"Graphics_GetAlphaToCoverage", Graphics_GetAlphaToCoverage},
{"Graphics_GetColorWrite", Graphics_GetColorWrite},
{"Graphics_GetCullMode", Graphics_GetCullMode},
{"Graphics_GetDepthConstantBias", Graphics_GetDepthConstantBias},
{"Graphics_GetDepthSlopeScaledBias", Graphics_GetDepthSlopeScaledBias},
{"Graphics_GetDepthTest", Graphics_GetDepthTest},
{"Graphics_GetDepthWrite", Graphics_GetDepthWrite},
{"Graphics_GetFillMode", Graphics_GetFillMode},
{"Graphics_GetLineAntiAlias", Graphics_GetLineAntiAlias},
{"Graphics_GetStencilTest", Graphics_GetStencilTest},
{"Graphics_GetScissorTest", Graphics_GetScissorTest},
{"Graphics_GetScissorRect", Graphics_GetScissorRect},
{"Graphics_GetStencilTestMode", Graphics_GetStencilTestMode},
{"Graphics_GetStencilPass", Graphics_GetStencilPass},
{"Graphics_GetStencilFail", Graphics_GetStencilFail},
{"Graphics_GetStencilZFail", Graphics_GetStencilZFail},
{"Graphics_GetStencilRef", Graphics_GetStencilRef},
{"Graphics_GetStencilCompareMask", Graphics_GetStencilCompareMask},
{"Graphics_GetStencilWriteMask", Graphics_GetStencilWriteMask},
{"Graphics_GetUseClipPlane", Graphics_GetUseClipPlane},
{"Graphics_GetShaderCacheDir", Graphics_GetShaderCacheDir},
{"Graphics_GetRenderTargetDimensions", Graphics_GetRenderTargetDimensions},
{"Graphics_OnWindowResized", Graphics_OnWindowResized},
{"Graphics_OnWindowMoved", Graphics_OnWindowMoved},
{"Graphics_Maximize", Graphics_Maximize},
{"Graphics_Minimize", Graphics_Minimize},
{"Graphics_Raise", Graphics_Raise},
{"Graphics_AddGPUObject", Graphics_AddGPUObject},
{"Graphics_RemoveGPUObject", Graphics_RemoveGPUObject},
{"Graphics_ReserveScratchBuffer", Graphics_ReserveScratchBuffer},
{"Graphics_FreeScratchBuffer", Graphics_FreeScratchBuffer},
{"Graphics_CleanupScratchBuffers", Graphics_CleanupScratchBuffers},
{"Graphics_GetRendererName", Graphics_GetRendererName},
{"Graphics_GetVersionString", Graphics_GetVersionString},
{"Graphics_glOESStandardDerivativesSupport", Graphics_glOESStandardDerivativesSupport},
{"Graphics_clipDistanceEXTSupport", Graphics_clipDistanceEXTSupport},
{"Graphics_clipDistanceAPPLESupport", Graphics_clipDistanceAPPLESupport},
{"Graphics_GetAlphaFormat", Graphics_GetAlphaFormat},
{"Graphics_GetLuminanceFormat", Graphics_GetLuminanceFormat},
{"Graphics_GetLuminanceAlphaFormat", Graphics_GetLuminanceAlphaFormat},
{"Graphics_GetRGBFormat", Graphics_GetRGBFormat},
{"Graphics_GetRGBAFormat", Graphics_GetRGBAFormat},
{"Graphics_GetRGBA16Format", Graphics_GetRGBA16Format},
{"Graphics_GetRGBAFloat16Format", Graphics_GetRGBAFloat16Format},
{"Graphics_GetRGBAFloat32Format", Graphics_GetRGBAFloat32Format},
{"Graphics_GetRG16Format", Graphics_GetRG16Format},
{"Graphics_GetRGFloat16Format", Graphics_GetRGFloat16Format},
{"Graphics_GetRGFloat32Format", Graphics_GetRGFloat32Format},
{"Graphics_GetFloat16Format", Graphics_GetFloat16Format},
{"Graphics_GetFloat32Format", Graphics_GetFloat32Format},
{"Graphics_GetLinearDepthFormat", Graphics_GetLinearDepthFormat},
{"Graphics_GetDepthStencilFormat", Graphics_GetDepthStencilFormat},
{"Graphics_GetReadableDepthFormat", Graphics_GetReadableDepthFormat},
{"Graphics_GetFormat19", Graphics_GetFormat19},
{"Graphics_GetPixelUVOffset", Graphics_GetPixelUVOffset},
{"Graphics_GetMaxBones", Graphics_GetMaxBones},
{"IndexBuffer_CastToGPUObject", IndexBuffer_CastToGPUObject},
{"IndexBuffer_GetType", IndexBuffer_GetType},
{"IndexBuffer_GetTypeName", IndexBuffer_GetTypeName},
{"IndexBuffer_GetTypeStatic", IndexBuffer_GetTypeStatic},
{"IndexBuffer_GetTypeNameStatic", IndexBuffer_GetTypeNameStatic},
{"IndexBuffer_IndexBuffer", IndexBuffer_IndexBuffer},
{"IndexBuffer_OnDeviceLost", IndexBuffer_OnDeviceLost},
{"IndexBuffer_Release", IndexBuffer_Release},
{"IndexBuffer_SetShadowed", IndexBuffer_SetShadowed},
{"IndexBuffer_SetSize", IndexBuffer_SetSize},
{"IndexBuffer_SetData", IndexBuffer_SetData},
{"IndexBuffer_SetDataRange", IndexBuffer_SetDataRange},
{"IndexBuffer_Lock", IndexBuffer_Lock},
{"IndexBuffer_Unlock", IndexBuffer_Unlock},
{"IndexBuffer_IsShadowed", IndexBuffer_IsShadowed},
{"IndexBuffer_IsDynamic", IndexBuffer_IsDynamic},
{"IndexBuffer_IsLocked", IndexBuffer_IsLocked},
{"IndexBuffer_GetIndexCount", IndexBuffer_GetIndexCount},
{"IndexBuffer_GetIndexSize", IndexBuffer_GetIndexSize},
{"IndexBuffer_GetShadowData", IndexBuffer_GetShadowData},
{"Input_GetType", Input_GetType},
{"Input_GetTypeName", Input_GetTypeName},
{"Input_GetTypeStatic", Input_GetTypeStatic},
{"Input_GetTypeNameStatic", Input_GetTypeNameStatic},
{"Input_Input", Input_Input},
{"Input_Update", Input_Update},
{"Input_SetToggleFullscreen", Input_SetToggleFullscreen},
{"Input_SetMouseVisible", Input_SetMouseVisible},
{"Input_ResetMouseVisible", Input_ResetMouseVisible},
{"Input_SetMouseGrabbed", Input_SetMouseGrabbed},
{"Input_ResetMouseGrabbed", Input_ResetMouseGrabbed},
{"Input_SetMouseMode", Input_SetMouseMode},
{"Input_ResetMouseMode", Input_ResetMouseMode},
{"Input_AddScreenJoystick", Input_AddScreenJoystick},
{"Input_RemoveScreenJoystick", Input_RemoveScreenJoystick},
{"Input_SetScreenJoystickVisible", Input_SetScreenJoystickVisible},
{"Input_SetScreenKeyboardVisible", Input_SetScreenKeyboardVisible},
{"Input_SetTouchEmulation", Input_SetTouchEmulation},
{"Input_RecordGesture", Input_RecordGesture},
{"Input_SaveGestures_File", Input_SaveGestures_File},
{"Input_SaveGestures_MemoryBuffer", Input_SaveGestures_MemoryBuffer},
{"Input_SaveGesture_File", Input_SaveGesture_File},
{"Input_SaveGesture_MemoryBuffer", Input_SaveGesture_MemoryBuffer},
{"Input_LoadGestures_File", Input_LoadGestures_File},
{"Input_LoadGestures_MemoryBuffer", Input_LoadGestures_MemoryBuffer},
{"Input_RemoveGesture", Input_RemoveGesture},
{"Input_RemoveAllGestures", Input_RemoveAllGestures},
{"Input_SetMousePosition", Input_SetMousePosition},
{"Input_CenterMousePosition", Input_CenterMousePosition},
{"Input_GetKeyFromName", Input_GetKeyFromName},
{"Input_GetKeyFromScancode", Input_GetKeyFromScancode},
{"Input_GetKeyName", Input_GetKeyName},
{"Input_GetScancodeFromKey", Input_GetScancodeFromKey},
{"Input_GetScancodeFromName", Input_GetScancodeFromName},
{"Input_GetScancodeName", Input_GetScancodeName},
{"Input_GetKeyDown", Input_GetKeyDown},
{"Input_GetKeyPress", Input_GetKeyPress},
{"Input_GetScancodeDown", Input_GetScancodeDown},
{"Input_GetScancodePress", Input_GetScancodePress},
{"Input_GetQualifierDown", Input_GetQualifierDown},
{"Input_GetQualifierPress", Input_GetQualifierPress},
{"Input_GetMousePosition", Input_GetMousePosition},
{"Input_GetMouseMove", Input_GetMouseMove},
{"Input_GetMouseMoveX", Input_GetMouseMoveX},
{"Input_GetMouseMoveY", Input_GetMouseMoveY},
{"Input_GetMouseMoveWheel", Input_GetMouseMoveWheel},
{"Input_GetInputScale", Input_GetInputScale},
{"Input_GetNumTouches", Input_GetNumTouches},
{"Input_GetTouch", Input_GetTouch},
{"Input_GetNumJoysticks", Input_GetNumJoysticks},
{"Input_GetJoystick", Input_GetJoystick},
{"Input_GetJoystickByIndex", Input_GetJoystickByIndex},
{"Input_GetJoystickByName", Input_GetJoystickByName},
{"Input_GetToggleFullscreen", Input_GetToggleFullscreen},
{"Input_IsScreenJoystickVisible", Input_IsScreenJoystickVisible},
{"Input_GetScreenKeyboardSupport", Input_GetScreenKeyboardSupport},
{"Input_IsScreenKeyboardVisible", Input_IsScreenKeyboardVisible},
{"Input_GetTouchEmulation", Input_GetTouchEmulation},
{"Input_IsMouseVisible", Input_IsMouseVisible},
{"Input_IsMouseGrabbed", Input_IsMouseGrabbed},
{"Input_IsMouseLocked", Input_IsMouseLocked},
{"Input_GetMouseMode", Input_GetMouseMode},
{"Input_HasFocus", Input_HasFocus},
{"Input_IsMinimized", Input_IsMinimized},
{"Input_MapCtrlQualifierToCommandKey", Input_MapCtrlQualifierToCommandKey},
{"Input_IsMapCtrlQualifierToCommandKey", Input_IsMapCtrlQualifierToCommandKey},
{"Input_GetMouseButtonDown", Input_GetMouseButtonDown},
{"Input_GetMouseButtonPress", Input_GetMouseButtonPress},
{"KinematicCharacterController_GetTransform", KinematicCharacterController_GetTransform},
{"KinematicCharacterController_GetType", KinematicCharacterController_GetType},
{"KinematicCharacterController_GetTypeName", KinematicCharacterController_GetTypeName},
{"KinematicCharacterController_GetTypeStatic", KinematicCharacterController_GetTypeStatic},
{"KinematicCharacterController_GetTypeNameStatic", KinematicCharacterController_GetTypeNameStatic},
{"KinematicCharacterController_KinematicCharacterController", KinematicCharacterController_KinematicCharacterController},
{"KinematicCharacterController_RegisterObject", KinematicCharacterController_RegisterObject},
{"KinematicCharacterController_ApplyAttributes", KinematicCharacterController_ApplyAttributes},
{"KinematicCharacterController_GetPosition", KinematicCharacterController_GetPosition},
{"KinematicCharacterController_GetRotation", KinematicCharacterController_GetRotation},
{"KinematicCharacterController_SetTransform", KinematicCharacterController_SetTransform},
{"KinematicCharacterController_SetCollisionLayer", KinematicCharacterController_SetCollisionLayer},
{"KinematicCharacterController_GetCollisionLayer", KinematicCharacterController_GetCollisionLayer},
{"KinematicCharacterController_SetCollisionMask", KinematicCharacterController_SetCollisionMask},
{"KinematicCharacterController_GetCollisionMask", KinematicCharacterController_GetCollisionMask},
{"KinematicCharacterController_SetCollisionLayerAndMask", KinematicCharacterController_SetCollisionLayerAndMask},
{"KinematicCharacterController_SetGravity", KinematicCharacterController_SetGravity},
{"KinematicCharacterController_GetGravity", KinematicCharacterController_GetGravity},
{"KinematicCharacterController_SetLinearDamping", KinematicCharacterController_SetLinearDamping},
{"KinematicCharacterController_GetLinearDamping", KinematicCharacterController_GetLinearDamping},
{"KinematicCharacterController_SetAngularDamping", KinematicCharacterController_SetAngularDamping},
{"KinematicCharacterController_GetAngularDamping", KinematicCharacterController_GetAngularDamping},
{"KinematicCharacterController_SetStepHeight", KinematicCharacterController_SetStepHeight},
{"KinematicCharacterController_GetStepHeight", KinematicCharacterController_GetStepHeight},
{"KinematicCharacterController_SetMaxJumpHeight", KinematicCharacterController_SetMaxJumpHeight},
{"KinematicCharacterController_GetMaxJumpHeight", KinematicCharacterController_GetMaxJumpHeight},
{"KinematicCharacterController_SetFallSpeed", KinematicCharacterController_SetFallSpeed},
{"KinematicCharacterController_GetFallSpeed", KinematicCharacterController_GetFallSpeed},
{"KinematicCharacterController_SetJumpSpeed", KinematicCharacterController_SetJumpSpeed},
{"KinematicCharacterController_GetJumpSpeed", KinematicCharacterController_GetJumpSpeed},
{"KinematicCharacterController_SetMaxSlope", KinematicCharacterController_SetMaxSlope},
{"KinematicCharacterController_GetMaxSlope", KinematicCharacterController_GetMaxSlope},
{"KinematicCharacterController_SetWalkDirection", KinematicCharacterController_SetWalkDirection},
{"KinematicCharacterController_OnGround", KinematicCharacterController_OnGround},
{"KinematicCharacterController_Jump", KinematicCharacterController_Jump},
{"KinematicCharacterController_ApplyImpulse", KinematicCharacterController_ApplyImpulse},
{"KinematicCharacterController_CanJump", KinematicCharacterController_CanJump},
{"KinematicCharacterController_SetAngularVelocity", KinematicCharacterController_SetAngularVelocity},
{"KinematicCharacterController_GetAngularVelocity", KinematicCharacterController_GetAngularVelocity},
{"KinematicCharacterController_SetLinearVelocity", KinematicCharacterController_SetLinearVelocity},
{"KinematicCharacterController_GetLinearVelocity", KinematicCharacterController_GetLinearVelocity},
{"KinematicCharacterController_Warp", KinematicCharacterController_Warp},
{"KinematicCharacterController_DrawDebugGeometry", KinematicCharacterController_DrawDebugGeometry},
{"LogicComponent_GetType", LogicComponent_GetType},
{"LogicComponent_GetTypeName", LogicComponent_GetTypeName},
{"LogicComponent_GetTypeStatic", LogicComponent_GetTypeStatic},
{"LogicComponent_GetTypeNameStatic", LogicComponent_GetTypeNameStatic},
{"LogicComponent_LogicComponent", LogicComponent_LogicComponent},
{"LogicComponent_OnSetEnabled", LogicComponent_OnSetEnabled},
{"LogicComponent_Start", LogicComponent_Start},
{"LogicComponent_DelayedStart", LogicComponent_DelayedStart},
{"LogicComponent_Stop", LogicComponent_Stop},
{"LogicComponent_Update", LogicComponent_Update},
{"LogicComponent_PostUpdate", LogicComponent_PostUpdate},
{"LogicComponent_FixedUpdate", LogicComponent_FixedUpdate},
{"LogicComponent_FixedPostUpdate", LogicComponent_FixedPostUpdate},
{"LogicComponent_IsDelayedStartCalled", LogicComponent_IsDelayedStartCalled},
{"Material_GetShaderParameterKeysSize", Material_GetShaderParameterKeysSize},
{"Material_GetShaderParameterGetKeys", Material_GetShaderParameterGetKeys},
{"Material_GetMaterialShaderParameterPtr", Material_GetMaterialShaderParameterPtr},
{"Material_GetShaderParameterColor", Material_GetShaderParameterColor},
{"Material_GetType", Material_GetType},
{"Material_GetTypeName", Material_GetTypeName},
{"Material_GetTypeStatic", Material_GetTypeStatic},
{"Material_GetTypeNameStatic", Material_GetTypeNameStatic},
{"Material_Material", Material_Material},
{"Material_RegisterObject", Material_RegisterObject},
{"Material_BeginLoad_File", Material_BeginLoad_File},
{"Material_BeginLoad_MemoryBuffer", Material_BeginLoad_MemoryBuffer},
{"Material_EndLoad", Material_EndLoad},
{"Material_Save_File", Material_Save_File},
{"Material_Save_MemoryBuffer", Material_Save_MemoryBuffer},
{"Material_Load", Material_Load},
{"Material_Save0", Material_Save0},
{"Material_SetNumTechniques", Material_SetNumTechniques},
{"Material_SetTechnique", Material_SetTechnique},
{"Material_SetVertexShaderDefines", Material_SetVertexShaderDefines},
{"Material_SetPixelShaderDefines", Material_SetPixelShaderDefines},
{"Material_SetShaderParameter_0", Material_SetShaderParameter_0},
{"Material_SetShaderParameter_1", Material_SetShaderParameter_1},
{"Material_SetShaderParameter_2", Material_SetShaderParameter_2},
{"Material_SetShaderParameter_3", Material_SetShaderParameter_3},
{"Material_SetShaderParameter_4", Material_SetShaderParameter_4},
{"Material_SetShaderParameter_5", Material_SetShaderParameter_5},
{"Material_SetShaderParameter_6", Material_SetShaderParameter_6},
{"Material_SetShaderParameter_7", Material_SetShaderParameter_7},
{"Material_SetShaderParameter_8", Material_SetShaderParameter_8},
{"Material_SetShaderParameter_9", Material_SetShaderParameter_9},
{"Material_SetShaderParameter_10", Material_SetShaderParameter_10},
{"Material_SetShaderParameter_11", Material_SetShaderParameter_11},
{"Material_SetShaderParameter_12", Material_SetShaderParameter_12},
{"Material_SetShaderParameter_13", Material_SetShaderParameter_13},
{"Material_SetShaderParameter_14", Material_SetShaderParameter_14},
{"Material_SetShaderParameterAnimation", Material_SetShaderParameterAnimation},
{"Material_SetShaderParameterAnimationWrapMode", Material_SetShaderParameterAnimationWrapMode},
{"Material_SetShaderParameterAnimationSpeed", Material_SetShaderParameterAnimationSpeed},
{"Material_SetTexture", Material_SetTexture},
{"Material_SetUVTransform", Material_SetUVTransform},
{"Material_SetUVTransform1", Material_SetUVTransform1},
{"Material_SetCullMode", Material_SetCullMode},
{"Material_SetShadowCullMode", Material_SetShadowCullMode},
{"Material_SetFillMode", Material_SetFillMode},
{"Material_SetDepthBias", Material_SetDepthBias},
{"Material_SetAlphaToCoverage", Material_SetAlphaToCoverage},
{"Material_SetLineAntiAlias", Material_SetLineAntiAlias},
{"Material_SetRenderOrder", Material_SetRenderOrder},
{"Material_SetOcclusion", Material_SetOcclusion},
{"Material_SetScene", Material_SetScene},
{"Material_RemoveShaderParameter", Material_RemoveShaderParameter},
{"Material_ReleaseShaders", Material_ReleaseShaders},
{"Material_Clone", Material_Clone},
{"Material_SortTechniques", Material_SortTechniques},
{"Material_MarkForAuxView", Material_MarkForAuxView},
{"Material_GetNumTechniques", Material_GetNumTechniques},
{"Material_GetTechnique", Material_GetTechnique},
{"Material_GetTechniqueOriginal", Material_GetTechniqueOriginal},
{"Material_GetTechniqueLodDistance", Material_GetTechniqueLodDistance},
{"Material_GetTechniqueQualityLevel", Material_GetTechniqueQualityLevel},
{"Material_GetPass", Material_GetPass},
{"Material_GetTexture", Material_GetTexture},
{"Material_GetVertexShaderDefines", Material_GetVertexShaderDefines},
{"Material_GetPixelShaderDefines", Material_GetPixelShaderDefines},
{"Material_GetShaderParameterPtr", Material_GetShaderParameterPtr},
{"Material_GetShaderParameterAnimation", Material_GetShaderParameterAnimation},
{"Material_GetShaderParameterAnimationWrapMode", Material_GetShaderParameterAnimationWrapMode},
{"Material_GetShaderParameterAnimationSpeed", Material_GetShaderParameterAnimationSpeed},
{"Material_GetCullMode", Material_GetCullMode},
{"Material_GetShadowCullMode", Material_GetShadowCullMode},
{"Material_GetFillMode", Material_GetFillMode},
{"Material_GetDepthBias", Material_GetDepthBias},
{"Material_GetAlphaToCoverage", Material_GetAlphaToCoverage},
{"Material_GetLineAntiAlias", Material_GetLineAntiAlias},
{"Material_GetRenderOrder", Material_GetRenderOrder},
{"Material_GetAuxViewFrameNumber", Material_GetAuxViewFrameNumber},
{"Material_GetOcclusion", Material_GetOcclusion},
{"Material_GetSpecular", Material_GetSpecular},
{"Material_GetScene", Material_GetScene},
{"Material_GetShaderParameterHash", Material_GetShaderParameterHash},
{"Material_GetTextureUnitName", Material_GetTextureUnitName},
{"Material_ParseShaderParameterValue", Material_ParseShaderParameterValue},
{"MemoryBuffer_MemoryBuffer", MemoryBuffer_MemoryBuffer},
{"MemoryBuffer_GetData", MemoryBuffer_GetData},
{"MemoryBuffer_GetSize", MemoryBuffer_GetSize},
{"MemoryBuffer_Dispose", MemoryBuffer_Dispose},
{"MemoryBuffer_GetString", MemoryBuffer_GetString},
{"Model_Clone_EmptyName", Model_Clone_EmptyName},
{"Model_GetSkeleton", Model_GetSkeleton},
{"Model_GetType", Model_GetType},
{"Model_GetTypeName", Model_GetTypeName},
{"Model_GetTypeStatic", Model_GetTypeStatic},
{"Model_GetTypeNameStatic", Model_GetTypeNameStatic},
{"Model_Model", Model_Model},
{"Model_RegisterObject", Model_RegisterObject},
{"Model_BeginLoad_File", Model_BeginLoad_File},
{"Model_BeginLoad_MemoryBuffer", Model_BeginLoad_MemoryBuffer},
{"Model_EndLoad", Model_EndLoad},
{"Model_Save_File", Model_Save_File},
{"Model_Save_MemoryBuffer", Model_Save_MemoryBuffer},
{"Model_SetBoundingBox", Model_SetBoundingBox},
{"Model_SetNumGeometries", Model_SetNumGeometries},
{"Model_SetNumGeometryLodLevels", Model_SetNumGeometryLodLevels},
{"Model_SetGeometry", Model_SetGeometry},
{"Model_SetGeometryCenter", Model_SetGeometryCenter},
{"Model_Clone", Model_Clone},
{"Model_GetBoundingBox", Model_GetBoundingBox},
{"Model_GetVertexBuffers", Model_GetVertexBuffers},
{"Model_GetIndexBuffers", Model_GetIndexBuffers},
{"Model_GetNumGeometries", Model_GetNumGeometries},
{"Model_GetNumGeometryLodLevels", Model_GetNumGeometryLodLevels},
{"Model_GetGeometry", Model_GetGeometry},
{"Model_GetGeometryCenter", Model_GetGeometryCenter},
{"Model_GetNumMorphs", Model_GetNumMorphs},
{"Model_GetMorph", Model_GetMorph},
{"Model_GetMorph0", Model_GetMorph0},
{"Model_GetMorph1", Model_GetMorph1},
{"Model_GetMorphRangeStart", Model_GetMorphRangeStart},
{"Model_GetMorphRangeCount", Model_GetMorphRangeCount},
{"Model_AddVertexBuffer", Model_AddVertexBuffer},
{"Model_AddIndexBuffer", Model_AddIndexBuffer},
{"Model_ClearGeometryBoneMappings", Model_ClearGeometryBoneMappings},
{"Model_AddGeometryBoneMapping", Model_AddGeometryBoneMapping},
{"urho_node_get_components", urho_node_get_components},
{"Node_GetChildrenWithTag", Node_GetChildrenWithTag},
{"Node_RemoveComponent22", Node_RemoveComponent22},
{"Node_GetVar", Node_GetVar},
{"Node_GetTags", Node_GetTags},
{"Node_GetVars", Node_GetVars},
{"Node_GetType", Node_GetType},
{"Node_GetTypeName", Node_GetTypeName},
{"Node_GetTypeStatic", Node_GetTypeStatic},
{"Node_GetTypeNameStatic", Node_GetTypeNameStatic},
{"Node_Node", Node_Node},
{"Node_RegisterObject", Node_RegisterObject},
{"Node_Load_File", Node_Load_File},
{"Node_Load_MemoryBuffer", Node_Load_MemoryBuffer},
{"Node_LoadXML_File", Node_LoadXML_File},
{"Node_LoadXML_MemoryBuffer", Node_LoadXML_MemoryBuffer},
{"Node_LoadJSON_File", Node_LoadJSON_File},
{"Node_LoadJSON_MemoryBuffer", Node_LoadJSON_MemoryBuffer},
{"Node_LoadXML0", Node_LoadXML0},
{"Node_Save_File", Node_Save_File},
{"Node_Save_MemoryBuffer", Node_Save_MemoryBuffer},
{"Node_SaveXML", Node_SaveXML},
{"Node_ApplyAttributes", Node_ApplyAttributes},
{"Node_SaveDefaultAttributes", Node_SaveDefaultAttributes},
{"Node_MarkNetworkUpdate", Node_MarkNetworkUpdate},
{"Node_AddReplicationState", Node_AddReplicationState},
{"Node_SaveXML1_File", Node_SaveXML1_File},
{"Node_SaveXML1_MemoryBuffer", Node_SaveXML1_MemoryBuffer},
{"Node_SaveJSON_File", Node_SaveJSON_File},
{"Node_SaveJSON_MemoryBuffer", Node_SaveJSON_MemoryBuffer},
{"Node_SetName", Node_SetName},
{"Node_AddTag", Node_AddTag},
{"Node_RemoveTag", Node_RemoveTag},
{"Node_RemoveAllTags", Node_RemoveAllTags},
{"Node_SetPosition", Node_SetPosition},
{"Node_SetPosition2D", Node_SetPosition2D},
{"Node_SetPosition2D2", Node_SetPosition2D2},
{"Node_SetRotation", Node_SetRotation},
{"Node_SetRotation2D", Node_SetRotation2D},
{"Node_SetDirection", Node_SetDirection},
{"Node_SetScale", Node_SetScale},
{"Node_SetScale3", Node_SetScale3},
{"Node_SetScale2D", Node_SetScale2D},
{"Node_SetScale2D4", Node_SetScale2D4},
{"Node_SetTransform", Node_SetTransform},
{"Node_SetTransform5", Node_SetTransform5},
{"Node_SetTransform6", Node_SetTransform6},
{"Node_SetTransform7", Node_SetTransform7},
{"Node_SetTransform2D", Node_SetTransform2D},
{"Node_SetTransform2D8", Node_SetTransform2D8},
{"Node_SetTransform2D9", Node_SetTransform2D9},
{"Node_SetWorldPosition", Node_SetWorldPosition},
{"Node_SetWorldPosition2D", Node_SetWorldPosition2D},
{"Node_SetWorldPosition2D10", Node_SetWorldPosition2D10},
{"Node_SetWorldRotation", Node_SetWorldRotation},
{"Node_SetWorldRotation2D", Node_SetWorldRotation2D},
{"Node_SetWorldDirection", Node_SetWorldDirection},
{"Node_SetWorldScale", Node_SetWorldScale},
{"Node_SetWorldScale11", Node_SetWorldScale11},
{"Node_SetWorldScale2D", Node_SetWorldScale2D},
{"Node_SetWorldScale2D12", Node_SetWorldScale2D12},
{"Node_SetWorldTransform", Node_SetWorldTransform},
{"Node_SetWorldTransform13", Node_SetWorldTransform13},
{"Node_SetWorldTransform14", Node_SetWorldTransform14},
{"Node_SetWorldTransform15", Node_SetWorldTransform15},
{"Node_SetWorldTransform2D", Node_SetWorldTransform2D},
{"Node_SetWorldTransform2D16", Node_SetWorldTransform2D16},
{"Node_SetWorldTransform2D17", Node_SetWorldTransform2D17},
{"Node_Translate", Node_Translate},
{"Node_Translate2D", Node_Translate2D},
{"Node_Rotate", Node_Rotate},
{"Node_Rotate2D", Node_Rotate2D},
{"Node_RotateAround", Node_RotateAround},
{"Node_RotateAround2D", Node_RotateAround2D},
{"Node_Pitch", Node_Pitch},
{"Node_Yaw", Node_Yaw},
{"Node_Roll", Node_Roll},
{"Node_LookAt", Node_LookAt},
{"Node_Scale", Node_Scale},
{"Node_Scale18", Node_Scale18},
{"Node_Scale2D", Node_Scale2D},
{"Node_SetEnabled", Node_SetEnabled},
{"Node_SetDeepEnabled", Node_SetDeepEnabled},
{"Node_ResetDeepEnabled", Node_ResetDeepEnabled},
{"Node_SetEnabledRecursive", Node_SetEnabledRecursive},
{"Node_SetOwner", Node_SetOwner},
{"Node_MarkDirty", Node_MarkDirty},
{"Node_CreateChild", Node_CreateChild},
{"Node_CreateTemporaryChild", Node_CreateTemporaryChild},
{"Node_AddChild", Node_AddChild},
{"Node_RemoveChild", Node_RemoveChild},
{"Node_RemoveAllChildren", Node_RemoveAllChildren},
{"Node_RemoveChildren", Node_RemoveChildren},
{"Node_CreateComponent", Node_CreateComponent},
{"Node_GetOrCreateComponent", Node_GetOrCreateComponent},
{"Node_CloneComponent", Node_CloneComponent},
{"Node_CloneComponent19", Node_CloneComponent19},
{"Node_RemoveComponent", Node_RemoveComponent},
{"Node_RemoveComponents", Node_RemoveComponents},
{"Node_RemoveComponents20", Node_RemoveComponents20},
{"Node_RemoveAllComponents", Node_RemoveAllComponents},
{"Node_ReorderComponent", Node_ReorderComponent},
{"Node_Clone", Node_Clone},
{"Node_Remove", Node_Remove},
{"Node_SetParent", Node_SetParent},
{"Node_SetVar_0", Node_SetVar_0},
{"Node_SetVar_1", Node_SetVar_1},
{"Node_SetVar_2", Node_SetVar_2},
{"Node_SetVar_3", Node_SetVar_3},
{"Node_SetVar_4", Node_SetVar_4},
{"Node_SetVar_5", Node_SetVar_5},
{"Node_SetVar_6", Node_SetVar_6},
{"Node_SetVar_7", Node_SetVar_7},
{"Node_SetVar_8", Node_SetVar_8},
{"Node_SetVar_9", Node_SetVar_9},
{"Node_SetVar_10", Node_SetVar_10},
{"Node_SetVar_11", Node_SetVar_11},
{"Node_SetVar_12", Node_SetVar_12},
{"Node_SetVar_13", Node_SetVar_13},
{"Node_SetVar_14", Node_SetVar_14},
{"Node_SetVar21_0", Node_SetVar21_0},
{"Node_SetVar21_1", Node_SetVar21_1},
{"Node_SetVar21_2", Node_SetVar21_2},
{"Node_SetVar21_3", Node_SetVar21_3},
{"Node_SetVar21_4", Node_SetVar21_4},
{"Node_SetVar21_5", Node_SetVar21_5},
{"Node_SetVar21_6", Node_SetVar21_6},
{"Node_SetVar21_7", Node_SetVar21_7},
{"Node_SetVar21_8", Node_SetVar21_8},
{"Node_SetVar21_9", Node_SetVar21_9},
{"Node_SetVar21_10", Node_SetVar21_10},
{"Node_SetVar21_11", Node_SetVar21_11},
{"Node_SetVar21_12", Node_SetVar21_12},
{"Node_SetVar21_13", Node_SetVar21_13},
{"Node_SetVar21_14", Node_SetVar21_14},
{"Node_AddListener", Node_AddListener},
{"Node_RemoveListener", Node_RemoveListener},
{"Node_GetID", Node_GetID},
{"Node_IsReplicated", Node_IsReplicated},
{"Node_GetName", Node_GetName},
{"Node_GetNameHash", Node_GetNameHash},
{"Node_HasTag", Node_HasTag},
{"Node_GetParent", Node_GetParent},
{"Node_GetScene", Node_GetScene},
{"Node_IsChildOf", Node_IsChildOf},
{"Node_IsEnabled", Node_IsEnabled},
{"Node_IsEnabledSelf", Node_IsEnabledSelf},
{"Node_GetOwner", Node_GetOwner},
{"Node_GetPosition", Node_GetPosition},
{"Node_GetPosition2D", Node_GetPosition2D},
{"Node_GetRotation", Node_GetRotation},
{"Node_GetRotation2D", Node_GetRotation2D},
{"Node_GetDirection", Node_GetDirection},
{"Node_GetUp", Node_GetUp},
{"Node_GetRight", Node_GetRight},
{"Node_GetScale", Node_GetScale},
{"Node_GetScale2D", Node_GetScale2D},
{"Node_GetTransform", Node_GetTransform},
{"Node_GetWorldPosition", Node_GetWorldPosition},
{"Node_GetWorldPosition2D", Node_GetWorldPosition2D},
{"Node_GetWorldRotation", Node_GetWorldRotation},
{"Node_GetWorldRotation2D", Node_GetWorldRotation2D},
{"Node_GetWorldDirection", Node_GetWorldDirection},
{"Node_GetWorldUp", Node_GetWorldUp},
{"Node_GetWorldRight", Node_GetWorldRight},
{"Node_GetWorldScale", Node_GetWorldScale},
{"Node_GetSignedWorldScale", Node_GetSignedWorldScale},
{"Node_GetWorldScale2D", Node_GetWorldScale2D},
{"Node_GetWorldTransform", Node_GetWorldTransform},
{"Node_LocalToWorld", Node_LocalToWorld},
{"Node_LocalToWorld22", Node_LocalToWorld22},
{"Node_LocalToWorld2D", Node_LocalToWorld2D},
{"Node_WorldToLocal", Node_WorldToLocal},
{"Node_WorldToLocal23", Node_WorldToLocal23},
{"Node_WorldToLocal2D", Node_WorldToLocal2D},
{"Node_IsDirty", Node_IsDirty},
{"Node_GetNumChildren", Node_GetNumChildren},
{"Node_GetChildren", Node_GetChildren},
{"Node_GetChild", Node_GetChild},
{"Node_GetChild24", Node_GetChild24},
{"Node_GetChild25", Node_GetChild25},
{"Node_GetNumComponents", Node_GetNumComponents},
{"Node_GetNumNetworkComponents", Node_GetNumNetworkComponents},
{"Node_GetComponents", Node_GetComponents},
{"Node_GetComponent", Node_GetComponent},
{"Node_GetParentComponent", Node_GetParentComponent},
{"Node_HasComponent", Node_HasComponent},
{"Node_GetVar26", Node_GetVar26},
{"Node_SetID", Node_SetID},
{"Node_SetScene", Node_SetScene},
{"Node_ResetScene", Node_ResetScene},
{"Node_SetNetPositionAttr", Node_SetNetPositionAttr},
{"Node_GetNetPositionAttr", Node_GetNetPositionAttr},
{"Node_PrepareNetworkUpdate", Node_PrepareNetworkUpdate},
{"Node_CleanupConnection", Node_CleanupConnection},
{"Node_MarkReplicationDirty", Node_MarkReplicationDirty},
{"Node_CreateChild27", Node_CreateChild27},
{"Node_AddComponent", Node_AddComponent},
{"Node_GetNumPersistentChildren", Node_GetNumPersistentChildren},
{"Node_GetNumPersistentComponents", Node_GetNumPersistentComponents},
{"Node_SetPositionSilent", Node_SetPositionSilent},
{"Node_SetRotationSilent", Node_SetRotationSilent},
{"Node_SetScaleSilent", Node_SetScaleSilent},
{"Node_SetTransformSilent", Node_SetTransformSilent},
{"Node_HasVar", Node_HasVar},
{"Node_HasVar28", Node_HasVar28},
{"FreeBuffer", FreeBuffer},
{"urho_subscribe_global_event", urho_subscribe_global_event},
{"urho_subscribe_event", urho_subscribe_event},
{"UrhoObject_GetType", UrhoObject_GetType},
{"UrhoObject_GetTypeName", UrhoObject_GetTypeName},
{"UrhoObject_GetTypeInfo", UrhoObject_GetTypeInfo},
{"UrhoObject_GetTypeInfoStatic", UrhoObject_GetTypeInfoStatic},
{"UrhoObject_IsInstanceOf", UrhoObject_IsInstanceOf},
{"UrhoObject_IsInstanceOf0", UrhoObject_IsInstanceOf0},
{"UrhoObject_SubscribeToEvent", UrhoObject_SubscribeToEvent},
{"UrhoObject_SubscribeToEvent1", UrhoObject_SubscribeToEvent1},
{"UrhoObject_UnsubscribeFromEvent", UrhoObject_UnsubscribeFromEvent},
{"UrhoObject_UnsubscribeFromEvent2", UrhoObject_UnsubscribeFromEvent2},
{"UrhoObject_UnsubscribeFromEvents", UrhoObject_UnsubscribeFromEvents},
{"UrhoObject_UnsubscribeFromAllEvents", UrhoObject_UnsubscribeFromAllEvents},
{"UrhoObject_SendEvent", UrhoObject_SendEvent},
{"UrhoObject_GetContext", UrhoObject_GetContext},
{"UrhoObject_SetGlobalVar_0", UrhoObject_SetGlobalVar_0},
{"UrhoObject_SetGlobalVar_1", UrhoObject_SetGlobalVar_1},
{"UrhoObject_SetGlobalVar_2", UrhoObject_SetGlobalVar_2},
{"UrhoObject_SetGlobalVar_3", UrhoObject_SetGlobalVar_3},
{"UrhoObject_SetGlobalVar_4", UrhoObject_SetGlobalVar_4},
{"UrhoObject_SetGlobalVar_5", UrhoObject_SetGlobalVar_5},
{"UrhoObject_SetGlobalVar_6", UrhoObject_SetGlobalVar_6},
{"UrhoObject_SetGlobalVar_7", UrhoObject_SetGlobalVar_7},
{"UrhoObject_SetGlobalVar_8", UrhoObject_SetGlobalVar_8},
{"UrhoObject_SetGlobalVar_9", UrhoObject_SetGlobalVar_9},
{"UrhoObject_SetGlobalVar_10", UrhoObject_SetGlobalVar_10},
{"UrhoObject_SetGlobalVar_11", UrhoObject_SetGlobalVar_11},
{"UrhoObject_SetGlobalVar_12", UrhoObject_SetGlobalVar_12},
{"UrhoObject_SetGlobalVar_13", UrhoObject_SetGlobalVar_13},
{"UrhoObject_SetGlobalVar_14", UrhoObject_SetGlobalVar_14},
{"UrhoObject_GetSubsystem", UrhoObject_GetSubsystem},
{"UrhoObject_GetEventSender", UrhoObject_GetEventSender},
{"UrhoObject_GetEventHandler", UrhoObject_GetEventHandler},
{"UrhoObject_HasSubscribedToEvent", UrhoObject_HasSubscribedToEvent},
{"UrhoObject_HasSubscribedToEvent3", UrhoObject_HasSubscribedToEvent3},
{"UrhoObject_HasEventHandlers", UrhoObject_HasEventHandlers},
{"UrhoObject_GetCategory", UrhoObject_GetCategory},
{"UrhoObject_SetBlockEvents", UrhoObject_SetBlockEvents},
{"UrhoObject_GetBlockEvents", UrhoObject_GetBlockEvents},
{"UrhoObject_PostCommandToPlugin", UrhoObject_PostCommandToPlugin},
{"UrhoObject_PostCommandToPlugin4", UrhoObject_PostCommandToPlugin4},
{"Octree_Raycast", Octree_Raycast},
{"Octree_GetType", Octree_GetType},
{"Octree_GetTypeName", Octree_GetTypeName},
{"Octree_GetTypeStatic", Octree_GetTypeStatic},
{"Octree_GetTypeNameStatic", Octree_GetTypeNameStatic},
{"Octree_Octree", Octree_Octree},
{"Octree_RegisterObject", Octree_RegisterObject},
{"Octree_DrawDebugGeometry", Octree_DrawDebugGeometry},
{"Octree_SetSize", Octree_SetSize},
{"Octree_AddManualDrawable", Octree_AddManualDrawable},
{"Octree_RemoveManualDrawable", Octree_RemoveManualDrawable},
{"Octree_GetNumLevels", Octree_GetNumLevels},
{"Octree_QueueUpdate", Octree_QueueUpdate},
{"Octree_CancelUpdate", Octree_CancelUpdate},
{"Octree_DrawDebugGeometry0", Octree_DrawDebugGeometry0},
{"Polyhedron_Polyhedron", Polyhedron_Polyhedron},
{"Polyhedron_Polyhedron0", Polyhedron_Polyhedron0},
{"Polyhedron_Polyhedron1", Polyhedron_Polyhedron1},
{"Polyhedron_Polyhedron2", Polyhedron_Polyhedron2},
{"Polyhedron_Define", Polyhedron_Define},
{"Polyhedron_Define3", Polyhedron_Define3},
{"Polyhedron_AddFace", Polyhedron_AddFace},
{"Polyhedron_AddFace4", Polyhedron_AddFace4},
{"Polyhedron_Clip", Polyhedron_Clip},
{"Polyhedron_Clip5", Polyhedron_Clip5},
{"Polyhedron_Clip6", Polyhedron_Clip6},
{"Polyhedron_Clear", Polyhedron_Clear},
{"Polyhedron_Transform", Polyhedron_Transform},
{"Polyhedron_Transform7", Polyhedron_Transform7},
{"Polyhedron_Transformed", Polyhedron_Transformed},
{"Polyhedron_Transformed8", Polyhedron_Transformed8},
{"Polyhedron_Empty", Polyhedron_Empty},
{"Profiler_BeginBlock", Profiler_BeginBlock},
{"Profiler_GetType", Profiler_GetType},
{"Profiler_GetTypeName", Profiler_GetTypeName},
{"Profiler_GetTypeStatic", Profiler_GetTypeStatic},
{"Profiler_GetTypeNameStatic", Profiler_GetTypeNameStatic},
{"Profiler_Profiler", Profiler_Profiler},
{"Profiler_EndBlock", Profiler_EndBlock},
{"Profiler_BeginFrame", Profiler_BeginFrame},
{"Profiler_EndFrame", Profiler_EndFrame},
{"Profiler_BeginInterval", Profiler_BeginInterval},
{"Profiler_PrintData", Profiler_PrintData},
{"Profiler_GetCurrentBlock", Profiler_GetCurrentBlock},
{"Profiler_GetRootBlock", Profiler_GetRootBlock},
{"RefCount_RefCount", RefCount_RefCount},
{"TryDeleteRefCounted", TryDeleteRefCounted},
{"RefCounted_RefCounted", RefCounted_RefCounted},
{"RefCounted_AddRef", RefCounted_AddRef},
{"RefCounted_ReleaseRef", RefCounted_ReleaseRef},
{"RefCounted_Refs", RefCounted_Refs},
{"RefCounted_WeakRefs", RefCounted_WeakRefs},
{"RefCounted_RefCountPtr", RefCounted_RefCountPtr},
{"RenderPath_RenderPath", RenderPath_RenderPath},
{"RenderPath_Clone", RenderPath_Clone},
{"RenderPath_Load", RenderPath_Load},
{"RenderPath_Append", RenderPath_Append},
{"RenderPath_SetEnabled", RenderPath_SetEnabled},
{"RenderPath_IsEnabled", RenderPath_IsEnabled},
{"RenderPath_IsAdded", RenderPath_IsAdded},
{"RenderPath_ToggleEnabled", RenderPath_ToggleEnabled},
{"RenderPath_RemoveRenderTarget", RenderPath_RemoveRenderTarget},
{"RenderPath_RemoveRenderTarget0", RenderPath_RemoveRenderTarget0},
{"RenderPath_RemoveRenderTargets", RenderPath_RemoveRenderTargets},
{"RenderPath_SetCommand", RenderPath_SetCommand},
{"RenderPath_AddCommand", RenderPath_AddCommand},
{"RenderPath_InsertCommand", RenderPath_InsertCommand},
{"RenderPath_RemoveCommand", RenderPath_RemoveCommand},
{"RenderPath_RemoveCommands", RenderPath_RemoveCommands},
{"RenderPath_SetShaderParameter_0", RenderPath_SetShaderParameter_0},
{"RenderPath_SetShaderParameter_1", RenderPath_SetShaderParameter_1},
{"RenderPath_SetShaderParameter_2", RenderPath_SetShaderParameter_2},
{"RenderPath_SetShaderParameter_3", RenderPath_SetShaderParameter_3},
{"RenderPath_SetShaderParameter_4", RenderPath_SetShaderParameter_4},
{"RenderPath_SetShaderParameter_5", RenderPath_SetShaderParameter_5},
{"RenderPath_SetShaderParameter_6", RenderPath_SetShaderParameter_6},
{"RenderPath_SetShaderParameter_7", RenderPath_SetShaderParameter_7},
{"RenderPath_SetShaderParameter_8", RenderPath_SetShaderParameter_8},
{"RenderPath_SetShaderParameter_9", RenderPath_SetShaderParameter_9},
{"RenderPath_SetShaderParameter_10", RenderPath_SetShaderParameter_10},
{"RenderPath_SetShaderParameter_11", RenderPath_SetShaderParameter_11},
{"RenderPath_SetShaderParameter_12", RenderPath_SetShaderParameter_12},
{"RenderPath_SetShaderParameter_13", RenderPath_SetShaderParameter_13},
{"RenderPath_SetShaderParameter_14", RenderPath_SetShaderParameter_14},
{"RenderPath_GetNumRenderTargets", RenderPath_GetNumRenderTargets},
{"RenderPath_GetNumCommands", RenderPath_GetNumCommands},
{"RenderPath_GetCommand", RenderPath_GetCommand},
{"SDL_SendWindowEvent", SDL_SendWindowEvent},
{"SDL_SendAppEvent", SDL_SendAppEvent},
{"SDL_SendKeyboardKey", SDL_SendKeyboardKey},
{"SDL_SetMainReady", SDL_SetMainReady},
{"SDL_AudioQuit", SDL_AudioQuit},
{"SDL_Quit", SDL_Quit},
{"Scene_LoadXMLFromCache", Scene_LoadXMLFromCache},
{"Scene_GetType", Scene_GetType},
{"Scene_GetTypeName", Scene_GetTypeName},
{"Scene_GetTypeStatic", Scene_GetTypeStatic},
{"Scene_GetTypeNameStatic", Scene_GetTypeNameStatic},
{"Scene_Scene", Scene_Scene},
{"Scene_RegisterObject", Scene_RegisterObject},
{"Scene_Load_File", Scene_Load_File},
{"Scene_Load_MemoryBuffer", Scene_Load_MemoryBuffer},
{"Scene_Save_File", Scene_Save_File},
{"Scene_Save_MemoryBuffer", Scene_Save_MemoryBuffer},
{"Scene_LoadXML", Scene_LoadXML},
{"Scene_MarkNetworkUpdate", Scene_MarkNetworkUpdate},
{"Scene_AddReplicationState", Scene_AddReplicationState},
{"Scene_LoadXML0_File", Scene_LoadXML0_File},
{"Scene_LoadXML0_MemoryBuffer", Scene_LoadXML0_MemoryBuffer},
{"Scene_LoadJSON_File", Scene_LoadJSON_File},
{"Scene_LoadJSON_MemoryBuffer", Scene_LoadJSON_MemoryBuffer},
{"Scene_SaveXML_File", Scene_SaveXML_File},
{"Scene_SaveXML_MemoryBuffer", Scene_SaveXML_MemoryBuffer},
{"Scene_SaveJSON_File", Scene_SaveJSON_File},
{"Scene_SaveJSON_MemoryBuffer", Scene_SaveJSON_MemoryBuffer},
{"Scene_LoadAsync", Scene_LoadAsync},
{"Scene_LoadAsyncXML", Scene_LoadAsyncXML},
{"Scene_LoadAsyncJSON", Scene_LoadAsyncJSON},
{"Scene_LoadAsyncNodeXML", Scene_LoadAsyncNodeXML},
{"Scene_LoadAsyncNodeXML1", Scene_LoadAsyncNodeXML1},
{"Scene_LoadAsyncNodeJSON", Scene_LoadAsyncNodeJSON},
{"Scene_LoadAsyncNodeJSON2", Scene_LoadAsyncNodeJSON2},
{"Scene_LoadAsyncNode", Scene_LoadAsyncNode},
{"Scene_LoadAsyncNode3", Scene_LoadAsyncNode3},
{"Scene_StopAsyncLoading", Scene_StopAsyncLoading},
{"Scene_Instantiate_File", Scene_Instantiate_File},
{"Scene_Instantiate_MemoryBuffer", Scene_Instantiate_MemoryBuffer},
{"Scene_InstantiateXML", Scene_InstantiateXML},
{"Scene_InstantiateXML4_File", Scene_InstantiateXML4_File},
{"Scene_InstantiateXML4_MemoryBuffer", Scene_InstantiateXML4_MemoryBuffer},
{"Scene_InstantiateJSON_File", Scene_InstantiateJSON_File},
{"Scene_InstantiateJSON_MemoryBuffer", Scene_InstantiateJSON_MemoryBuffer},
{"Scene_Clear", Scene_Clear},
{"Scene_SetUpdateEnabled", Scene_SetUpdateEnabled},
{"Scene_SetTimeScale", Scene_SetTimeScale},
{"Scene_SetElapsedTime", Scene_SetElapsedTime},
{"Scene_SetSmoothingConstant", Scene_SetSmoothingConstant},
{"Scene_SetSnapThreshold", Scene_SetSnapThreshold},
{"Scene_SetAsyncLoadingMs", Scene_SetAsyncLoadingMs},
{"Scene_SetAsyncIntervalMs", Scene_SetAsyncIntervalMs},
{"Scene_AddRequiredPackageFile", Scene_AddRequiredPackageFile},
{"Scene_ClearRequiredPackageFiles", Scene_ClearRequiredPackageFiles},
{"Scene_RegisterVar", Scene_RegisterVar},
{"Scene_UnregisterVar", Scene_UnregisterVar},
{"Scene_UnregisterAllVars", Scene_UnregisterAllVars},
{"Scene_GetNode", Scene_GetNode},
{"Scene_GetComponent", Scene_GetComponent},
{"Scene_IsUpdateEnabled", Scene_IsUpdateEnabled},
{"Scene_IsAsyncLoading", Scene_IsAsyncLoading},
{"Scene_GetAsyncProgress", Scene_GetAsyncProgress},
{"Scene_GetAsyncLoadMode", Scene_GetAsyncLoadMode},
{"Scene_GetFileName", Scene_GetFileName},
{"Scene_GetChecksum", Scene_GetChecksum},
{"Scene_GetTimeScale", Scene_GetTimeScale},
{"Scene_GetElapsedTime", Scene_GetElapsedTime},
{"Scene_GetSmoothingConstant", Scene_GetSmoothingConstant},
{"Scene_GetSnapThreshold", Scene_GetSnapThreshold},
{"Scene_GetAsyncLoadingMs", Scene_GetAsyncLoadingMs},
{"Scene_GetAsyncIntervalMs", Scene_GetAsyncIntervalMs},
{"Scene_GetRequiredPackageFiles", Scene_GetRequiredPackageFiles},
{"Scene_GetVarName", Scene_GetVarName},
{"Scene_Update", Scene_Update},
{"Scene_BeginThreadedUpdate", Scene_BeginThreadedUpdate},
{"Scene_EndThreadedUpdate", Scene_EndThreadedUpdate},
{"Scene_DelayedMarkedDirty", Scene_DelayedMarkedDirty},
{"Scene_IsThreadedUpdate", Scene_IsThreadedUpdate},
{"Scene_GetFreeNodeID", Scene_GetFreeNodeID},
{"Scene_GetFreeComponentID", Scene_GetFreeComponentID},
{"Scene_IsReplicatedID", Scene_IsReplicatedID},
{"Scene_NodeTagAdded", Scene_NodeTagAdded},
{"Scene_NodeTagRemoved", Scene_NodeTagRemoved},
{"Scene_SetVarNamesAttr", Scene_SetVarNamesAttr},
{"Scene_GetVarNamesAttr", Scene_GetVarNamesAttr},
{"Scene_PrepareNetworkUpdate", Scene_PrepareNetworkUpdate},
{"Scene_CleanupConnection", Scene_CleanupConnection},
{"Scene_MarkNetworkUpdate5", Scene_MarkNetworkUpdate5},
{"Scene_MarkNetworkUpdate6", Scene_MarkNetworkUpdate6},
{"Scene_MarkReplicationDirty", Scene_MarkReplicationDirty},
{"Serializable_SetAttribute_Variant", Serializable_SetAttribute_Variant},
{"Serializable_SetAttribute_Variant2", Serializable_SetAttribute_Variant2},
{"Serializable_SetAttribute_Variant3", Serializable_SetAttribute_Variant3},
{"Serializable_SetAttribute_Variant4", Serializable_SetAttribute_Variant4},
{"Serializable_GetAttributes", Serializable_GetAttributes},
{"Serializable_GetType", Serializable_GetType},
{"Serializable_GetTypeName", Serializable_GetTypeName},
{"Serializable_GetTypeStatic", Serializable_GetTypeStatic},
{"Serializable_GetTypeNameStatic", Serializable_GetTypeNameStatic},
{"Serializable_Serializable", Serializable_Serializable},
{"Serializable_Load_File", Serializable_Load_File},
{"Serializable_Load_MemoryBuffer", Serializable_Load_MemoryBuffer},
{"Serializable_Save_File", Serializable_Save_File},
{"Serializable_Save_MemoryBuffer", Serializable_Save_MemoryBuffer},
{"Serializable_LoadXML", Serializable_LoadXML},
{"Serializable_SaveXML", Serializable_SaveXML},
{"Serializable_ApplyAttributes", Serializable_ApplyAttributes},
{"Serializable_SaveDefaultAttributes", Serializable_SaveDefaultAttributes},
{"Serializable_MarkNetworkUpdate", Serializable_MarkNetworkUpdate},
{"Serializable_SetAttribute_0", Serializable_SetAttribute_0},
{"Serializable_SetAttribute_1", Serializable_SetAttribute_1},
{"Serializable_SetAttribute_2", Serializable_SetAttribute_2},
{"Serializable_SetAttribute_3", Serializable_SetAttribute_3},
{"Serializable_SetAttribute_4", Serializable_SetAttribute_4},
{"Serializable_SetAttribute_5", Serializable_SetAttribute_5},
{"Serializable_SetAttribute_6", Serializable_SetAttribute_6},
{"Serializable_SetAttribute_7", Serializable_SetAttribute_7},
{"Serializable_SetAttribute_8", Serializable_SetAttribute_8},
{"Serializable_SetAttribute_9", Serializable_SetAttribute_9},
{"Serializable_SetAttribute_10", Serializable_SetAttribute_10},
{"Serializable_SetAttribute_11", Serializable_SetAttribute_11},
{"Serializable_SetAttribute_12", Serializable_SetAttribute_12},
{"Serializable_SetAttribute_13", Serializable_SetAttribute_13},
{"Serializable_SetAttribute_14", Serializable_SetAttribute_14},
{"Serializable_SetAttribute0_0", Serializable_SetAttribute0_0},
{"Serializable_SetAttribute0_1", Serializable_SetAttribute0_1},
{"Serializable_SetAttribute0_2", Serializable_SetAttribute0_2},
{"Serializable_SetAttribute0_3", Serializable_SetAttribute0_3},
{"Serializable_SetAttribute0_4", Serializable_SetAttribute0_4},
{"Serializable_SetAttribute0_5", Serializable_SetAttribute0_5},
{"Serializable_SetAttribute0_6", Serializable_SetAttribute0_6},
{"Serializable_SetAttribute0_7", Serializable_SetAttribute0_7},
{"Serializable_SetAttribute0_8", Serializable_SetAttribute0_8},
{"Serializable_SetAttribute0_9", Serializable_SetAttribute0_9},
{"Serializable_SetAttribute0_10", Serializable_SetAttribute0_10},
{"Serializable_SetAttribute0_11", Serializable_SetAttribute0_11},
{"Serializable_SetAttribute0_12", Serializable_SetAttribute0_12},
{"Serializable_SetAttribute0_13", Serializable_SetAttribute0_13},
{"Serializable_SetAttribute0_14", Serializable_SetAttribute0_14},
{"Serializable_SetInstanceDefault", Serializable_SetInstanceDefault},
{"Serializable_ResetToDefault", Serializable_ResetToDefault},
{"Serializable_RemoveInstanceDefault", Serializable_RemoveInstanceDefault},
{"Serializable_SetTemporary", Serializable_SetTemporary},
{"Serializable_SetInterceptNetworkUpdate", Serializable_SetInterceptNetworkUpdate},
{"Serializable_AllocateNetworkState", Serializable_AllocateNetworkState},
{"Serializable_WriteInitialDeltaUpdate_File", Serializable_WriteInitialDeltaUpdate_File},
{"Serializable_WriteInitialDeltaUpdate_MemoryBuffer", Serializable_WriteInitialDeltaUpdate_MemoryBuffer},
{"Serializable_WriteLatestDataUpdate_File", Serializable_WriteLatestDataUpdate_File},
{"Serializable_WriteLatestDataUpdate_MemoryBuffer", Serializable_WriteLatestDataUpdate_MemoryBuffer},
{"Serializable_ReadDeltaUpdate_File", Serializable_ReadDeltaUpdate_File},
{"Serializable_ReadDeltaUpdate_MemoryBuffer", Serializable_ReadDeltaUpdate_MemoryBuffer},
{"Serializable_ReadLatestDataUpdate_File", Serializable_ReadLatestDataUpdate_File},
{"Serializable_ReadLatestDataUpdate_MemoryBuffer", Serializable_ReadLatestDataUpdate_MemoryBuffer},
{"Serializable_GetAttribute", Serializable_GetAttribute},
{"Serializable_GetAttribute1", Serializable_GetAttribute1},
{"Serializable_GetAttributeDefault", Serializable_GetAttributeDefault},
{"Serializable_GetAttributeDefault2", Serializable_GetAttributeDefault2},
{"Serializable_GetNumAttributes", Serializable_GetNumAttributes},
{"Serializable_GetNumNetworkAttributes", Serializable_GetNumNetworkAttributes},
{"Serializable_IsTemporary", Serializable_IsTemporary},
{"Serializable_GetInterceptNetworkUpdate", Serializable_GetInterceptNetworkUpdate},
{"Serializable_GetNetworkState", Serializable_GetNetworkState},
{"Skeleton_GetBone0", Skeleton_GetBone0},
{"Skeleton_Load_File", Skeleton_Load_File},
{"Skeleton_Load_MemoryBuffer", Skeleton_Load_MemoryBuffer},
{"Skeleton_Save_File", Skeleton_Save_File},
{"Skeleton_Save_MemoryBuffer", Skeleton_Save_MemoryBuffer},
{"Skeleton_SetRootBoneIndex", Skeleton_SetRootBoneIndex},
{"Skeleton_ClearBones", Skeleton_ClearBones},
{"Skeleton_Reset", Skeleton_Reset},
{"Skeleton_GetNumBones", Skeleton_GetNumBones},
{"Skeleton_GetRootBone", Skeleton_GetRootBone},
{"Skeleton_GetBoneIndex", Skeleton_GetBoneIndex},
{"Skeleton_GetBoneIndex0", Skeleton_GetBoneIndex0},
{"Skeleton_GetBoneParent", Skeleton_GetBoneParent},
{"Skeleton_GetBone", Skeleton_GetBone},
{"Skeleton_ResetSilent", Skeleton_ResetSilent},
{"Skeleton_CreateBone", Skeleton_CreateBone},
{"AnimatedModel_GetSkeleton", AnimatedModel_GetSkeleton},
{"AnimatedModel_GetType", AnimatedModel_GetType},
{"AnimatedModel_GetTypeName", AnimatedModel_GetTypeName},
{"AnimatedModel_GetTypeStatic", AnimatedModel_GetTypeStatic},
{"AnimatedModel_GetTypeNameStatic", AnimatedModel_GetTypeNameStatic},
{"AnimatedModel_AnimatedModel", AnimatedModel_AnimatedModel},
{"AnimatedModel_RegisterObject", AnimatedModel_RegisterObject},
{"AnimatedModel_Load_File", AnimatedModel_Load_File},
{"AnimatedModel_Load_MemoryBuffer", AnimatedModel_Load_MemoryBuffer},
{"AnimatedModel_LoadXML", AnimatedModel_LoadXML},
{"AnimatedModel_ApplyAttributes", AnimatedModel_ApplyAttributes},
{"AnimatedModel_GetUpdateGeometryType", AnimatedModel_GetUpdateGeometryType},
{"AnimatedModel_DrawDebugGeometry", AnimatedModel_DrawDebugGeometry},
{"AnimatedModel_SetModel", AnimatedModel_SetModel},
{"AnimatedModel_AddAnimationState", AnimatedModel_AddAnimationState},
{"AnimatedModel_RemoveAnimationState", AnimatedModel_RemoveAnimationState},
{"AnimatedModel_RemoveAnimationState0", AnimatedModel_RemoveAnimationState0},
{"AnimatedModel_RemoveAnimationState1", AnimatedModel_RemoveAnimationState1},
{"AnimatedModel_RemoveAnimationState2", AnimatedModel_RemoveAnimationState2},
{"AnimatedModel_RemoveAnimationState3", AnimatedModel_RemoveAnimationState3},
{"AnimatedModel_RemoveAllAnimationStates", AnimatedModel_RemoveAllAnimationStates},
{"AnimatedModel_SetAnimationLodBias", AnimatedModel_SetAnimationLodBias},
{"AnimatedModel_SetUpdateInvisible", AnimatedModel_SetUpdateInvisible},
{"AnimatedModel_SetMorphWeight", AnimatedModel_SetMorphWeight},
{"AnimatedModel_SetMorphWeight4", AnimatedModel_SetMorphWeight4},
{"AnimatedModel_SetMorphWeight5", AnimatedModel_SetMorphWeight5},
{"AnimatedModel_ResetMorphWeights", AnimatedModel_ResetMorphWeights},
{"AnimatedModel_ApplyAnimation", AnimatedModel_ApplyAnimation},
{"AnimatedModel_GetAnimationStates", AnimatedModel_GetAnimationStates},
{"AnimatedModel_GetNumAnimationStates", AnimatedModel_GetNumAnimationStates},
{"AnimatedModel_GetAnimationState", AnimatedModel_GetAnimationState},
{"AnimatedModel_GetAnimationState6", AnimatedModel_GetAnimationState6},
{"AnimatedModel_GetAnimationState7", AnimatedModel_GetAnimationState7},
{"AnimatedModel_GetAnimationState8", AnimatedModel_GetAnimationState8},
{"AnimatedModel_GetAnimationLodBias", AnimatedModel_GetAnimationLodBias},
{"AnimatedModel_GetUpdateInvisible", AnimatedModel_GetUpdateInvisible},
{"AnimatedModel_GetMorphVertexBuffers", AnimatedModel_GetMorphVertexBuffers},
{"AnimatedModel_GetNumMorphs", AnimatedModel_GetNumMorphs},
{"AnimatedModel_GetMorphWeight", AnimatedModel_GetMorphWeight},
{"AnimatedModel_GetMorphWeight9", AnimatedModel_GetMorphWeight9},
{"AnimatedModel_GetMorphWeight10", AnimatedModel_GetMorphWeight10},
{"AnimatedModel_IsMaster", AnimatedModel_IsMaster},
{"AnimatedModel_GetModelAttr", AnimatedModel_GetModelAttr},
{"AnimatedModel_UpdateBoneBoundingBox", AnimatedModel_UpdateBoneBoundingBox},
{"String_FreeNativeString", String_FreeNativeString},
{"urho_stringhash_from_string", urho_stringhash_from_string},
{"StringVector_Create", StringVector_Create},
{"StringVector_GetSize", StringVector_GetSize},
{"StringVector_GetString", StringVector_GetString},
{"StringVector_AddString", StringVector_AddString},
{"StringVector_SetString", StringVector_SetString},
{"StringVector_Empty", StringVector_Empty},
{"StringVector_Delete", StringVector_Delete},
{"Matrix3x4_Create", Matrix3x4_Create},
{"Matrix3x4_Multiply", Matrix3x4_Multiply},
{"Matrix3x4_Translation", Matrix3x4_Translation},
{"Matrix3x4_Rotation", Matrix3x4_Rotation},
{"JoystickState_GetNumButtons", JoystickState_GetNumButtons},
{"JoystickState_GetButtonDown", JoystickState_GetButtonDown},
{"JoystickState_GetNumHats", JoystickState_GetNumHats},
{"JoystickState_GetHatPosition", JoystickState_GetHatPosition},
{"JoystickState_GetNumAxes", JoystickState_GetNumAxes},
{"JoystickState_GetAxisPosition", JoystickState_GetAxisPosition},
{"RenderPathCommand_SetShaderParameter_float", RenderPathCommand_SetShaderParameter_float},
{"RenderPathCommand_SetShaderParameter_Matrix4", RenderPathCommand_SetShaderParameter_Matrix4},
{"RenderPathCommand_SetOutput", RenderPathCommand_SetOutput},
{"AnimationTrack_PushAnimationKeyFrame", AnimationTrack_PushAnimationKeyFrame},
{"Console_OpenConsoleWindow", Console_OpenConsoleWindow},
{"Console_GetConsoleInput", Console_GetConsoleInput},
{"UrhoConsole_GetType", UrhoConsole_GetType},
{"UrhoConsole_GetTypeName", UrhoConsole_GetTypeName},
{"UrhoConsole_GetTypeStatic", UrhoConsole_GetTypeStatic},
{"UrhoConsole_GetTypeNameStatic", UrhoConsole_GetTypeNameStatic},
{"UrhoConsole_Console", UrhoConsole_Console},
{"UrhoConsole_SetDefaultStyle", UrhoConsole_SetDefaultStyle},
{"UrhoConsole_SetVisible", UrhoConsole_SetVisible},
{"UrhoConsole_Toggle", UrhoConsole_Toggle},
{"UrhoConsole_SetAutoVisibleOnError", UrhoConsole_SetAutoVisibleOnError},
{"UrhoConsole_SetCommandInterpreter", UrhoConsole_SetCommandInterpreter},
{"UrhoConsole_SetNumBufferedRows", UrhoConsole_SetNumBufferedRows},
{"UrhoConsole_SetNumRows", UrhoConsole_SetNumRows},
{"UrhoConsole_SetNumHistoryRows", UrhoConsole_SetNumHistoryRows},
{"UrhoConsole_SetFocusOnShow", UrhoConsole_SetFocusOnShow},
{"UrhoConsole_AddAutoComplete", UrhoConsole_AddAutoComplete},
{"UrhoConsole_RemoveAutoComplete", UrhoConsole_RemoveAutoComplete},
{"UrhoConsole_UpdateElements", UrhoConsole_UpdateElements},
{"UrhoConsole_GetDefaultStyle", UrhoConsole_GetDefaultStyle},
{"UrhoConsole_GetBackground", UrhoConsole_GetBackground},
{"UrhoConsole_GetLineEdit", UrhoConsole_GetLineEdit},
{"UrhoConsole_GetCloseButton", UrhoConsole_GetCloseButton},
{"UrhoConsole_IsVisible", UrhoConsole_IsVisible},
{"UrhoConsole_IsAutoVisibleOnError", UrhoConsole_IsAutoVisibleOnError},
{"UrhoConsole_GetCommandInterpreter", UrhoConsole_GetCommandInterpreter},
{"UrhoConsole_GetNumBufferedRows", UrhoConsole_GetNumBufferedRows},
{"UrhoConsole_GetNumRows", UrhoConsole_GetNumRows},
{"UrhoConsole_CopySelectedRows", UrhoConsole_CopySelectedRows},
{"UrhoConsole_GetNumHistoryRows", UrhoConsole_GetNumHistoryRows},
{"UrhoConsole_GetHistoryPosition", UrhoConsole_GetHistoryPosition},
{"UrhoConsole_GetHistoryRow", UrhoConsole_GetHistoryRow},
{"UrhoConsole_GetFocusOnShow", UrhoConsole_GetFocusOnShow},
{"VariantMap_VariantMap", VariantMap_VariantMap},
{"VariantMap_Dispose", VariantMap_Dispose},
{"VariantMap_Erase", VariantMap_Erase},
{"VariantMap_Erase2", VariantMap_Erase2},
{"urho_map_get_variantmap", urho_map_get_variantmap},
{"urho_map_get_ptr", urho_map_get_ptr},
{"urho_map_get_buffer", urho_map_get_buffer},
{"urho_map_get_String", urho_map_get_String},
{"urho_map_get_StringHash", urho_map_get_StringHash},
{"urho_map_get_bool", urho_map_get_bool},
{"urho_map_get_int", urho_map_get_int},
{"urho_map_get_float", urho_map_get_float},
{"urho_map_get_uint", urho_map_get_uint},
{"urho_map_get_Vector3", urho_map_get_Vector3},
{"urho_map_get_IntVector2", urho_map_get_IntVector2},
{"urho_map_get_Variant", urho_map_get_Variant},
{"urho_map_contains_value", urho_map_contains_value},
{"urho_map_get_value", urho_map_get_value},
{"urho_map_set_value", urho_map_set_value},
{"urho_map_set_value_ptr", urho_map_set_value_ptr},
{"urho_map_get_keys_size", urho_map_get_keys_size},
{"urho_map_keys_get_key", urho_map_keys_get_key},
{"urho_map_keys_get_keys", urho_map_keys_get_keys},
{"VoidPtr_Free", VoidPtr_Free},
{"delete_vector3_pointer", delete_vector3_pointer},
{"VGComponent_GetType", VGComponent_GetType},
{"VGComponent_GetTypeName", VGComponent_GetTypeName},
{"VGComponent_GetTypeStatic", VGComponent_GetTypeStatic},
{"VGComponent_GetTypeNameStatic", VGComponent_GetTypeNameStatic},
{"VGComponent_RegisterObject", VGComponent_RegisterObject},
{"VGComponent_VGComponent", VGComponent_VGComponent},
{"VGComponent_Create", VGComponent_Create},
{"VGComponent_CreateChild", VGComponent_CreateChild},
{"VGComponent_GetChild", VGComponent_GetChild},
{"VGComponent_GetName", VGComponent_GetName},
{"VGComponent_BeginDraw", VGComponent_BeginDraw},
{"VGComponent_EndDraw", VGComponent_EndDraw},
{"VGComponent_SetPosition", VGComponent_SetPosition},
{"VGComponent_SetPosition0", VGComponent_SetPosition0},
{"VGComponent_SetHotSpot", VGComponent_SetHotSpot},
{"VGComponent_SetHotSpot1", VGComponent_SetHotSpot1},
{"VGComponent_SetScale", VGComponent_SetScale},
{"VGComponent_SetScale2", VGComponent_SetScale2},
{"VGComponent_SetScale3", VGComponent_SetScale3},
{"VGComponent_SetRotation", VGComponent_SetRotation},
{"VGComponent_GetHotSpot", VGComponent_GetHotSpot},
{"VGComponent_GetTransformPositionRotation", VGComponent_GetTransformPositionRotation},
{"VGComponent_GetTransformScale", VGComponent_GetTransformScale},
{"VGComponent_GlobalCompositeOperation", VGComponent_GlobalCompositeOperation},
{"VGComponent_GlobalCompositeBlendFunc", VGComponent_GlobalCompositeBlendFunc},
{"VGComponent_GlobalCompositeBlendFuncSeparate", VGComponent_GlobalCompositeBlendFuncSeparate},
{"VGComponent_RGB", VGComponent_RGB},
{"VGComponent_RGBf", VGComponent_RGBf},
{"VGComponent_RGBA", VGComponent_RGBA},
{"VGComponent_RGBAf", VGComponent_RGBAf},
{"VGComponent_LerpRGBA", VGComponent_LerpRGBA},
{"VGComponent_TransRGBA", VGComponent_TransRGBA},
{"VGComponent_TransRGBAf", VGComponent_TransRGBAf},
{"VGComponent_HSL", VGComponent_HSL},
{"VGComponent_HSLA", VGComponent_HSLA},
{"VGComponent_SaveState", VGComponent_SaveState},
{"VGComponent_RestoreState", VGComponent_RestoreState},
{"VGComponent_ResetState", VGComponent_ResetState},
{"VGComponent_ShapeAntiAlias", VGComponent_ShapeAntiAlias},
{"VGComponent_StrokeColor", VGComponent_StrokeColor},
{"VGComponent_StrokePaint", VGComponent_StrokePaint},
{"VGComponent_FillColor", VGComponent_FillColor},
{"VGComponent_FillPaint", VGComponent_FillPaint},
{"VGComponent_MiterLimit", VGComponent_MiterLimit},
{"VGComponent_StrokeWidth", VGComponent_StrokeWidth},
{"VGComponent_LineCap", VGComponent_LineCap},
{"VGComponent_LineJoin", VGComponent_LineJoin},
{"VGComponent_GlobalAlpha", VGComponent_GlobalAlpha},
{"VGComponent_ResetTransform", VGComponent_ResetTransform},
{"VGComponent_Transform", VGComponent_Transform},
{"VGComponent_Translate", VGComponent_Translate},
{"VGComponent_Rotate", VGComponent_Rotate},
{"VGComponent_SkewX", VGComponent_SkewX},
{"VGComponent_SkewY", VGComponent_SkewY},
{"VGComponent_Scale", VGComponent_Scale},
{"VGComponent_CurrentTransform", VGComponent_CurrentTransform},
{"VGComponent_TransformIdentity", VGComponent_TransformIdentity},
{"VGComponent_TransformTranslate", VGComponent_TransformTranslate},
{"VGComponent_TransformScale", VGComponent_TransformScale},
{"VGComponent_TransformRotate", VGComponent_TransformRotate},
{"VGComponent_TransformSkewX", VGComponent_TransformSkewX},
{"VGComponent_TransformSkewY", VGComponent_TransformSkewY},
{"VGComponent_TransformMultiply", VGComponent_TransformMultiply},
{"VGComponent_TransformPremultiply", VGComponent_TransformPremultiply},
{"VGComponent_TransformInverse", VGComponent_TransformInverse},
{"VGComponent_TransformPoint", VGComponent_TransformPoint},
{"VGComponent_DegToRad", VGComponent_DegToRad},
{"VGComponent_RadToDeg", VGComponent_RadToDeg},
{"VGComponent_CreateImageMem", VGComponent_CreateImageMem},
{"VGComponent_CreateImageRGBA", VGComponent_CreateImageRGBA},
{"VGComponent_UpdateImage", VGComponent_UpdateImage},
{"VGComponent_ImageSize", VGComponent_ImageSize},
{"VGComponent_DeleteImage", VGComponent_DeleteImage},
{"VGComponent_LinearGradient", VGComponent_LinearGradient},
{"VGComponent_BoxGradient", VGComponent_BoxGradient},
{"VGComponent_RadialGradient", VGComponent_RadialGradient},
{"VGComponent_ImagePattern", VGComponent_ImagePattern},
{"VGComponent_Scissor", VGComponent_Scissor},
{"VGComponent_IntersectScissor", VGComponent_IntersectScissor},
{"VGComponent_ResetScissor", VGComponent_ResetScissor},
{"VGComponent_BeginPath", VGComponent_BeginPath},
{"VGComponent_MoveTo", VGComponent_MoveTo},
{"VGComponent_LineTo", VGComponent_LineTo},
{"VGComponent_BezierTo", VGComponent_BezierTo},
{"VGComponent_QuadTo", VGComponent_QuadTo},
{"VGComponent_ArcTo", VGComponent_ArcTo},
{"VGComponent_ClosePath", VGComponent_ClosePath},
{"VGComponent_PathWinding", VGComponent_PathWinding},
{"VGComponent_Arc", VGComponent_Arc},
{"VGComponent_Rect", VGComponent_Rect},
{"VGComponent_RoundedRect", VGComponent_RoundedRect},
{"VGComponent_RoundedRectVarying", VGComponent_RoundedRectVarying},
{"VGComponent_Ellipse", VGComponent_Ellipse},
{"VGComponent_Circle", VGComponent_Circle},
{"VGComponent_Arc4", VGComponent_Arc4},
{"VGComponent_Rect5", VGComponent_Rect5},
{"VGComponent_RoundedRect6", VGComponent_RoundedRect6},
{"VGComponent_RoundedRectVarying7", VGComponent_RoundedRectVarying7},
{"VGComponent_Ellipse8", VGComponent_Ellipse8},
{"VGComponent_Circle9", VGComponent_Circle9},
{"VGComponent_Fill", VGComponent_Fill},
{"VGComponent_Stroke", VGComponent_Stroke},
{"VGComponent_AddFallbackFontId", VGComponent_AddFallbackFontId},
{"VGComponent_ResetFallbackFontsId", VGComponent_ResetFallbackFontsId},
{"VGComponent_FontSize", VGComponent_FontSize},
{"VGComponent_FontBlur", VGComponent_FontBlur},
{"VGComponent_TextLetterSpacing", VGComponent_TextLetterSpacing},
{"VGComponent_TextLineHeight", VGComponent_TextLineHeight},
{"VGComponent_TextAlign", VGComponent_TextAlign},
{"VGComponent_FontFaceId", VGComponent_FontFaceId},
{"VGComponent_TextMetrics", VGComponent_TextMetrics},
{"VGComponent_FontFace", VGComponent_FontFace},
{"VGComponent_Text", VGComponent_Text},
{"VGComponent_TextBox", VGComponent_TextBox},
{"VGComponent_TextBreakLines", VGComponent_TextBreakLines},
{"VGComponent_TextBounds", VGComponent_TextBounds},
{"VGComponent_TextBoxBounds", VGComponent_TextBoxBounds},
{"VGComponent_TextGlyphPositions", VGComponent_TextGlyphPositions},
{"VGElement_GetType", VGElement_GetType},
{"VGElement_GetTypeName", VGElement_GetTypeName},
{"VGElement_GetTypeStatic", VGElement_GetTypeStatic},
{"VGElement_GetTypeNameStatic", VGElement_GetTypeNameStatic},
{"VGElement_RegisterObject", VGElement_RegisterObject},
{"VGElement_VGElement", VGElement_VGElement},
{"VGElement_GetRenderTarget", VGElement_GetRenderTarget},
{"VGElement_OnResize", VGElement_OnResize},
{"VGElement_BeginRender", VGElement_BeginRender},
{"VGElement_EndRender", VGElement_EndRender},
{"VGElement_GetSize", VGElement_GetSize},
{"VGElement_SetClearColor", VGElement_SetClearColor},
{"VGElement_GetClearColor", VGElement_GetClearColor},
{"VGElement_BeginFrame", VGElement_BeginFrame},
{"VGElement_CancelFrame", VGElement_CancelFrame},
{"VGElement_EndFrame", VGElement_EndFrame},
{"VGElement_GlobalCompositeOperation", VGElement_GlobalCompositeOperation},
{"VGElement_GlobalCompositeBlendFunc", VGElement_GlobalCompositeBlendFunc},
{"VGElement_GlobalCompositeBlendFuncSeparate", VGElement_GlobalCompositeBlendFuncSeparate},
{"VGElement_RGB", VGElement_RGB},
{"VGElement_RGBf", VGElement_RGBf},
{"VGElement_RGBA", VGElement_RGBA},
{"VGElement_RGBAf", VGElement_RGBAf},
{"VGElement_LerpRGBA", VGElement_LerpRGBA},
{"VGElement_TransRGBA", VGElement_TransRGBA},
{"VGElement_TransRGBAf", VGElement_TransRGBAf},
{"VGElement_HSL", VGElement_HSL},
{"VGElement_HSLA", VGElement_HSLA},
{"VGElement_SaveState", VGElement_SaveState},
{"VGElement_RestoreState", VGElement_RestoreState},
{"VGElement_ResetState", VGElement_ResetState},
{"VGElement_ShapeAntiAlias", VGElement_ShapeAntiAlias},
{"VGElement_StrokeColor", VGElement_StrokeColor},
{"VGElement_StrokePaint", VGElement_StrokePaint},
{"VGElement_FillColor", VGElement_FillColor},
{"VGElement_FillPaint", VGElement_FillPaint},
{"VGElement_MiterLimit", VGElement_MiterLimit},
{"VGElement_StrokeWidth", VGElement_StrokeWidth},
{"VGElement_LineCap", VGElement_LineCap},
{"VGElement_LineJoin", VGElement_LineJoin},
{"VGElement_GlobalAlpha", VGElement_GlobalAlpha},
{"VGElement_ResetTransform", VGElement_ResetTransform},
{"VGElement_Transform", VGElement_Transform},
{"VGElement_Translate", VGElement_Translate},
{"VGElement_Rotate", VGElement_Rotate},
{"VGElement_SkewX", VGElement_SkewX},
{"VGElement_SkewY", VGElement_SkewY},
{"VGElement_Scale", VGElement_Scale},
{"VGElement_CurrentTransform", VGElement_CurrentTransform},
{"VGElement_TransformIdentity", VGElement_TransformIdentity},
{"VGElement_TransformTranslate", VGElement_TransformTranslate},
{"VGElement_TransformScale", VGElement_TransformScale},
{"VGElement_TransformRotate", VGElement_TransformRotate},
{"VGElement_TransformSkewX", VGElement_TransformSkewX},
{"VGElement_TransformSkewY", VGElement_TransformSkewY},
{"VGElement_TransformMultiply", VGElement_TransformMultiply},
{"VGElement_TransformPremultiply", VGElement_TransformPremultiply},
{"VGElement_TransformInverse", VGElement_TransformInverse},
{"VGElement_TransformPoint", VGElement_TransformPoint},
{"VGElement_DegToRad", VGElement_DegToRad},
{"VGElement_RadToDeg", VGElement_RadToDeg},
{"VGElement_CreateImageMem", VGElement_CreateImageMem},
{"VGElement_CreateImageRGBA", VGElement_CreateImageRGBA},
{"VGElement_UpdateImage", VGElement_UpdateImage},
{"VGElement_ImageSize", VGElement_ImageSize},
{"VGElement_DeleteImage", VGElement_DeleteImage},
{"VGElement_LinearGradient", VGElement_LinearGradient},
{"VGElement_BoxGradient", VGElement_BoxGradient},
{"VGElement_RadialGradient", VGElement_RadialGradient},
{"VGElement_ImagePattern", VGElement_ImagePattern},
{"VGElement_Scissor", VGElement_Scissor},
{"VGElement_IntersectScissor", VGElement_IntersectScissor},
{"VGElement_ResetScissor", VGElement_ResetScissor},
{"VGElement_BeginPath", VGElement_BeginPath},
{"VGElement_MoveTo", VGElement_MoveTo},
{"VGElement_LineTo", VGElement_LineTo},
{"VGElement_BezierTo", VGElement_BezierTo},
{"VGElement_QuadTo", VGElement_QuadTo},
{"VGElement_ArcTo", VGElement_ArcTo},
{"VGElement_ClosePath", VGElement_ClosePath},
{"VGElement_PathWinding", VGElement_PathWinding},
{"VGElement_Arc", VGElement_Arc},
{"VGElement_Rect", VGElement_Rect},
{"VGElement_RoundedRect", VGElement_RoundedRect},
{"VGElement_RoundedRectVarying", VGElement_RoundedRectVarying},
{"VGElement_Ellipse", VGElement_Ellipse},
{"VGElement_Circle", VGElement_Circle},
{"VGElement_Fill", VGElement_Fill},
{"VGElement_Stroke", VGElement_Stroke},
{"VGElement_AddFallbackFontId", VGElement_AddFallbackFontId},
{"VGElement_ResetFallbackFontsId", VGElement_ResetFallbackFontsId},
{"VGElement_FontSize", VGElement_FontSize},
{"VGElement_FontBlur", VGElement_FontBlur},
{"VGElement_TextLetterSpacing", VGElement_TextLetterSpacing},
{"VGElement_TextLineHeight", VGElement_TextLineHeight},
{"VGElement_TextAlign", VGElement_TextAlign},
{"VGElement_FontFaceId", VGElement_FontFaceId},
{"VGElement_TextMetrics", VGElement_TextMetrics},
{"VGElement_FontFace", VGElement_FontFace},
{"VGElement_Text", VGElement_Text},
{"VGElement_TextBox", VGElement_TextBox},
{"VGElement_TextBreakLines", VGElement_TextBreakLines},
{"VGElement_TextBounds", VGElement_TextBounds},
{"VGElement_TextBoxBounds", VGElement_TextBoxBounds},
{"VGElement_TextGlyphPositions", VGElement_TextGlyphPositions},
{"VGFrameBuffer_GetType", VGFrameBuffer_GetType},
{"VGFrameBuffer_GetTypeName", VGFrameBuffer_GetTypeName},
{"VGFrameBuffer_GetTypeStatic", VGFrameBuffer_GetTypeStatic},
{"VGFrameBuffer_GetTypeNameStatic", VGFrameBuffer_GetTypeNameStatic},
{"VGFrameBuffer_RegisterObject", VGFrameBuffer_RegisterObject},
{"VGFrameBuffer_Current", VGFrameBuffer_Current},
{"VGFrameBuffer_VGFrameBuffer", VGFrameBuffer_VGFrameBuffer},
{"VGFrameBuffer_VGFrameBuffer0", VGFrameBuffer_VGFrameBuffer0},
{"VGFrameBuffer_CreateFrameBuffer", VGFrameBuffer_CreateFrameBuffer},
{"VGFrameBuffer_Bind", VGFrameBuffer_Bind},
{"VGFrameBuffer_UnBind", VGFrameBuffer_UnBind},
{"VGFrameBuffer_GetRenderTarget", VGFrameBuffer_GetRenderTarget},
{"VGFrameBuffer_GetSize", VGFrameBuffer_GetSize},
{"VGFrameBuffer_SetClearColor", VGFrameBuffer_SetClearColor},
{"VGFrameBuffer_GetClearColor", VGFrameBuffer_GetClearColor},
{"VGFrameBuffer_EnableRenderEvents", VGFrameBuffer_EnableRenderEvents},
{"VGFrameBuffer_DisbaleRenderEvents", VGFrameBuffer_DisbaleRenderEvents},
{"VGFrameBuffer_BeginFrame", VGFrameBuffer_BeginFrame},
{"VGFrameBuffer_CancelFrame", VGFrameBuffer_CancelFrame},
{"VGFrameBuffer_EndFrame", VGFrameBuffer_EndFrame},
{"VGFrameBuffer_GlobalCompositeOperation", VGFrameBuffer_GlobalCompositeOperation},
{"VGFrameBuffer_GlobalCompositeBlendFunc", VGFrameBuffer_GlobalCompositeBlendFunc},
{"VGFrameBuffer_GlobalCompositeBlendFuncSeparate", VGFrameBuffer_GlobalCompositeBlendFuncSeparate},
{"VGFrameBuffer_RGB", VGFrameBuffer_RGB},
{"VGFrameBuffer_RGBf", VGFrameBuffer_RGBf},
{"VGFrameBuffer_RGBA", VGFrameBuffer_RGBA},
{"VGFrameBuffer_RGBAf", VGFrameBuffer_RGBAf},
{"VGFrameBuffer_LerpRGBA", VGFrameBuffer_LerpRGBA},
{"VGFrameBuffer_TransRGBA", VGFrameBuffer_TransRGBA},
{"VGFrameBuffer_TransRGBAf", VGFrameBuffer_TransRGBAf},
{"VGFrameBuffer_HSL", VGFrameBuffer_HSL},
{"VGFrameBuffer_HSLA", VGFrameBuffer_HSLA},
{"VGFrameBuffer_SaveState", VGFrameBuffer_SaveState},
{"VGFrameBuffer_RestoreState", VGFrameBuffer_RestoreState},
{"VGFrameBuffer_ResetState", VGFrameBuffer_ResetState},
{"VGFrameBuffer_ShapeAntiAlias", VGFrameBuffer_ShapeAntiAlias},
{"VGFrameBuffer_StrokeColor", VGFrameBuffer_StrokeColor},
{"VGFrameBuffer_StrokePaint", VGFrameBuffer_StrokePaint},
{"VGFrameBuffer_FillColor", VGFrameBuffer_FillColor},
{"VGFrameBuffer_FillPaint", VGFrameBuffer_FillPaint},
{"VGFrameBuffer_MiterLimit", VGFrameBuffer_MiterLimit},
{"VGFrameBuffer_StrokeWidth", VGFrameBuffer_StrokeWidth},
{"VGFrameBuffer_LineCap", VGFrameBuffer_LineCap},
{"VGFrameBuffer_LineJoin", VGFrameBuffer_LineJoin},
{"VGFrameBuffer_GlobalAlpha", VGFrameBuffer_GlobalAlpha},
{"VGFrameBuffer_ResetTransform", VGFrameBuffer_ResetTransform},
{"VGFrameBuffer_Transform", VGFrameBuffer_Transform},
{"VGFrameBuffer_Translate", VGFrameBuffer_Translate},
{"VGFrameBuffer_Rotate", VGFrameBuffer_Rotate},
{"VGFrameBuffer_SkewX", VGFrameBuffer_SkewX},
{"VGFrameBuffer_SkewY", VGFrameBuffer_SkewY},
{"VGFrameBuffer_Scale", VGFrameBuffer_Scale},
{"VGFrameBuffer_CurrentTransform", VGFrameBuffer_CurrentTransform},
{"VGFrameBuffer_TransformIdentity", VGFrameBuffer_TransformIdentity},
{"VGFrameBuffer_TransformTranslate", VGFrameBuffer_TransformTranslate},
{"VGFrameBuffer_TransformScale", VGFrameBuffer_TransformScale},
{"VGFrameBuffer_TransformRotate", VGFrameBuffer_TransformRotate},
{"VGFrameBuffer_TransformSkewX", VGFrameBuffer_TransformSkewX},
{"VGFrameBuffer_TransformSkewY", VGFrameBuffer_TransformSkewY},
{"VGFrameBuffer_TransformMultiply", VGFrameBuffer_TransformMultiply},
{"VGFrameBuffer_TransformPremultiply", VGFrameBuffer_TransformPremultiply},
{"VGFrameBuffer_TransformInverse", VGFrameBuffer_TransformInverse},
{"VGFrameBuffer_TransformPoint", VGFrameBuffer_TransformPoint},
{"VGFrameBuffer_DegToRad", VGFrameBuffer_DegToRad},
{"VGFrameBuffer_RadToDeg", VGFrameBuffer_RadToDeg},
{"VGFrameBuffer_CreateImageMem", VGFrameBuffer_CreateImageMem},
{"VGFrameBuffer_CreateImageRGBA", VGFrameBuffer_CreateImageRGBA},
{"VGFrameBuffer_UpdateImage", VGFrameBuffer_UpdateImage},
{"VGFrameBuffer_ImageSize", VGFrameBuffer_ImageSize},
{"VGFrameBuffer_DeleteImage", VGFrameBuffer_DeleteImage},
{"VGFrameBuffer_LinearGradient", VGFrameBuffer_LinearGradient},
{"VGFrameBuffer_BoxGradient", VGFrameBuffer_BoxGradient},
{"VGFrameBuffer_RadialGradient", VGFrameBuffer_RadialGradient},
{"VGFrameBuffer_ImagePattern", VGFrameBuffer_ImagePattern},
{"VGFrameBuffer_Scissor", VGFrameBuffer_Scissor},
{"VGFrameBuffer_IntersectScissor", VGFrameBuffer_IntersectScissor},
{"VGFrameBuffer_ResetScissor", VGFrameBuffer_ResetScissor},
{"VGFrameBuffer_BeginPath", VGFrameBuffer_BeginPath},
{"VGFrameBuffer_MoveTo", VGFrameBuffer_MoveTo},
{"VGFrameBuffer_LineTo", VGFrameBuffer_LineTo},
{"VGFrameBuffer_BezierTo", VGFrameBuffer_BezierTo},
{"VGFrameBuffer_QuadTo", VGFrameBuffer_QuadTo},
{"VGFrameBuffer_ArcTo", VGFrameBuffer_ArcTo},
{"VGFrameBuffer_ClosePath", VGFrameBuffer_ClosePath},
{"VGFrameBuffer_PathWinding", VGFrameBuffer_PathWinding},
{"VGFrameBuffer_Arc", VGFrameBuffer_Arc},
{"VGFrameBuffer_Rect", VGFrameBuffer_Rect},
{"VGFrameBuffer_RoundedRect", VGFrameBuffer_RoundedRect},
{"VGFrameBuffer_RoundedRectVarying", VGFrameBuffer_RoundedRectVarying},
{"VGFrameBuffer_Ellipse", VGFrameBuffer_Ellipse},
{"VGFrameBuffer_Circle", VGFrameBuffer_Circle},
{"VGFrameBuffer_Fill", VGFrameBuffer_Fill},
{"VGFrameBuffer_Stroke", VGFrameBuffer_Stroke},
{"VGFrameBuffer_AddFallbackFontId", VGFrameBuffer_AddFallbackFontId},
{"VGFrameBuffer_ResetFallbackFontsId", VGFrameBuffer_ResetFallbackFontsId},
{"VGFrameBuffer_FontSize", VGFrameBuffer_FontSize},
{"VGFrameBuffer_FontBlur", VGFrameBuffer_FontBlur},
{"VGFrameBuffer_TextLetterSpacing", VGFrameBuffer_TextLetterSpacing},
{"VGFrameBuffer_TextLineHeight", VGFrameBuffer_TextLineHeight},
{"VGFrameBuffer_TextAlign", VGFrameBuffer_TextAlign},
{"VGFrameBuffer_FontFaceId", VGFrameBuffer_FontFaceId},
{"VGFrameBuffer_TextMetrics", VGFrameBuffer_TextMetrics},
{"VGFrameBuffer_FontFace", VGFrameBuffer_FontFace},
{"VGFrameBuffer_Text", VGFrameBuffer_Text},
{"VGFrameBuffer_TextBox", VGFrameBuffer_TextBox},
{"VGFrameBuffer_TextBreakLines", VGFrameBuffer_TextBreakLines},
{"VGFrameBuffer_TextBounds", VGFrameBuffer_TextBounds},
{"VGFrameBuffer_TextBoxBounds", VGFrameBuffer_TextBoxBounds},
{"VGFrameBuffer_TextGlyphPositions", VGFrameBuffer_TextGlyphPositions},
{"VGTextRowBuffer_GetType", VGTextRowBuffer_GetType},
{"VGTextRowBuffer_GetTypeName", VGTextRowBuffer_GetTypeName},
{"VGTextRowBuffer_GetTypeStatic", VGTextRowBuffer_GetTypeStatic},
{"VGTextRowBuffer_GetTypeNameStatic", VGTextRowBuffer_GetTypeNameStatic},
{"VGTextRowBuffer_VGTextRowBuffer", VGTextRowBuffer_VGTextRowBuffer},
{"VGTextRowBuffer_Clear", VGTextRowBuffer_Clear},
{"VGTextRowBuffer_AddRow", VGTextRowBuffer_AddRow},
{"VGTextRowBuffer_GetSize", VGTextRowBuffer_GetSize},
{"VGTextRowBuffer_GetRowData", VGTextRowBuffer_GetRowData},
{"VGTextRowBuffer_GetRowText", VGTextRowBuffer_GetRowText},
{"VGTextRowBuffer_GetRowMin", VGTextRowBuffer_GetRowMin},
{"VGTextRowBuffer_GetRowMax", VGTextRowBuffer_GetRowMax},
{"VGTextRowBuffer_GetRowWidth", VGTextRowBuffer_GetRowWidth},
{"Variant_GetTypeName", Variant_GetTypeName},
{"Variant_GetVariantMap", Variant_GetVariantMap},
{"Variant_GetString", Variant_GetString},
{"Variant_ToString", Variant_ToString},
{"Variant_GetBuffer", Variant_GetBuffer},
{"Variant_GetResourceRefName", Variant_GetResourceRefName},
{"Variant_GetResourceRefType", Variant_GetResourceRefType},
{"Variant_VariantVector_GetVariant", Variant_VariantVector_GetVariant},
{"Variant_VariantVector_GetSize", Variant_VariantVector_GetSize},
{"Variant_StringVector_GetString", Variant_StringVector_GetString},
{"Variant_StringVector_GetSize", Variant_StringVector_GetSize},
{"Variant_ResourceRefList_GetType", Variant_ResourceRefList_GetType},
{"Variant_ResourceRefList_Names_GetSize", Variant_ResourceRefList_Names_GetSize},
{"Variant_ResourceRefList_Names_GetNameAt", Variant_ResourceRefList_Names_GetNameAt},
{"Variant_EqualityOperator", Variant_EqualityOperator},
{"Variant_GetRetVariant", Variant_GetRetVariant},
{"VertexBuffer_GetElementMask", VertexBuffer_GetElementMask},
{"VertexBuffer_CastToGPUObject", VertexBuffer_CastToGPUObject},
{"VertexBuffer_GetType", VertexBuffer_GetType},
{"VertexBuffer_GetTypeName", VertexBuffer_GetTypeName},
{"VertexBuffer_GetTypeStatic", VertexBuffer_GetTypeStatic},
{"VertexBuffer_GetTypeNameStatic", VertexBuffer_GetTypeNameStatic},
{"VertexBuffer_VertexBuffer", VertexBuffer_VertexBuffer},
{"VertexBuffer_OnDeviceLost", VertexBuffer_OnDeviceLost},
{"VertexBuffer_Release", VertexBuffer_Release},
{"VertexBuffer_SetShadowed", VertexBuffer_SetShadowed},
{"VertexBuffer_SetSize", VertexBuffer_SetSize},
{"VertexBuffer_SetSize0", VertexBuffer_SetSize0},
{"VertexBuffer_SetData", VertexBuffer_SetData},
{"VertexBuffer_SetDataRange", VertexBuffer_SetDataRange},
{"VertexBuffer_Lock", VertexBuffer_Lock},
{"VertexBuffer_Unlock", VertexBuffer_Unlock},
{"VertexBuffer_IsShadowed", VertexBuffer_IsShadowed},
{"VertexBuffer_IsDynamic", VertexBuffer_IsDynamic},
{"VertexBuffer_IsLocked", VertexBuffer_IsLocked},
{"VertexBuffer_GetVertexCount", VertexBuffer_GetVertexCount},
{"VertexBuffer_GetVertexSize", VertexBuffer_GetVertexSize},
{"VertexBuffer_GetElement", VertexBuffer_GetElement},
{"VertexBuffer_GetElement1", VertexBuffer_GetElement1},
{"VertexBuffer_HasElement", VertexBuffer_HasElement},
{"VertexBuffer_HasElement2", VertexBuffer_HasElement2},
{"VertexBuffer_GetElementOffset", VertexBuffer_GetElementOffset},
{"VertexBuffer_GetElementOffset3", VertexBuffer_GetElementOffset3},
{"VertexBuffer_GetShadowData", VertexBuffer_GetShadowData},
{"VertexBuffer_GetBufferHash", VertexBuffer_GetBufferHash},
{"VertexBuffer_GetVertexSize4", VertexBuffer_GetVertexSize4},
{"Viewport_GetType", Viewport_GetType},
{"Viewport_GetTypeName", Viewport_GetTypeName},
{"Viewport_GetTypeStatic", Viewport_GetTypeStatic},
{"Viewport_GetTypeNameStatic", Viewport_GetTypeNameStatic},
{"Viewport_Viewport", Viewport_Viewport},
{"Viewport_Viewport0", Viewport_Viewport0},
{"Viewport_Viewport1", Viewport_Viewport1},
{"Viewport_SetScene", Viewport_SetScene},
{"Viewport_SetCamera", Viewport_SetCamera},
{"Viewport_SetRect", Viewport_SetRect},
{"Viewport_SetRenderPath", Viewport_SetRenderPath},
{"Viewport_SetRenderPath2", Viewport_SetRenderPath2},
{"Viewport_SetDrawDebug", Viewport_SetDrawDebug},
{"Viewport_SetCullCamera", Viewport_SetCullCamera},
{"Viewport_GetScene", Viewport_GetScene},
{"Viewport_GetCamera", Viewport_GetCamera},
{"Viewport_GetView", Viewport_GetView},
{"Viewport_GetRect", Viewport_GetRect},
{"Viewport_GetRenderPath", Viewport_GetRenderPath},
{"Viewport_GetDrawDebug", Viewport_GetDrawDebug},
{"Viewport_GetCullCamera", Viewport_GetCullCamera},
{"Viewport_GetScreenRay", Viewport_GetScreenRay},
{"Viewport_WorldToScreenPoint", Viewport_WorldToScreenPoint},
{"Viewport_ScreenToWorldPoint", Viewport_ScreenToWorldPoint},
{"Viewport_AllocateView", Viewport_AllocateView},
{"Viewport_SetClearColor", Viewport_SetClearColor},
{"float_convert_to_string", float_convert_to_string},
{"double_convert_to_string", double_convert_to_string},
{"Quaternion_FromLookRotation", Quaternion_FromLookRotation},
{"RegisterMonoNativeCallbacks", RegisterMonoNativeCallbacks},
{"urho_unsubscribe", urho_unsubscribe},
{"VectorSharedPtr_Count", VectorSharedPtr_Count},
{"VectorSharedPtr_GetIdx", VectorSharedPtr_GetIdx},
{"PodVectorUint_Count", PodVectorUint_Count},
{"PodVectorUint_GetIdx", PodVectorUint_GetIdx},
{"Animatable_GetType", Animatable_GetType},
{"Animatable_GetTypeName", Animatable_GetTypeName},
{"Animatable_GetTypeStatic", Animatable_GetTypeStatic},
{"Animatable_GetTypeNameStatic", Animatable_GetTypeNameStatic},
{"Animatable_RegisterObject", Animatable_RegisterObject},
{"Animatable_LoadXML", Animatable_LoadXML},
{"Animatable_SaveXML", Animatable_SaveXML},
{"Animatable_SetAnimationEnabled", Animatable_SetAnimationEnabled},
{"Animatable_SetAnimationTime", Animatable_SetAnimationTime},
{"Animatable_SetObjectAnimation", Animatable_SetObjectAnimation},
{"Animatable_SetAttributeAnimation", Animatable_SetAttributeAnimation},
{"Animatable_SetAttributeAnimationWrapMode", Animatable_SetAttributeAnimationWrapMode},
{"Animatable_SetAttributeAnimationSpeed", Animatable_SetAttributeAnimationSpeed},
{"Animatable_SetAttributeAnimationTime", Animatable_SetAttributeAnimationTime},
{"Animatable_RemoveObjectAnimation", Animatable_RemoveObjectAnimation},
{"Animatable_RemoveAttributeAnimation", Animatable_RemoveAttributeAnimation},
{"Animatable_GetAnimationEnabled", Animatable_GetAnimationEnabled},
{"Animatable_GetObjectAnimation", Animatable_GetObjectAnimation},
{"Animatable_GetAttributeAnimation", Animatable_GetAttributeAnimation},
{"Animatable_GetAttributeAnimationWrapMode", Animatable_GetAttributeAnimationWrapMode},
{"Animatable_GetAttributeAnimationSpeed", Animatable_GetAttributeAnimationSpeed},
{"Animatable_GetAttributeAnimationTime", Animatable_GetAttributeAnimationTime},
{"Animatable_GetObjectAnimationAttr", Animatable_GetObjectAnimationAttr},
{"AnimationController_GetType", AnimationController_GetType},
{"AnimationController_GetTypeName", AnimationController_GetTypeName},
{"AnimationController_GetTypeStatic", AnimationController_GetTypeStatic},
{"AnimationController_GetTypeNameStatic", AnimationController_GetTypeNameStatic},
{"AnimationController_AnimationController", AnimationController_AnimationController},
{"AnimationController_RegisterObject", AnimationController_RegisterObject},
{"AnimationController_OnSetEnabled", AnimationController_OnSetEnabled},
{"AnimationController_Update", AnimationController_Update},
{"AnimationController_Play", AnimationController_Play},
{"AnimationController_PlayExclusive", AnimationController_PlayExclusive},
{"AnimationController_Stop", AnimationController_Stop},
{"AnimationController_StopLayer", AnimationController_StopLayer},
{"AnimationController_StopAll", AnimationController_StopAll},
{"AnimationController_Fade", AnimationController_Fade},
{"AnimationController_FadeOthers", AnimationController_FadeOthers},
{"AnimationController_SetLayer", AnimationController_SetLayer},
{"AnimationController_SetStartBone", AnimationController_SetStartBone},
{"AnimationController_SetTime", AnimationController_SetTime},
{"AnimationController_SetWeight", AnimationController_SetWeight},
{"AnimationController_SetLooped", AnimationController_SetLooped},
{"AnimationController_SetSpeed", AnimationController_SetSpeed},
{"AnimationController_SetAutoFade", AnimationController_SetAutoFade},
{"AnimationController_SetRemoveOnCompletion", AnimationController_SetRemoveOnCompletion},
{"AnimationController_SetBlendMode", AnimationController_SetBlendMode},
{"AnimationController_IsPlaying", AnimationController_IsPlaying},
{"AnimationController_IsPlaying0", AnimationController_IsPlaying0},
{"AnimationController_IsFadingIn", AnimationController_IsFadingIn},
{"AnimationController_IsFadingOut", AnimationController_IsFadingOut},
{"AnimationController_IsAtEnd", AnimationController_IsAtEnd},
{"AnimationController_GetLayer", AnimationController_GetLayer},
{"AnimationController_GetStartBone", AnimationController_GetStartBone},
{"AnimationController_GetStartBoneName", AnimationController_GetStartBoneName},
{"AnimationController_GetTime", AnimationController_GetTime},
{"AnimationController_GetWeight", AnimationController_GetWeight},
{"AnimationController_IsLooped", AnimationController_IsLooped},
{"AnimationController_GetBlendMode", AnimationController_GetBlendMode},
{"AnimationController_GetLength", AnimationController_GetLength},
{"AnimationController_GetSpeed", AnimationController_GetSpeed},
{"AnimationController_GetFadeTarget", AnimationController_GetFadeTarget},
{"AnimationController_GetFadeTime", AnimationController_GetFadeTime},
{"AnimationController_GetAutoFade", AnimationController_GetAutoFade},
{"AnimationController_GetRemoveOnCompletion", AnimationController_GetRemoveOnCompletion},
{"AnimationController_GetAnimationState", AnimationController_GetAnimationState},
{"AnimationController_GetAnimationState1", AnimationController_GetAnimationState1},
{"AnimationState_AnimationState", AnimationState_AnimationState},
{"AnimationState_AnimationState0", AnimationState_AnimationState0},
{"AnimationState_SetStartBone", AnimationState_SetStartBone},
{"AnimationState_SetLooped", AnimationState_SetLooped},
{"AnimationState_SetWeight", AnimationState_SetWeight},
{"AnimationState_SetBlendMode", AnimationState_SetBlendMode},
{"AnimationState_SetTime", AnimationState_SetTime},
{"AnimationState_SetBoneWeight", AnimationState_SetBoneWeight},
{"AnimationState_SetBoneWeight1", AnimationState_SetBoneWeight1},
{"AnimationState_SetBoneWeight2", AnimationState_SetBoneWeight2},
{"AnimationState_AddWeight", AnimationState_AddWeight},
{"AnimationState_AddTime", AnimationState_AddTime},
{"AnimationState_SetLayer", AnimationState_SetLayer},
{"AnimationState_GetAnimation", AnimationState_GetAnimation},
{"AnimationState_GetModel", AnimationState_GetModel},
{"AnimationState_GetNode", AnimationState_GetNode},
{"AnimationState_GetStartBone", AnimationState_GetStartBone},
{"AnimationState_GetBoneWeight", AnimationState_GetBoneWeight},
{"AnimationState_GetBoneWeight3", AnimationState_GetBoneWeight3},
{"AnimationState_GetBoneWeight4", AnimationState_GetBoneWeight4},
{"AnimationState_GetTrackIndex", AnimationState_GetTrackIndex},
{"AnimationState_GetTrackIndex5", AnimationState_GetTrackIndex5},
{"AnimationState_GetTrackIndex6", AnimationState_GetTrackIndex6},
{"AnimationState_IsEnabled", AnimationState_IsEnabled},
{"AnimationState_IsLooped", AnimationState_IsLooped},
{"AnimationState_GetWeight", AnimationState_GetWeight},
{"AnimationState_GetBlendMode", AnimationState_GetBlendMode},
{"AnimationState_GetTime", AnimationState_GetTime},
{"AnimationState_GetLength", AnimationState_GetLength},
{"AnimationState_GetLayer", AnimationState_GetLayer},
{"AnimationState_Apply", AnimationState_Apply},
{"AreaAllocator_AreaAllocator", AreaAllocator_AreaAllocator},
{"AreaAllocator_AreaAllocator0", AreaAllocator_AreaAllocator0},
{"AreaAllocator_AreaAllocator1", AreaAllocator_AreaAllocator1},
{"AreaAllocator_Reset", AreaAllocator_Reset},
{"AreaAllocator_Allocate", AreaAllocator_Allocate},
{"AreaAllocator_GetWidth", AreaAllocator_GetWidth},
{"AreaAllocator_GetHeight", AreaAllocator_GetHeight},
{"AreaAllocator_GetFastMode", AreaAllocator_GetFastMode},
{"AttributeAccessor_Set_0", AttributeAccessor_Set_0},
{"AttributeAccessor_Set_1", AttributeAccessor_Set_1},
{"AttributeAccessor_Set_2", AttributeAccessor_Set_2},
{"AttributeAccessor_Set_3", AttributeAccessor_Set_3},
{"AttributeAccessor_Set_4", AttributeAccessor_Set_4},
{"AttributeAccessor_Set_5", AttributeAccessor_Set_5},
{"AttributeAccessor_Set_6", AttributeAccessor_Set_6},
{"AttributeAccessor_Set_7", AttributeAccessor_Set_7},
{"AttributeAccessor_Set_8", AttributeAccessor_Set_8},
{"AttributeAccessor_Set_9", AttributeAccessor_Set_9},
{"AttributeAccessor_Set_10", AttributeAccessor_Set_10},
{"AttributeAccessor_Set_11", AttributeAccessor_Set_11},
{"AttributeAccessor_Set_12", AttributeAccessor_Set_12},
{"AttributeAccessor_Set_13", AttributeAccessor_Set_13},
{"AttributeAccessor_Set_14", AttributeAccessor_Set_14},
{"Automation_GetType", Automation_GetType},
{"Automation_GetTypeName", Automation_GetTypeName},
{"Automation_GetTypeStatic", Automation_GetTypeStatic},
{"Automation_GetTypeNameStatic", Automation_GetTypeNameStatic},
{"Automation_Automation", Automation_Automation},
{"Automation_IsAvaliable", Automation_IsAvaliable},
{"Automation_MouseClick", Automation_MouseClick},
{"Automation_MousePress", Automation_MousePress},
{"Automation_MouseRelease", Automation_MouseRelease},
{"Automation_MouseScrollH", Automation_MouseScrollH},
{"Automation_MouseScrollV", Automation_MouseScrollV},
{"Automation_MouseGetPos", Automation_MouseGetPos},
{"Automation_MouseSetPos", Automation_MouseSetPos},
{"Automation_MouseSetPos0", Automation_MouseSetPos0},
{"Automation_MouseGetState", Automation_MouseGetState},
{"Automation_KeyboardClick", Automation_KeyboardClick},
{"Automation_KeyboardPress", Automation_KeyboardPress},
{"Automation_KeyboardRelease", Automation_KeyboardRelease},
{"Automation_KeyboardGetState", Automation_KeyboardGetState},
{"Automation_GetScreenBounds", Automation_GetScreenBounds},
{"ConstantBuffer_CastToGPUObject", ConstantBuffer_CastToGPUObject},
{"ConstantBuffer_GetType", ConstantBuffer_GetType},
{"ConstantBuffer_GetTypeName", ConstantBuffer_GetTypeName},
{"ConstantBuffer_GetTypeStatic", ConstantBuffer_GetTypeStatic},
{"ConstantBuffer_GetTypeNameStatic", ConstantBuffer_GetTypeNameStatic},
{"ConstantBuffer_ConstantBuffer", ConstantBuffer_ConstantBuffer},
{"ConstantBuffer_Release", ConstantBuffer_Release},
{"ConstantBuffer_SetSize", ConstantBuffer_SetSize},
{"ConstantBuffer_SetParameter", ConstantBuffer_SetParameter},
{"ConstantBuffer_SetVector3ArrayParameter", ConstantBuffer_SetVector3ArrayParameter},
{"ConstantBuffer_Apply", ConstantBuffer_Apply},
{"ConstantBuffer_GetSize", ConstantBuffer_GetSize},
{"ConstantBuffer_IsDirty", ConstantBuffer_IsDirty},
{"ConvexData_ConvexData", ConvexData_ConvexData},
{"ConvexData_ConvexData0", ConvexData_ConvexData0},
{"CustomGeometry_GetType", CustomGeometry_GetType},
{"CustomGeometry_GetTypeName", CustomGeometry_GetTypeName},
{"CustomGeometry_GetTypeStatic", CustomGeometry_GetTypeStatic},
{"CustomGeometry_GetTypeNameStatic", CustomGeometry_GetTypeNameStatic},
{"CustomGeometry_CustomGeometry", CustomGeometry_CustomGeometry},
{"CustomGeometry_RegisterObject", CustomGeometry_RegisterObject},
{"CustomGeometry_GetLodGeometry", CustomGeometry_GetLodGeometry},
{"CustomGeometry_GetNumOccluderTriangles", CustomGeometry_GetNumOccluderTriangles},
{"CustomGeometry_DrawOcclusion", CustomGeometry_DrawOcclusion},
{"CustomGeometry_Clear", CustomGeometry_Clear},
{"CustomGeometry_SetNumGeometries", CustomGeometry_SetNumGeometries},
{"CustomGeometry_SetDynamic", CustomGeometry_SetDynamic},
{"CustomGeometry_BeginGeometry", CustomGeometry_BeginGeometry},
{"CustomGeometry_DefineVertex", CustomGeometry_DefineVertex},
{"CustomGeometry_DefineNormal", CustomGeometry_DefineNormal},
{"CustomGeometry_DefineColor", CustomGeometry_DefineColor},
{"CustomGeometry_DefineTexCoord", CustomGeometry_DefineTexCoord},
{"CustomGeometry_DefineTangent", CustomGeometry_DefineTangent},
{"CustomGeometry_DefineGeometry", CustomGeometry_DefineGeometry},
{"CustomGeometry_Commit", CustomGeometry_Commit},
{"CustomGeometry_SetMaterial", CustomGeometry_SetMaterial},
{"CustomGeometry_SetMaterial0", CustomGeometry_SetMaterial0},
{"CustomGeometry_GetNumGeometries", CustomGeometry_GetNumGeometries},
{"CustomGeometry_GetNumVertices", CustomGeometry_GetNumVertices},
{"CustomGeometry_IsDynamic", CustomGeometry_IsDynamic},
{"CustomGeometry_GetMaterial", CustomGeometry_GetMaterial},
{"CustomGeometry_GetVertex", CustomGeometry_GetVertex},
{"Database_GetType", Database_GetType},
{"Database_GetTypeName", Database_GetTypeName},
{"Database_GetTypeStatic", Database_GetTypeStatic},
{"Database_GetTypeNameStatic", Database_GetTypeNameStatic},
{"Database_Database", Database_Database},
{"Database_GetAPI", Database_GetAPI},
{"Database_Connect", Database_Connect},
{"Database_Disconnect", Database_Disconnect},
{"Database_IsPooling", Database_IsPooling},
{"Database_GetPoolSize", Database_GetPoolSize},
{"Database_SetPoolSize", Database_SetPoolSize},
{"DebugHud_GetType", DebugHud_GetType},
{"DebugHud_GetTypeName", DebugHud_GetTypeName},
{"DebugHud_GetTypeStatic", DebugHud_GetTypeStatic},
{"DebugHud_GetTypeNameStatic", DebugHud_GetTypeNameStatic},
{"DebugHud_DebugHud", DebugHud_DebugHud},
{"DebugHud_Update", DebugHud_Update},
{"DebugHud_SetDefaultStyle", DebugHud_SetDefaultStyle},
{"DebugHud_SetMode", DebugHud_SetMode},
{"DebugHud_SetProfilerMaxDepth", DebugHud_SetProfilerMaxDepth},
{"DebugHud_SetProfilerInterval", DebugHud_SetProfilerInterval},
{"DebugHud_SetUseRendererStats", DebugHud_SetUseRendererStats},
{"DebugHud_Toggle", DebugHud_Toggle},
{"DebugHud_ToggleAll", DebugHud_ToggleAll},
{"DebugHud_GetDefaultStyle", DebugHud_GetDefaultStyle},
{"DebugHud_GetStatsText", DebugHud_GetStatsText},
{"DebugHud_GetModeText", DebugHud_GetModeText},
{"DebugHud_GetProfilerText", DebugHud_GetProfilerText},
{"DebugHud_GetMemoryText", DebugHud_GetMemoryText},
{"DebugHud_GetMode", DebugHud_GetMode},
{"DebugHud_GetProfilerMaxDepth", DebugHud_GetProfilerMaxDepth},
{"DebugHud_GetProfilerInterval", DebugHud_GetProfilerInterval},
{"DebugHud_GetUseRendererStats", DebugHud_GetUseRendererStats},
{"DebugHud_SetAppStats", DebugHud_SetAppStats},
{"DebugHud_ResetAppStats", DebugHud_ResetAppStats},
{"DebugHud_ClearAppStats", DebugHud_ClearAppStats},
{"DebugRenderer_GetType", DebugRenderer_GetType},
{"DebugRenderer_GetTypeName", DebugRenderer_GetTypeName},
{"DebugRenderer_GetTypeStatic", DebugRenderer_GetTypeStatic},
{"DebugRenderer_GetTypeNameStatic", DebugRenderer_GetTypeNameStatic},
{"DebugRenderer_DebugRenderer", DebugRenderer_DebugRenderer},
{"DebugRenderer_RegisterObject", DebugRenderer_RegisterObject},
{"DebugRenderer_SetLineAntiAlias", DebugRenderer_SetLineAntiAlias},
{"DebugRenderer_SetView", DebugRenderer_SetView},
{"DebugRenderer_AddLine", DebugRenderer_AddLine},
{"DebugRenderer_AddLine0", DebugRenderer_AddLine0},
{"DebugRenderer_AddTriangle", DebugRenderer_AddTriangle},
{"DebugRenderer_AddTriangle1", DebugRenderer_AddTriangle1},
{"DebugRenderer_AddPolygon", DebugRenderer_AddPolygon},
{"DebugRenderer_AddPolygon2", DebugRenderer_AddPolygon2},
{"DebugRenderer_AddNode", DebugRenderer_AddNode},
{"DebugRenderer_AddBoundingBox", DebugRenderer_AddBoundingBox},
{"DebugRenderer_AddBoundingBox3", DebugRenderer_AddBoundingBox3},
{"DebugRenderer_AddFrustum", DebugRenderer_AddFrustum},
{"DebugRenderer_AddPolyhedron", DebugRenderer_AddPolyhedron},
{"DebugRenderer_AddSphere", DebugRenderer_AddSphere},
{"DebugRenderer_AddSphereSector", DebugRenderer_AddSphereSector},
{"DebugRenderer_AddCylinder", DebugRenderer_AddCylinder},
{"DebugRenderer_AddTriangleMesh", DebugRenderer_AddTriangleMesh},
{"DebugRenderer_AddTriangleMesh4", DebugRenderer_AddTriangleMesh4},
{"DebugRenderer_AddCircle", DebugRenderer_AddCircle},
{"DebugRenderer_AddCross", DebugRenderer_AddCross},
{"DebugRenderer_AddQuad", DebugRenderer_AddQuad},
{"DebugRenderer_Render", DebugRenderer_Render},
{"DebugRenderer_GetLineAntiAlias", DebugRenderer_GetLineAntiAlias},
{"DebugRenderer_GetView", DebugRenderer_GetView},
{"DebugRenderer_GetProjection", DebugRenderer_GetProjection},
{"DebugRenderer_GetFrustum", DebugRenderer_GetFrustum},
{"DebugRenderer_IsInside", DebugRenderer_IsInside},
{"DebugRenderer_HasContent", DebugRenderer_HasContent},
{"DecalSet_GetType", DecalSet_GetType},
{"DecalSet_GetTypeName", DecalSet_GetTypeName},
{"DecalSet_GetTypeStatic", DecalSet_GetTypeStatic},
{"DecalSet_GetTypeNameStatic", DecalSet_GetTypeNameStatic},
{"DecalSet_DecalSet", DecalSet_DecalSet},
{"DecalSet_RegisterObject", DecalSet_RegisterObject},
{"DecalSet_ApplyAttributes", DecalSet_ApplyAttributes},
{"DecalSet_OnSetEnabled", DecalSet_OnSetEnabled},
{"DecalSet_GetUpdateGeometryType", DecalSet_GetUpdateGeometryType},
{"DecalSet_SetMaterial", DecalSet_SetMaterial},
{"DecalSet_SetMaxVertices", DecalSet_SetMaxVertices},
{"DecalSet_SetMaxIndices", DecalSet_SetMaxIndices},
{"DecalSet_SetOptimizeBufferSize", DecalSet_SetOptimizeBufferSize},
{"DecalSet_AddDecal", DecalSet_AddDecal},
{"DecalSet_RemoveDecals", DecalSet_RemoveDecals},
{"DecalSet_RemoveAllDecals", DecalSet_RemoveAllDecals},
{"DecalSet_GetMaterial", DecalSet_GetMaterial},
{"DecalSet_GetNumDecals", DecalSet_GetNumDecals},
{"DecalSet_GetNumVertices", DecalSet_GetNumVertices},
{"DecalSet_GetNumIndices", DecalSet_GetNumIndices},
{"DecalSet_GetMaxVertices", DecalSet_GetMaxVertices},
{"DecalSet_GetMaxIndices", DecalSet_GetMaxIndices},
{"DecalSet_GetOptimizeBufferSize", DecalSet_GetOptimizeBufferSize},
{"DecalSet_GetMaterialAttr", DecalSet_GetMaterialAttr},
{"Drawable_GetType", Drawable_GetType},
{"Drawable_GetTypeName", Drawable_GetTypeName},
{"Drawable_GetTypeStatic", Drawable_GetTypeStatic},
{"Drawable_GetTypeNameStatic", Drawable_GetTypeNameStatic},
{"Drawable_RegisterObject", Drawable_RegisterObject},
{"Drawable_OnSetEnabled", Drawable_OnSetEnabled},
{"Drawable_GetUpdateGeometryType", Drawable_GetUpdateGeometryType},
{"Drawable_GetLodGeometry", Drawable_GetLodGeometry},
{"Drawable_GetNumOccluderTriangles", Drawable_GetNumOccluderTriangles},
{"Drawable_DrawOcclusion", Drawable_DrawOcclusion},
{"Drawable_DrawDebugGeometry", Drawable_DrawDebugGeometry},
{"Drawable_SetDrawDistance", Drawable_SetDrawDistance},
{"Drawable_SetShadowDistance", Drawable_SetShadowDistance},
{"Drawable_SetLodBias", Drawable_SetLodBias},
{"Drawable_SetViewMask", Drawable_SetViewMask},
{"Drawable_SetLightMask", Drawable_SetLightMask},
{"Drawable_SetShadowMask", Drawable_SetShadowMask},
{"Drawable_SetZoneMask", Drawable_SetZoneMask},
{"Drawable_SetMaxLights", Drawable_SetMaxLights},
{"Drawable_SetCastShadows", Drawable_SetCastShadows},
{"Drawable_SetOccluder", Drawable_SetOccluder},
{"Drawable_SetOccludee", Drawable_SetOccludee},
{"Drawable_MarkForUpdate", Drawable_MarkForUpdate},
{"Drawable_GetBoundingBox", Drawable_GetBoundingBox},
{"Drawable_GetWorldBoundingBox", Drawable_GetWorldBoundingBox},
{"Drawable_GetDrawableFlags", Drawable_GetDrawableFlags},
{"Drawable_GetDrawDistance", Drawable_GetDrawDistance},
{"Drawable_GetShadowDistance", Drawable_GetShadowDistance},
{"Drawable_GetLodBias", Drawable_GetLodBias},
{"Drawable_GetViewMask", Drawable_GetViewMask},
{"Drawable_GetLightMask", Drawable_GetLightMask},
{"Drawable_GetShadowMask", Drawable_GetShadowMask},
{"Drawable_GetZoneMask", Drawable_GetZoneMask},
{"Drawable_GetMaxLights", Drawable_GetMaxLights},
{"Drawable_GetCastShadows", Drawable_GetCastShadows},
{"Drawable_IsOccluder", Drawable_IsOccluder},
{"Drawable_IsOccludee", Drawable_IsOccludee},
{"Drawable_IsInView", Drawable_IsInView},
{"Drawable_IsInView0", Drawable_IsInView0},
{"Drawable_SetZone", Drawable_SetZone},
{"Drawable_SetSortValue", Drawable_SetSortValue},
{"Drawable_SetMinMaxZ", Drawable_SetMinMaxZ},
{"Drawable_MarkInView", Drawable_MarkInView},
{"Drawable_LimitLights", Drawable_LimitLights},
{"Drawable_LimitVertexLights", Drawable_LimitVertexLights},
{"Drawable_SetBasePass", Drawable_SetBasePass},
{"Drawable_GetOctant", Drawable_GetOctant},
{"Drawable_GetZone", Drawable_GetZone},
{"Drawable_IsZoneDirty", Drawable_IsZoneDirty},
{"Drawable_GetDistance", Drawable_GetDistance},
{"Drawable_GetLodDistance", Drawable_GetLodDistance},
{"Drawable_GetSortValue", Drawable_GetSortValue},
{"Drawable_HasBasePass", Drawable_HasBasePass},
{"Drawable_GetFirstLight", Drawable_GetFirstLight},
{"Drawable_GetMinZ", Drawable_GetMinZ},
{"Drawable_GetMaxZ", Drawable_GetMaxZ},
{"Drawable_AddLight", Drawable_AddLight},
{"Drawable_AddVertexLight", Drawable_AddVertexLight},
{"Engine_GetType", Engine_GetType},
{"Engine_GetTypeName", Engine_GetTypeName},
{"Engine_GetTypeStatic", Engine_GetTypeStatic},
{"Engine_GetTypeNameStatic", Engine_GetTypeNameStatic},
{"Engine_Engine", Engine_Engine},
{"Engine_RunFrame", Engine_RunFrame},
{"Engine_CreateConsole", Engine_CreateConsole},
{"Engine_CreateDebugHud", Engine_CreateDebugHud},
{"Engine_SetMinFps", Engine_SetMinFps},
{"Engine_SetMaxFps", Engine_SetMaxFps},
{"Engine_SetMaxInactiveFps", Engine_SetMaxInactiveFps},
{"Engine_SetTimeStepSmoothing", Engine_SetTimeStepSmoothing},
{"Engine_SetPauseMinimized", Engine_SetPauseMinimized},
{"Engine_SetAutoExit", Engine_SetAutoExit},
{"Engine_SetNextTimeStep", Engine_SetNextTimeStep},
{"Engine_Exit", Engine_Exit},
{"Engine_DumpProfiler", Engine_DumpProfiler},
{"Engine_DumpResources", Engine_DumpResources},
{"Engine_DumpMemory", Engine_DumpMemory},
{"Engine_GetNextTimeStep", Engine_GetNextTimeStep},
{"Engine_GetMinFps", Engine_GetMinFps},
{"Engine_GetMaxFps", Engine_GetMaxFps},
{"Engine_GetMaxInactiveFps", Engine_GetMaxInactiveFps},
{"Engine_GetTimeStepSmoothing", Engine_GetTimeStepSmoothing},
{"Engine_GetPauseMinimized", Engine_GetPauseMinimized},
{"Engine_GetAutoExit", Engine_GetAutoExit},
{"Engine_IsInitialized", Engine_IsInitialized},
{"Engine_IsExiting", Engine_IsExiting},
{"Engine_IsHeadless", Engine_IsHeadless},
{"Engine_Update", Engine_Update},
{"Engine_Render", Engine_Render},
{"Engine_ApplyFrameLimit", Engine_ApplyFrameLimit},
{"EventReceiverGroup_EventReceiverGroup", EventReceiverGroup_EventReceiverGroup},
{"EventReceiverGroup_BeginSendEvent", EventReceiverGroup_BeginSendEvent},
{"EventReceiverGroup_EndSendEvent", EventReceiverGroup_EndSendEvent},
{"EventReceiverGroup_Add", EventReceiverGroup_Add},
{"EventReceiverGroup_Remove", EventReceiverGroup_Remove},
{"GImpactMeshData_GImpactMeshData", GImpactMeshData_GImpactMeshData},
{"GImpactMeshData_GImpactMeshData0", GImpactMeshData_GImpactMeshData0},
{"Geometry_GetType", Geometry_GetType},
{"Geometry_GetTypeName", Geometry_GetTypeName},
{"Geometry_GetTypeStatic", Geometry_GetTypeStatic},
{"Geometry_GetTypeNameStatic", Geometry_GetTypeNameStatic},
{"Geometry_Geometry", Geometry_Geometry},
{"Geometry_SetNumVertexBuffers", Geometry_SetNumVertexBuffers},
{"Geometry_SetVertexBuffer", Geometry_SetVertexBuffer},
{"Geometry_SetIndexBuffer", Geometry_SetIndexBuffer},
{"Geometry_SetDrawRange", Geometry_SetDrawRange},
{"Geometry_SetDrawRange0", Geometry_SetDrawRange0},
{"Geometry_SetLodDistance", Geometry_SetLodDistance},
{"Geometry_Draw", Geometry_Draw},
{"Geometry_GetVertexBuffers", Geometry_GetVertexBuffers},
{"Geometry_GetNumVertexBuffers", Geometry_GetNumVertexBuffers},
{"Geometry_GetVertexBuffer", Geometry_GetVertexBuffer},
{"Geometry_GetIndexBuffer", Geometry_GetIndexBuffer},
{"Geometry_GetPrimitiveType", Geometry_GetPrimitiveType},
{"Geometry_GetIndexStart", Geometry_GetIndexStart},
{"Geometry_GetIndexCount", Geometry_GetIndexCount},
{"Geometry_GetVertexStart", Geometry_GetVertexStart},
{"Geometry_GetVertexCount", Geometry_GetVertexCount},
{"Geometry_GetLodDistance", Geometry_GetLodDistance},
{"Geometry_GetBufferHash", Geometry_GetBufferHash},
{"Geometry_GetHitDistance", Geometry_GetHitDistance},
{"Geometry_IsInside", Geometry_IsInside},
{"Geometry_IsEmpty", Geometry_IsEmpty},
{"HeightfieldData_HeightfieldData", HeightfieldData_HeightfieldData},
{"HierarchyContainer_GetType", HierarchyContainer_GetType},
{"HierarchyContainer_GetTypeName", HierarchyContainer_GetTypeName},
{"HierarchyContainer_GetTypeStatic", HierarchyContainer_GetTypeStatic},
{"HierarchyContainer_GetTypeNameStatic", HierarchyContainer_GetTypeNameStatic},
{"HierarchyContainer_HierarchyContainer", HierarchyContainer_HierarchyContainer},
{"HierarchyContainer_RegisterObject", HierarchyContainer_RegisterObject},
{"HierarchyContainer_InsertChild", HierarchyContainer_InsertChild},
{"IKConstraint_GetType", IKConstraint_GetType},
{"IKConstraint_GetTypeName", IKConstraint_GetTypeName},
{"IKConstraint_GetTypeStatic", IKConstraint_GetTypeStatic},
{"IKConstraint_GetTypeNameStatic", IKConstraint_GetTypeNameStatic},
{"IKConstraint_IKConstraint", IKConstraint_IKConstraint},
{"IKConstraint_RegisterObject", IKConstraint_RegisterObject},
{"IKConstraint_GetStiffness", IKConstraint_GetStiffness},
{"IKConstraint_SetStiffness", IKConstraint_SetStiffness},
{"IKConstraint_GetStretchiness", IKConstraint_GetStretchiness},
{"IKConstraint_SetStretchiness", IKConstraint_SetStretchiness},
{"IKConstraint_GetLengthConstraints", IKConstraint_GetLengthConstraints},
{"IKConstraint_SetLengthConstraints", IKConstraint_SetLengthConstraints},
{"IKEffector_GetType", IKEffector_GetType},
{"IKEffector_GetTypeName", IKEffector_GetTypeName},
{"IKEffector_GetTypeStatic", IKEffector_GetTypeStatic},
{"IKEffector_GetTypeNameStatic", IKEffector_GetTypeNameStatic},
{"IKEffector_IKEffector", IKEffector_IKEffector},
{"IKEffector_RegisterObject", IKEffector_RegisterObject},
{"IKEffector_GetFeature", IKEffector_GetFeature},
{"IKEffector_SetFeature", IKEffector_SetFeature},
{"IKEffector_GetTargetNode", IKEffector_GetTargetNode},
{"IKEffector_SetTargetNode", IKEffector_SetTargetNode},
{"IKEffector_GetTargetName", IKEffector_GetTargetName},
{"IKEffector_SetTargetName", IKEffector_SetTargetName},
{"IKEffector_GetTargetPosition", IKEffector_GetTargetPosition},
{"IKEffector_SetTargetPosition", IKEffector_SetTargetPosition},
{"IKEffector_GetTargetRotation", IKEffector_GetTargetRotation},
{"IKEffector_SetTargetRotation", IKEffector_SetTargetRotation},
{"IKEffector_GetTargetRotationEuler", IKEffector_GetTargetRotationEuler},
{"IKEffector_SetTargetRotationEuler", IKEffector_SetTargetRotationEuler},
{"IKEffector_GetChainLength", IKEffector_GetChainLength},
{"IKEffector_SetChainLength", IKEffector_SetChainLength},
{"IKEffector_GetWeight", IKEffector_GetWeight},
{"IKEffector_SetWeight", IKEffector_SetWeight},
{"IKEffector_GetRotationWeight", IKEffector_GetRotationWeight},
{"IKEffector_SetRotationWeight", IKEffector_SetRotationWeight},
{"IKEffector_GetRotationDecay", IKEffector_GetRotationDecay},
{"IKEffector_SetRotationDecay", IKEffector_SetRotationDecay},
{"IKEffector_DrawDebugGeometry", IKEffector_DrawDebugGeometry},
{"IKEffector_DrawDebugGeometry0", IKEffector_DrawDebugGeometry0},
{"IKEffector_GetFEATURE_WEIGHT_NLERP", IKEffector_GetFEATURE_WEIGHT_NLERP},
{"IKEffector_GetFEATURE_INHERIT_PARENT_ROTATION", IKEffector_GetFEATURE_INHERIT_PARENT_ROTATION},
{"IKEffector_SetFEATURE_WEIGHT_NLERP", IKEffector_SetFEATURE_WEIGHT_NLERP},
{"IKEffector_SetFEATURE_INHERIT_PARENT_ROTATION", IKEffector_SetFEATURE_INHERIT_PARENT_ROTATION},
{"IKSolver_GetType", IKSolver_GetType},
{"IKSolver_GetTypeName", IKSolver_GetTypeName},
{"IKSolver_GetTypeStatic", IKSolver_GetTypeStatic},
{"IKSolver_GetTypeNameStatic", IKSolver_GetTypeNameStatic},
{"IKSolver_IKSolver", IKSolver_IKSolver},
{"IKSolver_RegisterObject", IKSolver_RegisterObject},
{"IKSolver_GetAlgorithm", IKSolver_GetAlgorithm},
{"IKSolver_SetAlgorithm", IKSolver_SetAlgorithm},
{"IKSolver_GetFeature", IKSolver_GetFeature},
{"IKSolver_SetFeature", IKSolver_SetFeature},
{"IKSolver_GetMaximumIterations", IKSolver_GetMaximumIterations},
{"IKSolver_SetMaximumIterations", IKSolver_SetMaximumIterations},
{"IKSolver_GetTolerance", IKSolver_GetTolerance},
{"IKSolver_SetTolerance", IKSolver_SetTolerance},
{"IKSolver_RebuildChainTrees", IKSolver_RebuildChainTrees},
{"IKSolver_RecalculateSegmentLengths", IKSolver_RecalculateSegmentLengths},
{"IKSolver_CalculateJointRotations", IKSolver_CalculateJointRotations},
{"IKSolver_Solve", IKSolver_Solve},
{"IKSolver_ApplyOriginalPoseToScene", IKSolver_ApplyOriginalPoseToScene},
{"IKSolver_ApplySceneToOriginalPose", IKSolver_ApplySceneToOriginalPose},
{"IKSolver_ApplyActivePoseToScene", IKSolver_ApplyActivePoseToScene},
{"IKSolver_ApplySceneToActivePose", IKSolver_ApplySceneToActivePose},
{"IKSolver_ApplyOriginalPoseToActivePose", IKSolver_ApplyOriginalPoseToActivePose},
{"IKSolver_DrawDebugGeometry", IKSolver_DrawDebugGeometry},
{"IKSolver_DrawDebugGeometry0", IKSolver_DrawDebugGeometry0},
{"IKSolver_GetFEATURE_JOINT_ROTATIONS", IKSolver_GetFEATURE_JOINT_ROTATIONS},
{"IKSolver_GetFEATURE_TARGET_ROTATIONS", IKSolver_GetFEATURE_TARGET_ROTATIONS},
{"IKSolver_GetFEATURE_UPDATE_ORIGINAL_POSE", IKSolver_GetFEATURE_UPDATE_ORIGINAL_POSE},
{"IKSolver_GetFEATURE_UPDATE_ACTIVE_POSE", IKSolver_GetFEATURE_UPDATE_ACTIVE_POSE},
{"IKSolver_GetFEATURE_USE_ORIGINAL_POSE", IKSolver_GetFEATURE_USE_ORIGINAL_POSE},
{"IKSolver_GetFEATURE_CONSTRAINTS", IKSolver_GetFEATURE_CONSTRAINTS},
{"IKSolver_GetFEATURE_AUTO_SOLVE", IKSolver_GetFEATURE_AUTO_SOLVE},
{"IKSolver_SetFEATURE_JOINT_ROTATIONS", IKSolver_SetFEATURE_JOINT_ROTATIONS},
{"IKSolver_SetFEATURE_TARGET_ROTATIONS", IKSolver_SetFEATURE_TARGET_ROTATIONS},
{"IKSolver_SetFEATURE_UPDATE_ORIGINAL_POSE", IKSolver_SetFEATURE_UPDATE_ORIGINAL_POSE},
{"IKSolver_SetFEATURE_UPDATE_ACTIVE_POSE", IKSolver_SetFEATURE_UPDATE_ACTIVE_POSE},
{"IKSolver_SetFEATURE_USE_ORIGINAL_POSE", IKSolver_SetFEATURE_USE_ORIGINAL_POSE},
{"IKSolver_SetFEATURE_CONSTRAINTS", IKSolver_SetFEATURE_CONSTRAINTS},
{"IKSolver_SetFEATURE_AUTO_SOLVE", IKSolver_SetFEATURE_AUTO_SOLVE},
{"JsonBuilder_GetType", JsonBuilder_GetType},
{"JsonBuilder_GetTypeName", JsonBuilder_GetTypeName},
{"JsonBuilder_GetTypeStatic", JsonBuilder_GetTypeStatic},
{"JsonBuilder_GetTypeNameStatic", JsonBuilder_GetTypeNameStatic},
{"JsonBuilder_JsonBuilder", JsonBuilder_JsonBuilder},
{"Light_GetType", Light_GetType},
{"Light_GetTypeName", Light_GetTypeName},
{"Light_GetTypeStatic", Light_GetTypeStatic},
{"Light_GetTypeNameStatic", Light_GetTypeNameStatic},
{"Light_Light", Light_Light},
{"Light_RegisterObject", Light_RegisterObject},
{"Light_DrawDebugGeometry", Light_DrawDebugGeometry},
{"Light_SetLightType", Light_SetLightType},
{"Light_SetPerVertex", Light_SetPerVertex},
{"Light_SetColor", Light_SetColor},
{"Light_SetTemperature", Light_SetTemperature},
{"Light_SetRadius", Light_SetRadius},
{"Light_SetLength", Light_SetLength},
{"Light_SetUsePhysicalValues", Light_SetUsePhysicalValues},
{"Light_SetSpecularIntensity", Light_SetSpecularIntensity},
{"Light_SetBrightness", Light_SetBrightness},
{"Light_SetRange", Light_SetRange},
{"Light_SetFov", Light_SetFov},
{"Light_SetAspectRatio", Light_SetAspectRatio},
{"Light_SetFadeDistance", Light_SetFadeDistance},
{"Light_SetShadowFadeDistance", Light_SetShadowFadeDistance},
{"Light_SetShadowBias", Light_SetShadowBias},
{"Light_SetShadowCascade", Light_SetShadowCascade},
{"Light_SetShadowFocus", Light_SetShadowFocus},
{"Light_SetShadowIntensity", Light_SetShadowIntensity},
{"Light_SetShadowResolution", Light_SetShadowResolution},
{"Light_SetShadowNearFarRatio", Light_SetShadowNearFarRatio},
{"Light_SetShadowMaxExtrusion", Light_SetShadowMaxExtrusion},
{"Light_SetRampTexture", Light_SetRampTexture},
{"Light_SetShapeTexture", Light_SetShapeTexture},
{"Light_GetLightType", Light_GetLightType},
{"Light_GetPerVertex", Light_GetPerVertex},
{"Light_GetColor", Light_GetColor},
{"Light_GetTemperature", Light_GetTemperature},
{"Light_GetRadius", Light_GetRadius},
{"Light_GetLength", Light_GetLength},
{"Light_GetUsePhysicalValues", Light_GetUsePhysicalValues},
{"Light_GetColorFromTemperature", Light_GetColorFromTemperature},
{"Light_GetSpecularIntensity", Light_GetSpecularIntensity},
{"Light_GetBrightness", Light_GetBrightness},
{"Light_GetEffectiveColor", Light_GetEffectiveColor},
{"Light_GetEffectiveSpecularIntensity", Light_GetEffectiveSpecularIntensity},
{"Light_GetRange", Light_GetRange},
{"Light_GetFov", Light_GetFov},
{"Light_GetAspectRatio", Light_GetAspectRatio},
{"Light_GetFadeDistance", Light_GetFadeDistance},
{"Light_GetShadowFadeDistance", Light_GetShadowFadeDistance},
{"Light_GetShadowBias", Light_GetShadowBias},
{"Light_GetShadowCascade", Light_GetShadowCascade},
{"Light_GetShadowFocus", Light_GetShadowFocus},
{"Light_GetShadowIntensity", Light_GetShadowIntensity},
{"Light_GetShadowResolution", Light_GetShadowResolution},
{"Light_GetShadowNearFarRatio", Light_GetShadowNearFarRatio},
{"Light_GetShadowMaxExtrusion", Light_GetShadowMaxExtrusion},
{"Light_GetRampTexture", Light_GetRampTexture},
{"Light_GetShapeTexture", Light_GetShapeTexture},
{"Light_GetFrustum", Light_GetFrustum},
{"Light_GetViewSpaceFrustum", Light_GetViewSpaceFrustum},
{"Light_GetNumShadowSplits", Light_GetNumShadowSplits},
{"Light_IsNegative", Light_IsNegative},
{"Light_SetIntensitySortValue", Light_SetIntensitySortValue},
{"Light_SetIntensitySortValue0", Light_SetIntensitySortValue0},
{"Light_SetLightQueue", Light_SetLightQueue},
{"Light_GetVolumeTransform", Light_GetVolumeTransform},
{"Light_GetLightQueue", Light_GetLightQueue},
{"Light_GetIntensityDivisor", Light_GetIntensityDivisor},
{"Light_GetRampTextureAttr", Light_GetRampTextureAttr},
{"Light_GetShapeTextureAttr", Light_GetShapeTextureAttr},
{"Light_GetFullscreenQuadTransform", Light_GetFullscreenQuadTransform},
{"Time_GetType", Time_GetType},
{"Time_GetTypeName", Time_GetTypeName},
{"Time_GetTypeStatic", Time_GetTypeStatic},
{"Time_GetTypeNameStatic", Time_GetTypeNameStatic},
{"Time_Time", Time_Time},
{"Time_BeginFrame", Time_BeginFrame},
{"Time_EndFrame", Time_EndFrame},
{"Time_SetTimerPeriod", Time_SetTimerPeriod},
{"Time_GetFrameNumber", Time_GetFrameNumber},
{"Time_GetTimeStep", Time_GetTimeStep},
{"Time_GetTimerPeriod", Time_GetTimerPeriod},
{"Time_GetElapsedTime", Time_GetElapsedTime},
{"Time_GetFramesPerSecond", Time_GetFramesPerSecond},
{"Time_GetSystemTime", Time_GetSystemTime},
{"Time_GetTimeSinceEpoch", Time_GetTimeSinceEpoch},
{"Time_GetTimeStamp", Time_GetTimeStamp},
{"Time_Sleep", Time_Sleep},
{"WorkQueue_GetType", WorkQueue_GetType},
{"WorkQueue_GetTypeName", WorkQueue_GetTypeName},
{"WorkQueue_GetTypeStatic", WorkQueue_GetTypeStatic},
{"WorkQueue_GetTypeNameStatic", WorkQueue_GetTypeNameStatic},
{"WorkQueue_WorkQueue", WorkQueue_WorkQueue},
{"WorkQueue_CreateThreads", WorkQueue_CreateThreads},
{"WorkQueue_GetFreeItem", WorkQueue_GetFreeItem},
{"WorkQueue_Pause", WorkQueue_Pause},
{"WorkQueue_Resume", WorkQueue_Resume},
{"WorkQueue_Complete", WorkQueue_Complete},
{"WorkQueue_SetTolerance", WorkQueue_SetTolerance},
{"WorkQueue_SetNonThreadedWorkMs", WorkQueue_SetNonThreadedWorkMs},
{"WorkQueue_GetNumThreads", WorkQueue_GetNumThreads},
{"WorkQueue_IsCompleted", WorkQueue_IsCompleted},
{"WorkQueue_IsCompleting", WorkQueue_IsCompleting},
{"WorkQueue_GetTolerance", WorkQueue_GetTolerance},
{"WorkQueue_GetNonThreadedWorkMs", WorkQueue_GetNonThreadedWorkMs},
{"Terrain_GetType", Terrain_GetType},
{"Terrain_GetTypeName", Terrain_GetTypeName},
{"Terrain_GetTypeStatic", Terrain_GetTypeStatic},
{"Terrain_GetTypeNameStatic", Terrain_GetTypeNameStatic},
{"Terrain_Terrain", Terrain_Terrain},
{"Terrain_RegisterObject", Terrain_RegisterObject},
{"Terrain_ApplyAttributes", Terrain_ApplyAttributes},
{"Terrain_OnSetEnabled", Terrain_OnSetEnabled},
{"Terrain_SetPatchSize", Terrain_SetPatchSize},
{"Terrain_SetSpacing", Terrain_SetSpacing},
{"Terrain_SetMaxLodLevels", Terrain_SetMaxLodLevels},
{"Terrain_SetOcclusionLodLevel", Terrain_SetOcclusionLodLevel},
{"Terrain_SetSmoothing", Terrain_SetSmoothing},
{"Terrain_SetHeightMap", Terrain_SetHeightMap},
{"Terrain_SetMaterial", Terrain_SetMaterial},
{"Terrain_SetNorthNeighbor", Terrain_SetNorthNeighbor},
{"Terrain_SetSouthNeighbor", Terrain_SetSouthNeighbor},
{"Terrain_SetWestNeighbor", Terrain_SetWestNeighbor},
{"Terrain_SetEastNeighbor", Terrain_SetEastNeighbor},
{"Terrain_SetNeighbors", Terrain_SetNeighbors},
{"Terrain_SetDrawDistance", Terrain_SetDrawDistance},
{"Terrain_SetShadowDistance", Terrain_SetShadowDistance},
{"Terrain_SetLodBias", Terrain_SetLodBias},
{"Terrain_SetViewMask", Terrain_SetViewMask},
{"Terrain_SetLightMask", Terrain_SetLightMask},
{"Terrain_SetShadowMask", Terrain_SetShadowMask},
{"Terrain_SetZoneMask", Terrain_SetZoneMask},
{"Terrain_SetMaxLights", Terrain_SetMaxLights},
{"Terrain_SetCastShadows", Terrain_SetCastShadows},
{"Terrain_SetOccluder", Terrain_SetOccluder},
{"Terrain_SetOccludee", Terrain_SetOccludee},
{"Terrain_ApplyHeightMap", Terrain_ApplyHeightMap},
{"Terrain_GetPatchSize", Terrain_GetPatchSize},
{"Terrain_GetSpacing", Terrain_GetSpacing},
{"Terrain_GetNumVertices", Terrain_GetNumVertices},
{"Terrain_GetNumPatches", Terrain_GetNumPatches},
{"Terrain_GetMaxLodLevels", Terrain_GetMaxLodLevels},
{"Terrain_GetOcclusionLodLevel", Terrain_GetOcclusionLodLevel},
{"Terrain_GetSmoothing", Terrain_GetSmoothing},
{"Terrain_GetHeightMap", Terrain_GetHeightMap},
{"Terrain_GetMaterial", Terrain_GetMaterial},
{"Terrain_GetPatch", Terrain_GetPatch},
{"Terrain_GetPatch0", Terrain_GetPatch0},
{"Terrain_GetNeighborPatch", Terrain_GetNeighborPatch},
{"Terrain_GetHeight", Terrain_GetHeight},
{"Terrain_GetNormal", Terrain_GetNormal},
{"Terrain_WorldToHeightMap", Terrain_WorldToHeightMap},
{"Terrain_HeightMapToWorld", Terrain_HeightMapToWorld},
{"Terrain_GetNorthNeighbor", Terrain_GetNorthNeighbor},
{"Terrain_GetSouthNeighbor", Terrain_GetSouthNeighbor},
{"Terrain_GetWestNeighbor", Terrain_GetWestNeighbor},
{"Terrain_GetEastNeighbor", Terrain_GetEastNeighbor},
{"Terrain_GetDrawDistance", Terrain_GetDrawDistance},
{"Terrain_GetShadowDistance", Terrain_GetShadowDistance},
{"Terrain_GetLodBias", Terrain_GetLodBias},
{"Terrain_GetViewMask", Terrain_GetViewMask},
{"Terrain_GetLightMask", Terrain_GetLightMask},
{"Terrain_GetShadowMask", Terrain_GetShadowMask},
{"Terrain_GetZoneMask", Terrain_GetZoneMask},
{"Terrain_GetMaxLights", Terrain_GetMaxLights},
{"Terrain_IsVisible", Terrain_IsVisible},
{"Terrain_GetCastShadows", Terrain_GetCastShadows},
{"Terrain_IsOccluder", Terrain_IsOccluder},
{"Terrain_IsOccludee", Terrain_IsOccludee},
{"Terrain_CreatePatchGeometry", Terrain_CreatePatchGeometry},
{"Terrain_UpdatePatchLod", Terrain_UpdatePatchLod},
{"Terrain_SetPatchSizeAttr", Terrain_SetPatchSizeAttr},
{"Terrain_SetMaxLodLevelsAttr", Terrain_SetMaxLodLevelsAttr},
{"Terrain_SetOcclusionLodLevelAttr", Terrain_SetOcclusionLodLevelAttr},
{"Terrain_GetHeightMapAttr", Terrain_GetHeightMapAttr},
{"Terrain_GetMaterialAttr", Terrain_GetMaterialAttr},
{"Renderer_GetType", Renderer_GetType},
{"Renderer_GetTypeName", Renderer_GetTypeName},
{"Renderer_GetTypeStatic", Renderer_GetTypeStatic},
{"Renderer_GetTypeNameStatic", Renderer_GetTypeNameStatic},
{"Renderer_Renderer", Renderer_Renderer},
{"Renderer_SetNumViewports", Renderer_SetNumViewports},
{"Renderer_SetViewport", Renderer_SetViewport},
{"Renderer_SetDefaultRenderPath", Renderer_SetDefaultRenderPath},
{"Renderer_SetDefaultRenderPath0", Renderer_SetDefaultRenderPath0},
{"Renderer_SetDefaultTechnique", Renderer_SetDefaultTechnique},
{"Renderer_SetHDRRendering", Renderer_SetHDRRendering},
{"Renderer_SetSpecularLighting", Renderer_SetSpecularLighting},
{"Renderer_SetTextureAnisotropy", Renderer_SetTextureAnisotropy},
{"Renderer_SetTextureFilterMode", Renderer_SetTextureFilterMode},
{"Renderer_SetTextureQuality", Renderer_SetTextureQuality},
{"Renderer_SetMaterialQuality", Renderer_SetMaterialQuality},
{"Renderer_SetDrawShadows", Renderer_SetDrawShadows},
{"Renderer_SetShadowMapSize", Renderer_SetShadowMapSize},
{"Renderer_SetShadowQuality", Renderer_SetShadowQuality},
{"Renderer_SetShadowSoftness", Renderer_SetShadowSoftness},
{"Renderer_SetVSMShadowParameters", Renderer_SetVSMShadowParameters},
{"Renderer_SetVSMMultiSample", Renderer_SetVSMMultiSample},
{"Renderer_SetReuseShadowMaps", Renderer_SetReuseShadowMaps},
{"Renderer_SetMaxShadowMaps", Renderer_SetMaxShadowMaps},
{"Renderer_SetDynamicInstancing", Renderer_SetDynamicInstancing},
{"Renderer_SetNumExtraInstancingBufferElements", Renderer_SetNumExtraInstancingBufferElements},
{"Renderer_SetMinInstances", Renderer_SetMinInstances},
{"Renderer_SetMaxSortedInstances", Renderer_SetMaxSortedInstances},
{"Renderer_SetMaxOccluderTriangles", Renderer_SetMaxOccluderTriangles},
{"Renderer_SetOcclusionBufferSize", Renderer_SetOcclusionBufferSize},
{"Renderer_SetOccluderSizeThreshold", Renderer_SetOccluderSizeThreshold},
{"Renderer_SetThreadedOcclusion", Renderer_SetThreadedOcclusion},
{"Renderer_SetMobileShadowBiasMul", Renderer_SetMobileShadowBiasMul},
{"Renderer_SetMobileShadowBiasAdd", Renderer_SetMobileShadowBiasAdd},
{"Renderer_SetMobileNormalOffsetMul", Renderer_SetMobileNormalOffsetMul},
{"Renderer_ReloadShaders", Renderer_ReloadShaders},
{"Renderer_ApplyShadowMapFilter", Renderer_ApplyShadowMapFilter},
{"Renderer_GetNumViewports", Renderer_GetNumViewports},
{"Renderer_GetViewport", Renderer_GetViewport},
{"Renderer_GetViewportForScene", Renderer_GetViewportForScene},
{"Renderer_GetDefaultRenderPath", Renderer_GetDefaultRenderPath},
{"Renderer_GetDefaultTechnique", Renderer_GetDefaultTechnique},
{"Renderer_GetHDRRendering", Renderer_GetHDRRendering},
{"Renderer_GetSpecularLighting", Renderer_GetSpecularLighting},
{"Renderer_GetDrawShadows", Renderer_GetDrawShadows},
{"Renderer_GetTextureAnisotropy", Renderer_GetTextureAnisotropy},
{"Renderer_GetTextureFilterMode", Renderer_GetTextureFilterMode},
{"Renderer_GetTextureQuality", Renderer_GetTextureQuality},
{"Renderer_GetMaterialQuality", Renderer_GetMaterialQuality},
{"Renderer_GetShadowMapSize", Renderer_GetShadowMapSize},
{"Renderer_GetShadowQuality", Renderer_GetShadowQuality},
{"Renderer_GetShadowSoftness", Renderer_GetShadowSoftness},
{"Renderer_GetVSMShadowParameters", Renderer_GetVSMShadowParameters},
{"Renderer_GetVSMMultiSample", Renderer_GetVSMMultiSample},
{"Renderer_GetReuseShadowMaps", Renderer_GetReuseShadowMaps},
{"Renderer_GetMaxShadowMaps", Renderer_GetMaxShadowMaps},
{"Renderer_GetDynamicInstancing", Renderer_GetDynamicInstancing},
{"Renderer_GetNumExtraInstancingBufferElements", Renderer_GetNumExtraInstancingBufferElements},
{"Renderer_GetMinInstances", Renderer_GetMinInstances},
{"Renderer_GetMaxSortedInstances", Renderer_GetMaxSortedInstances},
{"Renderer_GetMaxOccluderTriangles", Renderer_GetMaxOccluderTriangles},
{"Renderer_GetOcclusionBufferSize", Renderer_GetOcclusionBufferSize},
{"Renderer_GetOccluderSizeThreshold", Renderer_GetOccluderSizeThreshold},
{"Renderer_GetThreadedOcclusion", Renderer_GetThreadedOcclusion},
{"Renderer_GetMobileShadowBiasMul", Renderer_GetMobileShadowBiasMul},
{"Renderer_GetMobileShadowBiasAdd", Renderer_GetMobileShadowBiasAdd},
{"Renderer_GetMobileNormalOffsetMul", Renderer_GetMobileNormalOffsetMul},
{"Renderer_GetNumViews", Renderer_GetNumViews},
{"Renderer_GetNumPrimitives", Renderer_GetNumPrimitives},
{"Renderer_GetNumBatches", Renderer_GetNumBatches},
{"Renderer_GetNumGeometries", Renderer_GetNumGeometries},
{"Renderer_GetNumLights", Renderer_GetNumLights},
{"Renderer_GetNumShadowMaps", Renderer_GetNumShadowMaps},
{"Renderer_GetNumOccluders", Renderer_GetNumOccluders},
{"Renderer_GetDefaultZone", Renderer_GetDefaultZone},
{"Renderer_GetDefaultMaterial", Renderer_GetDefaultMaterial},
{"Renderer_GetDefaultLightRamp", Renderer_GetDefaultLightRamp},
{"Renderer_GetDefaultLightSpot", Renderer_GetDefaultLightSpot},
{"Renderer_GetFaceSelectCubeMap", Renderer_GetFaceSelectCubeMap},
{"Renderer_GetIndirectionCubeMap", Renderer_GetIndirectionCubeMap},
{"Renderer_GetInstancingBuffer", Renderer_GetInstancingBuffer},
{"Renderer_Update", Renderer_Update},
{"Renderer_Render", Renderer_Render},
{"Renderer_DrawDebugGeometry", Renderer_DrawDebugGeometry},
{"Renderer_QueueRenderSurface", Renderer_QueueRenderSurface},
{"Renderer_QueueViewport", Renderer_QueueViewport},
{"Renderer_GetLightGeometry", Renderer_GetLightGeometry},
{"Renderer_GetQuadGeometry", Renderer_GetQuadGeometry},
{"Renderer_GetShadowMap", Renderer_GetShadowMap},
{"Renderer_GetScreenBuffer", Renderer_GetScreenBuffer},
{"Renderer_GetDepthStencil", Renderer_GetDepthStencil},
{"Renderer_GetOcclusionBuffer", Renderer_GetOcclusionBuffer},
{"Renderer_GetShadowCamera", Renderer_GetShadowCamera},
{"Renderer_StorePreparedView", Renderer_StorePreparedView},
{"Renderer_GetPreparedView", Renderer_GetPreparedView},
{"Renderer_SetCullMode", Renderer_SetCullMode},
{"Renderer_ResizeInstancingBuffer", Renderer_ResizeInstancingBuffer},
{"Renderer_OptimizeLightByScissor", Renderer_OptimizeLightByScissor},
{"Renderer_OptimizeLightByStencil", Renderer_OptimizeLightByStencil},
{"Renderer_GetActualView", Renderer_GetActualView},
{"View_GetType", View_GetType},
{"View_GetTypeName", View_GetTypeName},
{"View_GetTypeStatic", View_GetTypeStatic},
{"View_GetTypeNameStatic", View_GetTypeNameStatic},
{"View_View", View_View},
{"View_Define", View_Define},
{"View_Render", View_Render},
{"View_GetGraphics", View_GetGraphics},
{"View_GetRenderer", View_GetRenderer},
{"View_GetScene", View_GetScene},
{"View_GetOctree", View_GetOctree},
{"View_GetCamera", View_GetCamera},
{"View_GetCullCamera", View_GetCullCamera},
{"View_GetRenderTarget", View_GetRenderTarget},
{"View_GetDrawDebug", View_GetDrawDebug},
{"View_GetViewRect", View_GetViewRect},
{"View_GetViewSize", View_GetViewSize},
{"View_GetOcclusionBuffer", View_GetOcclusionBuffer},
{"View_GetNumActiveOccluders", View_GetNumActiveOccluders},
{"View_GetSourceView", View_GetSourceView},
{"View_SetGlobalShaderParameters", View_SetGlobalShaderParameters},
{"View_SetCameraShaderParameters", View_SetCameraShaderParameters},
{"View_SetCommandShaderParameters", View_SetCommandShaderParameters},
{"View_SetGBufferShaderParameters", View_SetGBufferShaderParameters},
{"View_DrawFullscreenQuad", View_DrawFullscreenQuad},
{"View_FindNamedTexture", View_FindNamedTexture},
{"View_SetClearColor", View_SetClearColor},
{"SmoothedTransform_GetType", SmoothedTransform_GetType},
{"SmoothedTransform_GetTypeName", SmoothedTransform_GetTypeName},
{"SmoothedTransform_GetTypeStatic", SmoothedTransform_GetTypeStatic},
{"SmoothedTransform_GetTypeNameStatic", SmoothedTransform_GetTypeNameStatic},
{"SmoothedTransform_SmoothedTransform", SmoothedTransform_SmoothedTransform},
{"SmoothedTransform_RegisterObject", SmoothedTransform_RegisterObject},
{"SmoothedTransform_Update", SmoothedTransform_Update},
{"SmoothedTransform_SetTargetPosition", SmoothedTransform_SetTargetPosition},
{"SmoothedTransform_SetTargetRotation", SmoothedTransform_SetTargetRotation},
{"SmoothedTransform_SetTargetWorldPosition", SmoothedTransform_SetTargetWorldPosition},
{"SmoothedTransform_SetTargetWorldRotation", SmoothedTransform_SetTargetWorldRotation},
{"SmoothedTransform_GetTargetPosition", SmoothedTransform_GetTargetPosition},
{"SmoothedTransform_GetTargetRotation", SmoothedTransform_GetTargetRotation},
{"SmoothedTransform_GetTargetWorldPosition", SmoothedTransform_GetTargetWorldPosition},
{"SmoothedTransform_GetTargetWorldRotation", SmoothedTransform_GetTargetWorldRotation},
{"SmoothedTransform_IsInProgress", SmoothedTransform_IsInProgress},
{"ObjectAnimation_GetType", ObjectAnimation_GetType},
{"ObjectAnimation_GetTypeName", ObjectAnimation_GetTypeName},
{"ObjectAnimation_GetTypeStatic", ObjectAnimation_GetTypeStatic},
{"ObjectAnimation_GetTypeNameStatic", ObjectAnimation_GetTypeNameStatic},
{"ObjectAnimation_ObjectAnimation", ObjectAnimation_ObjectAnimation},
{"ObjectAnimation_RegisterObject", ObjectAnimation_RegisterObject},
{"ObjectAnimation_BeginLoad_File", ObjectAnimation_BeginLoad_File},
{"ObjectAnimation_BeginLoad_MemoryBuffer", ObjectAnimation_BeginLoad_MemoryBuffer},
{"ObjectAnimation_Save_File", ObjectAnimation_Save_File},
{"ObjectAnimation_Save_MemoryBuffer", ObjectAnimation_Save_MemoryBuffer},
{"ObjectAnimation_LoadXML", ObjectAnimation_LoadXML},
{"ObjectAnimation_SaveXML", ObjectAnimation_SaveXML},
{"ObjectAnimation_AddAttributeAnimation", ObjectAnimation_AddAttributeAnimation},
{"ObjectAnimation_RemoveAttributeAnimation", ObjectAnimation_RemoveAttributeAnimation},
{"ObjectAnimation_RemoveAttributeAnimation0", ObjectAnimation_RemoveAttributeAnimation0},
{"ObjectAnimation_GetAttributeAnimation", ObjectAnimation_GetAttributeAnimation},
{"ObjectAnimation_GetAttributeAnimationWrapMode", ObjectAnimation_GetAttributeAnimationWrapMode},
{"ObjectAnimation_GetAttributeAnimationSpeed", ObjectAnimation_GetAttributeAnimationSpeed},
{"ObjectAnimation_GetAttributeAnimationInfo", ObjectAnimation_GetAttributeAnimationInfo},
{"ObjectFactory_CreateObject", ObjectFactory_CreateObject},
{"ObjectFactory_GetContext", ObjectFactory_GetContext},
{"ObjectFactory_GetTypeInfo", ObjectFactory_GetTypeInfo},
{"ObjectFactory_GetType", ObjectFactory_GetType},
{"ObjectFactory_GetTypeName", ObjectFactory_GetTypeName},
{"OcclusionBuffer_GetType", OcclusionBuffer_GetType},
{"OcclusionBuffer_GetTypeName", OcclusionBuffer_GetTypeName},
{"OcclusionBuffer_GetTypeStatic", OcclusionBuffer_GetTypeStatic},
{"OcclusionBuffer_GetTypeNameStatic", OcclusionBuffer_GetTypeNameStatic},
{"OcclusionBuffer_OcclusionBuffer", OcclusionBuffer_OcclusionBuffer},
{"OcclusionBuffer_SetSize", OcclusionBuffer_SetSize},
{"OcclusionBuffer_SetView", OcclusionBuffer_SetView},
{"OcclusionBuffer_SetMaxTriangles", OcclusionBuffer_SetMaxTriangles},
{"OcclusionBuffer_SetCullMode", OcclusionBuffer_SetCullMode},
{"OcclusionBuffer_Reset", OcclusionBuffer_Reset},
{"OcclusionBuffer_Clear", OcclusionBuffer_Clear},
{"OcclusionBuffer_AddTriangles", OcclusionBuffer_AddTriangles},
{"OcclusionBuffer_AddTriangles0", OcclusionBuffer_AddTriangles0},
{"OcclusionBuffer_DrawTriangles", OcclusionBuffer_DrawTriangles},
{"OcclusionBuffer_BuildDepthHierarchy", OcclusionBuffer_BuildDepthHierarchy},
{"OcclusionBuffer_ResetUseTimer", OcclusionBuffer_ResetUseTimer},
{"OcclusionBuffer_GetBuffer", OcclusionBuffer_GetBuffer},
{"OcclusionBuffer_GetView", OcclusionBuffer_GetView},
{"OcclusionBuffer_GetProjection", OcclusionBuffer_GetProjection},
{"OcclusionBuffer_GetWidth", OcclusionBuffer_GetWidth},
{"OcclusionBuffer_GetHeight", OcclusionBuffer_GetHeight},
{"OcclusionBuffer_GetNumTriangles", OcclusionBuffer_GetNumTriangles},
{"OcclusionBuffer_GetMaxTriangles", OcclusionBuffer_GetMaxTriangles},
{"OcclusionBuffer_GetCullMode", OcclusionBuffer_GetCullMode},
{"OcclusionBuffer_IsThreaded", OcclusionBuffer_IsThreaded},
{"OcclusionBuffer_IsVisible", OcclusionBuffer_IsVisible},
{"OcclusionBuffer_GetUseTimer", OcclusionBuffer_GetUseTimer},
{"ParticleEffect_GetType", ParticleEffect_GetType},
{"ParticleEffect_GetTypeName", ParticleEffect_GetTypeName},
{"ParticleEffect_GetTypeStatic", ParticleEffect_GetTypeStatic},
{"ParticleEffect_GetTypeNameStatic", ParticleEffect_GetTypeNameStatic},
{"ParticleEffect_ParticleEffect", ParticleEffect_ParticleEffect},
{"ParticleEffect_RegisterObject", ParticleEffect_RegisterObject},
{"ParticleEffect_BeginLoad_File", ParticleEffect_BeginLoad_File},
{"ParticleEffect_BeginLoad_MemoryBuffer", ParticleEffect_BeginLoad_MemoryBuffer},
{"ParticleEffect_EndLoad", ParticleEffect_EndLoad},
{"ParticleEffect_Save_File", ParticleEffect_Save_File},
{"ParticleEffect_Save_MemoryBuffer", ParticleEffect_Save_MemoryBuffer},
{"ParticleEffect_Save0", ParticleEffect_Save0},
{"ParticleEffect_Load", ParticleEffect_Load},
{"ParticleEffect_SetMaterial", ParticleEffect_SetMaterial},
{"ParticleEffect_SetNumParticles", ParticleEffect_SetNumParticles},
{"ParticleEffect_SetUpdateInvisible", ParticleEffect_SetUpdateInvisible},
{"ParticleEffect_SetRelative", ParticleEffect_SetRelative},
{"ParticleEffect_SetScaled", ParticleEffect_SetScaled},
{"ParticleEffect_SetSorted", ParticleEffect_SetSorted},
{"ParticleEffect_SetFixedScreenSize", ParticleEffect_SetFixedScreenSize},
{"ParticleEffect_SetAnimationLodBias", ParticleEffect_SetAnimationLodBias},
{"ParticleEffect_SetEmitterType", ParticleEffect_SetEmitterType},
{"ParticleEffect_SetEmitterSize", ParticleEffect_SetEmitterSize},
{"ParticleEffect_SetMinDirection", ParticleEffect_SetMinDirection},
{"ParticleEffect_SetMaxDirection", ParticleEffect_SetMaxDirection},
{"ParticleEffect_SetConstantForce", ParticleEffect_SetConstantForce},
{"ParticleEffect_SetDampingForce", ParticleEffect_SetDampingForce},
{"ParticleEffect_SetActiveTime", ParticleEffect_SetActiveTime},
{"ParticleEffect_SetInactiveTime", ParticleEffect_SetInactiveTime},
{"ParticleEffect_SetMinEmissionRate", ParticleEffect_SetMinEmissionRate},
{"ParticleEffect_SetMaxEmissionRate", ParticleEffect_SetMaxEmissionRate},
{"ParticleEffect_SetMinParticleSize", ParticleEffect_SetMinParticleSize},
{"ParticleEffect_SetMaxParticleSize", ParticleEffect_SetMaxParticleSize},
{"ParticleEffect_SetMinTimeToLive", ParticleEffect_SetMinTimeToLive},
{"ParticleEffect_SetMaxTimeToLive", ParticleEffect_SetMaxTimeToLive},
{"ParticleEffect_SetMinVelocity", ParticleEffect_SetMinVelocity},
{"ParticleEffect_SetMaxVelocity", ParticleEffect_SetMaxVelocity},
{"ParticleEffect_SetMinRotation", ParticleEffect_SetMinRotation},
{"ParticleEffect_SetMaxRotation", ParticleEffect_SetMaxRotation},
{"ParticleEffect_SetMinRotationSpeed", ParticleEffect_SetMinRotationSpeed},
{"ParticleEffect_SetMaxRotationSpeed", ParticleEffect_SetMaxRotationSpeed},
{"ParticleEffect_SetSizeAdd", ParticleEffect_SetSizeAdd},
{"ParticleEffect_SetSizeMul", ParticleEffect_SetSizeMul},
{"ParticleEffect_SetFaceCameraMode", ParticleEffect_SetFaceCameraMode},
{"ParticleEffect_AddColorTime", ParticleEffect_AddColorTime},
{"ParticleEffect_RemoveColorFrame", ParticleEffect_RemoveColorFrame},
{"ParticleEffect_SetColorFrame", ParticleEffect_SetColorFrame},
{"ParticleEffect_SetNumColorFrames", ParticleEffect_SetNumColorFrames},
{"ParticleEffect_SortColorFrames", ParticleEffect_SortColorFrames},
{"ParticleEffect_RemoveTextureFrame", ParticleEffect_RemoveTextureFrame},
{"ParticleEffect_SetTextureFrame", ParticleEffect_SetTextureFrame},
{"ParticleEffect_SetNumTextureFrames", ParticleEffect_SetNumTextureFrames},
{"ParticleEffect_SortTextureFrames", ParticleEffect_SortTextureFrames},
{"ParticleEffect_Clone", ParticleEffect_Clone},
{"ParticleEffect_GetMaterial", ParticleEffect_GetMaterial},
{"ParticleEffect_GetNumParticles", ParticleEffect_GetNumParticles},
{"ParticleEffect_GetUpdateInvisible", ParticleEffect_GetUpdateInvisible},
{"ParticleEffect_IsRelative", ParticleEffect_IsRelative},
{"ParticleEffect_IsScaled", ParticleEffect_IsScaled},
{"ParticleEffect_IsSorted", ParticleEffect_IsSorted},
{"ParticleEffect_IsFixedScreenSize", ParticleEffect_IsFixedScreenSize},
{"ParticleEffect_GetAnimationLodBias", ParticleEffect_GetAnimationLodBias},
{"ParticleEffect_GetEmitterType", ParticleEffect_GetEmitterType},
{"ParticleEffect_GetEmitterSize", ParticleEffect_GetEmitterSize},
{"ParticleEffect_GetMinDirection", ParticleEffect_GetMinDirection},
{"ParticleEffect_GetMaxDirection", ParticleEffect_GetMaxDirection},
{"ParticleEffect_GetConstantForce", ParticleEffect_GetConstantForce},
{"ParticleEffect_GetDampingForce", ParticleEffect_GetDampingForce},
{"ParticleEffect_GetActiveTime", ParticleEffect_GetActiveTime},
{"ParticleEffect_GetInactiveTime", ParticleEffect_GetInactiveTime},
{"ParticleEffect_GetMinEmissionRate", ParticleEffect_GetMinEmissionRate},
{"ParticleEffect_GetMaxEmissionRate", ParticleEffect_GetMaxEmissionRate},
{"ParticleEffect_GetMinParticleSize", ParticleEffect_GetMinParticleSize},
{"ParticleEffect_GetMaxParticleSize", ParticleEffect_GetMaxParticleSize},
{"ParticleEffect_GetMinTimeToLive", ParticleEffect_GetMinTimeToLive},
{"ParticleEffect_GetMaxTimeToLive", ParticleEffect_GetMaxTimeToLive},
{"ParticleEffect_GetMinVelocity", ParticleEffect_GetMinVelocity},
{"ParticleEffect_GetMaxVelocity", ParticleEffect_GetMaxVelocity},
{"ParticleEffect_GetMinRotation", ParticleEffect_GetMinRotation},
{"ParticleEffect_GetMaxRotation", ParticleEffect_GetMaxRotation},
{"ParticleEffect_GetMinRotationSpeed", ParticleEffect_GetMinRotationSpeed},
{"ParticleEffect_GetMaxRotationSpeed", ParticleEffect_GetMaxRotationSpeed},
{"ParticleEffect_GetSizeAdd", ParticleEffect_GetSizeAdd},
{"ParticleEffect_GetSizeMul", ParticleEffect_GetSizeMul},
{"ParticleEffect_GetNumColorFrames", ParticleEffect_GetNumColorFrames},
{"ParticleEffect_GetColorFrame", ParticleEffect_GetColorFrame},
{"ParticleEffect_GetNumTextureFrames", ParticleEffect_GetNumTextureFrames},
{"ParticleEffect_GetTextureFrame", ParticleEffect_GetTextureFrame},
{"ParticleEffect_GetFaceCameraMode", ParticleEffect_GetFaceCameraMode},
{"ParticleEffect_GetRandomDirection", ParticleEffect_GetRandomDirection},
{"ParticleEffect_GetRandomSize", ParticleEffect_GetRandomSize},
{"ParticleEffect_GetRandomVelocity", ParticleEffect_GetRandomVelocity},
{"ParticleEffect_GetRandomTimeToLive", ParticleEffect_GetRandomTimeToLive},
{"ParticleEffect_GetRandomRotationSpeed", ParticleEffect_GetRandomRotationSpeed},
{"ParticleEffect_GetRandomRotation", ParticleEffect_GetRandomRotation},
{"ParticleEmitter_GetType", ParticleEmitter_GetType},
{"ParticleEmitter_GetTypeName", ParticleEmitter_GetTypeName},
{"ParticleEmitter_GetTypeStatic", ParticleEmitter_GetTypeStatic},
{"ParticleEmitter_GetTypeNameStatic", ParticleEmitter_GetTypeNameStatic},
{"ParticleEmitter_ParticleEmitter", ParticleEmitter_ParticleEmitter},
{"ParticleEmitter_RegisterObject", ParticleEmitter_RegisterObject},
{"ParticleEmitter_OnSetEnabled", ParticleEmitter_OnSetEnabled},
{"ParticleEmitter_SetEffect", ParticleEmitter_SetEffect},
{"ParticleEmitter_SetNumParticles", ParticleEmitter_SetNumParticles},
{"ParticleEmitter_SetEmitting", ParticleEmitter_SetEmitting},
{"ParticleEmitter_SetSerializeParticles", ParticleEmitter_SetSerializeParticles},
{"ParticleEmitter_SetAutoRemoveMode", ParticleEmitter_SetAutoRemoveMode},
{"ParticleEmitter_ResetEmissionTimer", ParticleEmitter_ResetEmissionTimer},
{"ParticleEmitter_RemoveAllParticles", ParticleEmitter_RemoveAllParticles},
{"ParticleEmitter_Reset", ParticleEmitter_Reset},
{"ParticleEmitter_ApplyEffect", ParticleEmitter_ApplyEffect},
{"ParticleEmitter_GetEffect", ParticleEmitter_GetEffect},
{"ParticleEmitter_GetNumParticles", ParticleEmitter_GetNumParticles},
{"ParticleEmitter_IsEmitting", ParticleEmitter_IsEmitting},
{"ParticleEmitter_GetSerializeParticles", ParticleEmitter_GetSerializeParticles},
{"ParticleEmitter_GetAutoRemoveMode", ParticleEmitter_GetAutoRemoveMode},
{"ParticleEmitter_GetEffectAttr", ParticleEmitter_GetEffectAttr},
{"Pass_Pass", Pass_Pass},
{"Pass_SetBlendMode", Pass_SetBlendMode},
{"Pass_SetCullMode", Pass_SetCullMode},
{"Pass_SetDepthTestMode", Pass_SetDepthTestMode},
{"Pass_SetLightingMode", Pass_SetLightingMode},
{"Pass_SetDepthWrite", Pass_SetDepthWrite},
{"Pass_SetAlphaToCoverage", Pass_SetAlphaToCoverage},
{"Pass_SetIsDesktop", Pass_SetIsDesktop},
{"Pass_SetVertexShader", Pass_SetVertexShader},
{"Pass_SetPixelShader", Pass_SetPixelShader},
{"Pass_SetVertexShaderDefines", Pass_SetVertexShaderDefines},
{"Pass_SetPixelShaderDefines", Pass_SetPixelShaderDefines},
{"Pass_SetVertexShaderDefineExcludes", Pass_SetVertexShaderDefineExcludes},
{"Pass_SetPixelShaderDefineExcludes", Pass_SetPixelShaderDefineExcludes},
{"Pass_ReleaseShaders", Pass_ReleaseShaders},
{"Pass_MarkShadersLoaded", Pass_MarkShadersLoaded},
{"Pass_GetName", Pass_GetName},
{"Pass_GetIndex", Pass_GetIndex},
{"Pass_GetBlendMode", Pass_GetBlendMode},
{"Pass_GetCullMode", Pass_GetCullMode},
{"Pass_GetDepthTestMode", Pass_GetDepthTestMode},
{"Pass_GetLightingMode", Pass_GetLightingMode},
{"Pass_GetShadersLoadedFrameNumber", Pass_GetShadersLoadedFrameNumber},
{"Pass_GetDepthWrite", Pass_GetDepthWrite},
{"Pass_GetAlphaToCoverage", Pass_GetAlphaToCoverage},
{"Pass_IsDesktop", Pass_IsDesktop},
{"Pass_GetVertexShader", Pass_GetVertexShader},
{"Pass_GetPixelShader", Pass_GetPixelShader},
{"Pass_GetVertexShaderDefines", Pass_GetVertexShaderDefines},
{"Pass_GetPixelShaderDefines", Pass_GetPixelShaderDefines},
{"Pass_GetVertexShaderDefineExcludes", Pass_GetVertexShaderDefineExcludes},
{"Pass_GetPixelShaderDefineExcludes", Pass_GetPixelShaderDefineExcludes},
{"Pass_GetEffectiveVertexShaderDefines", Pass_GetEffectiveVertexShaderDefines},
{"Pass_GetEffectivePixelShaderDefines", Pass_GetEffectivePixelShaderDefines},
{"Plugin_GetType", Plugin_GetType},
{"Plugin_GetTypeName", Plugin_GetTypeName},
{"Plugin_GetTypeStatic", Plugin_GetTypeStatic},
{"Plugin_GetTypeNameStatic", Plugin_GetTypeNameStatic},
{"Plugin_Plugin", Plugin_Plugin},
{"Plugin_LoadAndroidPlugin", Plugin_LoadAndroidPlugin},
{"Plugin_sendEvent", Plugin_sendEvent},
{"Plugin_OnPluginEvent", Plugin_OnPluginEvent},
{"RenderSurface_RenderSurface", RenderSurface_RenderSurface},
{"RenderSurface_SetNumViewports", RenderSurface_SetNumViewports},
{"RenderSurface_SetViewport", RenderSurface_SetViewport},
{"RenderSurface_SetUpdateMode", RenderSurface_SetUpdateMode},
{"RenderSurface_SetLinkedRenderTarget", RenderSurface_SetLinkedRenderTarget},
{"RenderSurface_SetLinkedDepthStencil", RenderSurface_SetLinkedDepthStencil},
{"RenderSurface_QueueUpdate", RenderSurface_QueueUpdate},
{"RenderSurface_Release", RenderSurface_Release},
{"RenderSurface_CreateRenderBuffer", RenderSurface_CreateRenderBuffer},
{"RenderSurface_GetWidth", RenderSurface_GetWidth},
{"RenderSurface_GetHeight", RenderSurface_GetHeight},
{"RenderSurface_GetUsage", RenderSurface_GetUsage},
{"RenderSurface_GetMultiSample", RenderSurface_GetMultiSample},
{"RenderSurface_GetAutoResolve", RenderSurface_GetAutoResolve},
{"RenderSurface_GetNumViewports", RenderSurface_GetNumViewports},
{"RenderSurface_GetViewport", RenderSurface_GetViewport},
{"RenderSurface_GetUpdateMode", RenderSurface_GetUpdateMode},
{"RenderSurface_GetLinkedRenderTarget", RenderSurface_GetLinkedRenderTarget},
{"RenderSurface_GetLinkedDepthStencil", RenderSurface_GetLinkedDepthStencil},
{"RenderSurface_IsUpdateQueued", RenderSurface_IsUpdateQueued},
{"RenderSurface_ResetUpdateQueued", RenderSurface_ResetUpdateQueued},
{"RenderSurface_GetParentTexture", RenderSurface_GetParentTexture},
{"RenderSurface_GetSurface", RenderSurface_GetSurface},
{"RenderSurface_GetRenderTargetView", RenderSurface_GetRenderTargetView},
{"RenderSurface_GetReadOnlyView", RenderSurface_GetReadOnlyView},
{"RenderSurface_GetTarget", RenderSurface_GetTarget},
{"RenderSurface_GetRenderBuffer", RenderSurface_GetRenderBuffer},
{"RenderSurface_IsResolveDirty", RenderSurface_IsResolveDirty},
{"RenderSurface_SetResolveDirty", RenderSurface_SetResolveDirty},
{"ResourceWithMetadata_GetType", ResourceWithMetadata_GetType},
{"ResourceWithMetadata_GetTypeName", ResourceWithMetadata_GetTypeName},
{"ResourceWithMetadata_GetTypeStatic", ResourceWithMetadata_GetTypeStatic},
{"ResourceWithMetadata_GetTypeNameStatic", ResourceWithMetadata_GetTypeNameStatic},
{"ResourceWithMetadata_ResourceWithMetadata", ResourceWithMetadata_ResourceWithMetadata},
{"ResourceWithMetadata_AddMetadata_0", ResourceWithMetadata_AddMetadata_0},
{"ResourceWithMetadata_AddMetadata_1", ResourceWithMetadata_AddMetadata_1},
{"ResourceWithMetadata_AddMetadata_2", ResourceWithMetadata_AddMetadata_2},
{"ResourceWithMetadata_AddMetadata_3", ResourceWithMetadata_AddMetadata_3},
{"ResourceWithMetadata_AddMetadata_4", ResourceWithMetadata_AddMetadata_4},
{"ResourceWithMetadata_AddMetadata_5", ResourceWithMetadata_AddMetadata_5},
{"ResourceWithMetadata_AddMetadata_6", ResourceWithMetadata_AddMetadata_6},
{"ResourceWithMetadata_AddMetadata_7", ResourceWithMetadata_AddMetadata_7},
{"ResourceWithMetadata_AddMetadata_8", ResourceWithMetadata_AddMetadata_8},
{"ResourceWithMetadata_AddMetadata_9", ResourceWithMetadata_AddMetadata_9},
{"ResourceWithMetadata_AddMetadata_10", ResourceWithMetadata_AddMetadata_10},
{"ResourceWithMetadata_AddMetadata_11", ResourceWithMetadata_AddMetadata_11},
{"ResourceWithMetadata_AddMetadata_12", ResourceWithMetadata_AddMetadata_12},
{"ResourceWithMetadata_AddMetadata_13", ResourceWithMetadata_AddMetadata_13},
{"ResourceWithMetadata_AddMetadata_14", ResourceWithMetadata_AddMetadata_14},
{"ResourceWithMetadata_RemoveMetadata", ResourceWithMetadata_RemoveMetadata},
{"ResourceWithMetadata_RemoveAllMetadata", ResourceWithMetadata_RemoveAllMetadata},
{"ResourceWithMetadata_HasMetadata", ResourceWithMetadata_HasMetadata},
{"RibbonTrail_GetType", RibbonTrail_GetType},
{"RibbonTrail_GetTypeName", RibbonTrail_GetTypeName},
{"RibbonTrail_GetTypeStatic", RibbonTrail_GetTypeStatic},
{"RibbonTrail_GetTypeNameStatic", RibbonTrail_GetTypeNameStatic},
{"RibbonTrail_RibbonTrail", RibbonTrail_RibbonTrail},
{"RibbonTrail_RegisterObject", RibbonTrail_RegisterObject},
{"RibbonTrail_OnSetEnabled", RibbonTrail_OnSetEnabled},
{"RibbonTrail_GetUpdateGeometryType", RibbonTrail_GetUpdateGeometryType},
{"RibbonTrail_SetMaterial", RibbonTrail_SetMaterial},
{"RibbonTrail_SetVertexDistance", RibbonTrail_SetVertexDistance},
{"RibbonTrail_SetWidth", RibbonTrail_SetWidth},
{"RibbonTrail_SetStartColor", RibbonTrail_SetStartColor},
{"RibbonTrail_SetEndColor", RibbonTrail_SetEndColor},
{"RibbonTrail_SetStartScale", RibbonTrail_SetStartScale},
{"RibbonTrail_SetEndScale", RibbonTrail_SetEndScale},
{"RibbonTrail_SetTrailType", RibbonTrail_SetTrailType},
{"RibbonTrail_SetBaseVelocity", RibbonTrail_SetBaseVelocity},
{"RibbonTrail_SetSorted", RibbonTrail_SetSorted},
{"RibbonTrail_SetLifetime", RibbonTrail_SetLifetime},
{"RibbonTrail_SetEmitting", RibbonTrail_SetEmitting},
{"RibbonTrail_SetUpdateInvisible", RibbonTrail_SetUpdateInvisible},
{"RibbonTrail_SetTailColumn", RibbonTrail_SetTailColumn},
{"RibbonTrail_SetAnimationLodBias", RibbonTrail_SetAnimationLodBias},
{"RibbonTrail_Commit", RibbonTrail_Commit},
{"RibbonTrail_GetMaterial", RibbonTrail_GetMaterial},
{"RibbonTrail_GetMaterialAttr", RibbonTrail_GetMaterialAttr},
{"RibbonTrail_GetVertexDistance", RibbonTrail_GetVertexDistance},
{"RibbonTrail_GetWidth", RibbonTrail_GetWidth},
{"RibbonTrail_GetStartColor", RibbonTrail_GetStartColor},
{"RibbonTrail_GetEndColor", RibbonTrail_GetEndColor},
{"RibbonTrail_GetStartScale", RibbonTrail_GetStartScale},
{"RibbonTrail_GetEndScale", RibbonTrail_GetEndScale},
{"RibbonTrail_IsSorted", RibbonTrail_IsSorted},
{"RibbonTrail_GetLifetime", RibbonTrail_GetLifetime},
{"RibbonTrail_GetAnimationLodBias", RibbonTrail_GetAnimationLodBias},
{"RibbonTrail_GetTrailType", RibbonTrail_GetTrailType},
{"RibbonTrail_GetBaseVelocity", RibbonTrail_GetBaseVelocity},
{"RibbonTrail_GetTailColumn", RibbonTrail_GetTailColumn},
{"RibbonTrail_IsEmitting", RibbonTrail_IsEmitting},
{"RibbonTrail_GetUpdateInvisible", RibbonTrail_GetUpdateInvisible},
{"SceneResolver_SceneResolver", SceneResolver_SceneResolver},
{"SceneResolver_Reset", SceneResolver_Reset},
{"SceneResolver_AddNode", SceneResolver_AddNode},
{"SceneResolver_AddComponent", SceneResolver_AddComponent},
{"SceneResolver_Resolve", SceneResolver_Resolve},
{"Shader_GetType", Shader_GetType},
{"Shader_GetTypeName", Shader_GetTypeName},
{"Shader_GetTypeStatic", Shader_GetTypeStatic},
{"Shader_GetTypeNameStatic", Shader_GetTypeNameStatic},
{"Shader_Shader", Shader_Shader},
{"Shader_RegisterObject", Shader_RegisterObject},
{"Shader_BeginLoad_File", Shader_BeginLoad_File},
{"Shader_BeginLoad_MemoryBuffer", Shader_BeginLoad_MemoryBuffer},
{"Shader_EndLoad", Shader_EndLoad},
{"Shader_GetVariation", Shader_GetVariation},
{"Shader_GetSourceCode", Shader_GetSourceCode},
{"Shader_GetTimeStamp", Shader_GetTimeStamp},
{"ShaderParameterAnimationInfo_ShaderParameterAnimationInfo", ShaderParameterAnimationInfo_ShaderParameterAnimationInfo},
{"ShaderParameterAnimationInfo_GetName", ShaderParameterAnimationInfo_GetName},
{"ShaderPrecache_GetType", ShaderPrecache_GetType},
{"ShaderPrecache_GetTypeName", ShaderPrecache_GetTypeName},
{"ShaderPrecache_GetTypeStatic", ShaderPrecache_GetTypeStatic},
{"ShaderPrecache_GetTypeNameStatic", ShaderPrecache_GetTypeNameStatic},
{"ShaderPrecache_ShaderPrecache", ShaderPrecache_ShaderPrecache},
{"ShaderPrecache_StoreShaders", ShaderPrecache_StoreShaders},
{"ShaderPrecache_LoadShaders_File", ShaderPrecache_LoadShaders_File},
{"ShaderPrecache_LoadShaders_MemoryBuffer", ShaderPrecache_LoadShaders_MemoryBuffer},
{"ShaderProgram_CastToGPUObject", ShaderProgram_CastToGPUObject},
{"ShaderProgram_ShaderProgram", ShaderProgram_ShaderProgram},
{"ShaderVariation_CastToGPUObject", ShaderVariation_CastToGPUObject},
{"ShaderVariation_ShaderVariation", ShaderVariation_ShaderVariation},
{"ShaderVariation_Release", ShaderVariation_Release},
{"ShaderVariation_Create", ShaderVariation_Create},
{"ShaderVariation_SetName", ShaderVariation_SetName},
{"ShaderVariation_SetDefines", ShaderVariation_SetDefines},
{"ShaderVariation_GetOwner", ShaderVariation_GetOwner},
{"ShaderVariation_GetShaderType", ShaderVariation_GetShaderType},
{"ShaderVariation_GetName", ShaderVariation_GetName},
{"ShaderVariation_GetFullName", ShaderVariation_GetFullName},
{"ShaderVariation_HasParameter", ShaderVariation_HasParameter},
{"ShaderVariation_HasTextureUnit", ShaderVariation_HasTextureUnit},
{"ShaderVariation_GetElementHash", ShaderVariation_GetElementHash},
{"ShaderVariation_GetDefines", ShaderVariation_GetDefines},
{"ShaderVariation_GetCompilerOutput", ShaderVariation_GetCompilerOutput},
{"ShaderVariation_GetConstantBufferSizes", ShaderVariation_GetConstantBufferSizes},
{"ShaderVariation_GetDefinesClipPlane", ShaderVariation_GetDefinesClipPlane},
{"Skybox_GetType", Skybox_GetType},
{"Skybox_GetTypeName", Skybox_GetTypeName},
{"Skybox_GetTypeStatic", Skybox_GetTypeStatic},
{"Skybox_GetTypeNameStatic", Skybox_GetTypeNameStatic},
{"Skybox_Skybox", Skybox_Skybox},
{"Skybox_RegisterObject", Skybox_RegisterObject},
{"Sphere_Sphere", Sphere_Sphere},
{"Sphere_Sphere0", Sphere_Sphere0},
{"Sphere_Sphere1", Sphere_Sphere1},
{"Sphere_Sphere2", Sphere_Sphere2},
{"Sphere_Sphere3", Sphere_Sphere3},
{"Sphere_Sphere4", Sphere_Sphere4},
{"Sphere_Sphere5", Sphere_Sphere5},
{"Sphere_Define", Sphere_Define},
{"Sphere_Define6", Sphere_Define6},
{"Sphere_Define7", Sphere_Define7},
{"Sphere_Define8", Sphere_Define8},
{"Sphere_Define9", Sphere_Define9},
{"Sphere_Define10", Sphere_Define10},
{"Sphere_Merge", Sphere_Merge},
{"Sphere_Merge11", Sphere_Merge11},
{"Sphere_Merge12", Sphere_Merge12},
{"Sphere_Merge13", Sphere_Merge13},
{"Sphere_Merge14", Sphere_Merge14},
{"Sphere_Merge15", Sphere_Merge15},
{"Sphere_Clear", Sphere_Clear},
{"Sphere_Defined", Sphere_Defined},
{"Sphere_IsInside", Sphere_IsInside},
{"Sphere_IsInside16", Sphere_IsInside16},
{"Sphere_IsInsideFast", Sphere_IsInsideFast},
{"Sphere_IsInside17", Sphere_IsInside17},
{"Sphere_IsInsideFast18", Sphere_IsInsideFast18},
{"Sphere_Distance", Sphere_Distance},
{"Sphere_GetLocalPoint", Sphere_GetLocalPoint},
{"Sphere_GetPoint", Sphere_GetPoint},
{"Sphere_GetCenter", Sphere_GetCenter},
{"Sphere_GetRadius", Sphere_GetRadius},
{"Sphere_SetRadius", Sphere_SetRadius},
{"Spline_Spline", Spline_Spline},
{"Spline_Spline0", Spline_Spline0},
{"Spline_GetInterpolationMode", Spline_GetInterpolationMode},
{"Spline_GetKnot", Spline_GetKnot},
{"Spline_GetPoint", Spline_GetPoint},
{"Spline_SetInterpolationMode", Spline_SetInterpolationMode},
{"Spline_SetKnot_0", Spline_SetKnot_0},
{"Spline_SetKnot_1", Spline_SetKnot_1},
{"Spline_SetKnot_2", Spline_SetKnot_2},
{"Spline_SetKnot_3", Spline_SetKnot_3},
{"Spline_SetKnot_4", Spline_SetKnot_4},
{"Spline_SetKnot_5", Spline_SetKnot_5},
{"Spline_SetKnot_6", Spline_SetKnot_6},
{"Spline_SetKnot_7", Spline_SetKnot_7},
{"Spline_SetKnot_8", Spline_SetKnot_8},
{"Spline_SetKnot_9", Spline_SetKnot_9},
{"Spline_SetKnot_10", Spline_SetKnot_10},
{"Spline_SetKnot_11", Spline_SetKnot_11},
{"Spline_SetKnot_12", Spline_SetKnot_12},
{"Spline_SetKnot_13", Spline_SetKnot_13},
{"Spline_SetKnot_14", Spline_SetKnot_14},
{"Spline_AddKnot_0", Spline_AddKnot_0},
{"Spline_AddKnot_1", Spline_AddKnot_1},
{"Spline_AddKnot_2", Spline_AddKnot_2},
{"Spline_AddKnot_3", Spline_AddKnot_3},
{"Spline_AddKnot_4", Spline_AddKnot_4},
{"Spline_AddKnot_5", Spline_AddKnot_5},
{"Spline_AddKnot_6", Spline_AddKnot_6},
{"Spline_AddKnot_7", Spline_AddKnot_7},
{"Spline_AddKnot_8", Spline_AddKnot_8},
{"Spline_AddKnot_9", Spline_AddKnot_9},
{"Spline_AddKnot_10", Spline_AddKnot_10},
{"Spline_AddKnot_11", Spline_AddKnot_11},
{"Spline_AddKnot_12", Spline_AddKnot_12},
{"Spline_AddKnot_13", Spline_AddKnot_13},
{"Spline_AddKnot_14", Spline_AddKnot_14},
{"Spline_AddKnot1_0", Spline_AddKnot1_0},
{"Spline_AddKnot1_1", Spline_AddKnot1_1},
{"Spline_AddKnot1_2", Spline_AddKnot1_2},
{"Spline_AddKnot1_3", Spline_AddKnot1_3},
{"Spline_AddKnot1_4", Spline_AddKnot1_4},
{"Spline_AddKnot1_5", Spline_AddKnot1_5},
{"Spline_AddKnot1_6", Spline_AddKnot1_6},
{"Spline_AddKnot1_7", Spline_AddKnot1_7},
{"Spline_AddKnot1_8", Spline_AddKnot1_8},
{"Spline_AddKnot1_9", Spline_AddKnot1_9},
{"Spline_AddKnot1_10", Spline_AddKnot1_10},
{"Spline_AddKnot1_11", Spline_AddKnot1_11},
{"Spline_AddKnot1_12", Spline_AddKnot1_12},
{"Spline_AddKnot1_13", Spline_AddKnot1_13},
{"Spline_AddKnot1_14", Spline_AddKnot1_14},
{"Spline_RemoveKnot", Spline_RemoveKnot},
{"Spline_RemoveKnot2", Spline_RemoveKnot2},
{"Spline_Clear", Spline_Clear},
{"SplinePath_GetType", SplinePath_GetType},
{"SplinePath_GetTypeName", SplinePath_GetTypeName},
{"SplinePath_GetTypeStatic", SplinePath_GetTypeStatic},
{"SplinePath_GetTypeNameStatic", SplinePath_GetTypeNameStatic},
{"SplinePath_SplinePath", SplinePath_SplinePath},
{"SplinePath_RegisterObject", SplinePath_RegisterObject},
{"SplinePath_ApplyAttributes", SplinePath_ApplyAttributes},
{"SplinePath_DrawDebugGeometry", SplinePath_DrawDebugGeometry},
{"SplinePath_AddControlPoint", SplinePath_AddControlPoint},
{"SplinePath_RemoveControlPoint", SplinePath_RemoveControlPoint},
{"SplinePath_ClearControlPoints", SplinePath_ClearControlPoints},
{"SplinePath_SetInterpolationMode", SplinePath_SetInterpolationMode},
{"SplinePath_SetSpeed", SplinePath_SetSpeed},
{"SplinePath_SetPosition", SplinePath_SetPosition},
{"SplinePath_SetControlledNode", SplinePath_SetControlledNode},
{"SplinePath_GetInterpolationMode", SplinePath_GetInterpolationMode},
{"SplinePath_GetSpeed", SplinePath_GetSpeed},
{"SplinePath_GetLength", SplinePath_GetLength},
{"SplinePath_GetPosition", SplinePath_GetPosition},
{"SplinePath_GetControlledNode", SplinePath_GetControlledNode},
{"SplinePath_GetPoint", SplinePath_GetPoint},
{"SplinePath_Move", SplinePath_Move},
{"SplinePath_Reset", SplinePath_Reset},
{"SplinePath_IsFinished", SplinePath_IsFinished},
{"SplinePath_SetControlledIdAttr", SplinePath_SetControlledIdAttr},
{"SplinePath_GetControlledIdAttr", SplinePath_GetControlledIdAttr},
{"StaticModel_GetType", StaticModel_GetType},
{"StaticModel_GetTypeName", StaticModel_GetTypeName},
{"StaticModel_GetTypeStatic", StaticModel_GetTypeStatic},
{"StaticModel_GetTypeNameStatic", StaticModel_GetTypeNameStatic},
{"StaticModel_StaticModel", StaticModel_StaticModel},
{"StaticModel_RegisterObject", StaticModel_RegisterObject},
{"StaticModel_GetLodGeometry", StaticModel_GetLodGeometry},
{"StaticModel_GetNumOccluderTriangles", StaticModel_GetNumOccluderTriangles},
{"StaticModel_DrawOcclusion", StaticModel_DrawOcclusion},
{"StaticModel_SetModel", StaticModel_SetModel},
{"StaticModel_SetMaterial", StaticModel_SetMaterial},
{"StaticModel_SetMaterial0", StaticModel_SetMaterial0},
{"StaticModel_SetOcclusionLodLevel", StaticModel_SetOcclusionLodLevel},
{"StaticModel_ApplyMaterialList", StaticModel_ApplyMaterialList},
{"StaticModel_GetModel", StaticModel_GetModel},
{"StaticModel_GetNumGeometries", StaticModel_GetNumGeometries},
{"StaticModel_GetMaterial", StaticModel_GetMaterial},
{"StaticModel_GetMaterial1", StaticModel_GetMaterial1},
{"StaticModel_GetOcclusionLodLevel", StaticModel_GetOcclusionLodLevel},
{"StaticModel_IsInside", StaticModel_IsInside},
{"StaticModel_IsInsideLocal", StaticModel_IsInsideLocal},
{"StaticModel_GetModelAttr", StaticModel_GetModelAttr},
{"StaticModelGroup_GetType", StaticModelGroup_GetType},
{"StaticModelGroup_GetTypeName", StaticModelGroup_GetTypeName},
{"StaticModelGroup_GetTypeStatic", StaticModelGroup_GetTypeStatic},
{"StaticModelGroup_GetTypeNameStatic", StaticModelGroup_GetTypeNameStatic},
{"StaticModelGroup_StaticModelGroup", StaticModelGroup_StaticModelGroup},
{"StaticModelGroup_RegisterObject", StaticModelGroup_RegisterObject},
{"StaticModelGroup_ApplyAttributes", StaticModelGroup_ApplyAttributes},
{"StaticModelGroup_GetNumOccluderTriangles", StaticModelGroup_GetNumOccluderTriangles},
{"StaticModelGroup_DrawOcclusion", StaticModelGroup_DrawOcclusion},
{"StaticModelGroup_AddInstanceNode", StaticModelGroup_AddInstanceNode},
{"StaticModelGroup_RemoveInstanceNode", StaticModelGroup_RemoveInstanceNode},
{"StaticModelGroup_RemoveAllInstanceNodes", StaticModelGroup_RemoveAllInstanceNodes},
{"StaticModelGroup_GetNumInstanceNodes", StaticModelGroup_GetNumInstanceNodes},
{"StaticModelGroup_GetInstanceNode", StaticModelGroup_GetInstanceNode},
{"Technique_GetType", Technique_GetType},
{"Technique_GetTypeName", Technique_GetTypeName},
{"Technique_GetTypeStatic", Technique_GetTypeStatic},
{"Technique_GetTypeNameStatic", Technique_GetTypeNameStatic},
{"Technique_Technique", Technique_Technique},
{"Technique_RegisterObject", Technique_RegisterObject},
{"Technique_BeginLoad_File", Technique_BeginLoad_File},
{"Technique_BeginLoad_MemoryBuffer", Technique_BeginLoad_MemoryBuffer},
{"Technique_SetIsDesktop", Technique_SetIsDesktop},
{"Technique_CreatePass", Technique_CreatePass},
{"Technique_RemovePass", Technique_RemovePass},
{"Technique_ReleaseShaders", Technique_ReleaseShaders},
{"Technique_Clone", Technique_Clone},
{"Technique_IsDesktop", Technique_IsDesktop},
{"Technique_IsSupported", Technique_IsSupported},
{"Technique_HasPass", Technique_HasPass},
{"Technique_HasPass0", Technique_HasPass0},
{"Technique_GetPass", Technique_GetPass},
{"Technique_GetPass1", Technique_GetPass1},
{"Technique_GetSupportedPass", Technique_GetSupportedPass},
{"Technique_GetSupportedPass2", Technique_GetSupportedPass2},
{"Technique_GetNumPasses", Technique_GetNumPasses},
{"Technique_CloneWithDefines", Technique_CloneWithDefines},
{"Technique_GetPassIndex", Technique_GetPassIndex},
{"TerrainPatch_GetType", TerrainPatch_GetType},
{"TerrainPatch_GetTypeName", TerrainPatch_GetTypeName},
{"TerrainPatch_GetTypeStatic", TerrainPatch_GetTypeStatic},
{"TerrainPatch_GetTypeNameStatic", TerrainPatch_GetTypeNameStatic},
{"TerrainPatch_TerrainPatch", TerrainPatch_TerrainPatch},
{"TerrainPatch_RegisterObject", TerrainPatch_RegisterObject},
{"TerrainPatch_GetUpdateGeometryType", TerrainPatch_GetUpdateGeometryType},
{"TerrainPatch_GetLodGeometry", TerrainPatch_GetLodGeometry},
{"TerrainPatch_GetNumOccluderTriangles", TerrainPatch_GetNumOccluderTriangles},
{"TerrainPatch_DrawOcclusion", TerrainPatch_DrawOcclusion},
{"TerrainPatch_DrawDebugGeometry", TerrainPatch_DrawDebugGeometry},
{"TerrainPatch_SetOwner", TerrainPatch_SetOwner},
{"TerrainPatch_SetNeighbors", TerrainPatch_SetNeighbors},
{"TerrainPatch_SetMaterial", TerrainPatch_SetMaterial},
{"TerrainPatch_SetBoundingBox", TerrainPatch_SetBoundingBox},
{"TerrainPatch_SetCoordinates", TerrainPatch_SetCoordinates},
{"TerrainPatch_ResetLod", TerrainPatch_ResetLod},
{"TerrainPatch_GetGeometry", TerrainPatch_GetGeometry},
{"TerrainPatch_GetMaxLodGeometry", TerrainPatch_GetMaxLodGeometry},
{"TerrainPatch_GetOcclusionGeometry", TerrainPatch_GetOcclusionGeometry},
{"TerrainPatch_GetVertexBuffer", TerrainPatch_GetVertexBuffer},
{"TerrainPatch_GetOwner", TerrainPatch_GetOwner},
{"TerrainPatch_GetNorthPatch", TerrainPatch_GetNorthPatch},
{"TerrainPatch_GetSouthPatch", TerrainPatch_GetSouthPatch},
{"TerrainPatch_GetWestPatch", TerrainPatch_GetWestPatch},
{"TerrainPatch_GetEastPatch", TerrainPatch_GetEastPatch},
{"TerrainPatch_GetCoordinates", TerrainPatch_GetCoordinates},
{"TerrainPatch_GetLodLevel", TerrainPatch_GetLodLevel},
{"Texture_CastToGPUObject", Texture_CastToGPUObject},
{"Texture_GetType", Texture_GetType},
{"Texture_GetTypeName", Texture_GetTypeName},
{"Texture_GetTypeStatic", Texture_GetTypeStatic},
{"Texture_GetTypeNameStatic", Texture_GetTypeNameStatic},
{"Texture_Texture", Texture_Texture},
{"Texture_SetNumLevels", Texture_SetNumLevels},
{"Texture_SetFilterMode", Texture_SetFilterMode},
{"Texture_SetAddressMode", Texture_SetAddressMode},
{"Texture_SetAnisotropy", Texture_SetAnisotropy},
{"Texture_SetShadowCompare", Texture_SetShadowCompare},
{"Texture_SetBorderColor", Texture_SetBorderColor},
{"Texture_SetSRGB", Texture_SetSRGB},
{"Texture_SetBackupTexture", Texture_SetBackupTexture},
{"Texture_SetMipsToSkip", Texture_SetMipsToSkip},
{"Texture_GetFormat", Texture_GetFormat},
{"Texture_IsCompressed", Texture_IsCompressed},
{"Texture_GetLevels", Texture_GetLevels},
{"Texture_GetWidth", Texture_GetWidth},
{"Texture_GetHeight", Texture_GetHeight},
{"Texture_GetDepth", Texture_GetDepth},
{"Texture_GetFilterMode", Texture_GetFilterMode},
{"Texture_GetAddressMode", Texture_GetAddressMode},
{"Texture_GetAnisotropy", Texture_GetAnisotropy},
{"Texture_GetShadowCompare", Texture_GetShadowCompare},
{"Texture_GetBorderColor", Texture_GetBorderColor},
{"Texture_GetSRGB", Texture_GetSRGB},
{"Texture_GetMultiSample", Texture_GetMultiSample},
{"Texture_GetAutoResolve", Texture_GetAutoResolve},
{"Texture_IsResolveDirty", Texture_IsResolveDirty},
{"Texture_GetLevelsDirty", Texture_GetLevelsDirty},
{"Texture_GetBackupTexture", Texture_GetBackupTexture},
{"Texture_GetMipsToSkip", Texture_GetMipsToSkip},
{"Texture_GetLevelWidth", Texture_GetLevelWidth},
{"Texture_GetLevelHeight", Texture_GetLevelHeight},
{"Texture_GetLevelDepth", Texture_GetLevelDepth},
{"Texture_GetUsage", Texture_GetUsage},
{"Texture_GetDataSize", Texture_GetDataSize},
{"Texture_GetDataSize0", Texture_GetDataSize0},
{"Texture_GetRowDataSize", Texture_GetRowDataSize},
{"Texture_GetComponents", Texture_GetComponents},
{"Texture_GetParametersDirty", Texture_GetParametersDirty},
{"Texture_SetParameters", Texture_SetParameters},
{"Texture_SetParameters1", Texture_SetParameters1},
{"Texture_SetParametersDirty", Texture_SetParametersDirty},
{"Texture_UpdateParameters", Texture_UpdateParameters},
{"Texture_GetShaderResourceView", Texture_GetShaderResourceView},
{"Texture_GetSampler", Texture_GetSampler},
{"Texture_GetResolveTexture", Texture_GetResolveTexture},
{"Texture_GetSRGBFormat", Texture_GetSRGBFormat},
{"Texture_SetResolveDirty", Texture_SetResolveDirty},
{"Texture_SetLevelsDirty", Texture_SetLevelsDirty},
{"Texture_RegenerateLevels", Texture_RegenerateLevels},
{"Texture_CheckMaxLevels", Texture_CheckMaxLevels},
{"Texture_CheckMaxLevels2", Texture_CheckMaxLevels2},
{"Texture2DArray_GetType", Texture2DArray_GetType},
{"Texture2DArray_GetTypeName", Texture2DArray_GetTypeName},
{"Texture2DArray_GetTypeStatic", Texture2DArray_GetTypeStatic},
{"Texture2DArray_GetTypeNameStatic", Texture2DArray_GetTypeNameStatic},
{"Texture2DArray_Texture2DArray", Texture2DArray_Texture2DArray},
{"Texture2DArray_RegisterObject", Texture2DArray_RegisterObject},
{"Texture2DArray_BeginLoad_File", Texture2DArray_BeginLoad_File},
{"Texture2DArray_BeginLoad_MemoryBuffer", Texture2DArray_BeginLoad_MemoryBuffer},
{"Texture2DArray_EndLoad", Texture2DArray_EndLoad},
{"Texture2DArray_OnDeviceLost", Texture2DArray_OnDeviceLost},
{"Texture2DArray_OnDeviceReset", Texture2DArray_OnDeviceReset},
{"Texture2DArray_Release", Texture2DArray_Release},
{"Texture2DArray_SetLayers", Texture2DArray_SetLayers},
{"Texture2DArray_SetSize", Texture2DArray_SetSize},
{"Texture2DArray_SetData", Texture2DArray_SetData},
{"Texture2DArray_SetData0_File", Texture2DArray_SetData0_File},
{"Texture2DArray_SetData0_MemoryBuffer", Texture2DArray_SetData0_MemoryBuffer},
{"Texture2DArray_SetData1", Texture2DArray_SetData1},
{"Texture2DArray_GetLayers", Texture2DArray_GetLayers},
{"Texture2DArray_GetData", Texture2DArray_GetData},
{"Texture2DArray_GetRenderSurface", Texture2DArray_GetRenderSurface},
{"Texture3D_GetType", Texture3D_GetType},
{"Texture3D_GetTypeName", Texture3D_GetTypeName},
{"Texture3D_GetTypeStatic", Texture3D_GetTypeStatic},
{"Texture3D_GetTypeNameStatic", Texture3D_GetTypeNameStatic},
{"Texture3D_Texture3D", Texture3D_Texture3D},
{"Texture3D_RegisterObject", Texture3D_RegisterObject},
{"Texture3D_BeginLoad_File", Texture3D_BeginLoad_File},
{"Texture3D_BeginLoad_MemoryBuffer", Texture3D_BeginLoad_MemoryBuffer},
{"Texture3D_EndLoad", Texture3D_EndLoad},
{"Texture3D_Release", Texture3D_Release},
{"Texture3D_SetSize", Texture3D_SetSize},
{"Texture3D_SetData", Texture3D_SetData},
{"Texture3D_SetData0", Texture3D_SetData0},
{"Texture3D_GetData", Texture3D_GetData},
{"TextureCube_GetType", TextureCube_GetType},
{"TextureCube_GetTypeName", TextureCube_GetTypeName},
{"TextureCube_GetTypeStatic", TextureCube_GetTypeStatic},
{"TextureCube_GetTypeNameStatic", TextureCube_GetTypeNameStatic},
{"TextureCube_TextureCube", TextureCube_TextureCube},
{"TextureCube_RegisterObject", TextureCube_RegisterObject},
{"TextureCube_BeginLoad_File", TextureCube_BeginLoad_File},
{"TextureCube_BeginLoad_MemoryBuffer", TextureCube_BeginLoad_MemoryBuffer},
{"TextureCube_EndLoad", TextureCube_EndLoad},
{"TextureCube_Release", TextureCube_Release},
{"TextureCube_SetSize", TextureCube_SetSize},
{"TextureCube_SetData", TextureCube_SetData},
{"TextureCube_SetData0_File", TextureCube_SetData0_File},
{"TextureCube_SetData0_MemoryBuffer", TextureCube_SetData0_MemoryBuffer},
{"TextureCube_SetData1", TextureCube_SetData1},
{"TextureCube_GetData", TextureCube_GetData},
{"TextureCube_GetImage", TextureCube_GetImage},
{"TextureCube_GetRenderSurface", TextureCube_GetRenderSurface},
{"TriangleMeshData_TriangleMeshData", TriangleMeshData_TriangleMeshData},
{"TriangleMeshData_TriangleMeshData0", TriangleMeshData_TriangleMeshData0},
{"UIComponent_GetType", UIComponent_GetType},
{"UIComponent_GetTypeName", UIComponent_GetTypeName},
{"UIComponent_GetTypeStatic", UIComponent_GetTypeStatic},
{"UIComponent_GetTypeNameStatic", UIComponent_GetTypeNameStatic},
{"UIComponent_UIComponent", UIComponent_UIComponent},
{"UIComponent_RegisterObject", UIComponent_RegisterObject},
{"UIComponent_GetRoot", UIComponent_GetRoot},
{"UIComponent_GetMaterial", UIComponent_GetMaterial},
{"UIComponent_GetTexture", UIComponent_GetTexture},
{"UIComponent_SetViewportIndex", UIComponent_SetViewportIndex},
{"UISelectable_GetType", UISelectable_GetType},
{"UISelectable_GetTypeName", UISelectable_GetTypeName},
{"UISelectable_GetTypeStatic", UISelectable_GetTypeStatic},
{"UISelectable_GetTypeNameStatic", UISelectable_GetTypeNameStatic},
{"UISelectable_RegisterObject", UISelectable_RegisterObject},
{"UISelectable_SetSelectionColor", UISelectable_SetSelectionColor},
{"UISelectable_SetHoverColor", UISelectable_SetHoverColor},
{"UISelectable_GetSelectionColor", UISelectable_GetSelectionColor},
{"UISelectable_GetHoverColor", UISelectable_GetHoverColor},
{"UISelectable_UISelectable", UISelectable_UISelectable},
{"UnknownComponent_UnknownComponent", UnknownComponent_UnknownComponent},
{"UnknownComponent_RegisterObject", UnknownComponent_RegisterObject},
{"UnknownComponent_GetType", UnknownComponent_GetType},
{"UnknownComponent_GetTypeName", UnknownComponent_GetTypeName},
{"UnknownComponent_Load_File", UnknownComponent_Load_File},
{"UnknownComponent_Load_MemoryBuffer", UnknownComponent_Load_MemoryBuffer},
{"UnknownComponent_LoadXML", UnknownComponent_LoadXML},
{"UnknownComponent_Save_File", UnknownComponent_Save_File},
{"UnknownComponent_Save_MemoryBuffer", UnknownComponent_Save_MemoryBuffer},
{"UnknownComponent_SaveXML", UnknownComponent_SaveXML},
{"UnknownComponent_SetTypeName", UnknownComponent_SetTypeName},
{"UnknownComponent_SetType", UnknownComponent_SetType},
{"UnknownComponent_GetUseXML", UnknownComponent_GetUseXML},
{"UnknownComponent_GetTypeStatic", UnknownComponent_GetTypeStatic},
{"UnknownComponent_GetTypeNameStatic", UnknownComponent_GetTypeNameStatic},
{"VGCanvas_GetType", VGCanvas_GetType},
{"VGCanvas_GetTypeName", VGCanvas_GetTypeName},
{"VGCanvas_GetTypeStatic", VGCanvas_GetTypeStatic},
{"VGCanvas_GetTypeNameStatic", VGCanvas_GetTypeNameStatic},
{"VGCanvas_VGCanvas", VGCanvas_VGCanvas},
{"VGCanvas_RegisterObject", VGCanvas_RegisterObject},
{"VGTextRow_GetType", VGTextRow_GetType},
{"VGTextRow_GetTypeName", VGTextRow_GetTypeName},
{"VGTextRow_GetTypeStatic", VGTextRow_GetTypeStatic},
{"VGTextRow_GetTypeNameStatic", VGTextRow_GetTypeNameStatic},
{"VGTextRow_VGTextRow", VGTextRow_VGTextRow},
{"VGTextRow_VGTextRow0", VGTextRow_VGTextRow0},
{"VGTextRow_GetText", VGTextRow_GetText},
{"VGTextRow_SetText", VGTextRow_SetText},
{"VGTextRow_GetWidth", VGTextRow_GetWidth},
{"VGTextRow_SetWidth", VGTextRow_SetWidth},
{"VGTextRow_GetMin", VGTextRow_GetMin},
{"VGTextRow_SetMin", VGTextRow_SetMin},
{"VGTextRow_GetMax", VGTextRow_GetMax},
{"VGTextRow_SetMax", VGTextRow_SetMax},
{"ValueAnimation_GetType", ValueAnimation_GetType},
{"ValueAnimation_GetTypeName", ValueAnimation_GetTypeName},
{"ValueAnimation_GetTypeStatic", ValueAnimation_GetTypeStatic},
{"ValueAnimation_GetTypeNameStatic", ValueAnimation_GetTypeNameStatic},
{"ValueAnimation_ValueAnimation", ValueAnimation_ValueAnimation},
{"ValueAnimation_RegisterObject", ValueAnimation_RegisterObject},
{"ValueAnimation_BeginLoad_File", ValueAnimation_BeginLoad_File},
{"ValueAnimation_BeginLoad_MemoryBuffer", ValueAnimation_BeginLoad_MemoryBuffer},
{"ValueAnimation_Save_File", ValueAnimation_Save_File},
{"ValueAnimation_Save_MemoryBuffer", ValueAnimation_Save_MemoryBuffer},
{"ValueAnimation_LoadXML", ValueAnimation_LoadXML},
{"ValueAnimation_SaveXML", ValueAnimation_SaveXML},
{"ValueAnimation_SetOwner", ValueAnimation_SetOwner},
{"ValueAnimation_SetInterpolationMethod", ValueAnimation_SetInterpolationMethod},
{"ValueAnimation_SetSplineTension", ValueAnimation_SetSplineTension},
{"ValueAnimation_SetValueType", ValueAnimation_SetValueType},
{"ValueAnimation_SetKeyFrame_0", ValueAnimation_SetKeyFrame_0},
{"ValueAnimation_SetKeyFrame_1", ValueAnimation_SetKeyFrame_1},
{"ValueAnimation_SetKeyFrame_2", ValueAnimation_SetKeyFrame_2},
{"ValueAnimation_SetKeyFrame_3", ValueAnimation_SetKeyFrame_3},
{"ValueAnimation_SetKeyFrame_4", ValueAnimation_SetKeyFrame_4},
{"ValueAnimation_SetKeyFrame_5", ValueAnimation_SetKeyFrame_5},
{"ValueAnimation_SetKeyFrame_6", ValueAnimation_SetKeyFrame_6},
{"ValueAnimation_SetKeyFrame_7", ValueAnimation_SetKeyFrame_7},
{"ValueAnimation_SetKeyFrame_8", ValueAnimation_SetKeyFrame_8},
{"ValueAnimation_SetKeyFrame_9", ValueAnimation_SetKeyFrame_9},
{"ValueAnimation_SetKeyFrame_10", ValueAnimation_SetKeyFrame_10},
{"ValueAnimation_SetKeyFrame_11", ValueAnimation_SetKeyFrame_11},
{"ValueAnimation_SetKeyFrame_12", ValueAnimation_SetKeyFrame_12},
{"ValueAnimation_SetKeyFrame_13", ValueAnimation_SetKeyFrame_13},
{"ValueAnimation_SetKeyFrame_14", ValueAnimation_SetKeyFrame_14},
{"ValueAnimation_IsValid", ValueAnimation_IsValid},
{"ValueAnimation_GetOwner", ValueAnimation_GetOwner},
{"ValueAnimation_GetInterpolationMethod", ValueAnimation_GetInterpolationMethod},
{"ValueAnimation_GetSplineTension", ValueAnimation_GetSplineTension},
{"ValueAnimation_GetValueType", ValueAnimation_GetValueType},
{"ValueAnimation_GetBeginTime", ValueAnimation_GetBeginTime},
{"ValueAnimation_GetEndTime", ValueAnimation_GetEndTime},
{"ValueAnimation_GetAnimationValue", ValueAnimation_GetAnimationValue},
{"ValueAnimation_HasEventFrames", ValueAnimation_HasEventFrames},
{"ValueAnimationInfo_ValueAnimationInfo", ValueAnimationInfo_ValueAnimationInfo},
{"ValueAnimationInfo_ValueAnimationInfo0", ValueAnimationInfo_ValueAnimationInfo0},
{"ValueAnimationInfo_Update", ValueAnimationInfo_Update},
{"ValueAnimationInfo_SetTime", ValueAnimationInfo_SetTime},
{"ValueAnimationInfo_SetWrapMode", ValueAnimationInfo_SetWrapMode},
{"ValueAnimationInfo_SetSpeed", ValueAnimationInfo_SetSpeed},
{"ValueAnimationInfo_GetTarget", ValueAnimationInfo_GetTarget},
{"ValueAnimationInfo_GetAnimation", ValueAnimationInfo_GetAnimation},
{"ValueAnimationInfo_GetWrapMode", ValueAnimationInfo_GetWrapMode},
{"ValueAnimationInfo_GetTime", ValueAnimationInfo_GetTime},
{"ValueAnimationInfo_GetSpeed", ValueAnimationInfo_GetSpeed},
{"VectorGraphics_GetType", VectorGraphics_GetType},
{"VectorGraphics_GetTypeName", VectorGraphics_GetTypeName},
{"VectorGraphics_GetTypeStatic", VectorGraphics_GetTypeStatic},
{"VectorGraphics_GetTypeNameStatic", VectorGraphics_GetTypeNameStatic},
{"VectorGraphics_VectorGraphics", VectorGraphics_VectorGraphics},
{"VectorGraphics_Initialize", VectorGraphics_Initialize},
{"VectorGraphics_Clear", VectorGraphics_Clear},
{"VectorGraphics_GetNVGContext", VectorGraphics_GetNVGContext},
{"VectorGraphics_GetCurrentFrameBuffer", VectorGraphics_GetCurrentFrameBuffer},
{"VectorGraphics_CreateFont", VectorGraphics_CreateFont},
{"VectorGraphics_CreateFontAtIndex", VectorGraphics_CreateFontAtIndex},
{"VectorGraphics_CreateFontMem", VectorGraphics_CreateFontMem},
{"VectorGraphics_CreateFontMemAtIndex", VectorGraphics_CreateFontMemAtIndex},
{"VectorGraphics_FindFont", VectorGraphics_FindFont},
{"VectorGraphics_AddFallbackFontId", VectorGraphics_AddFallbackFontId},
{"VectorGraphics_ResetFallbackFontsId", VectorGraphics_ResetFallbackFontsId},
{"VectorGraphics_AddFallbackFont", VectorGraphics_AddFallbackFont},
{"VectorGraphics_ResetFallbackFonts", VectorGraphics_ResetFallbackFonts},
{"VectorGraphics_CreateImage", VectorGraphics_CreateImage},
{"VectorGraphics_CreateImageMem", VectorGraphics_CreateImageMem},
{"VectorGraphics_LoadSVGImage", VectorGraphics_LoadSVGImage},
{"VectorGraphics_GetSVGHeight", VectorGraphics_GetSVGHeight},
{"VectorGraphics_GetSVGWidth", VectorGraphics_GetSVGWidth},
{"VectorGraphics_GetSVGSize", VectorGraphics_GetSVGSize},
{"VectorGraphics_CreateImageRGBA", VectorGraphics_CreateImageRGBA},
{"VectorGraphics_UpdateImage", VectorGraphics_UpdateImage},
{"VectorGraphics_ImageSize", VectorGraphics_ImageSize},
{"VectorGraphics_DeleteImage", VectorGraphics_DeleteImage},
{"VectorGraphics_LoadSVGIntoTexture", VectorGraphics_LoadSVGIntoTexture},
{"Zone_GetType", Zone_GetType},
{"Zone_GetTypeName", Zone_GetTypeName},
{"Zone_GetTypeStatic", Zone_GetTypeStatic},
{"Zone_GetTypeNameStatic", Zone_GetTypeNameStatic},
{"Zone_Zone", Zone_Zone},
{"Zone_RegisterObject", Zone_RegisterObject},
{"Zone_DrawDebugGeometry", Zone_DrawDebugGeometry},
{"Zone_SetBoundingBox", Zone_SetBoundingBox},
{"Zone_SetAmbientColor", Zone_SetAmbientColor},
{"Zone_SetFogColor", Zone_SetFogColor},
{"Zone_SetFogStart", Zone_SetFogStart},
{"Zone_SetFogEnd", Zone_SetFogEnd},
{"Zone_SetFogHeight", Zone_SetFogHeight},
{"Zone_SetFogHeightScale", Zone_SetFogHeightScale},
{"Zone_SetPriority", Zone_SetPriority},
{"Zone_SetHeightFog", Zone_SetHeightFog},
{"Zone_SetOverride", Zone_SetOverride},
{"Zone_SetAmbientGradient", Zone_SetAmbientGradient},
{"Zone_SetZoneTexture", Zone_SetZoneTexture},
{"Zone_GetInverseWorldTransform", Zone_GetInverseWorldTransform},
{"Zone_GetAmbientColor", Zone_GetAmbientColor},
{"Zone_GetAmbientStartColor", Zone_GetAmbientStartColor},
{"Zone_GetAmbientEndColor", Zone_GetAmbientEndColor},
{"Zone_GetFogColor", Zone_GetFogColor},
{"Zone_GetFogStart", Zone_GetFogStart},
{"Zone_GetFogEnd", Zone_GetFogEnd},
{"Zone_GetFogHeight", Zone_GetFogHeight},
{"Zone_GetFogHeightScale", Zone_GetFogHeightScale},
{"Zone_GetPriority", Zone_GetPriority},
{"Zone_GetHeightFog", Zone_GetHeightFog},
{"Zone_GetOverride", Zone_GetOverride},
{"Zone_GetAmbientGradient", Zone_GetAmbientGradient},
{"Zone_GetZoneTexture", Zone_GetZoneTexture},
{"Zone_IsInside", Zone_IsInside},
{"Zone_GetZoneTextureAttr", Zone_GetZoneTextureAttr},
{"urho_navigationmesh_findpath", urho_navigationmesh_findpath},
{"NavigationMesh_GetType", NavigationMesh_GetType},
{"NavigationMesh_GetTypeName", NavigationMesh_GetTypeName},
{"NavigationMesh_GetTypeStatic", NavigationMesh_GetTypeStatic},
{"NavigationMesh_GetTypeNameStatic", NavigationMesh_GetTypeNameStatic},
{"NavigationMesh_NavigationMesh", NavigationMesh_NavigationMesh},
{"NavigationMesh_RegisterObject", NavigationMesh_RegisterObject},
{"NavigationMesh_DrawDebugGeometry", NavigationMesh_DrawDebugGeometry},
{"NavigationMesh_SetTileSize", NavigationMesh_SetTileSize},
{"NavigationMesh_SetCellSize", NavigationMesh_SetCellSize},
{"NavigationMesh_SetCellHeight", NavigationMesh_SetCellHeight},
{"NavigationMesh_SetAgentHeight", NavigationMesh_SetAgentHeight},
{"NavigationMesh_SetAgentRadius", NavigationMesh_SetAgentRadius},
{"NavigationMesh_SetAgentMaxClimb", NavigationMesh_SetAgentMaxClimb},
{"NavigationMesh_SetAgentMaxSlope", NavigationMesh_SetAgentMaxSlope},
{"NavigationMesh_SetRegionMinSize", NavigationMesh_SetRegionMinSize},
{"NavigationMesh_SetRegionMergeSize", NavigationMesh_SetRegionMergeSize},
{"NavigationMesh_SetEdgeMaxLength", NavigationMesh_SetEdgeMaxLength},
{"NavigationMesh_SetEdgeMaxError", NavigationMesh_SetEdgeMaxError},
{"NavigationMesh_SetDetailSampleDistance", NavigationMesh_SetDetailSampleDistance},
{"NavigationMesh_SetDetailSampleMaxError", NavigationMesh_SetDetailSampleMaxError},
{"NavigationMesh_SetPadding", NavigationMesh_SetPadding},
{"NavigationMesh_SetAreaCost", NavigationMesh_SetAreaCost},
{"NavigationMesh_Allocate", NavigationMesh_Allocate},
{"NavigationMesh_Build", NavigationMesh_Build},
{"NavigationMesh_Build0", NavigationMesh_Build0},
{"NavigationMesh_Build1", NavigationMesh_Build1},
{"NavigationMesh_RemoveTile", NavigationMesh_RemoveTile},
{"NavigationMesh_RemoveAllTiles", NavigationMesh_RemoveAllTiles},
{"NavigationMesh_HasTile", NavigationMesh_HasTile},
{"NavigationMesh_GetTileBoundingBox", NavigationMesh_GetTileBoundingBox},
{"NavigationMesh_GetTileIndex", NavigationMesh_GetTileIndex},
{"NavigationMesh_FindNearestPoint", NavigationMesh_FindNearestPoint},
{"NavigationMesh_MoveAlongSurface", NavigationMesh_MoveAlongSurface},
{"NavigationMesh_GetRandomPoint", NavigationMesh_GetRandomPoint},
{"NavigationMesh_GetRandomPointInCircle", NavigationMesh_GetRandomPointInCircle},
{"NavigationMesh_GetDistanceToWall", NavigationMesh_GetDistanceToWall},
{"NavigationMesh_Raycast", NavigationMesh_Raycast},
{"NavigationMesh_DrawDebugGeometry2", NavigationMesh_DrawDebugGeometry2},
{"NavigationMesh_GetMeshName", NavigationMesh_GetMeshName},
{"NavigationMesh_SetMeshName", NavigationMesh_SetMeshName},
{"NavigationMesh_GetTileSize", NavigationMesh_GetTileSize},
{"NavigationMesh_GetCellSize", NavigationMesh_GetCellSize},
{"NavigationMesh_GetCellHeight", NavigationMesh_GetCellHeight},
{"NavigationMesh_GetAgentHeight", NavigationMesh_GetAgentHeight},
{"NavigationMesh_GetAgentRadius", NavigationMesh_GetAgentRadius},
{"NavigationMesh_GetAgentMaxClimb", NavigationMesh_GetAgentMaxClimb},
{"NavigationMesh_GetAgentMaxSlope", NavigationMesh_GetAgentMaxSlope},
{"NavigationMesh_GetRegionMinSize", NavigationMesh_GetRegionMinSize},
{"NavigationMesh_GetRegionMergeSize", NavigationMesh_GetRegionMergeSize},
{"NavigationMesh_GetEdgeMaxLength", NavigationMesh_GetEdgeMaxLength},
{"NavigationMesh_GetEdgeMaxError", NavigationMesh_GetEdgeMaxError},
{"NavigationMesh_GetDetailSampleDistance", NavigationMesh_GetDetailSampleDistance},
{"NavigationMesh_GetDetailSampleMaxError", NavigationMesh_GetDetailSampleMaxError},
{"NavigationMesh_GetPadding", NavigationMesh_GetPadding},
{"NavigationMesh_GetAreaCost", NavigationMesh_GetAreaCost},
{"NavigationMesh_IsInitialized", NavigationMesh_IsInitialized},
{"NavigationMesh_GetBoundingBox", NavigationMesh_GetBoundingBox},
{"NavigationMesh_GetWorldBoundingBox", NavigationMesh_GetWorldBoundingBox},
{"NavigationMesh_GetNumTiles", NavigationMesh_GetNumTiles},
{"NavigationMesh_SetPartitionType", NavigationMesh_SetPartitionType},
{"NavigationMesh_GetPartitionType", NavigationMesh_GetPartitionType},
{"NavigationMesh_SetDrawOffMeshConnections", NavigationMesh_SetDrawOffMeshConnections},
{"NavigationMesh_GetDrawOffMeshConnections", NavigationMesh_GetDrawOffMeshConnections},
{"NavigationMesh_SetDrawNavAreas", NavigationMesh_SetDrawNavAreas},
{"NavigationMesh_GetDrawNavAreas", NavigationMesh_GetDrawNavAreas},
{"CrowdAgent_GetType", CrowdAgent_GetType},
{"CrowdAgent_GetTypeName", CrowdAgent_GetTypeName},
{"CrowdAgent_GetTypeStatic", CrowdAgent_GetTypeStatic},
{"CrowdAgent_GetTypeNameStatic", CrowdAgent_GetTypeNameStatic},
{"CrowdAgent_CrowdAgent", CrowdAgent_CrowdAgent},
{"CrowdAgent_RegisterObject", CrowdAgent_RegisterObject},
{"CrowdAgent_ApplyAttributes", CrowdAgent_ApplyAttributes},
{"CrowdAgent_OnSetEnabled", CrowdAgent_OnSetEnabled},
{"CrowdAgent_DrawDebugGeometry", CrowdAgent_DrawDebugGeometry},
{"CrowdAgent_DrawDebugGeometry0", CrowdAgent_DrawDebugGeometry0},
{"CrowdAgent_SetTargetPosition", CrowdAgent_SetTargetPosition},
{"CrowdAgent_SetTargetVelocity", CrowdAgent_SetTargetVelocity},
{"CrowdAgent_ResetTarget", CrowdAgent_ResetTarget},
{"CrowdAgent_SetUpdateNodePosition", CrowdAgent_SetUpdateNodePosition},
{"CrowdAgent_SetMaxAccel", CrowdAgent_SetMaxAccel},
{"CrowdAgent_SetMaxSpeed", CrowdAgent_SetMaxSpeed},
{"CrowdAgent_SetRadius", CrowdAgent_SetRadius},
{"CrowdAgent_SetHeight", CrowdAgent_SetHeight},
{"CrowdAgent_SetQueryFilterType", CrowdAgent_SetQueryFilterType},
{"CrowdAgent_SetObstacleAvoidanceType", CrowdAgent_SetObstacleAvoidanceType},
{"CrowdAgent_SetNavigationQuality", CrowdAgent_SetNavigationQuality},
{"CrowdAgent_SetNavigationPushiness", CrowdAgent_SetNavigationPushiness},
{"CrowdAgent_GetPosition", CrowdAgent_GetPosition},
{"CrowdAgent_GetDesiredVelocity", CrowdAgent_GetDesiredVelocity},
{"CrowdAgent_GetActualVelocity", CrowdAgent_GetActualVelocity},
{"CrowdAgent_GetTargetPosition", CrowdAgent_GetTargetPosition},
{"CrowdAgent_GetTargetVelocity", CrowdAgent_GetTargetVelocity},
{"CrowdAgent_GetRequestedTargetType", CrowdAgent_GetRequestedTargetType},
{"CrowdAgent_GetAgentState", CrowdAgent_GetAgentState},
{"CrowdAgent_GetTargetState", CrowdAgent_GetTargetState},
{"CrowdAgent_GetUpdateNodePosition", CrowdAgent_GetUpdateNodePosition},
{"CrowdAgent_GetAgentCrowdId", CrowdAgent_GetAgentCrowdId},
{"CrowdAgent_GetMaxAccel", CrowdAgent_GetMaxAccel},
{"CrowdAgent_GetMaxSpeed", CrowdAgent_GetMaxSpeed},
{"CrowdAgent_GetRadius", CrowdAgent_GetRadius},
{"CrowdAgent_GetHeight", CrowdAgent_GetHeight},
{"CrowdAgent_GetQueryFilterType", CrowdAgent_GetQueryFilterType},
{"CrowdAgent_GetObstacleAvoidanceType", CrowdAgent_GetObstacleAvoidanceType},
{"CrowdAgent_GetNavigationQuality", CrowdAgent_GetNavigationQuality},
{"CrowdAgent_GetNavigationPushiness", CrowdAgent_GetNavigationPushiness},
{"CrowdAgent_HasRequestedTarget", CrowdAgent_HasRequestedTarget},
{"CrowdAgent_HasArrived", CrowdAgent_HasArrived},
{"CrowdAgent_IsInCrowd", CrowdAgent_IsInCrowd},
{"CrowdManager_GetType", CrowdManager_GetType},
{"CrowdManager_GetTypeName", CrowdManager_GetTypeName},
{"CrowdManager_GetTypeStatic", CrowdManager_GetTypeStatic},
{"CrowdManager_GetTypeNameStatic", CrowdManager_GetTypeNameStatic},
{"CrowdManager_CrowdManager", CrowdManager_CrowdManager},
{"CrowdManager_RegisterObject", CrowdManager_RegisterObject},
{"CrowdManager_ApplyAttributes", CrowdManager_ApplyAttributes},
{"CrowdManager_DrawDebugGeometry", CrowdManager_DrawDebugGeometry},
{"CrowdManager_DrawDebugGeometry0", CrowdManager_DrawDebugGeometry0},
{"CrowdManager_SetCrowdTarget", CrowdManager_SetCrowdTarget},
{"CrowdManager_SetCrowdVelocity", CrowdManager_SetCrowdVelocity},
{"CrowdManager_ResetCrowdTarget", CrowdManager_ResetCrowdTarget},
{"CrowdManager_SetMaxAgents", CrowdManager_SetMaxAgents},
{"CrowdManager_SetMaxAgentRadius", CrowdManager_SetMaxAgentRadius},
{"CrowdManager_SetNavigationMesh", CrowdManager_SetNavigationMesh},
{"CrowdManager_SetIncludeFlags", CrowdManager_SetIncludeFlags},
{"CrowdManager_SetExcludeFlags", CrowdManager_SetExcludeFlags},
{"CrowdManager_SetAreaCost", CrowdManager_SetAreaCost},
{"CrowdManager_SetObstacleAvoidanceParams", CrowdManager_SetObstacleAvoidanceParams},
{"CrowdManager_FindNearestPoint", CrowdManager_FindNearestPoint},
{"CrowdManager_MoveAlongSurface", CrowdManager_MoveAlongSurface},
{"CrowdManager_GetRandomPoint", CrowdManager_GetRandomPoint},
{"CrowdManager_GetRandomPointInCircle", CrowdManager_GetRandomPointInCircle},
{"CrowdManager_GetDistanceToWall", CrowdManager_GetDistanceToWall},
{"CrowdManager_Raycast", CrowdManager_Raycast},
{"CrowdManager_GetMaxAgents", CrowdManager_GetMaxAgents},
{"CrowdManager_GetMaxAgentRadius", CrowdManager_GetMaxAgentRadius},
{"CrowdManager_GetNavigationMesh", CrowdManager_GetNavigationMesh},
{"CrowdManager_GetNumQueryFilterTypes", CrowdManager_GetNumQueryFilterTypes},
{"CrowdManager_GetNumAreas", CrowdManager_GetNumAreas},
{"CrowdManager_GetIncludeFlags", CrowdManager_GetIncludeFlags},
{"CrowdManager_GetExcludeFlags", CrowdManager_GetExcludeFlags},
{"CrowdManager_GetAreaCost", CrowdManager_GetAreaCost},
{"CrowdManager_GetNumObstacleAvoidanceTypes", CrowdManager_GetNumObstacleAvoidanceTypes},
{"CrowdManager_GetObstacleAvoidanceParams", CrowdManager_GetObstacleAvoidanceParams},
{"DynamicNavigationMesh_GetType", DynamicNavigationMesh_GetType},
{"DynamicNavigationMesh_GetTypeName", DynamicNavigationMesh_GetTypeName},
{"DynamicNavigationMesh_GetTypeStatic", DynamicNavigationMesh_GetTypeStatic},
{"DynamicNavigationMesh_GetTypeNameStatic", DynamicNavigationMesh_GetTypeNameStatic},
{"DynamicNavigationMesh_DynamicNavigationMesh", DynamicNavigationMesh_DynamicNavigationMesh},
{"DynamicNavigationMesh_RegisterObject", DynamicNavigationMesh_RegisterObject},
{"DynamicNavigationMesh_Allocate", DynamicNavigationMesh_Allocate},
{"DynamicNavigationMesh_Build", DynamicNavigationMesh_Build},
{"DynamicNavigationMesh_Build0", DynamicNavigationMesh_Build0},
{"DynamicNavigationMesh_Build1", DynamicNavigationMesh_Build1},
{"DynamicNavigationMesh_IsObstacleInTile", DynamicNavigationMesh_IsObstacleInTile},
{"DynamicNavigationMesh_RemoveTile", DynamicNavigationMesh_RemoveTile},
{"DynamicNavigationMesh_RemoveAllTiles", DynamicNavigationMesh_RemoveAllTiles},
{"DynamicNavigationMesh_DrawDebugGeometry", DynamicNavigationMesh_DrawDebugGeometry},
{"DynamicNavigationMesh_DrawDebugGeometry2", DynamicNavigationMesh_DrawDebugGeometry2},
{"DynamicNavigationMesh_SetMaxObstacles", DynamicNavigationMesh_SetMaxObstacles},
{"DynamicNavigationMesh_SetMaxLayers", DynamicNavigationMesh_SetMaxLayers},
{"DynamicNavigationMesh_GetMaxObstacles", DynamicNavigationMesh_GetMaxObstacles},
{"DynamicNavigationMesh_GetMaxLayers", DynamicNavigationMesh_GetMaxLayers},
{"DynamicNavigationMesh_SetDrawObstacles", DynamicNavigationMesh_SetDrawObstacles},
{"DynamicNavigationMesh_GetDrawObstacles", DynamicNavigationMesh_GetDrawObstacles},
{"NavArea_GetType", NavArea_GetType},
{"NavArea_GetTypeName", NavArea_GetTypeName},
{"NavArea_GetTypeStatic", NavArea_GetTypeStatic},
{"NavArea_GetTypeNameStatic", NavArea_GetTypeNameStatic},
{"NavArea_NavArea", NavArea_NavArea},
{"NavArea_RegisterObject", NavArea_RegisterObject},
{"NavArea_DrawDebugGeometry", NavArea_DrawDebugGeometry},
{"NavArea_GetAreaID", NavArea_GetAreaID},
{"NavArea_SetAreaID", NavArea_SetAreaID},
{"NavArea_GetBoundingBox", NavArea_GetBoundingBox},
{"NavArea_SetBoundingBox", NavArea_SetBoundingBox},
{"NavArea_GetWorldBoundingBox", NavArea_GetWorldBoundingBox},
{"Navigable_GetType", Navigable_GetType},
{"Navigable_GetTypeName", Navigable_GetTypeName},
{"Navigable_GetTypeStatic", Navigable_GetTypeStatic},
{"Navigable_GetTypeNameStatic", Navigable_GetTypeNameStatic},
{"Navigable_Navigable", Navigable_Navigable},
{"Navigable_RegisterObject", Navigable_RegisterObject},
{"Navigable_SetRecursive", Navigable_SetRecursive},
{"Navigable_IsRecursive", Navigable_IsRecursive},
{"Obstacle_GetType", Obstacle_GetType},
{"Obstacle_GetTypeName", Obstacle_GetTypeName},
{"Obstacle_GetTypeStatic", Obstacle_GetTypeStatic},
{"Obstacle_GetTypeNameStatic", Obstacle_GetTypeNameStatic},
{"Obstacle_Obstacle", Obstacle_Obstacle},
{"Obstacle_RegisterObject", Obstacle_RegisterObject},
{"Obstacle_OnSetEnabled", Obstacle_OnSetEnabled},
{"Obstacle_GetHeight", Obstacle_GetHeight},
{"Obstacle_SetHeight", Obstacle_SetHeight},
{"Obstacle_GetRadius", Obstacle_GetRadius},
{"Obstacle_SetRadius", Obstacle_SetRadius},
{"Obstacle_GetObstacleID", Obstacle_GetObstacleID},
{"Obstacle_DrawDebugGeometry", Obstacle_DrawDebugGeometry},
{"Obstacle_DrawDebugGeometry0", Obstacle_DrawDebugGeometry0},
{"OffMeshConnection_GetType", OffMeshConnection_GetType},
{"OffMeshConnection_GetTypeName", OffMeshConnection_GetTypeName},
{"OffMeshConnection_GetTypeStatic", OffMeshConnection_GetTypeStatic},
{"OffMeshConnection_GetTypeNameStatic", OffMeshConnection_GetTypeNameStatic},
{"OffMeshConnection_OffMeshConnection", OffMeshConnection_OffMeshConnection},
{"OffMeshConnection_RegisterObject", OffMeshConnection_RegisterObject},
{"OffMeshConnection_ApplyAttributes", OffMeshConnection_ApplyAttributes},
{"OffMeshConnection_DrawDebugGeometry", OffMeshConnection_DrawDebugGeometry},
{"OffMeshConnection_SetEndPoint", OffMeshConnection_SetEndPoint},
{"OffMeshConnection_SetRadius", OffMeshConnection_SetRadius},
{"OffMeshConnection_SetBidirectional", OffMeshConnection_SetBidirectional},
{"OffMeshConnection_SetMask", OffMeshConnection_SetMask},
{"OffMeshConnection_SetAreaID", OffMeshConnection_SetAreaID},
{"OffMeshConnection_GetEndPoint", OffMeshConnection_GetEndPoint},
{"OffMeshConnection_GetRadius", OffMeshConnection_GetRadius},
{"OffMeshConnection_IsBidirectional", OffMeshConnection_IsBidirectional},
{"OffMeshConnection_GetMask", OffMeshConnection_GetMask},
{"OffMeshConnection_GetAreaID", OffMeshConnection_GetAreaID},
{"Image_GetDataBytes", Image_GetDataBytes},
{"Image_SavePNG2", Image_SavePNG2},
{"Image_GetType", Image_GetType},
{"Image_GetTypeName", Image_GetTypeName},
{"Image_GetTypeStatic", Image_GetTypeStatic},
{"Image_GetTypeNameStatic", Image_GetTypeNameStatic},
{"Image_Image", Image_Image},
{"Image_RegisterObject", Image_RegisterObject},
{"Image_BeginLoad_File", Image_BeginLoad_File},
{"Image_BeginLoad_MemoryBuffer", Image_BeginLoad_MemoryBuffer},
{"Image_Save_File", Image_Save_File},
{"Image_Save_MemoryBuffer", Image_Save_MemoryBuffer},
{"Image_SaveFile", Image_SaveFile},
{"Image_SetSize", Image_SetSize},
{"Image_SetSize0", Image_SetSize0},
{"Image_SetData", Image_SetData},
{"Image_SetData1", Image_SetData1},
{"Image_SetPixel", Image_SetPixel},
{"Image_SetPixel2", Image_SetPixel2},
{"Image_SetPixelInt", Image_SetPixelInt},
{"Image_SetPixelInt3", Image_SetPixelInt3},
{"Image_LoadColorLUT_File", Image_LoadColorLUT_File},
{"Image_LoadColorLUT_MemoryBuffer", Image_LoadColorLUT_MemoryBuffer},
{"Image_FlipHorizontal", Image_FlipHorizontal},
{"Image_FlipVertical", Image_FlipVertical},
{"Image_Resize", Image_Resize},
{"Image_Clear", Image_Clear},
{"Image_ClearInt", Image_ClearInt},
{"Image_SaveBMP", Image_SaveBMP},
{"Image_SavePNG", Image_SavePNG},
{"Image_SaveTGA", Image_SaveTGA},
{"Image_SaveJPG", Image_SaveJPG},
{"Image_SaveDDS", Image_SaveDDS},
{"Image_SaveWEBP", Image_SaveWEBP},
{"Image_IsCubemap", Image_IsCubemap},
{"Image_IsArray", Image_IsArray},
{"Image_IsSRGB", Image_IsSRGB},
{"Image_GetPixel", Image_GetPixel},
{"Image_GetPixel4", Image_GetPixel4},
{"Image_GetPixelInt", Image_GetPixelInt},
{"Image_GetPixelInt5", Image_GetPixelInt5},
{"Image_GetPixelBilinear", Image_GetPixelBilinear},
{"Image_GetPixelTrilinear", Image_GetPixelTrilinear},
{"Image_GetWidth", Image_GetWidth},
{"Image_GetHeight", Image_GetHeight},
{"Image_GetDepth", Image_GetDepth},
{"Image_GetComponents", Image_GetComponents},
{"Image_GetData", Image_GetData},
{"Image_IsCompressed", Image_IsCompressed},
{"Image_GetCompressedFormat", Image_GetCompressedFormat},
{"Image_GetNumCompressedLevels", Image_GetNumCompressedLevels},
{"Image_GetNextLevel", Image_GetNextLevel},
{"Image_GetNextSibling", Image_GetNextSibling},
{"Image_ConvertToRGBA", Image_ConvertToRGBA},
{"Image_GetCompressedLevel", Image_GetCompressedLevel},
{"Image_GetDecompressedImage", Image_GetDecompressedImage},
{"Image_GetSubimage", Image_GetSubimage},
{"Image_PrecalculateLevels", Image_PrecalculateLevels},
{"Image_HasAlphaChannel", Image_HasAlphaChannel},
{"Image_SetSubimage", Image_SetSubimage},
{"Image_CleanupLevels", Image_CleanupLevels},
{"ResourceCache_GetFilesInResourceDirs", ResourceCache_GetFilesInResourceDirs},
{"ResourceCache_GetFromResultFileInResourceDirs", ResourceCache_GetFromResultFileInResourceDirs},
{"ResourceCache_ClearVectorResultFilesInResourceDirs", ResourceCache_ClearVectorResultFilesInResourceDirs},
{"ResourceCache_GetResourceDirsCount", ResourceCache_GetResourceDirsCount},
{"ResourceCache_GetResourceDir", ResourceCache_GetResourceDir},
{"ResourceCache_GetType", ResourceCache_GetType},
{"ResourceCache_GetTypeName", ResourceCache_GetTypeName},
{"ResourceCache_GetTypeStatic", ResourceCache_GetTypeStatic},
{"ResourceCache_GetTypeNameStatic", ResourceCache_GetTypeNameStatic},
{"ResourceCache_ResourceCache", ResourceCache_ResourceCache},
{"ResourceCache_AddResourceDir", ResourceCache_AddResourceDir},
{"ResourceCache_AddPackageFile", ResourceCache_AddPackageFile},
{"ResourceCache_AddPackageFile0", ResourceCache_AddPackageFile0},
{"ResourceCache_AddManualResource", ResourceCache_AddManualResource},
{"ResourceCache_RemoveResourceDir", ResourceCache_RemoveResourceDir},
{"ResourceCache_RemovePackageFile", ResourceCache_RemovePackageFile},
{"ResourceCache_RemovePackageFile1", ResourceCache_RemovePackageFile1},
{"ResourceCache_ReleaseResource", ResourceCache_ReleaseResource},
{"ResourceCache_ReleaseResources", ResourceCache_ReleaseResources},
{"ResourceCache_ReleaseResources2", ResourceCache_ReleaseResources2},
{"ResourceCache_ReleaseResources3", ResourceCache_ReleaseResources3},
{"ResourceCache_ReleaseAllResources", ResourceCache_ReleaseAllResources},
{"ResourceCache_ReloadResource", ResourceCache_ReloadResource},
{"ResourceCache_ReloadResourceWithDependencies", ResourceCache_ReloadResourceWithDependencies},
{"ResourceCache_SetMemoryBudget", ResourceCache_SetMemoryBudget},
{"ResourceCache_SetAutoReloadResources", ResourceCache_SetAutoReloadResources},
{"ResourceCache_SetReturnFailedResources", ResourceCache_SetReturnFailedResources},
{"ResourceCache_SetSearchPackagesFirst", ResourceCache_SetSearchPackagesFirst},
{"ResourceCache_SetFinishBackgroundResourcesMs", ResourceCache_SetFinishBackgroundResourcesMs},
{"ResourceCache_AddResourceRouter", ResourceCache_AddResourceRouter},
{"ResourceCache_RemoveResourceRouter", ResourceCache_RemoveResourceRouter},
{"ResourceCache_GetFile", ResourceCache_GetFile},
{"ResourceCache_GetResource", ResourceCache_GetResource},
{"ResourceCache_GetTempResource", ResourceCache_GetTempResource},
{"ResourceCache_BackgroundLoadResource", ResourceCache_BackgroundLoadResource},
{"ResourceCache_GetNumBackgroundLoadResources", ResourceCache_GetNumBackgroundLoadResources},
{"ResourceCache_GetExistingResource", ResourceCache_GetExistingResource},
{"ResourceCache_GetPackageFiles", ResourceCache_GetPackageFiles},
{"ResourceCache_Exists", ResourceCache_Exists},
{"ResourceCache_GetMemoryBudget", ResourceCache_GetMemoryBudget},
{"ResourceCache_GetMemoryUse", ResourceCache_GetMemoryUse},
{"ResourceCache_GetTotalMemoryUse", ResourceCache_GetTotalMemoryUse},
{"ResourceCache_GetResourceFileName", ResourceCache_GetResourceFileName},
{"ResourceCache_GetAutoReloadResources", ResourceCache_GetAutoReloadResources},
{"ResourceCache_GetReturnFailedResources", ResourceCache_GetReturnFailedResources},
{"ResourceCache_GetSearchPackagesFirst", ResourceCache_GetSearchPackagesFirst},
{"ResourceCache_GetFinishBackgroundResourcesMs", ResourceCache_GetFinishBackgroundResourcesMs},
{"ResourceCache_GetResourceRouter", ResourceCache_GetResourceRouter},
{"ResourceCache_GetPreferredResourceDir", ResourceCache_GetPreferredResourceDir},
{"ResourceCache_SanitateResourceName", ResourceCache_SanitateResourceName},
{"ResourceCache_SanitateResourceDirName", ResourceCache_SanitateResourceDirName},
{"ResourceCache_StoreResourceDependency", ResourceCache_StoreResourceDependency},
{"ResourceCache_ResetDependencies", ResourceCache_ResetDependencies},
{"ResourceCache_PrintMemoryUsage", ResourceCache_PrintMemoryUsage},
{"XmlElement_XMLElement", XmlElement_XMLElement},
{"XmlElement_XMLElement0", XmlElement_XMLElement0},
{"XmlElement_CreateChild", XmlElement_CreateChild},
{"XmlElement_GetOrCreateChild", XmlElement_GetOrCreateChild},
{"XmlElement_AppendChild", XmlElement_AppendChild},
{"XmlElement_Remove", XmlElement_Remove},
{"XmlElement_RemoveChild", XmlElement_RemoveChild},
{"XmlElement_RemoveChild1", XmlElement_RemoveChild1},
{"XmlElement_RemoveChildren", XmlElement_RemoveChildren},
{"XmlElement_RemoveAttribute", XmlElement_RemoveAttribute},
{"XmlElement_SetValue", XmlElement_SetValue},
{"XmlElement_SetAttribute", XmlElement_SetAttribute},
{"XmlElement_SetAttribute2", XmlElement_SetAttribute2},
{"XmlElement_SetBool", XmlElement_SetBool},
{"XmlElement_SetBoundingBox", XmlElement_SetBoundingBox},
{"XmlElement_SetBoundingBox3", XmlElement_SetBoundingBox3},
{"XmlElement_SetBuffer", XmlElement_SetBuffer},
{"XmlElement_SetColor", XmlElement_SetColor},
{"XmlElement_SetFloat", XmlElement_SetFloat},
{"XmlElement_SetDouble", XmlElement_SetDouble},
{"XmlElement_SetUInt", XmlElement_SetUInt},
{"XmlElement_SetInt", XmlElement_SetInt},
{"XmlElement_SetUInt64", XmlElement_SetUInt64},
{"XmlElement_SetInt64", XmlElement_SetInt64},
{"XmlElement_SetIntRect", XmlElement_SetIntRect},
{"XmlElement_SetIntVector2", XmlElement_SetIntVector2},
{"XmlElement_SetQuaternion", XmlElement_SetQuaternion},
{"XmlElement_SetString", XmlElement_SetString},
{"XmlElement_SetVariant_0", XmlElement_SetVariant_0},
{"XmlElement_SetVariant_1", XmlElement_SetVariant_1},
{"XmlElement_SetVariant_2", XmlElement_SetVariant_2},
{"XmlElement_SetVariant_3", XmlElement_SetVariant_3},
{"XmlElement_SetVariant_4", XmlElement_SetVariant_4},
{"XmlElement_SetVariant_5", XmlElement_SetVariant_5},
{"XmlElement_SetVariant_6", XmlElement_SetVariant_6},
{"XmlElement_SetVariant_7", XmlElement_SetVariant_7},
{"XmlElement_SetVariant_8", XmlElement_SetVariant_8},
{"XmlElement_SetVariant_9", XmlElement_SetVariant_9},
{"XmlElement_SetVariant_10", XmlElement_SetVariant_10},
{"XmlElement_SetVariant_11", XmlElement_SetVariant_11},
{"XmlElement_SetVariant_12", XmlElement_SetVariant_12},
{"XmlElement_SetVariant_13", XmlElement_SetVariant_13},
{"XmlElement_SetVariant_14", XmlElement_SetVariant_14},
{"XmlElement_SetVariantValue_0", XmlElement_SetVariantValue_0},
{"XmlElement_SetVariantValue_1", XmlElement_SetVariantValue_1},
{"XmlElement_SetVariantValue_2", XmlElement_SetVariantValue_2},
{"XmlElement_SetVariantValue_3", XmlElement_SetVariantValue_3},
{"XmlElement_SetVariantValue_4", XmlElement_SetVariantValue_4},
{"XmlElement_SetVariantValue_5", XmlElement_SetVariantValue_5},
{"XmlElement_SetVariantValue_6", XmlElement_SetVariantValue_6},
{"XmlElement_SetVariantValue_7", XmlElement_SetVariantValue_7},
{"XmlElement_SetVariantValue_8", XmlElement_SetVariantValue_8},
{"XmlElement_SetVariantValue_9", XmlElement_SetVariantValue_9},
{"XmlElement_SetVariantValue_10", XmlElement_SetVariantValue_10},
{"XmlElement_SetVariantValue_11", XmlElement_SetVariantValue_11},
{"XmlElement_SetVariantValue_12", XmlElement_SetVariantValue_12},
{"XmlElement_SetVariantValue_13", XmlElement_SetVariantValue_13},
{"XmlElement_SetVariantValue_14", XmlElement_SetVariantValue_14},
{"XmlElement_SetVector2", XmlElement_SetVector2},
{"XmlElement_SetVector3", XmlElement_SetVector3},
{"XmlElement_SetVector4", XmlElement_SetVector4},
{"XmlElement_SetVectorVariant_0", XmlElement_SetVectorVariant_0},
{"XmlElement_SetVectorVariant_1", XmlElement_SetVectorVariant_1},
{"XmlElement_SetVectorVariant_2", XmlElement_SetVectorVariant_2},
{"XmlElement_SetVectorVariant_3", XmlElement_SetVectorVariant_3},
{"XmlElement_SetVectorVariant_4", XmlElement_SetVectorVariant_4},
{"XmlElement_SetVectorVariant_5", XmlElement_SetVectorVariant_5},
{"XmlElement_SetVectorVariant_6", XmlElement_SetVectorVariant_6},
{"XmlElement_SetVectorVariant_7", XmlElement_SetVectorVariant_7},
{"XmlElement_SetVectorVariant_8", XmlElement_SetVectorVariant_8},
{"XmlElement_SetVectorVariant_9", XmlElement_SetVectorVariant_9},
{"XmlElement_SetVectorVariant_10", XmlElement_SetVectorVariant_10},
{"XmlElement_SetVectorVariant_11", XmlElement_SetVectorVariant_11},
{"XmlElement_SetVectorVariant_12", XmlElement_SetVectorVariant_12},
{"XmlElement_SetVectorVariant_13", XmlElement_SetVectorVariant_13},
{"XmlElement_SetVectorVariant_14", XmlElement_SetVectorVariant_14},
{"XmlElement_SetMatrix3", XmlElement_SetMatrix3},
{"XmlElement_SetMatrix3x4", XmlElement_SetMatrix3x4},
{"XmlElement_SetMatrix4", XmlElement_SetMatrix4},
{"XmlElement_IsNull", XmlElement_IsNull},
{"XmlElement_NotNull", XmlElement_NotNull},
{"XmlElement_GetName", XmlElement_GetName},
{"XmlElement_HasChild", XmlElement_HasChild},
{"XmlElement_GetChild", XmlElement_GetChild},
{"XmlElement_GetNext", XmlElement_GetNext},
{"XmlElement_GetParent", XmlElement_GetParent},
{"XmlElement_GetNumAttributes", XmlElement_GetNumAttributes},
{"XmlElement_HasAttribute", XmlElement_HasAttribute},
{"XmlElement_GetValue", XmlElement_GetValue},
{"XmlElement_GetAttribute", XmlElement_GetAttribute},
{"XmlElement_GetAttributeLower", XmlElement_GetAttributeLower},
{"XmlElement_GetAttributeUpper", XmlElement_GetAttributeUpper},
{"XmlElement_GetBool", XmlElement_GetBool},
{"XmlElement_GetBuffer", XmlElement_GetBuffer},
{"XmlElement_GetBoundingBox", XmlElement_GetBoundingBox},
{"XmlElement_GetBoundingBox4", XmlElement_GetBoundingBox4},
{"XmlElement_GetColor", XmlElement_GetColor},
{"XmlElement_GetFloat", XmlElement_GetFloat},
{"XmlElement_GetDouble", XmlElement_GetDouble},
{"XmlElement_GetUInt", XmlElement_GetUInt},
{"XmlElement_GetInt", XmlElement_GetInt},
{"XmlElement_GetUInt64", XmlElement_GetUInt64},
{"XmlElement_GetInt64", XmlElement_GetInt64},
{"XmlElement_GetIntRect", XmlElement_GetIntRect},
{"XmlElement_GetIntVector2", XmlElement_GetIntVector2},
{"XmlElement_GetIntVector3", XmlElement_GetIntVector3},
{"XmlElement_GetRect", XmlElement_GetRect},
{"XmlElement_GetQuaternion", XmlElement_GetQuaternion},
{"XmlElement_GetVariant", XmlElement_GetVariant},
{"XmlElement_GetVariantValue", XmlElement_GetVariantValue},
{"XmlElement_GetResourceRef", XmlElement_GetResourceRef},
{"XmlElement_GetResourceRefList", XmlElement_GetResourceRefList},
{"XmlElement_GetVector2", XmlElement_GetVector2},
{"XmlElement_GetVector3", XmlElement_GetVector3},
{"XmlElement_GetVector4", XmlElement_GetVector4},
{"XmlElement_GetVector", XmlElement_GetVector},
{"XmlElement_GetVectorVariant", XmlElement_GetVectorVariant},
{"XmlElement_GetMatrix3", XmlElement_GetMatrix3},
{"XmlElement_GetMatrix3x4", XmlElement_GetMatrix3x4},
{"XmlElement_GetMatrix4", XmlElement_GetMatrix4},
{"XmlElement_GetFile", XmlElement_GetFile},
{"XmlElement_GetXPathResultSet", XmlElement_GetXPathResultSet},
{"XmlElement_GetXPathResultIndex", XmlElement_GetXPathResultIndex},
{"XmlElement_NextResult", XmlElement_NextResult},
{"JsonFile_GetType", JsonFile_GetType},
{"JsonFile_GetTypeName", JsonFile_GetTypeName},
{"JsonFile_GetTypeStatic", JsonFile_GetTypeStatic},
{"JsonFile_GetTypeNameStatic", JsonFile_GetTypeNameStatic},
{"JsonFile_JSONFile", JsonFile_JSONFile},
{"JsonFile_RegisterObject", JsonFile_RegisterObject},
{"JsonFile_BeginLoad_File", JsonFile_BeginLoad_File},
{"JsonFile_BeginLoad_MemoryBuffer", JsonFile_BeginLoad_MemoryBuffer},
{"JsonFile_Save_File", JsonFile_Save_File},
{"JsonFile_Save_MemoryBuffer", JsonFile_Save_MemoryBuffer},
{"JsonFile_Save0_File", JsonFile_Save0_File},
{"JsonFile_Save0_MemoryBuffer", JsonFile_Save0_MemoryBuffer},
{"JsonFile_FromString", JsonFile_FromString},
{"JsonFile_ToString", JsonFile_ToString},
{"JsonFile_GetString", JsonFile_GetString},
{"JsonFile_GetInt", JsonFile_GetInt},
{"JsonFile_GetUInt", JsonFile_GetUInt},
{"JsonFile_GetFloat", JsonFile_GetFloat},
{"JsonFile_GetDouble", JsonFile_GetDouble},
{"JsonFile_GetBool", JsonFile_GetBool},
{"JsonFile_SetString", JsonFile_SetString},
{"JsonFile_SetInt", JsonFile_SetInt},
{"JsonFile_SetUInt", JsonFile_SetUInt},
{"JsonFile_SetFloat", JsonFile_SetFloat},
{"JsonFile_SetDouble", JsonFile_SetDouble},
{"JsonFile_SetBool", JsonFile_SetBool},
{"Localization_GetType", Localization_GetType},
{"Localization_GetTypeName", Localization_GetTypeName},
{"Localization_GetTypeStatic", Localization_GetTypeStatic},
{"Localization_GetTypeNameStatic", Localization_GetTypeNameStatic},
{"Localization_Localization", Localization_Localization},
{"Localization_GetNumLanguages", Localization_GetNumLanguages},
{"Localization_GetLanguageIndex", Localization_GetLanguageIndex},
{"Localization_GetLanguageIndex0", Localization_GetLanguageIndex0},
{"Localization_GetLanguage", Localization_GetLanguage},
{"Localization_GetLanguage1", Localization_GetLanguage1},
{"Localization_SetLanguage", Localization_SetLanguage},
{"Localization_SetLanguage2", Localization_SetLanguage2},
{"Localization_Get", Localization_Get},
{"Localization_Reset", Localization_Reset},
{"Localization_LoadJSONFile", Localization_LoadJSONFile},
{"Resource_GetType", Resource_GetType},
{"Resource_GetTypeName", Resource_GetTypeName},
{"Resource_GetTypeStatic", Resource_GetTypeStatic},
{"Resource_GetTypeNameStatic", Resource_GetTypeNameStatic},
{"Resource_Resource", Resource_Resource},
{"Resource_Load_File", Resource_Load_File},
{"Resource_Load_MemoryBuffer", Resource_Load_MemoryBuffer},
{"Resource_BeginLoad_File", Resource_BeginLoad_File},
{"Resource_BeginLoad_MemoryBuffer", Resource_BeginLoad_MemoryBuffer},
{"Resource_EndLoad", Resource_EndLoad},
{"Resource_Save_File", Resource_Save_File},
{"Resource_Save_MemoryBuffer", Resource_Save_MemoryBuffer},
{"Resource_LoadFile", Resource_LoadFile},
{"Resource_SaveFile", Resource_SaveFile},
{"Resource_SetName", Resource_SetName},
{"Resource_SetMemoryUse", Resource_SetMemoryUse},
{"Resource_ResetUseTimer", Resource_ResetUseTimer},
{"Resource_SetAsyncLoadState", Resource_SetAsyncLoadState},
{"Resource_GetName", Resource_GetName},
{"Resource_GetNameHash", Resource_GetNameHash},
{"Resource_GetMemoryUse", Resource_GetMemoryUse},
{"Resource_GetUseTimer", Resource_GetUseTimer},
{"Resource_GetAsyncLoadState", Resource_GetAsyncLoadState},
{"PListFile_GetType", PListFile_GetType},
{"PListFile_GetTypeName", PListFile_GetTypeName},
{"PListFile_GetTypeStatic", PListFile_GetTypeStatic},
{"PListFile_GetTypeNameStatic", PListFile_GetTypeNameStatic},
{"PListFile_PListFile", PListFile_PListFile},
{"PListFile_RegisterObject", PListFile_RegisterObject},
{"PListFile_BeginLoad_File", PListFile_BeginLoad_File},
{"PListFile_BeginLoad_MemoryBuffer", PListFile_BeginLoad_MemoryBuffer},
{"XmlFile_GetType", XmlFile_GetType},
{"XmlFile_GetTypeName", XmlFile_GetTypeName},
{"XmlFile_GetTypeStatic", XmlFile_GetTypeStatic},
{"XmlFile_GetTypeNameStatic", XmlFile_GetTypeNameStatic},
{"XmlFile_XMLFile", XmlFile_XMLFile},
{"XmlFile_RegisterObject", XmlFile_RegisterObject},
{"XmlFile_BeginLoad_File", XmlFile_BeginLoad_File},
{"XmlFile_BeginLoad_MemoryBuffer", XmlFile_BeginLoad_MemoryBuffer},
{"XmlFile_Save_File", XmlFile_Save_File},
{"XmlFile_Save_MemoryBuffer", XmlFile_Save_MemoryBuffer},
{"XmlFile_Save0_File", XmlFile_Save0_File},
{"XmlFile_Save0_MemoryBuffer", XmlFile_Save0_MemoryBuffer},
{"XmlFile_FromString", XmlFile_FromString},
{"XmlFile_CreateRoot", XmlFile_CreateRoot},
{"XmlFile_GetOrCreateRoot", XmlFile_GetOrCreateRoot},
{"XmlFile_GetRoot", XmlFile_GetRoot},
{"XmlFile_ToString", XmlFile_ToString},
{"XmlFile_Patch", XmlFile_Patch},
{"XmlFile_Patch1", XmlFile_Patch1},
{"FileSelector_SetFilters", FileSelector_SetFilters},
{"FileSelector_GetType", FileSelector_GetType},
{"FileSelector_GetTypeName", FileSelector_GetTypeName},
{"FileSelector_GetTypeStatic", FileSelector_GetTypeStatic},
{"FileSelector_GetTypeNameStatic", FileSelector_GetTypeNameStatic},
{"FileSelector_FileSelector", FileSelector_FileSelector},
{"FileSelector_RegisterObject", FileSelector_RegisterObject},
{"FileSelector_SetDefaultStyle", FileSelector_SetDefaultStyle},
{"FileSelector_SetTitle", FileSelector_SetTitle},
{"FileSelector_SetButtonTexts", FileSelector_SetButtonTexts},
{"FileSelector_SetPath", FileSelector_SetPath},
{"FileSelector_SetFileName", FileSelector_SetFileName},
{"FileSelector_SetDirectoryMode", FileSelector_SetDirectoryMode},
{"FileSelector_UpdateElements", FileSelector_UpdateElements},
{"FileSelector_GetDefaultStyle", FileSelector_GetDefaultStyle},
{"FileSelector_GetWindow", FileSelector_GetWindow},
{"FileSelector_GetTitleText", FileSelector_GetTitleText},
{"FileSelector_GetFileList", FileSelector_GetFileList},
{"FileSelector_GetPathEdit", FileSelector_GetPathEdit},
{"FileSelector_GetFileNameEdit", FileSelector_GetFileNameEdit},
{"FileSelector_GetFilterList", FileSelector_GetFilterList},
{"FileSelector_GetOKButton", FileSelector_GetOKButton},
{"FileSelector_GetCancelButton", FileSelector_GetCancelButton},
{"FileSelector_GetCloseButton", FileSelector_GetCloseButton},
{"FileSelector_GetTitle", FileSelector_GetTitle},
{"FileSelector_GetPath", FileSelector_GetPath},
{"FileSelector_GetFileName", FileSelector_GetFileName},
{"FileSelector_GetFilter", FileSelector_GetFilter},
{"FileSelector_GetFilterIndex", FileSelector_GetFilterIndex},
{"FileSelector_GetDirectoryMode", FileSelector_GetDirectoryMode},
{"ListView_GetSelections", ListView_GetSelections},
{"ListView_SetSelections", ListView_SetSelections},
{"ListView_GetType", ListView_GetType},
{"ListView_GetTypeName", ListView_GetTypeName},
{"ListView_GetTypeStatic", ListView_GetTypeStatic},
{"ListView_GetTypeNameStatic", ListView_GetTypeNameStatic},
{"ListView_ListView", ListView_ListView},
{"ListView_RegisterObject", ListView_RegisterObject},
{"ListView_OnResize", ListView_OnResize},
{"ListView_UpdateInternalLayout", ListView_UpdateInternalLayout},
{"ListView_DisableInternalLayoutUpdate", ListView_DisableInternalLayoutUpdate},
{"ListView_EnableInternalLayoutUpdate", ListView_EnableInternalLayoutUpdate},
{"ListView_AddItem", ListView_AddItem},
{"ListView_InsertItem", ListView_InsertItem},
{"ListView_RemoveItem", ListView_RemoveItem},
{"ListView_RemoveItem0", ListView_RemoveItem0},
{"ListView_RemoveAllItems", ListView_RemoveAllItems},
{"ListView_SetSelection", ListView_SetSelection},
{"ListView_AddSelection", ListView_AddSelection},
{"ListView_RemoveSelection", ListView_RemoveSelection},
{"ListView_ToggleSelection", ListView_ToggleSelection},
{"ListView_ChangeSelection", ListView_ChangeSelection},
{"ListView_ClearSelection", ListView_ClearSelection},
{"ListView_SetHighlightMode", ListView_SetHighlightMode},
{"ListView_SetMultiselect", ListView_SetMultiselect},
{"ListView_SetHierarchyMode", ListView_SetHierarchyMode},
{"ListView_SetBaseIndent", ListView_SetBaseIndent},
{"ListView_SetClearSelectionOnDefocus", ListView_SetClearSelectionOnDefocus},
{"ListView_SetSelectOnClickEnd", ListView_SetSelectOnClickEnd},
{"ListView_Expand", ListView_Expand},
{"ListView_ToggleExpand", ListView_ToggleExpand},
{"ListView_GetNumItems", ListView_GetNumItems},
{"ListView_GetItem", ListView_GetItem},
{"ListView_FindItem", ListView_FindItem},
{"ListView_GetSelection", ListView_GetSelection},
{"ListView_CopySelectedItemsToClipboard", ListView_CopySelectedItemsToClipboard},
{"ListView_GetSelectedItem", ListView_GetSelectedItem},
{"ListView_IsSelected", ListView_IsSelected},
{"ListView_IsExpanded", ListView_IsExpanded},
{"ListView_GetHighlightMode", ListView_GetHighlightMode},
{"ListView_GetMultiselect", ListView_GetMultiselect},
{"ListView_GetClearSelectionOnDefocus", ListView_GetClearSelectionOnDefocus},
{"ListView_GetSelectOnClickEnd", ListView_GetSelectOnClickEnd},
{"ListView_GetHierarchyMode", ListView_GetHierarchyMode},
{"ListView_GetBaseIndent", ListView_GetBaseIndent},
{"ListView_EnsureItemVisibility", ListView_EnsureItemVisibility},
{"ListView_EnsureItemVisibility1", ListView_EnsureItemVisibility1},
{"ListView_GetEnsureItemVisibilityOnFcousChanged", ListView_GetEnsureItemVisibilityOnFcousChanged},
{"ListView_SetEnsureItemVisibilityOnFcousChanged", ListView_SetEnsureItemVisibilityOnFcousChanged},
{"UI_LoadLayoutToElement", UI_LoadLayoutToElement},
{"UI_GetType", UI_GetType},
{"UI_GetTypeName", UI_GetTypeName},
{"UI_GetTypeStatic", UI_GetTypeStatic},
{"UI_GetTypeNameStatic", UI_GetTypeNameStatic},
{"UI_UI", UI_UI},
{"UI_SetCursor", UI_SetCursor},
{"UI_SetFocusElement", UI_SetFocusElement},
{"UI_SetModalElement", UI_SetModalElement},
{"UI_Clear", UI_Clear},
{"UI_Update", UI_Update},
{"UI_RenderUpdate", UI_RenderUpdate},
{"UI_Render", UI_Render},
{"UI_DebugDraw", UI_DebugDraw},
{"UI_LoadLayout_File", UI_LoadLayout_File},
{"UI_LoadLayout_MemoryBuffer", UI_LoadLayout_MemoryBuffer},
{"UI_LoadLayout0", UI_LoadLayout0},
{"UI_SaveLayout_File", UI_SaveLayout_File},
{"UI_SaveLayout_MemoryBuffer", UI_SaveLayout_MemoryBuffer},
{"UI_SetClipboardText", UI_SetClipboardText},
{"UI_SetDoubleClickInterval", UI_SetDoubleClickInterval},
{"UI_SetMaxDoubleClickDistance", UI_SetMaxDoubleClickDistance},
{"UI_SetDragBeginInterval", UI_SetDragBeginInterval},
{"UI_SetDragBeginDistance", UI_SetDragBeginDistance},
{"UI_SetDefaultToolTipDelay", UI_SetDefaultToolTipDelay},
{"UI_SetMaxFontTextureSize", UI_SetMaxFontTextureSize},
{"UI_SetNonFocusedMouseWheel", UI_SetNonFocusedMouseWheel},
{"UI_SetUseSystemClipboard", UI_SetUseSystemClipboard},
{"UI_SetUseScreenKeyboard", UI_SetUseScreenKeyboard},
{"UI_SetUseMutableGlyphs", UI_SetUseMutableGlyphs},
{"UI_SetForceAutoHint", UI_SetForceAutoHint},
{"UI_SetFontHintLevel", UI_SetFontHintLevel},
{"UI_SetFontSubpixelThreshold", UI_SetFontSubpixelThreshold},
{"UI_SetFontOversampling", UI_SetFontOversampling},
{"UI_SetScale", UI_SetScale},
{"UI_SetWidth", UI_SetWidth},
{"UI_SetHeight", UI_SetHeight},
{"UI_SetCustomSize", UI_SetCustomSize},
{"UI_SetCustomSize1", UI_SetCustomSize1},
{"UI_GetRoot", UI_GetRoot},
{"UI_GetRootModalElement", UI_GetRootModalElement},
{"UI_GetCursor", UI_GetCursor},
{"UI_GetCursorPosition", UI_GetCursorPosition},
{"UI_GetElementAt", UI_GetElementAt},
{"UI_GetElementAt2", UI_GetElementAt2},
{"UI_GetElementAt3", UI_GetElementAt3},
{"UI_ConvertSystemToUI", UI_ConvertSystemToUI},
{"UI_ConvertUIToSystem", UI_ConvertUIToSystem},
{"UI_GetFocusElement", UI_GetFocusElement},
{"UI_GetFrontElement", UI_GetFrontElement},
{"UI_GetNumDragElements", UI_GetNumDragElements},
{"UI_GetDragElement", UI_GetDragElement},
{"UI_GetClipboardText", UI_GetClipboardText},
{"UI_GetDoubleClickInterval", UI_GetDoubleClickInterval},
{"UI_GetMaxDoubleClickDistance", UI_GetMaxDoubleClickDistance},
{"UI_GetDragBeginInterval", UI_GetDragBeginInterval},
{"UI_GetDragBeginDistance", UI_GetDragBeginDistance},
{"UI_GetDefaultToolTipDelay", UI_GetDefaultToolTipDelay},
{"UI_GetMaxFontTextureSize", UI_GetMaxFontTextureSize},
{"UI_IsNonFocusedMouseWheel", UI_IsNonFocusedMouseWheel},
{"UI_GetUseSystemClipboard", UI_GetUseSystemClipboard},
{"UI_GetUseScreenKeyboard", UI_GetUseScreenKeyboard},
{"UI_GetUseMutableGlyphs", UI_GetUseMutableGlyphs},
{"UI_GetForceAutoHint", UI_GetForceAutoHint},
{"UI_GetFontHintLevel", UI_GetFontHintLevel},
{"UI_GetFontSubpixelThreshold", UI_GetFontSubpixelThreshold},
{"UI_GetFontOversampling", UI_GetFontOversampling},
{"UI_HasModalElement", UI_HasModalElement},
{"UI_IsDragging", UI_IsDragging},
{"UI_GetScale", UI_GetScale},
{"UI_GetCustomSize", UI_GetCustomSize},
{"UI_SetElementRenderTexture", UI_SetElementRenderTexture},
{"UIElement_SetVar_IntPtr", UIElement_SetVar_IntPtr},
{"UIElement_GetTags", UIElement_GetTags},
{"UIElement_GetVars", UIElement_GetVars},
{"UIElement_GetType", UIElement_GetType},
{"UIElement_GetTypeName", UIElement_GetTypeName},
{"UIElement_GetTypeStatic", UIElement_GetTypeStatic},
{"UIElement_GetTypeNameStatic", UIElement_GetTypeNameStatic},
{"UIElement_UIElement", UIElement_UIElement},
{"UIElement_RegisterObject", UIElement_RegisterObject},
{"UIElement_ApplyAttributes", UIElement_ApplyAttributes},
{"UIElement_LoadXML", UIElement_LoadXML},
{"UIElement_LoadXML0", UIElement_LoadXML0},
{"UIElement_LoadChildXML", UIElement_LoadChildXML},
{"UIElement_SaveXML", UIElement_SaveXML},
{"UIElement_Update", UIElement_Update},
{"UIElement_IsWithinScissor", UIElement_IsWithinScissor},
{"UIElement_GetScreenPosition", UIElement_GetScreenPosition},
{"UIElement_OnTextInput", UIElement_OnTextInput},
{"UIElement_OnResize", UIElement_OnResize},
{"UIElement_OnPositionSet", UIElement_OnPositionSet},
{"UIElement_OnSetEditable", UIElement_OnSetEditable},
{"UIElement_OnIndentSet", UIElement_OnIndentSet},
{"UIElement_ScreenToElement", UIElement_ScreenToElement},
{"UIElement_ElementToScreen", UIElement_ElementToScreen},
{"UIElement_IsWheelHandler", UIElement_IsWheelHandler},
{"UIElement_LoadXML1_File", UIElement_LoadXML1_File},
{"UIElement_LoadXML1_MemoryBuffer", UIElement_LoadXML1_MemoryBuffer},
{"UIElement_SaveXML2_File", UIElement_SaveXML2_File},
{"UIElement_SaveXML2_MemoryBuffer", UIElement_SaveXML2_MemoryBuffer},
{"UIElement_FilterAttributes", UIElement_FilterAttributes},
{"UIElement_SetName", UIElement_SetName},
{"UIElement_SetPosition", UIElement_SetPosition},
{"UIElement_SetPosition3", UIElement_SetPosition3},
{"UIElement_SetSize", UIElement_SetSize},
{"UIElement_SetSize4", UIElement_SetSize4},
{"UIElement_SetWidth", UIElement_SetWidth},
{"UIElement_SetHeight", UIElement_SetHeight},
{"UIElement_SetMinSize", UIElement_SetMinSize},
{"UIElement_SetMinSize5", UIElement_SetMinSize5},
{"UIElement_SetMinWidth", UIElement_SetMinWidth},
{"UIElement_SetMinHeight", UIElement_SetMinHeight},
{"UIElement_SetMaxSize", UIElement_SetMaxSize},
{"UIElement_SetMaxSize6", UIElement_SetMaxSize6},
{"UIElement_SetMaxWidth", UIElement_SetMaxWidth},
{"UIElement_SetMaxHeight", UIElement_SetMaxHeight},
{"UIElement_SetFixedSize", UIElement_SetFixedSize},
{"UIElement_SetFixedSize7", UIElement_SetFixedSize7},
{"UIElement_SetFixedWidth", UIElement_SetFixedWidth},
{"UIElement_SetFixedHeight", UIElement_SetFixedHeight},
{"UIElement_SetAlignment", UIElement_SetAlignment},
{"UIElement_SetHorizontalAlignment", UIElement_SetHorizontalAlignment},
{"UIElement_SetVerticalAlignment", UIElement_SetVerticalAlignment},
{"UIElement_SetEnableAnchor", UIElement_SetEnableAnchor},
{"UIElement_SetMinAnchor", UIElement_SetMinAnchor},
{"UIElement_SetMinAnchor8", UIElement_SetMinAnchor8},
{"UIElement_SetMaxAnchor", UIElement_SetMaxAnchor},
{"UIElement_SetMaxAnchor9", UIElement_SetMaxAnchor9},
{"UIElement_SetMinOffset", UIElement_SetMinOffset},
{"UIElement_SetMaxOffset", UIElement_SetMaxOffset},
{"UIElement_SetPivot", UIElement_SetPivot},
{"UIElement_SetPivot10", UIElement_SetPivot10},
{"UIElement_SetClipBorder", UIElement_SetClipBorder},
{"UIElement_SetColor", UIElement_SetColor},
{"UIElement_SetColor11", UIElement_SetColor11},
{"UIElement_SetPriority", UIElement_SetPriority},
{"UIElement_SetOpacity", UIElement_SetOpacity},
{"UIElement_SetBringToFront", UIElement_SetBringToFront},
{"UIElement_SetBringToBack", UIElement_SetBringToBack},
{"UIElement_SetClipChildren", UIElement_SetClipChildren},
{"UIElement_SetSortChildren", UIElement_SetSortChildren},
{"UIElement_SetUseDerivedOpacity", UIElement_SetUseDerivedOpacity},
{"UIElement_SetEnabled", UIElement_SetEnabled},
{"UIElement_SetDeepEnabled", UIElement_SetDeepEnabled},
{"UIElement_ResetDeepEnabled", UIElement_ResetDeepEnabled},
{"UIElement_SetEnabledRecursive", UIElement_SetEnabledRecursive},
{"UIElement_SetEditable", UIElement_SetEditable},
{"UIElement_SetFocus", UIElement_SetFocus},
{"UIElement_SetSelected", UIElement_SetSelected},
{"UIElement_SetVisible", UIElement_SetVisible},
{"UIElement_SetFocusMode", UIElement_SetFocusMode},
{"UIElement_SetDragDropMode", UIElement_SetDragDropMode},
{"UIElement_SetStyle", UIElement_SetStyle},
{"UIElement_SetStyle12", UIElement_SetStyle12},
{"UIElement_SetStyleAuto", UIElement_SetStyleAuto},
{"UIElement_SetDefaultStyle", UIElement_SetDefaultStyle},
{"UIElement_SetLayout", UIElement_SetLayout},
{"UIElement_SetLayoutMode", UIElement_SetLayoutMode},
{"UIElement_SetLayoutSpacing", UIElement_SetLayoutSpacing},
{"UIElement_SetLayoutBorder", UIElement_SetLayoutBorder},
{"UIElement_SetLayoutFlexScale", UIElement_SetLayoutFlexScale},
{"UIElement_SetIndent", UIElement_SetIndent},
{"UIElement_SetIndentSpacing", UIElement_SetIndentSpacing},
{"UIElement_UpdateLayout", UIElement_UpdateLayout},
{"UIElement_DisableLayoutUpdate", UIElement_DisableLayoutUpdate},
{"UIElement_EnableLayoutUpdate", UIElement_EnableLayoutUpdate},
{"UIElement_BringToFront", UIElement_BringToFront},
{"UIElement_CreateChild", UIElement_CreateChild},
{"UIElement_AddChild", UIElement_AddChild},
{"UIElement_InsertChild", UIElement_InsertChild},
{"UIElement_RemoveChild", UIElement_RemoveChild},
{"UIElement_RemoveChildAtIndex", UIElement_RemoveChildAtIndex},
{"UIElement_RemoveAllChildren", UIElement_RemoveAllChildren},
{"UIElement_Remove", UIElement_Remove},
{"UIElement_FindChild", UIElement_FindChild},
{"UIElement_SetParent", UIElement_SetParent},
{"UIElement_SetVar_0", UIElement_SetVar_0},
{"UIElement_SetVar_1", UIElement_SetVar_1},
{"UIElement_SetVar_2", UIElement_SetVar_2},
{"UIElement_SetVar_3", UIElement_SetVar_3},
{"UIElement_SetVar_4", UIElement_SetVar_4},
{"UIElement_SetVar_5", UIElement_SetVar_5},
{"UIElement_SetVar_6", UIElement_SetVar_6},
{"UIElement_SetVar_7", UIElement_SetVar_7},
{"UIElement_SetVar_8", UIElement_SetVar_8},
{"UIElement_SetVar_9", UIElement_SetVar_9},
{"UIElement_SetVar_10", UIElement_SetVar_10},
{"UIElement_SetVar_11", UIElement_SetVar_11},
{"UIElement_SetVar_12", UIElement_SetVar_12},
{"UIElement_SetVar_13", UIElement_SetVar_13},
{"UIElement_SetVar_14", UIElement_SetVar_14},
{"UIElement_SetVar13_0", UIElement_SetVar13_0},
{"UIElement_SetVar13_1", UIElement_SetVar13_1},
{"UIElement_SetVar13_2", UIElement_SetVar13_2},
{"UIElement_SetVar13_3", UIElement_SetVar13_3},
{"UIElement_SetVar13_4", UIElement_SetVar13_4},
{"UIElement_SetVar13_5", UIElement_SetVar13_5},
{"UIElement_SetVar13_6", UIElement_SetVar13_6},
{"UIElement_SetVar13_7", UIElement_SetVar13_7},
{"UIElement_SetVar13_8", UIElement_SetVar13_8},
{"UIElement_SetVar13_9", UIElement_SetVar13_9},
{"UIElement_SetVar13_10", UIElement_SetVar13_10},
{"UIElement_SetVar13_11", UIElement_SetVar13_11},
{"UIElement_SetVar13_12", UIElement_SetVar13_12},
{"UIElement_SetVar13_13", UIElement_SetVar13_13},
{"UIElement_SetVar13_14", UIElement_SetVar13_14},
{"UIElement_SetInternal", UIElement_SetInternal},
{"UIElement_SetTraversalMode", UIElement_SetTraversalMode},
{"UIElement_SetElementEventSender", UIElement_SetElementEventSender},
{"UIElement_AddTag", UIElement_AddTag},
{"UIElement_RemoveTag", UIElement_RemoveTag},
{"UIElement_RemoveAllTags", UIElement_RemoveAllTags},
{"UIElement_GetName", UIElement_GetName},
{"UIElement_GetPosition", UIElement_GetPosition},
{"UIElement_GetSize", UIElement_GetSize},
{"UIElement_GetWidth", UIElement_GetWidth},
{"UIElement_GetHeight", UIElement_GetHeight},
{"UIElement_GetMinSize", UIElement_GetMinSize},
{"UIElement_GetMinWidth", UIElement_GetMinWidth},
{"UIElement_GetMinHeight", UIElement_GetMinHeight},
{"UIElement_GetMaxSize", UIElement_GetMaxSize},
{"UIElement_GetMaxWidth", UIElement_GetMaxWidth},
{"UIElement_GetMaxHeight", UIElement_GetMaxHeight},
{"UIElement_IsFixedSize", UIElement_IsFixedSize},
{"UIElement_IsFixedWidth", UIElement_IsFixedWidth},
{"UIElement_IsFixedHeight", UIElement_IsFixedHeight},
{"UIElement_GetChildOffset", UIElement_GetChildOffset},
{"UIElement_GetHorizontalAlignment", UIElement_GetHorizontalAlignment},
{"UIElement_GetVerticalAlignment", UIElement_GetVerticalAlignment},
{"UIElement_GetEnableAnchor", UIElement_GetEnableAnchor},
{"UIElement_GetMinAnchor", UIElement_GetMinAnchor},
{"UIElement_GetMaxAnchor", UIElement_GetMaxAnchor},
{"UIElement_GetMinOffset", UIElement_GetMinOffset},
{"UIElement_GetMaxOffset", UIElement_GetMaxOffset},
{"UIElement_GetPivot", UIElement_GetPivot},
{"UIElement_GetClipBorder", UIElement_GetClipBorder},
{"UIElement_GetColor", UIElement_GetColor},
{"UIElement_GetPriority", UIElement_GetPriority},
{"UIElement_GetOpacity", UIElement_GetOpacity},
{"UIElement_GetDerivedOpacity", UIElement_GetDerivedOpacity},
{"UIElement_GetBringToFront", UIElement_GetBringToFront},
{"UIElement_GetBringToBack", UIElement_GetBringToBack},
{"UIElement_GetClipChildren", UIElement_GetClipChildren},
{"UIElement_GetSortChildren", UIElement_GetSortChildren},
{"UIElement_GetUseDerivedOpacity", UIElement_GetUseDerivedOpacity},
{"UIElement_HasFocus", UIElement_HasFocus},
{"UIElement_IsChildOf", UIElement_IsChildOf},
{"UIElement_IsEnabled", UIElement_IsEnabled},
{"UIElement_IsEnabledSelf", UIElement_IsEnabledSelf},
{"UIElement_IsEditable", UIElement_IsEditable},
{"UIElement_IsSelected", UIElement_IsSelected},
{"UIElement_IsVisible", UIElement_IsVisible},
{"UIElement_IsVisibleEffective", UIElement_IsVisibleEffective},
{"UIElement_IsHovering", UIElement_IsHovering},
{"UIElement_IsInternal", UIElement_IsInternal},
{"UIElement_HasColorGradient", UIElement_HasColorGradient},
{"UIElement_GetFocusMode", UIElement_GetFocusMode},
{"UIElement_GetDragDropMode", UIElement_GetDragDropMode},
{"UIElement_GetAppliedStyle", UIElement_GetAppliedStyle},
{"UIElement_GetDefaultStyle", UIElement_GetDefaultStyle},
{"UIElement_GetLayoutMode", UIElement_GetLayoutMode},
{"UIElement_GetLayoutSpacing", UIElement_GetLayoutSpacing},
{"UIElement_GetLayoutBorder", UIElement_GetLayoutBorder},
{"UIElement_GetLayoutFlexScale", UIElement_GetLayoutFlexScale},
{"UIElement_GetNumChildren", UIElement_GetNumChildren},
{"UIElement_GetChild", UIElement_GetChild},
{"UIElement_GetChild14", UIElement_GetChild14},
{"UIElement_GetChildren", UIElement_GetChildren},
{"UIElement_GetParent", UIElement_GetParent},
{"UIElement_GetRoot", UIElement_GetRoot},
{"UIElement_GetDerivedColor", UIElement_GetDerivedColor},
{"UIElement_GetVar", UIElement_GetVar},
{"UIElement_GetVar15", UIElement_GetVar15},
{"UIElement_HasTag", UIElement_HasTag},
{"UIElement_GetDragButtonCount", UIElement_GetDragButtonCount},
{"UIElement_IsInside", UIElement_IsInside},
{"UIElement_IsInsideCombined", UIElement_IsInsideCombined},
{"UIElement_GetCombinedScreenRect", UIElement_GetCombinedScreenRect},
{"UIElement_SortChildren", UIElement_SortChildren},
{"UIElement_GetLayoutElementMaxSize", UIElement_GetLayoutElementMaxSize},
{"UIElement_GetIndent", UIElement_GetIndent},
{"UIElement_GetIndentSpacing", UIElement_GetIndentSpacing},
{"UIElement_GetIndentWidth", UIElement_GetIndentWidth},
{"UIElement_SetChildOffset", UIElement_SetChildOffset},
{"UIElement_SetHovering", UIElement_SetHovering},
{"UIElement_GetColorAttr", UIElement_GetColorAttr},
{"UIElement_GetTraversalMode", UIElement_GetTraversalMode},
{"UIElement_IsElementEventSender", UIElement_IsElementEventSender},
{"UIElement_GetElementEventSender", UIElement_GetElementEventSender},
{"UIElement_GetEffectiveMinSize", UIElement_GetEffectiveMinSize},
{"UIElement_SetRenderTexture", UIElement_SetRenderTexture},
{"BorderImage_GetType", BorderImage_GetType},
{"BorderImage_GetTypeName", BorderImage_GetTypeName},
{"BorderImage_GetTypeStatic", BorderImage_GetTypeStatic},
{"BorderImage_GetTypeNameStatic", BorderImage_GetTypeNameStatic},
{"BorderImage_BorderImage", BorderImage_BorderImage},
{"BorderImage_RegisterObject", BorderImage_RegisterObject},
{"BorderImage_SetTexture", BorderImage_SetTexture},
{"BorderImage_SetImageRect", BorderImage_SetImageRect},
{"BorderImage_SetFullImageRect", BorderImage_SetFullImageRect},
{"BorderImage_SetBorder", BorderImage_SetBorder},
{"BorderImage_SetImageBorder", BorderImage_SetImageBorder},
{"BorderImage_SetHoverOffset", BorderImage_SetHoverOffset},
{"BorderImage_SetHoverOffset0", BorderImage_SetHoverOffset0},
{"BorderImage_SetDisabledOffset", BorderImage_SetDisabledOffset},
{"BorderImage_SetDisabledOffset1", BorderImage_SetDisabledOffset1},
{"BorderImage_SetBlendMode", BorderImage_SetBlendMode},
{"BorderImage_SetTiled", BorderImage_SetTiled},
{"BorderImage_SetMaterial", BorderImage_SetMaterial},
{"BorderImage_GetTexture", BorderImage_GetTexture},
{"BorderImage_GetImageRect", BorderImage_GetImageRect},
{"BorderImage_GetBorder", BorderImage_GetBorder},
{"BorderImage_GetImageBorder", BorderImage_GetImageBorder},
{"BorderImage_GetHoverOffset", BorderImage_GetHoverOffset},
{"BorderImage_GetDisabledOffset", BorderImage_GetDisabledOffset},
{"BorderImage_GetBlendMode", BorderImage_GetBlendMode},
{"BorderImage_IsTiled", BorderImage_IsTiled},
{"BorderImage_GetMaterial", BorderImage_GetMaterial},
{"BorderImage_GetTextureAttr", BorderImage_GetTextureAttr},
{"BorderImage_GetMaterialAttr", BorderImage_GetMaterialAttr},
{"Button_GetType", Button_GetType},
{"Button_GetTypeName", Button_GetTypeName},
{"Button_GetTypeStatic", Button_GetTypeStatic},
{"Button_GetTypeNameStatic", Button_GetTypeNameStatic},
{"Button_Button", Button_Button},
{"Button_RegisterObject", Button_RegisterObject},
{"Button_Update", Button_Update},
{"Button_SetPressedOffset", Button_SetPressedOffset},
{"Button_SetPressedOffset0", Button_SetPressedOffset0},
{"Button_SetPressedChildOffset", Button_SetPressedChildOffset},
{"Button_SetPressedChildOffset1", Button_SetPressedChildOffset1},
{"Button_SetRepeat", Button_SetRepeat},
{"Button_SetRepeatDelay", Button_SetRepeatDelay},
{"Button_SetRepeatRate", Button_SetRepeatRate},
{"Button_GetPressedOffset", Button_GetPressedOffset},
{"Button_GetPressedChildOffset", Button_GetPressedChildOffset},
{"Button_GetRepeatDelay", Button_GetRepeatDelay},
{"Button_GetRepeatRate", Button_GetRepeatRate},
{"Button_IsPressed", Button_IsPressed},
{"CheckBox_GetType", CheckBox_GetType},
{"CheckBox_GetTypeName", CheckBox_GetTypeName},
{"CheckBox_GetTypeStatic", CheckBox_GetTypeStatic},
{"CheckBox_GetTypeNameStatic", CheckBox_GetTypeNameStatic},
{"CheckBox_CheckBox", CheckBox_CheckBox},
{"CheckBox_RegisterObject", CheckBox_RegisterObject},
{"CheckBox_SetChecked", CheckBox_SetChecked},
{"CheckBox_SetCheckedOffset", CheckBox_SetCheckedOffset},
{"CheckBox_SetCheckedOffset0", CheckBox_SetCheckedOffset0},
{"CheckBox_IsChecked", CheckBox_IsChecked},
{"CheckBox_GetCheckedOffset", CheckBox_GetCheckedOffset},
{"Cursor_GetType", Cursor_GetType},
{"Cursor_GetTypeName", Cursor_GetTypeName},
{"Cursor_GetTypeStatic", Cursor_GetTypeStatic},
{"Cursor_GetTypeNameStatic", Cursor_GetTypeNameStatic},
{"Cursor_Cursor", Cursor_Cursor},
{"Cursor_RegisterObject", Cursor_RegisterObject},
{"Cursor_DefineShape", Cursor_DefineShape},
{"Cursor_DefineShape0", Cursor_DefineShape0},
{"Cursor_SetShape", Cursor_SetShape},
{"Cursor_SetShape1", Cursor_SetShape1},
{"Cursor_SetUseSystemShapes", Cursor_SetUseSystemShapes},
{"Cursor_GetShape", Cursor_GetShape},
{"Cursor_GetUseSystemShapes", Cursor_GetUseSystemShapes},
{"Cursor_ApplyOSCursorShape", Cursor_ApplyOSCursorShape},
{"DropDownList_GetType", DropDownList_GetType},
{"DropDownList_GetTypeName", DropDownList_GetTypeName},
{"DropDownList_GetTypeStatic", DropDownList_GetTypeStatic},
{"DropDownList_GetTypeNameStatic", DropDownList_GetTypeNameStatic},
{"DropDownList_DropDownList", DropDownList_DropDownList},
{"DropDownList_RegisterObject", DropDownList_RegisterObject},
{"DropDownList_ApplyAttributes", DropDownList_ApplyAttributes},
{"DropDownList_OnShowPopup", DropDownList_OnShowPopup},
{"DropDownList_OnHidePopup", DropDownList_OnHidePopup},
{"DropDownList_OnSetEditable", DropDownList_OnSetEditable},
{"DropDownList_AddItem", DropDownList_AddItem},
{"DropDownList_InsertItem", DropDownList_InsertItem},
{"DropDownList_RemoveItem", DropDownList_RemoveItem},
{"DropDownList_RemoveItem0", DropDownList_RemoveItem0},
{"DropDownList_RemoveAllItems", DropDownList_RemoveAllItems},
{"DropDownList_SetSelection", DropDownList_SetSelection},
{"DropDownList_SetPlaceholderText", DropDownList_SetPlaceholderText},
{"DropDownList_SetResizePopup", DropDownList_SetResizePopup},
{"DropDownList_GetNumItems", DropDownList_GetNumItems},
{"DropDownList_GetItem", DropDownList_GetItem},
{"DropDownList_GetSelection", DropDownList_GetSelection},
{"DropDownList_GetSelectedItem", DropDownList_GetSelectedItem},
{"DropDownList_GetListView", DropDownList_GetListView},
{"DropDownList_GetPlaceholder", DropDownList_GetPlaceholder},
{"DropDownList_GetPlaceholderText", DropDownList_GetPlaceholderText},
{"DropDownList_GetResizePopup", DropDownList_GetResizePopup},
{"DropDownList_SetSelectionAttr", DropDownList_SetSelectionAttr},
{"Font_GetType", Font_GetType},
{"Font_GetTypeName", Font_GetTypeName},
{"Font_GetTypeStatic", Font_GetTypeStatic},
{"Font_GetTypeNameStatic", Font_GetTypeNameStatic},
{"Font_Font", Font_Font},
{"Font_RegisterObject", Font_RegisterObject},
{"Font_BeginLoad_File", Font_BeginLoad_File},
{"Font_BeginLoad_MemoryBuffer", Font_BeginLoad_MemoryBuffer},
{"Font_SaveXML_File", Font_SaveXML_File},
{"Font_SaveXML_MemoryBuffer", Font_SaveXML_MemoryBuffer},
{"Font_SetAbsoluteGlyphOffset", Font_SetAbsoluteGlyphOffset},
{"Font_SetScaledGlyphOffset", Font_SetScaledGlyphOffset},
{"Font_GetFace", Font_GetFace},
{"Font_GetFontType", Font_GetFontType},
{"Font_IsSDFFont", Font_IsSDFFont},
{"Font_GetAbsoluteGlyphOffset", Font_GetAbsoluteGlyphOffset},
{"Font_GetScaledGlyphOffset", Font_GetScaledGlyphOffset},
{"Font_GetTotalGlyphOffset", Font_GetTotalGlyphOffset},
{"Font_ReleaseFaces", Font_ReleaseFaces},
{"FontFace_Load", FontFace_Load},
{"FontFace_GetGlyph", FontFace_GetGlyph},
{"FontFace_HasMutableGlyphs", FontFace_HasMutableGlyphs},
{"FontFace_GetKerning", FontFace_GetKerning},
{"FontFace_IsDataLost", FontFace_IsDataLost},
{"FontFace_GetPointSize", FontFace_GetPointSize},
{"FontFace_GetRowHeight", FontFace_GetRowHeight},
{"FontFace_GetTextures", FontFace_GetTextures},
{"FontFaceBitmap_FontFaceBitmap", FontFaceBitmap_FontFaceBitmap},
{"FontFaceBitmap_Load", FontFaceBitmap_Load},
{"FontFaceBitmap_Load0", FontFaceBitmap_Load0},
{"FontFaceBitmap_Save_File", FontFaceBitmap_Save_File},
{"FontFaceBitmap_Save_MemoryBuffer", FontFaceBitmap_Save_MemoryBuffer},
{"FontFaceFreeType_FontFaceFreeType", FontFaceFreeType_FontFaceFreeType},
{"FontFaceFreeType_Load", FontFaceFreeType_Load},
{"FontFaceFreeType_GetGlyph", FontFaceFreeType_GetGlyph},
{"FontFaceFreeType_HasMutableGlyphs", FontFaceFreeType_HasMutableGlyphs},
{"LineEdit_GetType", LineEdit_GetType},
{"LineEdit_GetTypeName", LineEdit_GetTypeName},
{"LineEdit_GetTypeStatic", LineEdit_GetTypeStatic},
{"LineEdit_GetTypeNameStatic", LineEdit_GetTypeNameStatic},
{"LineEdit_LineEdit", LineEdit_LineEdit},
{"LineEdit_RegisterObject", LineEdit_RegisterObject},
{"LineEdit_ApplyAttributes", LineEdit_ApplyAttributes},
{"LineEdit_Update", LineEdit_Update},
{"LineEdit_OnTextInput", LineEdit_OnTextInput},
{"LineEdit_SetText", LineEdit_SetText},
{"LineEdit_SetCursorPosition", LineEdit_SetCursorPosition},
{"LineEdit_SetCursorBlinkRate", LineEdit_SetCursorBlinkRate},
{"LineEdit_SetMaxLength", LineEdit_SetMaxLength},
{"LineEdit_SetEchoCharacter", LineEdit_SetEchoCharacter},
{"LineEdit_SetCursorMovable", LineEdit_SetCursorMovable},
{"LineEdit_SetTextSelectable", LineEdit_SetTextSelectable},
{"LineEdit_SetTextCopyable", LineEdit_SetTextCopyable},
{"LineEdit_GetText", LineEdit_GetText},
{"LineEdit_GetCursorPosition", LineEdit_GetCursorPosition},
{"LineEdit_GetCursorBlinkRate", LineEdit_GetCursorBlinkRate},
{"LineEdit_GetMaxLength", LineEdit_GetMaxLength},
{"LineEdit_GetEchoCharacter", LineEdit_GetEchoCharacter},
{"LineEdit_IsCursorMovable", LineEdit_IsCursorMovable},
{"LineEdit_IsTextSelectable", LineEdit_IsTextSelectable},
{"LineEdit_IsTextCopyable", LineEdit_IsTextCopyable},
{"LineEdit_GetTextElement", LineEdit_GetTextElement},
{"LineEdit_GetCursor", LineEdit_GetCursor},
{"Menu_GetType", Menu_GetType},
{"Menu_GetTypeName", Menu_GetTypeName},
{"Menu_GetTypeStatic", Menu_GetTypeStatic},
{"Menu_GetTypeNameStatic", Menu_GetTypeNameStatic},
{"Menu_Menu", Menu_Menu},
{"Menu_RegisterObject", Menu_RegisterObject},
{"Menu_LoadXML", Menu_LoadXML},
{"Menu_SaveXML", Menu_SaveXML},
{"Menu_Update", Menu_Update},
{"Menu_OnShowPopup", Menu_OnShowPopup},
{"Menu_OnHidePopup", Menu_OnHidePopup},
{"Menu_SetPopup", Menu_SetPopup},
{"Menu_SetPopupOffset", Menu_SetPopupOffset},
{"Menu_SetPopupOffset0", Menu_SetPopupOffset0},
{"Menu_ShowPopup", Menu_ShowPopup},
{"Menu_SetAccelerator", Menu_SetAccelerator},
{"Menu_GetPopup", Menu_GetPopup},
{"Menu_GetPopupOffset", Menu_GetPopupOffset},
{"Menu_GetShowPopup", Menu_GetShowPopup},
{"Menu_GetAcceleratorKey", Menu_GetAcceleratorKey},
{"Menu_GetAcceleratorQualifiers", Menu_GetAcceleratorQualifiers},
{"MessageBox_GetType", MessageBox_GetType},
{"MessageBox_GetTypeName", MessageBox_GetTypeName},
{"MessageBox_GetTypeStatic", MessageBox_GetTypeStatic},
{"MessageBox_GetTypeNameStatic", MessageBox_GetTypeNameStatic},
{"MessageBox_MessageBox", MessageBox_MessageBox},
{"MessageBox_RegisterObject", MessageBox_RegisterObject},
{"MessageBox_SetTitle", MessageBox_SetTitle},
{"MessageBox_SetMessage", MessageBox_SetMessage},
{"MessageBox_GetTitle", MessageBox_GetTitle},
{"MessageBox_GetMessage", MessageBox_GetMessage},
{"MessageBox_GetWindow", MessageBox_GetWindow},
{"Slider_GetType", Slider_GetType},
{"Slider_GetTypeName", Slider_GetTypeName},
{"Slider_GetTypeStatic", Slider_GetTypeStatic},
{"Slider_GetTypeNameStatic", Slider_GetTypeNameStatic},
{"Slider_Slider", Slider_Slider},
{"Slider_RegisterObject", Slider_RegisterObject},
{"Slider_Update", Slider_Update},
{"Slider_OnResize", Slider_OnResize},
{"Slider_SetOrientation", Slider_SetOrientation},
{"Slider_SetRange", Slider_SetRange},
{"Slider_SetValue", Slider_SetValue},
{"Slider_ChangeValue", Slider_ChangeValue},
{"Slider_SetRepeatRate", Slider_SetRepeatRate},
{"Slider_GetOrientation", Slider_GetOrientation},
{"Slider_GetRange", Slider_GetRange},
{"Slider_GetValue", Slider_GetValue},
{"Slider_GetKnob", Slider_GetKnob},
{"Slider_GetRepeatRate", Slider_GetRepeatRate},
{"ScrollBar_GetType", ScrollBar_GetType},
{"ScrollBar_GetTypeName", ScrollBar_GetTypeName},
{"ScrollBar_GetTypeStatic", ScrollBar_GetTypeStatic},
{"ScrollBar_GetTypeNameStatic", ScrollBar_GetTypeNameStatic},
{"ScrollBar_ScrollBar", ScrollBar_ScrollBar},
{"ScrollBar_RegisterObject", ScrollBar_RegisterObject},
{"ScrollBar_ApplyAttributes", ScrollBar_ApplyAttributes},
{"ScrollBar_OnResize", ScrollBar_OnResize},
{"ScrollBar_OnSetEditable", ScrollBar_OnSetEditable},
{"ScrollBar_SetOrientation", ScrollBar_SetOrientation},
{"ScrollBar_SetRange", ScrollBar_SetRange},
{"ScrollBar_SetValue", ScrollBar_SetValue},
{"ScrollBar_ChangeValue", ScrollBar_ChangeValue},
{"ScrollBar_SetScrollStep", ScrollBar_SetScrollStep},
{"ScrollBar_SetStepFactor", ScrollBar_SetStepFactor},
{"ScrollBar_StepBack", ScrollBar_StepBack},
{"ScrollBar_StepForward", ScrollBar_StepForward},
{"ScrollBar_GetOrientation", ScrollBar_GetOrientation},
{"ScrollBar_GetRange", ScrollBar_GetRange},
{"ScrollBar_GetValue", ScrollBar_GetValue},
{"ScrollBar_GetScrollStep", ScrollBar_GetScrollStep},
{"ScrollBar_GetStepFactor", ScrollBar_GetStepFactor},
{"ScrollBar_GetEffectiveScrollStep", ScrollBar_GetEffectiveScrollStep},
{"ScrollBar_GetBackButton", ScrollBar_GetBackButton},
{"ScrollBar_GetForwardButton", ScrollBar_GetForwardButton},
{"ScrollBar_GetSlider", ScrollBar_GetSlider},
{"ScrollView_GetType", ScrollView_GetType},
{"ScrollView_GetTypeName", ScrollView_GetTypeName},
{"ScrollView_GetTypeStatic", ScrollView_GetTypeStatic},
{"ScrollView_GetTypeNameStatic", ScrollView_GetTypeNameStatic},
{"ScrollView_ScrollView", ScrollView_ScrollView},
{"ScrollView_RegisterObject", ScrollView_RegisterObject},
{"ScrollView_Update", ScrollView_Update},
{"ScrollView_ApplyAttributes", ScrollView_ApplyAttributes},
{"ScrollView_OnResize", ScrollView_OnResize},
{"ScrollView_IsWheelHandler", ScrollView_IsWheelHandler},
{"ScrollView_SetContentElement", ScrollView_SetContentElement},
{"ScrollView_SetViewPosition", ScrollView_SetViewPosition},
{"ScrollView_SetViewPosition0", ScrollView_SetViewPosition0},
{"ScrollView_SetScrollBarsVisible", ScrollView_SetScrollBarsVisible},
{"ScrollView_SetHorizontalScrollBarVisible", ScrollView_SetHorizontalScrollBarVisible},
{"ScrollView_SetVerticalScrollBarVisible", ScrollView_SetVerticalScrollBarVisible},
{"ScrollView_SetScrollBarsAutoVisible", ScrollView_SetScrollBarsAutoVisible},
{"ScrollView_SetScrollStep", ScrollView_SetScrollStep},
{"ScrollView_SetPageStep", ScrollView_SetPageStep},
{"ScrollView_SetScrollDeceleration", ScrollView_SetScrollDeceleration},
{"ScrollView_SetScrollSnapEpsilon", ScrollView_SetScrollSnapEpsilon},
{"ScrollView_SetAutoDisableChildren", ScrollView_SetAutoDisableChildren},
{"ScrollView_SetAutoDisableThreshold", ScrollView_SetAutoDisableThreshold},
{"ScrollView_GetViewPosition", ScrollView_GetViewPosition},
{"ScrollView_GetContentElement", ScrollView_GetContentElement},
{"ScrollView_GetHorizontalScrollBar", ScrollView_GetHorizontalScrollBar},
{"ScrollView_GetVerticalScrollBar", ScrollView_GetVerticalScrollBar},
{"ScrollView_GetScrollPanel", ScrollView_GetScrollPanel},
{"ScrollView_GetScrollBarsAutoVisible", ScrollView_GetScrollBarsAutoVisible},
{"ScrollView_GetHorizontalScrollBarVisible", ScrollView_GetHorizontalScrollBarVisible},
{"ScrollView_GetVerticalScrollBarVisible", ScrollView_GetVerticalScrollBarVisible},
{"ScrollView_GetScrollStep", ScrollView_GetScrollStep},
{"ScrollView_GetPageStep", ScrollView_GetPageStep},
{"ScrollView_GetScrollDeceleration", ScrollView_GetScrollDeceleration},
{"ScrollView_GetScrollSnapEpsilon", ScrollView_GetScrollSnapEpsilon},
{"ScrollView_GetAutoDisableChildren", ScrollView_GetAutoDisableChildren},
{"ScrollView_GetAutoDisableThreshold", ScrollView_GetAutoDisableThreshold},
{"ScrollView_SetViewPositionAttr", ScrollView_SetViewPositionAttr},
{"Window_GetType", Window_GetType},
{"Window_GetTypeName", Window_GetTypeName},
{"Window_GetTypeStatic", Window_GetTypeStatic},
{"Window_GetTypeNameStatic", Window_GetTypeNameStatic},
{"Window_Window", Window_Window},
{"Window_RegisterObject", Window_RegisterObject},
{"Window_SetMovable", Window_SetMovable},
{"Window_SetResizable", Window_SetResizable},
{"Window_SetFixedWidthResizing", Window_SetFixedWidthResizing},
{"Window_SetFixedHeightResizing", Window_SetFixedHeightResizing},
{"Window_SetResizeBorder", Window_SetResizeBorder},
{"Window_SetModal", Window_SetModal},
{"Window_SetModalShadeColor", Window_SetModalShadeColor},
{"Window_SetModalFrameColor", Window_SetModalFrameColor},
{"Window_SetModalFrameSize", Window_SetModalFrameSize},
{"Window_SetModalAutoDismiss", Window_SetModalAutoDismiss},
{"Window_IsMovable", Window_IsMovable},
{"Window_IsResizable", Window_IsResizable},
{"Window_GetFixedWidthResizing", Window_GetFixedWidthResizing},
{"Window_GetFixedHeightResizing", Window_GetFixedHeightResizing},
{"Window_GetResizeBorder", Window_GetResizeBorder},
{"Window_IsModal", Window_IsModal},
{"Window_GetModalShadeColor", Window_GetModalShadeColor},
{"Window_GetModalFrameColor", Window_GetModalFrameColor},
{"Window_GetModalFrameSize", Window_GetModalFrameSize},
{"Window_GetModalAutoDismiss", Window_GetModalAutoDismiss},
{"Sprite_GetType", Sprite_GetType},
{"Sprite_GetTypeName", Sprite_GetTypeName},
{"Sprite_GetTypeStatic", Sprite_GetTypeStatic},
{"Sprite_GetTypeNameStatic", Sprite_GetTypeNameStatic},
{"Sprite_Sprite", Sprite_Sprite},
{"Sprite_RegisterObject", Sprite_RegisterObject},
{"Sprite_IsWithinScissor", Sprite_IsWithinScissor},
{"Sprite_GetScreenPosition", Sprite_GetScreenPosition},
{"Sprite_OnPositionSet", Sprite_OnPositionSet},
{"Sprite_ScreenToElement", Sprite_ScreenToElement},
{"Sprite_ElementToScreen", Sprite_ElementToScreen},
{"Sprite_SetPosition", Sprite_SetPosition},
{"Sprite_SetPosition0", Sprite_SetPosition0},
{"Sprite_SetHotSpot", Sprite_SetHotSpot},
{"Sprite_SetHotSpot1", Sprite_SetHotSpot1},
{"Sprite_SetScale", Sprite_SetScale},
{"Sprite_SetScale2", Sprite_SetScale2},
{"Sprite_SetScale3", Sprite_SetScale3},
{"Sprite_SetRotation", Sprite_SetRotation},
{"Sprite_SetTexture", Sprite_SetTexture},
{"Sprite_SetImageRect", Sprite_SetImageRect},
{"Sprite_SetFullImageRect", Sprite_SetFullImageRect},
{"Sprite_SetBlendMode", Sprite_SetBlendMode},
{"Sprite_GetPosition", Sprite_GetPosition},
{"Sprite_GetHotSpot", Sprite_GetHotSpot},
{"Sprite_GetScale", Sprite_GetScale},
{"Sprite_GetRotation", Sprite_GetRotation},
{"Sprite_GetTexture", Sprite_GetTexture},
{"Sprite_GetImageRect", Sprite_GetImageRect},
{"Sprite_GetBlendMode", Sprite_GetBlendMode},
{"Sprite_GetTextureAttr", Sprite_GetTextureAttr},
{"Sprite_GetTransform", Sprite_GetTransform},
{"Text_GetType", Text_GetType},
{"Text_GetTypeName", Text_GetTypeName},
{"Text_GetTypeStatic", Text_GetTypeStatic},
{"Text_GetTypeNameStatic", Text_GetTypeNameStatic},
{"Text_Text", Text_Text},
{"Text_RegisterObject", Text_RegisterObject},
{"Text_ApplyAttributes", Text_ApplyAttributes},
{"Text_OnResize", Text_OnResize},
{"Text_OnIndentSet", Text_OnIndentSet},
{"Text_SetFont", Text_SetFont},
{"Text_SetFont0", Text_SetFont0},
{"Text_SetFontSize", Text_SetFontSize},
{"Text_SetText", Text_SetText},
{"Text_SetTextAlignment", Text_SetTextAlignment},
{"Text_SetRowSpacing", Text_SetRowSpacing},
{"Text_SetWordwrap", Text_SetWordwrap},
{"Text_SetAutoLocalizable", Text_SetAutoLocalizable},
{"Text_SetSelection", Text_SetSelection},
{"Text_ClearSelection", Text_ClearSelection},
{"Text_SetTextEffect", Text_SetTextEffect},
{"Text_SetEffectShadowOffset", Text_SetEffectShadowOffset},
{"Text_SetEffectStrokeThickness", Text_SetEffectStrokeThickness},
{"Text_SetEffectRoundStroke", Text_SetEffectRoundStroke},
{"Text_SetEffectColor", Text_SetEffectColor},
{"Text_GetFont", Text_GetFont},
{"Text_GetFontSize", Text_GetFontSize},
{"Text_GetText", Text_GetText},
{"Text_GetTextAlignment", Text_GetTextAlignment},
{"Text_GetRowSpacing", Text_GetRowSpacing},
{"Text_GetWordwrap", Text_GetWordwrap},
{"Text_GetAutoLocalizable", Text_GetAutoLocalizable},
{"Text_GetSelectionStart", Text_GetSelectionStart},
{"Text_GetSelectionLength", Text_GetSelectionLength},
{"Text_GetTextEffect", Text_GetTextEffect},
{"Text_GetEffectShadowOffset", Text_GetEffectShadowOffset},
{"Text_GetEffectStrokeThickness", Text_GetEffectStrokeThickness},
{"Text_GetEffectRoundStroke", Text_GetEffectRoundStroke},
{"Text_GetEffectColor", Text_GetEffectColor},
{"Text_GetRowHeight", Text_GetRowHeight},
{"Text_GetNumRows", Text_GetNumRows},
{"Text_GetNumChars", Text_GetNumChars},
{"Text_GetRowWidth", Text_GetRowWidth},
{"Text_GetCharPosition", Text_GetCharPosition},
{"Text_GetCharSize", Text_GetCharSize},
{"Text_SetEffectDepthBias", Text_SetEffectDepthBias},
{"Text_GetEffectDepthBias", Text_GetEffectDepthBias},
{"Text_GetFontAttr", Text_GetFontAttr},
{"Text_SetTextAttr", Text_SetTextAttr},
{"Text_GetTextAttr", Text_GetTextAttr},
{"Text3D_GetType", Text3D_GetType},
{"Text3D_GetTypeName", Text3D_GetTypeName},
{"Text3D_GetTypeStatic", Text3D_GetTypeStatic},
{"Text3D_GetTypeNameStatic", Text3D_GetTypeNameStatic},
{"Text3D_Text3D", Text3D_Text3D},
{"Text3D_RegisterObject", Text3D_RegisterObject},
{"Text3D_ApplyAttributes", Text3D_ApplyAttributes},
{"Text3D_GetUpdateGeometryType", Text3D_GetUpdateGeometryType},
{"Text3D_SetFont", Text3D_SetFont},
{"Text3D_SetFont0", Text3D_SetFont0},
{"Text3D_SetFontSize", Text3D_SetFontSize},
{"Text3D_SetMaterial", Text3D_SetMaterial},
{"Text3D_SetText", Text3D_SetText},
{"Text3D_SetAlignment", Text3D_SetAlignment},
{"Text3D_SetHorizontalAlignment", Text3D_SetHorizontalAlignment},
{"Text3D_SetVerticalAlignment", Text3D_SetVerticalAlignment},
{"Text3D_SetTextAlignment", Text3D_SetTextAlignment},
{"Text3D_SetRowSpacing", Text3D_SetRowSpacing},
{"Text3D_SetWordwrap", Text3D_SetWordwrap},
{"Text3D_SetTextEffect", Text3D_SetTextEffect},
{"Text3D_SetEffectShadowOffset", Text3D_SetEffectShadowOffset},
{"Text3D_SetEffectStrokeThickness", Text3D_SetEffectStrokeThickness},
{"Text3D_SetEffectRoundStroke", Text3D_SetEffectRoundStroke},
{"Text3D_SetEffectColor", Text3D_SetEffectColor},
{"Text3D_SetEffectDepthBias", Text3D_SetEffectDepthBias},
{"Text3D_SetWidth", Text3D_SetWidth},
{"Text3D_SetColor", Text3D_SetColor},
{"Text3D_SetColor1", Text3D_SetColor1},
{"Text3D_SetOpacity", Text3D_SetOpacity},
{"Text3D_SetFixedScreenSize", Text3D_SetFixedScreenSize},
{"Text3D_SetFaceCameraMode", Text3D_SetFaceCameraMode},
{"Text3D_GetFont", Text3D_GetFont},
{"Text3D_GetFontSize", Text3D_GetFontSize},
{"Text3D_GetMaterial", Text3D_GetMaterial},
{"Text3D_GetText", Text3D_GetText},
{"Text3D_GetTextAlignment", Text3D_GetTextAlignment},
{"Text3D_GetHorizontalAlignment", Text3D_GetHorizontalAlignment},
{"Text3D_GetVerticalAlignment", Text3D_GetVerticalAlignment},
{"Text3D_GetRowSpacing", Text3D_GetRowSpacing},
{"Text3D_GetWordwrap", Text3D_GetWordwrap},
{"Text3D_GetTextEffect", Text3D_GetTextEffect},
{"Text3D_GetEffectShadowOffset", Text3D_GetEffectShadowOffset},
{"Text3D_GetEffectStrokeThickness", Text3D_GetEffectStrokeThickness},
{"Text3D_GetEffectRoundStroke", Text3D_GetEffectRoundStroke},
{"Text3D_GetEffectColor", Text3D_GetEffectColor},
{"Text3D_GetEffectDepthBias", Text3D_GetEffectDepthBias},
{"Text3D_GetWidth", Text3D_GetWidth},
{"Text3D_GetHeight", Text3D_GetHeight},
{"Text3D_GetRowHeight", Text3D_GetRowHeight},
{"Text3D_GetNumRows", Text3D_GetNumRows},
{"Text3D_GetNumChars", Text3D_GetNumChars},
{"Text3D_GetRowWidth", Text3D_GetRowWidth},
{"Text3D_GetCharPosition", Text3D_GetCharPosition},
{"Text3D_GetCharSize", Text3D_GetCharSize},
{"Text3D_GetColor", Text3D_GetColor},
{"Text3D_GetOpacity", Text3D_GetOpacity},
{"Text3D_IsFixedScreenSize", Text3D_IsFixedScreenSize},
{"Text3D_GetFaceCameraMode", Text3D_GetFaceCameraMode},
{"Text3D_GetFontAttr", Text3D_GetFontAttr},
{"Text3D_GetMaterialAttr", Text3D_GetMaterialAttr},
{"Text3D_SetTextAttr", Text3D_SetTextAttr},
{"Text3D_GetTextAttr", Text3D_GetTextAttr},
{"Text3D_GetColorAttr", Text3D_GetColorAttr},
{"ToolTip_GetType", ToolTip_GetType},
{"ToolTip_GetTypeName", ToolTip_GetTypeName},
{"ToolTip_GetTypeStatic", ToolTip_GetTypeStatic},
{"ToolTip_GetTypeNameStatic", ToolTip_GetTypeNameStatic},
{"ToolTip_ToolTip", ToolTip_ToolTip},
{"ToolTip_RegisterObject", ToolTip_RegisterObject},
{"ToolTip_Update", ToolTip_Update},
{"ToolTip_Reset", ToolTip_Reset},
{"ToolTip_AddAltTarget", ToolTip_AddAltTarget},
{"ToolTip_SetDelay", ToolTip_SetDelay},
{"ToolTip_GetDelay", ToolTip_GetDelay},
{"UIBatch_UIBatch", UIBatch_UIBatch},
{"UIBatch_SetColor", UIBatch_SetColor},
{"UIBatch_SetDefaultColor", UIBatch_SetDefaultColor},
{"UIBatch_AddQuad", UIBatch_AddQuad},
{"UIBatch_AddQuad0", UIBatch_AddQuad0},
{"UIBatch_AddQuad1", UIBatch_AddQuad1},
{"UIBatch_AddQuad2", UIBatch_AddQuad2},
{"UIBatch_AddQuad3", UIBatch_AddQuad3},
{"UIBatch_GetInterpolatedColor", UIBatch_GetInterpolatedColor},
{"View3D_GetType", View3D_GetType},
{"View3D_GetTypeName", View3D_GetTypeName},
{"View3D_GetTypeStatic", View3D_GetTypeStatic},
{"View3D_GetTypeNameStatic", View3D_GetTypeNameStatic},
{"View3D_View3D", View3D_View3D},
{"View3D_RegisterObject", View3D_RegisterObject},
{"View3D_OnResize", View3D_OnResize},
{"View3D_SetView", View3D_SetView},
{"View3D_SetFormat", View3D_SetFormat},
{"View3D_SetAutoUpdate", View3D_SetAutoUpdate},
{"View3D_QueueUpdate", View3D_QueueUpdate},
{"View3D_GetFormat", View3D_GetFormat},
{"View3D_GetAutoUpdate", View3D_GetAutoUpdate},
{"View3D_GetScene", View3D_GetScene},
{"View3D_GetCameraNode", View3D_GetCameraNode},
{"View3D_GetRenderTexture", View3D_GetRenderTexture},
{"View3D_GetDepthTexture", View3D_GetDepthTexture},
{"View3D_GetViewport", View3D_GetViewport},
{"File_GetSize", File_GetSize},
{"File_WriteLine", File_WriteLine},
{"File_ReadLine", File_ReadLine},
{"File_GetType", File_GetType},
{"File_GetTypeName", File_GetTypeName},
{"File_GetTypeStatic", File_GetTypeStatic},
{"File_GetTypeNameStatic", File_GetTypeNameStatic},
{"File_File", File_File},
{"File_File0", File_File0},
{"File_File1", File_File1},
{"File_Read", File_Read},
{"File_Seek", File_Seek},
{"File_Write", File_Write},
{"File_GetChecksum", File_GetChecksum},
{"File_Open", File_Open},
{"File_Open2", File_Open2},
{"File_Close", File_Close},
{"File_Flush", File_Flush},
{"File_GetMode", File_GetMode},
{"File_IsOpen", File_IsOpen},
{"File_GetHandle", File_GetHandle},
{"File_IsPackaged", File_IsPackaged},
{"File_GetName", File_GetName},
{"Log_GetType", Log_GetType},
{"Log_GetTypeName", Log_GetTypeName},
{"Log_GetTypeStatic", Log_GetTypeStatic},
{"Log_GetTypeNameStatic", Log_GetTypeNameStatic},
{"Log_Log", Log_Log},
{"Log_Open", Log_Open},
{"Log_Close", Log_Close},
{"Log_SetLevel", Log_SetLevel},
{"Log_SetTimeStamp", Log_SetTimeStamp},
{"Log_SetQuiet", Log_SetQuiet},
{"Log_GetLevel", Log_GetLevel},
{"Log_GetTimeStamp", Log_GetTimeStamp},
{"Log_GetLastMessage", Log_GetLastMessage},
{"Log_IsQuiet", Log_IsQuiet},
{"Log_Write", Log_Write},
{"Log_WriteRaw", Log_WriteRaw},
{"FileSystem_GetType", FileSystem_GetType},
{"FileSystem_GetTypeName", FileSystem_GetTypeName},
{"FileSystem_GetTypeStatic", FileSystem_GetTypeStatic},
{"FileSystem_GetTypeNameStatic", FileSystem_GetTypeNameStatic},
{"FileSystem_FileSystem", FileSystem_FileSystem},
{"FileSystem_SetCurrentDir", FileSystem_SetCurrentDir},
{"FileSystem_CreateDir", FileSystem_CreateDir},
{"FileSystem_SetExecuteConsoleCommands", FileSystem_SetExecuteConsoleCommands},
{"FileSystem_SystemCommand", FileSystem_SystemCommand},
{"FileSystem_SystemCommandAsync", FileSystem_SystemCommandAsync},
{"FileSystem_SystemOpen", FileSystem_SystemOpen},
{"FileSystem_Copy", FileSystem_Copy},
{"FileSystem_Rename", FileSystem_Rename},
{"FileSystem_Delete", FileSystem_Delete},
{"FileSystem_RegisterPath", FileSystem_RegisterPath},
{"FileSystem_SetLastModifiedTime", FileSystem_SetLastModifiedTime},
{"FileSystem_GetCurrentDir", FileSystem_GetCurrentDir},
{"FileSystem_GetExecuteConsoleCommands", FileSystem_GetExecuteConsoleCommands},
{"FileSystem_HasRegisteredPaths", FileSystem_HasRegisteredPaths},
{"FileSystem_CheckAccess", FileSystem_CheckAccess},
{"FileSystem_GetLastModifiedTime", FileSystem_GetLastModifiedTime},
{"FileSystem_FileExists", FileSystem_FileExists},
{"FileSystem_DirExists", FileSystem_DirExists},
{"FileSystem_GetProgramDir", FileSystem_GetProgramDir},
{"FileSystem_GetUserDocumentsDir", FileSystem_GetUserDocumentsDir},
{"FileSystem_GetAppPreferencesDir", FileSystem_GetAppPreferencesDir},
{"FileSystem_GetTemporaryDir", FileSystem_GetTemporaryDir},
{"FileWatcher_GetType", FileWatcher_GetType},
{"FileWatcher_GetTypeName", FileWatcher_GetTypeName},
{"FileWatcher_GetTypeStatic", FileWatcher_GetTypeStatic},
{"FileWatcher_GetTypeNameStatic", FileWatcher_GetTypeNameStatic},
{"FileWatcher_FileWatcher", FileWatcher_FileWatcher},
{"FileWatcher_ThreadFunction", FileWatcher_ThreadFunction},
{"FileWatcher_StartWatching", FileWatcher_StartWatching},
{"FileWatcher_StopWatching", FileWatcher_StopWatching},
{"FileWatcher_SetDelay", FileWatcher_SetDelay},
{"FileWatcher_AddChange", FileWatcher_AddChange},
{"FileWatcher_GetPath", FileWatcher_GetPath},
{"FileWatcher_GetDelay", FileWatcher_GetDelay},
{"PackageFile_GetType", PackageFile_GetType},
{"PackageFile_GetTypeName", PackageFile_GetTypeName},
{"PackageFile_GetTypeStatic", PackageFile_GetTypeStatic},
{"PackageFile_GetTypeNameStatic", PackageFile_GetTypeNameStatic},
{"PackageFile_PackageFile", PackageFile_PackageFile},
{"PackageFile_PackageFile0", PackageFile_PackageFile0},
{"PackageFile_Open", PackageFile_Open},
{"PackageFile_Exists", PackageFile_Exists},
{"PackageFile_GetEntry", PackageFile_GetEntry},
{"PackageFile_GetName", PackageFile_GetName},
{"PackageFile_GetNameHash", PackageFile_GetNameHash},
{"PackageFile_GetNumFiles", PackageFile_GetNumFiles},
{"PackageFile_GetTotalSize", PackageFile_GetTotalSize},
{"PackageFile_GetTotalDataSize", PackageFile_GetTotalDataSize},
{"PackageFile_GetChecksum", PackageFile_GetChecksum},
{"PackageFile_IsCompressed", PackageFile_IsCompressed},
{"Drawable2D_SetSourceBatchesVertices", Drawable2D_SetSourceBatchesVertices},
{"Drawable2D_GetType", Drawable2D_GetType},
{"Drawable2D_GetTypeName", Drawable2D_GetTypeName},
{"Drawable2D_GetTypeStatic", Drawable2D_GetTypeStatic},
{"Drawable2D_GetTypeNameStatic", Drawable2D_GetTypeNameStatic},
{"Drawable2D_RegisterObject", Drawable2D_RegisterObject},
{"Drawable2D_OnSetEnabled", Drawable2D_OnSetEnabled},
{"Drawable2D_SetLayer", Drawable2D_SetLayer},
{"Drawable2D_SetOrderInLayer", Drawable2D_SetOrderInLayer},
{"Drawable2D_GetLayer", Drawable2D_GetLayer},
{"Drawable2D_GetOrderInLayer", Drawable2D_GetOrderInLayer},
{"Drawable2D_SetSourceBatches", Drawable2D_SetSourceBatches},
{"Drawable2D_SetSourceBatchesDirty", Drawable2D_SetSourceBatchesDirty},
{"Drawable2D_SetMonoUpdateSourceBatches", Drawable2D_SetMonoUpdateSourceBatches},
{"PhysicsWorld2D_GetRigidBodies", PhysicsWorld2D_GetRigidBodies},
{"PhysicsWorld2D_GetType", PhysicsWorld2D_GetType},
{"PhysicsWorld2D_GetTypeName", PhysicsWorld2D_GetTypeName},
{"PhysicsWorld2D_GetTypeStatic", PhysicsWorld2D_GetTypeStatic},
{"PhysicsWorld2D_GetTypeNameStatic", PhysicsWorld2D_GetTypeNameStatic},
{"PhysicsWorld2D_PhysicsWorld2D", PhysicsWorld2D_PhysicsWorld2D},
{"PhysicsWorld2D_RegisterObject", PhysicsWorld2D_RegisterObject},
{"PhysicsWorld2D_DrawDebugGeometry", PhysicsWorld2D_DrawDebugGeometry},
{"PhysicsWorld2D_Update", PhysicsWorld2D_Update},
{"PhysicsWorld2D_DrawDebugGeometry0", PhysicsWorld2D_DrawDebugGeometry0},
{"PhysicsWorld2D_SetUpdateEnabled", PhysicsWorld2D_SetUpdateEnabled},
{"PhysicsWorld2D_SetDrawShape", PhysicsWorld2D_SetDrawShape},
{"PhysicsWorld2D_SetDrawJoint", PhysicsWorld2D_SetDrawJoint},
{"PhysicsWorld2D_SetDrawAabb", PhysicsWorld2D_SetDrawAabb},
{"PhysicsWorld2D_SetDrawPair", PhysicsWorld2D_SetDrawPair},
{"PhysicsWorld2D_SetDrawCenterOfMass", PhysicsWorld2D_SetDrawCenterOfMass},
{"PhysicsWorld2D_SetAllowSleeping", PhysicsWorld2D_SetAllowSleeping},
{"PhysicsWorld2D_SetWarmStarting", PhysicsWorld2D_SetWarmStarting},
{"PhysicsWorld2D_SetContinuousPhysics", PhysicsWorld2D_SetContinuousPhysics},
{"PhysicsWorld2D_SetSubStepping", PhysicsWorld2D_SetSubStepping},
{"PhysicsWorld2D_SetGravity", PhysicsWorld2D_SetGravity},
{"PhysicsWorld2D_SetAutoClearForces", PhysicsWorld2D_SetAutoClearForces},
{"PhysicsWorld2D_SetVelocityIterations", PhysicsWorld2D_SetVelocityIterations},
{"PhysicsWorld2D_SetPositionIterations", PhysicsWorld2D_SetPositionIterations},
{"PhysicsWorld2D_AddRigidBody", PhysicsWorld2D_AddRigidBody},
{"PhysicsWorld2D_RemoveRigidBody", PhysicsWorld2D_RemoveRigidBody},
{"PhysicsWorld2D_GetRigidBody", PhysicsWorld2D_GetRigidBody},
{"PhysicsWorld2D_GetRigidBody1", PhysicsWorld2D_GetRigidBody1},
{"PhysicsWorld2D_IsUpdateEnabled", PhysicsWorld2D_IsUpdateEnabled},
{"PhysicsWorld2D_GetDrawShape", PhysicsWorld2D_GetDrawShape},
{"PhysicsWorld2D_GetDrawJoint", PhysicsWorld2D_GetDrawJoint},
{"PhysicsWorld2D_GetDrawAabb", PhysicsWorld2D_GetDrawAabb},
{"PhysicsWorld2D_GetDrawPair", PhysicsWorld2D_GetDrawPair},
{"PhysicsWorld2D_GetDrawCenterOfMass", PhysicsWorld2D_GetDrawCenterOfMass},
{"PhysicsWorld2D_GetAllowSleeping", PhysicsWorld2D_GetAllowSleeping},
{"PhysicsWorld2D_GetWarmStarting", PhysicsWorld2D_GetWarmStarting},
{"PhysicsWorld2D_GetContinuousPhysics", PhysicsWorld2D_GetContinuousPhysics},
{"PhysicsWorld2D_GetSubStepping", PhysicsWorld2D_GetSubStepping},
{"PhysicsWorld2D_GetAutoClearForces", PhysicsWorld2D_GetAutoClearForces},
{"PhysicsWorld2D_GetGravity", PhysicsWorld2D_GetGravity},
{"PhysicsWorld2D_GetVelocityIterations", PhysicsWorld2D_GetVelocityIterations},
{"PhysicsWorld2D_GetPositionIterations", PhysicsWorld2D_GetPositionIterations},
{"PhysicsWorld2D_SetApplyingTransforms", PhysicsWorld2D_SetApplyingTransforms},
{"PhysicsWorld2D_IsApplyingTransforms", PhysicsWorld2D_IsApplyingTransforms},
{"StaticSprite2D_GetType", StaticSprite2D_GetType},
{"StaticSprite2D_GetTypeName", StaticSprite2D_GetTypeName},
{"StaticSprite2D_GetTypeStatic", StaticSprite2D_GetTypeStatic},
{"StaticSprite2D_GetTypeNameStatic", StaticSprite2D_GetTypeNameStatic},
{"StaticSprite2D_StaticSprite2D", StaticSprite2D_StaticSprite2D},
{"StaticSprite2D_RegisterObject", StaticSprite2D_RegisterObject},
{"StaticSprite2D_SetSprite", StaticSprite2D_SetSprite},
{"StaticSprite2D_SetBlendMode", StaticSprite2D_SetBlendMode},
{"StaticSprite2D_SetFlip", StaticSprite2D_SetFlip},
{"StaticSprite2D_SetFlipX", StaticSprite2D_SetFlipX},
{"StaticSprite2D_SetFlipY", StaticSprite2D_SetFlipY},
{"StaticSprite2D_SetSwapXY", StaticSprite2D_SetSwapXY},
{"StaticSprite2D_SetColor", StaticSprite2D_SetColor},
{"StaticSprite2D_SetAlpha", StaticSprite2D_SetAlpha},
{"StaticSprite2D_SetUseHotSpot", StaticSprite2D_SetUseHotSpot},
{"StaticSprite2D_SetUseDrawRect", StaticSprite2D_SetUseDrawRect},
{"StaticSprite2D_SetUseTextureRect", StaticSprite2D_SetUseTextureRect},
{"StaticSprite2D_SetHotSpot", StaticSprite2D_SetHotSpot},
{"StaticSprite2D_SetCustomMaterial", StaticSprite2D_SetCustomMaterial},
{"StaticSprite2D_GetSprite", StaticSprite2D_GetSprite},
{"StaticSprite2D_GetBlendMode", StaticSprite2D_GetBlendMode},
{"StaticSprite2D_GetFlipX", StaticSprite2D_GetFlipX},
{"StaticSprite2D_GetFlipY", StaticSprite2D_GetFlipY},
{"StaticSprite2D_GetSwapXY", StaticSprite2D_GetSwapXY},
{"StaticSprite2D_GetColor", StaticSprite2D_GetColor},
{"StaticSprite2D_GetAlpha", StaticSprite2D_GetAlpha},
{"StaticSprite2D_GetUseHotSpot", StaticSprite2D_GetUseHotSpot},
{"StaticSprite2D_GetUseDrawRect", StaticSprite2D_GetUseDrawRect},
{"StaticSprite2D_GetUseTextureRect", StaticSprite2D_GetUseTextureRect},
{"StaticSprite2D_GetHotSpot", StaticSprite2D_GetHotSpot},
{"StaticSprite2D_GetCustomMaterial", StaticSprite2D_GetCustomMaterial},
{"StaticSprite2D_GetSpriteAttr", StaticSprite2D_GetSpriteAttr},
{"StaticSprite2D_GetCustomMaterialAttr", StaticSprite2D_GetCustomMaterialAttr},
{"StaticSprite2D_SetMonoWorldBoundingBoxUpdate", StaticSprite2D_SetMonoWorldBoundingBoxUpdate},
{"Texture2D_GetType", Texture2D_GetType},
{"Texture2D_GetTypeName", Texture2D_GetTypeName},
{"Texture2D_GetTypeStatic", Texture2D_GetTypeStatic},
{"Texture2D_GetTypeNameStatic", Texture2D_GetTypeNameStatic},
{"Texture2D_Texture2D", Texture2D_Texture2D},
{"Texture2D_RegisterObject", Texture2D_RegisterObject},
{"Texture2D_BeginLoad_File", Texture2D_BeginLoad_File},
{"Texture2D_BeginLoad_MemoryBuffer", Texture2D_BeginLoad_MemoryBuffer},
{"Texture2D_EndLoad", Texture2D_EndLoad},
{"Texture2D_Release", Texture2D_Release},
{"Texture2D_SetSize", Texture2D_SetSize},
{"Texture2D_SetData", Texture2D_SetData},
{"Texture2D_SetData0", Texture2D_SetData0},
{"Texture2D_GetData", Texture2D_GetData},
{"Texture2D_GetImage", Texture2D_GetImage},
{"Texture2D_GetImage1", Texture2D_GetImage1},
{"Texture2D_GetRenderSurface", Texture2D_GetRenderSurface},
{"AnimatedSprite2D_GetType", AnimatedSprite2D_GetType},
{"AnimatedSprite2D_GetTypeName", AnimatedSprite2D_GetTypeName},
{"AnimatedSprite2D_GetTypeStatic", AnimatedSprite2D_GetTypeStatic},
{"AnimatedSprite2D_GetTypeNameStatic", AnimatedSprite2D_GetTypeNameStatic},
{"AnimatedSprite2D_AnimatedSprite2D", AnimatedSprite2D_AnimatedSprite2D},
{"AnimatedSprite2D_RegisterObject", AnimatedSprite2D_RegisterObject},
{"AnimatedSprite2D_OnSetEnabled", AnimatedSprite2D_OnSetEnabled},
{"AnimatedSprite2D_SetAnimationSet", AnimatedSprite2D_SetAnimationSet},
{"AnimatedSprite2D_SetEntity", AnimatedSprite2D_SetEntity},
{"AnimatedSprite2D_SetAnimation", AnimatedSprite2D_SetAnimation},
{"AnimatedSprite2D_SetLoopMode", AnimatedSprite2D_SetLoopMode},
{"AnimatedSprite2D_SetSpeed", AnimatedSprite2D_SetSpeed},
{"AnimatedSprite2D_GetAnimationSet", AnimatedSprite2D_GetAnimationSet},
{"AnimatedSprite2D_GetEntity", AnimatedSprite2D_GetEntity},
{"AnimatedSprite2D_GetAnimation", AnimatedSprite2D_GetAnimation},
{"AnimatedSprite2D_GetLoopMode", AnimatedSprite2D_GetLoopMode},
{"AnimatedSprite2D_GetSpeed", AnimatedSprite2D_GetSpeed},
{"AnimatedSprite2D_GetAnimationSetAttr", AnimatedSprite2D_GetAnimationSetAttr},
{"AnimatedSprite2D_SetAnimationAttr", AnimatedSprite2D_SetAnimationAttr},
{"AnimationSet2D_GetType", AnimationSet2D_GetType},
{"AnimationSet2D_GetTypeName", AnimationSet2D_GetTypeName},
{"AnimationSet2D_GetTypeStatic", AnimationSet2D_GetTypeStatic},
{"AnimationSet2D_GetTypeNameStatic", AnimationSet2D_GetTypeNameStatic},
{"AnimationSet2D_AnimationSet2D", AnimationSet2D_AnimationSet2D},
{"AnimationSet2D_RegisterObject", AnimationSet2D_RegisterObject},
{"AnimationSet2D_BeginLoad_File", AnimationSet2D_BeginLoad_File},
{"AnimationSet2D_BeginLoad_MemoryBuffer", AnimationSet2D_BeginLoad_MemoryBuffer},
{"AnimationSet2D_EndLoad", AnimationSet2D_EndLoad},
{"AnimationSet2D_GetNumAnimations", AnimationSet2D_GetNumAnimations},
{"AnimationSet2D_GetAnimation", AnimationSet2D_GetAnimation},
{"AnimationSet2D_HasAnimation", AnimationSet2D_HasAnimation},
{"AnimationSet2D_GetSprite", AnimationSet2D_GetSprite},
{"AnimationSet2D_GetSpriterFileSprite", AnimationSet2D_GetSpriterFileSprite},
{"CollisionBox2D_GetType", CollisionBox2D_GetType},
{"CollisionBox2D_GetTypeName", CollisionBox2D_GetTypeName},
{"CollisionBox2D_GetTypeStatic", CollisionBox2D_GetTypeStatic},
{"CollisionBox2D_GetTypeNameStatic", CollisionBox2D_GetTypeNameStatic},
{"CollisionBox2D_CollisionBox2D", CollisionBox2D_CollisionBox2D},
{"CollisionBox2D_RegisterObject", CollisionBox2D_RegisterObject},
{"CollisionBox2D_SetSize", CollisionBox2D_SetSize},
{"CollisionBox2D_SetSize0", CollisionBox2D_SetSize0},
{"CollisionBox2D_SetCenter", CollisionBox2D_SetCenter},
{"CollisionBox2D_SetCenter1", CollisionBox2D_SetCenter1},
{"CollisionBox2D_SetAngle", CollisionBox2D_SetAngle},
{"CollisionBox2D_GetSize", CollisionBox2D_GetSize},
{"CollisionBox2D_GetCenter", CollisionBox2D_GetCenter},
{"CollisionBox2D_GetAngle", CollisionBox2D_GetAngle},
{"CollisionChain2D_GetType", CollisionChain2D_GetType},
{"CollisionChain2D_GetTypeName", CollisionChain2D_GetTypeName},
{"CollisionChain2D_GetTypeStatic", CollisionChain2D_GetTypeStatic},
{"CollisionChain2D_GetTypeNameStatic", CollisionChain2D_GetTypeNameStatic},
{"CollisionChain2D_CollisionChain2D", CollisionChain2D_CollisionChain2D},
{"CollisionChain2D_RegisterObject", CollisionChain2D_RegisterObject},
{"CollisionChain2D_SetLoop", CollisionChain2D_SetLoop},
{"CollisionChain2D_SetVertexCount", CollisionChain2D_SetVertexCount},
{"CollisionChain2D_SetVertex", CollisionChain2D_SetVertex},
{"CollisionChain2D_GetLoop", CollisionChain2D_GetLoop},
{"CollisionChain2D_GetVertexCount", CollisionChain2D_GetVertexCount},
{"CollisionChain2D_GetVertex", CollisionChain2D_GetVertex},
{"CollisionCircle2D_GetType", CollisionCircle2D_GetType},
{"CollisionCircle2D_GetTypeName", CollisionCircle2D_GetTypeName},
{"CollisionCircle2D_GetTypeStatic", CollisionCircle2D_GetTypeStatic},
{"CollisionCircle2D_GetTypeNameStatic", CollisionCircle2D_GetTypeNameStatic},
{"CollisionCircle2D_CollisionCircle2D", CollisionCircle2D_CollisionCircle2D},
{"CollisionCircle2D_RegisterObject", CollisionCircle2D_RegisterObject},
{"CollisionCircle2D_SetRadius", CollisionCircle2D_SetRadius},
{"CollisionCircle2D_SetCenter", CollisionCircle2D_SetCenter},
{"CollisionCircle2D_SetCenter0", CollisionCircle2D_SetCenter0},
{"CollisionCircle2D_GetRadius", CollisionCircle2D_GetRadius},
{"CollisionCircle2D_GetCenter", CollisionCircle2D_GetCenter},
{"CollisionEdge2D_GetType", CollisionEdge2D_GetType},
{"CollisionEdge2D_GetTypeName", CollisionEdge2D_GetTypeName},
{"CollisionEdge2D_GetTypeStatic", CollisionEdge2D_GetTypeStatic},
{"CollisionEdge2D_GetTypeNameStatic", CollisionEdge2D_GetTypeNameStatic},
{"CollisionEdge2D_CollisionEdge2D", CollisionEdge2D_CollisionEdge2D},
{"CollisionEdge2D_RegisterObject", CollisionEdge2D_RegisterObject},
{"CollisionEdge2D_SetVertex1", CollisionEdge2D_SetVertex1},
{"CollisionEdge2D_SetVertex2", CollisionEdge2D_SetVertex2},
{"CollisionEdge2D_SetVertices", CollisionEdge2D_SetVertices},
{"CollisionEdge2D_GetVertex1", CollisionEdge2D_GetVertex1},
{"CollisionEdge2D_GetVertex2", CollisionEdge2D_GetVertex2},
{"CollisionPolygon2D_GetType", CollisionPolygon2D_GetType},
{"CollisionPolygon2D_GetTypeName", CollisionPolygon2D_GetTypeName},
{"CollisionPolygon2D_GetTypeStatic", CollisionPolygon2D_GetTypeStatic},
{"CollisionPolygon2D_GetTypeNameStatic", CollisionPolygon2D_GetTypeNameStatic},
{"CollisionPolygon2D_CollisionPolygon2D", CollisionPolygon2D_CollisionPolygon2D},
{"CollisionPolygon2D_RegisterObject", CollisionPolygon2D_RegisterObject},
{"CollisionPolygon2D_SetVertexCount", CollisionPolygon2D_SetVertexCount},
{"CollisionPolygon2D_SetVertex", CollisionPolygon2D_SetVertex},
{"CollisionPolygon2D_GetVertexCount", CollisionPolygon2D_GetVertexCount},
{"CollisionPolygon2D_GetVertex", CollisionPolygon2D_GetVertex},
{"CollisionShape2D_GetType", CollisionShape2D_GetType},
{"CollisionShape2D_GetTypeName", CollisionShape2D_GetTypeName},
{"CollisionShape2D_GetTypeStatic", CollisionShape2D_GetTypeStatic},
{"CollisionShape2D_GetTypeNameStatic", CollisionShape2D_GetTypeNameStatic},
{"CollisionShape2D_RegisterObject", CollisionShape2D_RegisterObject},
{"CollisionShape2D_OnSetEnabled", CollisionShape2D_OnSetEnabled},
{"CollisionShape2D_SetTrigger", CollisionShape2D_SetTrigger},
{"CollisionShape2D_SetCategoryBits", CollisionShape2D_SetCategoryBits},
{"CollisionShape2D_SetMaskBits", CollisionShape2D_SetMaskBits},
{"CollisionShape2D_SetGroupIndex", CollisionShape2D_SetGroupIndex},
{"CollisionShape2D_SetDensity", CollisionShape2D_SetDensity},
{"CollisionShape2D_SetFriction", CollisionShape2D_SetFriction},
{"CollisionShape2D_SetRestitution", CollisionShape2D_SetRestitution},
{"CollisionShape2D_CreateFixture", CollisionShape2D_CreateFixture},
{"CollisionShape2D_ReleaseFixture", CollisionShape2D_ReleaseFixture},
{"CollisionShape2D_IsTrigger", CollisionShape2D_IsTrigger},
{"CollisionShape2D_GetCategoryBits", CollisionShape2D_GetCategoryBits},
{"CollisionShape2D_GetMaskBits", CollisionShape2D_GetMaskBits},
{"CollisionShape2D_GetGroupIndex", CollisionShape2D_GetGroupIndex},
{"CollisionShape2D_GetDensity", CollisionShape2D_GetDensity},
{"CollisionShape2D_GetFriction", CollisionShape2D_GetFriction},
{"CollisionShape2D_GetRestitution", CollisionShape2D_GetRestitution},
{"CollisionShape2D_GetMass", CollisionShape2D_GetMass},
{"CollisionShape2D_GetInertia", CollisionShape2D_GetInertia},
{"CollisionShape2D_GetMassCenter", CollisionShape2D_GetMassCenter},
{"Constraint2D_GetType", Constraint2D_GetType},
{"Constraint2D_GetTypeName", Constraint2D_GetTypeName},
{"Constraint2D_GetTypeStatic", Constraint2D_GetTypeStatic},
{"Constraint2D_GetTypeNameStatic", Constraint2D_GetTypeNameStatic},
{"Constraint2D_Constraint2D", Constraint2D_Constraint2D},
{"Constraint2D_RegisterObject", Constraint2D_RegisterObject},
{"Constraint2D_ApplyAttributes", Constraint2D_ApplyAttributes},
{"Constraint2D_OnSetEnabled", Constraint2D_OnSetEnabled},
{"Constraint2D_CreateJoint", Constraint2D_CreateJoint},
{"Constraint2D_ReleaseJoint", Constraint2D_ReleaseJoint},
{"Constraint2D_SetOtherBody", Constraint2D_SetOtherBody},
{"Constraint2D_SetCollideConnected", Constraint2D_SetCollideConnected},
{"Constraint2D_SetAttachedConstraint", Constraint2D_SetAttachedConstraint},
{"Constraint2D_GetOwnerBody", Constraint2D_GetOwnerBody},
{"Constraint2D_GetOtherBody", Constraint2D_GetOtherBody},
{"Constraint2D_GetCollideConnected", Constraint2D_GetCollideConnected},
{"Constraint2D_GetAttachedConstraint", Constraint2D_GetAttachedConstraint},
{"ConstraintDistance2D_GetType", ConstraintDistance2D_GetType},
{"ConstraintDistance2D_GetTypeName", ConstraintDistance2D_GetTypeName},
{"ConstraintDistance2D_GetTypeStatic", ConstraintDistance2D_GetTypeStatic},
{"ConstraintDistance2D_GetTypeNameStatic", ConstraintDistance2D_GetTypeNameStatic},
{"ConstraintDistance2D_ConstraintDistance2D", ConstraintDistance2D_ConstraintDistance2D},
{"ConstraintDistance2D_RegisterObject", ConstraintDistance2D_RegisterObject},
{"ConstraintDistance2D_SetOwnerBodyAnchor", ConstraintDistance2D_SetOwnerBodyAnchor},
{"ConstraintDistance2D_SetOtherBodyAnchor", ConstraintDistance2D_SetOtherBodyAnchor},
{"ConstraintDistance2D_SetFrequencyHz", ConstraintDistance2D_SetFrequencyHz},
{"ConstraintDistance2D_SetDampingRatio", ConstraintDistance2D_SetDampingRatio},
{"ConstraintDistance2D_SetLength", ConstraintDistance2D_SetLength},
{"ConstraintDistance2D_GetOwnerBodyAnchor", ConstraintDistance2D_GetOwnerBodyAnchor},
{"ConstraintDistance2D_GetOtherBodyAnchor", ConstraintDistance2D_GetOtherBodyAnchor},
{"ConstraintDistance2D_GetFrequencyHz", ConstraintDistance2D_GetFrequencyHz},
{"ConstraintDistance2D_GetDampingRatio", ConstraintDistance2D_GetDampingRatio},
{"ConstraintDistance2D_GetLength", ConstraintDistance2D_GetLength},
{"ConstraintFriction2D_GetType", ConstraintFriction2D_GetType},
{"ConstraintFriction2D_GetTypeName", ConstraintFriction2D_GetTypeName},
{"ConstraintFriction2D_GetTypeStatic", ConstraintFriction2D_GetTypeStatic},
{"ConstraintFriction2D_GetTypeNameStatic", ConstraintFriction2D_GetTypeNameStatic},
{"ConstraintFriction2D_ConstraintFriction2D", ConstraintFriction2D_ConstraintFriction2D},
{"ConstraintFriction2D_RegisterObject", ConstraintFriction2D_RegisterObject},
{"ConstraintFriction2D_SetAnchor", ConstraintFriction2D_SetAnchor},
{"ConstraintFriction2D_SetMaxForce", ConstraintFriction2D_SetMaxForce},
{"ConstraintFriction2D_SetMaxTorque", ConstraintFriction2D_SetMaxTorque},
{"ConstraintFriction2D_GetAnchor", ConstraintFriction2D_GetAnchor},
{"ConstraintFriction2D_GetMaxForce", ConstraintFriction2D_GetMaxForce},
{"ConstraintFriction2D_GetMaxTorque", ConstraintFriction2D_GetMaxTorque},
{"ConstraintGear2D_GetType", ConstraintGear2D_GetType},
{"ConstraintGear2D_GetTypeName", ConstraintGear2D_GetTypeName},
{"ConstraintGear2D_GetTypeStatic", ConstraintGear2D_GetTypeStatic},
{"ConstraintGear2D_GetTypeNameStatic", ConstraintGear2D_GetTypeNameStatic},
{"ConstraintGear2D_ConstraintGear2D", ConstraintGear2D_ConstraintGear2D},
{"ConstraintGear2D_RegisterObject", ConstraintGear2D_RegisterObject},
{"ConstraintGear2D_SetOwnerConstraint", ConstraintGear2D_SetOwnerConstraint},
{"ConstraintGear2D_SetOtherConstraint", ConstraintGear2D_SetOtherConstraint},
{"ConstraintGear2D_SetRatio", ConstraintGear2D_SetRatio},
{"ConstraintGear2D_GetOwnerConstraint", ConstraintGear2D_GetOwnerConstraint},
{"ConstraintGear2D_GetOtherConstraint", ConstraintGear2D_GetOtherConstraint},
{"ConstraintGear2D_GetRatio", ConstraintGear2D_GetRatio},
{"ConstraintMotor2D_GetType", ConstraintMotor2D_GetType},
{"ConstraintMotor2D_GetTypeName", ConstraintMotor2D_GetTypeName},
{"ConstraintMotor2D_GetTypeStatic", ConstraintMotor2D_GetTypeStatic},
{"ConstraintMotor2D_GetTypeNameStatic", ConstraintMotor2D_GetTypeNameStatic},
{"ConstraintMotor2D_ConstraintMotor2D", ConstraintMotor2D_ConstraintMotor2D},
{"ConstraintMotor2D_RegisterObject", ConstraintMotor2D_RegisterObject},
{"ConstraintMotor2D_SetLinearOffset", ConstraintMotor2D_SetLinearOffset},
{"ConstraintMotor2D_SetAngularOffset", ConstraintMotor2D_SetAngularOffset},
{"ConstraintMotor2D_SetMaxForce", ConstraintMotor2D_SetMaxForce},
{"ConstraintMotor2D_SetMaxTorque", ConstraintMotor2D_SetMaxTorque},
{"ConstraintMotor2D_SetCorrectionFactor", ConstraintMotor2D_SetCorrectionFactor},
{"ConstraintMotor2D_GetLinearOffset", ConstraintMotor2D_GetLinearOffset},
{"ConstraintMotor2D_GetAngularOffset", ConstraintMotor2D_GetAngularOffset},
{"ConstraintMotor2D_GetMaxForce", ConstraintMotor2D_GetMaxForce},
{"ConstraintMotor2D_GetMaxTorque", ConstraintMotor2D_GetMaxTorque},
{"ConstraintMotor2D_GetCorrectionFactor", ConstraintMotor2D_GetCorrectionFactor},
{"ConstraintMouse2D_GetType", ConstraintMouse2D_GetType},
{"ConstraintMouse2D_GetTypeName", ConstraintMouse2D_GetTypeName},
{"ConstraintMouse2D_GetTypeStatic", ConstraintMouse2D_GetTypeStatic},
{"ConstraintMouse2D_GetTypeNameStatic", ConstraintMouse2D_GetTypeNameStatic},
{"ConstraintMouse2D_ConstraintMouse2D", ConstraintMouse2D_ConstraintMouse2D},
{"ConstraintMouse2D_RegisterObject", ConstraintMouse2D_RegisterObject},
{"ConstraintMouse2D_SetTarget", ConstraintMouse2D_SetTarget},
{"ConstraintMouse2D_SetMaxForce", ConstraintMouse2D_SetMaxForce},
{"ConstraintMouse2D_SetFrequencyHz", ConstraintMouse2D_SetFrequencyHz},
{"ConstraintMouse2D_SetDampingRatio", ConstraintMouse2D_SetDampingRatio},
{"ConstraintMouse2D_GetTarget", ConstraintMouse2D_GetTarget},
{"ConstraintMouse2D_GetMaxForce", ConstraintMouse2D_GetMaxForce},
{"ConstraintMouse2D_GetFrequencyHz", ConstraintMouse2D_GetFrequencyHz},
{"ConstraintMouse2D_GetDampingRatio", ConstraintMouse2D_GetDampingRatio},
{"ConstraintPrismatic2D_GetType", ConstraintPrismatic2D_GetType},
{"ConstraintPrismatic2D_GetTypeName", ConstraintPrismatic2D_GetTypeName},
{"ConstraintPrismatic2D_GetTypeStatic", ConstraintPrismatic2D_GetTypeStatic},
{"ConstraintPrismatic2D_GetTypeNameStatic", ConstraintPrismatic2D_GetTypeNameStatic},
{"ConstraintPrismatic2D_ConstraintPrismatic2D", ConstraintPrismatic2D_ConstraintPrismatic2D},
{"ConstraintPrismatic2D_RegisterObject", ConstraintPrismatic2D_RegisterObject},
{"ConstraintPrismatic2D_SetAnchor", ConstraintPrismatic2D_SetAnchor},
{"ConstraintPrismatic2D_SetAxis", ConstraintPrismatic2D_SetAxis},
{"ConstraintPrismatic2D_SetEnableLimit", ConstraintPrismatic2D_SetEnableLimit},
{"ConstraintPrismatic2D_SetLowerTranslation", ConstraintPrismatic2D_SetLowerTranslation},
{"ConstraintPrismatic2D_SetUpperTranslation", ConstraintPrismatic2D_SetUpperTranslation},
{"ConstraintPrismatic2D_SetEnableMotor", ConstraintPrismatic2D_SetEnableMotor},
{"ConstraintPrismatic2D_SetMaxMotorForce", ConstraintPrismatic2D_SetMaxMotorForce},
{"ConstraintPrismatic2D_SetMotorSpeed", ConstraintPrismatic2D_SetMotorSpeed},
{"ConstraintPrismatic2D_GetAnchor", ConstraintPrismatic2D_GetAnchor},
{"ConstraintPrismatic2D_GetAxis", ConstraintPrismatic2D_GetAxis},
{"ConstraintPrismatic2D_GetEnableLimit", ConstraintPrismatic2D_GetEnableLimit},
{"ConstraintPrismatic2D_GetLowerTranslation", ConstraintPrismatic2D_GetLowerTranslation},
{"ConstraintPrismatic2D_GetUpperTranslation", ConstraintPrismatic2D_GetUpperTranslation},
{"ConstraintPrismatic2D_GetEnableMotor", ConstraintPrismatic2D_GetEnableMotor},
{"ConstraintPrismatic2D_GetMaxMotorForce", ConstraintPrismatic2D_GetMaxMotorForce},
{"ConstraintPrismatic2D_GetMotorSpeed", ConstraintPrismatic2D_GetMotorSpeed},
{"ConstraintPulley2D_GetType", ConstraintPulley2D_GetType},
{"ConstraintPulley2D_GetTypeName", ConstraintPulley2D_GetTypeName},
{"ConstraintPulley2D_GetTypeStatic", ConstraintPulley2D_GetTypeStatic},
{"ConstraintPulley2D_GetTypeNameStatic", ConstraintPulley2D_GetTypeNameStatic},
{"ConstraintPulley2D_ConstraintPulley2D", ConstraintPulley2D_ConstraintPulley2D},
{"ConstraintPulley2D_RegisterObject", ConstraintPulley2D_RegisterObject},
{"ConstraintPulley2D_SetOwnerBodyGroundAnchor", ConstraintPulley2D_SetOwnerBodyGroundAnchor},
{"ConstraintPulley2D_SetOtherBodyGroundAnchor", ConstraintPulley2D_SetOtherBodyGroundAnchor},
{"ConstraintPulley2D_SetOwnerBodyAnchor", ConstraintPulley2D_SetOwnerBodyAnchor},
{"ConstraintPulley2D_SetOtherBodyAnchor", ConstraintPulley2D_SetOtherBodyAnchor},
{"ConstraintPulley2D_SetRatio", ConstraintPulley2D_SetRatio},
{"ConstraintPulley2D_GetOwnerBodyGroundAnchor", ConstraintPulley2D_GetOwnerBodyGroundAnchor},
{"ConstraintPulley2D_GetOtherBodyGroundAnchor", ConstraintPulley2D_GetOtherBodyGroundAnchor},
{"ConstraintPulley2D_GetOwnerBodyAnchor", ConstraintPulley2D_GetOwnerBodyAnchor},
{"ConstraintPulley2D_GetOtherBodyAnchor", ConstraintPulley2D_GetOtherBodyAnchor},
{"ConstraintPulley2D_GetRatio", ConstraintPulley2D_GetRatio},
{"ConstraintRevolute2D_GetType", ConstraintRevolute2D_GetType},
{"ConstraintRevolute2D_GetTypeName", ConstraintRevolute2D_GetTypeName},
{"ConstraintRevolute2D_GetTypeStatic", ConstraintRevolute2D_GetTypeStatic},
{"ConstraintRevolute2D_GetTypeNameStatic", ConstraintRevolute2D_GetTypeNameStatic},
{"ConstraintRevolute2D_ConstraintRevolute2D", ConstraintRevolute2D_ConstraintRevolute2D},
{"ConstraintRevolute2D_RegisterObject", ConstraintRevolute2D_RegisterObject},
{"ConstraintRevolute2D_SetAnchor", ConstraintRevolute2D_SetAnchor},
{"ConstraintRevolute2D_SetEnableLimit", ConstraintRevolute2D_SetEnableLimit},
{"ConstraintRevolute2D_SetLowerAngle", ConstraintRevolute2D_SetLowerAngle},
{"ConstraintRevolute2D_SetUpperAngle", ConstraintRevolute2D_SetUpperAngle},
{"ConstraintRevolute2D_SetEnableMotor", ConstraintRevolute2D_SetEnableMotor},
{"ConstraintRevolute2D_SetMotorSpeed", ConstraintRevolute2D_SetMotorSpeed},
{"ConstraintRevolute2D_SetMaxMotorTorque", ConstraintRevolute2D_SetMaxMotorTorque},
{"ConstraintRevolute2D_GetAnchor", ConstraintRevolute2D_GetAnchor},
{"ConstraintRevolute2D_GetEnableLimit", ConstraintRevolute2D_GetEnableLimit},
{"ConstraintRevolute2D_GetLowerAngle", ConstraintRevolute2D_GetLowerAngle},
{"ConstraintRevolute2D_GetUpperAngle", ConstraintRevolute2D_GetUpperAngle},
{"ConstraintRevolute2D_GetEnableMotor", ConstraintRevolute2D_GetEnableMotor},
{"ConstraintRevolute2D_GetMotorSpeed", ConstraintRevolute2D_GetMotorSpeed},
{"ConstraintRevolute2D_GetMaxMotorTorque", ConstraintRevolute2D_GetMaxMotorTorque},
{"ConstraintRope2D_GetType", ConstraintRope2D_GetType},
{"ConstraintRope2D_GetTypeName", ConstraintRope2D_GetTypeName},
{"ConstraintRope2D_GetTypeStatic", ConstraintRope2D_GetTypeStatic},
{"ConstraintRope2D_GetTypeNameStatic", ConstraintRope2D_GetTypeNameStatic},
{"ConstraintRope2D_ConstraintRope2D", ConstraintRope2D_ConstraintRope2D},
{"ConstraintRope2D_RegisterObject", ConstraintRope2D_RegisterObject},
{"ConstraintRope2D_SetOwnerBodyAnchor", ConstraintRope2D_SetOwnerBodyAnchor},
{"ConstraintRope2D_SetOtherBodyAnchor", ConstraintRope2D_SetOtherBodyAnchor},
{"ConstraintRope2D_SetMaxLength", ConstraintRope2D_SetMaxLength},
{"ConstraintRope2D_GetOwnerBodyAnchor", ConstraintRope2D_GetOwnerBodyAnchor},
{"ConstraintRope2D_GetOtherBodyAnchor", ConstraintRope2D_GetOtherBodyAnchor},
{"ConstraintRope2D_GetMaxLength", ConstraintRope2D_GetMaxLength},
{"ConstraintWeld2D_GetType", ConstraintWeld2D_GetType},
{"ConstraintWeld2D_GetTypeName", ConstraintWeld2D_GetTypeName},
{"ConstraintWeld2D_GetTypeStatic", ConstraintWeld2D_GetTypeStatic},
{"ConstraintWeld2D_GetTypeNameStatic", ConstraintWeld2D_GetTypeNameStatic},
{"ConstraintWeld2D_ConstraintWeld2D", ConstraintWeld2D_ConstraintWeld2D},
{"ConstraintWeld2D_RegisterObject", ConstraintWeld2D_RegisterObject},
{"ConstraintWeld2D_SetAnchor", ConstraintWeld2D_SetAnchor},
{"ConstraintWeld2D_SetFrequencyHz", ConstraintWeld2D_SetFrequencyHz},
{"ConstraintWeld2D_SetDampingRatio", ConstraintWeld2D_SetDampingRatio},
{"ConstraintWeld2D_GetAnchor", ConstraintWeld2D_GetAnchor},
{"ConstraintWeld2D_GetFrequencyHz", ConstraintWeld2D_GetFrequencyHz},
{"ConstraintWeld2D_GetDampingRatio", ConstraintWeld2D_GetDampingRatio},
{"ConstraintWheel2D_GetType", ConstraintWheel2D_GetType},
{"ConstraintWheel2D_GetTypeName", ConstraintWheel2D_GetTypeName},
{"ConstraintWheel2D_GetTypeStatic", ConstraintWheel2D_GetTypeStatic},
{"ConstraintWheel2D_GetTypeNameStatic", ConstraintWheel2D_GetTypeNameStatic},
{"ConstraintWheel2D_ConstraintWheel2D", ConstraintWheel2D_ConstraintWheel2D},
{"ConstraintWheel2D_RegisterObject", ConstraintWheel2D_RegisterObject},
{"ConstraintWheel2D_SetAnchor", ConstraintWheel2D_SetAnchor},
{"ConstraintWheel2D_SetAxis", ConstraintWheel2D_SetAxis},
{"ConstraintWheel2D_SetEnableMotor", ConstraintWheel2D_SetEnableMotor},
{"ConstraintWheel2D_SetMaxMotorTorque", ConstraintWheel2D_SetMaxMotorTorque},
{"ConstraintWheel2D_SetMotorSpeed", ConstraintWheel2D_SetMotorSpeed},
{"ConstraintWheel2D_SetFrequencyHz", ConstraintWheel2D_SetFrequencyHz},
{"ConstraintWheel2D_SetDampingRatio", ConstraintWheel2D_SetDampingRatio},
{"ConstraintWheel2D_GetAnchor", ConstraintWheel2D_GetAnchor},
{"ConstraintWheel2D_GetAxis", ConstraintWheel2D_GetAxis},
{"ConstraintWheel2D_GetEnableMotor", ConstraintWheel2D_GetEnableMotor},
{"ConstraintWheel2D_GetMaxMotorTorque", ConstraintWheel2D_GetMaxMotorTorque},
{"ConstraintWheel2D_GetMotorSpeed", ConstraintWheel2D_GetMotorSpeed},
{"ConstraintWheel2D_GetFrequencyHz", ConstraintWheel2D_GetFrequencyHz},
{"ConstraintWheel2D_GetDampingRatio", ConstraintWheel2D_GetDampingRatio},
{"ParticleEffect2D_GetType", ParticleEffect2D_GetType},
{"ParticleEffect2D_GetTypeName", ParticleEffect2D_GetTypeName},
{"ParticleEffect2D_GetTypeStatic", ParticleEffect2D_GetTypeStatic},
{"ParticleEffect2D_GetTypeNameStatic", ParticleEffect2D_GetTypeNameStatic},
{"ParticleEffect2D_ParticleEffect2D", ParticleEffect2D_ParticleEffect2D},
{"ParticleEffect2D_RegisterObject", ParticleEffect2D_RegisterObject},
{"ParticleEffect2D_BeginLoad_File", ParticleEffect2D_BeginLoad_File},
{"ParticleEffect2D_BeginLoad_MemoryBuffer", ParticleEffect2D_BeginLoad_MemoryBuffer},
{"ParticleEffect2D_EndLoad", ParticleEffect2D_EndLoad},
{"ParticleEffect2D_Save_File", ParticleEffect2D_Save_File},
{"ParticleEffect2D_Save_MemoryBuffer", ParticleEffect2D_Save_MemoryBuffer},
{"ParticleEffect2D_SetSprite", ParticleEffect2D_SetSprite},
{"ParticleEffect2D_SetSourcePositionVariance", ParticleEffect2D_SetSourcePositionVariance},
{"ParticleEffect2D_SetSpeed", ParticleEffect2D_SetSpeed},
{"ParticleEffect2D_SetSpeedVariance", ParticleEffect2D_SetSpeedVariance},
{"ParticleEffect2D_SetParticleLifeSpan", ParticleEffect2D_SetParticleLifeSpan},
{"ParticleEffect2D_SetParticleLifespanVariance", ParticleEffect2D_SetParticleLifespanVariance},
{"ParticleEffect2D_SetAngle", ParticleEffect2D_SetAngle},
{"ParticleEffect2D_SetAngleVariance", ParticleEffect2D_SetAngleVariance},
{"ParticleEffect2D_SetGravity", ParticleEffect2D_SetGravity},
{"ParticleEffect2D_SetRadialAcceleration", ParticleEffect2D_SetRadialAcceleration},
{"ParticleEffect2D_SetTangentialAcceleration", ParticleEffect2D_SetTangentialAcceleration},
{"ParticleEffect2D_SetRadialAccelVariance", ParticleEffect2D_SetRadialAccelVariance},
{"ParticleEffect2D_SetTangentialAccelVariance", ParticleEffect2D_SetTangentialAccelVariance},
{"ParticleEffect2D_SetStartColor", ParticleEffect2D_SetStartColor},
{"ParticleEffect2D_SetStartColorVariance", ParticleEffect2D_SetStartColorVariance},
{"ParticleEffect2D_SetFinishColor", ParticleEffect2D_SetFinishColor},
{"ParticleEffect2D_SetFinishColorVariance", ParticleEffect2D_SetFinishColorVariance},
{"ParticleEffect2D_SetMaxParticles", ParticleEffect2D_SetMaxParticles},
{"ParticleEffect2D_SetStartParticleSize", ParticleEffect2D_SetStartParticleSize},
{"ParticleEffect2D_SetStartParticleSizeVariance", ParticleEffect2D_SetStartParticleSizeVariance},
{"ParticleEffect2D_SetFinishParticleSize", ParticleEffect2D_SetFinishParticleSize},
{"ParticleEffect2D_SetFinishParticleSizeVariance", ParticleEffect2D_SetFinishParticleSizeVariance},
{"ParticleEffect2D_SetDuration", ParticleEffect2D_SetDuration},
{"ParticleEffect2D_SetEmitterType", ParticleEffect2D_SetEmitterType},
{"ParticleEffect2D_SetMaxRadius", ParticleEffect2D_SetMaxRadius},
{"ParticleEffect2D_SetMaxRadiusVariance", ParticleEffect2D_SetMaxRadiusVariance},
{"ParticleEffect2D_SetMinRadius", ParticleEffect2D_SetMinRadius},
{"ParticleEffect2D_SetMinRadiusVariance", ParticleEffect2D_SetMinRadiusVariance},
{"ParticleEffect2D_SetRotatePerSecond", ParticleEffect2D_SetRotatePerSecond},
{"ParticleEffect2D_SetRotatePerSecondVariance", ParticleEffect2D_SetRotatePerSecondVariance},
{"ParticleEffect2D_SetBlendMode", ParticleEffect2D_SetBlendMode},
{"ParticleEffect2D_SetRotationStart", ParticleEffect2D_SetRotationStart},
{"ParticleEffect2D_SetRotationStartVariance", ParticleEffect2D_SetRotationStartVariance},
{"ParticleEffect2D_SetRotationEnd", ParticleEffect2D_SetRotationEnd},
{"ParticleEffect2D_SetRotationEndVariance", ParticleEffect2D_SetRotationEndVariance},
{"ParticleEffect2D_Clone", ParticleEffect2D_Clone},
{"ParticleEffect2D_GetSprite", ParticleEffect2D_GetSprite},
{"ParticleEffect2D_GetSourcePositionVariance", ParticleEffect2D_GetSourcePositionVariance},
{"ParticleEffect2D_GetSpeed", ParticleEffect2D_GetSpeed},
{"ParticleEffect2D_GetSpeedVariance", ParticleEffect2D_GetSpeedVariance},
{"ParticleEffect2D_GetParticleLifeSpan", ParticleEffect2D_GetParticleLifeSpan},
{"ParticleEffect2D_GetParticleLifespanVariance", ParticleEffect2D_GetParticleLifespanVariance},
{"ParticleEffect2D_GetAngle", ParticleEffect2D_GetAngle},
{"ParticleEffect2D_GetAngleVariance", ParticleEffect2D_GetAngleVariance},
{"ParticleEffect2D_GetGravity", ParticleEffect2D_GetGravity},
{"ParticleEffect2D_GetRadialAcceleration", ParticleEffect2D_GetRadialAcceleration},
{"ParticleEffect2D_GetTangentialAcceleration", ParticleEffect2D_GetTangentialAcceleration},
{"ParticleEffect2D_GetRadialAccelVariance", ParticleEffect2D_GetRadialAccelVariance},
{"ParticleEffect2D_GetTangentialAccelVariance", ParticleEffect2D_GetTangentialAccelVariance},
{"ParticleEffect2D_GetStartColor", ParticleEffect2D_GetStartColor},
{"ParticleEffect2D_GetStartColorVariance", ParticleEffect2D_GetStartColorVariance},
{"ParticleEffect2D_GetFinishColor", ParticleEffect2D_GetFinishColor},
{"ParticleEffect2D_GetFinishColorVariance", ParticleEffect2D_GetFinishColorVariance},
{"ParticleEffect2D_GetMaxParticles", ParticleEffect2D_GetMaxParticles},
{"ParticleEffect2D_GetStartParticleSize", ParticleEffect2D_GetStartParticleSize},
{"ParticleEffect2D_GetStartParticleSizeVariance", ParticleEffect2D_GetStartParticleSizeVariance},
{"ParticleEffect2D_GetFinishParticleSize", ParticleEffect2D_GetFinishParticleSize},
{"ParticleEffect2D_GetFinishParticleSizeVariance", ParticleEffect2D_GetFinishParticleSizeVariance},
{"ParticleEffect2D_GetDuration", ParticleEffect2D_GetDuration},
{"ParticleEffect2D_GetEmitterType", ParticleEffect2D_GetEmitterType},
{"ParticleEffect2D_GetMaxRadius", ParticleEffect2D_GetMaxRadius},
{"ParticleEffect2D_GetMaxRadiusVariance", ParticleEffect2D_GetMaxRadiusVariance},
{"ParticleEffect2D_GetMinRadius", ParticleEffect2D_GetMinRadius},
{"ParticleEffect2D_GetMinRadiusVariance", ParticleEffect2D_GetMinRadiusVariance},
{"ParticleEffect2D_GetRotatePerSecond", ParticleEffect2D_GetRotatePerSecond},
{"ParticleEffect2D_GetRotatePerSecondVariance", ParticleEffect2D_GetRotatePerSecondVariance},
{"ParticleEffect2D_GetBlendMode", ParticleEffect2D_GetBlendMode},
{"ParticleEffect2D_GetRotationStart", ParticleEffect2D_GetRotationStart},
{"ParticleEffect2D_GetRotationStartVariance", ParticleEffect2D_GetRotationStartVariance},
{"ParticleEffect2D_GetRotationEnd", ParticleEffect2D_GetRotationEnd},
{"ParticleEffect2D_GetRotationEndVariance", ParticleEffect2D_GetRotationEndVariance},
{"ParticleEmitter2D_GetType", ParticleEmitter2D_GetType},
{"ParticleEmitter2D_GetTypeName", ParticleEmitter2D_GetTypeName},
{"ParticleEmitter2D_GetTypeStatic", ParticleEmitter2D_GetTypeStatic},
{"ParticleEmitter2D_GetTypeNameStatic", ParticleEmitter2D_GetTypeNameStatic},
{"ParticleEmitter2D_ParticleEmitter2D", ParticleEmitter2D_ParticleEmitter2D},
{"ParticleEmitter2D_RegisterObject", ParticleEmitter2D_RegisterObject},
{"ParticleEmitter2D_OnSetEnabled", ParticleEmitter2D_OnSetEnabled},
{"ParticleEmitter2D_SetEffect", ParticleEmitter2D_SetEffect},
{"ParticleEmitter2D_SetSprite", ParticleEmitter2D_SetSprite},
{"ParticleEmitter2D_SetBlendMode", ParticleEmitter2D_SetBlendMode},
{"ParticleEmitter2D_SetMaxParticles", ParticleEmitter2D_SetMaxParticles},
{"ParticleEmitter2D_SetEmitting", ParticleEmitter2D_SetEmitting},
{"ParticleEmitter2D_GetEffect", ParticleEmitter2D_GetEffect},
{"ParticleEmitter2D_GetSprite", ParticleEmitter2D_GetSprite},
{"ParticleEmitter2D_GetBlendMode", ParticleEmitter2D_GetBlendMode},
{"ParticleEmitter2D_GetMaxParticles", ParticleEmitter2D_GetMaxParticles},
{"ParticleEmitter2D_GetParticleEffectAttr", ParticleEmitter2D_GetParticleEffectAttr},
{"ParticleEmitter2D_GetSpriteAttr", ParticleEmitter2D_GetSpriteAttr},
{"ParticleEmitter2D_IsEmitting", ParticleEmitter2D_IsEmitting},
{"PropertySet2D_PropertySet2D", PropertySet2D_PropertySet2D},
{"PropertySet2D_Load", PropertySet2D_Load},
{"PropertySet2D_HasProperty", PropertySet2D_HasProperty},
{"PropertySet2D_GetProperty", PropertySet2D_GetProperty},
{"Renderer2D_GetType", Renderer2D_GetType},
{"Renderer2D_GetTypeName", Renderer2D_GetTypeName},
{"Renderer2D_GetTypeStatic", Renderer2D_GetTypeStatic},
{"Renderer2D_GetTypeNameStatic", Renderer2D_GetTypeNameStatic},
{"Renderer2D_Renderer2D", Renderer2D_Renderer2D},
{"Renderer2D_RegisterObject", Renderer2D_RegisterObject},
{"Renderer2D_GetUpdateGeometryType", Renderer2D_GetUpdateGeometryType},
{"Renderer2D_AddDrawable", Renderer2D_AddDrawable},
{"Renderer2D_RemoveDrawable", Renderer2D_RemoveDrawable},
{"Renderer2D_GetMaterial", Renderer2D_GetMaterial},
{"Renderer2D_CheckVisibility", Renderer2D_CheckVisibility},
{"RigidBody2D_GetType", RigidBody2D_GetType},
{"RigidBody2D_GetTypeName", RigidBody2D_GetTypeName},
{"RigidBody2D_GetTypeStatic", RigidBody2D_GetTypeStatic},
{"RigidBody2D_GetTypeNameStatic", RigidBody2D_GetTypeNameStatic},
{"RigidBody2D_RigidBody2D", RigidBody2D_RigidBody2D},
{"RigidBody2D_RegisterObject", RigidBody2D_RegisterObject},
{"RigidBody2D_OnSetEnabled", RigidBody2D_OnSetEnabled},
{"RigidBody2D_SetBodyType", RigidBody2D_SetBodyType},
{"RigidBody2D_SetMass", RigidBody2D_SetMass},
{"RigidBody2D_SetInertia", RigidBody2D_SetInertia},
{"RigidBody2D_SetMassCenter", RigidBody2D_SetMassCenter},
{"RigidBody2D_SetUseFixtureMass", RigidBody2D_SetUseFixtureMass},
{"RigidBody2D_SetLinearDamping", RigidBody2D_SetLinearDamping},
{"RigidBody2D_SetAngularDamping", RigidBody2D_SetAngularDamping},
{"RigidBody2D_SetAllowSleep", RigidBody2D_SetAllowSleep},
{"RigidBody2D_SetFixedRotation", RigidBody2D_SetFixedRotation},
{"RigidBody2D_SetBullet", RigidBody2D_SetBullet},
{"RigidBody2D_SetGravityScale", RigidBody2D_SetGravityScale},
{"RigidBody2D_SetAwake", RigidBody2D_SetAwake},
{"RigidBody2D_SetLinearVelocity", RigidBody2D_SetLinearVelocity},
{"RigidBody2D_SetAngularVelocity", RigidBody2D_SetAngularVelocity},
{"RigidBody2D_ApplyForce", RigidBody2D_ApplyForce},
{"RigidBody2D_ApplyForceToCenter", RigidBody2D_ApplyForceToCenter},
{"RigidBody2D_ApplyTorque", RigidBody2D_ApplyTorque},
{"RigidBody2D_ApplyLinearImpulse", RigidBody2D_ApplyLinearImpulse},
{"RigidBody2D_ApplyLinearImpulseToCenter", RigidBody2D_ApplyLinearImpulseToCenter},
{"RigidBody2D_ApplyAngularImpulse", RigidBody2D_ApplyAngularImpulse},
{"RigidBody2D_CreateBody", RigidBody2D_CreateBody},
{"RigidBody2D_ReleaseBody", RigidBody2D_ReleaseBody},
{"RigidBody2D_ApplyWorldTransform", RigidBody2D_ApplyWorldTransform},
{"RigidBody2D_ApplyWorldTransform0", RigidBody2D_ApplyWorldTransform0},
{"RigidBody2D_AddCollisionShape2D", RigidBody2D_AddCollisionShape2D},
{"RigidBody2D_RemoveCollisionShape2D", RigidBody2D_RemoveCollisionShape2D},
{"RigidBody2D_AddConstraint2D", RigidBody2D_AddConstraint2D},
{"RigidBody2D_RemoveConstraint2D", RigidBody2D_RemoveConstraint2D},
{"RigidBody2D_GetBodyType", RigidBody2D_GetBodyType},
{"RigidBody2D_GetMass", RigidBody2D_GetMass},
{"RigidBody2D_GetInertia", RigidBody2D_GetInertia},
{"RigidBody2D_GetMassCenter", RigidBody2D_GetMassCenter},
{"RigidBody2D_GetUseFixtureMass", RigidBody2D_GetUseFixtureMass},
{"RigidBody2D_GetLinearDamping", RigidBody2D_GetLinearDamping},
{"RigidBody2D_GetAngularDamping", RigidBody2D_GetAngularDamping},
{"RigidBody2D_IsAllowSleep", RigidBody2D_IsAllowSleep},
{"RigidBody2D_IsFixedRotation", RigidBody2D_IsFixedRotation},
{"RigidBody2D_IsBullet", RigidBody2D_IsBullet},
{"RigidBody2D_GetGravityScale", RigidBody2D_GetGravityScale},
{"RigidBody2D_IsAwake", RigidBody2D_IsAwake},
{"RigidBody2D_GetLinearVelocity", RigidBody2D_GetLinearVelocity},
{"RigidBody2D_GetAngularVelocity", RigidBody2D_GetAngularVelocity},
{"Sprite2D_GetType", Sprite2D_GetType},
{"Sprite2D_GetTypeName", Sprite2D_GetTypeName},
{"Sprite2D_GetTypeStatic", Sprite2D_GetTypeStatic},
{"Sprite2D_GetTypeNameStatic", Sprite2D_GetTypeNameStatic},
{"Sprite2D_Sprite2D", Sprite2D_Sprite2D},
{"Sprite2D_RegisterObject", Sprite2D_RegisterObject},
{"Sprite2D_BeginLoad_File", Sprite2D_BeginLoad_File},
{"Sprite2D_BeginLoad_MemoryBuffer", Sprite2D_BeginLoad_MemoryBuffer},
{"Sprite2D_EndLoad", Sprite2D_EndLoad},
{"Sprite2D_SetTexture", Sprite2D_SetTexture},
{"Sprite2D_SetRectangle", Sprite2D_SetRectangle},
{"Sprite2D_SetHotSpot", Sprite2D_SetHotSpot},
{"Sprite2D_SetOffset", Sprite2D_SetOffset},
{"Sprite2D_SetTextureEdgeOffset", Sprite2D_SetTextureEdgeOffset},
{"Sprite2D_SetSpriteSheet", Sprite2D_SetSpriteSheet},
{"Sprite2D_GetTexture", Sprite2D_GetTexture},
{"Sprite2D_GetRectangle", Sprite2D_GetRectangle},
{"Sprite2D_GetHotSpot", Sprite2D_GetHotSpot},
{"Sprite2D_GetOffset", Sprite2D_GetOffset},
{"Sprite2D_GetTextureEdgeOffset", Sprite2D_GetTextureEdgeOffset},
{"Sprite2D_GetSpriteSheet", Sprite2D_GetSpriteSheet},
{"Sprite2D_SaveToResourceRef", Sprite2D_SaveToResourceRef},
{"SpriteSheet2D_GetType", SpriteSheet2D_GetType},
{"SpriteSheet2D_GetTypeName", SpriteSheet2D_GetTypeName},
{"SpriteSheet2D_GetTypeStatic", SpriteSheet2D_GetTypeStatic},
{"SpriteSheet2D_GetTypeNameStatic", SpriteSheet2D_GetTypeNameStatic},
{"SpriteSheet2D_SpriteSheet2D", SpriteSheet2D_SpriteSheet2D},
{"SpriteSheet2D_RegisterObject", SpriteSheet2D_RegisterObject},
{"SpriteSheet2D_BeginLoad_File", SpriteSheet2D_BeginLoad_File},
{"SpriteSheet2D_BeginLoad_MemoryBuffer", SpriteSheet2D_BeginLoad_MemoryBuffer},
{"SpriteSheet2D_EndLoad", SpriteSheet2D_EndLoad},
{"SpriteSheet2D_SetTexture", SpriteSheet2D_SetTexture},
{"SpriteSheet2D_DefineSprite", SpriteSheet2D_DefineSprite},
{"SpriteSheet2D_GetTexture", SpriteSheet2D_GetTexture},
{"SpriteSheet2D_GetSprite", SpriteSheet2D_GetSprite},
{"Tile2D_Tile2D", Tile2D_Tile2D},
{"Tile2D_GetGid", Tile2D_GetGid},
{"Tile2D_GetFlipX", Tile2D_GetFlipX},
{"Tile2D_GetFlipY", Tile2D_GetFlipY},
{"Tile2D_GetSwapXY", Tile2D_GetSwapXY},
{"Tile2D_GetSprite", Tile2D_GetSprite},
{"Tile2D_HasProperty", Tile2D_HasProperty},
{"Tile2D_GetProperty", Tile2D_GetProperty},
{"TileMap2D_GetType", TileMap2D_GetType},
{"TileMap2D_GetTypeName", TileMap2D_GetTypeName},
{"TileMap2D_GetTypeStatic", TileMap2D_GetTypeStatic},
{"TileMap2D_GetTypeNameStatic", TileMap2D_GetTypeNameStatic},
{"TileMap2D_TileMap2D", TileMap2D_TileMap2D},
{"TileMap2D_RegisterObject", TileMap2D_RegisterObject},
{"TileMap2D_DrawDebugGeometry", TileMap2D_DrawDebugGeometry},
{"TileMap2D_SetTmxFile", TileMap2D_SetTmxFile},
{"TileMap2D_DrawDebugGeometry0", TileMap2D_DrawDebugGeometry0},
{"TileMap2D_GetTmxFile", TileMap2D_GetTmxFile},
{"TileMap2D_GetInfo", TileMap2D_GetInfo},
{"TileMap2D_GetNumLayers", TileMap2D_GetNumLayers},
{"TileMap2D_GetLayer", TileMap2D_GetLayer},
{"TileMap2D_TileIndexToPosition", TileMap2D_TileIndexToPosition},
{"TileMap2D_PositionToTileIndex", TileMap2D_PositionToTileIndex},
{"TileMap2D_GetTmxFileAttr", TileMap2D_GetTmxFileAttr},
{"TileMapLayer2D_GetType", TileMapLayer2D_GetType},
{"TileMapLayer2D_GetTypeName", TileMapLayer2D_GetTypeName},
{"TileMapLayer2D_GetTypeStatic", TileMapLayer2D_GetTypeStatic},
{"TileMapLayer2D_GetTypeNameStatic", TileMapLayer2D_GetTypeNameStatic},
{"TileMapLayer2D_TileMapLayer2D", TileMapLayer2D_TileMapLayer2D},
{"TileMapLayer2D_RegisterObject", TileMapLayer2D_RegisterObject},
{"TileMapLayer2D_DrawDebugGeometry", TileMapLayer2D_DrawDebugGeometry},
{"TileMapLayer2D_Initialize", TileMapLayer2D_Initialize},
{"TileMapLayer2D_SetDrawOrder", TileMapLayer2D_SetDrawOrder},
{"TileMapLayer2D_SetVisible", TileMapLayer2D_SetVisible},
{"TileMapLayer2D_GetTileMap", TileMapLayer2D_GetTileMap},
{"TileMapLayer2D_GetTmxLayer", TileMapLayer2D_GetTmxLayer},
{"TileMapLayer2D_GetDrawOrder", TileMapLayer2D_GetDrawOrder},
{"TileMapLayer2D_IsVisible", TileMapLayer2D_IsVisible},
{"TileMapLayer2D_HasProperty", TileMapLayer2D_HasProperty},
{"TileMapLayer2D_GetProperty", TileMapLayer2D_GetProperty},
{"TileMapLayer2D_GetLayerType", TileMapLayer2D_GetLayerType},
{"TileMapLayer2D_GetWidth", TileMapLayer2D_GetWidth},
{"TileMapLayer2D_GetHeight", TileMapLayer2D_GetHeight},
{"TileMapLayer2D_GetTileNode", TileMapLayer2D_GetTileNode},
{"TileMapLayer2D_GetTile", TileMapLayer2D_GetTile},
{"TileMapLayer2D_GetNumObjects", TileMapLayer2D_GetNumObjects},
{"TileMapLayer2D_GetObject", TileMapLayer2D_GetObject},
{"TileMapLayer2D_GetObjectNode", TileMapLayer2D_GetObjectNode},
{"TileMapLayer2D_GetImageNode", TileMapLayer2D_GetImageNode},
{"TileMapObject2D_TileMapObject2D", TileMapObject2D_TileMapObject2D},
{"TileMapObject2D_GetObjectType", TileMapObject2D_GetObjectType},
{"TileMapObject2D_GetName", TileMapObject2D_GetName},
{"TileMapObject2D_GetType", TileMapObject2D_GetType},
{"TileMapObject2D_GetPosition", TileMapObject2D_GetPosition},
{"TileMapObject2D_GetSize", TileMapObject2D_GetSize},
{"TileMapObject2D_GetNumPoints", TileMapObject2D_GetNumPoints},
{"TileMapObject2D_GetPoint", TileMapObject2D_GetPoint},
{"TileMapObject2D_GetTileGid", TileMapObject2D_GetTileGid},
{"TileMapObject2D_GetTileFlipX", TileMapObject2D_GetTileFlipX},
{"TileMapObject2D_GetTileFlipY", TileMapObject2D_GetTileFlipY},
{"TileMapObject2D_GetTileSwapXY", TileMapObject2D_GetTileSwapXY},
{"TileMapObject2D_GetTileSprite", TileMapObject2D_GetTileSprite},
{"TileMapObject2D_HasProperty", TileMapObject2D_HasProperty},
{"TileMapObject2D_GetProperty", TileMapObject2D_GetProperty},
{"TmxFile2D_GetType", TmxFile2D_GetType},
{"TmxFile2D_GetTypeName", TmxFile2D_GetTypeName},
{"TmxFile2D_GetTypeStatic", TmxFile2D_GetTypeStatic},
{"TmxFile2D_GetTypeNameStatic", TmxFile2D_GetTypeNameStatic},
{"TmxFile2D_TmxFile2D", TmxFile2D_TmxFile2D},
{"TmxFile2D_RegisterObject", TmxFile2D_RegisterObject},
{"TmxFile2D_BeginLoad_File", TmxFile2D_BeginLoad_File},
{"TmxFile2D_BeginLoad_MemoryBuffer", TmxFile2D_BeginLoad_MemoryBuffer},
{"TmxFile2D_EndLoad", TmxFile2D_EndLoad},
{"TmxFile2D_SetInfo", TmxFile2D_SetInfo},
{"TmxFile2D_AddLayer", TmxFile2D_AddLayer},
{"TmxFile2D_GetInfo", TmxFile2D_GetInfo},
{"TmxFile2D_GetTileSprite", TmxFile2D_GetTileSprite},
{"TmxFile2D_GetTilePropertySet", TmxFile2D_GetTilePropertySet},
{"TmxFile2D_GetNumLayers", TmxFile2D_GetNumLayers},
{"TmxFile2D_GetLayer", TmxFile2D_GetLayer},
{"TmxFile2D_SetSpriteTextureEdgeOffset", TmxFile2D_SetSpriteTextureEdgeOffset},
{"TmxFile2D_GetSpriteTextureEdgeOffset", TmxFile2D_GetSpriteTextureEdgeOffset},
{"TmxImageLayer2D_TmxImageLayer2D", TmxImageLayer2D_TmxImageLayer2D},
{"TmxImageLayer2D_Load", TmxImageLayer2D_Load},
{"TmxImageLayer2D_GetPosition", TmxImageLayer2D_GetPosition},
{"TmxImageLayer2D_GetSource", TmxImageLayer2D_GetSource},
{"TmxImageLayer2D_GetSprite", TmxImageLayer2D_GetSprite},
{"TmxLayer2D_TmxLayer2D", TmxLayer2D_TmxLayer2D},
{"TmxLayer2D_GetTmxFile", TmxLayer2D_GetTmxFile},
{"TmxLayer2D_GetType", TmxLayer2D_GetType},
{"TmxLayer2D_GetName", TmxLayer2D_GetName},
{"TmxLayer2D_GetWidth", TmxLayer2D_GetWidth},
{"TmxLayer2D_GetHeight", TmxLayer2D_GetHeight},
{"TmxLayer2D_IsVisible", TmxLayer2D_IsVisible},
{"TmxLayer2D_HasProperty", TmxLayer2D_HasProperty},
{"TmxLayer2D_GetProperty", TmxLayer2D_GetProperty},
{"TmxObjectGroup2D_TmxObjectGroup2D", TmxObjectGroup2D_TmxObjectGroup2D},
{"TmxObjectGroup2D_Load", TmxObjectGroup2D_Load},
{"TmxObjectGroup2D_GetNumObjects", TmxObjectGroup2D_GetNumObjects},
{"TmxObjectGroup2D_GetObject", TmxObjectGroup2D_GetObject},
{"TmxTileLayer2D_TmxTileLayer2D", TmxTileLayer2D_TmxTileLayer2D},
{"TmxTileLayer2D_Load", TmxTileLayer2D_Load},
{"TmxTileLayer2D_GetTile", TmxTileLayer2D_GetTile},
{"Connection_GetControls", Connection_GetControls},
{"Connection_SetControls", Connection_SetControls},
{"Connection_SendRemoteEvent", Connection_SendRemoteEvent},
{"Connection_SendRemoteEvent2", Connection_SendRemoteEvent2},
{"Connection_GetType", Connection_GetType},
{"Connection_GetTypeName", Connection_GetTypeName},
{"Connection_GetTypeStatic", Connection_GetTypeStatic},
{"Connection_GetTypeNameStatic", Connection_GetTypeNameStatic},
{"Connection_GetPacketType", Connection_GetPacketType},
{"Connection_SendMessage", Connection_SendMessage},
{"Connection_SetScene", Connection_SetScene},
{"Connection_SetPosition", Connection_SetPosition},
{"Connection_SetRotation", Connection_SetRotation},
{"Connection_SetConnectPending", Connection_SetConnectPending},
{"Connection_SetLogStatistics", Connection_SetLogStatistics},
{"Connection_Disconnect", Connection_Disconnect},
{"Connection_SendServerUpdate", Connection_SendServerUpdate},
{"Connection_SendClientUpdate", Connection_SendClientUpdate},
{"Connection_SendRemoteEvents", Connection_SendRemoteEvents},
{"Connection_SendPackages", Connection_SendPackages},
{"Connection_SendBuffer", Connection_SendBuffer},
{"Connection_SendAllBuffers", Connection_SendAllBuffers},
{"Connection_ProcessPendingLatestData", Connection_ProcessPendingLatestData},
{"Connection_Ban", Connection_Ban},
{"Connection_GetScene", Connection_GetScene},
{"Connection_GetTimeStamp", Connection_GetTimeStamp},
{"Connection_GetPosition", Connection_GetPosition},
{"Connection_GetRotation", Connection_GetRotation},
{"Connection_IsClient", Connection_IsClient},
{"Connection_IsConnected", Connection_IsConnected},
{"Connection_IsConnectPending", Connection_IsConnectPending},
{"Connection_IsSceneLoaded", Connection_IsSceneLoaded},
{"Connection_GetLogStatistics", Connection_GetLogStatistics},
{"Connection_GetAddress", Connection_GetAddress},
{"Connection_GetPort", Connection_GetPort},
{"Connection_GetRoundTripTime", Connection_GetRoundTripTime},
{"Connection_GetLastHeardTime", Connection_GetLastHeardTime},
{"Connection_GetBytesInPerSec", Connection_GetBytesInPerSec},
{"Connection_GetBytesOutPerSec", Connection_GetBytesOutPerSec},
{"Connection_GetPacketsInPerSec", Connection_GetPacketsInPerSec},
{"Connection_GetPacketsOutPerSec", Connection_GetPacketsOutPerSec},
{"Connection_ToString", Connection_ToString},
{"Connection_GetNumDownloads", Connection_GetNumDownloads},
{"Connection_GetDownloadName", Connection_GetDownloadName},
{"Connection_GetDownloadProgress", Connection_GetDownloadProgress},
{"Connection_SendPackageToClient", Connection_SendPackageToClient},
{"Connection_ConfigureNetworkSimulator", Connection_ConfigureNetworkSimulator},
{"Connection_SetPacketSizeLimit", Connection_SetPacketSizeLimit},
{"Network_Connect", Network_Connect},
{"Network_GetClientConnections", Network_GetClientConnections},
{"Network_GetInterfaceBroadcastAddress", Network_GetInterfaceBroadcastAddress},
{"Network_GetType", Network_GetType},
{"Network_GetTypeName", Network_GetTypeName},
{"Network_GetTypeStatic", Network_GetTypeStatic},
{"Network_GetTypeNameStatic", Network_GetTypeNameStatic},
{"Network_Network", Network_Network},
{"Network_DiscoverHosts", Network_DiscoverHosts},
{"Network_SetPassword", Network_SetPassword},
{"Network_SetNATServerInfo", Network_SetNATServerInfo},
{"Network_Disconnect", Network_Disconnect},
{"Network_StartServer", Network_StartServer},
{"Network_StopServer", Network_StopServer},
{"Network_StartNATClient", Network_StartNATClient},
{"Network_GetGUID", Network_GetGUID},
{"Network_BroadcastMessage", Network_BroadcastMessage},
{"Network_SetUpdateFps", Network_SetUpdateFps},
{"Network_SetSimulatedLatency", Network_SetSimulatedLatency},
{"Network_SetSimulatedPacketLoss", Network_SetSimulatedPacketLoss},
{"Network_RegisterRemoteEvent", Network_RegisterRemoteEvent},
{"Network_UnregisterRemoteEvent", Network_UnregisterRemoteEvent},
{"Network_UnregisterAllRemoteEvents", Network_UnregisterAllRemoteEvents},
{"Network_SetPackageCacheDir", Network_SetPackageCacheDir},
{"Network_SendPackageToClients", Network_SendPackageToClients},
{"Network_BanAddress", Network_BanAddress},
{"Network_GetUpdateFps", Network_GetUpdateFps},
{"Network_GetSimulatedLatency", Network_GetSimulatedLatency},
{"Network_GetSimulatedPacketLoss", Network_GetSimulatedPacketLoss},
{"Network_GetServerConnection", Network_GetServerConnection},
{"Network_IsServerRunning", Network_IsServerRunning},
{"Network_CheckRemoteEvent", Network_CheckRemoteEvent},
{"Network_GetPackageCacheDir", Network_GetPackageCacheDir},
{"Network_Update", Network_Update},
{"Network_PostUpdate", Network_PostUpdate},
{"HttpRequest_ThreadFunction", HttpRequest_ThreadFunction},
{"HttpRequest_Read", HttpRequest_Read},
{"HttpRequest_Seek", HttpRequest_Seek},
{"HttpRequest_IsEof", HttpRequest_IsEof},
{"HttpRequest_GetURL", HttpRequest_GetURL},
{"HttpRequest_GetVerb", HttpRequest_GetVerb},
{"HttpRequest_GetError", HttpRequest_GetError},
{"HttpRequest_GetState", HttpRequest_GetState},
{"HttpRequest_GetAvailableSize", HttpRequest_GetAvailableSize},
{"HttpRequest_IsOpen", HttpRequest_IsOpen},
{"NetworkPriority_GetType", NetworkPriority_GetType},
{"NetworkPriority_GetTypeName", NetworkPriority_GetTypeName},
{"NetworkPriority_GetTypeStatic", NetworkPriority_GetTypeStatic},
{"NetworkPriority_GetTypeNameStatic", NetworkPriority_GetTypeNameStatic},
{"NetworkPriority_NetworkPriority", NetworkPriority_NetworkPriority},
{"NetworkPriority_RegisterObject", NetworkPriority_RegisterObject},
{"NetworkPriority_SetBasePriority", NetworkPriority_SetBasePriority},
{"NetworkPriority_SetDistanceFactor", NetworkPriority_SetDistanceFactor},
{"NetworkPriority_SetMinPriority", NetworkPriority_SetMinPriority},
{"NetworkPriority_SetAlwaysUpdateOwner", NetworkPriority_SetAlwaysUpdateOwner},
{"NetworkPriority_GetBasePriority", NetworkPriority_GetBasePriority},
{"NetworkPriority_GetDistanceFactor", NetworkPriority_GetDistanceFactor},
{"NetworkPriority_GetMinPriority", NetworkPriority_GetMinPriority},
{"NetworkPriority_GetAlwaysUpdateOwner", NetworkPriority_GetAlwaysUpdateOwner},
{"NetworkPriority_CheckUpdate", NetworkPriority_CheckUpdate},
{"CollisionShape_GetType", CollisionShape_GetType},
{"CollisionShape_GetTypeName", CollisionShape_GetTypeName},
{"CollisionShape_GetTypeStatic", CollisionShape_GetTypeStatic},
{"CollisionShape_GetTypeNameStatic", CollisionShape_GetTypeNameStatic},
{"CollisionShape_CollisionShape", CollisionShape_CollisionShape},
{"CollisionShape_RegisterObject", CollisionShape_RegisterObject},
{"CollisionShape_ApplyAttributes", CollisionShape_ApplyAttributes},
{"CollisionShape_OnSetEnabled", CollisionShape_OnSetEnabled},
{"CollisionShape_DrawDebugGeometry", CollisionShape_DrawDebugGeometry},
{"CollisionShape_SetBox", CollisionShape_SetBox},
{"CollisionShape_SetSphere", CollisionShape_SetSphere},
{"CollisionShape_SetStaticPlane", CollisionShape_SetStaticPlane},
{"CollisionShape_SetCylinder", CollisionShape_SetCylinder},
{"CollisionShape_SetCapsule", CollisionShape_SetCapsule},
{"CollisionShape_SetCone", CollisionShape_SetCone},
{"CollisionShape_SetTriangleMesh", CollisionShape_SetTriangleMesh},
{"CollisionShape_SetCustomTriangleMesh", CollisionShape_SetCustomTriangleMesh},
{"CollisionShape_SetConvexHull", CollisionShape_SetConvexHull},
{"CollisionShape_SetCustomConvexHull", CollisionShape_SetCustomConvexHull},
{"CollisionShape_SetGImpactMesh", CollisionShape_SetGImpactMesh},
{"CollisionShape_SetCustomGImpactMesh", CollisionShape_SetCustomGImpactMesh},
{"CollisionShape_SetTerrain", CollisionShape_SetTerrain},
{"CollisionShape_SetShapeType", CollisionShape_SetShapeType},
{"CollisionShape_SetSize", CollisionShape_SetSize},
{"CollisionShape_SetPosition", CollisionShape_SetPosition},
{"CollisionShape_SetRotation", CollisionShape_SetRotation},
{"CollisionShape_SetTransform", CollisionShape_SetTransform},
{"CollisionShape_SetMargin", CollisionShape_SetMargin},
{"CollisionShape_SetModel", CollisionShape_SetModel},
{"CollisionShape_SetLodLevel", CollisionShape_SetLodLevel},
{"CollisionShape_GetPhysicsWorld", CollisionShape_GetPhysicsWorld},
{"CollisionShape_GetShapeType", CollisionShape_GetShapeType},
{"CollisionShape_GetSize", CollisionShape_GetSize},
{"CollisionShape_GetPosition", CollisionShape_GetPosition},
{"CollisionShape_GetRotation", CollisionShape_GetRotation},
{"CollisionShape_GetMargin", CollisionShape_GetMargin},
{"CollisionShape_GetModel", CollisionShape_GetModel},
{"CollisionShape_GetLodLevel", CollisionShape_GetLodLevel},
{"CollisionShape_GetWorldBoundingBox", CollisionShape_GetWorldBoundingBox},
{"CollisionShape_NotifyRigidBody", CollisionShape_NotifyRigidBody},
{"CollisionShape_GetModelAttr", CollisionShape_GetModelAttr},
{"CollisionShape_ReleaseShape", CollisionShape_ReleaseShape},
{"Constraint_GetType", Constraint_GetType},
{"Constraint_GetTypeName", Constraint_GetTypeName},
{"Constraint_GetTypeStatic", Constraint_GetTypeStatic},
{"Constraint_GetTypeNameStatic", Constraint_GetTypeNameStatic},
{"Constraint_Constraint", Constraint_Constraint},
{"Constraint_RegisterObject", Constraint_RegisterObject},
{"Constraint_ApplyAttributes", Constraint_ApplyAttributes},
{"Constraint_OnSetEnabled", Constraint_OnSetEnabled},
{"Constraint_DrawDebugGeometry", Constraint_DrawDebugGeometry},
{"Constraint_SetConstraintType", Constraint_SetConstraintType},
{"Constraint_SetOtherBody", Constraint_SetOtherBody},
{"Constraint_SetPosition", Constraint_SetPosition},
{"Constraint_SetRotation", Constraint_SetRotation},
{"Constraint_SetAxis", Constraint_SetAxis},
{"Constraint_SetOtherPosition", Constraint_SetOtherPosition},
{"Constraint_SetOtherRotation", Constraint_SetOtherRotation},
{"Constraint_SetOtherAxis", Constraint_SetOtherAxis},
{"Constraint_SetWorldPosition", Constraint_SetWorldPosition},
{"Constraint_SetHighLimit", Constraint_SetHighLimit},
{"Constraint_SetLowLimit", Constraint_SetLowLimit},
{"Constraint_SetERP", Constraint_SetERP},
{"Constraint_SetCFM", Constraint_SetCFM},
{"Constraint_SetDisableCollision", Constraint_SetDisableCollision},
{"Constraint_GetPhysicsWorld", Constraint_GetPhysicsWorld},
{"Constraint_GetConstraintType", Constraint_GetConstraintType},
{"Constraint_GetOwnBody", Constraint_GetOwnBody},
{"Constraint_GetOtherBody", Constraint_GetOtherBody},
{"Constraint_GetPosition", Constraint_GetPosition},
{"Constraint_GetRotation", Constraint_GetRotation},
{"Constraint_GetOtherPosition", Constraint_GetOtherPosition},
{"Constraint_GetOtherRotation", Constraint_GetOtherRotation},
{"Constraint_GetWorldPosition", Constraint_GetWorldPosition},
{"Constraint_GetHighLimit", Constraint_GetHighLimit},
{"Constraint_GetLowLimit", Constraint_GetLowLimit},
{"Constraint_GetERP", Constraint_GetERP},
{"Constraint_GetCFM", Constraint_GetCFM},
{"Constraint_GetDisableCollision", Constraint_GetDisableCollision},
{"Constraint_ReleaseConstraint", Constraint_ReleaseConstraint},
{"Constraint_ApplyFrames", Constraint_ApplyFrames},
{"CustomRaycastVehicle_GetType", CustomRaycastVehicle_GetType},
{"CustomRaycastVehicle_GetTypeName", CustomRaycastVehicle_GetTypeName},
{"CustomRaycastVehicle_GetTypeStatic", CustomRaycastVehicle_GetTypeStatic},
{"CustomRaycastVehicle_GetTypeNameStatic", CustomRaycastVehicle_GetTypeNameStatic},
{"CustomRaycastVehicle_CustomRaycastVehicle", CustomRaycastVehicle_CustomRaycastVehicle},
{"CustomRaycastVehicle_RegisterObject", CustomRaycastVehicle_RegisterObject},
{"CustomRaycastVehicle_ResetSuspension", CustomRaycastVehicle_ResetSuspension},
{"CustomRaycastVehicle_SetVehicleCenterOfMass", CustomRaycastVehicle_SetVehicleCenterOfMass},
{"CustomRaycastVehicle_GetVehicleCenterOfMass", CustomRaycastVehicle_GetVehicleCenterOfMass},
{"CustomRaycastVehicle_GetSteeringValue", CustomRaycastVehicle_GetSteeringValue},
{"CustomRaycastVehicle_SetSteeringValue", CustomRaycastVehicle_SetSteeringValue},
{"CustomRaycastVehicle_ApplyEngineForce", CustomRaycastVehicle_ApplyEngineForce},
{"CustomRaycastVehicle_SetBrake", CustomRaycastVehicle_SetBrake},
{"CustomRaycastVehicle_GetWheelPositionWS", CustomRaycastVehicle_GetWheelPositionWS},
{"CustomRaycastVehicle_GetWheelPositionLS", CustomRaycastVehicle_GetWheelPositionLS},
{"CustomRaycastVehicle_GetWheelRotation", CustomRaycastVehicle_GetWheelRotation},
{"CustomRaycastVehicle_UpdateWheelTransform", CustomRaycastVehicle_UpdateWheelTransform},
{"CustomRaycastVehicle_AddWheel", CustomRaycastVehicle_AddWheel},
{"CustomRaycastVehicle_GetNumWheels", CustomRaycastVehicle_GetNumWheels},
{"CustomRaycastVehicle_GetForwardVector", CustomRaycastVehicle_GetForwardVector},
{"CustomRaycastVehicle_GetCurrentSpeedKmHour", CustomRaycastVehicle_GetCurrentSpeedKmHour},
{"CustomRaycastVehicle_GetCompoundLocalExtents", CustomRaycastVehicle_GetCompoundLocalExtents},
{"CustomRaycastVehicle_GetCompooundLocalExtentsCenter", CustomRaycastVehicle_GetCompooundLocalExtentsCenter},
{"CustomRaycastVehicle_GetCompoundLocalAabbMin", CustomRaycastVehicle_GetCompoundLocalAabbMin},
{"CustomRaycastVehicle_GetCompoundLocalAabbMax", CustomRaycastVehicle_GetCompoundLocalAabbMax},
{"CustomRaycastVehicle_CompoundScaleLocalAabbMin", CustomRaycastVehicle_CompoundScaleLocalAabbMin},
{"CustomRaycastVehicle_CompoundScaleLocalAabbMax", CustomRaycastVehicle_CompoundScaleLocalAabbMax},
{"CustomRaycastVehicle_SetWheelSuspensionStiffness", CustomRaycastVehicle_SetWheelSuspensionStiffness},
{"CustomRaycastVehicle_GetWheelSuspensionStiffness", CustomRaycastVehicle_GetWheelSuspensionStiffness},
{"CustomRaycastVehicle_SetWheelDampingRelaxation", CustomRaycastVehicle_SetWheelDampingRelaxation},
{"CustomRaycastVehicle_GetWheelDampingRelaxation", CustomRaycastVehicle_GetWheelDampingRelaxation},
{"CustomRaycastVehicle_SetWheelDampingCompression", CustomRaycastVehicle_SetWheelDampingCompression},
{"CustomRaycastVehicle_GetWheelDampingCompression", CustomRaycastVehicle_GetWheelDampingCompression},
{"CustomRaycastVehicle_SetWheelFrictionSlip", CustomRaycastVehicle_SetWheelFrictionSlip},
{"CustomRaycastVehicle_GetWheelFrictionSlip", CustomRaycastVehicle_GetWheelFrictionSlip},
{"CustomRaycastVehicle_SetWheelRollInfluence", CustomRaycastVehicle_SetWheelRollInfluence},
{"CustomRaycastVehicle_GetWheelRollInfluence", CustomRaycastVehicle_GetWheelRollInfluence},
{"CustomRaycastVehicle_SetSideFrictionStiffness", CustomRaycastVehicle_SetSideFrictionStiffness},
{"CustomRaycastVehicle_GetSideFrictionStiffness", CustomRaycastVehicle_GetSideFrictionStiffness},
{"CustomRaycastVehicle_GetChassisConnectionPointCS", CustomRaycastVehicle_GetChassisConnectionPointCS},
{"CustomRaycastVehicle_IsWheelInContact", CustomRaycastVehicle_IsWheelInContact},
{"CustomRaycastVehicle_GetContactPointWS", CustomRaycastVehicle_GetContactPointWS},
{"CustomRaycastVehicle_GetContactNormalWS", CustomRaycastVehicle_GetContactNormalWS},
{"CustomRaycastVehicle_SetSkidInfoCumulative", CustomRaycastVehicle_SetSkidInfoCumulative},
{"CustomRaycastVehicle_GetSkidInfoCumulative", CustomRaycastVehicle_GetSkidInfoCumulative},
{"CustomRaycastVehicle_GetWheelsRadius", CustomRaycastVehicle_GetWheelsRadius},
{"CustomRaycastVehicle_SetSkidInfo", CustomRaycastVehicle_SetSkidInfo},
{"CustomRaycastVehicle_GetSkidInfo", CustomRaycastVehicle_GetSkidInfo},
{"CustomRaycastVehicle_SetDeltaRotation", CustomRaycastVehicle_SetDeltaRotation},
{"CustomRaycastVehicle_GetDeltaRotation", CustomRaycastVehicle_GetDeltaRotation},
{"CustomRaycastVehicle_SetRotation", CustomRaycastVehicle_SetRotation},
{"CustomRaycastVehicle_GetRotation", CustomRaycastVehicle_GetRotation},
{"CustomRaycastVehicle_GetWheelAxleWS", CustomRaycastVehicle_GetWheelAxleWS},
{"CustomRaycastVehicle_SetRollInfluence", CustomRaycastVehicle_SetRollInfluence},
{"CustomRaycastVehicle_GetRollInfluence", CustomRaycastVehicle_GetRollInfluence},
{"PhysicsWorld_GetType", PhysicsWorld_GetType},
{"PhysicsWorld_GetTypeName", PhysicsWorld_GetTypeName},
{"PhysicsWorld_GetTypeStatic", PhysicsWorld_GetTypeStatic},
{"PhysicsWorld_GetTypeNameStatic", PhysicsWorld_GetTypeNameStatic},
{"PhysicsWorld_PhysicsWorld", PhysicsWorld_PhysicsWorld},
{"PhysicsWorld_RegisterObject", PhysicsWorld_RegisterObject},
{"PhysicsWorld_setDebugMode", PhysicsWorld_setDebugMode},
{"PhysicsWorld_getDebugMode", PhysicsWorld_getDebugMode},
{"PhysicsWorld_DrawDebugGeometry", PhysicsWorld_DrawDebugGeometry},
{"PhysicsWorld_Update", PhysicsWorld_Update},
{"PhysicsWorld_UpdateCollisions", PhysicsWorld_UpdateCollisions},
{"PhysicsWorld_SetFps", PhysicsWorld_SetFps},
{"PhysicsWorld_SetGravity", PhysicsWorld_SetGravity},
{"PhysicsWorld_SetMaxSubSteps", PhysicsWorld_SetMaxSubSteps},
{"PhysicsWorld_SetNumIterations", PhysicsWorld_SetNumIterations},
{"PhysicsWorld_SetUpdateEnabled", PhysicsWorld_SetUpdateEnabled},
{"PhysicsWorld_SetInterpolation", PhysicsWorld_SetInterpolation},
{"PhysicsWorld_SetInternalEdge", PhysicsWorld_SetInternalEdge},
{"PhysicsWorld_SetSplitImpulse", PhysicsWorld_SetSplitImpulse},
{"PhysicsWorld_SetMaxNetworkAngularVelocity", PhysicsWorld_SetMaxNetworkAngularVelocity},
{"PhysicsWorld_RaycastSingle", PhysicsWorld_RaycastSingle},
{"PhysicsWorld_RaycastSingleSegmented", PhysicsWorld_RaycastSingleSegmented},
{"PhysicsWorld_SphereCast", PhysicsWorld_SphereCast},
{"PhysicsWorld_ConvexCast", PhysicsWorld_ConvexCast},
{"PhysicsWorld_RemoveCachedGeometry", PhysicsWorld_RemoveCachedGeometry},
{"PhysicsWorld_GetGravity", PhysicsWorld_GetGravity},
{"PhysicsWorld_GetMaxSubSteps", PhysicsWorld_GetMaxSubSteps},
{"PhysicsWorld_GetNumIterations", PhysicsWorld_GetNumIterations},
{"PhysicsWorld_IsUpdateEnabled", PhysicsWorld_IsUpdateEnabled},
{"PhysicsWorld_GetInterpolation", PhysicsWorld_GetInterpolation},
{"PhysicsWorld_GetInternalEdge", PhysicsWorld_GetInternalEdge},
{"PhysicsWorld_GetSplitImpulse", PhysicsWorld_GetSplitImpulse},
{"PhysicsWorld_GetFps", PhysicsWorld_GetFps},
{"PhysicsWorld_GetMaxNetworkAngularVelocity", PhysicsWorld_GetMaxNetworkAngularVelocity},
{"PhysicsWorld_AddRigidBody", PhysicsWorld_AddRigidBody},
{"PhysicsWorld_RemoveRigidBody", PhysicsWorld_RemoveRigidBody},
{"PhysicsWorld_AddCollisionShape", PhysicsWorld_AddCollisionShape},
{"PhysicsWorld_RemoveCollisionShape", PhysicsWorld_RemoveCollisionShape},
{"PhysicsWorld_AddConstraint", PhysicsWorld_AddConstraint},
{"PhysicsWorld_RemoveConstraint", PhysicsWorld_RemoveConstraint},
{"PhysicsWorld_DrawDebugGeometry0", PhysicsWorld_DrawDebugGeometry0},
{"PhysicsWorld_SetDebugRenderer", PhysicsWorld_SetDebugRenderer},
{"PhysicsWorld_SetDebugDepthTest", PhysicsWorld_SetDebugDepthTest},
{"PhysicsWorld_CleanupGeometryCache", PhysicsWorld_CleanupGeometryCache},
{"PhysicsWorld_SetApplyingTransforms", PhysicsWorld_SetApplyingTransforms},
{"PhysicsWorld_IsApplyingTransforms", PhysicsWorld_IsApplyingTransforms},
{"PhysicsWorld_IsSimulating", PhysicsWorld_IsSimulating},
{"RaycastVehicle_GetType", RaycastVehicle_GetType},
{"RaycastVehicle_GetTypeName", RaycastVehicle_GetTypeName},
{"RaycastVehicle_GetTypeStatic", RaycastVehicle_GetTypeStatic},
{"RaycastVehicle_GetTypeNameStatic", RaycastVehicle_GetTypeNameStatic},
{"RaycastVehicle_RegisterObject", RaycastVehicle_RegisterObject},
{"RaycastVehicle_OnSetEnabled", RaycastVehicle_OnSetEnabled},
{"RaycastVehicle_ApplyAttributes", RaycastVehicle_ApplyAttributes},
{"RaycastVehicle_AddWheel", RaycastVehicle_AddWheel},
{"RaycastVehicle_ResetSuspension", RaycastVehicle_ResetSuspension},
{"RaycastVehicle_UpdateWheelTransform", RaycastVehicle_UpdateWheelTransform},
{"RaycastVehicle_SetSteeringValue", RaycastVehicle_SetSteeringValue},
{"RaycastVehicle_SetWheelSuspensionStiffness", RaycastVehicle_SetWheelSuspensionStiffness},
{"RaycastVehicle_SetWheelMaxSuspensionForce", RaycastVehicle_SetWheelMaxSuspensionForce},
{"RaycastVehicle_SetWheelDampingRelaxation", RaycastVehicle_SetWheelDampingRelaxation},
{"RaycastVehicle_SetWheelDampingCompression", RaycastVehicle_SetWheelDampingCompression},
{"RaycastVehicle_SetWheelFrictionSlip", RaycastVehicle_SetWheelFrictionSlip},
{"RaycastVehicle_SetWheelRollInfluence", RaycastVehicle_SetWheelRollInfluence},
{"RaycastVehicle_SetEngineForce", RaycastVehicle_SetEngineForce},
{"RaycastVehicle_SetBrake", RaycastVehicle_SetBrake},
{"RaycastVehicle_SetWheelRadius", RaycastVehicle_SetWheelRadius},
{"RaycastVehicle_ResetWheels", RaycastVehicle_ResetWheels},
{"RaycastVehicle_SetWheelSkidInfo", RaycastVehicle_SetWheelSkidInfo},
{"RaycastVehicle_WheelIsGrounded", RaycastVehicle_WheelIsGrounded},
{"RaycastVehicle_SetMaxSuspensionTravel", RaycastVehicle_SetMaxSuspensionTravel},
{"RaycastVehicle_SetWheelDirection", RaycastVehicle_SetWheelDirection},
{"RaycastVehicle_SetWheelAxle", RaycastVehicle_SetWheelAxle},
{"RaycastVehicle_SetMaxSideSlipSpeed", RaycastVehicle_SetMaxSideSlipSpeed},
{"RaycastVehicle_SetWheelSkidInfoCumulative", RaycastVehicle_SetWheelSkidInfoCumulative},
{"RaycastVehicle_SetInAirRPM", RaycastVehicle_SetInAirRPM},
{"RaycastVehicle_Init", RaycastVehicle_Init},
{"RaycastVehicle_FixedUpdate", RaycastVehicle_FixedUpdate},
{"RaycastVehicle_FixedPostUpdate", RaycastVehicle_FixedPostUpdate},
{"RaycastVehicle_PostUpdate", RaycastVehicle_PostUpdate},
{"RaycastVehicle_GetWheelPosition", RaycastVehicle_GetWheelPosition},
{"RaycastVehicle_GetWheelRotation", RaycastVehicle_GetWheelRotation},
{"RaycastVehicle_GetWheelConnectionPoint", RaycastVehicle_GetWheelConnectionPoint},
{"RaycastVehicle_GetNumWheels", RaycastVehicle_GetNumWheels},
{"RaycastVehicle_GetWheelNode", RaycastVehicle_GetWheelNode},
{"RaycastVehicle_GetSteeringValue", RaycastVehicle_GetSteeringValue},
{"RaycastVehicle_GetWheelSuspensionStiffness", RaycastVehicle_GetWheelSuspensionStiffness},
{"RaycastVehicle_GetWheelMaxSuspensionForce", RaycastVehicle_GetWheelMaxSuspensionForce},
{"RaycastVehicle_GetWheelDampingRelaxation", RaycastVehicle_GetWheelDampingRelaxation},
{"RaycastVehicle_GetWheelDampingCompression", RaycastVehicle_GetWheelDampingCompression},
{"RaycastVehicle_GetWheelFrictionSlip", RaycastVehicle_GetWheelFrictionSlip},
{"RaycastVehicle_GetWheelRollInfluence", RaycastVehicle_GetWheelRollInfluence},
{"RaycastVehicle_GetEngineForce", RaycastVehicle_GetEngineForce},
{"RaycastVehicle_GetBrake", RaycastVehicle_GetBrake},
{"RaycastVehicle_GetWheelRadius", RaycastVehicle_GetWheelRadius},
{"RaycastVehicle_SetWheelRestLength", RaycastVehicle_SetWheelRestLength},
{"RaycastVehicle_GetWheelRestLength", RaycastVehicle_GetWheelRestLength},
{"RaycastVehicle_GetMaxSuspensionTravel", RaycastVehicle_GetMaxSuspensionTravel},
{"RaycastVehicle_GetWheelAxle", RaycastVehicle_GetWheelAxle},
{"RaycastVehicle_GetWheelSideSlipSpeed", RaycastVehicle_GetWheelSideSlipSpeed},
{"RaycastVehicle_GetMaxSideSlipSpeed", RaycastVehicle_GetMaxSideSlipSpeed},
{"RaycastVehicle_GetWheelSkidInfo", RaycastVehicle_GetWheelSkidInfo},
{"RaycastVehicle_GetWheelDirection", RaycastVehicle_GetWheelDirection},
{"RaycastVehicle_GetWheelSkidInfoCumulative", RaycastVehicle_GetWheelSkidInfoCumulative},
{"RaycastVehicle_IsFrontWheel", RaycastVehicle_IsFrontWheel},
{"RaycastVehicle_GetContactPosition", RaycastVehicle_GetContactPosition},
{"RaycastVehicle_GetContactNormal", RaycastVehicle_GetContactNormal},
{"RaycastVehicle_GetInAirRPM", RaycastVehicle_GetInAirRPM},
{"RaycastVehicle_GetCoordinateSystem", RaycastVehicle_GetCoordinateSystem},
{"RigidBody_GetType", RigidBody_GetType},
{"RigidBody_GetTypeName", RigidBody_GetTypeName},
{"RigidBody_GetTypeStatic", RigidBody_GetTypeStatic},
{"RigidBody_GetTypeNameStatic", RigidBody_GetTypeNameStatic},
{"RigidBody_RigidBody", RigidBody_RigidBody},
{"RigidBody_RegisterObject", RigidBody_RegisterObject},
{"RigidBody_ApplyAttributes", RigidBody_ApplyAttributes},
{"RigidBody_OnSetEnabled", RigidBody_OnSetEnabled},
{"RigidBody_DrawDebugGeometry", RigidBody_DrawDebugGeometry},
{"RigidBody_SetMass", RigidBody_SetMass},
{"RigidBody_SetPosition", RigidBody_SetPosition},
{"RigidBody_SetRotation", RigidBody_SetRotation},
{"RigidBody_SetTransform", RigidBody_SetTransform},
{"RigidBody_SetLinearVelocity", RigidBody_SetLinearVelocity},
{"RigidBody_SetLinearFactor", RigidBody_SetLinearFactor},
{"RigidBody_SetLinearRestThreshold", RigidBody_SetLinearRestThreshold},
{"RigidBody_SetLinearDamping", RigidBody_SetLinearDamping},
{"RigidBody_SetAngularVelocity", RigidBody_SetAngularVelocity},
{"RigidBody_SetAngularFactor", RigidBody_SetAngularFactor},
{"RigidBody_SetAngularRestThreshold", RigidBody_SetAngularRestThreshold},
{"RigidBody_SetAngularDamping", RigidBody_SetAngularDamping},
{"RigidBody_SetFriction", RigidBody_SetFriction},
{"RigidBody_SetAnisotropicFriction", RigidBody_SetAnisotropicFriction},
{"RigidBody_SetRollingFriction", RigidBody_SetRollingFriction},
{"RigidBody_SetRestitution", RigidBody_SetRestitution},
{"RigidBody_SetContactProcessingThreshold", RigidBody_SetContactProcessingThreshold},
{"RigidBody_SetCcdRadius", RigidBody_SetCcdRadius},
{"RigidBody_SetCcdMotionThreshold", RigidBody_SetCcdMotionThreshold},
{"RigidBody_SetUseGravity", RigidBody_SetUseGravity},
{"RigidBody_SetGravityOverride", RigidBody_SetGravityOverride},
{"RigidBody_SetKinematic", RigidBody_SetKinematic},
{"RigidBody_SetTrigger", RigidBody_SetTrigger},
{"RigidBody_SetCollisionLayer", RigidBody_SetCollisionLayer},
{"RigidBody_SetCollisionMask", RigidBody_SetCollisionMask},
{"RigidBody_SetCollisionLayerAndMask", RigidBody_SetCollisionLayerAndMask},
{"RigidBody_SetCollisionEventMode", RigidBody_SetCollisionEventMode},
{"RigidBody_ApplyForce", RigidBody_ApplyForce},
{"RigidBody_ApplyForce0", RigidBody_ApplyForce0},
{"RigidBody_ApplyTorque", RigidBody_ApplyTorque},
{"RigidBody_ApplyImpulse", RigidBody_ApplyImpulse},
{"RigidBody_ApplyImpulse1", RigidBody_ApplyImpulse1},
{"RigidBody_ApplyTorqueImpulse", RigidBody_ApplyTorqueImpulse},
{"RigidBody_ResetForces", RigidBody_ResetForces},
{"RigidBody_Activate", RigidBody_Activate},
{"RigidBody_ReAddBodyToWorld", RigidBody_ReAddBodyToWorld},
{"RigidBody_DisableMassUpdate", RigidBody_DisableMassUpdate},
{"RigidBody_EnableMassUpdate", RigidBody_EnableMassUpdate},
{"RigidBody_GetPhysicsWorld", RigidBody_GetPhysicsWorld},
{"RigidBody_GetMass", RigidBody_GetMass},
{"RigidBody_GetPosition", RigidBody_GetPosition},
{"RigidBody_GetRotation", RigidBody_GetRotation},
{"RigidBody_GetLinearVelocity", RigidBody_GetLinearVelocity},
{"RigidBody_GetLinearFactor", RigidBody_GetLinearFactor},
{"RigidBody_GetVelocityAtPoint", RigidBody_GetVelocityAtPoint},
{"RigidBody_GetLinearRestThreshold", RigidBody_GetLinearRestThreshold},
{"RigidBody_GetLinearDamping", RigidBody_GetLinearDamping},
{"RigidBody_GetAngularVelocity", RigidBody_GetAngularVelocity},
{"RigidBody_GetAngularFactor", RigidBody_GetAngularFactor},
{"RigidBody_GetAngularRestThreshold", RigidBody_GetAngularRestThreshold},
{"RigidBody_GetAngularDamping", RigidBody_GetAngularDamping},
{"RigidBody_GetFriction", RigidBody_GetFriction},
{"RigidBody_GetAnisotropicFriction", RigidBody_GetAnisotropicFriction},
{"RigidBody_GetRollingFriction", RigidBody_GetRollingFriction},
{"RigidBody_GetRestitution", RigidBody_GetRestitution},
{"RigidBody_GetContactProcessingThreshold", RigidBody_GetContactProcessingThreshold},
{"RigidBody_GetCcdRadius", RigidBody_GetCcdRadius},
{"RigidBody_GetCcdMotionThreshold", RigidBody_GetCcdMotionThreshold},
{"RigidBody_GetUseGravity", RigidBody_GetUseGravity},
{"RigidBody_GetGravityOverride", RigidBody_GetGravityOverride},
{"RigidBody_GetCenterOfMass", RigidBody_GetCenterOfMass},
{"RigidBody_IsKinematic", RigidBody_IsKinematic},
{"RigidBody_IsTrigger", RigidBody_IsTrigger},
{"RigidBody_IsActive", RigidBody_IsActive},
{"RigidBody_GetCollisionLayer", RigidBody_GetCollisionLayer},
{"RigidBody_GetCollisionMask", RigidBody_GetCollisionMask},
{"RigidBody_GetCollisionEventMode", RigidBody_GetCollisionEventMode},
{"RigidBody_ApplyWorldTransform", RigidBody_ApplyWorldTransform},
{"RigidBody_UpdateMass", RigidBody_UpdateMass},
{"RigidBody_UpdateGravity", RigidBody_UpdateGravity},
{"RigidBody_AddConstraint", RigidBody_AddConstraint},
{"RigidBody_RemoveConstraint", RigidBody_RemoveConstraint},
{"RigidBody_ReleaseBody", RigidBody_ReleaseBody},
{"BufferedSoundStream_BufferedSoundStream", BufferedSoundStream_BufferedSoundStream},
{"BufferedSoundStream_GetData", BufferedSoundStream_GetData},
{"BufferedSoundStream_AddData", BufferedSoundStream_AddData},
{"BufferedSoundStream_Clear", BufferedSoundStream_Clear},
{"BufferedSoundStream_GetBufferNumBytes", BufferedSoundStream_GetBufferNumBytes},
{"BufferedSoundStream_GetBufferLength", BufferedSoundStream_GetBufferLength},
{"Audio_GetType", Audio_GetType},
{"Audio_GetTypeName", Audio_GetTypeName},
{"Audio_GetTypeStatic", Audio_GetTypeStatic},
{"Audio_GetTypeNameStatic", Audio_GetTypeNameStatic},
{"Audio_Audio", Audio_Audio},
{"Audio_SetMode", Audio_SetMode},
{"Audio_Update", Audio_Update},
{"Audio_Play", Audio_Play},
{"Audio_Stop", Audio_Stop},
{"Audio_SetMasterGain", Audio_SetMasterGain},
{"Audio_PauseSoundType", Audio_PauseSoundType},
{"Audio_ResumeSoundType", Audio_ResumeSoundType},
{"Audio_ResumeAll", Audio_ResumeAll},
{"Audio_SetListener", Audio_SetListener},
{"Audio_StopSound", Audio_StopSound},
{"Audio_GetSampleSize", Audio_GetSampleSize},
{"Audio_GetMixRate", Audio_GetMixRate},
{"Audio_GetInterpolation", Audio_GetInterpolation},
{"Audio_IsStereo", Audio_IsStereo},
{"Audio_IsPlaying", Audio_IsPlaying},
{"Audio_IsInitialized", Audio_IsInitialized},
{"Audio_GetMasterGain", Audio_GetMasterGain},
{"Audio_IsSoundTypePaused", Audio_IsSoundTypePaused},
{"Audio_GetListener", Audio_GetListener},
{"Audio_HasMasterGain", Audio_HasMasterGain},
{"Audio_AddSoundSource", Audio_AddSoundSource},
{"Audio_RemoveSoundSource", Audio_RemoveSoundSource},
{"Audio_GetSoundSourceMasterGain", Audio_GetSoundSourceMasterGain},
{"Audio_MixOutput", Audio_MixOutput},
{"Audio_RefreshMode", Audio_RefreshMode},
{"Audio_Close", Audio_Close},
{"OggVorbisSoundStream_OggVorbisSoundStream", OggVorbisSoundStream_OggVorbisSoundStream},
{"OggVorbisSoundStream_Seek", OggVorbisSoundStream_Seek},
{"OggVorbisSoundStream_GetData", OggVorbisSoundStream_GetData},
{"Sound_GetType", Sound_GetType},
{"Sound_GetTypeName", Sound_GetTypeName},
{"Sound_GetTypeStatic", Sound_GetTypeStatic},
{"Sound_GetTypeNameStatic", Sound_GetTypeNameStatic},
{"Sound_Sound", Sound_Sound},
{"Sound_RegisterObject", Sound_RegisterObject},
{"Sound_BeginLoad_File", Sound_BeginLoad_File},
{"Sound_BeginLoad_MemoryBuffer", Sound_BeginLoad_MemoryBuffer},
{"Sound_LoadRaw_File", Sound_LoadRaw_File},
{"Sound_LoadRaw_MemoryBuffer", Sound_LoadRaw_MemoryBuffer},
{"Sound_LoadWav_File", Sound_LoadWav_File},
{"Sound_LoadWav_MemoryBuffer", Sound_LoadWav_MemoryBuffer},
{"Sound_LoadOggVorbis_File", Sound_LoadOggVorbis_File},
{"Sound_LoadOggVorbis_MemoryBuffer", Sound_LoadOggVorbis_MemoryBuffer},
{"Sound_SetSize", Sound_SetSize},
{"Sound_SetData", Sound_SetData},
{"Sound_SetFormat", Sound_SetFormat},
{"Sound_SetLooped", Sound_SetLooped},
{"Sound_SetLoop", Sound_SetLoop},
{"Sound_GetDecoderStream", Sound_GetDecoderStream},
{"Sound_GetStart", Sound_GetStart},
{"Sound_GetRepeat", Sound_GetRepeat},
{"Sound_GetEnd", Sound_GetEnd},
{"Sound_GetLength", Sound_GetLength},
{"Sound_GetDataSize", Sound_GetDataSize},
{"Sound_GetSampleSize", Sound_GetSampleSize},
{"Sound_GetFrequency", Sound_GetFrequency},
{"Sound_GetIntFrequency", Sound_GetIntFrequency},
{"Sound_IsLooped", Sound_IsLooped},
{"Sound_IsSixteenBit", Sound_IsSixteenBit},
{"Sound_IsStereo", Sound_IsStereo},
{"Sound_IsCompressed", Sound_IsCompressed},
{"Sound_FixInterpolation", Sound_FixInterpolation},
{"SoundListener_GetType", SoundListener_GetType},
{"SoundListener_GetTypeName", SoundListener_GetTypeName},
{"SoundListener_GetTypeStatic", SoundListener_GetTypeStatic},
{"SoundListener_GetTypeNameStatic", SoundListener_GetTypeNameStatic},
{"SoundListener_SoundListener", SoundListener_SoundListener},
{"SoundListener_RegisterObject", SoundListener_RegisterObject},
{"SoundSource_GetType", SoundSource_GetType},
{"SoundSource_GetTypeName", SoundSource_GetTypeName},
{"SoundSource_GetTypeStatic", SoundSource_GetTypeStatic},
{"SoundSource_GetTypeNameStatic", SoundSource_GetTypeNameStatic},
{"SoundSource_SoundSource", SoundSource_SoundSource},
{"SoundSource_RegisterObject", SoundSource_RegisterObject},
{"SoundSource_Seek", SoundSource_Seek},
{"SoundSource_Play", SoundSource_Play},
{"SoundSource_Play0", SoundSource_Play0},
{"SoundSource_Play1", SoundSource_Play1},
{"SoundSource_Play2", SoundSource_Play2},
{"SoundSource_Play3", SoundSource_Play3},
{"SoundSource_Stop", SoundSource_Stop},
{"SoundSource_SetSoundType", SoundSource_SetSoundType},
{"SoundSource_SetFrequency", SoundSource_SetFrequency},
{"SoundSource_SetGain", SoundSource_SetGain},
{"SoundSource_SetAttenuation", SoundSource_SetAttenuation},
{"SoundSource_SetPanning", SoundSource_SetPanning},
{"SoundSource_SetAutoRemoveMode", SoundSource_SetAutoRemoveMode},
{"SoundSource_SetPlayPosition", SoundSource_SetPlayPosition},
{"SoundSource_GetSound", SoundSource_GetSound},
{"SoundSource_GetPlayPosition", SoundSource_GetPlayPosition},
{"SoundSource_GetSoundType", SoundSource_GetSoundType},
{"SoundSource_GetTimePosition", SoundSource_GetTimePosition},
{"SoundSource_GetFrequency", SoundSource_GetFrequency},
{"SoundSource_GetGain", SoundSource_GetGain},
{"SoundSource_GetAttenuation", SoundSource_GetAttenuation},
{"SoundSource_GetPanning", SoundSource_GetPanning},
{"SoundSource_GetAutoRemoveMode", SoundSource_GetAutoRemoveMode},
{"SoundSource_IsPlaying", SoundSource_IsPlaying},
{"SoundSource_Update", SoundSource_Update},
{"SoundSource_Mix", SoundSource_Mix},
{"SoundSource_UpdateMasterGain", SoundSource_UpdateMasterGain},
{"SoundSource_SetPositionAttr", SoundSource_SetPositionAttr},
{"SoundSource_GetSoundAttr", SoundSource_GetSoundAttr},
{"SoundSource_SetPlayingAttr", SoundSource_SetPlayingAttr},
{"SoundSource_GetPositionAttr", SoundSource_GetPositionAttr},
{"SoundSource3D_GetType", SoundSource3D_GetType},
{"SoundSource3D_GetTypeName", SoundSource3D_GetTypeName},
{"SoundSource3D_GetTypeStatic", SoundSource3D_GetTypeStatic},
{"SoundSource3D_GetTypeNameStatic", SoundSource3D_GetTypeNameStatic},
{"SoundSource3D_SoundSource3D", SoundSource3D_SoundSource3D},
{"SoundSource3D_RegisterObject", SoundSource3D_RegisterObject},
{"SoundSource3D_DrawDebugGeometry", SoundSource3D_DrawDebugGeometry},
{"SoundSource3D_Update", SoundSource3D_Update},
{"SoundSource3D_SetDistanceAttenuation", SoundSource3D_SetDistanceAttenuation},
{"SoundSource3D_SetAngleAttenuation", SoundSource3D_SetAngleAttenuation},
{"SoundSource3D_SetNearDistance", SoundSource3D_SetNearDistance},
{"SoundSource3D_SetFarDistance", SoundSource3D_SetFarDistance},
{"SoundSource3D_SetInnerAngle", SoundSource3D_SetInnerAngle},
{"SoundSource3D_SetOuterAngle", SoundSource3D_SetOuterAngle},
{"SoundSource3D_SetRolloffFactor", SoundSource3D_SetRolloffFactor},
{"SoundSource3D_CalculateAttenuation", SoundSource3D_CalculateAttenuation},
{"SoundSource3D_GetNearDistance", SoundSource3D_GetNearDistance},
{"SoundSource3D_GetFarDistance", SoundSource3D_GetFarDistance},
{"SoundSource3D_GetInnerAngle", SoundSource3D_GetInnerAngle},
{"SoundSource3D_GetOuterAngle", SoundSource3D_GetOuterAngle},
{"SoundSource3D_RollAngleoffFactor", SoundSource3D_RollAngleoffFactor},
{"SoundStream_Seek", SoundStream_Seek},
{"SoundStream_GetData", SoundStream_GetData},
{"SoundStream_SetFormat", SoundStream_SetFormat},
{"SoundStream_SetStopAtEnd", SoundStream_SetStopAtEnd},
{"SoundStream_GetSampleSize", SoundStream_GetSampleSize},
{"SoundStream_GetFrequency", SoundStream_GetFrequency},
{"SoundStream_GetIntFrequency", SoundStream_GetIntFrequency},
{"SoundStream_GetStopAtEnd", SoundStream_GetStopAtEnd},
{"SoundStream_IsSixteenBit", SoundStream_IsSixteenBit},
{"SoundStream_IsStereo", SoundStream_IsStereo},
{NULL, NULL}
};
static void *pinvoke_tables[] = { Urho3D_imports,};
static char *pinvoke_names[] = { "Urho3D",};
InterpFtnDesc wasm_native_to_interp_ftndescs[6];
typedef void  (*WasmInterpEntrySig_0) (int,int);
void wasm_native_to_interp_UrhoDotNet_100664642 (int arg0) { 
((WasmInterpEntrySig_0)wasm_native_to_interp_ftndescs [0].func) (&arg0, wasm_native_to_interp_ftndescs [0].arg);
}
typedef void  (*WasmInterpEntrySig_1) (int,int);
void wasm_native_to_interp_UrhoDotNet_100664643 (int arg0) { 
((WasmInterpEntrySig_1)wasm_native_to_interp_ftndescs [1].func) (&arg0, wasm_native_to_interp_ftndescs [1].arg);
}
typedef void  (*WasmInterpEntrySig_2) (int,int);
void wasm_native_to_interp_UrhoDotNet_100664646 (int arg0) { 
((WasmInterpEntrySig_2)wasm_native_to_interp_ftndescs [2].func) (&arg0, wasm_native_to_interp_ftndescs [2].arg);
}
typedef void  (*WasmInterpEntrySig_3) (int,int,int,int);
void wasm_native_to_interp_UrhoDotNet_100667452 (int arg0,int arg1,int arg2) { 
((WasmInterpEntrySig_3)wasm_native_to_interp_ftndescs [3].func) (&arg0, &arg1, &arg2, wasm_native_to_interp_ftndescs [3].arg);
}
typedef void  (*WasmInterpEntrySig_4) (int,int,int,int);
void wasm_native_to_interp_UrhoDotNet_100667453 (int arg0,int arg1,int arg2) { 
((WasmInterpEntrySig_4)wasm_native_to_interp_ftndescs [4].func) (&arg0, &arg1, &arg2, wasm_native_to_interp_ftndescs [4].arg);
}
typedef void  (*WasmInterpEntrySig_5) (int,int,int,int,int,int);
void wasm_native_to_interp_UrhoDotNet_100670883 (int arg0,int arg1,int arg2,int arg3,int arg4) { 
((WasmInterpEntrySig_5)wasm_native_to_interp_ftndescs [5].func) (&arg0, &arg1, &arg2, &arg3, &arg4, wasm_native_to_interp_ftndescs [5].arg);
}
static void *wasm_native_to_interp_funcs[] = { wasm_native_to_interp_UrhoDotNet_100664642,wasm_native_to_interp_UrhoDotNet_100664643,wasm_native_to_interp_UrhoDotNet_100664646,wasm_native_to_interp_UrhoDotNet_100667452,wasm_native_to_interp_UrhoDotNet_100667453,wasm_native_to_interp_UrhoDotNet_100670883,};
static const char *wasm_native_to_interp_map[] = { "UrhoDotNet_100664642",
"UrhoDotNet_100664643",
"UrhoDotNet_100664646",
"UrhoDotNet_100667452",
"UrhoDotNet_100667453",
"UrhoDotNet_100670883",
};
