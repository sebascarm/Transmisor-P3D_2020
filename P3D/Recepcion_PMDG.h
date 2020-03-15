#pragma once

//------------------------------------------------//
//--     PROCESAR RECEPCION DE PMDG (SIM)		  //
//------------------------------------------------//
void P3D_Base::Recepcion_PMDG(PMDG_NG3_Data* pS) {
	// Aft overhead
	//------------------------------------------
	if (AFT_OVERHEAD) {
		// ADIRU
		Controlar(pS->IRS_DisplaySelector, Est_PMDG.IRS_DisplaySelector, "IRS_DisplaySelector");		// Positions 0..4
		Controlar(pS->IRS_SysDisplay_R, Est_PMDG.IRS_SysDisplay_R, "IRS_SysDisplay_R");					// false: L  true: R
		Controlar(pS->IRS_annunGPS, Est_PMDG.IRS_annunGPS, "IRS_annunGPS");
		Controlar(pS->IRS_annunALIGN[0], Est_PMDG.IRS_annunALIGN[0], "IRS_annunALIGN[0]");
		Controlar(pS->IRS_annunALIGN[1], Est_PMDG.IRS_annunALIGN[1], "IRS_annunALIGN[1]");
		Controlar(pS->IRS_annunALIGN[0], Est_PMDG.IRS_annunALIGN[0], "IRS_annunALIGN[0]");
		Controlar(pS->IRS_annunALIGN[1], Est_PMDG.IRS_annunALIGN[1], "IRS_annunALIGN[1]");
		Controlar(pS->IRS_annunON_DC[0], Est_PMDG.IRS_annunON_DC[0], "IRS_annunON_DC[0]");
		Controlar(pS->IRS_annunON_DC[1], Est_PMDG.IRS_annunON_DC[1], "IRS_annunON_DC[1]");
		Controlar(pS->IRS_annunFAULT[0], Est_PMDG.IRS_annunFAULT[0], "IRS_annunFAULT[0]");
		Controlar(pS->IRS_annunFAULT[1], Est_PMDG.IRS_annunFAULT[1], "IRS_annunFAULT[1]");
		Controlar(pS->IRS_annunDC_FAIL[0], Est_PMDG.IRS_annunDC_FAIL[0], "IRS_annunDC_FAIL[0]");
		Controlar(pS->IRS_annunDC_FAIL[1], Est_PMDG.IRS_annunDC_FAIL[1], "IRS_annunDC_FAIL[1]");
		Controlar(pS->IRS_ModeSelector[0], Est_PMDG.IRS_ModeSelector[0], "IRS_ModeSelector[0]");		// 0: OFF  1: ALIGN  2: NAV  3: ATT
		Controlar(pS->IRS_ModeSelector[1], Est_PMDG.IRS_ModeSelector[1], "IRS_ModeSelector[1]");		// 0: OFF  1: ALIGN  2: NAV  3: ATT
	// PSEU
		Controlar(pS->WARN_annunPSEU, Est_PMDG.WARN_annunPSEU, "WARN_annunPSEU");
		// Service Interphone
		Controlar(pS->COMM_ServiceInterphoneSw, Est_PMDG.COMM_ServiceInterphoneSw, "COMM_ServiceInterphoneSw");
		// Lights
		Controlar(pS->LTS_DomeWhiteSw, Est_PMDG.LTS_DomeWhiteSw, "LTS_DomeWhiteSw");					// 0: DIM  1: OFF  2: BRIGHT
		// Engine
		Controlar(pS->ENG_EECSwitch[0], Est_PMDG.ENG_EECSwitch[0], "ENG_EECSwitch[0]");
		Controlar(pS->ENG_EECSwitch[1], Est_PMDG.ENG_EECSwitch[1], "ENG_EECSwitch[1]");
		Controlar(pS->ENG_annunREVERSER[0], Est_PMDG.ENG_annunREVERSER[0], "ENG_annunREVERSER[0]");
		Controlar(pS->ENG_annunREVERSER[1], Est_PMDG.ENG_annunREVERSER[1], "ENG_annunREVERSER[1]");
		Controlar(pS->ENG_annunENGINE_CONTROL[0], Est_PMDG.ENG_annunENGINE_CONTROL[0], "ENG_annunENGINE_CONTROL[0]");
		Controlar(pS->ENG_annunENGINE_CONTROL[1], Est_PMDG.ENG_annunENGINE_CONTROL[1], "ENG_annunENGINE_CONTROL[1]");
		Controlar(pS->ENG_annunALTN[0], Est_PMDG.ENG_annunALTN[0], "ENG_annunALTN[0]");
		Controlar(pS->ENG_annunALTN[1], Est_PMDG.ENG_annunALTN[1], "ENG_annunALTN[1]");
		// Oxygen
		Controlar(pS->OXY_Needle, Est_PMDG.OXY_Needle, "OXY_Needle");									// Position 0...240
		Controlar(pS->OXY_SwNormal, Est_PMDG.OXY_SwNormal, "OXY_SwNormal");								// true: NORMAL  false: ON
		Controlar(pS->OXY_annunPASS_OXY_ON, Est_PMDG.OXY_annunPASS_OXY_ON, "OXY_annunPASS_OXY_ON");
		// Gear
		Controlar(pS->GEAR_annunOvhdLEFT, Est_PMDG.GEAR_annunOvhdLEFT, "GEAR_annunOvhdLEFT");
		Controlar(pS->GEAR_annunOvhdNOSE, Est_PMDG.GEAR_annunOvhdNOSE, "GEAR_annunOvhdNOSE");
		Controlar(pS->GEAR_annunOvhdRIGHT, Est_PMDG.GEAR_annunOvhdRIGHT, "GEAR_annunOvhdRIGHT");
		// Flight recorder
		Controlar(pS->FLTREC_SwNormal, Est_PMDG.FLTREC_SwNormal, "FLTREC_SwNormal");					// true: NORMAL  false: TEST
		Controlar(pS->FLTREC_annunOFF, Est_PMDG.FLTREC_annunOFF, "FLTREC_annunOFF");
	};

	// Forward overhead
	//------------------------------------------
	if (FORWARD_OVERHEAD) {
		// Flight Controls
		Controlar(pS->FCTL_FltControl_Sw[0], Est_PMDG.FCTL_FltControl_Sw[0], "FCTL_FltControl_Sw[0]");				// 0: STBY/RUD  1: OFF  2: ON
		Controlar(pS->FCTL_FltControl_Sw[1], Est_PMDG.FCTL_FltControl_Sw[1], "FCTL_FltControl_Sw[1]");				// 0: STBY/RUD  1: OFF  2: ON
		Controlar(pS->FCTL_Spoiler_Sw[0], Est_PMDG.FCTL_Spoiler_Sw[0], "FCTL_Spoiler_Sw[0]");						// true: ON  false: OFF  
		Controlar(pS->FCTL_Spoiler_Sw[1], Est_PMDG.FCTL_Spoiler_Sw[1], "FCTL_Spoiler_Sw[1]");						// true: ON  false: OFF  
		Controlar(pS->FCTL_YawDamper_Sw, Est_PMDG.FCTL_YawDamper_Sw, "FCTL_YawDamper_Sw");
		Controlar(pS->FCTL_AltnFlaps_Sw_ARM, Est_PMDG.FCTL_AltnFlaps_Sw_ARM, "FCTL_AltnFlaps_Sw_ARM");				// true: ARM  false: OFF
		Controlar(pS->FCTL_AltnFlaps_Control_Sw, Est_PMDG.FCTL_AltnFlaps_Control_Sw, "FCTL_AltnFlaps_Control_Sw");			// 0: UP  1: OFF  2: DOWN
		Controlar(pS->FCTL_annunFC_LOW_PRESSURE[0], Est_PMDG.FCTL_annunFC_LOW_PRESSURE[0], "FCTL_annunFC_LOW_PRESSURE[0]");		// FLT CONTROL
		Controlar(pS->FCTL_annunFC_LOW_PRESSURE[1], Est_PMDG.FCTL_annunFC_LOW_PRESSURE[1], "FCTL_annunFC_LOW_PRESSURE[1]");		// FLT CONTROL
		Controlar(pS->FCTL_annunYAW_DAMPER, Est_PMDG.FCTL_annunYAW_DAMPER, "FCTL_annunYAW_DAMPER");
		Controlar(pS->FCTL_annunLOW_QUANTITY, Est_PMDG.FCTL_annunLOW_QUANTITY, "FCTL_annunLOW_QUANTITY");
		Controlar(pS->FCTL_annunLOW_PRESSURE, Est_PMDG.FCTL_annunLOW_PRESSURE, "FCTL_annunLOW_PRESSURE");
		Controlar(pS->FCTL_annunLOW_STBY_RUD_ON, Est_PMDG.FCTL_annunLOW_STBY_RUD_ON, "FCTL_annunLOW_STBY_RUD_ON");
		Controlar(pS->FCTL_annunFEEL_DIFF_PRESS, Est_PMDG.FCTL_annunFEEL_DIFF_PRESS, "FCTL_annunFEEL_DIFF_PRESS");
		Controlar(pS->FCTL_annunSPEED_TRIM_FAIL, Est_PMDG.FCTL_annunSPEED_TRIM_FAIL, "FCTL_annunSPEED_TRIM_FAIL");
		Controlar(pS->FCTL_annunMACH_TRIM_FAIL, Est_PMDG.FCTL_annunMACH_TRIM_FAIL, "FCTL_annunMACH_TRIM_FAIL");
		Controlar(pS->FCTL_annunAUTO_SLAT_FAIL, Est_PMDG.FCTL_annunAUTO_SLAT_FAIL, "FCTL_annunAUTO_SLAT_FAIL");
		// Navigation/Displays
		Controlar(pS->NAVDIS_VHFNavSelector, Est_PMDG.NAVDIS_VHFNavSelector, "NAVDIS_VHFNavSelector");				// 0: BOTH ON 1  1: NORMAL  2: BOTH ON 2
		Controlar(pS->NAVDIS_IRSSelector, Est_PMDG.NAVDIS_IRSSelector, "NAVDIS_IRSSelector");						// 0: BOTH ON L  1: NORMAL  2: BOTH ON R
		Controlar(pS->NAVDIS_FMCSelector, Est_PMDG.NAVDIS_FMCSelector, "NAVDIS_FMCSelector");						// 0: BOTH ON L  1: NORMAL  2: BOTH ON R
		Controlar(pS->NAVDIS_SourceSelector, Est_PMDG.NAVDIS_SourceSelector, "NAVDIS_SourceSelector");				// 0: ALL ON 1   1: AUTO    2: ALL ON 2
		Controlar(pS->NAVDIS_ControlPaneSelector, Est_PMDG.NAVDIS_ControlPaneSelector, "NAVDIS_ControlPaneSelector");			// 0: BOTH ON 1  1: NORMAL  2: BOTH ON 2
		// Fuel
		Controlar(pS->FUEL_FuelTempNeedle, Est_PMDG.FUEL_FuelTempNeedle, "FUEL_FuelTempNeedle");					// Value
		Controlar(pS->FUEL_CrossFeedSw, Est_PMDG.FUEL_CrossFeedSw, "FUEL_CrossFeedSw");
		Controlar(pS->FUEL_PumpFwdSw[0], Est_PMDG.FUEL_PumpFwdSw[0], "FUEL_PumpFwdSw[0]");							// left fwd / right fwd
		Controlar(pS->FUEL_PumpFwdSw[1], Est_PMDG.FUEL_PumpFwdSw[1], "FUEL_PumpFwdSw[1]");							// left fwd / right fwd
		Controlar(pS->FUEL_PumpAftSw[0], Est_PMDG.FUEL_PumpAftSw[0], "FUEL_PumpAftSw[0]");							// left aft / right aft
		Controlar(pS->FUEL_PumpAftSw[1], Est_PMDG.FUEL_PumpAftSw[1], "FUEL_PumpAftSw[1]");							// left aft / right aft
		Controlar(pS->FUEL_PumpCtrSw[0], Est_PMDG.FUEL_PumpCtrSw[0], "FUEL_PumpCtrSw[0]");							// ctr left / ctr right
		Controlar(pS->FUEL_PumpCtrSw[1], Est_PMDG.FUEL_PumpCtrSw[1], "FUEL_PumpCtrSw[1]");							// ctr left / ctr right
		Controlar(pS->FUEL_AuxFwd[0], Est_PMDG.FUEL_AuxFwd[0], "FUEL_AuxFwd[0]");									// aux fwd A and aux fwd B
		Controlar(pS->FUEL_AuxFwd[1], Est_PMDG.FUEL_AuxFwd[1], "FUEL_AuxFwd[1]");									// aux fwd A and aux fwd B
		Controlar(pS->FUEL_AuxAft[0], Est_PMDG.FUEL_AuxAft[0], "FUEL_AuxAft[0]");									//aux aft A and aux aft B
		Controlar(pS->FUEL_AuxAft[1], Est_PMDG.FUEL_AuxAft[1], "FUEL_AuxAft[1]");									//aux aft A and aux aft B
		Controlar(pS->FUEL_FWDBleed, Est_PMDG.FUEL_FWDBleed, "FUEL_FWDBleed");
		Controlar(pS->FUEL_AFTBleed, Est_PMDG.FUEL_AFTBleed, "FUEL_AFTBleed");
		Controlar(pS->FUEL_GNDXfr, Est_PMDG.FUEL_GNDXfr, "FUEL_GNDXfr");
		Controlar(pS->FUEL_annunENG_VALVE_CLOSED[0], Est_PMDG.FUEL_annunENG_VALVE_CLOSED[0], "FUEL_annunENG_VALVE_CLOSED[0]");		// 0: Closed  1: Open  2: In transit (bright)
		Controlar(pS->FUEL_annunENG_VALVE_CLOSED[1], Est_PMDG.FUEL_annunENG_VALVE_CLOSED[1], "FUEL_annunENG_VALVE_CLOSED[1]");		// 0: Closed  1: Open  2: In transit (bright)
		Controlar(pS->FUEL_annunSPAR_VALVE_CLOSED[0], Est_PMDG.FUEL_annunSPAR_VALVE_CLOSED[0], "FUEL_annunSPAR_VALVE_CLOSED[0]");	// 0: Closed  1: Open  2: In transit (bright)
		Controlar(pS->FUEL_annunSPAR_VALVE_CLOSED[1], Est_PMDG.FUEL_annunSPAR_VALVE_CLOSED[1], "FUEL_annunSPAR_VALVE_CLOSED[1]");	// 0: Closed  1: Open  2: In transit (bright)
		Controlar(pS->FUEL_annunFILTER_BYPASS[0], Est_PMDG.FUEL_annunFILTER_BYPASS[0], "FUEL_annunFILTER_BYPASS[0]");
		Controlar(pS->FUEL_annunFILTER_BYPASS[1], Est_PMDG.FUEL_annunFILTER_BYPASS[1], "FUEL_annunFILTER_BYPASS[1]");
		Controlar(pS->FUEL_annunXFEED_VALVE_OPEN, Est_PMDG.FUEL_annunXFEED_VALVE_OPEN, "FUEL_annunXFEED_VALVE_OPEN");	// 0: Closed  1: Open  2: In transit (dim)
		Controlar(pS->FUEL_annunLOWPRESS_Fwd[0], Est_PMDG.FUEL_annunLOWPRESS_Fwd[0], "FUEL_annunLOWPRESS_Fwd[0]");
		Controlar(pS->FUEL_annunLOWPRESS_Fwd[1], Est_PMDG.FUEL_annunLOWPRESS_Fwd[1], "FUEL_annunLOWPRESS_Fwd[1]");
		Controlar(pS->FUEL_annunLOWPRESS_Aft[0], Est_PMDG.FUEL_annunLOWPRESS_Aft[0], "FUEL_annunLOWPRESS_Aft[0]");
		Controlar(pS->FUEL_annunLOWPRESS_Aft[1], Est_PMDG.FUEL_annunLOWPRESS_Aft[1], "FUEL_annunLOWPRESS_Aft[1]");
		Controlar(pS->FUEL_annunLOWPRESS_Ctr[0], Est_PMDG.FUEL_annunLOWPRESS_Ctr[0], "FUEL_annunLOWPRESS_Ctr[0]");
		Controlar(pS->FUEL_annunLOWPRESS_Ctr[1], Est_PMDG.FUEL_annunLOWPRESS_Ctr[1], "FUEL_annunLOWPRESS_Ctr[1]");
		// Electrical
		Controlar(pS->ELEC_annunBAT_DISCHARGE, Est_PMDG.ELEC_annunBAT_DISCHARGE, "ELEC_annunBAT_DISCHARGE");
		Controlar(pS->ELEC_annunTR_UNIT, Est_PMDG.ELEC_annunTR_UNIT, "ELEC_annunTR_UNIT");
		Controlar(pS->ELEC_annunELEC, Est_PMDG.ELEC_annunELEC, "ELEC_annunELEC");
		Controlar(pS->ELEC_DCMeterSelector, Est_PMDG.ELEC_DCMeterSelector, "ELEC_DCMeterSelector");					// 0: STBY PWR  1: BAT BUS ... 7: TEST
		Controlar(pS->ELEC_ACMeterSelector, Est_PMDG.ELEC_ACMeterSelector, "ELEC_ACMeterSelector");					// 0: STBY PWR  1: GND PWR ... 6: TEST
		Controlar(pS->ELEC_BatSelector, Est_PMDG.ELEC_BatSelector, "ELEC_BatSelector");								// 0: OFF  1: BAT  2: ON
		Controlar(pS->ELEC_CabUtilSw, Est_PMDG.ELEC_CabUtilSw, "ELEC_CabUtilSw");
		Controlar(pS->ELEC_IFEPassSeatSw, Est_PMDG.ELEC_IFEPassSeatSw, "ELEC_IFEPassSeatSw");
		Controlar(pS->ELEC_annunDRIVE[0], Est_PMDG.ELEC_annunDRIVE[0], "ELEC_annunDRIVE[0]");
		Controlar(pS->ELEC_annunDRIVE[1], Est_PMDG.ELEC_annunDRIVE[1], "ELEC_annunDRIVE[1]");
		Controlar(pS->ELEC_annunSTANDBY_POWER_OFF, Est_PMDG.ELEC_annunSTANDBY_POWER_OFF, "ELEC_annunSTANDBY_POWER_OFF");
		Controlar(pS->ELEC_IDGDisconnectSw[0], Est_PMDG.ELEC_IDGDisconnectSw[0], "ELEC_IDGDisconnectSw[0]");
		Controlar(pS->ELEC_IDGDisconnectSw[1], Est_PMDG.ELEC_IDGDisconnectSw[1], "ELEC_IDGDisconnectSw[1]");
		Controlar(pS->ELEC_StandbyPowerSelector, Est_PMDG.ELEC_StandbyPowerSelector, "ELEC_StandbyPowerSelector");	// 0: BAT  1: OFF  2: AUTO
		Controlar(pS->ELEC_annunGRD_POWER_AVAILABLE, Est_PMDG.ELEC_annunGRD_POWER_AVAILABLE, "ELEC_annunGRD_POWER_AVAILABLE");
		Controlar(pS->ELEC_GrdPwrSw, Est_PMDG.ELEC_GrdPwrSw, "ELEC_GrdPwrSw");
		Controlar(pS->ELEC_BusTransSw_AUTO, Est_PMDG.ELEC_BusTransSw_AUTO, "ELEC_BusTransSw_AUTO");
		Controlar(pS->ELEC_GenSw[0], Est_PMDG.ELEC_GenSw[0], "ELEC_GenSw[0]");
		Controlar(pS->ELEC_GenSw[1], Est_PMDG.ELEC_GenSw[1], "ELEC_GenSw[1]");
		Controlar(pS->ELEC_APUGenSw[0], Est_PMDG.ELEC_APUGenSw[0], "ELEC_APUGenSw[0]");
		Controlar(pS->ELEC_APUGenSw[1], Est_PMDG.ELEC_APUGenSw[1], "ELEC_APUGenSw[1]");
		Controlar(pS->ELEC_annunTRANSFER_BUS_OFF[0], Est_PMDG.ELEC_annunTRANSFER_BUS_OFF[0], "ELEC_annunTRANSFER_BUS_OFF[0]");
		Controlar(pS->ELEC_annunTRANSFER_BUS_OFF[1], Est_PMDG.ELEC_annunTRANSFER_BUS_OFF[1], "ELEC_annunTRANSFER_BUS_OFF[1]");
		Controlar(pS->ELEC_annunSOURCE_OFF[0], Est_PMDG.ELEC_annunSOURCE_OFF[0], "ELEC_annunSOURCE_OFF[0]");
		Controlar(pS->ELEC_annunSOURCE_OFF[1], Est_PMDG.ELEC_annunSOURCE_OFF[1], "ELEC_annunSOURCE_OFF[1]");
		Controlar(pS->ELEC_annunGEN_BUS_OFF[0], Est_PMDG.ELEC_annunGEN_BUS_OFF[0], "ELEC_annunGEN_BUS_OFF[0]");
		Controlar(pS->ELEC_annunGEN_BUS_OFF[1], Est_PMDG.ELEC_annunGEN_BUS_OFF[1], "ELEC_annunGEN_BUS_OFF[1]");
		Controlar(pS->ELEC_annunAPU_GEN_OFF_BUS, Est_PMDG.ELEC_annunAPU_GEN_OFF_BUS, "ELEC_annunAPU_GEN_OFF_BUS");
		// APU
		Controlar(pS->APU_EGTNeedle, Est_PMDG.APU_EGTNeedle, "APU_EGTNeedle");										// Value
		Controlar(pS->APU_annunMAINT, Est_PMDG.APU_annunMAINT, "APU_annunMAINT");
		Controlar(pS->APU_annunLOW_OIL_PRESSURE, Est_PMDG.APU_annunLOW_OIL_PRESSURE, "APU_annunLOW_OIL_PRESSURE");
		Controlar(pS->APU_annunFAULT, Est_PMDG.APU_annunFAULT, "APU_annunFAULT");
		Controlar(pS->APU_annunOVERSPEED, Est_PMDG.APU_annunOVERSPEED, "APU_annunOVERSPEED");
		// Wipers
		Controlar(pS->OH_WiperLSelector, Est_PMDG.OH_WiperLSelector, "OH_WiperLSelector");							// 0: PARK  1: INT  2: LOW  3:HIGH
		Controlar(pS->OH_WiperRSelector, Est_PMDG.OH_WiperRSelector, "OH_WiperRSelector");							// 0: PARK  1: INT  2: LOW  3:HIGH
		// Center overhead controls & indicators
		Controlar(pS->LTS_CircuitBreakerKnob, Est_PMDG.LTS_CircuitBreakerKnob, "LTS_CircuitBreakerKnob");			// Position 0...150
		Controlar(pS->LTS_OvereadPanelKnob, Est_PMDG.LTS_OvereadPanelKnob, "LTS_OvereadPanelKnob");					// Position 0...150
		Controlar(pS->AIR_EquipCoolingSupplyNORM, Est_PMDG.AIR_EquipCoolingSupplyNORM, "AIR_EquipCoolingSupplyNORM");
		Controlar(pS->AIR_EquipCoolingExhaustNORM, Est_PMDG.AIR_EquipCoolingExhaustNORM, "AIR_EquipCoolingExhaustNORM");
		Controlar(pS->AIR_annunEquipCoolingSupplyOFF, Est_PMDG.AIR_annunEquipCoolingSupplyOFF, "AIR_annunEquipCoolingSupplyOFF");
		Controlar(pS->AIR_annunEquipCoolingExhaustOFF, Est_PMDG.AIR_annunEquipCoolingExhaustOFF, "AIR_annunEquipCoolingExhaustOFF");
		Controlar(pS->LTS_annunEmerNOT_ARMED, Est_PMDG.LTS_annunEmerNOT_ARMED, "LTS_annunEmerNOT_ARMED");
		Controlar(pS->LTS_EmerExitSelector, Est_PMDG.LTS_EmerExitSelector, "LTS_EmerExitSelector");					// 0: OFF  1: ARMED  2: ON
		Controlar(pS->COMM_NoSmokingSelector, Est_PMDG.COMM_NoSmokingSelector, "COMM_NoSmokingSelector");			// 0: OFF  1: AUTO   2: ON
		Controlar(pS->COMM_FastenBeltsSelector, Est_PMDG.COMM_FastenBeltsSelector, "COMM_FastenBeltsSelector");		// 0: OFF  1: AUTO   2: ON
		Controlar(pS->COMM_annunCALL, Est_PMDG.COMM_annunCALL, "COMM_annunCALL");
		Controlar(pS->COMM_annunPA_IN_USE, Est_PMDG.COMM_annunPA_IN_USE, "COMM_annunPA_IN_USE");
		// Anti-ice
		Controlar(pS->ICE_annunOVERHEAT[0], Est_PMDG.ICE_annunOVERHEAT[0], "ICE_annunOVERHEAT[0]");
		Controlar(pS->ICE_annunOVERHEAT[1], Est_PMDG.ICE_annunOVERHEAT[1], "ICE_annunOVERHEAT[1]");
		Controlar(pS->ICE_annunOVERHEAT[2], Est_PMDG.ICE_annunOVERHEAT[2], "ICE_annunOVERHEAT[2]");
		Controlar(pS->ICE_annunOVERHEAT[3], Est_PMDG.ICE_annunOVERHEAT[3], "ICE_annunOVERHEAT[3]");
		Controlar(pS->ICE_annunON[0], Est_PMDG.ICE_annunON[0], "ICE_annunON[0]");
		Controlar(pS->ICE_annunON[1], Est_PMDG.ICE_annunON[1], "ICE_annunON[1]");
		Controlar(pS->ICE_annunON[2], Est_PMDG.ICE_annunON[2], "ICE_annunON[2]");
		Controlar(pS->ICE_annunON[3], Est_PMDG.ICE_annunON[3], "ICE_annunON[3]");
		Controlar(pS->ICE_WindowHeatSw[0], Est_PMDG.ICE_WindowHeatSw[0], "ICE_WindowHeatSw[0]");
		Controlar(pS->ICE_WindowHeatSw[1], Est_PMDG.ICE_WindowHeatSw[1], "ICE_WindowHeatSw[1]");
		Controlar(pS->ICE_WindowHeatSw[2], Est_PMDG.ICE_WindowHeatSw[2], "ICE_WindowHeatSw[2]");
		Controlar(pS->ICE_WindowHeatSw[3], Est_PMDG.ICE_WindowHeatSw[3], "ICE_WindowHeatSw[3]");
		Controlar(pS->ICE_annunCAPT_PITOT, Est_PMDG.ICE_annunCAPT_PITOT, "ICE_annunCAPT_PITOT");
		Controlar(pS->ICE_annunL_ELEV_PITOT, Est_PMDG.ICE_annunL_ELEV_PITOT, "ICE_annunL_ELEV_PITOT");
		Controlar(pS->ICE_annunL_ALPHA_VANE, Est_PMDG.ICE_annunL_ALPHA_VANE, "ICE_annunL_ALPHA_VANE");
		Controlar(pS->ICE_annunL_TEMP_PROBE, Est_PMDG.ICE_annunL_TEMP_PROBE, "ICE_annunL_TEMP_PROBE");
		Controlar(pS->ICE_annunFO_PITOT, Est_PMDG.ICE_annunFO_PITOT, "ICE_annunFO_PITOT");
		Controlar(pS->ICE_annunR_ELEV_PITOT, Est_PMDG.ICE_annunR_ELEV_PITOT, "ICE_annunR_ELEV_PITOT");
		Controlar(pS->ICE_annunR_ALPHA_VANE, Est_PMDG.ICE_annunR_ALPHA_VANE, "ICE_annunR_ALPHA_VANE");
		Controlar(pS->ICE_annunAUX_PITOT, Est_PMDG.ICE_annunAUX_PITOT, "ICE_annunAUX_PITOT");
		Controlar(pS->ICE_ProbeHeatSw[0], Est_PMDG.ICE_ProbeHeatSw[0], "ICE_ProbeHeatSw[0]");
		Controlar(pS->ICE_ProbeHeatSw[1], Est_PMDG.ICE_ProbeHeatSw[1], "ICE_ProbeHeatSw[1]");
		Controlar(pS->ICE_annunVALVE_OPEN[0], Est_PMDG.ICE_annunVALVE_OPEN[0], "ICE_annunVALVE_OPEN[0]");
		Controlar(pS->ICE_annunVALVE_OPEN[1], Est_PMDG.ICE_annunVALVE_OPEN[1], "ICE_annunVALVE_OPEN[1]");
		Controlar(pS->ICE_annunCOWL_ANTI_ICE[0], Est_PMDG.ICE_annunCOWL_ANTI_ICE[0], "ICE_annunCOWL_ANTI_ICE[0]");
		Controlar(pS->ICE_annunCOWL_ANTI_ICE[1], Est_PMDG.ICE_annunCOWL_ANTI_ICE[1], "ICE_annunCOWL_ANTI_ICE[1]");
		Controlar(pS->ICE_annunCOWL_VALVE_OPEN[0], Est_PMDG.ICE_annunCOWL_VALVE_OPEN[0], "ICE_annunCOWL_VALVE_OPEN[0]");
		Controlar(pS->ICE_annunCOWL_VALVE_OPEN[1], Est_PMDG.ICE_annunCOWL_VALVE_OPEN[1], "ICE_annunCOWL_VALVE_OPEN[1]");
		Controlar(pS->ICE_WingAntiIceSw, Est_PMDG.ICE_WingAntiIceSw, "ICE_WingAntiIceSw");
		Controlar(pS->ICE_EngAntiIceSw[0], Est_PMDG.ICE_EngAntiIceSw[0], "ICE_EngAntiIceSw[0]");
		Controlar(pS->ICE_EngAntiIceSw[1], Est_PMDG.ICE_EngAntiIceSw[1], "ICE_EngAntiIceSw[1]");
		// Hydraulics
		Controlar(pS->HYD_annunLOW_PRESS_eng[0], Est_PMDG.HYD_annunLOW_PRESS_eng[0], "HYD_annunLOW_PRESS_eng[0]");
		Controlar(pS->HYD_annunLOW_PRESS_eng[1], Est_PMDG.HYD_annunLOW_PRESS_eng[1], "HYD_annunLOW_PRESS_eng[1]");
		Controlar(pS->HYD_annunLOW_PRESS_elec[0], Est_PMDG.HYD_annunLOW_PRESS_elec[0], "HYD_annunLOW_PRESS_elec[0]");
		Controlar(pS->HYD_annunLOW_PRESS_elec[1], Est_PMDG.HYD_annunLOW_PRESS_elec[1], "HYD_annunLOW_PRESS_elec[1]");
		Controlar(pS->HYD_annunOVERHEAT_elec[0], Est_PMDG.HYD_annunOVERHEAT_elec[0], "HYD_annunOVERHEAT_elec[0]");
		Controlar(pS->HYD_annunOVERHEAT_elec[1], Est_PMDG.HYD_annunOVERHEAT_elec[1], "HYD_annunOVERHEAT_elec[1]");
		Controlar(pS->HYD_PumpSw_eng[0], Est_PMDG.HYD_PumpSw_eng[0], "HYD_PumpSw_eng[0]");
		Controlar(pS->HYD_PumpSw_eng[1], Est_PMDG.HYD_PumpSw_eng[1], "HYD_PumpSw_eng[1]");
		Controlar(pS->HYD_PumpSw_elec[0], Est_PMDG.HYD_PumpSw_elec[0], "HYD_PumpSw_elec[0]");
		Controlar(pS->HYD_PumpSw_elec[1], Est_PMDG.HYD_PumpSw_elec[1], "HYD_PumpSw_elec[1]");
		// Air systems
		Controlar(pS->AIR_TempSourceSelector, Est_PMDG.AIR_TempSourceSelector, "AIR_TempSourceSelector");		// Positions 0..6
		Controlar(pS->AIR_TrimAirSwitch, Est_PMDG.AIR_TrimAirSwitch, "AIR_TrimAirSwitch");
		Controlar(pS->AIR_annunZoneTemp[0], Est_PMDG.AIR_annunZoneTemp[0], "AIR_annunZoneTemp[0]");
		Controlar(pS->AIR_annunZoneTemp[1], Est_PMDG.AIR_annunZoneTemp[1], "AIR_annunZoneTemp[1]");
		Controlar(pS->AIR_annunZoneTemp[2], Est_PMDG.AIR_annunZoneTemp[2], "AIR_annunZoneTemp[2]");
		Controlar(pS->AIR_annunDualBleed, Est_PMDG.AIR_annunDualBleed, "AIR_annunDualBleed");
		Controlar(pS->AIR_annunRamDoorL, Est_PMDG.AIR_annunRamDoorL, "AIR_annunRamDoorL");
		Controlar(pS->AIR_annunRamDoorR, Est_PMDG.AIR_annunRamDoorR, "AIR_annunRamDoorR");
		Controlar(pS->AIR_RecircFanSwitch[0], Est_PMDG.AIR_RecircFanSwitch[0], "AIR_RecircFanSwitch[0]");
		Controlar(pS->AIR_RecircFanSwitch[1], Est_PMDG.AIR_RecircFanSwitch[1], "AIR_RecircFanSwitch[1]");
		Controlar(pS->AIR_PackSwitch[0], Est_PMDG.AIR_PackSwitch[0], "AIR_PackSwitch[0]");						// 0=OFF  1=AUTO  2=HIGH
		Controlar(pS->AIR_PackSwitch[1], Est_PMDG.AIR_PackSwitch[1], "AIR_PackSwitch[1]");						// 0=OFF  1=AUTO  2=HIGH
		Controlar(pS->AIR_BleedAirSwitch[0], Est_PMDG.AIR_BleedAirSwitch[0], "AIR_BleedAirSwitch[0]");
		Controlar(pS->AIR_BleedAirSwitch[1], Est_PMDG.AIR_BleedAirSwitch[1], "AIR_BleedAirSwitch[1]");
		Controlar(pS->AIR_APUBleedAirSwitch, Est_PMDG.AIR_APUBleedAirSwitch, "AIR_APUBleedAirSwitch");
		Controlar(pS->AIR_IsolationValveSwitch, Est_PMDG.AIR_IsolationValveSwitch, "AIR_IsolationValveSwitch");	// 0=CLOSE  1=AUTO  2=OPEN
		Controlar(pS->AIR_annunPackTripOff[0], Est_PMDG.AIR_annunPackTripOff[0], "AIR_annunPackTripOff[0]");
		Controlar(pS->AIR_annunPackTripOff[1], Est_PMDG.AIR_annunPackTripOff[1], "AIR_annunPackTripOff[1]");
		Controlar(pS->AIR_annunWingBodyOverheat[0], Est_PMDG.AIR_annunWingBodyOverheat[0], "AIR_annunWingBodyOverheat[0]");
		Controlar(pS->AIR_annunWingBodyOverheat[1], Est_PMDG.AIR_annunWingBodyOverheat[1], "AIR_annunWingBodyOverheat[1]");
		Controlar(pS->AIR_annunBleedTripOff[0], Est_PMDG.AIR_annunBleedTripOff[0], "AIR_annunBleedTripOff[0]");
		Controlar(pS->AIR_annunBleedTripOff[1], Est_PMDG.AIR_annunBleedTripOff[1], "AIR_annunBleedTripOff[1]");

		Controlar(pS->AIR_FltAltWindow, Est_PMDG.AIR_FltAltWindow, "AIR_FltAltWindow");							// WARNING obsolete - use AIR_DisplayFltAlt instead
		Controlar(pS->AIR_LandAltWindow, Est_PMDG.AIR_LandAltWindow, "AIR_LandAltWindow");						// WARNING obsolete - use AIR_DisplayLandAlt instead
		Controlar(pS->AIR_OutflowValveSwitch, Est_PMDG.AIR_OutflowValveSwitch, "AIR_OutflowValveSwitch");		// 0=CLOSE  1=NEUTRAL  2=OPEN
		Controlar(pS->AIR_PressurizationModeSelector, Est_PMDG.AIR_PressurizationModeSelector, "AIR_PressurizationModeSelector");	// 0=AUTO  1=ALTN  2=MAN
		// Bottom overhead
		Controlar(pS->LTS_LandingLtRetractableSw[0], Est_PMDG.LTS_LandingLtRetractableSw[0], "LTS_LandingLtRetractableSw[0]");		// 0: RETRACT  1: EXTEND  2: ON
		Controlar(pS->LTS_LandingLtRetractableSw[1], Est_PMDG.LTS_LandingLtRetractableSw[1], "LTS_LandingLtRetractableSw[1]");		// 0: RETRACT  1: EXTEND  2: ON
		Controlar(pS->LTS_LandingLtFixedSw[0], Est_PMDG.LTS_LandingLtFixedSw[0], "LTS_LandingLtFixedSw[0]");
		Controlar(pS->LTS_LandingLtFixedSw[1], Est_PMDG.LTS_LandingLtFixedSw[1], "LTS_LandingLtFixedSw[1]");
		Controlar(pS->LTS_RunwayTurnoffSw[0], Est_PMDG.LTS_RunwayTurnoffSw[0], "LTS_RunwayTurnoffSw[0]");
		Controlar(pS->LTS_RunwayTurnoffSw[1], Est_PMDG.LTS_RunwayTurnoffSw[1], "LTS_RunwayTurnoffSw[1]");
		Controlar(pS->LTS_TaxiSw, Est_PMDG.LTS_TaxiSw, "LTS_TaxiSw");
		Controlar(pS->APU_Selector, Est_PMDG.APU_Selector, "APU_Selector");										// 0: OFF  1: ON  2: START
		Controlar(pS->ENG_StartSelector[0], Est_PMDG.ENG_StartSelector[0], "ENG_StartSelector[0]");				// 0: GRD  1: OFF  2: CONT  3: FLT
		Controlar(pS->ENG_StartSelector[1], Est_PMDG.ENG_StartSelector[1], "ENG_StartSelector[1]");				// 0: GRD  1: OFF  2: CONT  3: FLT
		Controlar(pS->ENG_IgnitionSelector, Est_PMDG.ENG_IgnitionSelector, "ENG_IgnitionSelector");				// 0: IGN L  1: BOTH  2: IGN R
		Controlar(pS->LTS_LogoSw, Est_PMDG.LTS_LogoSw, "LTS_LogoSw");
		Controlar(pS->LTS_PositionSw, Est_PMDG.LTS_PositionSw, "LTS_PositionSw");								// 0: STEADY  1: OFF  2: STROBE&STEADY
		Controlar(pS->LTS_AntiCollisionSw, Est_PMDG.LTS_AntiCollisionSw, "LTS_AntiCollisionSw");
		Controlar(pS->LTS_WingSw, Est_PMDG.LTS_WingSw, "LTS_WingSw");
		Controlar(pS->LTS_WheelWellSw, Est_PMDG.LTS_WheelWellSw, "LTS_WheelWellSw");
	};
	// Glareshield
	//------------------------------------------
	if (GLARESHIEL) {
		// Warnings
		Controlar(pS->WARN_annunFIRE_WARN[0], Est_PMDG.WARN_annunFIRE_WARN[0], "WARN_annunFIRE_WARN[0]");
		Controlar(pS->WARN_annunFIRE_WARN[1], Est_PMDG.WARN_annunFIRE_WARN[1], "WARN_annunFIRE_WARN[1]");
		Controlar(pS->WARN_annunMASTER_CAUTION[0], Est_PMDG.WARN_annunMASTER_CAUTION[0], "WARN_annunMASTER_CAUTION[0]");
		Controlar(pS->WARN_annunMASTER_CAUTION[1], Est_PMDG.WARN_annunMASTER_CAUTION[1], "WARN_annunMASTER_CAUTION[1]");
		Controlar(pS->WARN_annunFLT_CONT, Est_PMDG.WARN_annunFLT_CONT, "WARN_annunFLT_CONT");
		Controlar(pS->WARN_annunIRS, Est_PMDG.WARN_annunIRS, "WARN_annunIRS");
		Controlar(pS->WARN_annunFUEL, Est_PMDG.WARN_annunFUEL, "WARN_annunFUEL");
		Controlar(pS->WARN_annunELEC, Est_PMDG.WARN_annunELEC, "WARN_annunELEC");
		Controlar(pS->WARN_annunAPU, Est_PMDG.WARN_annunAPU, "WARN_annunAPU");
		Controlar(pS->WARN_annunOVHT_DET, Est_PMDG.WARN_annunOVHT_DET, "WARN_annunOVHT_DET");
		Controlar(pS->WARN_annunANTI_ICE, Est_PMDG.WARN_annunANTI_ICE, "WARN_annunANTI_ICE");
		Controlar(pS->WARN_annunHYD, Est_PMDG.WARN_annunHYD, "WARN_annunHYD");
		Controlar(pS->WARN_annunDOORS, Est_PMDG.WARN_annunDOORS, "WARN_annunDOORS");
		Controlar(pS->WARN_annunENG, Est_PMDG.WARN_annunENG, "WARN_annunENG");
		Controlar(pS->WARN_annunOVERHEAD, Est_PMDG.WARN_annunOVERHEAD, "WARN_annunOVERHEAD");
		Controlar(pS->WARN_annunAIR_COND, Est_PMDG.WARN_annunAIR_COND, "WARN_annunAIR_COND");
		// EFIS control panels
		Controlar(pS->EFIS_MinsSelBARO[0], Est_PMDG.EFIS_MinsSelBARO[0], "EFIS_MinsSelBARO[0]");
		Controlar(pS->EFIS_MinsSelBARO[1], Est_PMDG.EFIS_MinsSelBARO[1], "EFIS_MinsSelBARO[1]");
		Controlar(pS->EFIS_BaroSelHPA[0], Est_PMDG.EFIS_BaroSelHPA[0], "EFIS_BaroSelHPA[0]");
		Controlar(pS->EFIS_BaroSelHPA[1], Est_PMDG.EFIS_BaroSelHPA[1], "EFIS_BaroSelHPA[1]");
		Controlar(pS->EFIS_VORADFSel1[0], Est_PMDG.EFIS_VORADFSel1[0], "EFIS_VORADFSel1[0]");	// 0: VOR  1: OFF  2: AD, F
		Controlar(pS->EFIS_VORADFSel1[1], Est_PMDG.EFIS_VORADFSel1[1], "EFIS_VORADFSel1[1]");	// 0: VOR  1: OFF  2: AD, F
		Controlar(pS->EFIS_VORADFSel2[0], Est_PMDG.EFIS_VORADFSel2[0], "EFIS_VORADFSel2[0]");	// 0: VOR  1: OFF  2: AD, F
		Controlar(pS->EFIS_VORADFSel2[1], Est_PMDG.EFIS_VORADFSel2[1], "EFIS_VORADFSel2[1]");	// 0: VOR  1: OFF  2: AD, F
		Controlar(pS->EFIS_ModeSel[0], Est_PMDG.EFIS_ModeSel[0], "EFIS_ModeSel[0]");			// 0: APP  1: VOR  2: MAP  3: PLA, n
		Controlar(pS->EFIS_ModeSel[1], Est_PMDG.EFIS_ModeSel[1], "EFIS_ModeSel[1]");			// 0: APP  1: VOR  2: MAP  3: PLA, 
		Controlar(pS->EFIS_RangeSel[0], Est_PMDG.EFIS_RangeSel[0], "EFIS_RangeSel[0]");			// 0: 5 ... 7: 64, 0
		Controlar(pS->EFIS_RangeSel[1], Est_PMDG.EFIS_RangeSel[1], "EFIS_RangeSel[1]");			// 0: 5 ... 7: 64, 0
		// Mode control panel
		Controlar(pS->MCP_Course[0], Est_PMDG.MCP_Course[0], "MCP_Course[0]");
		Controlar(pS->MCP_Course[1], Est_PMDG.MCP_Course[1], "MCP_Course[1]");
		Controlar(pS->MCP_IASMach, Est_PMDG.MCP_IASMach, "MCP_IASMach");						// Mach if < 10., 0
		Controlar(pS->MCP_IASBlank, Est_PMDG.MCP_IASBlank, "MCP_IASBlank");
		Controlar(pS->MCP_IASOverspeedFlash, Est_PMDG.MCP_IASOverspeedFlash, "MCP_IASOverspeedFlash");
		Controlar(pS->MCP_IASUnderspeedFlash, Est_PMDG.MCP_IASUnderspeedFlash, "MCP_IASUnderspeedFlash");
		Controlar(pS->MCP_Heading, Est_PMDG.MCP_Heading, "MCP_Heading");
		Controlar(pS->MCP_Altitude, Est_PMDG.MCP_Altitude, "MCP_Altitude");
		Controlar(pS->MCP_VertSpeed, Est_PMDG.MCP_VertSpeed, "MCP_VertSpeed");
		Controlar(pS->MCP_VertSpeedBlank, Est_PMDG.MCP_VertSpeedBlank, "MCP_VertSpeedBlank");

		Controlar(pS->MCP_FDSw[0], Est_PMDG.MCP_FDSw[0], "MCP_FDSw[0]");
		Controlar(pS->MCP_FDSw[1], Est_PMDG.MCP_FDSw[1], "MCP_FDSw[1]");
		Controlar(pS->MCP_ATArmSw, Est_PMDG.MCP_ATArmSw, "MCP_ATArmSw");
		Controlar(pS->MCP_BankLimitSel, Est_PMDG.MCP_BankLimitSel, "MCP_BankLimitSel");	// 0: 10 ... 4: 3, 0
		Controlar(pS->MCP_DisengageBar, Est_PMDG.MCP_DisengageBar, "MCP_DisengageBar");

		Controlar(pS->MCP_annunFD[0], Est_PMDG.MCP_annunFD[0], "MCP_annunFD[0]");
		Controlar(pS->MCP_annunFD[1], Est_PMDG.MCP_annunFD[1], "MCP_annunFD[1]");
		Controlar(pS->MCP_annunATArm, Est_PMDG.MCP_annunATArm, "MCP_annunATArm");
		Controlar(pS->MCP_annunN1, Est_PMDG.MCP_annunN1, "MCP_annunN1");
		Controlar(pS->MCP_annunSPEED, Est_PMDG.MCP_annunSPEED, "MCP_annunSPEED");
		Controlar(pS->MCP_annunVNAV, Est_PMDG.MCP_annunVNAV, "MCP_annunVNAV");
		Controlar(pS->MCP_annunLVL_CHG, Est_PMDG.MCP_annunLVL_CHG, "MCP_annunLVL_CHG");
		Controlar(pS->MCP_annunHDG_SEL, Est_PMDG.MCP_annunHDG_SEL, "MCP_annunHDG_SEL");
		Controlar(pS->MCP_annunLNAV, Est_PMDG.MCP_annunLNAV, "MCP_annunLNAV");
		Controlar(pS->MCP_annunVOR_LOC, Est_PMDG.MCP_annunVOR_LOC, "MCP_annunVOR_LOC");
		Controlar(pS->MCP_annunAPP, Est_PMDG.MCP_annunAPP, "MCP_annunAPP");
		Controlar(pS->MCP_annunALT_HOLD, Est_PMDG.MCP_annunALT_HOLD, "MCP_annunALT_HOLD");
		Controlar(pS->MCP_annunVS, Est_PMDG.MCP_annunVS, "MCP_annunVS");
		Controlar(pS->MCP_annunCMD_A, Est_PMDG.MCP_annunCMD_A, "MCP_annunCMD_A");
		Controlar(pS->MCP_annunCWS_A, Est_PMDG.MCP_annunCWS_A, "MCP_annunCWS_A");
		Controlar(pS->MCP_annunCMD_B, Est_PMDG.MCP_annunCMD_B, "MCP_annunCMD_B");
		Controlar(pS->MCP_annunCWS_B, Est_PMDG.MCP_annunCWS_B, "MCP_annunCWS_B");
	};
	// Forward panel
	//------------------------------------------
	if (FORWARD_PANEL) {
		Controlar(pS->MAIN_NoseWheelSteeringSwNORM, Est_PMDG.MAIN_NoseWheelSteeringSwNORM, "MAIN_NoseWheelSteeringSwNORM");		// false: AL, T
		Controlar(pS->MAIN_annunBELOW_GS[0], Est_PMDG.MAIN_annunBELOW_GS[0], "MAIN_annunBELOW_GS[0]");
		Controlar(pS->MAIN_annunBELOW_GS[1], Est_PMDG.MAIN_annunBELOW_GS[1], "MAIN_annunBELOW_GS[1]");
		Controlar(pS->MAIN_MainPanelDUSel[0], Est_PMDG.MAIN_MainPanelDUSel[0], "MAIN_MainPanelDUSel[0]");	// 0: OUTBD PFD ... 4 MFD for Capt, reverse sequence for F, O
		Controlar(pS->MAIN_MainPanelDUSel[1], Est_PMDG.MAIN_MainPanelDUSel[1], "MAIN_MainPanelDUSel[1]");	// 0: OUTBD PFD ... 4 MFD for Capt, reverse sequence for F, O
		Controlar(pS->MAIN_LowerDUSel[0], Est_PMDG.MAIN_LowerDUSel[0], "MAIN_LowerDUSel[0]");				// 0: ENG PRI ... 2 ND for Capt, reverse sequence for F, O
		Controlar(pS->MAIN_LowerDUSel[1], Est_PMDG.MAIN_LowerDUSel[1], "MAIN_LowerDUSel[1]");				// 0: ENG PRI ... 2 ND for Capt, reverse sequence for F, O
		Controlar(pS->MAIN_annunAP[0], Est_PMDG.MAIN_annunAP[0], "MAIN_annunAP[0]");						// Red color. See MAIN_annunAP_Amber for amber color (added to the bottom of the struct, )
		Controlar(pS->MAIN_annunAP[1], Est_PMDG.MAIN_annunAP[1], "MAIN_annunAP[1]");						// Red color. See MAIN_annunAP_Amber for amber color (added to the
		Controlar(pS->MAIN_annunAT[0], Est_PMDG.MAIN_annunAT[0], "MAIN_annunAT[0]");						// Red color. See MAIN_annunAT_Amber for amber color (added to the bottom of the struct, )
		Controlar(pS->MAIN_annunAT[1], Est_PMDG.MAIN_annunAT[1], "MAIN_annunAT[1]");						// Red color. See MAIN_annunAT_Amber for amber color (added to the bottom 
		Controlar(pS->MAIN_annunFMC[0], Est_PMDG.MAIN_annunFMC[0], "MAIN_annunFMC[0]");
		Controlar(pS->MAIN_annunFMC[1], Est_PMDG.MAIN_annunFMC[1], "MAIN_annunFMC[1]");
		Controlar(pS->MAIN_DisengageTestSelector[0], Est_PMDG.MAIN_DisengageTestSelector[0], "MAIN_DisengageTestSelector[0]");			// 0: 1  1: OFF  2: , 2
		Controlar(pS->MAIN_DisengageTestSelector[1], Est_PMDG.MAIN_DisengageTestSelector[1], "MAIN_DisengageTestSelector[1]");			// 0: 1  1: OFF  2: , 2
		Controlar(pS->MAIN_annunSPEEDBRAKE_ARMED, Est_PMDG.MAIN_annunSPEEDBRAKE_ARMED, "MAIN_annunSPEEDBRAKE_ARMED");
		Controlar(pS->MAIN_annunSPEEDBRAKE_DO_NOT_ARM, Est_PMDG.MAIN_annunSPEEDBRAKE_DO_NOT_ARM, "MAIN_annunSPEEDBRAKE_DO_NOT_ARM");
		Controlar(pS->MAIN_annunSPEEDBRAKE_EXTENDED, Est_PMDG.MAIN_annunSPEEDBRAKE_EXTENDED, "MAIN_annunSPEEDBRAKE_EXTENDED");
		Controlar(pS->MAIN_annunSTAB_OUT_OF_TRIM, Est_PMDG.MAIN_annunSTAB_OUT_OF_TRIM, "MAIN_annunSTAB_OUT_OF_TRIM");
		Controlar(pS->MAIN_LightsSelector, Est_PMDG.MAIN_LightsSelector, "MAIN_LightsSelector");				// 0: TEST  1: BRT  2: DI, M
		Controlar(pS->MAIN_RMISelector1_VOR, Est_PMDG.MAIN_RMISelector1_VOR, "MAIN_RMISelector1_VOR");
		Controlar(pS->MAIN_RMISelector2_VOR, Est_PMDG.MAIN_RMISelector2_VOR, "MAIN_RMISelector2_VOR");
		Controlar(pS->MAIN_N1SetSelector, Est_PMDG.MAIN_N1SetSelector, "MAIN_N1SetSelector");					// 0: 2  1: 1  2: AUTO  3: BOT, H
		Controlar(pS->MAIN_SpdRefSelector, Est_PMDG.MAIN_SpdRefSelector, "MAIN_SpdRefSelector");				// 0: SET  1: AUTO  2: V1  3: VR  4: WT  5: VREF  6: Bug ,  
		Controlar(pS->MAIN_FuelFlowSelector, Est_PMDG.MAIN_FuelFlowSelector, "MAIN_FuelFlowSelector");			// 0: RESET  1: RATE  2: USE, D
		Controlar(pS->MAIN_AutobrakeSelector, Est_PMDG.MAIN_AutobrakeSelector, "MAIN_AutobrakeSelector");		// 0: RTO  1: OFF ... 5: MA, X
		Controlar(pS->MAIN_annunANTI_SKID_INOP, Est_PMDG.MAIN_annunANTI_SKID_INOP, "MAIN_annunANTI_SKID_INOP");
		Controlar(pS->MAIN_annunAUTO_BRAKE_DISARM, Est_PMDG.MAIN_annunAUTO_BRAKE_DISARM, "MAIN_annunAUTO_BRAKE_DISARM");
		Controlar(pS->MAIN_annunLE_FLAPS_TRANSIT, Est_PMDG.MAIN_annunLE_FLAPS_TRANSIT, "MAIN_annunLE_FLAPS_TRANSIT");
		Controlar(pS->MAIN_annunLE_FLAPS_EXT, Est_PMDG.MAIN_annunLE_FLAPS_EXT, "MAIN_annunLE_FLAPS_EXT");
		Controlar(pS->MAIN_TEFlapsNeedle[0], Est_PMDG.MAIN_TEFlapsNeedle[0], "MAIN_TEFlapsNeedle[0]");			// Valu, e
		Controlar(pS->MAIN_TEFlapsNeedle[1], Est_PMDG.MAIN_TEFlapsNeedle[1], "MAIN_TEFlapsNeedle[1]");			// Valu, e
		Controlar(pS->MAIN_annunGEAR_transit[0], Est_PMDG.MAIN_annunGEAR_transit[0], "MAIN_annunGEAR_transit[0]");
		Controlar(pS->MAIN_annunGEAR_transit[1], Est_PMDG.MAIN_annunGEAR_transit[1], "MAIN_annunGEAR_transit[1]");
		Controlar(pS->MAIN_annunGEAR_transit[2], Est_PMDG.MAIN_annunGEAR_transit[2], "MAIN_annunGEAR_transit[2]");
		Controlar(pS->MAIN_annunGEAR_locked[0], Est_PMDG.MAIN_annunGEAR_locked[0], "MAIN_annunGEAR_locked[0]");
		Controlar(pS->MAIN_annunGEAR_locked[1], Est_PMDG.MAIN_annunGEAR_locked[1], "MAIN_annunGEAR_locked[1]");
		Controlar(pS->MAIN_annunGEAR_locked[2], Est_PMDG.MAIN_annunGEAR_locked[2], "MAIN_annunGEAR_locked[2]");
		Controlar(pS->MAIN_GearLever, Est_PMDG.MAIN_GearLever, "MAIN_GearLever");								// 0: UP  1: OFF  2: DOW, N
		Controlar(pS->MAIN_BrakePressNeedle, Est_PMDG.MAIN_BrakePressNeedle, "MAIN_BrakePressNeedle");			// Valu, e

		Controlar(pS->HGS_annun_AIII, Est_PMDG.HGS_annun_AIII, "HGS_annun_AIII");
		Controlar(pS->HGS_annun_NO_AIII, Est_PMDG.HGS_annun_NO_AIII, "HGS_annun_NO_AIII");
		Controlar(pS->HGS_annun_FLARE, Est_PMDG.HGS_annun_FLARE, "HGS_annun_FLARE");
		Controlar(pS->HGS_annun_RO, Est_PMDG.HGS_annun_RO, "HGS_annun_RO");
		Controlar(pS->HGS_annun_RO_CTN, Est_PMDG.HGS_annun_RO_CTN, "HGS_annun_RO_CTN");
		Controlar(pS->HGS_annun_RO_ARM, Est_PMDG.HGS_annun_RO_ARM, "HGS_annun_RO_ARM");
		Controlar(pS->HGS_annun_TO, Est_PMDG.HGS_annun_TO, "HGS_annun_TO");
		Controlar(pS->HGS_annun_TO_CTN, Est_PMDG.HGS_annun_TO_CTN, "HGS_annun_TO_CTN");
		Controlar(pS->HGS_annun_APCH, Est_PMDG.HGS_annun_APCH, "HGS_annun_APCH");
		Controlar(pS->HGS_annun_TO_WARN, Est_PMDG.HGS_annun_TO_WARN, "HGS_annun_TO_WARN");
		Controlar(pS->HGS_annun_Bar, Est_PMDG.HGS_annun_Bar, "HGS_annun_Bar");
		Controlar(pS->HGS_annun_FAIL, Est_PMDG.HGS_annun_FAIL, "HGS_annun_FAIL");
	};
	// Lower forward panel
	//------------------------------------------
	if (LOWER_FORWARD_PANEL) {
		Controlar(pS->LTS_MainPanelKnob[0], Est_PMDG.LTS_MainPanelKnob[0], "LTS_MainPanelKnob[0]");				// Position 0...150
		Controlar(pS->LTS_MainPanelKnob[1], Est_PMDG.LTS_MainPanelKnob[1], "LTS_MainPanelKnob[1]");				// Position 0...150
		Controlar(pS->LTS_BackgroundKnob, Est_PMDG.LTS_BackgroundKnob, "LTS_BackgroundKnob");					// Position 0...150
		Controlar(pS->LTS_AFDSFloodKnob, Est_PMDG.LTS_AFDSFloodKnob, "LTS_AFDSFloodKnob");						// Position 0...150
		Controlar(pS->LTS_OutbdDUBrtKnob[0], Est_PMDG.LTS_OutbdDUBrtKnob[0], "LTS_OutbdDUBrtKnob[0]");			// Position 0...127
		Controlar(pS->LTS_OutbdDUBrtKnob[1], Est_PMDG.LTS_OutbdDUBrtKnob[1], "LTS_OutbdDUBrtKnob[1]");			// Position 0...127
		Controlar(pS->LTS_InbdDUBrtKnob[0], Est_PMDG.LTS_InbdDUBrtKnob[0], "LTS_InbdDUBrtKnob[0]");				// Position 0...127
		Controlar(pS->LTS_InbdDUBrtKnob[1], Est_PMDG.LTS_InbdDUBrtKnob[1], "LTS_InbdDUBrtKnob[1]");				// Position 0...127
		Controlar(pS->LTS_InbdDUMapBrtKnob[0], Est_PMDG.LTS_InbdDUMapBrtKnob[0], "LTS_InbdDUMapBrtKnob[0]");	// Position 0...127
		Controlar(pS->LTS_InbdDUMapBrtKnob[1], Est_PMDG.LTS_InbdDUMapBrtKnob[1], "LTS_InbdDUMapBrtKnob[1]");	// Position 0...127
		Controlar(pS->LTS_UpperDUBrtKnob, Est_PMDG.LTS_UpperDUBrtKnob, "LTS_UpperDUBrtKnob");					// Position 0...127
		Controlar(pS->LTS_LowerDUBrtKnob, Est_PMDG.LTS_LowerDUBrtKnob, "LTS_LowerDUBrtKnob");					// Position 0...127
		Controlar(pS->LTS_LowerDUMapBrtKnob, Est_PMDG.LTS_LowerDUMapBrtKnob, "LTS_LowerDUMapBrtKnob");			// Position 0...127

		Controlar(pS->GPWS_annunINOP, Est_PMDG.GPWS_annunINOP, "GPWS_annunINOP");
		Controlar(pS->GPWS_FlapInhibitSw_NORM, Est_PMDG.GPWS_FlapInhibitSw_NORM, "GPWS_FlapInhibitSw_NORM");
		Controlar(pS->GPWS_GearInhibitSw_NORM, Est_PMDG.GPWS_GearInhibitSw_NORM, "GPWS_GearInhibitSw_NORM");
		Controlar(pS->GPWS_TerrInhibitSw_NORM, Est_PMDG.GPWS_TerrInhibitSw_NORM, "GPWS_TerrInhibitSw_NORM");
	};
	// Control Stand
	//------------------------------------------
	if (CONTROL_STAND) {
		Controlar(pS->CDU_annunEXEC[0], Est_PMDG.CDU_annunEXEC[0], "CDU_annunEXEC[0]");
		Controlar(pS->CDU_annunEXEC[1], Est_PMDG.CDU_annunEXEC[1], "CDU_annunEXEC[1]");
		Controlar(pS->CDU_annunCALL[0], Est_PMDG.CDU_annunCALL[0], "CDU_annunCALL[0]");
		Controlar(pS->CDU_annunCALL[1], Est_PMDG.CDU_annunCALL[1], "CDU_annunCALL[1]");
		Controlar(pS->CDU_annunFAIL[0], Est_PMDG.CDU_annunFAIL[0], "CDU_annunFAIL[0]");
		Controlar(pS->CDU_annunFAIL[1], Est_PMDG.CDU_annunFAIL[1], "CDU_annunFAIL[1]");
		Controlar(pS->CDU_annunMSG[0], Est_PMDG.CDU_annunMSG[0], "CDU_annunMSG[0]");
		Controlar(pS->CDU_annunMSG[1], Est_PMDG.CDU_annunMSG[1], "CDU_annunMSG[1]");
		Controlar(pS->CDU_annunOFST[0], Est_PMDG.CDU_annunOFST[0], "CDU_annunOFST[0]");
		Controlar(pS->CDU_annunOFST[1], Est_PMDG.CDU_annunOFST[1], "CDU_annunOFST[1]");
		Controlar(pS->CDU_BrtKnob[0], Est_PMDG.CDU_BrtKnob[0], "CDU_BrtKnob[0]");						// Position 0...127
		Controlar(pS->CDU_BrtKnob[1], Est_PMDG.CDU_BrtKnob[1], "CDU_BrtKnob[1]");						// Position 0...127

		Controlar(pS->TRIM_StabTrimMainElecSw_NORMAL, Est_PMDG.TRIM_StabTrimMainElecSw_NORMAL, "TRIM_StabTrimMainElecSw_NORMAL");
		Controlar(pS->TRIM_StabTrimAutoPilotSw_NORMAL, Est_PMDG.TRIM_StabTrimAutoPilotSw_NORMAL, "TRIM_StabTrimAutoPilotSw_NORMAL");
		Controlar(pS->PED_annunParkingBrake, Est_PMDG.PED_annunParkingBrake, "PED_annunParkingBrake");

		Controlar(pS->FIRE_OvhtDetSw[0], Est_PMDG.FIRE_OvhtDetSw[0], "FIRE_OvhtDetSw[0]");				// 0: A  1: NORMAL  2: B
		Controlar(pS->FIRE_OvhtDetSw[1], Est_PMDG.FIRE_OvhtDetSw[1], "FIRE_OvhtDetSw[1]");				// 0: A  1: NORMAL  2: B
		Controlar(pS->FIRE_annunENG_OVERHEAT[0], Est_PMDG.FIRE_annunENG_OVERHEAT[0], "FIRE_annunENG_OVERHEAT[0]");
		Controlar(pS->FIRE_annunENG_OVERHEAT[1], Est_PMDG.FIRE_annunENG_OVERHEAT[1], "FIRE_annunENG_OVERHEAT[1]");
		Controlar(pS->FIRE_DetTestSw, Est_PMDG.FIRE_DetTestSw, "FIRE_DetTestSw");						// 0: FAULT/INOP  1: neutral  2: OVHT/FIRE
		Controlar(pS->FIRE_HandlePos[0], Est_PMDG.FIRE_HandlePos[0], "FIRE_HandlePos[0]");				// 0: In  1: Blocked  2: Out  3: Turned Left  4: Turned right
		Controlar(pS->FIRE_HandlePos[1], Est_PMDG.FIRE_HandlePos[1], "FIRE_HandlePos[1]");				// 0: In  1: Blocked  2: Out  3: Turned Left  4: Turned right
		Controlar(pS->FIRE_HandlePos[2], Est_PMDG.FIRE_HandlePos[2], "FIRE_HandlePos[2]");				// 0: In  1: Blocked  2: Out  3: Turned Left  4: Turned right
		Controlar(pS->FIRE_HandleIlluminated[0], Est_PMDG.FIRE_HandleIlluminated[0], "FIRE_HandleIlluminated[0]");
		Controlar(pS->FIRE_HandleIlluminated[1], Est_PMDG.FIRE_HandleIlluminated[1], "FIRE_HandleIlluminated[1]");
		Controlar(pS->FIRE_HandleIlluminated[2], Est_PMDG.FIRE_HandleIlluminated[2], "FIRE_HandleIlluminated[2]");
		Controlar(pS->FIRE_annunWHEEL_WELL, Est_PMDG.FIRE_annunWHEEL_WELL, "FIRE_annunWHEEL_WELL");
		Controlar(pS->FIRE_annunFAULT, Est_PMDG.FIRE_annunFAULT, "FIRE_annunFAULT");
		Controlar(pS->FIRE_annunAPU_DET_INOP, Est_PMDG.FIRE_annunAPU_DET_INOP, "FIRE_annunAPU_DET_INOP");
		Controlar(pS->FIRE_annunAPU_BOTTLE_DISCHARGE, Est_PMDG.FIRE_annunAPU_BOTTLE_DISCHARGE, "FIRE_annunAPU_BOTTLE_DISCHARGE");
		Controlar(pS->FIRE_annunBOTTLE_DISCHARGE[0], Est_PMDG.FIRE_annunBOTTLE_DISCHARGE[0], "FIRE_annunBOTTLE_DISCHARGE[0]");
		Controlar(pS->FIRE_annunBOTTLE_DISCHARGE[1], Est_PMDG.FIRE_annunBOTTLE_DISCHARGE[1], "FIRE_annunBOTTLE_DISCHARGE[1]");
		Controlar(pS->FIRE_ExtinguisherTestSw, Est_PMDG.FIRE_ExtinguisherTestSw, "FIRE_ExtinguisherTestSw");		// 0: 1  1: neutral  2: 2
		Controlar(pS->FIRE_annunExtinguisherTest[0], Est_PMDG.FIRE_annunExtinguisherTest[0], "FIRE_annunExtinguisherTest[0]");		// Left, Right, APU
		Controlar(pS->FIRE_annunExtinguisherTest[1], Est_PMDG.FIRE_annunExtinguisherTest[1], "FIRE_annunExtinguisherTest[1]");		// Left, Right, APU
		Controlar(pS->FIRE_annunExtinguisherTest[2], Est_PMDG.FIRE_annunExtinguisherTest[2], "FIRE_annunExtinguisherTest[2]");		// Left, Right, APU

		Controlar(pS->CARGO_annunExtTest[0], Est_PMDG.CARGO_annunExtTest[0], "CARGO_annunExtTest[0]");	// Fwd, Aft
		Controlar(pS->CARGO_annunExtTest[1], Est_PMDG.CARGO_annunExtTest[1], "CARGO_annunExtTest[1]");	// Fwd, Aft
		Controlar(pS->CARGO_DetSelect[0], Est_PMDG.CARGO_DetSelect[0], "CARGO_DetSelect[0]");			// 0: A  1: ORM  2: B
		Controlar(pS->CARGO_DetSelect[1], Est_PMDG.CARGO_DetSelect[1], "CARGO_DetSelect[1]");			// 0: A  1: ORM  2:
		Controlar(pS->CARGO_ArmedSw[0], Est_PMDG.CARGO_ArmedSw[0], "CARGO_ArmedSw[0]");
		Controlar(pS->CARGO_ArmedSw[1], Est_PMDG.CARGO_ArmedSw[1], "CARGO_ArmedSw[1]");
		Controlar(pS->CARGO_annunFWD, Est_PMDG.CARGO_annunFWD, "CARGO_annunFWD");
		Controlar(pS->CARGO_annunAFT, Est_PMDG.CARGO_annunAFT, "CARGO_annunAFT");
		Controlar(pS->CARGO_annunDETECTOR_FAULT, Est_PMDG.CARGO_annunDETECTOR_FAULT, "CARGO_annunDETECTOR_FAULT");
		Controlar(pS->CARGO_annunDISCH, Est_PMDG.CARGO_annunDISCH, "CARGO_annunDISCH");

		Controlar(pS->CARGO_annunDISCH, Est_PMDG.HGS_annunRWY, "HGS_annunRWY");
		Controlar(pS->HGS_annunGS, Est_PMDG.HGS_annunGS, "HGS_annunGS");
		Controlar(pS->HGS_annunFAULT, Est_PMDG.HGS_annunFAULT, "HGS_annunFAULT");
		Controlar(pS->HGS_annunCLR, Est_PMDG.HGS_annunCLR, "HGS_annunCLR");

		Controlar(pS->XPDR_XpndrSelector_2, Est_PMDG.XPDR_XpndrSelector_2, "XPDR_XpndrSelector_2");		// false: 1  true: 2
		Controlar(pS->XPDR_AltSourceSel_2, Est_PMDG.XPDR_AltSourceSel_2, "XPDR_AltSourceSel_2");		// false: 1  true: 2
		Controlar(pS->XPDR_ModeSel, Est_PMDG.XPDR_ModeSel, "XPDR_ModeSel");								// 0: STBY  1: ALT RPTG OFF ... 4: TA/RA
		Controlar(pS->XPDR_annunFAIL, Est_PMDG.XPDR_annunFAIL, "XPDR_annunFAIL");

		Controlar(pS->LTS_PedFloodKnob, Est_PMDG.LTS_PedFloodKnob, "LTS_PedFloodKnob");					// Position 0...150
		Controlar(pS->LTS_PedPanelKnob, Est_PMDG.LTS_PedPanelKnob, "LTS_PedPanelKnob");					// Position 0...150

		Controlar(pS->TRIM_StabTrimSw_NORMAL, Est_PMDG.TRIM_StabTrimSw_NORMAL, "TRIM_StabTrimSw_NORMAL");
		Controlar(pS->PED_annunLOCK_FAIL, Est_PMDG.PED_annunLOCK_FAIL, "PED_annunLOCK_FAIL");
		Controlar(pS->PED_annunAUTO_UNLK, Est_PMDG.PED_annunAUTO_UNLK, "PED_annunAUTO_UNLK");
		Controlar(pS->PED_FltDkDoorSel, Est_PMDG.PED_FltDkDoorSel, "PED_FltDkDoorSel");					// 0: UNLKD  1 AUTO pushed in  2: AUTO  3: DENY
		// Additional variables: used by FS2Crew
		Controlar(pS->ENG_StartValve[0], Est_PMDG.ENG_StartValve[0], "ENG_StartValve[0]");				// true: valve open
		Controlar(pS->ENG_StartValve[1], Est_PMDG.ENG_StartValve[1], "ENG_StartValve[1]");				// true: valve open
		Controlar(pS->AIR_DuctPress[0], Est_PMDG.AIR_DuctPress[0], "AIR_DuctPress[0]");					// PSI
		Controlar(pS->AIR_DuctPress[1], Est_PMDG.AIR_DuctPress[1], "AIR_DuctPress[1]");					// PSI
		Controlar(pS->COMM_Attend_PressCount, Est_PMDG.COMM_Attend_PressCount, "COMM_Attend_PressCount");		// incremented with each button press
		Controlar(pS->COMM_GrdCall_PressCount, Est_PMDG.COMM_GrdCall_PressCount, "COMM_GrdCall_PressCount");	// incremented with each button press
		Controlar(pS->COMM_SelectedMic[0], Est_PMDG.COMM_SelectedMic[0], "COMM_SelectedMic[0]");				// array: 0=capt, 1=F/O, 2=observer.
		Controlar(pS->COMM_SelectedMic[1], Est_PMDG.COMM_SelectedMic[1], "COMM_SelectedMic[1]");				// array: 0=capt, 1=F/O, 2=observer.
		Controlar(pS->COMM_SelectedMic[2], Est_PMDG.COMM_SelectedMic[2], "COMM_SelectedMic[2]");				// array: 0=capt, 1=F/O, 2=observer.
																												// values: 0=VHF1  1=VHF2  2=VHF3  3=HF1  4=HF2  5=FLT  6=SVC  7=PA
		Controlar(pS->FUEL_QtyCenter, Est_PMDG.FUEL_QtyCenter, "FUEL_QtyCenter");		// LBS
		Controlar(pS->FUEL_QtyLeft, Est_PMDG.FUEL_QtyLeft, "FUEL_QtyLeft");				// LBS
		Controlar(pS->FUEL_QtyRight, Est_PMDG.FUEL_QtyRight, "FUEL_QtyRight");			// LBS
		Controlar(pS->IRS_aligned, Est_PMDG.IRS_aligned, "IRS_aligned");				// at least one IRU is aligned
		Controlar(pS->AircraftModel, Est_PMDG.AircraftModel, "AircraftModel");			// 1: -600  2: -700  3: -700WL  4: -800  5: -800WL  6: -900  7: -900ER
		Controlar(pS->WeightInKg, Est_PMDG.WeightInKg, "WeightInKg");					// false: LBS  true: KG
		Controlar(pS->GPWS_V1CallEnabled, Est_PMDG.GPWS_V1CallEnabled, "GPWS_V1CallEnabled");		// GPWS V1 callout option enabled
		Controlar(pS->GroundConnAvailable, Est_PMDG.GroundConnAvailable, "GroundConnAvailable");	// can connect/disconnect ground air/electrics

		Controlar(pS->FMC_TakeoffFlaps, Est_PMDG.FMC_TakeoffFlaps, "FMC_TakeoffFlaps");	// degrees, 0 if not set
		Controlar(pS->FMC_V1, Est_PMDG.FMC_V1, "FMC_V1");								// knots, 0 if not set
		Controlar(pS->FMC_VR, Est_PMDG.FMC_VR, "FMC_VR");								// knots, 0 if not set
		Controlar(pS->FMC_V2, Est_PMDG.FMC_V2, "FMC_V2");								// knots, 0 if not set
		Controlar(pS->FMC_LandingFlaps, Est_PMDG.FMC_LandingFlaps, "FMC_LandingFlaps");	// degrees, 0 if not set
		Controlar(pS->FMC_LandingVREF, Est_PMDG.FMC_LandingVREF, "FMC_LandingVREF");	// knots, 0 if not set
		Controlar(pS->FMC_CruiseAlt, Est_PMDG.FMC_CruiseAlt, "FMC_CruiseAlt");			// ft, 0 if not set
		Controlar(pS->FMC_LandingAltitude, Est_PMDG.FMC_LandingAltitude, "FMC_LandingAltitude");		// ft, -32767 if not available
		Controlar(pS->FMC_TransitionAlt, Est_PMDG.FMC_TransitionAlt, "FMC_TransitionAlt");				// ft
		Controlar(pS->FMC_TransitionLevel, Est_PMDG.FMC_TransitionLevel, "FMC_TransitionLevel");		// ft
		Controlar(pS->FMC_PerfInputComplete, Est_PMDG.FMC_PerfInputComplete, "FMC_PerfInputComplete");
		Controlar(pS->FMC_DistanceToTOD, Est_PMDG.FMC_DistanceToTOD, "FMC_DistanceToTOD");				// nm, 0.0 if passed, negative if n/a
		Controlar(pS->FMC_DistanceToDest, Est_PMDG.FMC_DistanceToDest, "FMC_DistanceToDest");			// nm, negative if n/a
		Controlar(pS->FMC_flightNumber[0], Est_PMDG.FMC_flightNumber[0], "FMC_flightNumber[0]");
		Controlar(pS->FMC_flightNumber[2], Est_PMDG.FMC_flightNumber[1], "FMC_flightNumber[1]");
		Controlar(pS->FMC_flightNumber[2], Est_PMDG.FMC_flightNumber[2], "FMC_flightNumber[2]");
		Controlar(pS->FMC_flightNumber[3], Est_PMDG.FMC_flightNumber[3], "FMC_flightNumber[3]");
		Controlar(pS->FMC_flightNumber[4], Est_PMDG.FMC_flightNumber[4], "FMC_flightNumber[4]");
		Controlar(pS->FMC_flightNumber[5], Est_PMDG.FMC_flightNumber[5], "FMC_flightNumber[5]");
		Controlar(pS->FMC_flightNumber[6], Est_PMDG.FMC_flightNumber[6], "FMC_flightNumber[6]");
		Controlar(pS->FMC_flightNumber[7], Est_PMDG.FMC_flightNumber[7], "FMC_flightNumber[7]");
		Controlar(pS->FMC_flightNumber[8], Est_PMDG.FMC_flightNumber[8], "FMC_flightNumber[8]");
		// New variables for SP2
		Controlar(pS->COMM_ReceiverSwitches[0], Est_PMDG.COMM_ReceiverSwitches[0], "COMM_ReceiverSwitches[0]");	// Bit flags for selector receivers (see ACP_SEL_RECV_VHF1 etc): [0]=Capt, [1]=FO, [2]=Overhead
		Controlar(pS->COMM_ReceiverSwitches[1], Est_PMDG.COMM_ReceiverSwitches[1], "COMM_ReceiverSwitches[1]");	// Bit flags for selector receivers (see ACP_SEL_RECV_VHF1 etc): [0]=Capt, [1]=FO, [2]=Overhead
		Controlar(pS->COMM_ReceiverSwitches[2], Est_PMDG.COMM_ReceiverSwitches[2], "COMM_ReceiverSwitches[2]");	// Bit flags for selector receivers (see ACP_SEL_RECV_VHF1 etc): [0]=Capt, [1]=FO, [2]=Overhead
		Controlar(pS->MAIN_annunAP_Amber[0], Est_PMDG.MAIN_annunAP_Amber[0], "MAIN_annunAP_Amber[0]");			// Amber color
		Controlar(pS->MAIN_annunAP_Amber[1], Est_PMDG.MAIN_annunAP_Amber[1], "MAIN_annunAP_Amber[1]");			// Amber color
		Controlar(pS->MAIN_annunAT_Amber[0], Est_PMDG.MAIN_annunAT_Amber[0], "MAIN_annunAT_Amber[0]");			// Amber color
		Controlar(pS->MAIN_annunAT_Amber[1], Est_PMDG.MAIN_annunAT_Amber[1], "MAIN_annunAT_Amber[1]");			// Amber color
		Controlar(pS->ICE_WindowHeatTestSw, Est_PMDG.ICE_WindowHeatTestSw, "ICE_WindowHeatTestSw");				// 0: OVHT  1: Neutral  2: PWR TEST
		Controlar(pS->DOOR_annunFWD_ENTRY, Est_PMDG.DOOR_annunFWD_ENTRY, "DOOR_annunFWD_ENTRY");
		Controlar(pS->DOOR_annunFWD_SERVICE, Est_PMDG.DOOR_annunFWD_SERVICE, "DOOR_annunFWD_SERVICE");
		Controlar(pS->DOOR_annunAIRSTAIR, Est_PMDG.DOOR_annunAIRSTAIR, "DOOR_annunAIRSTAIR");
		Controlar(pS->DOOR_annunLEFT_FWD_OVERWING, Est_PMDG.DOOR_annunLEFT_FWD_OVERWING, "DOOR_annunLEFT_FWD_OVERWING");
		Controlar(pS->DOOR_annunRIGHT_FWD_OVERWING, Est_PMDG.DOOR_annunRIGHT_FWD_OVERWING, "DOOR_annunRIGHT_FWD_OVERWING");
		Controlar(pS->DOOR_annunFWD_CARGO, Est_PMDG.DOOR_annunFWD_CARGO, "DOOR_annunFWD_CARGO");
		Controlar(pS->DOOR_annunEQUIP, Est_PMDG.DOOR_annunEQUIP, "DOOR_annunEQUIP");
		Controlar(pS->DOOR_annunLEFT_AFT_OVERWING, Est_PMDG.DOOR_annunLEFT_AFT_OVERWING, "DOOR_annunLEFT_AFT_OVERWING");
		Controlar(pS->DOOR_annunRIGHT_AFT_OVERWING, Est_PMDG.DOOR_annunRIGHT_AFT_OVERWING, "DOOR_annunRIGHT_AFT_OVERWING");
		Controlar(pS->DOOR_annunAFT_CARGO, Est_PMDG.DOOR_annunAFT_CARGO, "DOOR_annunAFT_CARGO");
		Controlar(pS->DOOR_annunAFT_ENTRY, Est_PMDG.DOOR_annunAFT_ENTRY, "DOOR_annunAFT_ENTRY");
		Controlar(pS->DOOR_annunAFT_SERVICE, Est_PMDG.DOOR_annunAFT_SERVICE, "DOOR_annunAFT_SERVICE");
		Controlar(pS->AIR_annunAUTO_FAIL, Est_PMDG.AIR_annunAUTO_FAIL, "AIR_annunAUTO_FAIL");
		Controlar(pS->AIR_annunOFFSCHED_DESCENT, Est_PMDG.AIR_annunOFFSCHED_DESCENT, "AIR_annunOFFSCHED_DESCENT");
		Controlar(pS->AIR_annunALTN, Est_PMDG.AIR_annunALTN, "AIR_annunALTN");
		Controlar(pS->AIR_annunMANUAL, Est_PMDG.AIR_annunMANUAL, "AIR_annunMANUAL");
		Controlar(pS->AIR_CabinAltNeedle, Est_PMDG.AIR_CabinAltNeedle, "AIR_CabinAltNeedle");					// Value - ft
		Controlar(pS->AIR_CabinDPNeedle, Est_PMDG.AIR_CabinDPNeedle, "AIR_CabinDPNeedle");						// Value - PSI
		Controlar(pS->AIR_CabinVSNeedle, Est_PMDG.AIR_CabinVSNeedle, "AIR_CabinVSNeedle");						// Value - ft/min
		Controlar(pS->AIR_CabinValveNeedle, Est_PMDG.AIR_CabinValveNeedle, "AIR_CabinValveNeedle");				// Value - 0 (closed) .. 1 (open)
		Controlar(pS->AIR_TemperatureNeedle, Est_PMDG.AIR_TemperatureNeedle, "AIR_TemperatureNeedle");			// Value - degrees C
		Controlar(pS->AIR_DuctPressNeedle[0], Est_PMDG.AIR_DuctPressNeedle[0], "AIR_DuctPressNeedle[0]");		// Value - degrees C
		Controlar(pS->AIR_DuctPressNeedle[1], Est_PMDG.AIR_DuctPressNeedle[1], "AIR_DuctPressNeedle[1]");		// Value - degrees C
		Controlar(pS->ELEC_MeterDisplayTop[0], Est_PMDG.ELEC_MeterDisplayTop[0], "ELEC_MeterDisplayTop[0]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[1], Est_PMDG.ELEC_MeterDisplayTop[1], "ELEC_MeterDisplayTop[1]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[2], Est_PMDG.ELEC_MeterDisplayTop[2], "ELEC_MeterDisplayTop[2]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[3], Est_PMDG.ELEC_MeterDisplayTop[3], "ELEC_MeterDisplayTop[3]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[4], Est_PMDG.ELEC_MeterDisplayTop[4], "ELEC_MeterDisplayTop[4]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[5], Est_PMDG.ELEC_MeterDisplayTop[5], "ELEC_MeterDisplayTop[5]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[6], Est_PMDG.ELEC_MeterDisplayTop[6], "ELEC_MeterDisplayTop[6]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[7], Est_PMDG.ELEC_MeterDisplayTop[7], "ELEC_MeterDisplayTop[7]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[8], Est_PMDG.ELEC_MeterDisplayTop[8], "ELEC_MeterDisplayTop[8]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[9], Est_PMDG.ELEC_MeterDisplayTop[9], "ELEC_MeterDisplayTop[9]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[10], Est_PMDG.ELEC_MeterDisplayTop[10], "ELEC_MeterDisplayTop[10]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[11], Est_PMDG.ELEC_MeterDisplayTop[12], "ELEC_MeterDisplayTop[11]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 
		Controlar(pS->ELEC_MeterDisplayTop[12], Est_PMDG.ELEC_MeterDisplayTop[12], "ELEC_MeterDisplayTop[12]");	// Top line of the display: 3 groups of 4 digits (or symbols) + terminating zero 

		Controlar(pS->ELEC_MeterDisplayBottom[0], Est_PMDG.ELEC_MeterDisplayBottom[0], "ELEC_MeterDisplayBottom[0]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[1], Est_PMDG.ELEC_MeterDisplayBottom[1], "ELEC_MeterDisplayBottom[1]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[2], Est_PMDG.ELEC_MeterDisplayBottom[2], "ELEC_MeterDisplayBottom[2]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[3], Est_PMDG.ELEC_MeterDisplayBottom[3], "ELEC_MeterDisplayBottom[3]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[4], Est_PMDG.ELEC_MeterDisplayBottom[4], "ELEC_MeterDisplayBottom[4]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[5], Est_PMDG.ELEC_MeterDisplayBottom[5], "ELEC_MeterDisplayBottom[5]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[6], Est_PMDG.ELEC_MeterDisplayBottom[6], "ELEC_MeterDisplayBottom[6]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[7], Est_PMDG.ELEC_MeterDisplayBottom[7], "ELEC_MeterDisplayBottom[7]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[8], Est_PMDG.ELEC_MeterDisplayBottom[8], "ELEC_MeterDisplayBottom[8]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[9], Est_PMDG.ELEC_MeterDisplayBottom[9], "ELEC_MeterDisplayBottom[9]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[10], Est_PMDG.ELEC_MeterDisplayBottom[10], "ELEC_MeterDisplayBottom[10]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[11], Est_PMDG.ELEC_MeterDisplayBottom[11], "ELEC_MeterDisplayBottom[11]");	// Bottom line of the display
		Controlar(pS->ELEC_MeterDisplayBottom[12], Est_PMDG.ELEC_MeterDisplayBottom[12], "ELEC_MeterDisplayBottom[12]");	// Bottom line of the display

		Controlar(pS->IRS_DisplayLeft[0], Est_PMDG.IRS_DisplayLeft[0], "IRS_DisplayLeft[0]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[1], Est_PMDG.IRS_DisplayLeft[1], "IRS_DisplayLeft[1]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[2], Est_PMDG.IRS_DisplayLeft[2], "IRS_DisplayLeft[2]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[3], Est_PMDG.IRS_DisplayLeft[3], "IRS_DisplayLeft[3]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[4], Est_PMDG.IRS_DisplayLeft[4], "IRS_DisplayLeft[4]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[5], Est_PMDG.IRS_DisplayLeft[5], "IRS_DisplayLeft[5]");					// Left display string, zero terminated
		Controlar(pS->IRS_DisplayLeft[6], Est_PMDG.IRS_DisplayLeft[6], "IRS_DisplayLeft[6]");					// Left display string, zero terminated

		Controlar(pS->IRS_DisplayRight[0], Est_PMDG.IRS_DisplayRight[0], "IRS_DisplayRight[0]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[1], Est_PMDG.IRS_DisplayRight[1], "IRS_DisplayRight[1]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[2], Est_PMDG.IRS_DisplayRight[2], "IRS_DisplayRight[2]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[3], Est_PMDG.IRS_DisplayRight[3], "IRS_DisplayRight[3]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[4], Est_PMDG.IRS_DisplayRight[4], "IRS_DisplayRight[4]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[5], Est_PMDG.IRS_DisplayRight[5], "IRS_DisplayRight[5]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[6], Est_PMDG.IRS_DisplayRight[6], "IRS_DisplayRight[6]");				// Right display string, zero terminated 
		Controlar(pS->IRS_DisplayRight[7], Est_PMDG.IRS_DisplayRight[7], "IRS_DisplayRight[7]");				// Right display string, zero terminated 

		Controlar(pS->IRS_DisplayShowsDots, Est_PMDG.IRS_DisplayShowsDots, "IRS_DisplayShowsDots");				// True if the degrees and decimal dot symbols are shown on the IRS display
		// Yet more new variables 
		Controlar(pS->ADF_StandbyFrequency, Est_PMDG.ADF_StandbyFrequency, "ADF_StandbyFrequency");				// Standby frequency multiplied by 10
		Controlar(pS->AFS_AutothrottleServosConnected, Est_PMDG.AFS_AutothrottleServosConnected, "AFS_AutothrottleServosConnected");	// True if the autothrottle system is driving the thrust levers
		Controlar(pS->AFS_ControlsPitch, Est_PMDG.AFS_ControlsPitch, "AFS_ControlsPitch");						// The autoflight system is actively controlling pitch
		Controlar(pS->AFS_ControlsRoll, Est_PMDG.AFS_ControlsRoll, "AFS_ControlsRoll");

		Controlar(pS->ELEC_BusPowered[0], Est_PMDG.ELEC_BusPowered[0], "ELEC_BusPowered[0]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[1], Est_PMDG.ELEC_BusPowered[1], "ELEC_BusPowered[1]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[2], Est_PMDG.ELEC_BusPowered[2], "ELEC_BusPowered[2]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[3], Est_PMDG.ELEC_BusPowered[3], "ELEC_BusPowered[3]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[4], Est_PMDG.ELEC_BusPowered[4], "ELEC_BusPowered[4]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[5], Est_PMDG.ELEC_BusPowered[5], "ELEC_BusPowered[5]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[6], Est_PMDG.ELEC_BusPowered[6], "ELEC_BusPowered[6]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[7], Est_PMDG.ELEC_BusPowered[7], "ELEC_BusPowered[7]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[8], Est_PMDG.ELEC_BusPowered[8], "ELEC_BusPowered[8]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[9], Est_PMDG.ELEC_BusPowered[9], "ELEC_BusPowered[9]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[10], Est_PMDG.ELEC_BusPowered[10], "ELEC_BusPowered[10]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[11], Est_PMDG.ELEC_BusPowered[11], "ELEC_BusPowered[11]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[12], Est_PMDG.ELEC_BusPowered[12], "ELEC_BusPowered[12]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[13], Est_PMDG.ELEC_BusPowered[13], "ELEC_BusPowered[13]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[14], Est_PMDG.ELEC_BusPowered[14], "ELEC_BusPowered[14]");				// True if the corresponding bus is powered:
		Controlar(pS->ELEC_BusPowered[15], Est_PMDG.ELEC_BusPowered[15], "ELEC_BusPowered[15]");				// True if the corresponding bus is powered:
													// DC HOT BATT			0	
													// DC HOT BATT SWITCHED	1	
													// DC BATT BUS			2	
													// DC STANDBY BUS		3	
													// DC BUS 1				4	
													// DC BUS 2				5	
													// DC GROUND SVC		6
													// AC TRANSFER 1		7
													// AC TRANSFER 2		8
													// AC GROUND SVC 1		9
													// AC GROUND SVC 2		10
													// AC MAIN 1			11
													// AC MAIN 2			12
													// AC GALLEY 1			13
													// AC GALLEY 2			14
													// AC STANDBY			15
		Controlar(pS->MCP_indication_powered, Est_PMDG.MCP_indication_powered, "MCP_indication_powered");		// true when the MCP is powered and the MCP windows are indicating

		Controlar(pS->AIR_DisplayFltAlt[0], Est_PMDG.AIR_DisplayFltAlt[0], "AIR_DisplayFltAlt[0]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayFltAlt[1], Est_PMDG.AIR_DisplayFltAlt[1], "AIR_DisplayFltAlt[1]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayFltAlt[2], Est_PMDG.AIR_DisplayFltAlt[2], "AIR_DisplayFltAlt[2]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayFltAlt[3], Est_PMDG.AIR_DisplayFltAlt[3], "AIR_DisplayFltAlt[3]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayFltAlt[4], Est_PMDG.AIR_DisplayFltAlt[4], "AIR_DisplayFltAlt[4]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayFltAlt[5], Est_PMDG.AIR_DisplayFltAlt[5], "AIR_DisplayFltAlt[5]");				// Pressurization system FLT ALT window, zero terminated, can be blank or show dashes or show test pattern

		Controlar(pS->AIR_DisplayLandAlt[0], Est_PMDG.AIR_DisplayLandAlt[0], "AIR_DisplayLandAlt[0]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayLandAlt[1], Est_PMDG.AIR_DisplayLandAlt[1], "AIR_DisplayLandAlt[1]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayLandAlt[2], Est_PMDG.AIR_DisplayLandAlt[2], "AIR_DisplayLandAlt[2]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayLandAlt[3], Est_PMDG.AIR_DisplayLandAlt[3], "AIR_DisplayLandAlt[3]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayLandAlt[4], Est_PMDG.AIR_DisplayLandAlt[4], "AIR_DisplayLandAlt[4]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		Controlar(pS->AIR_DisplayLandAlt[5], Est_PMDG.AIR_DisplayLandAlt[5], "AIR_DisplayLandAlt[5]");			// Pressurization system LAND ALT window, zero terminated, can be blank or show dashes or show test pattern
		// New variables for 737NGXu
		Controlar(pS->MAIN_annunCABIN_ALTITUDE, Est_PMDG.MAIN_annunCABIN_ALTITUDE, "MAIN_annunCABIN_ALTITUDE");
		Controlar(pS->MAIN_annunTAKEOFF_CONFIG, Est_PMDG.MAIN_annunTAKEOFF_CONFIG, "MAIN_annunTAKEOFF_CONFIG");
		Controlar(pS->CVR_annunTEST, Est_PMDG.CVR_annunTEST, "CVR_annunTEST");									// CVR TEST indicator
		// The rest of the controls and indicators match their standard FSX counterparts
		// and can be accessed using the standard SimConnect means.

		// Controlar(pS->reserved[123], Est_PMDG.reserved[123], "reserved[123]");
	}

}


