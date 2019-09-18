
// Generated from icl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "iclParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by iclParser.
 */
class  iclVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by iclParser.
   */
    virtual antlrcpp::Any visitPos_int(iclParser::Pos_intContext *context) = 0;

    virtual antlrcpp::Any visitVector_id(iclParser::Vector_idContext *context) = 0;

    virtual antlrcpp::Any visitIndex_or_range(iclParser::Index_or_rangeContext *context) = 0;

    virtual antlrcpp::Any visitIndex(iclParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitRange(iclParser::RangeContext *context) = 0;

    virtual antlrcpp::Any visitNumber(iclParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitInteger_expr(iclParser::Integer_exprContext *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_lvl1(iclParser::Integer_expr_lvl1Context *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_lvl1_b(iclParser::Integer_expr_lvl1_bContext *context) = 0;

    virtual antlrcpp::Any visitPlus_or_minus(iclParser::Plus_or_minusContext *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_lvl2(iclParser::Integer_expr_lvl2Context *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_lvl2_b(iclParser::Integer_expr_lvl2_bContext *context) = 0;

    virtual antlrcpp::Any visitStar_or_slash_or_percent(iclParser::Star_or_slash_or_percentContext *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_paren(iclParser::Integer_expr_parenContext *context) = 0;

    virtual antlrcpp::Any visitInteger_expr_arg(iclParser::Integer_expr_argContext *context) = 0;

    virtual antlrcpp::Any visitParameter_ref(iclParser::Parameter_refContext *context) = 0;

    virtual antlrcpp::Any visitConcat_number(iclParser::Concat_numberContext *context) = 0;

    virtual antlrcpp::Any visitConcat_number_list(iclParser::Concat_number_listContext *context) = 0;

    virtual antlrcpp::Any visitPin_id(iclParser::Pin_idContext *context) = 0;

    virtual antlrcpp::Any visitPort_name(iclParser::Port_nameContext *context) = 0;

    virtual antlrcpp::Any visitRegister_name(iclParser::Register_nameContext *context) = 0;

    virtual antlrcpp::Any visitInstance_name(iclParser::Instance_nameContext *context) = 0;

    virtual antlrcpp::Any visitNamespace_name(iclParser::Namespace_nameContext *context) = 0;

    virtual antlrcpp::Any visitModule_name(iclParser::Module_nameContext *context) = 0;

    virtual antlrcpp::Any visitReg_port_signal_id(iclParser::Reg_port_signal_idContext *context) = 0;

    virtual antlrcpp::Any visitSignal(iclParser::SignalContext *context) = 0;

    virtual antlrcpp::Any visitX_signal(iclParser::X_signalContext *context) = 0;

    virtual antlrcpp::Any visitData_signal(iclParser::Data_signalContext *context) = 0;

    virtual antlrcpp::Any visitScan_signal(iclParser::Scan_signalContext *context) = 0;

    virtual antlrcpp::Any visitCaptureEn_signal(iclParser::CaptureEn_signalContext *context) = 0;

    virtual antlrcpp::Any visitUpdateEn_signal(iclParser::UpdateEn_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_reset_signal(iclParser::Concat_reset_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_data_signal(iclParser::Concat_data_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_scan_signal(iclParser::Concat_scan_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_clock_signal(iclParser::Concat_clock_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_shiftEn_signal(iclParser::Concat_shiftEn_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_tms_signal(iclParser::Concat_tms_signalContext *context) = 0;

    virtual antlrcpp::Any visitConcat_trst_signal(iclParser::Concat_trst_signalContext *context) = 0;

    virtual antlrcpp::Any visitIcl_source(iclParser::Icl_sourceContext *context) = 0;

    virtual antlrcpp::Any visitIclSource_items(iclParser::IclSource_itemsContext *context) = 0;

    virtual antlrcpp::Any visitNameSpace_def(iclParser::NameSpace_defContext *context) = 0;

    virtual antlrcpp::Any visitUseNameSpace_def(iclParser::UseNameSpace_defContext *context) = 0;

    virtual antlrcpp::Any visitModule_def(iclParser::Module_defContext *context) = 0;

    virtual antlrcpp::Any visitModule_items(iclParser::Module_itemsContext *context) = 0;

    virtual antlrcpp::Any visitModule_item(iclParser::Module_itemContext *context) = 0;

    virtual antlrcpp::Any visitPort_def(iclParser::Port_defContext *context) = 0;

    virtual antlrcpp::Any visitScanInPort_def(iclParser::ScanInPort_defContext *context) = 0;

    virtual antlrcpp::Any visitScanInPort_tail(iclParser::ScanInPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitScanInPort_items(iclParser::ScanInPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitScanInPort_name(iclParser::ScanInPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_def(iclParser::ScanOutPort_defContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_tail(iclParser::ScanOutPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_items(iclParser::ScanOutPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_name(iclParser::ScanOutPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_item(iclParser::ScanOutPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_source(iclParser::ScanOutPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_enable(iclParser::ScanOutPort_enableContext *context) = 0;

    virtual antlrcpp::Any visitScanOutPort_launchEdge(iclParser::ScanOutPort_launchEdgeContext *context) = 0;

    virtual antlrcpp::Any visitRising_or_falling(iclParser::Rising_or_fallingContext *context) = 0;

    virtual antlrcpp::Any visitShiftEnPort_def(iclParser::ShiftEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitShiftEnPort_tail(iclParser::ShiftEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitShiftEnPort_items(iclParser::ShiftEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitShiftEnPort_name(iclParser::ShiftEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitCaptureEnPort_def(iclParser::CaptureEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitCaptureEnPort_tail(iclParser::CaptureEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitCaptureEnPort_items(iclParser::CaptureEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitCaptureEnPort_name(iclParser::CaptureEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitUpdateEnPort_def(iclParser::UpdateEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitUpdateEnPort_tail(iclParser::UpdateEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitUpdateEnPort_items(iclParser::UpdateEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitUpdateEnPort_name(iclParser::UpdateEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_def(iclParser::DataInPort_defContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_tail(iclParser::DataInPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_items(iclParser::DataInPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_name(iclParser::DataInPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_item(iclParser::DataInPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitDataInPort_refEnum(iclParser::DataInPort_refEnumContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_def(iclParser::DataOutPort_defContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_tail(iclParser::DataOutPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_items(iclParser::DataOutPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_name(iclParser::DataOutPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_item(iclParser::DataOutPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_source(iclParser::DataOutPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_enable(iclParser::DataOutPort_enableContext *context) = 0;

    virtual antlrcpp::Any visitDataOutPort_refEnum(iclParser::DataOutPort_refEnumContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_def(iclParser::ToShiftEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_tail(iclParser::ToShiftEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_items(iclParser::ToShiftEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_name(iclParser::ToShiftEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_item(iclParser::ToShiftEnPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToShiftEnPort_source(iclParser::ToShiftEnPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_def(iclParser::ToCaptureEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_tail(iclParser::ToCaptureEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_items(iclParser::ToCaptureEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_name(iclParser::ToCaptureEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_item(iclParser::ToCaptureEnPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToCaptureEnPort_source(iclParser::ToCaptureEnPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_def(iclParser::ToUpdateEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_tail(iclParser::ToUpdateEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_items(iclParser::ToUpdateEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_name(iclParser::ToUpdateEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_item(iclParser::ToUpdateEnPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToUpdateEnPort_source(iclParser::ToUpdateEnPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitSelectPort_def(iclParser::SelectPort_defContext *context) = 0;

    virtual antlrcpp::Any visitSelectPort_tail(iclParser::SelectPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitSelectPort_items(iclParser::SelectPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitSelectPort_name(iclParser::SelectPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_def(iclParser::ToSelectPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_name(iclParser::ToSelectPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_tail(iclParser::ToSelectPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_items(iclParser::ToSelectPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_item(iclParser::ToSelectPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToSelectPort_source(iclParser::ToSelectPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_def(iclParser::ResetPort_defContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_name(iclParser::ResetPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_tail(iclParser::ResetPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_items(iclParser::ResetPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_item(iclParser::ResetPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitResetPort_polarity(iclParser::ResetPort_polarityContext *context) = 0;

    virtual antlrcpp::Any visitZero_or_one(iclParser::Zero_or_oneContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_def(iclParser::ToResetPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_name(iclParser::ToResetPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_tail(iclParser::ToResetPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_items(iclParser::ToResetPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_item(iclParser::ToResetPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_source(iclParser::ToResetPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitToResetPort_polarity(iclParser::ToResetPort_polarityContext *context) = 0;

    virtual antlrcpp::Any visitTmsPort_def(iclParser::TmsPort_defContext *context) = 0;

    virtual antlrcpp::Any visitTmsPort_tail(iclParser::TmsPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitTmsPort_items(iclParser::TmsPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitTmsPort_name(iclParser::TmsPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_def(iclParser::ToTmsPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_name(iclParser::ToTmsPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_tail(iclParser::ToTmsPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_items(iclParser::ToTmsPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_item(iclParser::ToTmsPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToTmsPort_source(iclParser::ToTmsPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitToIRSelectPort_def(iclParser::ToIRSelectPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToIRSelectPort_tail(iclParser::ToIRSelectPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToIRSelectPort_items(iclParser::ToIRSelectPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToIRSelectPort_name(iclParser::ToIRSelectPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitTckPort_def(iclParser::TckPort_defContext *context) = 0;

    virtual antlrcpp::Any visitTckPort_tail(iclParser::TckPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitTckPort_items(iclParser::TckPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitTckPort_name(iclParser::TckPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToTckPort_def(iclParser::ToTckPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToTckPort_tail(iclParser::ToTckPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToTckPort_items(iclParser::ToTckPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToTckPort_name(iclParser::ToTckPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_def(iclParser::ClockPort_defContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_name(iclParser::ClockPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_tail(iclParser::ClockPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_items(iclParser::ClockPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_item(iclParser::ClockPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitClockPort_diffPort(iclParser::ClockPort_diffPortContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_def(iclParser::ToClockPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_name(iclParser::ToClockPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_tail(iclParser::ToClockPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_items(iclParser::ToClockPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_item(iclParser::ToClockPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToClockPort_source(iclParser::ToClockPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitFreqMultiplier_def(iclParser::FreqMultiplier_defContext *context) = 0;

    virtual antlrcpp::Any visitFreqDivider_def(iclParser::FreqDivider_defContext *context) = 0;

    virtual antlrcpp::Any visitDifferentialInvOf_def(iclParser::DifferentialInvOf_defContext *context) = 0;

    virtual antlrcpp::Any visitPeriod_def(iclParser::Period_defContext *context) = 0;

    virtual antlrcpp::Any visitTunit(iclParser::TunitContext *context) = 0;

    virtual antlrcpp::Any visitTrstPort_def(iclParser::TrstPort_defContext *context) = 0;

    virtual antlrcpp::Any visitTrstPort_tail(iclParser::TrstPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitTrstPort_items(iclParser::TrstPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitTrstPort_name(iclParser::TrstPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_def(iclParser::ToTrstPort_defContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_name(iclParser::ToTrstPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_tail(iclParser::ToTrstPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_items(iclParser::ToTrstPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_item(iclParser::ToTrstPort_itemContext *context) = 0;

    virtual antlrcpp::Any visitToTrstPort_source(iclParser::ToTrstPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitAddressPort_def(iclParser::AddressPort_defContext *context) = 0;

    virtual antlrcpp::Any visitAddressPort_tail(iclParser::AddressPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitAddressPort_items(iclParser::AddressPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitAddressPort_name(iclParser::AddressPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitWriteEnPort_def(iclParser::WriteEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitWriteEnPort_tail(iclParser::WriteEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitWriteEnPort_items(iclParser::WriteEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitWriteEnPort_name(iclParser::WriteEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitReadEnPort_def(iclParser::ReadEnPort_defContext *context) = 0;

    virtual antlrcpp::Any visitReadEnPort_tail(iclParser::ReadEnPort_tailContext *context) = 0;

    virtual antlrcpp::Any visitReadEnPort_items(iclParser::ReadEnPort_itemsContext *context) = 0;

    virtual antlrcpp::Any visitReadEnPort_name(iclParser::ReadEnPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitInstance_def(iclParser::Instance_defContext *context) = 0;

    virtual antlrcpp::Any visitInstance_module(iclParser::Instance_moduleContext *context) = 0;

    virtual antlrcpp::Any visitInstance_tail(iclParser::Instance_tailContext *context) = 0;

    virtual antlrcpp::Any visitInstance_items(iclParser::Instance_itemsContext *context) = 0;

    virtual antlrcpp::Any visitInstance_item(iclParser::Instance_itemContext *context) = 0;

    virtual antlrcpp::Any visitInputPort_connection(iclParser::InputPort_connectionContext *context) = 0;

    virtual antlrcpp::Any visitAllowBroadcast_def(iclParser::AllowBroadcast_defContext *context) = 0;

    virtual antlrcpp::Any visitAllowBroadcast_items(iclParser::AllowBroadcast_itemsContext *context) = 0;

    virtual antlrcpp::Any visitInputPort_name(iclParser::InputPort_nameContext *context) = 0;

    virtual antlrcpp::Any visitInputPort_source(iclParser::InputPort_sourceContext *context) = 0;

    virtual antlrcpp::Any visitParameter_override(iclParser::Parameter_overrideContext *context) = 0;

    virtual antlrcpp::Any visitInstance_addressValue(iclParser::Instance_addressValueContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_def(iclParser::ScanRegister_defContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_name(iclParser::ScanRegister_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_tail(iclParser::ScanRegister_tailContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_items(iclParser::ScanRegister_itemsContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_item(iclParser::ScanRegister_itemContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_scanInSource(iclParser::ScanRegister_scanInSourceContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_defaultLoadValue(iclParser::ScanRegister_defaultLoadValueContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_captureSource(iclParser::ScanRegister_captureSourceContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_resetValue(iclParser::ScanRegister_resetValueContext *context) = 0;

    virtual antlrcpp::Any visitScanRegister_refEnum(iclParser::ScanRegister_refEnumContext *context) = 0;

    virtual antlrcpp::Any visitNumber_or_enum(iclParser::Number_or_enumContext *context) = 0;

    virtual antlrcpp::Any visitSignal_or_enum(iclParser::Signal_or_enumContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_def(iclParser::DataRegister_defContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_name(iclParser::DataRegister_nameContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_tail(iclParser::DataRegister_tailContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_items(iclParser::DataRegister_itemsContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_item(iclParser::DataRegister_itemContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_type(iclParser::DataRegister_typeContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_common(iclParser::DataRegister_commonContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_resetValue(iclParser::DataRegister_resetValueContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_defaultLoadValue(iclParser::DataRegister_defaultLoadValueContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_refEnum(iclParser::DataRegister_refEnumContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_selectable(iclParser::DataRegister_selectableContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_writeEnSource(iclParser::DataRegister_writeEnSourceContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_writeDataSource(iclParser::DataRegister_writeDataSourceContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_addressable(iclParser::DataRegister_addressableContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_addressValue(iclParser::DataRegister_addressValueContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_readCallBack(iclParser::DataRegister_readCallBackContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_readCallBack_proc(iclParser::DataRegister_readCallBack_procContext *context) = 0;

    virtual antlrcpp::Any visitIProc_arglist(iclParser::IProc_arglistContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_readDataSource(iclParser::DataRegister_readDataSourceContext *context) = 0;

    virtual antlrcpp::Any visitDataRegister_writeCallBack(iclParser::DataRegister_writeCallBackContext *context) = 0;

    virtual antlrcpp::Any visitIProc_namespace(iclParser::IProc_namespaceContext *context) = 0;

    virtual antlrcpp::Any visitIProc_name(iclParser::IProc_nameContext *context) = 0;

    virtual antlrcpp::Any visitIProc_args(iclParser::IProc_argsContext *context) = 0;

    virtual antlrcpp::Any visitSub_namespace(iclParser::Sub_namespaceContext *context) = 0;

    virtual antlrcpp::Any visitRef_module_name(iclParser::Ref_module_nameContext *context) = 0;

    virtual antlrcpp::Any visitLogicSignal_def(iclParser::LogicSignal_defContext *context) = 0;

    virtual antlrcpp::Any visitLogicSignal_name(iclParser::LogicSignal_nameContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr(iclParser::Logic_exprContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_lvl1(iclParser::Logic_expr_lvl1Context *context) = 0;

    virtual antlrcpp::Any visitLogic_and_or_or(iclParser::Logic_and_or_orContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_lvl2(iclParser::Logic_expr_lvl2Context *context) = 0;

    virtual antlrcpp::Any visitAnd_or_xor(iclParser::And_or_xorContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_lvl3(iclParser::Logic_expr_lvl3Context *context) = 0;

    virtual antlrcpp::Any visitEq_or_neq(iclParser::Eq_or_neqContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_lvl4(iclParser::Logic_expr_lvl4Context *context) = 0;

    virtual antlrcpp::Any visitLogic_unary_expr(iclParser::Logic_unary_exprContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_arg(iclParser::Logic_expr_argContext *context) = 0;

    virtual antlrcpp::Any visitNeg_or_not(iclParser::Neg_or_notContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_paren(iclParser::Logic_expr_parenContext *context) = 0;

    virtual antlrcpp::Any visitLogic_expr_num_arg(iclParser::Logic_expr_num_argContext *context) = 0;

    virtual antlrcpp::Any visitScanMux_def(iclParser::ScanMux_defContext *context) = 0;

    virtual antlrcpp::Any visitScanMux_selections(iclParser::ScanMux_selectionsContext *context) = 0;

    virtual antlrcpp::Any visitScanMux_name(iclParser::ScanMux_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanMux_select(iclParser::ScanMux_selectContext *context) = 0;

    virtual antlrcpp::Any visitScanMux_selection(iclParser::ScanMux_selectionContext *context) = 0;

    virtual antlrcpp::Any visitDataMux_def(iclParser::DataMux_defContext *context) = 0;

    virtual antlrcpp::Any visitDataMux_selections(iclParser::DataMux_selectionsContext *context) = 0;

    virtual antlrcpp::Any visitDataMux_name(iclParser::DataMux_nameContext *context) = 0;

    virtual antlrcpp::Any visitDataMux_select(iclParser::DataMux_selectContext *context) = 0;

    virtual antlrcpp::Any visitDataMux_selection(iclParser::DataMux_selectionContext *context) = 0;

    virtual antlrcpp::Any visitClockMux_def(iclParser::ClockMux_defContext *context) = 0;

    virtual antlrcpp::Any visitClockMux_selections(iclParser::ClockMux_selectionsContext *context) = 0;

    virtual antlrcpp::Any visitClockMux_name(iclParser::ClockMux_nameContext *context) = 0;

    virtual antlrcpp::Any visitClockMux_select(iclParser::ClockMux_selectContext *context) = 0;

    virtual antlrcpp::Any visitClockMux_selection(iclParser::ClockMux_selectionContext *context) = 0;

    virtual antlrcpp::Any visitOneHotScanGroup_def(iclParser::OneHotScanGroup_defContext *context) = 0;

    virtual antlrcpp::Any visitOneHotScanGroup_items(iclParser::OneHotScanGroup_itemsContext *context) = 0;

    virtual antlrcpp::Any visitOneHotScanGroup_name(iclParser::OneHotScanGroup_nameContext *context) = 0;

    virtual antlrcpp::Any visitOneHotScanGroup_item(iclParser::OneHotScanGroup_itemContext *context) = 0;

    virtual antlrcpp::Any visitOneHotDataGroup_def(iclParser::OneHotDataGroup_defContext *context) = 0;

    virtual antlrcpp::Any visitOneHotDataGroup_items(iclParser::OneHotDataGroup_itemsContext *context) = 0;

    virtual antlrcpp::Any visitOneHotDataGroup_name(iclParser::OneHotDataGroup_nameContext *context) = 0;

    virtual antlrcpp::Any visitOneHotDataGroup_item(iclParser::OneHotDataGroup_itemContext *context) = 0;

    virtual antlrcpp::Any visitOneHotDataGroup_portSource(iclParser::OneHotDataGroup_portSourceContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink_def(iclParser::AccessLink_defContext *context) = 0;

    virtual antlrcpp::Any visitAccessLinkGeneric_def(iclParser::AccessLinkGeneric_defContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink_genericID(iclParser::AccessLink_genericIDContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_def(iclParser::AccessLink1149_defContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_stds(iclParser::AccessLink1149_stdsContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink_name(iclParser::AccessLink_nameContext *context) = 0;

    virtual antlrcpp::Any visitBsdlEntity_name(iclParser::BsdlEntity_nameContext *context) = 0;

    virtual antlrcpp::Any visitBsdl_instr_refs(iclParser::Bsdl_instr_refsContext *context) = 0;

    virtual antlrcpp::Any visitBsdl_instr_ref(iclParser::Bsdl_instr_refContext *context) = 0;

    virtual antlrcpp::Any visitBsdl_instr_selected_items(iclParser::Bsdl_instr_selected_itemsContext *context) = 0;

    virtual antlrcpp::Any visitBsdl_instr_name(iclParser::Bsdl_instr_nameContext *context) = 0;

    virtual antlrcpp::Any visitBsdl_instr_selected_item(iclParser::Bsdl_instr_selected_itemContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_ScanInterface_names(iclParser::AccessLink1149_ScanInterface_namesContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_ActiveSignal_name(iclParser::AccessLink1149_ActiveSignal_nameContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_ActiveSignal_names(iclParser::AccessLink1149_ActiveSignal_namesContext *context) = 0;

    virtual antlrcpp::Any visitAccessLink1149_ScanInterface_name(iclParser::AccessLink1149_ScanInterface_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanInterface_def(iclParser::ScanInterface_defContext *context) = 0;

    virtual antlrcpp::Any visitScanInterface_items(iclParser::ScanInterface_itemsContext *context) = 0;

    virtual antlrcpp::Any visitScanInterface_name(iclParser::ScanInterface_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanInterface_item(iclParser::ScanInterface_itemContext *context) = 0;

    virtual antlrcpp::Any visitScanInterfacePort_def(iclParser::ScanInterfacePort_defContext *context) = 0;

    virtual antlrcpp::Any visitScanInterfaceChain_def(iclParser::ScanInterfaceChain_defContext *context) = 0;

    virtual antlrcpp::Any visitScanInterfaceChain_items(iclParser::ScanInterfaceChain_itemsContext *context) = 0;

    virtual antlrcpp::Any visitScanInterfaceChain_name(iclParser::ScanInterfaceChain_nameContext *context) = 0;

    virtual antlrcpp::Any visitScanInterfaceChain_item(iclParser::ScanInterfaceChain_itemContext *context) = 0;

    virtual antlrcpp::Any visitDefaultLoad_def(iclParser::DefaultLoad_defContext *context) = 0;

    virtual antlrcpp::Any visitAlias_def(iclParser::Alias_defContext *context) = 0;

    virtual antlrcpp::Any visitAlias_name(iclParser::Alias_nameContext *context) = 0;

    virtual antlrcpp::Any visitAlias_tail(iclParser::Alias_tailContext *context) = 0;

    virtual antlrcpp::Any visitAlias_items(iclParser::Alias_itemsContext *context) = 0;

    virtual antlrcpp::Any visitAlias_item(iclParser::Alias_itemContext *context) = 0;

    virtual antlrcpp::Any visitAlias_iApplyEndState(iclParser::Alias_iApplyEndStateContext *context) = 0;

    virtual antlrcpp::Any visitAlias_refEnum(iclParser::Alias_refEnumContext *context) = 0;

    virtual antlrcpp::Any visitConcat_hier_data_signal(iclParser::Concat_hier_data_signalContext *context) = 0;

    virtual antlrcpp::Any visitX_hier_data_signal(iclParser::X_hier_data_signalContext *context) = 0;

    virtual antlrcpp::Any visitHier_data_signal(iclParser::Hier_data_signalContext *context) = 0;

    virtual antlrcpp::Any visitHier_data_signal_instances(iclParser::Hier_data_signal_instancesContext *context) = 0;

    virtual antlrcpp::Any visitEnum_def(iclParser::Enum_defContext *context) = 0;

    virtual antlrcpp::Any visitEnum_items(iclParser::Enum_itemsContext *context) = 0;

    virtual antlrcpp::Any visitEnum_name(iclParser::Enum_nameContext *context) = 0;

    virtual antlrcpp::Any visitEnum_item(iclParser::Enum_itemContext *context) = 0;

    virtual antlrcpp::Any visitEnum_symbol(iclParser::Enum_symbolContext *context) = 0;

    virtual antlrcpp::Any visitEnum_value(iclParser::Enum_valueContext *context) = 0;

    virtual antlrcpp::Any visitParameter_def(iclParser::Parameter_defContext *context) = 0;

    virtual antlrcpp::Any visitLocalParameter_def(iclParser::LocalParameter_defContext *context) = 0;

    virtual antlrcpp::Any visitParameter_name(iclParser::Parameter_nameContext *context) = 0;

    virtual antlrcpp::Any visitParameter_value(iclParser::Parameter_valueContext *context) = 0;

    virtual antlrcpp::Any visitConcat_string(iclParser::Concat_stringContext *context) = 0;

    virtual antlrcpp::Any visitString_or_parm(iclParser::String_or_parmContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_def(iclParser::Attribute_defContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_name(iclParser::Attribute_nameContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_value(iclParser::Attribute_valueContext *context) = 0;


};

