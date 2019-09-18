
// Generated from icl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  iclParser : public antlr4::Parser {
public:
  enum {
    ACCESSLINK = 1, ACCESSTOGETHER = 2, ACTIVEPOLARITY = 3, ACTIVESIGNALS = 4, 
    ADDRESSPORT = 5, ADDRESSVALUE = 6, ALIAS = 7, ALLOWBROADCASTONSCANINTERFACE = 8, 
    UNSIZED_BIN_NUM = 9, UNSIZED_DEC_NUM = 10, UNSIZED_HEX_NUM = 11, AND = 12, 
    ATTRIBUTE = 13, BSDLENTITIY = 14, CAPTUREENPORT = 15, CAPTURESOURCE = 16, 
    CHAIN = 17, CLOCKMUX = 18, CLOCKPORT = 19, COLON = 20, COMMA = 21, DATAINPORT = 22, 
    DATAMUX = 23, DATAOUTPORT = 24, DATAREGISTER = 25, DEFAULTLOADVALUE = 26, 
    DIFFERENTIALINVOF = 27, DOLLAR = 28, DOT = 29, DOUBLE_COLON = 30, D_SUBST = 31, 
    ENABLE = 32, ENUM = 33, EQUAL = 34, FALLING = 35, FREQDIVIDER = 36, 
    FREQMULTIPLIER = 37, IAPPLYENDSTATE = 38, INPUTPORT = 39, INSTANCE = 40, 
    LAUNCHEDGE = 41, LEFT_BRACE = 42, LEFT_BRACKET = 43, LEFT_PAREN = 44, 
    LOCALPARAMETER = 45, LOGICSIGNAL = 46, LOGIC_AND = 47, LOGIC_EQUAL = 48, 
    LOGIC_OR = 49, MINUS = 50, MODULE = 51, MSEC = 52, NAMESPACE = 53, NOT_EQUAL = 54, 
    NSEC = 55, OF = 56, ZERO = 57, ONE = 58, ONEHOTDATAGROUP = 59, ONEHOTSCANGROUP = 60, 
    PARAMETER = 61, PERCENT = 62, PERIOD = 63, PIPE = 64, PLUS = 65, PORT = 66, 
    POS_INT = 67, PSEC = 68, READCALLBACK = 69, READDATASOURCE = 70, READENPORT = 71, 
    REFENUM = 72, RESETPORT = 73, RESETVALUE = 74, RIGHT_BRACE = 75, RIGHT_BRACKET = 76, 
    RIGHT_PAREN = 77, RISING = 78, R_SUBST = 79, SCANINPORT = 80, SCANINSOURCE = 81, 
    SCANINTERFACE = 82, SCANMUX = 83, SCANOUTPORT = 84, SCANREGISTER = 85, 
    SEC = 86, SELECTEDBY = 87, SELECTPORT = 88, SEMICOLON = 89, SHIFTENPORT = 90, 
    SLASH = 91, SOURCE = 92, STAR = 93, STD_1149_1_2001 = 94, STD_1149_1_2013 = 95, 
    STRING = 96, TCKPORT = 97, TILDE = 98, LOGIC_NOT = 99, TMSPORT = 100, 
    TOCAPTUREENPORT = 101, TOCLOCKPORT = 102, TOIRSELECTPORT = 103, TORESETPORT = 104, 
    TOSELECTPORT = 105, TOSHIFTENPORT = 106, TOTCKPORT = 107, TOTMSPORT = 108, 
    TOTRSTPORT = 109, TOUPDATEENPORT = 110, TRSTPORT = 111, UPDATEENPORT = 112, 
    USEC = 113, USENAMESPACE = 114, WRITECALLBACK = 115, WRITEDATASOURCE = 116, 
    WRITEENPORT = 117, WRITEENSOURCE = 118, SCALAR_ID = 119, XOR = 120, 
    SPACE = 121, ML_COMMENT = 122, SL_COMMENT = 123
  };

  enum {
    RulePos_int = 0, RuleVector_id = 1, RuleIndex_or_range = 2, RuleIndex = 3, 
    RuleRange = 4, RuleNumber = 5, RuleInteger_expr = 6, RuleInteger_expr_lvl1 = 7, 
    RuleInteger_expr_lvl1_b = 8, RulePlus_or_minus = 9, RuleInteger_expr_lvl2 = 10, 
    RuleInteger_expr_lvl2_b = 11, RuleStar_or_slash_or_percent = 12, RuleInteger_expr_paren = 13, 
    RuleInteger_expr_arg = 14, RuleParameter_ref = 15, RuleConcat_number = 16, 
    RuleConcat_number_list = 17, RulePin_id = 18, RulePort_name = 19, RuleRegister_name = 20, 
    RuleInstance_name = 21, RuleNamespace_name = 22, RuleModule_name = 23, 
    RuleReg_port_signal_id = 24, RuleSignal = 25, RuleX_signal = 26, RuleData_signal = 27, 
    RuleScan_signal = 28, RuleCaptureEn_signal = 29, RuleUpdateEn_signal = 30, 
    RuleConcat_reset_signal = 31, RuleConcat_data_signal = 32, RuleConcat_scan_signal = 33, 
    RuleConcat_clock_signal = 34, RuleConcat_shiftEn_signal = 35, RuleConcat_tms_signal = 36, 
    RuleConcat_trst_signal = 37, RuleIcl_source = 38, RuleIclSource_items = 39, 
    RuleNameSpace_def = 40, RuleUseNameSpace_def = 41, RuleModule_def = 42, 
    RuleModule_items = 43, RuleModule_item = 44, RulePort_def = 45, RuleScanInPort_def = 46, 
    RuleScanInPort_tail = 47, RuleScanInPort_items = 48, RuleScanInPort_name = 49, 
    RuleScanOutPort_def = 50, RuleScanOutPort_tail = 51, RuleScanOutPort_items = 52, 
    RuleScanOutPort_name = 53, RuleScanOutPort_item = 54, RuleScanOutPort_source = 55, 
    RuleScanOutPort_enable = 56, RuleScanOutPort_launchEdge = 57, RuleRising_or_falling = 58, 
    RuleShiftEnPort_def = 59, RuleShiftEnPort_tail = 60, RuleShiftEnPort_items = 61, 
    RuleShiftEnPort_name = 62, RuleCaptureEnPort_def = 63, RuleCaptureEnPort_tail = 64, 
    RuleCaptureEnPort_items = 65, RuleCaptureEnPort_name = 66, RuleUpdateEnPort_def = 67, 
    RuleUpdateEnPort_tail = 68, RuleUpdateEnPort_items = 69, RuleUpdateEnPort_name = 70, 
    RuleDataInPort_def = 71, RuleDataInPort_tail = 72, RuleDataInPort_items = 73, 
    RuleDataInPort_name = 74, RuleDataInPort_item = 75, RuleDataInPort_refEnum = 76, 
    RuleDataOutPort_def = 77, RuleDataOutPort_tail = 78, RuleDataOutPort_items = 79, 
    RuleDataOutPort_name = 80, RuleDataOutPort_item = 81, RuleDataOutPort_source = 82, 
    RuleDataOutPort_enable = 83, RuleDataOutPort_refEnum = 84, RuleToShiftEnPort_def = 85, 
    RuleToShiftEnPort_tail = 86, RuleToShiftEnPort_items = 87, RuleToShiftEnPort_name = 88, 
    RuleToShiftEnPort_item = 89, RuleToShiftEnPort_source = 90, RuleToCaptureEnPort_def = 91, 
    RuleToCaptureEnPort_tail = 92, RuleToCaptureEnPort_items = 93, RuleToCaptureEnPort_name = 94, 
    RuleToCaptureEnPort_item = 95, RuleToCaptureEnPort_source = 96, RuleToUpdateEnPort_def = 97, 
    RuleToUpdateEnPort_tail = 98, RuleToUpdateEnPort_items = 99, RuleToUpdateEnPort_name = 100, 
    RuleToUpdateEnPort_item = 101, RuleToUpdateEnPort_source = 102, RuleSelectPort_def = 103, 
    RuleSelectPort_tail = 104, RuleSelectPort_items = 105, RuleSelectPort_name = 106, 
    RuleToSelectPort_def = 107, RuleToSelectPort_name = 108, RuleToSelectPort_tail = 109, 
    RuleToSelectPort_items = 110, RuleToSelectPort_item = 111, RuleToSelectPort_source = 112, 
    RuleResetPort_def = 113, RuleResetPort_name = 114, RuleResetPort_tail = 115, 
    RuleResetPort_items = 116, RuleResetPort_item = 117, RuleResetPort_polarity = 118, 
    RuleZero_or_one = 119, RuleToResetPort_def = 120, RuleToResetPort_name = 121, 
    RuleToResetPort_tail = 122, RuleToResetPort_items = 123, RuleToResetPort_item = 124, 
    RuleToResetPort_source = 125, RuleToResetPort_polarity = 126, RuleTmsPort_def = 127, 
    RuleTmsPort_tail = 128, RuleTmsPort_items = 129, RuleTmsPort_name = 130, 
    RuleToTmsPort_def = 131, RuleToTmsPort_name = 132, RuleToTmsPort_tail = 133, 
    RuleToTmsPort_items = 134, RuleToTmsPort_item = 135, RuleToTmsPort_source = 136, 
    RuleToIRSelectPort_def = 137, RuleToIRSelectPort_tail = 138, RuleToIRSelectPort_items = 139, 
    RuleToIRSelectPort_name = 140, RuleTckPort_def = 141, RuleTckPort_tail = 142, 
    RuleTckPort_items = 143, RuleTckPort_name = 144, RuleToTckPort_def = 145, 
    RuleToTckPort_tail = 146, RuleToTckPort_items = 147, RuleToTckPort_name = 148, 
    RuleClockPort_def = 149, RuleClockPort_name = 150, RuleClockPort_tail = 151, 
    RuleClockPort_items = 152, RuleClockPort_item = 153, RuleClockPort_diffPort = 154, 
    RuleToClockPort_def = 155, RuleToClockPort_name = 156, RuleToClockPort_tail = 157, 
    RuleToClockPort_items = 158, RuleToClockPort_item = 159, RuleToClockPort_source = 160, 
    RuleFreqMultiplier_def = 161, RuleFreqDivider_def = 162, RuleDifferentialInvOf_def = 163, 
    RulePeriod_def = 164, RuleTunit = 165, RuleTrstPort_def = 166, RuleTrstPort_tail = 167, 
    RuleTrstPort_items = 168, RuleTrstPort_name = 169, RuleToTrstPort_def = 170, 
    RuleToTrstPort_name = 171, RuleToTrstPort_tail = 172, RuleToTrstPort_items = 173, 
    RuleToTrstPort_item = 174, RuleToTrstPort_source = 175, RuleAddressPort_def = 176, 
    RuleAddressPort_tail = 177, RuleAddressPort_items = 178, RuleAddressPort_name = 179, 
    RuleWriteEnPort_def = 180, RuleWriteEnPort_tail = 181, RuleWriteEnPort_items = 182, 
    RuleWriteEnPort_name = 183, RuleReadEnPort_def = 184, RuleReadEnPort_tail = 185, 
    RuleReadEnPort_items = 186, RuleReadEnPort_name = 187, RuleInstance_def = 188, 
    RuleInstance_module = 189, RuleInstance_tail = 190, RuleInstance_items = 191, 
    RuleInstance_item = 192, RuleInputPort_connection = 193, RuleAllowBroadcast_def = 194, 
    RuleAllowBroadcast_items = 195, RuleInputPort_name = 196, RuleInputPort_source = 197, 
    RuleParameter_override = 198, RuleInstance_addressValue = 199, RuleScanRegister_def = 200, 
    RuleScanRegister_name = 201, RuleScanRegister_tail = 202, RuleScanRegister_items = 203, 
    RuleScanRegister_item = 204, RuleScanRegister_scanInSource = 205, RuleScanRegister_defaultLoadValue = 206, 
    RuleScanRegister_captureSource = 207, RuleScanRegister_resetValue = 208, 
    RuleScanRegister_refEnum = 209, RuleNumber_or_enum = 210, RuleSignal_or_enum = 211, 
    RuleDataRegister_def = 212, RuleDataRegister_name = 213, RuleDataRegister_tail = 214, 
    RuleDataRegister_items = 215, RuleDataRegister_item = 216, RuleDataRegister_type = 217, 
    RuleDataRegister_common = 218, RuleDataRegister_resetValue = 219, RuleDataRegister_defaultLoadValue = 220, 
    RuleDataRegister_refEnum = 221, RuleDataRegister_selectable = 222, RuleDataRegister_writeEnSource = 223, 
    RuleDataRegister_writeDataSource = 224, RuleDataRegister_addressable = 225, 
    RuleDataRegister_addressValue = 226, RuleDataRegister_readCallBack = 227, 
    RuleDataRegister_readCallBack_proc = 228, RuleIProc_arglist = 229, RuleDataRegister_readDataSource = 230, 
    RuleDataRegister_writeCallBack = 231, RuleIProc_namespace = 232, RuleIProc_name = 233, 
    RuleIProc_args = 234, RuleSub_namespace = 235, RuleRef_module_name = 236, 
    RuleLogicSignal_def = 237, RuleLogicSignal_name = 238, RuleLogic_expr = 239, 
    RuleLogic_expr_lvl1 = 240, RuleLogic_and_or_or = 241, RuleLogic_expr_lvl2 = 242, 
    RuleAnd_or_xor = 243, RuleLogic_expr_lvl3 = 244, RuleEq_or_neq = 245, 
    RuleLogic_expr_lvl4 = 246, RuleLogic_unary_expr = 247, RuleLogic_expr_arg = 248, 
    RuleNeg_or_not = 249, RuleLogic_expr_paren = 250, RuleLogic_expr_num_arg = 251, 
    RuleScanMux_def = 252, RuleScanMux_selections = 253, RuleScanMux_name = 254, 
    RuleScanMux_select = 255, RuleScanMux_selection = 256, RuleDataMux_def = 257, 
    RuleDataMux_selections = 258, RuleDataMux_name = 259, RuleDataMux_select = 260, 
    RuleDataMux_selection = 261, RuleClockMux_def = 262, RuleClockMux_selections = 263, 
    RuleClockMux_name = 264, RuleClockMux_select = 265, RuleClockMux_selection = 266, 
    RuleOneHotScanGroup_def = 267, RuleOneHotScanGroup_items = 268, RuleOneHotScanGroup_name = 269, 
    RuleOneHotScanGroup_item = 270, RuleOneHotDataGroup_def = 271, RuleOneHotDataGroup_items = 272, 
    RuleOneHotDataGroup_name = 273, RuleOneHotDataGroup_item = 274, RuleOneHotDataGroup_portSource = 275, 
    RuleAccessLink_def = 276, RuleAccessLinkGeneric_def = 277, RuleAccessLink_genericID = 278, 
    RuleAccessLink1149_def = 279, RuleAccessLink1149_stds = 280, RuleAccessLink_name = 281, 
    RuleBsdlEntity_name = 282, RuleBsdl_instr_refs = 283, RuleBsdl_instr_ref = 284, 
    RuleBsdl_instr_selected_items = 285, RuleBsdl_instr_name = 286, RuleBsdl_instr_selected_item = 287, 
    RuleAccessLink1149_ScanInterface_names = 288, RuleAccessLink1149_ActiveSignal_name = 289, 
    RuleAccessLink1149_ActiveSignal_names = 290, RuleAccessLink1149_ScanInterface_name = 291, 
    RuleScanInterface_def = 292, RuleScanInterface_items = 293, RuleScanInterface_name = 294, 
    RuleScanInterface_item = 295, RuleScanInterfacePort_def = 296, RuleScanInterfaceChain_def = 297, 
    RuleScanInterfaceChain_items = 298, RuleScanInterfaceChain_name = 299, 
    RuleScanInterfaceChain_item = 300, RuleDefaultLoad_def = 301, RuleAlias_def = 302, 
    RuleAlias_name = 303, RuleAlias_tail = 304, RuleAlias_items = 305, RuleAlias_item = 306, 
    RuleAlias_iApplyEndState = 307, RuleAlias_refEnum = 308, RuleConcat_hier_data_signal = 309, 
    RuleX_hier_data_signal = 310, RuleHier_data_signal = 311, RuleHier_data_signal_instances = 312, 
    RuleEnum_def = 313, RuleEnum_items = 314, RuleEnum_name = 315, RuleEnum_item = 316, 
    RuleEnum_symbol = 317, RuleEnum_value = 318, RuleParameter_def = 319, 
    RuleLocalParameter_def = 320, RuleParameter_name = 321, RuleParameter_value = 322, 
    RuleConcat_string = 323, RuleString_or_parm = 324, RuleAttribute_def = 325, 
    RuleAttribute_name = 326, RuleAttribute_value = 327
  };

  iclParser(antlr4::TokenStream *input);
  ~iclParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Pos_intContext;
  class Vector_idContext;
  class Index_or_rangeContext;
  class IndexContext;
  class RangeContext;
  class NumberContext;
  class Integer_exprContext;
  class Integer_expr_lvl1Context;
  class Integer_expr_lvl1_bContext;
  class Plus_or_minusContext;
  class Integer_expr_lvl2Context;
  class Integer_expr_lvl2_bContext;
  class Star_or_slash_or_percentContext;
  class Integer_expr_parenContext;
  class Integer_expr_argContext;
  class Parameter_refContext;
  class Concat_numberContext;
  class Concat_number_listContext;
  class Pin_idContext;
  class Port_nameContext;
  class Register_nameContext;
  class Instance_nameContext;
  class Namespace_nameContext;
  class Module_nameContext;
  class Reg_port_signal_idContext;
  class SignalContext;
  class X_signalContext;
  class Data_signalContext;
  class Scan_signalContext;
  class CaptureEn_signalContext;
  class UpdateEn_signalContext;
  class Concat_reset_signalContext;
  class Concat_data_signalContext;
  class Concat_scan_signalContext;
  class Concat_clock_signalContext;
  class Concat_shiftEn_signalContext;
  class Concat_tms_signalContext;
  class Concat_trst_signalContext;
  class Icl_sourceContext;
  class IclSource_itemsContext;
  class NameSpace_defContext;
  class UseNameSpace_defContext;
  class Module_defContext;
  class Module_itemsContext;
  class Module_itemContext;
  class Port_defContext;
  class ScanInPort_defContext;
  class ScanInPort_tailContext;
  class ScanInPort_itemsContext;
  class ScanInPort_nameContext;
  class ScanOutPort_defContext;
  class ScanOutPort_tailContext;
  class ScanOutPort_itemsContext;
  class ScanOutPort_nameContext;
  class ScanOutPort_itemContext;
  class ScanOutPort_sourceContext;
  class ScanOutPort_enableContext;
  class ScanOutPort_launchEdgeContext;
  class Rising_or_fallingContext;
  class ShiftEnPort_defContext;
  class ShiftEnPort_tailContext;
  class ShiftEnPort_itemsContext;
  class ShiftEnPort_nameContext;
  class CaptureEnPort_defContext;
  class CaptureEnPort_tailContext;
  class CaptureEnPort_itemsContext;
  class CaptureEnPort_nameContext;
  class UpdateEnPort_defContext;
  class UpdateEnPort_tailContext;
  class UpdateEnPort_itemsContext;
  class UpdateEnPort_nameContext;
  class DataInPort_defContext;
  class DataInPort_tailContext;
  class DataInPort_itemsContext;
  class DataInPort_nameContext;
  class DataInPort_itemContext;
  class DataInPort_refEnumContext;
  class DataOutPort_defContext;
  class DataOutPort_tailContext;
  class DataOutPort_itemsContext;
  class DataOutPort_nameContext;
  class DataOutPort_itemContext;
  class DataOutPort_sourceContext;
  class DataOutPort_enableContext;
  class DataOutPort_refEnumContext;
  class ToShiftEnPort_defContext;
  class ToShiftEnPort_tailContext;
  class ToShiftEnPort_itemsContext;
  class ToShiftEnPort_nameContext;
  class ToShiftEnPort_itemContext;
  class ToShiftEnPort_sourceContext;
  class ToCaptureEnPort_defContext;
  class ToCaptureEnPort_tailContext;
  class ToCaptureEnPort_itemsContext;
  class ToCaptureEnPort_nameContext;
  class ToCaptureEnPort_itemContext;
  class ToCaptureEnPort_sourceContext;
  class ToUpdateEnPort_defContext;
  class ToUpdateEnPort_tailContext;
  class ToUpdateEnPort_itemsContext;
  class ToUpdateEnPort_nameContext;
  class ToUpdateEnPort_itemContext;
  class ToUpdateEnPort_sourceContext;
  class SelectPort_defContext;
  class SelectPort_tailContext;
  class SelectPort_itemsContext;
  class SelectPort_nameContext;
  class ToSelectPort_defContext;
  class ToSelectPort_nameContext;
  class ToSelectPort_tailContext;
  class ToSelectPort_itemsContext;
  class ToSelectPort_itemContext;
  class ToSelectPort_sourceContext;
  class ResetPort_defContext;
  class ResetPort_nameContext;
  class ResetPort_tailContext;
  class ResetPort_itemsContext;
  class ResetPort_itemContext;
  class ResetPort_polarityContext;
  class Zero_or_oneContext;
  class ToResetPort_defContext;
  class ToResetPort_nameContext;
  class ToResetPort_tailContext;
  class ToResetPort_itemsContext;
  class ToResetPort_itemContext;
  class ToResetPort_sourceContext;
  class ToResetPort_polarityContext;
  class TmsPort_defContext;
  class TmsPort_tailContext;
  class TmsPort_itemsContext;
  class TmsPort_nameContext;
  class ToTmsPort_defContext;
  class ToTmsPort_nameContext;
  class ToTmsPort_tailContext;
  class ToTmsPort_itemsContext;
  class ToTmsPort_itemContext;
  class ToTmsPort_sourceContext;
  class ToIRSelectPort_defContext;
  class ToIRSelectPort_tailContext;
  class ToIRSelectPort_itemsContext;
  class ToIRSelectPort_nameContext;
  class TckPort_defContext;
  class TckPort_tailContext;
  class TckPort_itemsContext;
  class TckPort_nameContext;
  class ToTckPort_defContext;
  class ToTckPort_tailContext;
  class ToTckPort_itemsContext;
  class ToTckPort_nameContext;
  class ClockPort_defContext;
  class ClockPort_nameContext;
  class ClockPort_tailContext;
  class ClockPort_itemsContext;
  class ClockPort_itemContext;
  class ClockPort_diffPortContext;
  class ToClockPort_defContext;
  class ToClockPort_nameContext;
  class ToClockPort_tailContext;
  class ToClockPort_itemsContext;
  class ToClockPort_itemContext;
  class ToClockPort_sourceContext;
  class FreqMultiplier_defContext;
  class FreqDivider_defContext;
  class DifferentialInvOf_defContext;
  class Period_defContext;
  class TunitContext;
  class TrstPort_defContext;
  class TrstPort_tailContext;
  class TrstPort_itemsContext;
  class TrstPort_nameContext;
  class ToTrstPort_defContext;
  class ToTrstPort_nameContext;
  class ToTrstPort_tailContext;
  class ToTrstPort_itemsContext;
  class ToTrstPort_itemContext;
  class ToTrstPort_sourceContext;
  class AddressPort_defContext;
  class AddressPort_tailContext;
  class AddressPort_itemsContext;
  class AddressPort_nameContext;
  class WriteEnPort_defContext;
  class WriteEnPort_tailContext;
  class WriteEnPort_itemsContext;
  class WriteEnPort_nameContext;
  class ReadEnPort_defContext;
  class ReadEnPort_tailContext;
  class ReadEnPort_itemsContext;
  class ReadEnPort_nameContext;
  class Instance_defContext;
  class Instance_moduleContext;
  class Instance_tailContext;
  class Instance_itemsContext;
  class Instance_itemContext;
  class InputPort_connectionContext;
  class AllowBroadcast_defContext;
  class AllowBroadcast_itemsContext;
  class InputPort_nameContext;
  class InputPort_sourceContext;
  class Parameter_overrideContext;
  class Instance_addressValueContext;
  class ScanRegister_defContext;
  class ScanRegister_nameContext;
  class ScanRegister_tailContext;
  class ScanRegister_itemsContext;
  class ScanRegister_itemContext;
  class ScanRegister_scanInSourceContext;
  class ScanRegister_defaultLoadValueContext;
  class ScanRegister_captureSourceContext;
  class ScanRegister_resetValueContext;
  class ScanRegister_refEnumContext;
  class Number_or_enumContext;
  class Signal_or_enumContext;
  class DataRegister_defContext;
  class DataRegister_nameContext;
  class DataRegister_tailContext;
  class DataRegister_itemsContext;
  class DataRegister_itemContext;
  class DataRegister_typeContext;
  class DataRegister_commonContext;
  class DataRegister_resetValueContext;
  class DataRegister_defaultLoadValueContext;
  class DataRegister_refEnumContext;
  class DataRegister_selectableContext;
  class DataRegister_writeEnSourceContext;
  class DataRegister_writeDataSourceContext;
  class DataRegister_addressableContext;
  class DataRegister_addressValueContext;
  class DataRegister_readCallBackContext;
  class DataRegister_readCallBack_procContext;
  class IProc_arglistContext;
  class DataRegister_readDataSourceContext;
  class DataRegister_writeCallBackContext;
  class IProc_namespaceContext;
  class IProc_nameContext;
  class IProc_argsContext;
  class Sub_namespaceContext;
  class Ref_module_nameContext;
  class LogicSignal_defContext;
  class LogicSignal_nameContext;
  class Logic_exprContext;
  class Logic_expr_lvl1Context;
  class Logic_and_or_orContext;
  class Logic_expr_lvl2Context;
  class And_or_xorContext;
  class Logic_expr_lvl3Context;
  class Eq_or_neqContext;
  class Logic_expr_lvl4Context;
  class Logic_unary_exprContext;
  class Logic_expr_argContext;
  class Neg_or_notContext;
  class Logic_expr_parenContext;
  class Logic_expr_num_argContext;
  class ScanMux_defContext;
  class ScanMux_selectionsContext;
  class ScanMux_nameContext;
  class ScanMux_selectContext;
  class ScanMux_selectionContext;
  class DataMux_defContext;
  class DataMux_selectionsContext;
  class DataMux_nameContext;
  class DataMux_selectContext;
  class DataMux_selectionContext;
  class ClockMux_defContext;
  class ClockMux_selectionsContext;
  class ClockMux_nameContext;
  class ClockMux_selectContext;
  class ClockMux_selectionContext;
  class OneHotScanGroup_defContext;
  class OneHotScanGroup_itemsContext;
  class OneHotScanGroup_nameContext;
  class OneHotScanGroup_itemContext;
  class OneHotDataGroup_defContext;
  class OneHotDataGroup_itemsContext;
  class OneHotDataGroup_nameContext;
  class OneHotDataGroup_itemContext;
  class OneHotDataGroup_portSourceContext;
  class AccessLink_defContext;
  class AccessLinkGeneric_defContext;
  class AccessLink_genericIDContext;
  class AccessLink1149_defContext;
  class AccessLink1149_stdsContext;
  class AccessLink_nameContext;
  class BsdlEntity_nameContext;
  class Bsdl_instr_refsContext;
  class Bsdl_instr_refContext;
  class Bsdl_instr_selected_itemsContext;
  class Bsdl_instr_nameContext;
  class Bsdl_instr_selected_itemContext;
  class AccessLink1149_ScanInterface_namesContext;
  class AccessLink1149_ActiveSignal_nameContext;
  class AccessLink1149_ActiveSignal_namesContext;
  class AccessLink1149_ScanInterface_nameContext;
  class ScanInterface_defContext;
  class ScanInterface_itemsContext;
  class ScanInterface_nameContext;
  class ScanInterface_itemContext;
  class ScanInterfacePort_defContext;
  class ScanInterfaceChain_defContext;
  class ScanInterfaceChain_itemsContext;
  class ScanInterfaceChain_nameContext;
  class ScanInterfaceChain_itemContext;
  class DefaultLoad_defContext;
  class Alias_defContext;
  class Alias_nameContext;
  class Alias_tailContext;
  class Alias_itemsContext;
  class Alias_itemContext;
  class Alias_iApplyEndStateContext;
  class Alias_refEnumContext;
  class Concat_hier_data_signalContext;
  class X_hier_data_signalContext;
  class Hier_data_signalContext;
  class Hier_data_signal_instancesContext;
  class Enum_defContext;
  class Enum_itemsContext;
  class Enum_nameContext;
  class Enum_itemContext;
  class Enum_symbolContext;
  class Enum_valueContext;
  class Parameter_defContext;
  class LocalParameter_defContext;
  class Parameter_nameContext;
  class Parameter_valueContext;
  class Concat_stringContext;
  class String_or_parmContext;
  class Attribute_defContext;
  class Attribute_nameContext;
  class Attribute_valueContext; 

  class  Pos_intContext : public antlr4::ParserRuleContext {
  public:
    Pos_intContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POS_INT();
    antlr4::tree::TerminalNode *ONE();
    antlr4::tree::TerminalNode *ZERO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pos_intContext* pos_int();

  class  Vector_idContext : public antlr4::ParserRuleContext {
  public:
    Vector_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    Index_or_rangeContext *index_or_range();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Vector_idContext* vector_id();

  class  Index_or_rangeContext : public antlr4::ParserRuleContext {
  public:
    Index_or_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexContext *index();
    RangeContext *range();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Index_or_rangeContext* index_or_range();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_exprContext *integer_expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);
    antlr4::tree::TerminalNode *COLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeContext* range();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIZED_DEC_NUM();
    antlr4::tree::TerminalNode *UNSIZED_BIN_NUM();
    antlr4::tree::TerminalNode *UNSIZED_HEX_NUM();
    Integer_exprContext *integer_expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  Integer_exprContext : public antlr4::ParserRuleContext {
  public:
    Integer_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_expr_lvl1Context *integer_expr_lvl1();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_exprContext* integer_expr();

  class  Integer_expr_lvl1Context : public antlr4::ParserRuleContext {
  public:
    Integer_expr_lvl1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_expr_lvl2Context *integer_expr_lvl2();
    Integer_expr_lvl1_bContext *integer_expr_lvl1_b();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_lvl1Context* integer_expr_lvl1();

  class  Integer_expr_lvl1_bContext : public antlr4::ParserRuleContext {
  public:
    Integer_expr_lvl1_bContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Plus_or_minusContext *plus_or_minus();
    Integer_expr_lvl1Context *integer_expr_lvl1();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_lvl1_bContext* integer_expr_lvl1_b();

  class  Plus_or_minusContext : public antlr4::ParserRuleContext {
  public:
    Plus_or_minusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Plus_or_minusContext* plus_or_minus();

  class  Integer_expr_lvl2Context : public antlr4::ParserRuleContext {
  public:
    Integer_expr_lvl2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_expr_argContext *integer_expr_arg();
    Integer_expr_lvl2_bContext *integer_expr_lvl2_b();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_lvl2Context* integer_expr_lvl2();

  class  Integer_expr_lvl2_bContext : public antlr4::ParserRuleContext {
  public:
    Integer_expr_lvl2_bContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Star_or_slash_or_percentContext *star_or_slash_or_percent();
    Integer_expr_lvl2Context *integer_expr_lvl2();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_lvl2_bContext* integer_expr_lvl2_b();

  class  Star_or_slash_or_percentContext : public antlr4::ParserRuleContext {
  public:
    Star_or_slash_or_percentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PERCENT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Star_or_slash_or_percentContext* star_or_slash_or_percent();

  class  Integer_expr_parenContext : public antlr4::ParserRuleContext {
  public:
    Integer_expr_parenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    Integer_exprContext *integer_expr();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_parenContext* integer_expr_paren();

  class  Integer_expr_argContext : public antlr4::ParserRuleContext {
  public:
    Integer_expr_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_expr_parenContext *integer_expr_paren();
    Pos_intContext *pos_int();
    Parameter_refContext *parameter_ref();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_expr_argContext* integer_expr_arg();

  class  Parameter_refContext : public antlr4::ParserRuleContext {
  public:
    Parameter_refContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOLLAR();
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_refContext* parameter_ref();

  class  Concat_numberContext : public antlr4::ParserRuleContext {
  public:
    Concat_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    antlr4::tree::TerminalNode *TILDE();
    Concat_numberContext *concat_number();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_numberContext* concat_number();
  Concat_numberContext* concat_number(int precedence);
  class  Concat_number_listContext : public antlr4::ParserRuleContext {
  public:
    Concat_number_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_numberContext *concat_number();
    Concat_number_listContext *concat_number_list();
    antlr4::tree::TerminalNode *PIPE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_number_listContext* concat_number_list();
  Concat_number_listContext* concat_number_list(int precedence);
  class  Pin_idContext : public antlr4::ParserRuleContext {
  public:
    Pin_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_nameContext *instance_name();
    antlr4::tree::TerminalNode *DOT();
    Pin_idContext *pin_id();
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pin_idContext* pin_id();

  class  Port_nameContext : public antlr4::ParserRuleContext {
  public:
    Port_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Vector_idContext *vector_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_nameContext* port_name();

  class  Register_nameContext : public antlr4::ParserRuleContext {
  public:
    Register_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Vector_idContext *vector_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Register_nameContext* register_name();

  class  Instance_nameContext : public antlr4::ParserRuleContext {
  public:
    Instance_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_nameContext* instance_name();

  class  Namespace_nameContext : public antlr4::ParserRuleContext {
  public:
    Namespace_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_nameContext* namespace_name();

  class  Module_nameContext : public antlr4::ParserRuleContext {
  public:
    Module_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_nameContext* module_name();

  class  Reg_port_signal_idContext : public antlr4::ParserRuleContext {
  public:
    Reg_port_signal_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Vector_idContext *vector_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reg_port_signal_idContext* reg_port_signal_id();

  class  SignalContext : public antlr4::ParserRuleContext {
  public:
    SignalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    Reg_port_signal_idContext *reg_port_signal_id();
    Pin_idContext *pin_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignalContext* signal();

  class  X_signalContext : public antlr4::ParserRuleContext {
  public:
    X_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalContext *signal();
    antlr4::tree::TerminalNode *TILDE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  X_signalContext* x_signal();

  class  Data_signalContext : public antlr4::ParserRuleContext {
  public:
    Data_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalContext *signal();
    antlr4::tree::TerminalNode *TILDE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_signalContext* data_signal();

  class  Scan_signalContext : public antlr4::ParserRuleContext {
  public:
    Scan_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalContext *signal();
    antlr4::tree::TerminalNode *TILDE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Scan_signalContext* scan_signal();

  class  CaptureEn_signalContext : public antlr4::ParserRuleContext {
  public:
    CaptureEn_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureEn_signalContext* captureEn_signal();

  class  UpdateEn_signalContext : public antlr4::ParserRuleContext {
  public:
    UpdateEn_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdateEn_signalContext* updateEn_signal();

  class  Concat_reset_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_reset_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_reset_signalContext *concat_reset_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_reset_signalContext* concat_reset_signal();
  Concat_reset_signalContext* concat_reset_signal(int precedence);
  class  Concat_data_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_data_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_data_signalContext* concat_data_signal();
  Concat_data_signalContext* concat_data_signal(int precedence);
  class  Concat_scan_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_scan_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_scan_signalContext *concat_scan_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_scan_signalContext* concat_scan_signal();
  Concat_scan_signalContext* concat_scan_signal(int precedence);
  class  Concat_clock_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_clock_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_clock_signalContext *concat_clock_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_clock_signalContext* concat_clock_signal();
  Concat_clock_signalContext* concat_clock_signal(int precedence);
  class  Concat_shiftEn_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_shiftEn_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_shiftEn_signalContext *concat_shiftEn_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_shiftEn_signalContext* concat_shiftEn_signal();
  Concat_shiftEn_signalContext* concat_shiftEn_signal(int precedence);
  class  Concat_tms_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_tms_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignalContext *signal();
    Concat_tms_signalContext *concat_tms_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_tms_signalContext* concat_tms_signal();
  Concat_tms_signalContext* concat_tms_signal(int precedence);
  class  Concat_trst_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_trst_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_signalContext *x_signal();
    Concat_trst_signalContext *concat_trst_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_trst_signalContext* concat_trst_signal();
  Concat_trst_signalContext* concat_trst_signal(int precedence);
  class  Icl_sourceContext : public antlr4::ParserRuleContext {
  public:
    Icl_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<IclSource_itemsContext *> iclSource_items();
    IclSource_itemsContext* iclSource_items(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Icl_sourceContext* icl_source();

  class  IclSource_itemsContext : public antlr4::ParserRuleContext {
  public:
    IclSource_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameSpace_defContext *nameSpace_def();
    UseNameSpace_defContext *useNameSpace_def();
    Module_defContext *module_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IclSource_itemsContext* iclSource_items();

  class  NameSpace_defContext : public antlr4::ParserRuleContext {
  public:
    NameSpace_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMESPACE();
    Namespace_nameContext *namespace_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameSpace_defContext* nameSpace_def();

  class  UseNameSpace_defContext : public antlr4::ParserRuleContext {
  public:
    UseNameSpace_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USENAMESPACE();
    Namespace_nameContext *namespace_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseNameSpace_defContext* useNameSpace_def();

  class  Module_defContext : public antlr4::ParserRuleContext {
  public:
    Module_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    Module_nameContext *module_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Module_itemsContext *module_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_defContext* module_def();

  class  Module_itemsContext : public antlr4::ParserRuleContext {
  public:
    Module_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_itemContext *module_item();
    Module_itemsContext *module_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_itemsContext* module_items();
  Module_itemsContext* module_items(int precedence);
  class  Module_itemContext : public antlr4::ParserRuleContext {
  public:
    Module_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UseNameSpace_defContext *useNameSpace_def();
    Attribute_defContext *attribute_def();
    Parameter_defContext *parameter_def();
    LocalParameter_defContext *localParameter_def();
    ScanInterface_defContext *scanInterface_def();
    Port_defContext *port_def();
    Instance_defContext *instance_def();
    LogicSignal_defContext *logicSignal_def();
    ScanRegister_defContext *scanRegister_def();
    DataRegister_defContext *dataRegister_def();
    ScanMux_defContext *scanMux_def();
    DataMux_defContext *dataMux_def();
    ClockMux_defContext *clockMux_def();
    OneHotDataGroup_defContext *oneHotDataGroup_def();
    OneHotScanGroup_defContext *oneHotScanGroup_def();
    Enum_defContext *enum_def();
    Alias_defContext *alias_def();
    AccessLink_defContext *accessLink_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_itemContext* module_item();

  class  Port_defContext : public antlr4::ParserRuleContext {
  public:
    Port_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanInPort_defContext *scanInPort_def();
    ScanOutPort_defContext *scanOutPort_def();
    ShiftEnPort_defContext *shiftEnPort_def();
    CaptureEnPort_defContext *captureEnPort_def();
    UpdateEnPort_defContext *updateEnPort_def();
    DataInPort_defContext *dataInPort_def();
    DataOutPort_defContext *dataOutPort_def();
    ToShiftEnPort_defContext *toShiftEnPort_def();
    ToUpdateEnPort_defContext *toUpdateEnPort_def();
    ToCaptureEnPort_defContext *toCaptureEnPort_def();
    SelectPort_defContext *selectPort_def();
    ToSelectPort_defContext *toSelectPort_def();
    ResetPort_defContext *resetPort_def();
    ToIRSelectPort_defContext *toIRSelectPort_def();
    TmsPort_defContext *tmsPort_def();
    ToTmsPort_defContext *toTmsPort_def();
    TckPort_defContext *tckPort_def();
    ToTckPort_defContext *toTckPort_def();
    ClockPort_defContext *clockPort_def();
    ToClockPort_defContext *toClockPort_def();
    TrstPort_defContext *trstPort_def();
    ToTrstPort_defContext *toTrstPort_def();
    ToResetPort_defContext *toResetPort_def();
    AddressPort_defContext *addressPort_def();
    WriteEnPort_defContext *writeEnPort_def();
    ReadEnPort_defContext *readEnPort_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_defContext* port_def();

  class  ScanInPort_defContext : public antlr4::ParserRuleContext {
  public:
    ScanInPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANINPORT();
    ScanInPort_nameContext *scanInPort_name();
    ScanInPort_tailContext *scanInPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInPort_defContext* scanInPort_def();

  class  ScanInPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ScanInPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanInPort_itemsContext *scanInPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInPort_tailContext* scanInPort_tail();

  class  ScanInPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ScanInPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ScanInPort_itemsContext *scanInPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInPort_itemsContext* scanInPort_items();
  ScanInPort_itemsContext* scanInPort_items(int precedence);
  class  ScanInPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanInPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInPort_nameContext* scanInPort_name();

  class  ScanOutPort_defContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANOUTPORT();
    ScanOutPort_nameContext *scanOutPort_name();
    ScanOutPort_tailContext *scanOutPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_defContext* scanOutPort_def();

  class  ScanOutPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanOutPort_itemsContext *scanOutPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_tailContext* scanOutPort_tail();

  class  ScanOutPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanOutPort_itemContext *scanOutPort_item();
    ScanOutPort_itemsContext *scanOutPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_itemsContext* scanOutPort_items();
  ScanOutPort_itemsContext* scanOutPort_items(int precedence);
  class  ScanOutPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_nameContext* scanOutPort_name();

  class  ScanOutPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ScanOutPort_sourceContext *scanOutPort_source();
    ScanOutPort_enableContext *scanOutPort_enable();
    ScanOutPort_launchEdgeContext *scanOutPort_launchEdge();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_itemContext* scanOutPort_item();

  class  ScanOutPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_scan_signalContext *concat_scan_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_sourceContext* scanOutPort_source();

  class  ScanOutPort_enableContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_enableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENABLE();
    Data_signalContext *data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_enableContext* scanOutPort_enable();

  class  ScanOutPort_launchEdgeContext : public antlr4::ParserRuleContext {
  public:
    ScanOutPort_launchEdgeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LAUNCHEDGE();
    Rising_or_fallingContext *rising_or_falling();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanOutPort_launchEdgeContext* scanOutPort_launchEdge();

  class  Rising_or_fallingContext : public antlr4::ParserRuleContext {
  public:
    Rising_or_fallingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RISING();
    antlr4::tree::TerminalNode *FALLING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rising_or_fallingContext* rising_or_falling();

  class  ShiftEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    ShiftEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHIFTENPORT();
    ShiftEnPort_nameContext *shiftEnPort_name();
    ShiftEnPort_tailContext *shiftEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftEnPort_defContext* shiftEnPort_def();

  class  ShiftEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ShiftEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ShiftEnPort_itemsContext *shiftEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftEnPort_tailContext* shiftEnPort_tail();

  class  ShiftEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ShiftEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ShiftEnPort_itemsContext *shiftEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftEnPort_itemsContext* shiftEnPort_items();
  ShiftEnPort_itemsContext* shiftEnPort_items(int precedence);
  class  ShiftEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ShiftEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftEnPort_nameContext* shiftEnPort_name();

  class  CaptureEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    CaptureEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAPTUREENPORT();
    CaptureEnPort_nameContext *captureEnPort_name();
    CaptureEnPort_tailContext *captureEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureEnPort_defContext* captureEnPort_def();

  class  CaptureEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    CaptureEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    CaptureEnPort_itemsContext *captureEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureEnPort_tailContext* captureEnPort_tail();

  class  CaptureEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    CaptureEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    CaptureEnPort_itemsContext *captureEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureEnPort_itemsContext* captureEnPort_items();
  CaptureEnPort_itemsContext* captureEnPort_items(int precedence);
  class  CaptureEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    CaptureEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaptureEnPort_nameContext* captureEnPort_name();

  class  UpdateEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    UpdateEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UPDATEENPORT();
    UpdateEnPort_nameContext *updateEnPort_name();
    UpdateEnPort_tailContext *updateEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdateEnPort_defContext* updateEnPort_def();

  class  UpdateEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    UpdateEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    UpdateEnPort_itemsContext *updateEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdateEnPort_tailContext* updateEnPort_tail();

  class  UpdateEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    UpdateEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    UpdateEnPort_itemsContext *updateEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdateEnPort_itemsContext* updateEnPort_items();
  UpdateEnPort_itemsContext* updateEnPort_items(int precedence);
  class  UpdateEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    UpdateEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UpdateEnPort_nameContext* updateEnPort_name();

  class  DataInPort_defContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATAINPORT();
    DataInPort_nameContext *dataInPort_name();
    DataInPort_tailContext *dataInPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_defContext* dataInPort_def();

  class  DataInPort_tailContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    DataInPort_itemsContext *dataInPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_tailContext* dataInPort_tail();

  class  DataInPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataInPort_itemContext *dataInPort_item();
    DataInPort_itemsContext *dataInPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_itemsContext* dataInPort_items();
  DataInPort_itemsContext* dataInPort_items(int precedence);
  class  DataInPort_nameContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_nameContext* dataInPort_name();

  class  DataInPort_itemContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    DataInPort_refEnumContext *dataInPort_refEnum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_itemContext* dataInPort_item();

  class  DataInPort_refEnumContext : public antlr4::ParserRuleContext {
  public:
    DataInPort_refEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataInPort_refEnumContext* dataInPort_refEnum();

  class  DataOutPort_defContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATAOUTPORT();
    DataOutPort_nameContext *dataOutPort_name();
    DataOutPort_tailContext *dataOutPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_defContext* dataOutPort_def();

  class  DataOutPort_tailContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    DataOutPort_itemsContext *dataOutPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_tailContext* dataOutPort_tail();

  class  DataOutPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataOutPort_itemContext *dataOutPort_item();
    DataOutPort_itemsContext *dataOutPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_itemsContext* dataOutPort_items();
  DataOutPort_itemsContext* dataOutPort_items(int precedence);
  class  DataOutPort_nameContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_nameContext* dataOutPort_name();

  class  DataOutPort_itemContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    DataOutPort_sourceContext *dataOutPort_source();
    DataOutPort_enableContext *dataOutPort_enable();
    DataOutPort_refEnumContext *dataOutPort_refEnum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_itemContext* dataOutPort_item();

  class  DataOutPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_sourceContext* dataOutPort_source();

  class  DataOutPort_enableContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_enableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENABLE();
    Data_signalContext *data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_enableContext* dataOutPort_enable();

  class  DataOutPort_refEnumContext : public antlr4::ParserRuleContext {
  public:
    DataOutPort_refEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataOutPort_refEnumContext* dataOutPort_refEnum();

  class  ToShiftEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOSHIFTENPORT();
    ToShiftEnPort_nameContext *toShiftEnPort_name();
    ToShiftEnPort_tailContext *toShiftEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_defContext* toShiftEnPort_def();

  class  ToShiftEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToShiftEnPort_itemsContext *toShiftEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_tailContext* toShiftEnPort_tail();

  class  ToShiftEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToShiftEnPort_itemContext *toShiftEnPort_item();
    ToShiftEnPort_itemsContext *toShiftEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_itemsContext* toShiftEnPort_items();
  ToShiftEnPort_itemsContext* toShiftEnPort_items(int precedence);
  class  ToShiftEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_nameContext* toShiftEnPort_name();

  class  ToShiftEnPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToShiftEnPort_sourceContext *toShiftEnPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_itemContext* toShiftEnPort_item();

  class  ToShiftEnPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToShiftEnPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_shiftEn_signalContext *concat_shiftEn_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToShiftEnPort_sourceContext* toShiftEnPort_source();

  class  ToCaptureEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOCAPTUREENPORT();
    ToCaptureEnPort_nameContext *toCaptureEnPort_name();
    ToCaptureEnPort_tailContext *toCaptureEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_defContext* toCaptureEnPort_def();

  class  ToCaptureEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToCaptureEnPort_itemsContext *toCaptureEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_tailContext* toCaptureEnPort_tail();

  class  ToCaptureEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToCaptureEnPort_itemContext *toCaptureEnPort_item();
    ToCaptureEnPort_itemsContext *toCaptureEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_itemsContext* toCaptureEnPort_items();
  ToCaptureEnPort_itemsContext* toCaptureEnPort_items(int precedence);
  class  ToCaptureEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_nameContext* toCaptureEnPort_name();

  class  ToCaptureEnPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToCaptureEnPort_sourceContext *toCaptureEnPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_itemContext* toCaptureEnPort_item();

  class  ToCaptureEnPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToCaptureEnPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    CaptureEn_signalContext *captureEn_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToCaptureEnPort_sourceContext* toCaptureEnPort_source();

  class  ToUpdateEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOUPDATEENPORT();
    ToUpdateEnPort_nameContext *toUpdateEnPort_name();
    ToUpdateEnPort_tailContext *toUpdateEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_defContext* toUpdateEnPort_def();

  class  ToUpdateEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToUpdateEnPort_itemsContext *toUpdateEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_tailContext* toUpdateEnPort_tail();

  class  ToUpdateEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToUpdateEnPort_itemContext *toUpdateEnPort_item();
    ToUpdateEnPort_itemsContext *toUpdateEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_itemsContext* toUpdateEnPort_items();
  ToUpdateEnPort_itemsContext* toUpdateEnPort_items(int precedence);
  class  ToUpdateEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_nameContext* toUpdateEnPort_name();

  class  ToUpdateEnPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToUpdateEnPort_sourceContext *toUpdateEnPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_itemContext* toUpdateEnPort_item();

  class  ToUpdateEnPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToUpdateEnPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    UpdateEn_signalContext *updateEn_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToUpdateEnPort_sourceContext* toUpdateEnPort_source();

  class  SelectPort_defContext : public antlr4::ParserRuleContext {
  public:
    SelectPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECTPORT();
    SelectPort_nameContext *selectPort_name();
    SelectPort_tailContext *selectPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectPort_defContext* selectPort_def();

  class  SelectPort_tailContext : public antlr4::ParserRuleContext {
  public:
    SelectPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    SelectPort_itemsContext *selectPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectPort_tailContext* selectPort_tail();

  class  SelectPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    SelectPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    SelectPort_itemsContext *selectPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectPort_itemsContext* selectPort_items();
  SelectPort_itemsContext* selectPort_items(int precedence);
  class  SelectPort_nameContext : public antlr4::ParserRuleContext {
  public:
    SelectPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectPort_nameContext* selectPort_name();

  class  ToSelectPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOSELECTPORT();
    ToSelectPort_nameContext *toSelectPort_name();
    ToSelectPort_tailContext *toSelectPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_defContext* toSelectPort_def();

  class  ToSelectPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_nameContext* toSelectPort_name();

  class  ToSelectPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToSelectPort_itemsContext *toSelectPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_tailContext* toSelectPort_tail();

  class  ToSelectPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToSelectPort_itemContext *toSelectPort_item();
    ToSelectPort_itemsContext *toSelectPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_itemsContext* toSelectPort_items();
  ToSelectPort_itemsContext* toSelectPort_items(int precedence);
  class  ToSelectPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToSelectPort_sourceContext *toSelectPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_itemContext* toSelectPort_item();

  class  ToSelectPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToSelectPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToSelectPort_sourceContext* toSelectPort_source();

  class  ResetPort_defContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESETPORT();
    ResetPort_nameContext *resetPort_name();
    ResetPort_tailContext *resetPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_defContext* resetPort_def();

  class  ResetPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_nameContext* resetPort_name();

  class  ResetPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ResetPort_itemsContext *resetPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_tailContext* resetPort_tail();

  class  ResetPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ResetPort_itemContext *resetPort_item();
    ResetPort_itemsContext *resetPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_itemsContext* resetPort_items();
  ResetPort_itemsContext* resetPort_items(int precedence);
  class  ResetPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ResetPort_polarityContext *resetPort_polarity();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_itemContext* resetPort_item();

  class  ResetPort_polarityContext : public antlr4::ParserRuleContext {
  public:
    ResetPort_polarityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTIVEPOLARITY();
    Zero_or_oneContext *zero_or_one();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetPort_polarityContext* resetPort_polarity();

  class  Zero_or_oneContext : public antlr4::ParserRuleContext {
  public:
    Zero_or_oneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZERO();
    antlr4::tree::TerminalNode *ONE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Zero_or_oneContext* zero_or_one();

  class  ToResetPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TORESETPORT();
    ToResetPort_nameContext *toResetPort_name();
    ToResetPort_tailContext *toResetPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_defContext* toResetPort_def();

  class  ToResetPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_nameContext* toResetPort_name();

  class  ToResetPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToResetPort_itemsContext *toResetPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_tailContext* toResetPort_tail();

  class  ToResetPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToResetPort_itemContext *toResetPort_item();
    ToResetPort_itemsContext *toResetPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_itemsContext* toResetPort_items();
  ToResetPort_itemsContext* toResetPort_items(int precedence);
  class  ToResetPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToResetPort_sourceContext *toResetPort_source();
    ToResetPort_polarityContext *toResetPort_polarity();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_itemContext* toResetPort_item();

  class  ToResetPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_reset_signalContext *concat_reset_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_sourceContext* toResetPort_source();

  class  ToResetPort_polarityContext : public antlr4::ParserRuleContext {
  public:
    ToResetPort_polarityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTIVEPOLARITY();
    Zero_or_oneContext *zero_or_one();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToResetPort_polarityContext* toResetPort_polarity();

  class  TmsPort_defContext : public antlr4::ParserRuleContext {
  public:
    TmsPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TMSPORT();
    TmsPort_nameContext *tmsPort_name();
    TmsPort_tailContext *tmsPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TmsPort_defContext* tmsPort_def();

  class  TmsPort_tailContext : public antlr4::ParserRuleContext {
  public:
    TmsPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    TmsPort_itemsContext *tmsPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TmsPort_tailContext* tmsPort_tail();

  class  TmsPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    TmsPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    TmsPort_itemsContext *tmsPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TmsPort_itemsContext* tmsPort_items();
  TmsPort_itemsContext* tmsPort_items(int precedence);
  class  TmsPort_nameContext : public antlr4::ParserRuleContext {
  public:
    TmsPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TmsPort_nameContext* tmsPort_name();

  class  ToTmsPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOTMSPORT();
    ToTmsPort_nameContext *toTmsPort_name();
    ToTmsPort_tailContext *toTmsPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_defContext* toTmsPort_def();

  class  ToTmsPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_nameContext* toTmsPort_name();

  class  ToTmsPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToTmsPort_itemsContext *toTmsPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_tailContext* toTmsPort_tail();

  class  ToTmsPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToTmsPort_itemContext *toTmsPort_item();
    ToTmsPort_itemsContext *toTmsPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_itemsContext* toTmsPort_items();
  ToTmsPort_itemsContext* toTmsPort_items(int precedence);
  class  ToTmsPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToTmsPort_sourceContext *toTmsPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_itemContext* toTmsPort_item();

  class  ToTmsPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToTmsPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_tms_signalContext *concat_tms_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTmsPort_sourceContext* toTmsPort_source();

  class  ToIRSelectPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToIRSelectPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOIRSELECTPORT();
    ToIRSelectPort_nameContext *toIRSelectPort_name();
    ToIRSelectPort_tailContext *toIRSelectPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToIRSelectPort_defContext* toIRSelectPort_def();

  class  ToIRSelectPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToIRSelectPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToIRSelectPort_itemsContext *toIRSelectPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToIRSelectPort_tailContext* toIRSelectPort_tail();

  class  ToIRSelectPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToIRSelectPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToIRSelectPort_itemsContext *toIRSelectPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToIRSelectPort_itemsContext* toIRSelectPort_items();
  ToIRSelectPort_itemsContext* toIRSelectPort_items(int precedence);
  class  ToIRSelectPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToIRSelectPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToIRSelectPort_nameContext* toIRSelectPort_name();

  class  TckPort_defContext : public antlr4::ParserRuleContext {
  public:
    TckPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TCKPORT();
    TckPort_nameContext *tckPort_name();
    TckPort_tailContext *tckPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TckPort_defContext* tckPort_def();

  class  TckPort_tailContext : public antlr4::ParserRuleContext {
  public:
    TckPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    TckPort_itemsContext *tckPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TckPort_tailContext* tckPort_tail();

  class  TckPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    TckPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    TckPort_itemsContext *tckPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TckPort_itemsContext* tckPort_items();
  TckPort_itemsContext* tckPort_items(int precedence);
  class  TckPort_nameContext : public antlr4::ParserRuleContext {
  public:
    TckPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TckPort_nameContext* tckPort_name();

  class  ToTckPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToTckPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOTCKPORT();
    ToTckPort_nameContext *toTckPort_name();
    ToTckPort_tailContext *toTckPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTckPort_defContext* toTckPort_def();

  class  ToTckPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToTckPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToTckPort_itemsContext *toTckPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTckPort_tailContext* toTckPort_tail();

  class  ToTckPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToTckPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToTckPort_itemsContext *toTckPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTckPort_itemsContext* toTckPort_items();
  ToTckPort_itemsContext* toTckPort_items(int precedence);
  class  ToTckPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToTckPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTckPort_nameContext* toTckPort_name();

  class  ClockPort_defContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLOCKPORT();
    ClockPort_nameContext *clockPort_name();
    ClockPort_tailContext *clockPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_defContext* clockPort_def();

  class  ClockPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_nameContext* clockPort_name();

  class  ClockPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ClockPort_itemsContext *clockPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_tailContext* clockPort_tail();

  class  ClockPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClockPort_itemContext *clockPort_item();
    ClockPort_itemsContext *clockPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_itemsContext* clockPort_items();
  ClockPort_itemsContext* clockPort_items(int precedence);
  class  ClockPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ClockPort_diffPortContext *clockPort_diffPort();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_itemContext* clockPort_item();

  class  ClockPort_diffPortContext : public antlr4::ParserRuleContext {
  public:
    ClockPort_diffPortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIFFERENTIALINVOF();
    Concat_clock_signalContext *concat_clock_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockPort_diffPortContext* clockPort_diffPort();

  class  ToClockPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOCLOCKPORT();
    ToClockPort_nameContext *toClockPort_name();
    ToClockPort_tailContext *toClockPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_defContext* toClockPort_def();

  class  ToClockPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_nameContext* toClockPort_name();

  class  ToClockPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToClockPort_itemsContext *toClockPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_tailContext* toClockPort_tail();

  class  ToClockPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToClockPort_itemContext *toClockPort_item();
    ToClockPort_itemsContext *toClockPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_itemsContext* toClockPort_items();
  ToClockPort_itemsContext* toClockPort_items(int precedence);
  class  ToClockPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToClockPort_sourceContext *toClockPort_source();
    FreqMultiplier_defContext *freqMultiplier_def();
    FreqDivider_defContext *freqDivider_def();
    DifferentialInvOf_defContext *differentialInvOf_def();
    Period_defContext *period_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_itemContext* toClockPort_item();

  class  ToClockPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToClockPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_clock_signalContext *concat_clock_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToClockPort_sourceContext* toClockPort_source();

  class  FreqMultiplier_defContext : public antlr4::ParserRuleContext {
  public:
    FreqMultiplier_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FREQMULTIPLIER();
    Pos_intContext *pos_int();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FreqMultiplier_defContext* freqMultiplier_def();

  class  FreqDivider_defContext : public antlr4::ParserRuleContext {
  public:
    FreqDivider_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FREQDIVIDER();
    Pos_intContext *pos_int();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FreqDivider_defContext* freqDivider_def();

  class  DifferentialInvOf_defContext : public antlr4::ParserRuleContext {
  public:
    DifferentialInvOf_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIFFERENTIALINVOF();
    Concat_clock_signalContext *concat_clock_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DifferentialInvOf_defContext* differentialInvOf_def();

  class  Period_defContext : public antlr4::ParserRuleContext {
  public:
    Period_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PERIOD();
    Pos_intContext *pos_int();
    TunitContext *tunit();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Period_defContext* period_def();

  class  TunitContext : public antlr4::ParserRuleContext {
  public:
    TunitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEC();
    antlr4::tree::TerminalNode *MSEC();
    antlr4::tree::TerminalNode *USEC();
    antlr4::tree::TerminalNode *NSEC();
    antlr4::tree::TerminalNode *PSEC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TunitContext* tunit();

  class  TrstPort_defContext : public antlr4::ParserRuleContext {
  public:
    TrstPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRSTPORT();
    TrstPort_nameContext *trstPort_name();
    TrstPort_tailContext *trstPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrstPort_defContext* trstPort_def();

  class  TrstPort_tailContext : public antlr4::ParserRuleContext {
  public:
    TrstPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    TrstPort_itemsContext *trstPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrstPort_tailContext* trstPort_tail();

  class  TrstPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    TrstPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    TrstPort_itemsContext *trstPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrstPort_itemsContext* trstPort_items();
  TrstPort_itemsContext* trstPort_items(int precedence);
  class  TrstPort_nameContext : public antlr4::ParserRuleContext {
  public:
    TrstPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrstPort_nameContext* trstPort_name();

  class  ToTrstPort_defContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOTRSTPORT();
    ToTrstPort_nameContext *toTrstPort_name();
    ToTrstPort_tailContext *toTrstPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_defContext* toTrstPort_def();

  class  ToTrstPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_nameContext* toTrstPort_name();

  class  ToTrstPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ToTrstPort_itemsContext *toTrstPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_tailContext* toTrstPort_tail();

  class  ToTrstPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToTrstPort_itemContext *toTrstPort_item();
    ToTrstPort_itemsContext *toTrstPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_itemsContext* toTrstPort_items();
  ToTrstPort_itemsContext* toTrstPort_items(int precedence);
  class  ToTrstPort_itemContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ToTrstPort_sourceContext *toTrstPort_source();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_itemContext* toTrstPort_item();

  class  ToTrstPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    ToTrstPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    Concat_trst_signalContext *concat_trst_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToTrstPort_sourceContext* toTrstPort_source();

  class  AddressPort_defContext : public antlr4::ParserRuleContext {
  public:
    AddressPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRESSPORT();
    AddressPort_nameContext *addressPort_name();
    AddressPort_tailContext *addressPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddressPort_defContext* addressPort_def();

  class  AddressPort_tailContext : public antlr4::ParserRuleContext {
  public:
    AddressPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    AddressPort_itemsContext *addressPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddressPort_tailContext* addressPort_tail();

  class  AddressPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    AddressPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    AddressPort_itemsContext *addressPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddressPort_itemsContext* addressPort_items();
  AddressPort_itemsContext* addressPort_items(int precedence);
  class  AddressPort_nameContext : public antlr4::ParserRuleContext {
  public:
    AddressPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddressPort_nameContext* addressPort_name();

  class  WriteEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    WriteEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITEENPORT();
    WriteEnPort_nameContext *writeEnPort_name();
    WriteEnPort_tailContext *writeEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteEnPort_defContext* writeEnPort_def();

  class  WriteEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    WriteEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    WriteEnPort_itemsContext *writeEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteEnPort_tailContext* writeEnPort_tail();

  class  WriteEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    WriteEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    WriteEnPort_itemsContext *writeEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteEnPort_itemsContext* writeEnPort_items();
  WriteEnPort_itemsContext* writeEnPort_items(int precedence);
  class  WriteEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    WriteEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteEnPort_nameContext* writeEnPort_name();

  class  ReadEnPort_defContext : public antlr4::ParserRuleContext {
  public:
    ReadEnPort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READENPORT();
    ReadEnPort_nameContext *readEnPort_name();
    ReadEnPort_tailContext *readEnPort_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadEnPort_defContext* readEnPort_def();

  class  ReadEnPort_tailContext : public antlr4::ParserRuleContext {
  public:
    ReadEnPort_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ReadEnPort_itemsContext *readEnPort_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadEnPort_tailContext* readEnPort_tail();

  class  ReadEnPort_itemsContext : public antlr4::ParserRuleContext {
  public:
    ReadEnPort_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ReadEnPort_itemsContext *readEnPort_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadEnPort_itemsContext* readEnPort_items();
  ReadEnPort_itemsContext* readEnPort_items(int precedence);
  class  ReadEnPort_nameContext : public antlr4::ParserRuleContext {
  public:
    ReadEnPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReadEnPort_nameContext* readEnPort_name();

  class  Instance_defContext : public antlr4::ParserRuleContext {
  public:
    Instance_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSTANCE();
    Instance_nameContext *instance_name();
    antlr4::tree::TerminalNode *OF();
    Instance_moduleContext *instance_module();
    Instance_tailContext *instance_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_defContext* instance_def();

  class  Instance_moduleContext : public antlr4::ParserRuleContext {
  public:
    Instance_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_nameContext *module_name();
    Namespace_nameContext *namespace_name();
    antlr4::tree::TerminalNode *DOUBLE_COLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_moduleContext* instance_module();

  class  Instance_tailContext : public antlr4::ParserRuleContext {
  public:
    Instance_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Instance_itemsContext *instance_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_tailContext* instance_tail();

  class  Instance_itemsContext : public antlr4::ParserRuleContext {
  public:
    Instance_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_itemContext *instance_item();
    Instance_itemsContext *instance_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_itemsContext* instance_items();
  Instance_itemsContext* instance_items(int precedence);
  class  Instance_itemContext : public antlr4::ParserRuleContext {
  public:
    Instance_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InputPort_connectionContext *inputPort_connection();
    AllowBroadcast_defContext *allowBroadcast_def();
    Attribute_defContext *attribute_def();
    Parameter_overrideContext *parameter_override();
    Instance_addressValueContext *instance_addressValue();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_itemContext* instance_item();

  class  InputPort_connectionContext : public antlr4::ParserRuleContext {
  public:
    InputPort_connectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INPUTPORT();
    InputPort_nameContext *inputPort_name();
    antlr4::tree::TerminalNode *EQUAL();
    InputPort_sourceContext *inputPort_source();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputPort_connectionContext* inputPort_connection();

  class  AllowBroadcast_defContext : public antlr4::ParserRuleContext {
  public:
    AllowBroadcast_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALLOWBROADCASTONSCANINTERFACE();
    AllowBroadcast_itemsContext *allowBroadcast_items();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllowBroadcast_defContext* allowBroadcast_def();

  class  AllowBroadcast_itemsContext : public antlr4::ParserRuleContext {
  public:
    AllowBroadcast_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanInterface_nameContext *scanInterface_name();
    AllowBroadcast_itemsContext *allowBroadcast_items();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllowBroadcast_itemsContext* allowBroadcast_items();
  AllowBroadcast_itemsContext* allowBroadcast_items(int precedence);
  class  InputPort_nameContext : public antlr4::ParserRuleContext {
  public:
    InputPort_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_nameContext *port_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputPort_nameContext* inputPort_name();

  class  InputPort_sourceContext : public antlr4::ParserRuleContext {
  public:
    InputPort_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputPort_sourceContext* inputPort_source();

  class  Parameter_overrideContext : public antlr4::ParserRuleContext {
  public:
    Parameter_overrideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_defContext *parameter_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_overrideContext* parameter_override();

  class  Instance_addressValueContext : public antlr4::ParserRuleContext {
  public:
    Instance_addressValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRESSVALUE();
    NumberContext *number();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_addressValueContext* instance_addressValue();

  class  ScanRegister_defContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANREGISTER();
    ScanRegister_nameContext *scanRegister_name();
    ScanRegister_tailContext *scanRegister_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_defContext* scanRegister_def();

  class  ScanRegister_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Register_nameContext *register_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_nameContext* scanRegister_name();

  class  ScanRegister_tailContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanRegister_itemsContext *scanRegister_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_tailContext* scanRegister_tail();

  class  ScanRegister_itemsContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanRegister_itemContext *scanRegister_item();
    ScanRegister_itemsContext *scanRegister_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_itemsContext* scanRegister_items();
  ScanRegister_itemsContext* scanRegister_items(int precedence);
  class  ScanRegister_itemContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ScanRegister_scanInSourceContext *scanRegister_scanInSource();
    ScanRegister_defaultLoadValueContext *scanRegister_defaultLoadValue();
    ScanRegister_captureSourceContext *scanRegister_captureSource();
    ScanRegister_resetValueContext *scanRegister_resetValue();
    ScanRegister_refEnumContext *scanRegister_refEnum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_itemContext* scanRegister_item();

  class  ScanRegister_scanInSourceContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_scanInSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANINSOURCE();
    Scan_signalContext *scan_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_scanInSourceContext* scanRegister_scanInSource();

  class  ScanRegister_defaultLoadValueContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_defaultLoadValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULTLOADVALUE();
    Number_or_enumContext *number_or_enum();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_defaultLoadValueContext* scanRegister_defaultLoadValue();

  class  ScanRegister_captureSourceContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_captureSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAPTURESOURCE();
    Signal_or_enumContext *signal_or_enum();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_captureSourceContext* scanRegister_captureSource();

  class  ScanRegister_resetValueContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_resetValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESETVALUE();
    Number_or_enumContext *number_or_enum();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_resetValueContext* scanRegister_resetValue();

  class  ScanRegister_refEnumContext : public antlr4::ParserRuleContext {
  public:
    ScanRegister_refEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanRegister_refEnumContext* scanRegister_refEnum();

  class  Number_or_enumContext : public antlr4::ParserRuleContext {
  public:
    Number_or_enumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_numberContext *concat_number();
    Enum_symbolContext *enum_symbol();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_or_enumContext* number_or_enum();

  class  Signal_or_enumContext : public antlr4::ParserRuleContext {
  public:
    Signal_or_enumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    antlr4::tree::TerminalNode *SCALAR_ID();
    Pin_idContext *pin_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Signal_or_enumContext* signal_or_enum();

  class  DataRegister_defContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATAREGISTER();
    DataRegister_nameContext *dataRegister_name();
    DataRegister_tailContext *dataRegister_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_defContext* dataRegister_def();

  class  DataRegister_nameContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Register_nameContext *register_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_nameContext* dataRegister_name();

  class  DataRegister_tailContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    DataRegister_itemsContext *dataRegister_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_tailContext* dataRegister_tail();

  class  DataRegister_itemsContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_itemContext *dataRegister_item();
    DataRegister_itemsContext *dataRegister_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_itemsContext* dataRegister_items();
  DataRegister_itemsContext* dataRegister_items(int precedence);
  class  DataRegister_itemContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_typeContext *dataRegister_type();
    DataRegister_commonContext *dataRegister_common();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_itemContext* dataRegister_item();

  class  DataRegister_typeContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_selectableContext *dataRegister_selectable();
    DataRegister_addressableContext *dataRegister_addressable();
    DataRegister_readCallBackContext *dataRegister_readCallBack();
    DataRegister_writeCallBackContext *dataRegister_writeCallBack();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_typeContext* dataRegister_type();

  class  DataRegister_commonContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_commonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_resetValueContext *dataRegister_resetValue();
    DataRegister_defaultLoadValueContext *dataRegister_defaultLoadValue();
    DataRegister_refEnumContext *dataRegister_refEnum();
    Attribute_defContext *attribute_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_commonContext* dataRegister_common();

  class  DataRegister_resetValueContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_resetValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESETVALUE();
    Number_or_enumContext *number_or_enum();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_resetValueContext* dataRegister_resetValue();

  class  DataRegister_defaultLoadValueContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_defaultLoadValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULTLOADVALUE();
    Number_or_enumContext *number_or_enum();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_defaultLoadValueContext* dataRegister_defaultLoadValue();

  class  DataRegister_refEnumContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_refEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_refEnumContext* dataRegister_refEnum();

  class  DataRegister_selectableContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_selectableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_writeEnSourceContext *dataRegister_writeEnSource();
    DataRegister_writeDataSourceContext *dataRegister_writeDataSource();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_selectableContext* dataRegister_selectable();

  class  DataRegister_writeEnSourceContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_writeEnSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITEENSOURCE();
    Data_signalContext *data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_writeEnSourceContext* dataRegister_writeEnSource();

  class  DataRegister_writeDataSourceContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_writeDataSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITEDATASOURCE();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_writeDataSourceContext* dataRegister_writeDataSource();

  class  DataRegister_addressableContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_addressableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_addressValueContext *dataRegister_addressValue();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_addressableContext* dataRegister_addressable();

  class  DataRegister_addressValueContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_addressValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRESSVALUE();
    NumberContext *number();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_addressValueContext* dataRegister_addressValue();

  class  DataRegister_readCallBackContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_readCallBackContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataRegister_readCallBack_procContext *dataRegister_readCallBack_proc();
    DataRegister_readDataSourceContext *dataRegister_readDataSource();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_readCallBackContext* dataRegister_readCallBack();

  class  DataRegister_readCallBack_procContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_readCallBack_procContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READCALLBACK();
    IProc_namespaceContext *iProc_namespace();
    IProc_nameContext *iProc_name();
    IProc_arglistContext *iProc_arglist();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_readCallBack_procContext* dataRegister_readCallBack_proc();

  class  IProc_arglistContext : public antlr4::ParserRuleContext {
  public:
    IProc_arglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IProc_argsContext *iProc_args();
    IProc_arglistContext *iProc_arglist();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IProc_arglistContext* iProc_arglist();
  IProc_arglistContext* iProc_arglist(int precedence);
  class  DataRegister_readDataSourceContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_readDataSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READDATASOURCE();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_readDataSourceContext* dataRegister_readDataSource();

  class  DataRegister_writeCallBackContext : public antlr4::ParserRuleContext {
  public:
    DataRegister_writeCallBackContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITECALLBACK();
    IProc_namespaceContext *iProc_namespace();
    IProc_nameContext *iProc_name();
    IProc_arglistContext *iProc_arglist();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataRegister_writeCallBackContext* dataRegister_writeCallBack();

  class  IProc_namespaceContext : public antlr4::ParserRuleContext {
  public:
    IProc_namespaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Namespace_nameContext *namespace_name();
    std::vector<antlr4::tree::TerminalNode *> DOUBLE_COLON();
    antlr4::tree::TerminalNode* DOUBLE_COLON(size_t i);
    Ref_module_nameContext *ref_module_name();
    Sub_namespaceContext *sub_namespace();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IProc_namespaceContext* iProc_namespace();

  class  IProc_nameContext : public antlr4::ParserRuleContext {
  public:
    IProc_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Parameter_refContext *parameter_ref();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IProc_nameContext* iProc_name();

  class  IProc_argsContext : public antlr4::ParserRuleContext {
  public:
    IProc_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *D_SUBST();
    antlr4::tree::TerminalNode *R_SUBST();
    NumberContext *number();
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IProc_argsContext* iProc_args();

  class  Sub_namespaceContext : public antlr4::ParserRuleContext {
  public:
    Sub_namespaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Parameter_refContext *parameter_ref();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_namespaceContext* sub_namespace();

  class  Ref_module_nameContext : public antlr4::ParserRuleContext {
  public:
    Ref_module_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();
    Parameter_refContext *parameter_ref();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref_module_nameContext* ref_module_name();

  class  LogicSignal_defContext : public antlr4::ParserRuleContext {
  public:
    LogicSignal_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOGICSIGNAL();
    LogicSignal_nameContext *logicSignal_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Logic_exprContext *logic_expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicSignal_defContext* logicSignal_def();

  class  LogicSignal_nameContext : public antlr4::ParserRuleContext {
  public:
    LogicSignal_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicSignal_nameContext* logicSignal_name();

  class  Logic_exprContext : public antlr4::ParserRuleContext {
  public:
    Logic_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_lvl1Context *logic_expr_lvl1();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_exprContext* logic_expr();

  class  Logic_expr_lvl1Context : public antlr4::ParserRuleContext {
  public:
    Logic_expr_lvl1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_lvl2Context *logic_expr_lvl2();
    Logic_and_or_orContext *logic_and_or_or();
    Logic_expr_lvl1Context *logic_expr_lvl1();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_lvl1Context* logic_expr_lvl1();

  class  Logic_and_or_orContext : public antlr4::ParserRuleContext {
  public:
    Logic_and_or_orContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOGIC_AND();
    antlr4::tree::TerminalNode *LOGIC_OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_and_or_orContext* logic_and_or_or();

  class  Logic_expr_lvl2Context : public antlr4::ParserRuleContext {
  public:
    Logic_expr_lvl2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_lvl3Context *logic_expr_lvl3();
    And_or_xorContext *and_or_xor();
    Logic_expr_lvl2Context *logic_expr_lvl2();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_lvl2Context* logic_expr_lvl2();

  class  And_or_xorContext : public antlr4::ParserRuleContext {
  public:
    And_or_xorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *PIPE();
    antlr4::tree::TerminalNode *XOR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  And_or_xorContext* and_or_xor();

  class  Logic_expr_lvl3Context : public antlr4::ParserRuleContext {
  public:
    Logic_expr_lvl3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_lvl4Context *logic_expr_lvl4();
    Eq_or_neqContext *eq_or_neq();
    Logic_expr_num_argContext *logic_expr_num_arg();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_lvl3Context* logic_expr_lvl3();

  class  Eq_or_neqContext : public antlr4::ParserRuleContext {
  public:
    Eq_or_neqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOGIC_EQUAL();
    antlr4::tree::TerminalNode *NOT_EQUAL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Eq_or_neqContext* eq_or_neq();

  class  Logic_expr_lvl4Context : public antlr4::ParserRuleContext {
  public:
    Logic_expr_lvl4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_argContext *logic_expr_arg();
    antlr4::tree::TerminalNode *COMMA();
    Logic_expr_lvl4Context *logic_expr_lvl4();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_lvl4Context* logic_expr_lvl4();

  class  Logic_unary_exprContext : public antlr4::ParserRuleContext {
  public:
    Logic_unary_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Neg_or_notContext *neg_or_not();
    Logic_expr_argContext *logic_expr_arg();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_unary_exprContext* logic_unary_expr();

  class  Logic_expr_argContext : public antlr4::ParserRuleContext {
  public:
    Logic_expr_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expr_parenContext *logic_expr_paren();
    Logic_unary_exprContext *logic_unary_expr();
    SignalContext *signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_argContext* logic_expr_arg();

  class  Neg_or_notContext : public antlr4::ParserRuleContext {
  public:
    Neg_or_notContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *LOGIC_NOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Neg_or_notContext* neg_or_not();

  class  Logic_expr_parenContext : public antlr4::ParserRuleContext {
  public:
    Logic_expr_parenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    Logic_exprContext *logic_expr();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_parenContext* logic_expr_paren();

  class  Logic_expr_num_argContext : public antlr4::ParserRuleContext {
  public:
    Logic_expr_num_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    Logic_expr_num_argContext *logic_expr_num_arg();
    antlr4::tree::TerminalNode *RIGHT_PAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expr_num_argContext* logic_expr_num_arg();

  class  ScanMux_defContext : public antlr4::ParserRuleContext {
  public:
    ScanMux_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANMUX();
    ScanMux_nameContext *scanMux_name();
    antlr4::tree::TerminalNode *SELECTEDBY();
    ScanMux_selectContext *scanMux_select();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanMux_selectionsContext *scanMux_selections();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanMux_defContext* scanMux_def();

  class  ScanMux_selectionsContext : public antlr4::ParserRuleContext {
  public:
    ScanMux_selectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanMux_selectionContext *scanMux_selection();
    ScanMux_selectionsContext *scanMux_selections();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanMux_selectionsContext* scanMux_selections();
  ScanMux_selectionsContext* scanMux_selections(int precedence);
  class  ScanMux_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanMux_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanMux_nameContext* scanMux_name();

  class  ScanMux_selectContext : public antlr4::ParserRuleContext {
  public:
    ScanMux_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanMux_selectContext* scanMux_select();

  class  ScanMux_selectionContext : public antlr4::ParserRuleContext {
  public:
    ScanMux_selectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_number_listContext *concat_number_list();
    antlr4::tree::TerminalNode *COLON();
    Concat_scan_signalContext *concat_scan_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanMux_selectionContext* scanMux_selection();

  class  DataMux_defContext : public antlr4::ParserRuleContext {
  public:
    DataMux_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATAMUX();
    DataMux_nameContext *dataMux_name();
    antlr4::tree::TerminalNode *SELECTEDBY();
    DataMux_selectContext *dataMux_select();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    DataMux_selectionsContext *dataMux_selections();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataMux_defContext* dataMux_def();

  class  DataMux_selectionsContext : public antlr4::ParserRuleContext {
  public:
    DataMux_selectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataMux_selectionContext *dataMux_selection();
    DataMux_selectionsContext *dataMux_selections();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataMux_selectionsContext* dataMux_selections();
  DataMux_selectionsContext* dataMux_selections(int precedence);
  class  DataMux_nameContext : public antlr4::ParserRuleContext {
  public:
    DataMux_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataMux_nameContext* dataMux_name();

  class  DataMux_selectContext : public antlr4::ParserRuleContext {
  public:
    DataMux_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataMux_selectContext* dataMux_select();

  class  DataMux_selectionContext : public antlr4::ParserRuleContext {
  public:
    DataMux_selectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_number_listContext *concat_number_list();
    antlr4::tree::TerminalNode *COLON();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataMux_selectionContext* dataMux_selection();

  class  ClockMux_defContext : public antlr4::ParserRuleContext {
  public:
    ClockMux_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLOCKMUX();
    ClockMux_nameContext *clockMux_name();
    antlr4::tree::TerminalNode *SELECTEDBY();
    ClockMux_selectContext *clockMux_select();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ClockMux_selectionsContext *clockMux_selections();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockMux_defContext* clockMux_def();

  class  ClockMux_selectionsContext : public antlr4::ParserRuleContext {
  public:
    ClockMux_selectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClockMux_selectionContext *clockMux_selection();
    ClockMux_selectionsContext *clockMux_selections();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockMux_selectionsContext* clockMux_selections();
  ClockMux_selectionsContext* clockMux_selections(int precedence);
  class  ClockMux_nameContext : public antlr4::ParserRuleContext {
  public:
    ClockMux_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockMux_nameContext* clockMux_name();

  class  ClockMux_selectContext : public antlr4::ParserRuleContext {
  public:
    ClockMux_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_data_signalContext *concat_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockMux_selectContext* clockMux_select();

  class  ClockMux_selectionContext : public antlr4::ParserRuleContext {
  public:
    ClockMux_selectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_number_listContext *concat_number_list();
    antlr4::tree::TerminalNode *COLON();
    Concat_clock_signalContext *concat_clock_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockMux_selectionContext* clockMux_selection();

  class  OneHotScanGroup_defContext : public antlr4::ParserRuleContext {
  public:
    OneHotScanGroup_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ONEHOTSCANGROUP();
    OneHotScanGroup_nameContext *oneHotScanGroup_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    OneHotScanGroup_itemsContext *oneHotScanGroup_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotScanGroup_defContext* oneHotScanGroup_def();

  class  OneHotScanGroup_itemsContext : public antlr4::ParserRuleContext {
  public:
    OneHotScanGroup_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OneHotScanGroup_itemContext *oneHotScanGroup_item();
    OneHotScanGroup_itemsContext *oneHotScanGroup_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotScanGroup_itemsContext* oneHotScanGroup_items();
  OneHotScanGroup_itemsContext* oneHotScanGroup_items(int precedence);
  class  OneHotScanGroup_nameContext : public antlr4::ParserRuleContext {
  public:
    OneHotScanGroup_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotScanGroup_nameContext* oneHotScanGroup_name();

  class  OneHotScanGroup_itemContext : public antlr4::ParserRuleContext {
  public:
    OneHotScanGroup_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PORT();
    Concat_scan_signalContext *concat_scan_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotScanGroup_itemContext* oneHotScanGroup_item();

  class  OneHotDataGroup_defContext : public antlr4::ParserRuleContext {
  public:
    OneHotDataGroup_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ONEHOTDATAGROUP();
    OneHotDataGroup_nameContext *oneHotDataGroup_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    OneHotDataGroup_itemsContext *oneHotDataGroup_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotDataGroup_defContext* oneHotDataGroup_def();

  class  OneHotDataGroup_itemsContext : public antlr4::ParserRuleContext {
  public:
    OneHotDataGroup_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OneHotDataGroup_itemContext *oneHotDataGroup_item();
    OneHotDataGroup_itemsContext *oneHotDataGroup_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotDataGroup_itemsContext* oneHotDataGroup_items();
  OneHotDataGroup_itemsContext* oneHotDataGroup_items(int precedence);
  class  OneHotDataGroup_nameContext : public antlr4::ParserRuleContext {
  public:
    OneHotDataGroup_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotDataGroup_nameContext* oneHotDataGroup_name();

  class  OneHotDataGroup_itemContext : public antlr4::ParserRuleContext {
  public:
    OneHotDataGroup_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_defContext *instance_def();
    DataRegister_defContext *dataRegister_def();
    OneHotDataGroup_portSourceContext *oneHotDataGroup_portSource();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotDataGroup_itemContext* oneHotDataGroup_item();

  class  OneHotDataGroup_portSourceContext : public antlr4::ParserRuleContext {
  public:
    OneHotDataGroup_portSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PORT();
    Concat_data_signalContext *concat_data_signal();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneHotDataGroup_portSourceContext* oneHotDataGroup_portSource();

  class  AccessLink_defContext : public antlr4::ParserRuleContext {
  public:
    AccessLink_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AccessLink1149_defContext *accessLink1149_def();
    AccessLinkGeneric_defContext *accessLinkGeneric_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink_defContext* accessLink_def();

  class  AccessLinkGeneric_defContext : public antlr4::ParserRuleContext {
  public:
    AccessLinkGeneric_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESSLINK();
    AccessLink_nameContext *accessLink_name();
    antlr4::tree::TerminalNode *OF();
    AccessLink_genericIDContext *accessLink_genericID();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLinkGeneric_defContext* accessLinkGeneric_def();

  class  AccessLink_genericIDContext : public antlr4::ParserRuleContext {
  public:
    AccessLink_genericIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink_genericIDContext* accessLink_genericID();

  class  AccessLink1149_defContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESSLINK();
    AccessLink_nameContext *accessLink_name();
    antlr4::tree::TerminalNode *OF();
    AccessLink1149_stdsContext *accessLink1149_stds();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *BSDLENTITIY();
    BsdlEntity_nameContext *bsdlEntity_name();
    antlr4::tree::TerminalNode *SEMICOLON();
    Bsdl_instr_refsContext *bsdl_instr_refs();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_defContext* accessLink1149_def();

  class  AccessLink1149_stdsContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_stdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STD_1149_1_2001();
    antlr4::tree::TerminalNode *STD_1149_1_2013();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_stdsContext* accessLink1149_stds();

  class  AccessLink_nameContext : public antlr4::ParserRuleContext {
  public:
    AccessLink_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink_nameContext* accessLink_name();

  class  BsdlEntity_nameContext : public antlr4::ParserRuleContext {
  public:
    BsdlEntity_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BsdlEntity_nameContext* bsdlEntity_name();

  class  Bsdl_instr_refsContext : public antlr4::ParserRuleContext {
  public:
    Bsdl_instr_refsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bsdl_instr_refContext *bsdl_instr_ref();
    Bsdl_instr_refsContext *bsdl_instr_refs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bsdl_instr_refsContext* bsdl_instr_refs();
  Bsdl_instr_refsContext* bsdl_instr_refs(int precedence);
  class  Bsdl_instr_refContext : public antlr4::ParserRuleContext {
  public:
    Bsdl_instr_refContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bsdl_instr_nameContext *bsdl_instr_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Bsdl_instr_selected_itemsContext *bsdl_instr_selected_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bsdl_instr_refContext* bsdl_instr_ref();

  class  Bsdl_instr_selected_itemsContext : public antlr4::ParserRuleContext {
  public:
    Bsdl_instr_selected_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bsdl_instr_selected_itemContext *bsdl_instr_selected_item();
    Bsdl_instr_selected_itemsContext *bsdl_instr_selected_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bsdl_instr_selected_itemsContext* bsdl_instr_selected_items();
  Bsdl_instr_selected_itemsContext* bsdl_instr_selected_items(int precedence);
  class  Bsdl_instr_nameContext : public antlr4::ParserRuleContext {
  public:
    Bsdl_instr_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bsdl_instr_nameContext* bsdl_instr_name();

  class  Bsdl_instr_selected_itemContext : public antlr4::ParserRuleContext {
  public:
    Bsdl_instr_selected_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANINTERFACE();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    AccessLink1149_ScanInterface_namesContext *accessLink1149_ScanInterface_names();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    antlr4::tree::TerminalNode *ACTIVESIGNALS();
    AccessLink1149_ActiveSignal_namesContext *accessLink1149_ActiveSignal_names();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bsdl_instr_selected_itemContext* bsdl_instr_selected_item();

  class  AccessLink1149_ScanInterface_namesContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_ScanInterface_namesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AccessLink1149_ScanInterface_nameContext *accessLink1149_ScanInterface_name();
    antlr4::tree::TerminalNode *SEMICOLON();
    AccessLink1149_ScanInterface_namesContext *accessLink1149_ScanInterface_names();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_ScanInterface_namesContext* accessLink1149_ScanInterface_names();
  AccessLink1149_ScanInterface_namesContext* accessLink1149_ScanInterface_names(int precedence);
  class  AccessLink1149_ActiveSignal_nameContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_ActiveSignal_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_ActiveSignal_nameContext* accessLink1149_ActiveSignal_name();

  class  AccessLink1149_ActiveSignal_namesContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_ActiveSignal_namesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AccessLink1149_ActiveSignal_nameContext *accessLink1149_ActiveSignal_name();
    antlr4::tree::TerminalNode *SEMICOLON();
    AccessLink1149_ActiveSignal_namesContext *accessLink1149_ActiveSignal_names();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_ActiveSignal_namesContext* accessLink1149_ActiveSignal_names();
  AccessLink1149_ActiveSignal_namesContext* accessLink1149_ActiveSignal_names(int precedence);
  class  AccessLink1149_ScanInterface_nameContext : public antlr4::ParserRuleContext {
  public:
    AccessLink1149_ScanInterface_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_nameContext *instance_name();
    antlr4::tree::TerminalNode *DOT();
    ScanInterface_nameContext *scanInterface_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AccessLink1149_ScanInterface_nameContext* accessLink1149_ScanInterface_name();

  class  ScanInterface_defContext : public antlr4::ParserRuleContext {
  public:
    ScanInterface_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCANINTERFACE();
    ScanInterface_nameContext *scanInterface_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanInterface_itemsContext *scanInterface_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterface_defContext* scanInterface_def();

  class  ScanInterface_itemsContext : public antlr4::ParserRuleContext {
  public:
    ScanInterface_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanInterface_itemContext *scanInterface_item();
    ScanInterface_itemsContext *scanInterface_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterface_itemsContext* scanInterface_items();
  ScanInterface_itemsContext* scanInterface_items(int precedence);
  class  ScanInterface_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanInterface_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterface_nameContext* scanInterface_name();

  class  ScanInterface_itemContext : public antlr4::ParserRuleContext {
  public:
    ScanInterface_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ScanInterfacePort_defContext *scanInterfacePort_def();
    DefaultLoad_defContext *defaultLoad_def();
    ScanInterfaceChain_defContext *scanInterfaceChain_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterface_itemContext* scanInterface_item();

  class  ScanInterfacePort_defContext : public antlr4::ParserRuleContext {
  public:
    ScanInterfacePort_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PORT();
    Reg_port_signal_idContext *reg_port_signal_id();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterfacePort_defContext* scanInterfacePort_def();

  class  ScanInterfaceChain_defContext : public antlr4::ParserRuleContext {
  public:
    ScanInterfaceChain_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAIN();
    ScanInterfaceChain_nameContext *scanInterfaceChain_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ScanInterfaceChain_itemsContext *scanInterfaceChain_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterfaceChain_defContext* scanInterfaceChain_def();

  class  ScanInterfaceChain_itemsContext : public antlr4::ParserRuleContext {
  public:
    ScanInterfaceChain_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScanInterfaceChain_itemContext *scanInterfaceChain_item();
    ScanInterfaceChain_itemsContext *scanInterfaceChain_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterfaceChain_itemsContext* scanInterfaceChain_items();
  ScanInterfaceChain_itemsContext* scanInterfaceChain_items(int precedence);
  class  ScanInterfaceChain_nameContext : public antlr4::ParserRuleContext {
  public:
    ScanInterfaceChain_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterfaceChain_nameContext* scanInterfaceChain_name();

  class  ScanInterfaceChain_itemContext : public antlr4::ParserRuleContext {
  public:
    ScanInterfaceChain_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    ScanInterfacePort_defContext *scanInterfacePort_def();
    DefaultLoad_defContext *defaultLoad_def();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScanInterfaceChain_itemContext* scanInterfaceChain_item();

  class  DefaultLoad_defContext : public antlr4::ParserRuleContext {
  public:
    DefaultLoad_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULTLOADVALUE();
    Concat_numberContext *concat_number();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultLoad_defContext* defaultLoad_def();

  class  Alias_defContext : public antlr4::ParserRuleContext {
  public:
    Alias_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIAS();
    Alias_nameContext *alias_name();
    antlr4::tree::TerminalNode *EQUAL();
    Concat_hier_data_signalContext *concat_hier_data_signal();
    Alias_tailContext *alias_tail();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_defContext* alias_def();

  class  Alias_nameContext : public antlr4::ParserRuleContext {
  public:
    Alias_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_nameContext* alias_name();

  class  Alias_tailContext : public antlr4::ParserRuleContext {
  public:
    Alias_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Alias_itemsContext *alias_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_tailContext* alias_tail();

  class  Alias_itemsContext : public antlr4::ParserRuleContext {
  public:
    Alias_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Alias_itemContext *alias_item();
    Alias_itemsContext *alias_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_itemsContext* alias_items();
  Alias_itemsContext* alias_items(int precedence);
  class  Alias_itemContext : public antlr4::ParserRuleContext {
  public:
    Alias_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_defContext *attribute_def();
    antlr4::tree::TerminalNode *ACCESSTOGETHER();
    antlr4::tree::TerminalNode *SEMICOLON();
    Alias_iApplyEndStateContext *alias_iApplyEndState();
    Alias_refEnumContext *alias_refEnum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_itemContext* alias_item();

  class  Alias_iApplyEndStateContext : public antlr4::ParserRuleContext {
  public:
    Alias_iApplyEndStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IAPPLYENDSTATE();
    Concat_numberContext *concat_number();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_iApplyEndStateContext* alias_iApplyEndState();

  class  Alias_refEnumContext : public antlr4::ParserRuleContext {
  public:
    Alias_refEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alias_refEnumContext* alias_refEnum();

  class  Concat_hier_data_signalContext : public antlr4::ParserRuleContext {
  public:
    Concat_hier_data_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    X_hier_data_signalContext *x_hier_data_signal();
    Concat_hier_data_signalContext *concat_hier_data_signal();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_hier_data_signalContext* concat_hier_data_signal();
  Concat_hier_data_signalContext* concat_hier_data_signal(int precedence);
  class  X_hier_data_signalContext : public antlr4::ParserRuleContext {
  public:
    X_hier_data_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE();
    Hier_data_signalContext *hier_data_signal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  X_hier_data_signalContext* x_hier_data_signal();

  class  Hier_data_signalContext : public antlr4::ParserRuleContext {
  public:
    Hier_data_signalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hier_data_signal_instancesContext *hier_data_signal_instances();
    Reg_port_signal_idContext *reg_port_signal_id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hier_data_signalContext* hier_data_signal();

  class  Hier_data_signal_instancesContext : public antlr4::ParserRuleContext {
  public:
    Hier_data_signal_instancesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_nameContext *instance_name();
    antlr4::tree::TerminalNode *DOT();
    Hier_data_signal_instancesContext *hier_data_signal_instances();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hier_data_signal_instancesContext* hier_data_signal_instances();
  Hier_data_signal_instancesContext* hier_data_signal_instances(int precedence);
  class  Enum_defContext : public antlr4::ParserRuleContext {
  public:
    Enum_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    Enum_nameContext *enum_name();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    Enum_itemsContext *enum_items();
    antlr4::tree::TerminalNode *RIGHT_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_defContext* enum_def();

  class  Enum_itemsContext : public antlr4::ParserRuleContext {
  public:
    Enum_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Enum_itemContext *enum_item();
    Enum_itemsContext *enum_items();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_itemsContext* enum_items();
  Enum_itemsContext* enum_items(int precedence);
  class  Enum_nameContext : public antlr4::ParserRuleContext {
  public:
    Enum_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_nameContext* enum_name();

  class  Enum_itemContext : public antlr4::ParserRuleContext {
  public:
    Enum_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Enum_symbolContext *enum_symbol();
    antlr4::tree::TerminalNode *EQUAL();
    Enum_valueContext *enum_value();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_itemContext* enum_item();

  class  Enum_symbolContext : public antlr4::ParserRuleContext {
  public:
    Enum_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_symbolContext* enum_symbol();

  class  Enum_valueContext : public antlr4::ParserRuleContext {
  public:
    Enum_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_numberContext *concat_number();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_valueContext* enum_value();

  class  Parameter_defContext : public antlr4::ParserRuleContext {
  public:
    Parameter_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETER();
    Parameter_nameContext *parameter_name();
    antlr4::tree::TerminalNode *EQUAL();
    Parameter_valueContext *parameter_value();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_defContext* parameter_def();

  class  LocalParameter_defContext : public antlr4::ParserRuleContext {
  public:
    LocalParameter_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCALPARAMETER();
    Parameter_nameContext *parameter_name();
    antlr4::tree::TerminalNode *EQUAL();
    Parameter_valueContext *parameter_value();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalParameter_defContext* localParameter_def();

  class  Parameter_nameContext : public antlr4::ParserRuleContext {
  public:
    Parameter_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_nameContext* parameter_name();

  class  Parameter_valueContext : public antlr4::ParserRuleContext {
  public:
    Parameter_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_stringContext *concat_string();
    Concat_numberContext *concat_number();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_valueContext* parameter_value();

  class  Concat_stringContext : public antlr4::ParserRuleContext {
  public:
    Concat_stringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    String_or_parmContext *string_or_parm();
    Concat_stringContext *concat_string();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concat_stringContext* concat_string();
  Concat_stringContext* concat_string(int precedence);
  class  String_or_parmContext : public antlr4::ParserRuleContext {
  public:
    String_or_parmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    Parameter_refContext *parameter_ref();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  String_or_parmContext* string_or_parm();

  class  Attribute_defContext : public antlr4::ParserRuleContext {
  public:
    Attribute_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTRIBUTE();
    Attribute_nameContext *attribute_name();
    antlr4::tree::TerminalNode *EQUAL();
    Attribute_valueContext *attribute_value();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attribute_defContext* attribute_def();

  class  Attribute_nameContext : public antlr4::ParserRuleContext {
  public:
    Attribute_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALAR_ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attribute_nameContext* attribute_name();

  class  Attribute_valueContext : public antlr4::ParserRuleContext {
  public:
    Attribute_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concat_stringContext *concat_string();
    Concat_numberContext *concat_number();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attribute_valueContext* attribute_value();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool concat_numberSempred(Concat_numberContext *_localctx, size_t predicateIndex);
  bool concat_number_listSempred(Concat_number_listContext *_localctx, size_t predicateIndex);
  bool concat_reset_signalSempred(Concat_reset_signalContext *_localctx, size_t predicateIndex);
  bool concat_data_signalSempred(Concat_data_signalContext *_localctx, size_t predicateIndex);
  bool concat_scan_signalSempred(Concat_scan_signalContext *_localctx, size_t predicateIndex);
  bool concat_clock_signalSempred(Concat_clock_signalContext *_localctx, size_t predicateIndex);
  bool concat_shiftEn_signalSempred(Concat_shiftEn_signalContext *_localctx, size_t predicateIndex);
  bool concat_tms_signalSempred(Concat_tms_signalContext *_localctx, size_t predicateIndex);
  bool concat_trst_signalSempred(Concat_trst_signalContext *_localctx, size_t predicateIndex);
  bool module_itemsSempred(Module_itemsContext *_localctx, size_t predicateIndex);
  bool scanInPort_itemsSempred(ScanInPort_itemsContext *_localctx, size_t predicateIndex);
  bool scanOutPort_itemsSempred(ScanOutPort_itemsContext *_localctx, size_t predicateIndex);
  bool shiftEnPort_itemsSempred(ShiftEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool captureEnPort_itemsSempred(CaptureEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool updateEnPort_itemsSempred(UpdateEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool dataInPort_itemsSempred(DataInPort_itemsContext *_localctx, size_t predicateIndex);
  bool dataOutPort_itemsSempred(DataOutPort_itemsContext *_localctx, size_t predicateIndex);
  bool toShiftEnPort_itemsSempred(ToShiftEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool toCaptureEnPort_itemsSempred(ToCaptureEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool toUpdateEnPort_itemsSempred(ToUpdateEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool selectPort_itemsSempred(SelectPort_itemsContext *_localctx, size_t predicateIndex);
  bool toSelectPort_itemsSempred(ToSelectPort_itemsContext *_localctx, size_t predicateIndex);
  bool resetPort_itemsSempred(ResetPort_itemsContext *_localctx, size_t predicateIndex);
  bool toResetPort_itemsSempred(ToResetPort_itemsContext *_localctx, size_t predicateIndex);
  bool tmsPort_itemsSempred(TmsPort_itemsContext *_localctx, size_t predicateIndex);
  bool toTmsPort_itemsSempred(ToTmsPort_itemsContext *_localctx, size_t predicateIndex);
  bool toIRSelectPort_itemsSempred(ToIRSelectPort_itemsContext *_localctx, size_t predicateIndex);
  bool tckPort_itemsSempred(TckPort_itemsContext *_localctx, size_t predicateIndex);
  bool toTckPort_itemsSempred(ToTckPort_itemsContext *_localctx, size_t predicateIndex);
  bool clockPort_itemsSempred(ClockPort_itemsContext *_localctx, size_t predicateIndex);
  bool toClockPort_itemsSempred(ToClockPort_itemsContext *_localctx, size_t predicateIndex);
  bool trstPort_itemsSempred(TrstPort_itemsContext *_localctx, size_t predicateIndex);
  bool toTrstPort_itemsSempred(ToTrstPort_itemsContext *_localctx, size_t predicateIndex);
  bool addressPort_itemsSempred(AddressPort_itemsContext *_localctx, size_t predicateIndex);
  bool writeEnPort_itemsSempred(WriteEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool readEnPort_itemsSempred(ReadEnPort_itemsContext *_localctx, size_t predicateIndex);
  bool instance_itemsSempred(Instance_itemsContext *_localctx, size_t predicateIndex);
  bool allowBroadcast_itemsSempred(AllowBroadcast_itemsContext *_localctx, size_t predicateIndex);
  bool scanRegister_itemsSempred(ScanRegister_itemsContext *_localctx, size_t predicateIndex);
  bool dataRegister_itemsSempred(DataRegister_itemsContext *_localctx, size_t predicateIndex);
  bool iProc_arglistSempred(IProc_arglistContext *_localctx, size_t predicateIndex);
  bool scanMux_selectionsSempred(ScanMux_selectionsContext *_localctx, size_t predicateIndex);
  bool dataMux_selectionsSempred(DataMux_selectionsContext *_localctx, size_t predicateIndex);
  bool clockMux_selectionsSempred(ClockMux_selectionsContext *_localctx, size_t predicateIndex);
  bool oneHotScanGroup_itemsSempred(OneHotScanGroup_itemsContext *_localctx, size_t predicateIndex);
  bool oneHotDataGroup_itemsSempred(OneHotDataGroup_itemsContext *_localctx, size_t predicateIndex);
  bool bsdl_instr_refsSempred(Bsdl_instr_refsContext *_localctx, size_t predicateIndex);
  bool bsdl_instr_selected_itemsSempred(Bsdl_instr_selected_itemsContext *_localctx, size_t predicateIndex);
  bool accessLink1149_ScanInterface_namesSempred(AccessLink1149_ScanInterface_namesContext *_localctx, size_t predicateIndex);
  bool accessLink1149_ActiveSignal_namesSempred(AccessLink1149_ActiveSignal_namesContext *_localctx, size_t predicateIndex);
  bool scanInterface_itemsSempred(ScanInterface_itemsContext *_localctx, size_t predicateIndex);
  bool scanInterfaceChain_itemsSempred(ScanInterfaceChain_itemsContext *_localctx, size_t predicateIndex);
  bool alias_itemsSempred(Alias_itemsContext *_localctx, size_t predicateIndex);
  bool concat_hier_data_signalSempred(Concat_hier_data_signalContext *_localctx, size_t predicateIndex);
  bool hier_data_signal_instancesSempred(Hier_data_signal_instancesContext *_localctx, size_t predicateIndex);
  bool enum_itemsSempred(Enum_itemsContext *_localctx, size_t predicateIndex);
  bool concat_stringSempred(Concat_stringContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

