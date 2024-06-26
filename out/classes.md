# Classes
This dump was generated using [p2dmp](https://github.com/hero622/p2dmp) on 26/06/2024 at 15:55:53 (UTC).
## CTestTraceline
```cpp
struct CTestTraceline {
	char pad_0120[288];  // 0x0000
	float m_angRotation[0];  // 0x0120
	float m_angRotation[1];  // 0x0124
	float m_angRotation[2];  // 0x0128
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
}
```
## CTEWorldDecal
```cpp
struct CTEWorldDecal {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	int32_t m_nIndex;  // 0x001c
}
```
## CTESpriteSpray
```cpp
struct CTESpriteSpray {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecDirection;  // 0x001c
	int32_t m_nModelIndex;  // 0x0028
	int32_t m_nSpeed;  // 0x002c
	float m_fNoise;  // 0x0030
	int32_t m_nCount;  // 0x0034
}
```
## CTESprite
```cpp
struct CTESprite {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	int32_t m_nModelIndex;  // 0x001c
	float m_fScale;  // 0x0020
	int32_t m_nBrightness;  // 0x0024
}
```
## CTESparks
```cpp
struct CTESparks {
	char pad_001c[28];  // 0x0000
	int32_t m_nMagnitude;  // 0x001c
	int32_t m_nTrailLength;  // 0x0020
	vec3_t m_vecDir;  // 0x0024
}
```
## CTESmoke
```cpp
struct CTESmoke {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	int32_t m_nModelIndex;  // 0x001c
	float m_fScale;  // 0x0020
	int32_t m_nFrameRate;  // 0x0024
}
```
## CTEProjectedDecal
```cpp
struct CTEProjectedDecal {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_angRotation;  // 0x001c
	float m_flDistance;  // 0x0028
	int32_t m_nIndex;  // 0x002c
}
```
## CTEPlayerDecal
```cpp
struct CTEPlayerDecal {
	char pad_0010[16];  // 0x0000
	int32_t m_nPlayer;  // 0x0010
	vec3_t m_vecOrigin;  // 0x0014
	int32_t m_nEntity;  // 0x0020
}
```
## CTEPhysicsProp
```cpp
struct CTEPhysicsProp {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	float m_angRotation[0];  // 0x001c
	float m_angRotation[1];  // 0x0020
	float m_angRotation[2];  // 0x0024
	vec3_t m_vecVelocity;  // 0x0028
	int32_t m_nModelIndex;  // 0x0034
	int32_t m_nSkin;  // 0x0038
	int32_t m_nFlags;  // 0x003c
	int32_t m_nEffects;  // 0x0040
}
```
## CTEParticleSystem
```cpp
struct CTEParticleSystem {
	char pad_0010[16];  // 0x0000
	float m_vecOrigin[0];  // 0x0010
	float m_vecOrigin[1];  // 0x0014
	float m_vecOrigin[2];  // 0x0018
}
```
## CTEMuzzleFlash
```cpp
struct CTEMuzzleFlash {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecAngles;  // 0x001c
	float m_flScale;  // 0x0028
	int32_t m_nType;  // 0x002c
}
```
## CTELargeFunnel
```cpp
struct CTELargeFunnel {
	char pad_001c[28];  // 0x0000
	int32_t m_nModelIndex;  // 0x001c
	int32_t m_nReversed;  // 0x0020
}
```
## CTEImpact
```cpp
struct CTEImpact {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecNormal;  // 0x001c
	int32_t m_iType;  // 0x0028
	int32_t m_ucFlags;  // 0x002c
}
```
## CTEGlowSprite
```cpp
struct CTEGlowSprite {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	int32_t m_nModelIndex;  // 0x001c
	float m_fScale;  // 0x0020
	float m_fLife;  // 0x0024
	int32_t m_nBrightness;  // 0x0028
}
```
## CTEShatterSurface
```cpp
struct CTEShatterSurface {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecAngles;  // 0x001c
	vec3_t m_vecForce;  // 0x0028
	vec3_t m_vecForcePos;  // 0x0034
	float m_flWidth;  // 0x0040
	float m_flHeight;  // 0x0044
	float m_flShardSize;  // 0x0048
	char pad_0050[4];  // 0x004c
	int32_t m_nSurfaceType;  // 0x0050
	int32_t m_uchFrontColor[0];  // 0x0054
	int32_t m_uchFrontColor[1];  // 0x0055
	int32_t m_uchFrontColor[2];  // 0x0056
	int32_t m_uchBackColor[0];  // 0x0057
	int32_t m_uchBackColor[1];  // 0x0058
	int32_t m_uchBackColor[2];  // 0x0059
}
```
## CTEFootprintDecal
```cpp
struct CTEFootprintDecal {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecDirection;  // 0x001c
	char pad_0034[12];  // 0x0028
	int32_t m_nEntity;  // 0x0034
	int32_t m_nIndex;  // 0x0038
	int32_t m_chMaterialType;  // 0x003c
}
```
## CTEFizz
```cpp
struct CTEFizz {
	char pad_0010[16];  // 0x0000
	int32_t m_nEntity;  // 0x0010
	int32_t m_nModelIndex;  // 0x0014
	int32_t m_nDensity;  // 0x0018
	int32_t m_nCurrent;  // 0x001c
}
```
## CTEExplosion
```cpp
struct CTEExplosion {
	char pad_001c[28];  // 0x0000
	int32_t m_nModelIndex;  // 0x001c
	float m_fScale;  // 0x0020
	int32_t m_nFrameRate;  // 0x0024
	int32_t m_nFlags;  // 0x0028
	vec3_t m_vecNormal;  // 0x002c
	int32_t m_chMaterialType;  // 0x0038
	int32_t m_nRadius;  // 0x003c
	int32_t m_nMagnitude;  // 0x0040
}
```
## CTEEnergySplash
```cpp
struct CTEEnergySplash {
	char pad_001c[28];  // 0x0000
	vec3_t m_vecDir;  // 0x001c
	int32_t m_bExplosive;  // 0x0028
}
```
## CTEDynamicLight
```cpp
struct CTEDynamicLight {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	float m_fRadius;  // 0x001c
	int32_t r;  // 0x0020
	int32_t g;  // 0x0024
	int32_t b;  // 0x0028
	int32_t exponent;  // 0x002c
	float m_fTime;  // 0x0030
	float m_fDecay;  // 0x0034
}
```
## CTEDecal
```cpp
struct CTEDecal {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecStart;  // 0x001c
	int32_t m_nEntity;  // 0x0028
	int32_t m_nHitbox;  // 0x002c
	int32_t m_nIndex;  // 0x0030
}
```
## CTEClientProjectile
```cpp
struct CTEClientProjectile {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	vec3_t m_vecVelocity;  // 0x001c
	int32_t m_nModelIndex;  // 0x0028
	int32_t m_nLifeTime;  // 0x002c
	int32_t m_hOwner;  // 0x0030
}
```
## CTEBubbleTrail
```cpp
struct CTEBubbleTrail {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecMins;  // 0x0010
	vec3_t m_vecMaxs;  // 0x001c
	float m_flWaterZ;  // 0x0028
	int32_t m_nModelIndex;  // 0x002c
	int32_t m_nCount;  // 0x0030
	float m_fSpeed;  // 0x0034
}
```
## CTEBubbles
```cpp
struct CTEBubbles {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecMins;  // 0x0010
	vec3_t m_vecMaxs;  // 0x001c
	float m_fHeight;  // 0x0028
	int32_t m_nModelIndex;  // 0x002c
	int32_t m_nCount;  // 0x0030
	float m_fSpeed;  // 0x0034
}
```
## CTEBSPDecal
```cpp
struct CTEBSPDecal {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	int32_t m_nEntity;  // 0x001c
	int32_t m_nIndex;  // 0x0020
}
```
## CTEBreakModel
```cpp
struct CTEBreakModel {
	char pad_0010[16];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0010
	float m_angRotation[0];  // 0x001c
	float m_angRotation[1];  // 0x0020
	float m_angRotation[2];  // 0x0024
	vec3_t m_vecSize;  // 0x0028
	vec3_t m_vecVelocity;  // 0x0034
	int32_t m_nRandomization;  // 0x0040
	int32_t m_nModelIndex;  // 0x0044
	int32_t m_nCount;  // 0x0048
	float m_fTime;  // 0x004c
	int32_t m_nFlags;  // 0x0050
}
```
## CTEBloodStream
```cpp
struct CTEBloodStream {
	char pad_001c[28];  // 0x0000
	vec3_t m_vecDirection;  // 0x001c
	int32_t r;  // 0x0028
	int32_t g;  // 0x002c
	int32_t b;  // 0x0030
	int32_t a;  // 0x0034
	int32_t m_nAmount;  // 0x0038
}
```
## CTEBloodSprite
```cpp
struct CTEBloodSprite {
	char pad_001c[28];  // 0x0000
	vec3_t m_vecDirection;  // 0x001c
	int32_t r;  // 0x0028
	int32_t g;  // 0x002c
	int32_t b;  // 0x0030
	int32_t a;  // 0x0034
	int32_t m_nDropModel;  // 0x0038
	int32_t m_nSprayModel;  // 0x003c
	int32_t m_nSize;  // 0x0040
}
```
## CTEBeamSpline
```cpp
struct CTEBeamSpline {
	char *m_vecPoints;  // 0x0000
	char pad_0010[12];  // 0x0004
	vec3_t m_vecPoints[0];  // 0x0010
}
```
## CTEBeamRingPoint
```cpp
struct CTEBeamRingPoint {
	char pad_004c[76];  // 0x0000
	vec3_t m_vecCenter;  // 0x004c
	float m_flStartRadius;  // 0x0058
	float m_flEndRadius;  // 0x005c
}
```
## CTEBeamRing
```cpp
struct CTEBeamRing {
	char pad_004c[76];  // 0x0000
	int32_t m_nStartEntity;  // 0x004c
	int32_t m_nEndEntity;  // 0x0050
}
```
## CTEBeamPoints
```cpp
struct CTEBeamPoints {
	char pad_004c[76];  // 0x0000
	vec3_t m_vecStartPoint;  // 0x004c
	vec3_t m_vecEndPoint;  // 0x0058
}
```
## CTEBeamLaser
```cpp
struct CTEBeamLaser {
	char pad_004c[76];  // 0x0000
	int32_t m_nStartEntity;  // 0x004c
	int32_t m_nEndEntity;  // 0x0050
}
```
## CTEBeamEnts
```cpp
struct CTEBeamEnts {
	char pad_004c[76];  // 0x0000
	int32_t m_nStartEntity;  // 0x004c
	int32_t m_nEndEntity;  // 0x0050
}
```
## CTEBeamEntPoint
```cpp
struct CTEBeamEntPoint {
	char pad_004c[76];  // 0x0000
	int32_t m_nStartEntity;  // 0x004c
	int32_t m_nEndEntity;  // 0x0050
	vec3_t m_vecStartPoint;  // 0x0054
	vec3_t m_vecEndPoint;  // 0x0060
}
```
## CTEBaseBeam
```cpp
struct CTEBaseBeam {
	char pad_0014[20];  // 0x0000
	int32_t m_nHaloIndex;  // 0x0014
	int32_t m_nStartFrame;  // 0x0018
	int32_t m_nFrameRate;  // 0x001c
	float m_fLife;  // 0x0020
	float m_fWidth;  // 0x0024
	float m_fEndWidth;  // 0x0028
	int32_t m_nFadeLength;  // 0x002c
	float m_fAmplitude;  // 0x0030
	int32_t r;  // 0x0034
	int32_t g;  // 0x0038
	int32_t b;  // 0x003c
	int32_t a;  // 0x0040
	int32_t m_nSpeed;  // 0x0044
	int32_t m_nFlags;  // 0x0048
}
```
## CSteamJet
```cpp
struct CSteamJet {
	char pad_0b6c[2924];  // 0x0000
	float m_SpreadSpeed;  // 0x0b6c
	float m_Speed;  // 0x0b70
	float m_StartSize;  // 0x0b74
	float m_EndSize;  // 0x0b78
	float m_Rate;  // 0x0b7c
	float m_JetLength;  // 0x0b80
	int32_t m_bEmit;  // 0x0b84
	int32_t m_nType;  // 0x0b88
	int32_t m_bFaceLeft;  // 0x0b8c
	int32_t m_spawnflags;  // 0x0b90
	float m_flRollSpeed;  // 0x0b94
}
```
## CSmokeStack
```cpp
struct CSmokeStack {
	char pad_0bbc[3004];  // 0x0000
	float m_SpreadSpeed;  // 0x0bbc
	float m_Speed;  // 0x0bc0
	float m_StartSize;  // 0x0bc4
	float m_EndSize;  // 0x0bc8
	float m_Rate;  // 0x0bcc
	float m_JetLength;  // 0x0bd0
	int32_t m_bEmit;  // 0x0bd4
	float m_flBaseSpread;  // 0x0bd8
	vec3_t m_AmbientLight.m_vPos;  // 0x0bdc
	vec3_t m_AmbientLight.m_vColor;  // 0x0be8
	float m_AmbientLight.m_flIntensity;  // 0x0bf4
	vec3_t m_DirLight.m_vPos;  // 0x0bf8
	vec3_t m_DirLight.m_vColor;  // 0x0c04
	float m_DirLight.m_flIntensity;  // 0x0c10
	char pad_0c20[12];  // 0x0c14
	vec3_t m_vWind;  // 0x0c20
	float m_flTwist;  // 0x0c2c
	int32_t m_iMaterialModel;  // 0x0c30
	char pad_0c68[52];  // 0x0c34
	float m_flRollSpeed;  // 0x0c68
}
```
## DustTrail
```cpp
struct DustTrail {
	char pad_0b6c[2924];  // 0x0000
	float m_SpawnRate;  // 0x0b6c
	vec3_t m_Color;  // 0x0b70
	float m_Opacity;  // 0x0b7c
	float m_ParticleLifetime;  // 0x0b80
	char pad_0b88[4];  // 0x0b84
	float m_StopEmitTime;  // 0x0b88
	float m_MinSpeed;  // 0x0b8c
	float m_MaxSpeed;  // 0x0b90
	float m_MinDirectedSpeed;  // 0x0b94
	float m_MaxDirectedSpeed;  // 0x0b98
	float m_StartSize;  // 0x0b9c
	float m_EndSize;  // 0x0ba0
	float m_SpawnRadius;  // 0x0ba4
	char pad_0bb4[12];  // 0x0ba8
	int32_t m_bEmit;  // 0x0bb4
}
```
## CFireTrail
```cpp
struct CFireTrail {
	char pad_0b6c[2924];  // 0x0000
	int32_t m_nAttachment;  // 0x0b6c
	float m_flLifetime;  // 0x0b70
}
```
## SporeTrail
```cpp
struct SporeTrail {
	char pad_0b68[2920];  // 0x0000
	vec3_t m_vecEndColor;  // 0x0b68
	float m_flSpawnRate;  // 0x0b74
	float m_flParticleLifetime;  // 0x0b78
	float m_flStartSize;  // 0x0b7c
	float m_flEndSize;  // 0x0b80
	float m_flSpawnRadius;  // 0x0b84
	char pad_0b94[12];  // 0x0b88
	int32_t m_bEmit;  // 0x0b94
}
```
## SporeExplosion
```cpp
struct SporeExplosion {
	char pad_0b6c[2924];  // 0x0000
	float m_flSpawnRate;  // 0x0b6c
	float m_flParticleLifetime;  // 0x0b70
	float m_flStartSize;  // 0x0b74
	float m_flEndSize;  // 0x0b78
	float m_flSpawnRadius;  // 0x0b7c
	char pad_0b84[4];  // 0x0b80
	int32_t m_bEmit;  // 0x0b84
	int32_t m_bDontRemove;  // 0x0b85
}
```
## RocketTrail
```cpp
struct RocketTrail {
	char pad_0b6c[2924];  // 0x0000
	float m_SpawnRate;  // 0x0b6c
	vec3_t m_StartColor;  // 0x0b70
	vec3_t m_EndColor;  // 0x0b7c
	float m_Opacity;  // 0x0b88
	float m_ParticleLifetime;  // 0x0b8c
	float m_StopEmitTime;  // 0x0b90
	float m_MinSpeed;  // 0x0b94
	float m_MaxSpeed;  // 0x0b98
	float m_StartSize;  // 0x0b9c
	float m_EndSize;  // 0x0ba0
	float m_SpawnRadius;  // 0x0ba4
	char pad_0bb4[12];  // 0x0ba8
	int32_t m_bEmit;  // 0x0bb4
	int32_t m_bDamaged;  // 0x0bb5
	int32_t m_nAttachment;  // 0x0bb8
	char pad_0bc8[12];  // 0x0bbc
	float m_flFlareScale;  // 0x0bc8
}
```
## SmokeTrail
```cpp
struct SmokeTrail {
	char pad_0b6c[2924];  // 0x0000
	float m_SpawnRate;  // 0x0b6c
	vec3_t m_StartColor;  // 0x0b70
	vec3_t m_EndColor;  // 0x0b7c
	float m_Opacity;  // 0x0b88
	float m_ParticleLifetime;  // 0x0b8c
	float m_StopEmitTime;  // 0x0b90
	float m_MinSpeed;  // 0x0b94
	float m_MaxSpeed;  // 0x0b98
	float m_MinDirectedSpeed;  // 0x0b9c
	float m_MaxDirectedSpeed;  // 0x0ba0
	float m_StartSize;  // 0x0ba4
	float m_EndSize;  // 0x0ba8
	float m_SpawnRadius;  // 0x0bac
	char pad_0bbc[12];  // 0x0bb0
	int32_t m_bEmit;  // 0x0bbc
	int32_t m_nAttachment;  // 0x0bc0
}
```
## CPropVehicleDriveable
```cpp
struct CPropVehicleDriveable {
	char pad_0dbc[3516];  // 0x0000
	int32_t m_hPlayer;  // 0x0dbc
	int32_t m_nSpeed;  // 0x0dc0
	int32_t m_nRPM;  // 0x0dc4
	float m_flThrottle;  // 0x0dc8
	int32_t m_nBoostTimeLeft;  // 0x0dcc
	int32_t m_nHasBoost;  // 0x0dd0
	int32_t m_nScannerDisabledWeapons;  // 0x0dd4
	int32_t m_nScannerDisabledVehicle;  // 0x0dd8
	char pad_0df8[28];  // 0x0ddc
	int32_t m_bEnterAnimOn;  // 0x0df8
	int32_t m_bExitAnimOn;  // 0x0df9
	char pad_0e00[3];  // 0x0dfd
	vec3_t m_vecGunCrosshair;  // 0x0e00
	char pad_0e38[44];  // 0x0e0c
	vec3_t m_vecEyeExitEndpoint;  // 0x0e38
	int32_t m_bHasGun;  // 0x0e44
	int32_t m_bUnableToFire;  // 0x0e45
}
```
## ParticleSmokeGrenade
```cpp
struct ParticleSmokeGrenade {
	char pad_0b6c[2924];  // 0x0000
	int32_t m_CurrentStage;  // 0x0b6c
	char pad_0b7c[12];  // 0x0b70
	float m_flSpawnTime;  // 0x0b7c
	float m_FadeStartTime;  // 0x0b80
	float m_FadeEndTime;  // 0x0b84
}
```
## CTEGaussExplosion
```cpp
struct CTEGaussExplosion {
	char pad_001c[28];  // 0x0000
	int32_t m_nType;  // 0x001c
	vec3_t m_vecDirection;  // 0x0020
}
```
## CEnvQuadraticBeam
```cpp
struct CEnvQuadraticBeam {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_targetPosition;  // 0x0a80
	vec3_t m_controlPosition;  // 0x0a8c
	float m_scrollRate;  // 0x0a98
	float m_flWidth;  // 0x0a9c
}
```
## CEmbers
```cpp
struct CEmbers {
	char pad_0a80[2688];  // 0x0000
	int32_t m_nDensity;  // 0x0a80
	int32_t m_nLifetime;  // 0x0a84
	int32_t m_nSpeed;  // 0x0a88
	int32_t m_bEmit;  // 0x0a8c
}
```
## CWeaponPortalgun
```cpp
struct CWeaponPortalgun {
	char pad_0e98[3736];  // 0x0000
	int32_t m_bCanFirePortal1;  // 0x0e98
	int32_t m_bCanFirePortal2;  // 0x0e99
	int32_t m_iLastFiredPortal;  // 0x0e9c
	int32_t m_bOpenProngs;  // 0x0ea0
	float m_fEffectsMaxSize1;  // 0x0ea4
	float m_fEffectsMaxSize2;  // 0x0ea8
	char pad_0eb8[12];  // 0x0eac
	vec3_t m_vecBluePortalPos;  // 0x0eb8
	vec3_t m_vecOrangePortalPos;  // 0x0ec4
	char pad_0ed4[4];  // 0x0ed0
	int32_t m_EffectState;  // 0x0ed4
	int32_t m_hPrimaryPortal;  // 0x0ed8
	int32_t m_hSecondaryPortal;  // 0x0edc
}
```
## CTrigger_TractorBeam
```cpp
struct CTrigger_TractorBeam {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bDisabled;  // 0x0a80
	char pad_0aa4[32];  // 0x0a84
	vec3_t m_vStart;  // 0x0aa4
	vec3_t m_vEnd;  // 0x0ab0
	float m_linearForce;  // 0x0abc
	float m_flRadius;  // 0x0ac0
	int32_t m_bReversed;  // 0x0ac4
	int32_t m_bFromPortal;  // 0x0ac5
	int32_t m_bToPortal;  // 0x0ac6
	int32_t m_bDisablePlayerMove;  // 0x0ac7
	char pad_0ad8[13];  // 0x0acb
	int32_t m_hProxyEntity;  // 0x0ad8
	char pad_0aec[16];  // 0x0adc
	float m_gravityScale;  // 0x0aec
	float m_addAirDensity;  // 0x0af0
	float m_linearLimit;  // 0x0af4
	float m_linearLimitDelta;  // 0x0af8
	float m_linearLimitTime;  // 0x0afc
	float m_linearLimitStart;  // 0x0b00
	float m_linearLimitStartTime;  // 0x0b04
	float m_linearScale;  // 0x0b08
	float m_angularLimit;  // 0x0b0c
	float m_angularScale;  // 0x0b10
	vec3_t m_linearForceAngles;  // 0x0b14
}
```
## CTriggerCatapult
```cpp
struct CTriggerCatapult {
	char pad_0abc[2748];  // 0x0000
	void *m_flRefireDelay;  // 0x0abc
	char pad_0b44[132];  // 0x0ac0
	float m_flPlayerVelocity;  // 0x0b44
	float m_flPhysicsVelocity;  // 0x0b48
	vec3_t m_vecLaunchAngles;  // 0x0b4c
	int32_t m_ExactVelocityChoice;  // 0x0b58
	int32_t m_bUseExactVelocity;  // 0x0b5c
	int32_t m_bUseThresholdCheck;  // 0x0b5d
	float m_flLowerThreshold;  // 0x0b60
	float m_flUpperThreshold;  // 0x0b64
	float m_flEntryAngleTolerance;  // 0x0b68
	int32_t m_bApplyAngularImpulse;  // 0x0b6c
	int32_t m_bOnlyVelocityCheck;  // 0x0b6d
	int32_t m_hLaunchTarget;  // 0x0b70
	int32_t m_bPlayersPassTriggerFilters;  // 0x0b74
	float m_flAirControlSupressionTime;  // 0x0b78
	int32_t m_bDirectionSuppressAirControl;  // 0x0b7c
}
```
## CPropTractorBeamProjector
```cpp
struct CPropTractorBeamProjector {
	char pad_0dbc[3516];  // 0x0000
	int32_t m_bEnabled;  // 0x0dbc
	float m_flLinearForce;  // 0x0dc0
	vec3_t m_vEndPos;  // 0x0dc4
	char pad_0dd2[2];  // 0x0dd0
	int32_t m_bNoEmitterParticles;  // 0x0dd2
}
```
## CPropRocketTripwire
```cpp
struct CPropRocketTripwire {
	char pad_0dd0[3536];  // 0x0000
	int32_t m_nBeamEndpointTexture;  // 0x0dd0
	int32_t m_iMuzzleAttachment;  // 0x0dd4
	int32_t m_bDrawBeams;  // 0x0dd8
	int32_t m_hRocket;  // 0x0ddc
}
```
## CTEWallPaintedEvent
```cpp
struct CTEWallPaintedEvent {
	char pad_0014[20];  // 0x0000
	int32_t m_colorIndex;  // 0x0014
	int32_t m_nSegment;  // 0x0018
}
```
## CProjectedWallEntity
```cpp
struct CProjectedWallEntity {
	char pad_0120[288];  // 0x0000
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_0b80[2632];  // 0x0138
	vec3_t m_vWorldSpace_WallMins;  // 0x0b80
	vec3_t m_vWorldSpace_WallMaxs;  // 0x0b8c
	char pad_0bb0[24];  // 0x0b98
	float m_flLength;  // 0x0bb0
	float m_flWidth;  // 0x0bb4
	float m_flHeight;  // 0x0bb8
	int32_t m_bIsHorizontal;  // 0x0bbc
	int32_t m_hColorPortal;  // 0x0bc0
	char pad_0bd4[16];  // 0x0bc4
	int32_t m_nNumSegments;  // 0x0bd4
	float m_flSegmentLength;  // 0x0bd8
	char pad_0bf0[20];  // 0x0bdc
	float m_flParticleUpdateTime;  // 0x0bf0
}
```
## CPortal_PointPush
```cpp
struct CPortal_PointPush {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bEnabled;  // 0x0a80
	float m_flMagnitude;  // 0x0a84
	float m_flRadius;  // 0x0a88
	float m_flInnerRadius;  // 0x0a8c
	float m_flConeOfInfluence;  // 0x0a90
}
```
## CNPC_HoverTurret
```cpp
struct CNPC_HoverTurret {
	char pad_1328[4904];  // 0x0000
	int32_t m_iLaserState;  // 0x1328
	int32_t m_sLaserHaloSprite;  // 0x132c
}
```
## CInfoPortalScore
```cpp
struct CInfoPortalScore {
	char pad_0a80[2688];  // 0x0000
	int32_t m_nBlueScore;  // 0x0a80
	int32_t m_nBlueRounds;  // 0x0a84
	int32_t m_nOrangeScore;  // 0x0a88
	int32_t m_nOrangeRounds;  // 0x0a8c
	int32_t m_nRoundsToWin;  // 0x0a90
	float m_flTotalTime;  // 0x0a94
	char *m_strGameDescription;  // 0x0a98
}
```
## CInfoPlacementHelper
```cpp
struct CInfoPlacementHelper {
	char pad_0120[288];  // 0x0000
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_0a80[2376];  // 0x0138
	char *m_strTargetProxy;  // 0x0a80
	char *m_strTargetEntity;  // 0x0a84
	float m_flRadius;  // 0x0a88
	int32_t m_bSnapToHelperAngles;  // 0x0a8c
	int32_t m_bForcePlacement;  // 0x0a8d
	int32_t m_bDisabled;  // 0x0a8e
	float m_flDisableTime;  // 0x0a90
	int32_t m_bDeferringToPortal;  // 0x0a94
}
```
## CLabIndicatorPanel
```cpp
struct CLabIndicatorPanel {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bEnabled;  // 0x0a80
	int32_t m_bStopped;  // 0x0a81
	int32_t m_bCountingDown;  // 0x0a82
	int32_t m_bIsCountdownTimer;  // 0x0a83
	int32_t m_bIsChecked;  // 0x0a84
	int32_t m_iPlayerPinged;  // 0x0a88
	float m_flTimerDuration;  // 0x0a8c
	float m_flTimerStart;  // 0x0a90
}
```
## CPortalLaser
```cpp
struct CPortalLaser {
	char pad_0dd0[3536];  // 0x0000
	int32_t m_hReflector;  // 0x0dd0
	char pad_0de0[12];  // 0x0dd4
	vec3_t m_vStartPoint;  // 0x0de0
	vec3_t m_vEndPoint;  // 0x0dec
	int32_t m_bLaserOn;  // 0x0df8
	int32_t m_bIsLethal;  // 0x0df9
	int32_t m_bIsAutoAiming;  // 0x0dfa
	int32_t m_bShouldSpark;  // 0x0dfb
	int32_t m_bUseParentDir;  // 0x0dfc
	vec3_t m_angParentAngles;  // 0x0e00
}
```
## CBaseProjector
```cpp
struct CBaseProjector {
	char pad_0db8[3512];  // 0x0000
	int32_t m_hFirstChild;  // 0x0db8
	int32_t m_bEnabled;  // 0x0dbc
}
```
## CBaseProjectedEntity
```cpp
struct CBaseProjectedEntity {
	char pad_0120[288];  // 0x0000
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_0aa4[2412];  // 0x0138
	int32_t m_hHitPortal;  // 0x0aa4
	int32_t m_hSourcePortal;  // 0x0aa8
	vec3_t m_vecSourcePortalCenter;  // 0x0aac
	vec3_t m_vecSourcePortalRemoteCenter;  // 0x0ab8
	vec3_t m_vecSourcePortalAngle;  // 0x0ac4
	vec3_t m_vecSourcePortalRemoteAngle;  // 0x0ad0
	vec3_t m_vecStartPoint;  // 0x0adc
	vec3_t m_vecEndPoint;  // 0x0ae8
	int32_t m_hChildSegment;  // 0x0af4
	int32_t m_hPlacementHelper;  // 0x0af8
	int32_t m_iMaxRemainingRecursions;  // 0x0afc
}
```
## CWeaponPaintGun
```cpp
struct CWeaponPaintGun {
	char pad_0ebc[3772];  // 0x0000
	int32_t m_nCurrentColor;  // 0x0ebc
	int32_t m_bFiringPaint;  // 0x0ec0
	int32_t m_bFiringErase;  // 0x0ec1
	int32_t m_nPaintAmmo;  // 0x0ec4
	void *m_bHasPaint;  // 0x0ec8
	char pad_0ed0[4];  // 0x0ecc
	void *m_hPaintStream;  // 0x0ed0
	char pad_0ee4[16];  // 0x0ed4
	void *m_PaintAmmoPerType;  // 0x0ee4
}
```
## CPaintStream
```cpp
struct CPaintStream {
	char pad_0e34[3636];  // 0x0000
	int32_t m_nPaintType;  // 0x0e34
	int32_t m_nRenderMode;  // 0x0e38
	vec3_t m_vLightPosition;  // 0x0e3c
	int32_t m_nMaxBlobCount;  // 0x0e48
}
```
## CPaintSprayer
```cpp
struct CPaintSprayer {
	char pad_0120[288];  // 0x0000
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
	char pad_0a8c[2380];  // 0x0140
	int32_t m_nBlobRandomSeed;  // 0x0a8c
	int32_t m_bActive;  // 0x0a90
	int32_t m_bSilent;  // 0x0a91
	int32_t m_bDrawOnly;  // 0x0a92
	int32_t m_nMaxBlobCount;  // 0x0a94
	int32_t m_PaintPowerType;  // 0x0a98
	float m_flBlobsPerSecond;  // 0x0a9c
	float m_flBlobSpreadRadius;  // 0x0aa0
	float m_flBlobSpreadAngle;  // 0x0aa4
	float m_flMinSpeed;  // 0x0aa8
	float m_flMaxSpeed;  // 0x0aac
	float m_flNoisyBlobPercentage;  // 0x0ab0
	float m_flPercentageSinceLastNoisyBlob;  // 0x0ab4
	float m_flStreakPercentage;  // 0x0ab8
	float m_flMinStreakTime;  // 0x0abc
	float m_flMaxStreakTime;  // 0x0ac0
	float m_flMinStreakSpeedDampen;  // 0x0ac4
	float m_flMaxStreakSpeedDampen;  // 0x0ac8
	float m_flStartTime;  // 0x0acc
	int32_t m_hPaintStream;  // 0x0ad0
}
```
## CTriggerPortalCleanser
```cpp
struct CTriggerPortalCleanser {
	char pad_0abc[2748];  // 0x0000
	int32_t m_bObject1InRange;  // 0x0abc
	int32_t m_bObject2InRange;  // 0x0abd
	int32_t m_hObject1;  // 0x0ac0
	int32_t m_hObject2;  // 0x0ac4
	int32_t m_bDisabled;  // 0x0ac8
	char pad_0ad0[4];  // 0x0acc
	int32_t m_bVisible;  // 0x0ad0
	int32_t m_bUseScanline;  // 0x0ad1
	int32_t m_bPlayersPassTriggerFilters;  // 0x0ad2
	float m_flPortalShotTime;  // 0x0ad4
}
```
## CPropPortalStatsDisplay
```cpp
struct CPropPortalStatsDisplay {
	char pad_0dba[3514];  // 0x0000
	int32_t m_bEnabled;  // 0x0dba
	int32_t m_iNumPortalsPlaced;  // 0x0dbc
	int32_t m_iNumStepsTaken;  // 0x0dc0
	float m_fNumSecondsTaken;  // 0x0dc4
	int32_t m_iBronzeObjective;  // 0x0dc8
	int32_t m_iSilverObjective;  // 0x0dcc
	int32_t m_iGoldObjective;  // 0x0dd0
	char *szChallengeFileName;  // 0x0dd4
	char pad_0e54[124];  // 0x0dd8
	char *szChallengeMapName;  // 0x0e54
	char pad_0e74[28];  // 0x0e58
	char *szChallengeName;  // 0x0e74
	char pad_0e94[28];  // 0x0e78
	int32_t m_iDisplayObjective;  // 0x0e94
}
```
## CProp_Portal
```cpp
struct CProp_Portal {
	char pad_351c[13596];  // 0x0000
	int32_t m_hFiredByPlayer;  // 0x351c
	char pad_3548[40];  // 0x3520
	int32_t m_nPlacementAttemptParity;  // 0x3548
}
```
## CProp_Mirror
```cpp
struct CProp_Mirror {
	char pad_1060[4192];  // 0x0000
	float m_fWidth;  // 0x1060
	float m_fHeight;  // 0x1064
}
```
## CPropEnergyBall
```cpp
struct CPropEnergyBall {
	char pad_0de0[3552];  // 0x0000
	int32_t m_bIsInfiniteLife;  // 0x0de0
	float m_fTimeTillDeath;  // 0x0de4
}
```
## CPortal_Player
```cpp
struct CPortal_Player {
	void *portallocaldata;  // 0x0000
	char pad_00fc[248];  // 0x0004
	vec3_t m_vecViewOffset;  // 0x00fc
	float m_vecViewOffset[1];  // 0x0100
	float m_vecViewOffset[2];  // 0x0104
	char pad_012c[36];  // 0x0108
	vec2_t m_vecOrigin;  // 0x012c
	float m_vecOrigin[2];  // 0x0134
	char pad_1c48[6928];  // 0x0138
	int32_t m_bPitchReorientation;  // 0x1c48
	char pad_1c58[12];  // 0x1c4c
	int32_t m_hPortalEnvironment;  // 0x1c58
	char pad_1c68[12];  // 0x1c5c
	void *m_PortalLocal;  // 0x1c68
	int32_t m_bShowingViewFinder;  // 0x1c6c
	float m_flAirControlSupressionTime;  // 0x1c70
	void *m_nLocatorEntityIndices;  // 0x1c74
	char pad_1cb4[60];  // 0x1c78
	int32_t m_bPlacingPhoto;  // 0x1cb4
	char pad_1d08[80];  // 0x1cb8
	vec3_t m_StickNormal;  // 0x1d08
	vec3_t m_OldStickNormal;  // 0x1d14
	vec3_t m_vPreUpdateVelocity;  // 0x1d20
	vec3_t m_Up;  // 0x1d2c
	vec3_t m_vStickRotationAxis;  // 0x1d38
	vec3_t m_StandHullMin;  // 0x1d44
	vec3_t m_StandHullMax;  // 0x1d50
	vec3_t m_DuckHullMin;  // 0x1d5c
	vec3_t m_DuckHullMax;  // 0x1d68
	vec3_t m_CachedStandHullMinAttempt;  // 0x1d74
	vec3_t m_CachedStandHullMaxAttempt;  // 0x1d80
	vec3_t m_CachedDuckHullMinAttempt;  // 0x1d8c
	vec3_t m_CachedDuckHullMaxAttempt;  // 0x1d98
	vec3_t m_vLocalUp;  // 0x1da4
	vec3_t m_vEyeOffset;  // 0x1db0
	vec3_t m_qQuaternionPunch;  // 0x1dbc
	int32_t m_PaintedPowerType;  // 0x1dc8
	void *m_PaintedPowerTimer;  // 0x1dcc
	char pad_1dd8[8];  // 0x1dd0
	float m_flAirInputScale;  // 0x1dd8
	float m_flCurrentStickTime;  // 0x1ddc
	int32_t m_nStickCameraState;  // 0x1de0
	int32_t m_InAirState;  // 0x1de4
	int32_t m_bDoneStickInterp;  // 0x1de8
	int32_t m_bDoneCorrectPitch;  // 0x1de9
	int32_t m_bJumpedThisFrame;  // 0x1deb
	int32_t m_bBouncedThisFrame;  // 0x1dec
	int32_t m_bDuckedInAir;  // 0x1ded
	int32_t m_hTractorBeam;  // 0x1df0
	char pad_1df8[4];  // 0x1df4
	int32_t m_bZoomedIn;  // 0x1df8
	float m_fBouncedTime;  // 0x1dfc
	int32_t m_bPreventedCrouchJumpThisFrame;  // 0x1e00
	char pad_1e28[36];  // 0x1e04
	float m_flMotionBlurAmount;  // 0x1e28
	char pad_1e34[8];  // 0x1e2c
	float m_angEyeAngles[0];  // 0x1e34
	float m_angEyeAngles[1];  // 0x1e38
	char pad_1e80[68];  // 0x1e3c
	float m_flHullHeight;  // 0x1e80
	char pad_1ef0[108];  // 0x1e84
	int32_t m_hRagdoll;  // 0x1ef0
	char pad_1f40[76];  // 0x1ef4
	int32_t m_iSpawnInterpCounter;  // 0x1f40
	char pad_1f48[4];  // 0x1f44
	int32_t m_iPlayerSoundType;  // 0x1f48
	int32_t m_bHeldObjectOnOppositeSideOfPortal;  // 0x1f4c
	int32_t m_hHeldObjectPortal;  // 0x1f50
	char pad_1fd4[128];  // 0x1f54
	int32_t m_bIsHoldingSomething;  // 0x1fd4
	char pad_2000[40];  // 0x1fd8
	int32_t m_bPingDisabled;  // 0x2000
	int32_t m_bTauntDisabled;  // 0x2001
	int32_t m_bTauntRemoteView;  // 0x2002
	vec3_t m_vecRemoteViewOrigin;  // 0x2004
	vec3_t m_vecRemoteViewAngles;  // 0x2010
	float m_fTauntCameraDistance;  // 0x201c
	char pad_2028[8];  // 0x2020
	int32_t m_nTeamTauntState;  // 0x2028
	vec3_t m_vTauntPosition;  // 0x202c
	vec3_t m_vTauntAngles;  // 0x2038
	vec3_t m_vPreTauntAngles;  // 0x2044
	int32_t m_bTrickFire;  // 0x2050
	int32_t m_hTauntPartnerInRange;  // 0x2054
	char *m_szTauntForce;  // 0x2058
	char pad_20d1[117];  // 0x205c
	int32_t m_bUseVMGrab;  // 0x20d1
	int32_t m_bUsingVMGrabState;  // 0x20d2
	int32_t m_hAttachedObject;  // 0x20d4
	char pad_21ec[276];  // 0x20d8
	vec3_t m_vecCarriedObjectAngles;  // 0x21ec
	char pad_2200[8];  // 0x21f8
	vec3_t m_vecCarriedObject_CurPosToTargetPos;  // 0x2200
	vec3_t m_vecCarriedObject_CurAngToTargetAng;  // 0x220c
	char pad_22b8[160];  // 0x2218
	int32_t m_iSpawnCounter;  // 0x22b8
	char pad_2371[181];  // 0x22bc
	int32_t m_bWantsToSwapGuns;  // 0x2371
	int32_t m_bPotatos;  // 0x2372
	char pad_2384[14];  // 0x2376
	void *m_Shared;  // 0x2384
	char pad_23c8[64];  // 0x2388
	void *m_StatsThisLevel;  // 0x23c8
	int32_t iNumPortalsPlaced;  // 0x23cc
	int32_t iNumStepsTaken;  // 0x23d0
	float fNumSecondsTaken;  // 0x23d4
	float fDistanceTaken;  // 0x23d8
	char pad_23f0[20];  // 0x23dc
	int32_t m_iEntityPortalledNetworkMessageCount;  // 0x23f0
}
```
## CPortalRagdoll
```cpp
struct CPortalRagdoll {
	char pad_0350[848];  // 0x0000
	int32_t m_nModelIndex;  // 0x0350
	char pad_0ae8[1940];  // 0x0354
	vec3_t m_vecForce;  // 0x0ae8
	int32_t m_nForceBone;  // 0x0af4
	char pad_11a0[1704];  // 0x0af8
	int32_t m_hPlayer;  // 0x11a0
	vec3_t m_vecRagdollVelocity;  // 0x11a4
}
```
## CTEPlayerAnimEvent
```cpp
struct CTEPlayerAnimEvent {
	char pad_0014[20];  // 0x0000
	int32_t m_iEvent;  // 0x0014
	int32_t m_nData;  // 0x0018
}
```
## CPortal_Base2D
```cpp
struct CPortal_Base2D {
	char pad_0120[288];  // 0x0000
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_1014[3804];  // 0x0138
	vec3_t m_ptOrigin;  // 0x1014
	char pad_1044[36];  // 0x1020
	vec3_t m_qAbsAngle;  // 0x1044
	int32_t m_bIsPortal2;  // 0x1050
	char pad_106c[24];  // 0x1054
	int32_t m_hLinkedPortal;  // 0x106c
	char pad_10ac[60];  // 0x1070
	void *m_PortalSimulator;  // 0x10ac
	char pad_34f0[9280];  // 0x10b0
	int32_t m_bActivated;  // 0x34f0
	int32_t m_bOldActivatedState;  // 0x34f1
	float m_fNetworkHalfWidth;  // 0x34f4
	float m_fNetworkHalfHeight;  // 0x34f8
	int32_t m_bIsMobile;  // 0x34fc
}
```
## CNPC_RocketTurret
```cpp
struct CNPC_RocketTurret {
	char pad_1324[4900];  // 0x0000
	int32_t m_iLaserState;  // 0x1324
	int32_t m_nSiteHalo;  // 0x1328
	vec3_t m_vecCurrentAngles;  // 0x132c
}
```
## CNPC_Portal_FloorTurret
```cpp
struct CNPC_Portal_FloorTurret {
	char pad_1344[4932];  // 0x0000
	int32_t m_bOutOfAmmo;  // 0x1344
	int32_t m_bLaserOn;  // 0x1345
	int32_t m_bIsFiring;  // 0x1346
	char pad_134c[2];  // 0x134a
	int32_t m_sLaserHaloSprite;  // 0x134c
}
```
## CNeurotoxinCountdown
```cpp
struct CNeurotoxinCountdown {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bEnabled;  // 0x0a80
	float m_flCountdownTime;  // 0x0a84
}
```
## CEnvPortalPathTrack
```cpp
struct CEnvPortalPathTrack {
	char pad_0a84[2692];  // 0x0000
	int32_t m_nState;  // 0x0a84
	char pad_0a90[8];  // 0x0a88
	int32_t m_bTrackActive;  // 0x0a90
	int32_t m_bEndpointActive;  // 0x0a91
}
```
## CEnv_Lightrail_Endpoint
```cpp
struct CEnv_Lightrail_Endpoint {
	char pad_0a80[2688];  // 0x0000
	float m_flSmallScale;  // 0x0a80
	float m_flLargeScale;  // 0x0a84
	int32_t m_nState;  // 0x0a88
	float m_flDuration;  // 0x0a8c
	float m_flStartTime;  // 0x0a90
	int32_t m_spawnflags;  // 0x0a94
}
```
## CFleshEffectTarget
```cpp
struct CFleshEffectTarget {
	char pad_0a80[2688];  // 0x0000
	float m_flRadius;  // 0x0a80
	char pad_0a8c[8];  // 0x0a84
	float m_flScaleTime;  // 0x0a8c
}
```
## CScriptIntro
```cpp
struct CScriptIntro {
	char *m_flFadeColor;  // 0x0000
	char pad_0a80[2684];  // 0x0004
	int32_t m_iNextFOV;  // 0x0a80
	int32_t m_iFOV;  // 0x0a84
	char pad_0a8c[4];  // 0x0a88
	int32_t m_iStartFOV;  // 0x0a8c
	float m_flNextFOVBlendTime;  // 0x0a90
	float m_flFOVBlendStartTime;  // 0x0a94
	int32_t m_bAlternateFOV;  // 0x0a98
	char pad_0ae0[68];  // 0x0a9c
	vec3_t m_vecCameraView;  // 0x0ae0
	vec3_t m_vecCameraViewAngles;  // 0x0aec
	int32_t m_iBlendMode;  // 0x0af8
	int32_t m_iNextBlendMode;  // 0x0afc
	float m_flNextBlendTime;  // 0x0b00
	float m_flBlendStartTime;  // 0x0b04
	int32_t m_bActive;  // 0x0b08
	int32_t m_hCameraEntity;  // 0x0b0c
	float m_flFadeColor[0];  // 0x0b10
	char pad_0b1c[8];  // 0x0b14
	float m_flFadeAlpha;  // 0x0b1c
	char pad_0b24[4];  // 0x0b20
	float m_flFadeDuration;  // 0x0b24
}
```
## CPropCombineBall
```cpp
struct CPropCombineBall {
	char pad_0dc4[3524];  // 0x0000
	int32_t m_bEmit;  // 0x0dc4
	float m_flRadius;  // 0x0dc8
	int32_t m_bHeld;  // 0x0dcc
	int32_t m_bLaunched;  // 0x0dcd
}
```
## CPlasmaBeamNode
```cpp
struct CPlasmaBeamNode {
	char pad_0108[264];  // 0x0000
	vec3_t m_vecVelocity;  // 0x0108
	char pad_0a80[2412];  // 0x0114
	int32_t m_bSprayOn;  // 0x0a80
}
```
## CInfoTeleporterCountdown
```cpp
struct CInfoTeleporterCountdown {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bCountdownStarted;  // 0x0a80
	int32_t m_bDisabled;  // 0x0a81
	float m_flStartTime;  // 0x0a84
	float m_flTimeRemaining;  // 0x0a88
}
```
## CMortarShell
```cpp
struct CMortarShell {
	char pad_0a8c[2700];  // 0x0000
	float m_flLifespan;  // 0x0a8c
	float m_flRadius;  // 0x0a90
	char pad_0a98[4];  // 0x0a94
	vec3_t m_vecSurfaceNormal;  // 0x0a98
}
```
## CCitadelEnergyCore
```cpp
struct CCitadelEnergyCore {
	char pad_0a80[2688];  // 0x0000
	float m_flScale;  // 0x0a80
	int32_t m_nState;  // 0x0a84
	float m_flDuration;  // 0x0a88
	float m_flStartTime;  // 0x0a8c
	int32_t m_spawnflags;  // 0x0a90
}
```
## CHL2_Player
```cpp
struct CHL2_Player {
	char pad_1b20[6944];  // 0x0000
	void *m_HL2Local;  // 0x1b20
	float m_flSuitPower;  // 0x1b24
	int32_t m_bZooming;  // 0x1b28
	int32_t m_bitsActiveDevices;  // 0x1b2c
	int32_t m_iSquadMemberCount;  // 0x1b30
	int32_t m_iSquadMedicCount;  // 0x1b34
	int32_t m_fSquadInFollowMode;  // 0x1b38
	int32_t m_bWeaponLowered;  // 0x1b39
	int32_t m_hAutoAimTarget;  // 0x1b3c
	vec3_t m_vecAutoAimPoint;  // 0x1b40
	int32_t m_bDisplayReticle;  // 0x1b4c
	int32_t m_bStickyAutoAim;  // 0x1b4d
	int32_t m_bAutoAimTarget;  // 0x1b4e
	int32_t m_hLadder;  // 0x1b50
	char pad_1b88[52];  // 0x1b54
	int32_t m_fIsSprinting;  // 0x1b88
}
```
## CTEAntlionDust
```cpp
struct CTEAntlionDust {
	char pad_0020[32];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0020
	vec3_t m_vecAngles;  // 0x002c
	int32_t m_bBlockedSpawner;  // 0x0038
}
```
## CHandleTest
```cpp
struct CHandleTest {
	char pad_0a80[2688];  // 0x0000
	int32_t m_Handle;  // 0x0a80
	int32_t m_bSendHandle;  // 0x0a84
}
```
## CSpriteTrail
```cpp
struct CSpriteTrail {
	char pad_111c[4380];  // 0x0000
	float m_flLifeTime;  // 0x111c
	float m_flStartWidth;  // 0x1120
	float m_flEndWidth;  // 0x1124
	float m_flStartWidthVariance;  // 0x1128
	float m_flTextureRes;  // 0x112c
	float m_flMinFadeLength;  // 0x1130
	vec3_t m_vecSkyboxOrigin;  // 0x1134
	float m_flSkyboxScale;  // 0x1140
}
```
## CSprite
```cpp
struct CSprite {
	char pad_0a90[2704];  // 0x0000
	int32_t m_hAttachedToEntity;  // 0x0a90
	int32_t m_nAttachment;  // 0x0a94
	float m_flSpriteFramerate;  // 0x0a98
	float m_flFrame;  // 0x0a9c
	float m_flDieTime;  // 0x0aa0
	int32_t m_nBrightness;  // 0x0aa4
	float m_flBrightnessTime;  // 0x0aa8
	float m_flSpriteScale;  // 0x0aac
	float m_flScaleTime;  // 0x0ab0
	int32_t m_bWorldSpaceScale;  // 0x0ab4
	float m_flGlowProxySize;  // 0x0ab8
	float m_flHDRColorScale;  // 0x0abc
	float m_flLastTime;  // 0x0ac0
	float m_flMaxFrame;  // 0x0ac4
}
```
## CRagdollPropAttached
```cpp
struct CRagdollPropAttached {
	char pad_10c8[4296];  // 0x0000
	vec3_t m_attachmentPointBoneSpace;  // 0x10c8
	char pad_10e0[12];  // 0x10d4
	vec3_t m_attachmentPointRagdollSpace;  // 0x10e0
	int32_t m_ragdollAttachedObjectIndex;  // 0x10ec
	int32_t m_boneIndexAttached;  // 0x10f0
}
```
## CRagdollProp
```cpp
struct CRagdollProp {
	char *m_ragAngles;  // 0x0000
	char pad_0db8[3508];  // 0x0004
	vec3_t m_ragPos[0];  // 0x0db8
	char pad_0ed8[276];  // 0x0dc4
	vec3_t m_ragAngles[0];  // 0x0ed8
	char pad_10b4[464];  // 0x0ee4
	int32_t m_hUnragdoll;  // 0x10b4
	float m_flBlendWeight;  // 0x10b8
	char pad_10c0[4];  // 0x10bc
	int32_t m_nOverlaySequence;  // 0x10c0
}
```
## CPoseController
```cpp
struct CPoseController {
	char pad_0a80[2688];  // 0x0000
	void *m_hProps;  // 0x0a80
	char pad_0a90[12];  // 0x0a84
	void *m_chPoseIndex;  // 0x0a90
	int32_t m_bPoseValueParity;  // 0x0a94
	float m_fPoseValue;  // 0x0a98
	float m_fInterpolationTime;  // 0x0a9c
	int32_t m_bInterpolationWrap;  // 0x0aa0
	float m_fCycleFrequency;  // 0x0aa4
	int32_t m_nFModType;  // 0x0aa8
	float m_fFModTimeOffset;  // 0x0aac
	float m_fFModRate;  // 0x0ab0
	float m_fFModAmplitude;  // 0x0ab4
}
```
## CFuncLadder
```cpp
struct CFuncLadder {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_vecLadderDir;  // 0x0a80
	char pad_0aa0[20];  // 0x0a8c
	vec3_t m_vecPlayerMountPositionTop;  // 0x0aa0
	vec3_t m_vecPlayerMountPositionBottom;  // 0x0aac
	char pad_0ab9[1];  // 0x0ab8
	int32_t m_bFakeLadder;  // 0x0ab9
}
```
## CWorld
```cpp
struct CWorld {
	char pad_0a80[2688];  // 0x0000
	float m_flWaveHeight;  // 0x0a80
	vec3_t m_WorldMins;  // 0x0a84
	vec3_t m_WorldMaxs;  // 0x0a90
	int32_t m_bStartDark;  // 0x0a9c
	float m_flMaxOccludeeArea;  // 0x0aa0
	float m_flMinOccluderArea;  // 0x0aa4
	float m_flMinPropScreenSpaceWidth;  // 0x0aa8
	float m_flMaxPropScreenSpaceWidth;  // 0x0aac
	int32_t m_bColdWorld;  // 0x0ab0
	int32_t m_iTimeOfDay;  // 0x0ab4
	char *m_iszDetailSpriteMaterial;  // 0x0ab8
	char pad_0bb8[252];  // 0x0abc
	int32_t m_nMaxBlobCount;  // 0x0bb8
}
```
## CWaterLODControl
```cpp
struct CWaterLODControl {
	char pad_0a80[2688];  // 0x0000
	float m_flCheapWaterStartDistance;  // 0x0a80
	float m_flCheapWaterEndDistance;  // 0x0a84
}
```
## CVGuiScreen
```cpp
struct CVGuiScreen {
	char pad_0a88[2696];  // 0x0000
	float m_flWidth;  // 0x0a88
	float m_flHeight;  // 0x0a8c
	int32_t m_nPanelName;  // 0x0a90
	char pad_0aac[24];  // 0x0a94
	int32_t m_nAttachmentIndex;  // 0x0aac
	int32_t m_nOverlayMaterial;  // 0x0ab0
	int32_t m_fScreenFlags;  // 0x0ab4
	char pad_0b10[88];  // 0x0ab8
	int32_t m_hPlayerOwner;  // 0x0b10
}
```
## CPropVehicleChoreoGeneric
```cpp
struct CPropVehicleChoreoGeneric {
	char pad_0e04[3588];  // 0x0000
	int32_t m_hPlayer;  // 0x0e04
	char pad_0e0c[4];  // 0x0e08
	int32_t m_bEnterAnimOn;  // 0x0e0c
	int32_t m_bExitAnimOn;  // 0x0e0d
	vec3_t m_vecEyeExitEndpoint;  // 0x0e10
	int32_t m_bForceEyesToAttachment;  // 0x0e1c
	char pad_0ea0[128];  // 0x0e20
	int32_t m_vehicleView.bClampEyeAngles;  // 0x0ea0
	float m_vehicleView.flPitchCurveZero;  // 0x0ea4
	float m_vehicleView.flPitchCurveLinear;  // 0x0ea8
	float m_vehicleView.flRollCurveZero;  // 0x0eac
	float m_vehicleView.flRollCurveLinear;  // 0x0eb0
	float m_vehicleView.flFOV;  // 0x0eb4
	float m_vehicleView.flYawMin;  // 0x0eb8
	float m_vehicleView.flYawMax;  // 0x0ebc
	float m_vehicleView.flPitchMin;  // 0x0ec0
	float m_vehicleView.flPitchMax;  // 0x0ec4
}
```
## CBaseTrigger
```cpp
struct CBaseTrigger {
	char pad_03bc[956];  // 0x0000
	int32_t m_spawnflags;  // 0x03bc
	char pad_0ab0[1776];  // 0x03c0
	int32_t m_bClientSidePredicted;  // 0x0ab0
}
```
## CTesla
```cpp
struct CTesla {
	char pad_0aa8[2728];  // 0x0000
	char *m_SoundName;  // 0x0aa8
	char pad_0ae8[60];  // 0x0aac
	char *m_iszSpriteName;  // 0x0ae8
}
```
## CBaseTeamObjectiveResource
```cpp
struct CBaseTeamObjectiveResource {
	char *m_vCPPositions;  // 0x0000
	char pad_0a84[2688];  // 0x0004
	int32_t m_iStopWatchTimer;  // 0x0a84
	int32_t m_iNumControlPoints;  // 0x0a88
	char pad_0a90[4];  // 0x0a8c
	int32_t m_bPlayingMiniRounds;  // 0x0a90
	int32_t m_bControlPointsReset;  // 0x0a91
	int32_t m_iUpdateCapHudParity;  // 0x0a94
	char pad_0a9c[4];  // 0x0a98
	vec3_t m_vCPPositions[0];  // 0x0a9c
	char pad_0afc[84];  // 0x0aa8
	void *m_bCPIsVisible;  // 0x0afc
	char pad_0b04[4];  // 0x0b00
	void *m_flLazyCapPerc;  // 0x0b04
	char pad_0b44[60];  // 0x0b08
	void *m_iTeamIcons;  // 0x0b44
	char pad_0c44[252];  // 0x0b48
	void *m_iTeamOverlays;  // 0x0c44
	char pad_0d44[252];  // 0x0c48
	void *m_iTeamReqCappers;  // 0x0d44
	char pad_0e44[252];  // 0x0d48
	void *m_flTeamCapTime;  // 0x0e44
	char pad_0f44[252];  // 0x0e48
	void *m_iPreviousPoints;  // 0x0f44
	char pad_1244[764];  // 0x0f48
	void *m_bTeamCanCap;  // 0x1244
	char pad_1284[60];  // 0x1248
	void *m_iTeamBaseIcons;  // 0x1284
	char pad_1304[124];  // 0x1288
	void *m_iBaseControlPoints;  // 0x1304
	char pad_1384[124];  // 0x1308
	void *m_bInMiniRound;  // 0x1384
	char pad_138c[4];  // 0x1388
	void *m_iWarnOnCap;  // 0x138c
	char pad_13ac[28];  // 0x1390
	char *m_iszWarnSound[0];  // 0x13ac
	char pad_1ba4[2036];  // 0x13b0
	void *m_flPathDistance;  // 0x1ba4
	char pad_1bc4[28];  // 0x1ba8
	void *m_iNumTeamMembers;  // 0x1bc4
	char pad_1cc4[252];  // 0x1bc8
	void *m_iCappingTeam;  // 0x1cc4
	char pad_1ce4[28];  // 0x1cc8
	void *m_iTeamInZone;  // 0x1ce4
	char pad_1d04[28];  // 0x1ce8
	void *m_bBlocked;  // 0x1d04
	char pad_1d0c[4];  // 0x1d08
	void *m_iOwner;  // 0x1d0c
	char pad_1d94[132];  // 0x1d10
	char *m_pszCapLayoutInHUD;  // 0x1d94
}
```
## CTeam
```cpp
struct CTeam {
	int32_t player_array_element;  // 0x0000
	char pad_0a94[2704];  // 0x0004
	char *m_szTeamname;  // 0x0a94
	char pad_0ab4[28];  // 0x0a98
	int32_t m_iScore;  // 0x0ab4
	int32_t m_iRoundsWon;  // 0x0ab8
}
```
## CSunlightShadowControl
```cpp
struct CSunlightShadowControl {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_shadowDirection;  // 0x0a80
	int32_t m_bEnabled;  // 0x0a8c
	char *m_TextureName;  // 0x0a8d
	char pad_0b98[263];  // 0x0a91
	int32_t m_LightColor;  // 0x0b98
	char pad_0bac[16];  // 0x0b9c
	float m_flColorTransitionTime;  // 0x0bac
	float m_flSunDistance;  // 0x0bb0
	float m_flFOV;  // 0x0bb4
	float m_flNearZ;  // 0x0bb8
	float m_flNorthOffset;  // 0x0bbc
	int32_t m_bEnableShadows;  // 0x0bc0
}
```
## CSun
```cpp
struct CSun {
	float HDRColorScale;  // 0x0000
	char pad_0c28[3108];  // 0x0004
	int32_t m_clrOverlay;  // 0x0c28
	int32_t m_nSize;  // 0x0c2c
	int32_t m_nOverlaySize;  // 0x0c30
	vec3_t m_vDirection;  // 0x0c34
	int32_t m_bOn;  // 0x0c40
	int32_t m_nMaterial;  // 0x0c44
	int32_t m_nOverlayMaterial;  // 0x0c48
}
```
## CParticlePerformanceMonitor
```cpp
struct CParticlePerformanceMonitor {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bDisplayPerf;  // 0x0a80
	int32_t m_bMeasurePerf;  // 0x0a81
}
```
## CSpotlightEnd
```cpp
struct CSpotlightEnd {
	char pad_0a80[2688];  // 0x0000
	float m_flLightScale;  // 0x0a80
	float m_Radius;  // 0x0a84
}
```
## CSpatialEntity
```cpp
struct CSpatialEntity {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0a80
	float m_minFalloff;  // 0x0a8c
	float m_maxFalloff;  // 0x0a90
	float m_flCurWeight;  // 0x0a94
	char pad_0b9c[260];  // 0x0a98
	int32_t m_bEnabled;  // 0x0b9c
}
```
## CSlideshowDisplay
```cpp
struct CSlideshowDisplay {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bEnabled;  // 0x0a80
	char *m_szDisplayText;  // 0x0a81
	char pad_0b01[124];  // 0x0a85
	char *m_szSlideshowDirectory;  // 0x0b01
	char pad_0b98[147];  // 0x0b05
	void *m_chCurrentSlideLists;  // 0x0b98
	char pad_0bb0[20];  // 0x0b9c
	float m_fMinSlideTime;  // 0x0bb0
	float m_fMaxSlideTime;  // 0x0bb4
	char pad_0bbc[4];  // 0x0bb8
	int32_t m_iCycleType;  // 0x0bbc
	int32_t m_bNoListRepeats;  // 0x0bc0
}
```
## CShadowControl
```cpp
struct CShadowControl {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_shadowDirection;  // 0x0a80
	int32_t m_shadowColor;  // 0x0a8c
	float m_flShadowMaxDist;  // 0x0a90
	int32_t m_bDisableShadows;  // 0x0a94
	int32_t m_bEnableLocalLightShadows;  // 0x0a95
}
```
## CSceneEntity
```cpp
struct CSceneEntity {
	void *m_hActorList;  // 0x0000
	char pad_0a84[2688];  // 0x0004
	int32_t m_bIsPlayingBack;  // 0x0a84
	int32_t m_bPaused;  // 0x0a85
	int32_t m_bMultiplayer;  // 0x0a86
	char pad_0a8c[2];  // 0x0a8a
	float m_flForceClientTime;  // 0x0a8c
	int32_t m_nSceneStringIndex;  // 0x0a90
}
```
## CRopeKeyframe
```cpp
struct CRopeKeyframe {
	char pad_012c[300];  // 0x0000
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
	char pad_03e0[672];  // 0x0140
	int32_t m_iParentAttachment;  // 0x03e0
	char pad_0a31[1613];  // 0x03e4
	int32_t m_nMinCPULevel;  // 0x0a31
	int32_t m_nMaxCPULevel;  // 0x0a32
	int32_t m_nMinGPULevel;  // 0x0a33
	int32_t m_nMaxGPULevel;  // 0x0a34
	char pad_0ab4[124];  // 0x0a38
	float m_flScrollSpeed;  // 0x0ab4
	int32_t m_RopeFlags;  // 0x0ab8
	int32_t m_iRopeMaterialModelIndex;  // 0x0abc
	char pad_0d48[648];  // 0x0ac0
	int32_t m_nSegments;  // 0x0d48
	int32_t m_hStartPoint;  // 0x0d4c
	int32_t m_hEndPoint;  // 0x0d50
	int32_t m_iStartAttachment;  // 0x0d54
	int32_t m_iEndAttachment;  // 0x0d56
	int32_t m_Subdiv;  // 0x0d58
	int32_t m_RopeLength;  // 0x0d5c
	int32_t m_Slack;  // 0x0d60
	float m_TextureScale;  // 0x0d64
	int32_t m_fLockedPoints;  // 0x0d68
	char pad_0d70[4];  // 0x0d6c
	float m_Width;  // 0x0d70
	char pad_0df0[124];  // 0x0d74
	int32_t m_bConstrainBetweenEndpoints;  // 0x0df0
}
```
## CPhysicsPropMultiplayer
```cpp
struct CPhysicsPropMultiplayer {
	char pad_0df4[3572];  // 0x0000
	int32_t m_iPhysicsMode;  // 0x0df4
	float m_fMass;  // 0x0df8
	vec3_t m_collisionMins;  // 0x0dfc
	vec3_t m_collisionMaxs;  // 0x0e08
}
```
## CPhysBoxMultiplayer
```cpp
struct CPhysBoxMultiplayer {
	char pad_0a8c[2700];  // 0x0000
	int32_t m_iPhysicsMode;  // 0x0a8c
	float m_fMass;  // 0x0a90
}
```
## CProp_Hallucination
```cpp
struct CProp_Hallucination {
	char pad_0dd1[3537];  // 0x0000
	int32_t m_bEnabled;  // 0x0dd1
	float m_fVisibleTime;  // 0x0dd4
	float m_fRechargeTime;  // 0x0dd8
}
```
## CPostProcessController
```cpp
struct CPostProcessController {
	char pad_0a80[2688];  // 0x0000
	void *m_flPostProcessParameters;  // 0x0a80
	char pad_0aac[40];  // 0x0a84
	int32_t m_bMaster;  // 0x0aac
}
```
## CPointCommentaryNode
```cpp
struct CPointCommentaryNode {
	char pad_0db8[3512];  // 0x0000
	int32_t m_bActive;  // 0x0db8
	float m_flStartTime;  // 0x0dbc
	char *m_iszCommentaryFile;  // 0x0dc0
	char pad_0ec4[256];  // 0x0dc4
	char *m_iszCommentaryFileNoHDR;  // 0x0ec4
	char pad_0fc8[256];  // 0x0ec8
	char *m_iszSpeakers;  // 0x0fc8
	char pad_10c8[252];  // 0x0fcc
	int32_t m_iNodeNumber;  // 0x10c8
	int32_t m_iNodeNumberMax;  // 0x10cc
	char pad_10d4[4];  // 0x10d0
	int32_t m_hViewPosition;  // 0x10d4
}
```
## CPointCamera
```cpp
struct CPointCamera {
	char pad_0a80[2688];  // 0x0000
	float m_FOV;  // 0x0a80
	float m_Resolution;  // 0x0a84
	int32_t m_bFogEnable;  // 0x0a88
	int32_t m_FogColor;  // 0x0a89
	char pad_0a90[3];  // 0x0a8d
	float m_flFogStart;  // 0x0a90
	float m_flFogEnd;  // 0x0a94
	float m_flFogMaxDensity;  // 0x0a98
	int32_t m_bActive;  // 0x0a9c
	int32_t m_bUseScreenAspectRatio;  // 0x0a9d
}
```
## CPlayerResource
```cpp
struct CPlayerResource {
	char pad_0b94[2964];  // 0x0000
	void *m_iScore;  // 0x0b94
	char pad_0c1c[132];  // 0x0b98
	void *m_iDeaths;  // 0x0c1c
	char pad_0ca4[132];  // 0x0c20
	void *m_bConnected;  // 0x0ca4
	char pad_0cc8[32];  // 0x0ca8
	void *m_iTeam;  // 0x0cc8
	char pad_0d50[132];  // 0x0ccc
	void *m_bAlive;  // 0x0d50
	char pad_0d74[32];  // 0x0d54
	void *m_iHealth;  // 0x0d74
}
```
## CPlasma
```cpp
struct CPlasma {
	char pad_0a80[2688];  // 0x0000
	float m_flStartScale;  // 0x0a80
	float m_flScale;  // 0x0a84
	float m_flScaleTime;  // 0x0a88
	int32_t m_nFlags;  // 0x0a8c
	int32_t m_nPlasmaModelIndex;  // 0x0a90
	int32_t m_nPlasmaModelIndex2;  // 0x0a94
	int32_t m_nGlowModelIndex;  // 0x0a98
}
```
## CPhysicsProp
```cpp
struct CPhysicsProp {
	char pad_03bc[956];  // 0x0000
	int32_t m_spawnflags;  // 0x03bc
	char pad_0dd0[2576];  // 0x03c0
	int32_t m_bAwake;  // 0x0dd0
}
```
## CStatueProp
```cpp
struct CStatueProp {
	char pad_0df0[3568];  // 0x0000
	int32_t m_hInitBaseAnimating;  // 0x0df0
	int32_t m_bShatter;  // 0x0df4
	int32_t m_nShatterFlags;  // 0x0df8
	vec3_t m_vShatterPosition;  // 0x0dfc
	vec3_t m_vShatterForce;  // 0x0e08
}
```
## CParticleSystem
```cpp
struct CParticleSystem {
	char pad_00e8[232];  // 0x0000
	int32_t m_fEffects;  // 0x00e8
	char pad_0120[52];  // 0x00ec
	vec3_t m_angRotation;  // 0x0120
	char pad_013c[16];  // 0x012c
	int32_t moveparent;  // 0x013c
	int32_t m_hOwnerEntity;  // 0x0140
	char pad_03e0[668];  // 0x0144
	int32_t m_iParentAttachment;  // 0x03e0
	char pad_0a80[1692];  // 0x03e4
	int32_t m_iEffectIndex;  // 0x0a80
	int32_t m_nStopType;  // 0x0a84
	int32_t m_bActive;  // 0x0a88
	float m_flStartTime;  // 0x0a8c
	char *m_szSnapshotFileName;  // 0x0a90
	char pad_0b94[256];  // 0x0a94
	void *m_vServerControlPoints;  // 0x0b94
	char pad_0bc4[44];  // 0x0b98
	void *m_iServerControlPointAssignments;  // 0x0bc4
	char pad_0bd8[16];  // 0x0bc8
	void *m_hControlPointEnts;  // 0x0bd8
	char pad_0cd4[248];  // 0x0bdc
	void *m_iControlPointParents;  // 0x0cd4
}
```
## CMovieDisplay
```cpp
struct CMovieDisplay {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bEnabled;  // 0x0a80
	int32_t m_bLooping;  // 0x0a81
	char *m_szMovieFilename;  // 0x0a82
	char pad_0b02[124];  // 0x0a86
	char *m_szGroupName;  // 0x0b02
	char pad_0b82[124];  // 0x0b06
	int32_t m_bStretchToFill;  // 0x0b82
	int32_t m_bForcedSlave;  // 0x0b83
	int32_t m_bUseCustomUVs;  // 0x0b84
	float m_flUMin;  // 0x0b88
	float m_flUMax;  // 0x0b8c
	float m_flVMin;  // 0x0b90
	float m_flVMax;  // 0x0b94
}
```
## CMaterialModifyControl
```cpp
struct CMaterialModifyControl {
	char pad_0a80[2688];  // 0x0000
	char *m_szMaterialName;  // 0x0a80
	char pad_0b7f[251];  // 0x0a84
	char *m_szMaterialVar;  // 0x0b7f
	char pad_0c7e[251];  // 0x0b83
	char *m_szMaterialVarValue;  // 0x0c7e
	char pad_0d88[262];  // 0x0c82
	int32_t m_iFrameStart;  // 0x0d88
	int32_t m_iFrameEnd;  // 0x0d8c
	int32_t m_bWrap;  // 0x0d90
	float m_flFramerate;  // 0x0d94
	int32_t m_bNewAnimCommandsSemaphore;  // 0x0d98
	float m_flFloatLerpStartValue;  // 0x0d9c
	float m_flFloatLerpEndValue;  // 0x0da0
	float m_flFloatLerpTransitionTime;  // 0x0da4
	int32_t m_bFloatLerpWrap;  // 0x0da8
	char pad_0db0[4];  // 0x0dac
	int32_t m_nModifyMode;  // 0x0db0
}
```
## CLightGlow
```cpp
struct CLightGlow {
	float HDRColorScale;  // 0x0000
	char pad_0120[284];  // 0x0004
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
	char pad_0a80[2368];  // 0x0140
	int32_t m_nHorizontalSize;  // 0x0a80
	int32_t m_nVerticalSize;  // 0x0a84
	int32_t m_nMinDist;  // 0x0a88
	int32_t m_nMaxDist;  // 0x0a8c
	int32_t m_nOuterMaxDist;  // 0x0a90
	int32_t m_spawnflags;  // 0x0a94
	char pad_0b90[248];  // 0x0a98
	float m_flGlowProxySize;  // 0x0b90
}
```
## CFuncSmokeVolume
```cpp
struct CFuncSmokeVolume {
	char pad_0410[1040];  // 0x0000
	void *m_Collision;  // 0x0410
	char pad_0418[4];  // 0x0414
	vec3_t m_vecMins;  // 0x0418
	vec3_t m_vecMaxs;  // 0x0424
	int32_t m_usSolidFlags;  // 0x0430
	int32_t m_nSolidType;  // 0x0432
	int32_t m_triggerBloat;  // 0x0433
	char pad_043a[3];  // 0x0437
	int32_t m_nSurroundType;  // 0x043a
	vec3_t m_vecSpecifiedSurroundingMins;  // 0x043c
	vec3_t m_vecSpecifiedSurroundingMaxs;  // 0x0448
	char pad_0b6c[1816];  // 0x0454
	int32_t m_Color1;  // 0x0b6c
	int32_t m_Color2;  // 0x0b70
	char *m_MaterialName;  // 0x0b74
	char pad_0c74[252];  // 0x0b78
	float m_ParticleDrawWidth;  // 0x0c74
	float m_ParticleSpacingDistance;  // 0x0c78
	float m_DensityRampSpeed;  // 0x0c7c
	float m_RotationSpeed;  // 0x0c80
	float m_MovementSpeed;  // 0x0c84
	float m_Density;  // 0x0c88
	float m_maxDrawDistance;  // 0x0c8c
	int32_t m_spawnflags;  // 0x0c90
}
```
## CFuncRotating
```cpp
struct CFuncRotating {
	char pad_0120[288];  // 0x0000
	float m_angRotation[0];  // 0x0120
	float m_angRotation[1];  // 0x0124
	float m_angRotation[2];  // 0x0128
	vec3_t m_vecOrigin;  // 0x012c
	char pad_0360[552];  // 0x0138
	int32_t m_flSimulationTime;  // 0x0360
}
```
## CFuncOccluder
```cpp
struct CFuncOccluder {
	char pad_0a80[2688];  // 0x0000
	int32_t m_nOccluderIndex;  // 0x0a80
	int32_t m_bActive;  // 0x0a84
}
```
## CFuncMoveLinear
```cpp
struct CFuncMoveLinear {
	char pad_00f8[248];  // 0x0000
	int32_t m_fFlags;  // 0x00f8
	char pad_0108[12];  // 0x00fc
	vec3_t m_vecVelocity;  // 0x0108
}
```
## CFunc_LOD
```cpp
struct CFunc_LOD {
	char pad_0a80[2688];  // 0x0000
	int32_t m_nDisappearMinDist;  // 0x0a80
	int32_t m_nDisappearMaxDist;  // 0x0a84
}
```
## CTEDust
```cpp
struct CTEDust {
	char pad_001c[28];  // 0x0000
	float m_flSize;  // 0x001c
	float m_flSpeed;  // 0x0020
	vec3_t m_vecDirection;  // 0x0024
}
```
## CFunc_Dust
```cpp
struct CFunc_Dust {
	char pad_0350[848];  // 0x0000
	int32_t m_nModelIndex;  // 0x0350
	char pad_0410[188];  // 0x0354
	void *m_Collision;  // 0x0410
	char pad_0418[4];  // 0x0414
	vec3_t m_vecMins;  // 0x0418
	vec3_t m_vecMaxs;  // 0x0424
	int32_t m_usSolidFlags;  // 0x0430
	int32_t m_nSolidType;  // 0x0432
	int32_t m_triggerBloat;  // 0x0433
	char pad_043a[3];  // 0x0437
	int32_t m_nSurroundType;  // 0x043a
	vec3_t m_vecSpecifiedSurroundingMins;  // 0x043c
	vec3_t m_vecSpecifiedSurroundingMaxs;  // 0x0448
	char pad_0a84[1584];  // 0x0454
	int32_t m_SpawnRate;  // 0x0a84
	float m_flSizeMin;  // 0x0a88
	float m_flSizeMax;  // 0x0a8c
	int32_t m_SpeedMax;  // 0x0a90
	int32_t m_LifetimeMin;  // 0x0a94
	int32_t m_LifetimeMax;  // 0x0a98
	int32_t m_DistMax;  // 0x0a9c
	float m_FallSpeed;  // 0x0aa0
	int32_t m_DustFlags;  // 0x0aa4
}
```
## CBreakableSurface
```cpp
struct CBreakableSurface {
	char pad_0a84[2692];  // 0x0000
	int32_t m_nNumWide;  // 0x0a84
	int32_t m_nNumHigh;  // 0x0a88
	float m_flPanelWidth;  // 0x0a8c
	float m_flPanelHeight;  // 0x0a90
	vec3_t m_vNormal;  // 0x0a94
	vec3_t m_vCorner;  // 0x0aa0
	int32_t m_bIsBroken;  // 0x0aac
	int32_t m_nSurfaceType;  // 0x0ab0
	char pad_0ad4[32];  // 0x0ab4
	void *m_RawPanelBitVec;  // 0x0ad4
}
```
## CFuncAreaPortalWindow
```cpp
struct CFuncAreaPortalWindow {
	char pad_0a80[2688];  // 0x0000
	float m_flFadeStartDist;  // 0x0a80
	float m_flFadeDist;  // 0x0a84
	float m_flTranslucencyLimit;  // 0x0a88
	int32_t m_iBackgroundModelIndex;  // 0x0a8c
}
```
## CFish
```cpp
struct CFish {
	char pad_0350[848];  // 0x0000
	int32_t m_nModelIndex;  // 0x0350
	char pad_0357[3];  // 0x0354
	int32_t m_lifeState;  // 0x0357
	char pad_0e00[2725];  // 0x035b
	float m_x;  // 0x0e00
	float m_y;  // 0x0e04
	float m_z;  // 0x0e08
	char pad_0e10[4];  // 0x0e0c
	float m_angle;  // 0x0e10
	char pad_0e24[16];  // 0x0e14
	float m_waterLevel;  // 0x0e24
}
```
## CFireSmoke
```cpp
struct CFireSmoke {
	char pad_0a80[2688];  // 0x0000
	float m_flStartScale;  // 0x0a80
	float m_flScale;  // 0x0a84
	float m_flScaleTime;  // 0x0a88
	int32_t m_nFlags;  // 0x0a8c
	int32_t m_nFlameModelIndex;  // 0x0a90
	int32_t m_nFlameFromAboveModelIndex;  // 0x0a94
}
```
## CEnvTonemapController
```cpp
struct CEnvTonemapController {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bUseCustomAutoExposureMin;  // 0x0a80
	int32_t m_bUseCustomAutoExposureMax;  // 0x0a81
	int32_t m_bUseCustomBloomScale;  // 0x0a82
	float m_flCustomAutoExposureMin;  // 0x0a84
	float m_flCustomAutoExposureMax;  // 0x0a88
	float m_flCustomBloomScale;  // 0x0a8c
	float m_flCustomBloomScaleMinimum;  // 0x0a90
	float m_flBloomExponent;  // 0x0a94
	float m_flBloomSaturation;  // 0x0a98
}
```
## CEnvScreenEffect
```cpp
struct CEnvScreenEffect {
	char pad_0a80[2688];  // 0x0000
	float m_flDuration;  // 0x0a80
	int32_t m_nType;  // 0x0a84
}
```
## CEnvScreenOverlay
```cpp
struct CEnvScreenOverlay {
	char *m_iszOverlayNames;  // 0x0000
	char pad_0a80[2684];  // 0x0004
	char *m_iszOverlayNames[0];  // 0x0a80
	char pad_1478[2548];  // 0x0a84
	float m_flOverlayTimes[0];  // 0x1478
	char pad_14a0[36];  // 0x147c
	float m_flStartTime;  // 0x14a0
	int32_t m_iDesiredOverlay;  // 0x14a4
	int32_t m_bIsActive;  // 0x14a8
}
```
## CEnvProjectedTexture
```cpp
struct CEnvProjectedTexture {
	char pad_0a84[2692];  // 0x0000
	int32_t m_hTargetEntity;  // 0x0a84
	int32_t m_bState;  // 0x0a88
	int32_t m_bAlwaysUpdate;  // 0x0a89
	float m_flLightFOV;  // 0x0a8c
	int32_t m_bEnableShadows;  // 0x0a90
	int32_t m_bSimpleProjection;  // 0x0a91
	int32_t m_bLightOnlyTarget;  // 0x0a92
	int32_t m_bLightWorld;  // 0x0a93
	int32_t m_bCameraSpace;  // 0x0a94
	float m_flBrightnessScale;  // 0x0a98
	int32_t m_LightColor;  // 0x0a9c
	char pad_0ab0[16];  // 0x0aa0
	float m_flColorTransitionTime;  // 0x0ab0
	float m_flAmbient;  // 0x0ab4
	float m_flNearZ;  // 0x0ab8
	float m_flFarZ;  // 0x0abc
	char *m_SpotlightTextureName;  // 0x0ac0
	char pad_0bcc[264];  // 0x0ac4
	int32_t m_nSpotlightTextureFrame;  // 0x0bcc
	int32_t m_nShadowQuality;  // 0x0bd0
	int32_t m_iStyle;  // 0x0bd4
	char pad_0be0[8];  // 0x0bd8
	float m_flProjectionSize;  // 0x0be0
	float m_flRotation;  // 0x0be4
}
```
## CFogController
```cpp
struct CFogController {
	char pad_0a84[2692];  // 0x0000
	vec3_t m_fog.dirPrimary;  // 0x0a84
	int32_t m_fog.colorPrimary;  // 0x0a90
	int32_t m_fog.colorSecondary;  // 0x0a94
	int32_t m_fog.colorPrimaryLerpTo;  // 0x0a98
	int32_t m_fog.colorSecondaryLerpTo;  // 0x0a9c
	float m_fog.start;  // 0x0aa0
	float m_fog.end;  // 0x0aa4
	float m_fog.farz;  // 0x0aa8
	float m_fog.maxdensity;  // 0x0aac
	float m_fog.startLerpTo;  // 0x0ab0
	float m_fog.endLerpTo;  // 0x0ab4
	float m_fog.maxdensityLerpTo;  // 0x0ab8
	float m_fog.lerptime;  // 0x0abc
	float m_fog.duration;  // 0x0ac0
	char pad_0ac5[1];  // 0x0ac4
	int32_t m_fog.blend;  // 0x0ac5
	float m_fog.HDRColorScale;  // 0x0ac8
}
```
## CEnvDOFController
```cpp
struct CEnvDOFController {
	char pad_0a80[2688];  // 0x0000
	int32_t m_bDOFEnabled;  // 0x0a80
	float m_flNearBlurDepth;  // 0x0a84
	float m_flNearFocusDepth;  // 0x0a88
	float m_flFarFocusDepth;  // 0x0a8c
	float m_flFarBlurDepth;  // 0x0a90
	float m_flNearBlurRadius;  // 0x0a94
	float m_flFarBlurRadius;  // 0x0a98
}
```
## CEntityParticleTrail
```cpp
struct CEntityParticleTrail {
	char pad_0b68[2920];  // 0x0000
	int32_t m_iMaterialName;  // 0x0b68
	void *m_Info;  // 0x0b6c
	char pad_0b74[4];  // 0x0b70
	float m_flLifetime;  // 0x0b74
	float m_flStartSize;  // 0x0b78
	float m_flEndSize;  // 0x0b7c
	int32_t m_hConstraintEntity;  // 0x0b80
}
```
## CEntityFreezing
```cpp
struct CEntityFreezing {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_vFreezingOrigin;  // 0x0a80
	void *m_flFrozenPerHitbox;  // 0x0a8c
	char pad_0b54[196];  // 0x0a90
	float m_flFrozen;  // 0x0b54
	int32_t m_bFinishFreezing;  // 0x0b58
}
```
## CEntityFlame
```cpp
struct CEntityFlame {
	char pad_0a80[2688];  // 0x0000
	int32_t m_hEntAttached;  // 0x0a80
	char pad_0a94[16];  // 0x0a84
	int32_t m_bCheapEffect;  // 0x0a94
}
```
## CEntityDissolve
```cpp
struct CEntityDissolve {
	char pad_0a84[2692];  // 0x0000
	float m_flStartTime;  // 0x0a84
	float m_flFadeOutStart;  // 0x0a88
	float m_flFadeOutLength;  // 0x0a8c
	float m_flFadeOutModelStart;  // 0x0a90
	float m_flFadeOutModelLength;  // 0x0a94
	float m_flFadeInStart;  // 0x0a98
	float m_flFadeInLength;  // 0x0a9c
	int32_t m_nDissolveType;  // 0x0aa0
	char pad_0aa8[4];  // 0x0aa4
	vec3_t m_vDissolverOrigin;  // 0x0aa8
	int32_t m_nMagnitude;  // 0x0ab4
}
```
## CDynamicLight
```cpp
struct CDynamicLight {
	char pad_0a80[2688];  // 0x0000
	int32_t m_Flags;  // 0x0a80
	int32_t m_LightStyle;  // 0x0a81
	float m_Radius;  // 0x0a84
	int32_t m_Exponent;  // 0x0a88
	float m_InnerAngle;  // 0x0a8c
	float m_OuterAngle;  // 0x0a90
	float m_SpotRadius;  // 0x0a94
}
```
## CColorCorrectionVolume
```cpp
struct CColorCorrectionVolume {
	char pad_0ac8[2760];  // 0x0000
	int32_t m_bEnabled;  // 0x0ac8
	float m_MaxWeight;  // 0x0acc
	float m_FadeDuration;  // 0x0ad0
	float m_Weight;  // 0x0ad4
	char *m_lookupFilename;  // 0x0ad8
}
```
## CColorCorrection
```cpp
struct CColorCorrection {
	char pad_0a80[2688];  // 0x0000
	vec3_t m_vecOrigin;  // 0x0a80
	float m_minFalloff;  // 0x0a8c
	float m_maxFalloff;  // 0x0a90
	float m_flFadeInDuration;  // 0x0a94
	float m_flFadeOutDuration;  // 0x0a98
	float m_flMaxWeight;  // 0x0a9c
	float m_flCurWeight;  // 0x0aa0
	char *m_netLookupFilename;  // 0x0aa4
	char pad_0ba8[256];  // 0x0aa8
	int32_t m_bEnabled;  // 0x0ba8
	int32_t m_bMaster;  // 0x0ba9
	int32_t m_bClientSide;  // 0x0baa
	int32_t m_bExclusive;  // 0x0bab
}
```
## CBreakableProp
```cpp
struct CBreakableProp {
	char pad_0dbc[3516];  // 0x0000
	vec3_t m_qPreferredPlayerCarryAngles;  // 0x0dbc
	int32_t m_bClientPhysics;  // 0x0dc8
}
```
## CBeamSpotlight
```cpp
struct CBeamSpotlight {
	char pad_0a80[2688];  // 0x0000
	int32_t m_nHaloIndex;  // 0x0a80
	int32_t m_nRotationAxis;  // 0x0a84
	float m_flRotationSpeed;  // 0x0a88
	int32_t m_bSpotlightOn;  // 0x0a8c
	int32_t m_bHasDynamicLight;  // 0x0a8d
	float m_flSpotlightMaxLength;  // 0x0a90
	float m_flSpotlightGoalWidth;  // 0x0a94
	float m_flHDRColorScale;  // 0x0a98
}
```
## CBaseToggle
```cpp
struct CBaseToggle {
	char pad_0a94[2708];  // 0x0000
	vec3_t m_vecFinalDest;  // 0x0a94
	int32_t m_movementType;  // 0x0aa0
	float m_flMoveTargetTime;  // 0x0aa4
}
```
## CBasePlayer
```cpp
struct CBasePlayer {
	void *localdata;  // 0x0000
	char pad_00f0[236];  // 0x0004
	int32_t m_nNextThinkTick;  // 0x00f0
	int32_t m_iHealth;  // 0x00f4
	int32_t m_fFlags;  // 0x00f8
	float m_vecViewOffset[0];  // 0x00fc
	float m_vecViewOffset[1];  // 0x0100
	float m_vecViewOffset[2];  // 0x0104
	float m_vecVelocity[0];  // 0x0108
	float m_vecVelocity[1];  // 0x010c
	float m_vecVelocity[2];  // 0x0110
	vec3_t m_vecBaseVelocity;  // 0x0114
	char pad_0138[24];  // 0x0120
	float m_flFriction;  // 0x0138
	char pad_0144[8];  // 0x013c
	int32_t m_hGroundEntity;  // 0x0144
	char pad_0356[526];  // 0x0148
	int32_t m_nWaterLevel;  // 0x0356
	int32_t m_lifeState;  // 0x0357
	char pad_11a4[3657];  // 0x035b
	void *m_iAmmo;  // 0x11a4
	char pad_1398[496];  // 0x11a8
	void *m_Local;  // 0x1398
	void *m_chAreaBits;  // 0x139c
	char pad_13bc[28];  // 0x13a0
	void *m_chAreaPortalBits;  // 0x13bc
	char pad_13dc[28];  // 0x13c0
	float m_flFOVRate;  // 0x13dc
	int32_t m_iHideHUD;  // 0x13e0
	int32_t m_nDuckTimeMsecs;  // 0x13e4
	int32_t m_nDuckJumpTimeMsecs;  // 0x13e8
	int32_t m_nJumpTimeMsecs;  // 0x13ec
	float m_flFallVelocity;  // 0x13f0
	float m_flStepSize;  // 0x13f4
	vec3_t m_vecPunchAngle;  // 0x13f8
	vec3_t m_vecPunchAngleVel;  // 0x1404
	int32_t m_bDucked;  // 0x1410
	int32_t m_bDucking;  // 0x1411
	int32_t m_bInDuckJump;  // 0x1412
	int32_t m_bDrawViewmodel;  // 0x1413
	int32_t m_bWearingSuit;  // 0x1414
	int32_t m_bPoisoned;  // 0x1415
	int32_t m_bAllowAutoMovement;  // 0x1416
	char pad_1488[110];  // 0x141a
	int32_t m_skybox3d.scale;  // 0x1488
	vec3_t m_skybox3d.origin;  // 0x148c
	int32_t m_skybox3d.area;  // 0x1498
	char pad_14a0[4];  // 0x149c
	vec3_t m_skybox3d.fog.dirPrimary;  // 0x14a0
	int32_t m_skybox3d.fog.colorPrimary;  // 0x14ac
	int32_t m_skybox3d.fog.colorSecondary;  // 0x14b0
	char pad_14bc[8];  // 0x14b4
	float m_skybox3d.fog.start;  // 0x14bc
	float m_skybox3d.fog.end;  // 0x14c0
	char pad_14c8[4];  // 0x14c4
	float m_skybox3d.fog.maxdensity;  // 0x14c8
	char pad_14e0[20];  // 0x14cc
	int32_t m_skybox3d.fog.enable;  // 0x14e0
	int32_t m_skybox3d.fog.blend;  // 0x14e1
	float m_skybox3d.fog.HDRColorScale;  // 0x14e4
	char pad_14ec[4];  // 0x14e8
	vec3_t m_audio.localSound[0];  // 0x14ec
	vec3_t m_audio.localSound[1];  // 0x14f8
	vec3_t m_audio.localSound[2];  // 0x1504
	vec3_t m_audio.localSound[3];  // 0x1510
	vec3_t m_audio.localSound[4];  // 0x151c
	vec3_t m_audio.localSound[5];  // 0x1528
	vec3_t m_audio.localSound[6];  // 0x1534
	vec3_t m_audio.localSound[7];  // 0x1540
	int32_t m_audio.soundscapeIndex;  // 0x154c
	int32_t m_audio.localBits;  // 0x1550
	int32_t m_audio.entIndex;  // 0x1554
	char pad_1560[8];  // 0x1558
	int32_t m_hTonemapController;  // 0x1560
	void *pl;  // 0x1564
	char pad_1578[16];  // 0x1568
	int32_t m_iFOV;  // 0x1578
	int32_t m_iFOVStart;  // 0x157c
	char pad_1594[20];  // 0x1580
	int32_t m_ladderSurfaceProps;  // 0x1594
	char pad_159c[4];  // 0x1598
	float m_flFOVTime;  // 0x159c
	char pad_15b0[16];  // 0x15a0
	vec3_t m_vecLadderNormal;  // 0x15b0
	char pad_15e0[36];  // 0x15bc
	int32_t m_iBonusProgress;  // 0x15e0
	int32_t m_iBonusChallenge;  // 0x15e4
	float m_flMaxspeed;  // 0x15e8
	int32_t m_hZoomOwner;  // 0x15ec
	char pad_15fc[12];  // 0x15f0
	int32_t m_vphysicsCollisionState;  // 0x15fc
	char pad_1688[136];  // 0x1600
	int32_t m_afPhysicsFlags;  // 0x1688
	int32_t m_hVehicle;  // 0x168c
	int32_t m_hLastWeapon;  // 0x1690
	int32_t m_hViewModel[0];  // 0x1694
	char pad_16a8[16];  // 0x1698
	int32_t m_fOnTarget;  // 0x16a8
	int32_t m_hUseEntity;  // 0x16ac
	int32_t m_iDefaultFOV;  // 0x16b0
	char pad_16bc[8];  // 0x16b4
	int32_t m_hViewEntity;  // 0x16bc
	int32_t m_bShouldDrawPlayerWhileUsingViewEntity;  // 0x16c0
	int32_t m_hConstraintEntity;  // 0x16c4
	vec3_t m_vecConstraintCenter;  // 0x16c8
	float m_flConstraintRadius;  // 0x16d4
	float m_flConstraintWidth;  // 0x16d8
	float m_flConstraintSpeedFactor;  // 0x16dc
	int32_t m_bConstraintPastRadius;  // 0x16e0
	int32_t m_iObserverMode;  // 0x16e4
	int32_t m_hObserverTarget;  // 0x16e8
	char pad_1708[28];  // 0x16ec
	float m_flDeathTime;  // 0x1708
	char pad_176c[96];  // 0x170c
	int32_t m_nTickBase;  // 0x176c
	char pad_18cc[348];  // 0x1770
	float m_flLaggedMovementValue;  // 0x18cc
	char pad_18ec[28];  // 0x18d0
	char *m_szLastPlaceName;  // 0x18ec
	char pad_1910[32];  // 0x18f0
	int32_t m_ubEFNoInterpParity;  // 0x1910
	char pad_1acc[440];  // 0x1914
	int32_t m_hPostProcessCtrl;  // 0x1acc
	int32_t m_hColorCorrectionCtrl;  // 0x1ad0
	char pad_1ad8[4];  // 0x1ad4
	int32_t m_PlayerFog.m_hCtrl;  // 0x1ad8
}
```
## CBaseFlex
```cpp
struct CBaseFlex {
	char pad_0e20[3616];  // 0x0000
	vec3_t m_viewtarget;  // 0x0e20
	char pad_0e58[44];  // 0x0e2c
	void *m_flexWeight;  // 0x0e58
	char pad_1004[424];  // 0x0e5c
	int32_t m_blinktoggle;  // 0x1004
}
```
## CBaseEntity
```cpp
struct CBaseEntity {
	int32_t movecollide;  // 0x0000
	char pad_006c[104];  // 0x0004
	int32_t m_clrRender;  // 0x006c
	int32_t m_cellbits;  // 0x0070
	char pad_0078[4];  // 0x0074
	int32_t m_cellX;  // 0x0078
	int32_t m_cellY;  // 0x007c
	int32_t m_cellZ;  // 0x0080
	char pad_00e8[100];  // 0x0084
	int32_t m_fEffects;  // 0x00e8
	int32_t m_iTeamNum;  // 0x00ec
	char pad_0120[48];  // 0x00f0
	vec3_t m_angRotation;  // 0x0120
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
	int32_t m_hOwnerEntity;  // 0x0140
	char pad_0148[4];  // 0x0144
	char *m_iName;  // 0x0148
	char pad_024c[256];  // 0x014c
	char *m_iSignifierName;  // 0x024c
	char pad_0350[256];  // 0x0250
	int32_t m_nModelIndex;  // 0x0350
	int32_t m_nRenderFX;  // 0x0352
	int32_t m_nRenderMode;  // 0x0353
	char pad_0360[9];  // 0x0357
	int32_t m_flSimulationTime;  // 0x0360
	char pad_03c0[92];  // 0x0364
	int32_t m_iObjectCapsCache;  // 0x03c0
	char pad_03e0[28];  // 0x03c4
	int32_t m_iParentAttachment;  // 0x03e0
	char pad_03e8[4];  // 0x03e4
	float m_fadeMinDist;  // 0x03e8
	float m_fadeMaxDist;  // 0x03ec
	float m_flFadeScale;  // 0x03f0
	char pad_0410[28];  // 0x03f4
	void *m_Collision;  // 0x0410
	char pad_0418[4];  // 0x0414
	vec3_t m_vecMins;  // 0x0418
	vec3_t m_vecMaxs;  // 0x0424
	int32_t m_usSolidFlags;  // 0x0430
	int32_t m_nSolidType;  // 0x0432
	int32_t m_triggerBloat;  // 0x0433
	char pad_043a[3];  // 0x0437
	int32_t m_nSurroundType;  // 0x043a
	vec3_t m_vecSpecifiedSurroundingMins;  // 0x043c
	vec3_t m_vecSpecifiedSurroundingMaxs;  // 0x0448
	char pad_0490[60];  // 0x0454
	float m_flElasticity;  // 0x0490
	float m_flShadowCastDistance;  // 0x0494
	char pad_0568[208];  // 0x0498
	int32_t m_CollisionGroup;  // 0x0568
	char pad_0a2e[1218];  // 0x056c
	int32_t m_bSimulatedEveryTick;  // 0x0a2e
	int32_t m_bAnimatedEveryTick;  // 0x0a2f
	int32_t m_bAlternateSorting;  // 0x0a30
	int32_t m_nMinCPULevel;  // 0x0a31
	int32_t m_nMaxCPULevel;  // 0x0a32
	int32_t m_nMinGPULevel;  // 0x0a33
	int32_t m_nMaxGPULevel;  // 0x0a34
	int32_t m_iTextureFrameIndex;  // 0x0a35
	char pad_0a40[7];  // 0x0a39
	int32_t m_hEffectEntity;  // 0x0a40
}
```
## CBaseCombatCharacter
```cpp
struct CBaseCombatCharacter {
	void *bcc_localdata;  // 0x0000
	char pad_12e4[4832];  // 0x0004
	int32_t m_hActiveWeapon;  // 0x12e4
}
```
## CBoneFollower
```cpp
struct CBoneFollower {
	char pad_0a80[2688];  // 0x0000
	int32_t m_modelIndex;  // 0x0a80
	int32_t m_solidIndex;  // 0x0a84
}
```
## CBaseAnimating
```cpp
struct CBaseAnimating {
	void *serveranimdata;  // 0x0000
	char pad_0371[877];  // 0x0004
	int32_t m_bClientSideRagdoll;  // 0x0371
	char pad_0a88[1811];  // 0x0375
	int32_t m_nHitboxSet;  // 0x0a88
	char pad_0aa8[28];  // 0x0a8c
	float m_flPlaybackRate;  // 0x0aa8
	int32_t m_nSkin;  // 0x0aac
	int32_t m_nBody;  // 0x0ab0
	int32_t m_nNewSequenceParity;  // 0x0ab4
	int32_t m_nResetEventsParity;  // 0x0ab8
	char pad_0ac4[8];  // 0x0abc
	void *m_flEncodedController;  // 0x0ac4
	char pad_0ad4[12];  // 0x0ac8
	int32_t m_nMuzzleFlashParity;  // 0x0ad4
	char pad_0ae8[16];  // 0x0ad8
	vec3_t m_vecForce;  // 0x0ae8
	int32_t m_nForceBone;  // 0x0af4
	char pad_0b28[48];  // 0x0af8
	int32_t m_bClientSideFrameReset;  // 0x0b28
	float m_flFrozen;  // 0x0b2c
	char pad_0b7c[76];  // 0x0b30
	float m_flModelScale;  // 0x0b7c
	int32_t m_ScaleType;  // 0x0b80
	char pad_0bac[40];  // 0x0b84
	void *m_flPoseParameter;  // 0x0bac
	char pad_0cd4[292];  // 0x0bb0
	int32_t m_bClientSideAnimation;  // 0x0cd4
	char pad_0cf4[28];  // 0x0cd8
	int32_t m_nSequence;  // 0x0cf4
	char pad_0d7c[132];  // 0x0cf8
	int32_t m_hLightingOrigin;  // 0x0d7c
	char pad_0d82[2];  // 0x0d80
	int32_t m_bSuppressAnimSounds;  // 0x0d82
}
```
## CAI_BaseNPC
```cpp
struct CAI_BaseNPC {
	char pad_0357[855];  // 0x0000
	int32_t m_lifeState;  // 0x0357
	char pad_1300[4005];  // 0x035b
	float m_flTimePingEffect;  // 0x1300
	int32_t m_iDeathPose;  // 0x1304
	int32_t m_iDeathFrame;  // 0x1308
	int32_t m_iSpeedModRadius;  // 0x130c
	int32_t m_iSpeedModSpeed;  // 0x1310
	int32_t m_bPerformAvoidance;  // 0x1314
	int32_t m_bIsMoving;  // 0x1315
	int32_t m_bFadeCorpse;  // 0x1316
	int32_t m_bSpeedModActive;  // 0x1317
	int32_t m_bImportanRagdoll;  // 0x1318
}
```
## CBeam
```cpp
struct CBeam {
	char pad_006c[108];  // 0x0000
	int32_t m_clrRender;  // 0x006c
	char pad_00a8[56];  // 0x0070
	vec3_t m_vecOrigin;  // 0x00a8
	char pad_012c[120];  // 0x00b4
	vec3_t m_vecOrigin;  // 0x012c
	char pad_013c[4];  // 0x0138
	int32_t moveparent;  // 0x013c
	char pad_0350[528];  // 0x0140
	int32_t m_nModelIndex;  // 0x0350
	int32_t m_nRenderFX;  // 0x0352
	int32_t m_nRenderMode;  // 0x0353
	char pad_0a80[1833];  // 0x0357
	float m_flFrameRate;  // 0x0a80
	float m_flHDRColorScale;  // 0x0a84
	char pad_0a90[8];  // 0x0a88
	int32_t m_nNumBeamEnts;  // 0x0a90
	char pad_0a98[4];  // 0x0a94
	int32_t m_nHaloIndex;  // 0x0a98
	int32_t m_nBeamType;  // 0x0a9c
	int32_t m_nBeamFlags;  // 0x0aa0
	void *m_hAttachEntity;  // 0x0aa4
	char pad_0acc[36];  // 0x0aa8
	void *m_nAttachIndex;  // 0x0acc
	char pad_0af4[36];  // 0x0ad0
	float m_fWidth;  // 0x0af4
	float m_fEndWidth;  // 0x0af8
	float m_fFadeLength;  // 0x0afc
	float m_fHaloScale;  // 0x0b00
	float m_fAmplitude;  // 0x0b04
	float m_fStartFrame;  // 0x0b08
	float m_fSpeed;  // 0x0b0c
	float m_flFrame;  // 0x0b10
	int32_t m_nClipStyle;  // 0x0b14
	vec3_t m_vecEndPos;  // 0x0b18
}
```
## CBaseViewModel
```cpp
struct CBaseViewModel {
	char pad_00e8[232];  // 0x0000
	int32_t m_fEffects;  // 0x00e8
	char pad_0350[612];  // 0x00ec
	int16_t m_nModelIndex;  // 0x0350
	char pad_0358[6];  // 0x0352
	float m_flAnimTime;  // 0x0358
	char pad_0aa4[1864];  // 0x035c
	float m_flCycle;  // 0x0aa4
	float m_flPlaybackRate;  // 0x0aa8
	int32_t m_nSkin;  // 0x0aac
	int32_t m_nBody;  // 0x0ab0
	int32_t m_nNewSequenceParity;  // 0x0ab4
	int32_t m_nResetEventsParity;  // 0x0ab8
	char pad_0ad4[24];  // 0x0abc
	int32_t m_nMuzzleFlashParity;  // 0x0ad4
	char pad_0cf4[540];  // 0x0ad8
	int32_t m_nSequence;  // 0x0cf4
	char pad_0dc4[204];  // 0x0cf8
	int32_t m_nViewModelIndex;  // 0x0dc4
	int32_t m_nAnimationParity;  // 0x0dc8
	int32_t m_hWeapon;  // 0x0dcc
	int32_t m_hOwner;  // 0x0dd0
	float m_flTimeWeaponIdle;  // 0x0dd4
	int32_t m_Activity;  // 0x0dd8
}
```
## CBaseGrenade
```cpp
struct CBaseGrenade {
	char pad_00f8[248];  // 0x0000
	int32_t m_fFlags;  // 0x00f8
	char pad_0108[12];  // 0x00fc
	vec3_t m_vecVelocity;  // 0x0108
	char pad_11a0[4236];  // 0x0114
	float m_flNextAttack;  // 0x11a0
	char pad_1301[349];  // 0x11a4
	int32_t m_bIsLive;  // 0x1301
	char pad_1304[2];  // 0x1302
	float m_DmgRadius;  // 0x1304
	char pad_1310[11];  // 0x1305
	float m_flDamage;  // 0x1310
	char pad_1318[4];  // 0x1314
	int32_t m_hThrower;  // 0x1318
}
```
## CBaseCombatWeapon
```cpp
struct CBaseCombatWeapon {
	void *LocalWeaponData;  // 0x0000
	char pad_00f0[236];  // 0x0004
	int32_t m_nNextThinkTick;  // 0x00f0
	char pad_0db8[3268];  // 0x00f4
	EHandle m_hOwner;  // 0x0db8
	int32_t m_nViewModelIndex;  // 0x0dbc
	float m_flNextPrimaryAttack;  // 0x0dc0
	float m_flNextSecondaryAttack;  // 0x0dc4
	int32_t m_iViewModelIndex;  // 0x0dc8
	int32_t m_iWorldModelIndex;  // 0x0dcc
	int32_t m_iState;  // 0x0dd0
	int32_t m_iPrimaryAmmoType;  // 0x0dd4
	int32_t m_iSecondaryAmmoType;  // 0x0dd8
	int32_t m_iClip1;  // 0x0ddc
	int32_t m_iClip2;  // 0x0de0
	float m_flTimeWeaponIdle;  // 0x0de4
	float m_flNextEmptySoundTime;  // 0x0de8
	float m_fMinRange1;  // 0x0dec
	float m_fMinRange2;  // 0x0df0
	float m_fMaxRange1;  // 0x0df4
	float m_fMaxRange2;  // 0x0df8
	float m_fFireDuration;  // 0x0dfc
	int32_t m_Activity;  // 0x0e00
	int32_t m_iPrimaryAmmoCount;  // 0x0e04
	int32_t m_iSecondaryAmmoCount;  // 0x0e08
	int32_t m_iszName;  // 0x0e0c
	bool m_bRemoveable;  // 0x0e10
	bool m_bInReload;  // 0x0e11
	bool m_bFireOnEmpty;  // 0x0e12
	bool m_bFiresUnderwater;  // 0x0e13
	bool m_bAltFiresUnderwater;  // 0x0e14
	bool m_bReloadsSingly;  // 0x0e15
}
```
## C_BaseAnimating
```cpp
struct C_BaseAnimating {
	char pad_0aa0[2720];  // 0x0000
	int32_t m_nPrevSequence;  // 0x0aa0
	float m_flCycle;  // 0x0aa4
	float m_flPlaybackRate;  // 0x0aa8
	int32_t m_nSkin;  // 0x0aac
	int32_t m_nBody;  // 0x0ab0
	int32_t m_nNewSequenceParity;  // 0x0ab4
	int32_t m_nResetEventsParity;  // 0x0ab8
	char pad_0ac4[8];  // 0x0abc
	float m_flEncodedController;  // 0x0ac4
	char pad_0ad4[12];  // 0x0ac8
	char m_nMuzzleFlashParity;  // 0x0ad4
	char pad_0cf4[543];  // 0x0ad5
	int32_t m_nSequence;  // 0x0cf4
}
```
## C_BaseCombatCharacter
```cpp
struct C_BaseCombatCharacter {
	char pad_11a0[4512];  // 0x0000
	float m_flNextAttack;  // 0x11a0
	int32_t m_iAmmo;  // 0x11a4
	char pad_1224[124];  // 0x11a8
	EHandle m_hMyWeapons;  // 0x1224
	char pad_12e4[188];  // 0x1228
	EHandle m_hActiveWeapon;  // 0x12e4
}
```
## CPlayerState
```cpp
struct CPlayerState {
	char pad_0004[4];  // 0x0000
	bool deadflag;  // 0x0004
}
```
## CPlayerLocalData
```cpp
struct CPlayerLocalData {
	char pad_003c[60];  // 0x0000
	int32_t m_nStepside;  // 0x003c
	int32_t m_nOldButtons;  // 0x0040
	float m_flFOVRate;  // 0x0044
	int32_t m_iHideHUD;  // 0x0048
	int32_t m_nDuckTimeMsecs;  // 0x004c
	int32_t m_nDuckJumpTimeMsecs;  // 0x0050
	int32_t m_nJumpTimeMsecs;  // 0x0054
	float m_flFallVelocity;  // 0x0058
	float m_flStepSize;  // 0x005c
	vec3_t m_vecPunchAngle;  // 0x0060
	vec3_t m_vecPunchAngleVel;  // 0x006c
	bool m_bDucked;  // 0x0078
	bool m_bDucking;  // 0x0079
	bool m_bInDuckJump;  // 0x007a
	bool m_bDrawViewmodel;  // 0x007b
	bool m_bWearingSuit;  // 0x007c
	bool m_bPoisoned;  // 0x007d
	bool m_bAllowAutoMovement;  // 0x007e
}
```
## C_BasePlayer
```cpp
struct C_BasePlayer {
	char pad_00f0[240];  // 0x0000
	int32_t m_nNextThinkTick;  // 0x00f0
	int32_t m_iHealth;  // 0x00f4
	char pad_0114[28];  // 0x00f8
	vec3_t m_vecBaseVelocity;  // 0x0114
	char pad_0144[36];  // 0x0120
	EHandle m_hGroundEntity;  // 0x0144
	char pad_0356[526];  // 0x0148
	char m_nWaterLevel;  // 0x0356
	char m_lifeState;  // 0x0357
	char pad_1398[4160];  // 0x0358
	void *m_Local;  // 0x1398
	char pad_1564[456];  // 0x139c
	void *pl;  // 0x1564
	char pad_1578[16];  // 0x1568
	int32_t m_iFOV;  // 0x1578
	int32_t m_iFOVStart;  // 0x157c
	int32_t m_afButtonLast;  // 0x1580
	int32_t m_afButtonPressed;  // 0x1584
	int32_t m_afButtonReleased;  // 0x1588
	int32_t m_nButtons;  // 0x158c
	int32_t m_nImpulse;  // 0x1590
	int32_t m_ladderSurfaceProps;  // 0x1594
	int32_t m_flPhysics;  // 0x1598
	float m_flFOVTime;  // 0x159c
	float m_flWaterJumpTime;  // 0x15a0
	float m_flSwimSoundTime;  // 0x15a4
	float m_flStepSoundTime;  // 0x15a8
	float m_surfaceFriction;  // 0x15ac
	vec3_t m_vecLadderNormal;  // 0x15b0
	char m_szAnimExtension;  // 0x15bc
	char pad_15e0[35];  // 0x15bd
	int32_t m_iBonusProgress;  // 0x15e0
	int32_t m_iBonusChallenge;  // 0x15e4
	float m_flMaxspeed;  // 0x15e8
	EHandle m_hZoomOwner;  // 0x15ec
	char pad_15fc[12];  // 0x15f0
	int32_t m_vphysicsCollisionState;  // 0x15fc
	vec3_t m_oldOrigin;  // 0x1600
	bool m_bTouchedPhysObject;  // 0x160c
	bool m_bPhysicsWasFrozen;  // 0x160d
	char pad_1610[2];  // 0x160e
	vec3_t m_vNewVPhysicsPosition;  // 0x1610
	vec3_t m_vNewVPhysicsVelocity;  // 0x161c
	char pad_1688[96];  // 0x1628
	int32_t m_afPhysicsFlags;  // 0x1688
	EHandle m_hVehicle;  // 0x168c
	EHandle m_hLastWeapon;  // 0x1690
	EHandle m_hViewModel;  // 0x1694
	char pad_16a8[16];  // 0x1698
	bool m_fOnTarget;  // 0x16a8
	char pad_176c[195];  // 0x16a9
	int32_t m_nTickBase;  // 0x176c
	char pad_18e0[368];  // 0x1770
	vec3_t m_vecPreviouslyPredictedOrigin;  // 0x18e0
}
```
## C_ColorCorrectionVolume
```cpp
struct C_ColorCorrectionVolume {
	char pad_0ad4[2772];  // 0x0000
	float m_Weight;  // 0x0ad4
}
```
## C_PlayerResource
```cpp
struct C_PlayerResource {
	char pad_0a84[2692];  // 0x0000
	char *m_szName;  // 0x0a84
	char pad_0b0c[132];  // 0x0a88
	int32_t m_iPing;  // 0x0b0c
	char pad_0b94[132];  // 0x0b10
	int32_t m_iScore;  // 0x0b94
	char pad_0c1c[132];  // 0x0b98
	int32_t m_iDeaths;  // 0x0c1c
	char pad_0ca4[132];  // 0x0c20
	bool m_bConnected;  // 0x0ca4
	char pad_0cc8[35];  // 0x0ca5
	int32_t m_iTeam;  // 0x0cc8
	char pad_0d50[132];  // 0x0ccc
	bool m_bAlive;  // 0x0d50
	char pad_0d74[35];  // 0x0d51
	int32_t m_iHealth;  // 0x0d74
}
```
## C_Team
```cpp
struct C_Team {
	char pad_0a94[2708];  // 0x0000
	char m_szTeamname;  // 0x0a94
	char pad_0ab4[31];  // 0x0a95
	int32_t m_iScore;  // 0x0ab4
	int32_t m_iRoundsWon;  // 0x0ab8
	int32_t m_iDeaths;  // 0x0abc
	int32_t m_iPing;  // 0x0ac0
	int32_t m_iPacketloss;  // 0x0ac4
	int32_t m_iTeamNum;  // 0x0ac8
}
```
## CCollisionProperty
```cpp
struct CCollisionProperty {
	char pad_0008[8];  // 0x0000
	vec3_t m_vecMins;  // 0x0008
	vec3_t m_vecMaxs;  // 0x0014
	int16_t m_usSolidFlags;  // 0x0020
	char m_nSolidType;  // 0x0022
	char m_triggerBloat;  // 0x0023
}
```
## IntervalTimer
```cpp
struct IntervalTimer {
	char pad_0004[4];  // 0x0000
	float m_timestamp;  // 0x0004
}
```
## CountdownTimer
```cpp
struct CountdownTimer {
	char pad_0004[4];  // 0x0000
	float m_duration;  // 0x0004
	float m_timestamp;  // 0x0008
}
```
## C_BaseHLPlayer
```cpp
struct C_BaseHLPlayer {
	char pad_1b20[6944];  // 0x0000
	void *m_HL2Local;  // 0x1b20
	char pad_1b88[100];  // 0x1b24
	bool m_fIsSprinting;  // 0x1b88
}
```
## C_HL2PlayerLocalData
```cpp
struct C_HL2PlayerLocalData {
	char pad_0030[48];  // 0x0000
	EHandle m_hLadder;  // 0x0030
}
```
## C_Portal_Base2D
```cpp
struct C_Portal_Base2D {
	char pad_0dbc[3516];  // 0x0000
	VMatrix m_matrixThisToLinked;  // 0x0dbc
	char pad_1014[536];  // 0x0dfc
	vec3_t m_ptOrigin;  // 0x1014
	vec3_t m_vForward;  // 0x1020
	vec3_t m_vUp;  // 0x102c
	vec3_t m_vRight;  // 0x1038
	vec3_t m_qAbsAngle;  // 0x1044
	char pad_106c[28];  // 0x1050
	EHandle m_hLinkedPortal;  // 0x106c
	char pad_1074[4];  // 0x1070
	void *m_plane_Origin;  // 0x1074
	char pad_34f0[9336];  // 0x1078
	bool m_bActivated;  // 0x34f0
	bool m_bOldActivatedState;  // 0x34f1
}
```
## C_Portal_Player
```cpp
struct C_Portal_Player {
	char pad_0aa4[2724];  // 0x0000
	float m_flCycle;  // 0x0aa4
	float m_flPlaybackRate;  // 0x0aa8
	int32_t m_nSkin;  // 0x0aac
	int32_t m_nBody;  // 0x0ab0
	int32_t m_nNewSequenceParity;  // 0x0ab4
	int32_t m_nResetEventsParity;  // 0x0ab8
	char pad_0ac4[8];  // 0x0abc
	float m_flEncodedController;  // 0x0ac4
	char pad_0cf4[556];  // 0x0ac8
	int32_t m_nSequence;  // 0x0cf4
	char pad_1c58[3936];  // 0x0cf8
	EHandle m_hPortalEnvironment;  // 0x1c58
	char pad_1c68[12];  // 0x1c5c
	void *m_PortalLocal;  // 0x1c68
	char pad_1e80[532];  // 0x1c6c
	float m_flHullHeight;  // 0x1e80
	char pad_22bc[1080];  // 0x1e84
	float m_fLatestServerTeleport;  // 0x22bc
	VMatrix m_matLatestServerTeleportationInverseMatrix;  // 0x22c0
	void *m_CachedJumpPower;  // 0x2300
	char pad_2350[76];  // 0x2304
	float m_flCachedJumpPowerTime;  // 0x2350
	float m_flUsePostTeleportationBoxTime;  // 0x2354
	float m_flSpeedDecelerationTime;  // 0x2358
	char pad_2362[6];  // 0x235c
	bool m_bJumpWasPressedWhenForced;  // 0x2362
}
```
## C_PropEnergyBall
```cpp
struct C_PropEnergyBall {
	char pad_0de0[3552];  // 0x0000
	bool m_bIsInfiniteLife;  // 0x0de0
	char pad_0de4[3];  // 0x0de1
	float m_fTimeTillDeath;  // 0x0de4
}
```
## C_Prop_Portal
```cpp
struct C_Prop_Portal {
	char pad_3548[13640];  // 0x0000
	int32_t m_nPlacementAttemptParity;  // 0x3548
}
```
## CPortalPlayerShared
```cpp
struct CPortalPlayerShared {
	char pad_0004[4];  // 0x0000
	int32_t m_nPlayerCond;  // 0x0004
}
```
## C_WeaponPaintGun
```cpp
struct C_WeaponPaintGun {
	char pad_0ebc[3772];  // 0x0000
	int32_t m_nCurrentColor;  // 0x0ebc
	bool m_bFiringPaint;  // 0x0ec0
	bool m_bFiringErase;  // 0x0ec1
	char pad_0ec4[2];  // 0x0ec2
	int32_t m_nPaintAmmo;  // 0x0ec4
	bool m_bHasPaint;  // 0x0ec8
	char pad_0ee4[27];  // 0x0ec9
	int32_t m_PaintAmmoPerType;  // 0x0ee4
}
```
## PaintPowerInfo_t
```cpp
struct PaintPowerInfo_t {
	char pad_0004[4];  // 0x0000
	vec3_t m_SurfaceNormal;  // 0x0004
	vec3_t m_ContactPoint;  // 0x0010
	int32_t m_PaintPowerType;  // 0x001c
	EHandle m_HandleToOther;  // 0x0020
	int32_t m_State;  // 0x0024
	bool m_IsOnThinSurface;  // 0x0028
}
```
## C_BaseProjectedEntity
```cpp
struct C_BaseProjectedEntity {
	char pad_0aa4[2724];  // 0x0000
	EHandle m_hHitPortal;  // 0x0aa4
	EHandle m_hSourcePortal;  // 0x0aa8
	vec3_t m_vecSourcePortalCenter;  // 0x0aac
	vec3_t m_vecSourcePortalRemoteCenter;  // 0x0ab8
	vec3_t m_vecSourcePortalAngle;  // 0x0ac4
	vec3_t m_vecSourcePortalRemoteAngle;  // 0x0ad0
	vec3_t m_vecStartPoint;  // 0x0adc
	vec3_t m_vecEndPoint;  // 0x0ae8
	char pad_0af8[4];  // 0x0af4
	EHandle m_hPlacementHelper;  // 0x0af8
}
```
## C_PortalPlayerLocalData
```cpp
struct C_PortalPlayerLocalData {
	char pad_00a0[160];  // 0x0000
	vec3_t m_StickNormal;  // 0x00a0
	vec3_t m_OldStickNormal;  // 0x00ac
	vec3_t m_vPreUpdateVelocity;  // 0x00b8
	vec3_t m_Up;  // 0x00c4
	vec3_t m_vStickRotationAxis;  // 0x00d0
	vec3_t m_StandHullMin;  // 0x00dc
	vec3_t m_StandHullMax;  // 0x00e8
	vec3_t m_DuckHullMin;  // 0x00f4
	vec3_t m_DuckHullMax;  // 0x0100
	vec3_t m_CachedStandHullMinAttempt;  // 0x010c
	vec3_t m_CachedStandHullMaxAttempt;  // 0x0118
	vec3_t m_CachedDuckHullMinAttempt;  // 0x0124
	vec3_t m_CachedDuckHullMaxAttempt;  // 0x0130
	vec3_t m_vLocalUp;  // 0x013c
	vec3_t m_vEyeOffset;  // 0x0148
	vec3_t m_qQuaternionPunch;  // 0x0154
	char pad_0170[16];  // 0x0160
	float m_flAirInputScale;  // 0x0170
	float m_flCurrentStickTime;  // 0x0174
	int32_t m_nStickCameraState;  // 0x0178
	int32_t m_InAirState;  // 0x017c
	bool m_bDoneStickInterp;  // 0x0180
	bool m_bDoneCorrectPitch;  // 0x0181
	char pad_0183[1];  // 0x0182
	bool m_bJumpedThisFrame;  // 0x0183
	bool m_bBouncedThisFrame;  // 0x0184
	bool m_bDuckedInAir;  // 0x0185
	char pad_0188[2];  // 0x0186
	EHandle m_hTractorBeam;  // 0x0188
	char pad_0190[4];  // 0x018c
	bool m_bZoomedIn;  // 0x0190
	char pad_0194[3];  // 0x0191
	float m_fBouncedTime;  // 0x0194
	bool m_bPreventedCrouchJumpThisFrame;  // 0x0198
}
```
## C_ProjectedWallEntity
```cpp
struct C_ProjectedWallEntity {
	char pad_0b80[2944];  // 0x0000
	float m_vWorldSpace_WallMins;  // 0x0b80
	char pad_0b8c[8];  // 0x0b84
	float m_vWorldSpace_WallMaxs;  // 0x0b8c
	char pad_0bac[28];  // 0x0b90
	int32_t m_pActiveCollideable;  // 0x0bac
	float m_flLength;  // 0x0bb0
	float m_flWidth;  // 0x0bb4
	float m_flHeight;  // 0x0bb8
	char pad_0bf0[52];  // 0x0bbc
	float m_flParticleUpdateTime;  // 0x0bf0
}
```
## C_PropTractorBeamProjector
```cpp
struct C_PropTractorBeamProjector {
	char pad_0aa4[2724];  // 0x0000
	float m_flCycle;  // 0x0aa4
	float m_flPlaybackRate;  // 0x0aa8
}
```
## C_TriggerCatapult
```cpp
struct C_TriggerCatapult {
	char pad_0abc[2748];  // 0x0000
	float m_flRefireDelay;  // 0x0abc
}
```
## C_Trigger_TractorBeam
```cpp
struct C_Trigger_TractorBeam {
	char pad_0aa4[2724];  // 0x0000
	vec3_t m_vStart;  // 0x0aa4
	vec3_t m_vEnd;  // 0x0ab0
}
```
## C_WeaponPortalgun
```cpp
struct C_WeaponPortalgun {
	char pad_0e98[3736];  // 0x0000
	bool m_bCanFirePortal1;  // 0x0e98
	bool m_bCanFirePortal2;  // 0x0e99
	char pad_0e9c[2];  // 0x0e9a
	int32_t m_iLastFiredPortal;  // 0x0e9c
	bool m_bOpenProngs;  // 0x0ea0
	char pad_0ed4[51];  // 0x0ea1
	int32_t m_EffectState;  // 0x0ed4
}
```
## CBasePortalCombatWeapon
```cpp
struct CBasePortalCombatWeapon {
	char pad_0e84[3716];  // 0x0000
	float m_flNextRepeatPrimaryAttack;  // 0x0e84
	float m_flNextRepeatSecondaryAttack;  // 0x0e88
}
```
