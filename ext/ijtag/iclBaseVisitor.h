
// Generated from icl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "iclVisitor.h"


/**
 * This class provides an empty implementation of iclVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  iclBaseVisitor : public iclVisitor {
public:

  virtual antlrcpp::Any visitPos_int(iclParser::Pos_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVector_id(iclParser::Vector_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_or_range(iclParser::Index_or_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex(iclParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(iclParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(iclParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr(iclParser::Integer_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_lvl1(iclParser::Integer_expr_lvl1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_lvl1_b(iclParser::Integer_expr_lvl1_bContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlus_or_minus(iclParser::Plus_or_minusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_lvl2(iclParser::Integer_expr_lvl2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_lvl2_b(iclParser::Integer_expr_lvl2_bContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStar_or_slash_or_percent(iclParser::Star_or_slash_or_percentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_paren(iclParser::Integer_expr_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_expr_arg(iclParser::Integer_expr_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_ref(iclParser::Parameter_refContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_number(iclParser::Concat_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_number_list(iclParser::Concat_number_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPin_id(iclParser::Pin_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_name(iclParser::Port_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRegister_name(iclParser::Register_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_name(iclParser::Instance_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamespace_name(iclParser::Namespace_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_name(iclParser::Module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReg_port_signal_id(iclParser::Reg_port_signal_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal(iclParser::SignalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitX_signal(iclParser::X_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_signal(iclParser::Data_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScan_signal(iclParser::Scan_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaptureEn_signal(iclParser::CaptureEn_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateEn_signal(iclParser::UpdateEn_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_reset_signal(iclParser::Concat_reset_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_data_signal(iclParser::Concat_data_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_scan_signal(iclParser::Concat_scan_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_clock_signal(iclParser::Concat_clock_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_shiftEn_signal(iclParser::Concat_shiftEn_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_tms_signal(iclParser::Concat_tms_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_trst_signal(iclParser::Concat_trst_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIcl_source(iclParser::Icl_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIclSource_items(iclParser::IclSource_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNameSpace_def(iclParser::NameSpace_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseNameSpace_def(iclParser::UseNameSpace_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_def(iclParser::Module_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_items(iclParser::Module_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_item(iclParser::Module_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_def(iclParser::Port_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInPort_def(iclParser::ScanInPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInPort_tail(iclParser::ScanInPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInPort_items(iclParser::ScanInPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInPort_name(iclParser::ScanInPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_def(iclParser::ScanOutPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_tail(iclParser::ScanOutPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_items(iclParser::ScanOutPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_name(iclParser::ScanOutPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_item(iclParser::ScanOutPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_source(iclParser::ScanOutPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_enable(iclParser::ScanOutPort_enableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanOutPort_launchEdge(iclParser::ScanOutPort_launchEdgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRising_or_falling(iclParser::Rising_or_fallingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftEnPort_def(iclParser::ShiftEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftEnPort_tail(iclParser::ShiftEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftEnPort_items(iclParser::ShiftEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftEnPort_name(iclParser::ShiftEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaptureEnPort_def(iclParser::CaptureEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaptureEnPort_tail(iclParser::CaptureEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaptureEnPort_items(iclParser::CaptureEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaptureEnPort_name(iclParser::CaptureEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateEnPort_def(iclParser::UpdateEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateEnPort_tail(iclParser::UpdateEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateEnPort_items(iclParser::UpdateEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateEnPort_name(iclParser::UpdateEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_def(iclParser::DataInPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_tail(iclParser::DataInPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_items(iclParser::DataInPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_name(iclParser::DataInPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_item(iclParser::DataInPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataInPort_refEnum(iclParser::DataInPort_refEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_def(iclParser::DataOutPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_tail(iclParser::DataOutPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_items(iclParser::DataOutPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_name(iclParser::DataOutPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_item(iclParser::DataOutPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_source(iclParser::DataOutPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_enable(iclParser::DataOutPort_enableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataOutPort_refEnum(iclParser::DataOutPort_refEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_def(iclParser::ToShiftEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_tail(iclParser::ToShiftEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_items(iclParser::ToShiftEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_name(iclParser::ToShiftEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_item(iclParser::ToShiftEnPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToShiftEnPort_source(iclParser::ToShiftEnPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_def(iclParser::ToCaptureEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_tail(iclParser::ToCaptureEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_items(iclParser::ToCaptureEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_name(iclParser::ToCaptureEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_item(iclParser::ToCaptureEnPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToCaptureEnPort_source(iclParser::ToCaptureEnPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_def(iclParser::ToUpdateEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_tail(iclParser::ToUpdateEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_items(iclParser::ToUpdateEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_name(iclParser::ToUpdateEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_item(iclParser::ToUpdateEnPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToUpdateEnPort_source(iclParser::ToUpdateEnPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectPort_def(iclParser::SelectPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectPort_tail(iclParser::SelectPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectPort_items(iclParser::SelectPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectPort_name(iclParser::SelectPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_def(iclParser::ToSelectPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_name(iclParser::ToSelectPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_tail(iclParser::ToSelectPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_items(iclParser::ToSelectPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_item(iclParser::ToSelectPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToSelectPort_source(iclParser::ToSelectPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_def(iclParser::ResetPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_name(iclParser::ResetPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_tail(iclParser::ResetPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_items(iclParser::ResetPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_item(iclParser::ResetPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetPort_polarity(iclParser::ResetPort_polarityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitZero_or_one(iclParser::Zero_or_oneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_def(iclParser::ToResetPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_name(iclParser::ToResetPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_tail(iclParser::ToResetPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_items(iclParser::ToResetPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_item(iclParser::ToResetPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_source(iclParser::ToResetPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToResetPort_polarity(iclParser::ToResetPort_polarityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTmsPort_def(iclParser::TmsPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTmsPort_tail(iclParser::TmsPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTmsPort_items(iclParser::TmsPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTmsPort_name(iclParser::TmsPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_def(iclParser::ToTmsPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_name(iclParser::ToTmsPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_tail(iclParser::ToTmsPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_items(iclParser::ToTmsPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_item(iclParser::ToTmsPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTmsPort_source(iclParser::ToTmsPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToIRSelectPort_def(iclParser::ToIRSelectPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToIRSelectPort_tail(iclParser::ToIRSelectPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToIRSelectPort_items(iclParser::ToIRSelectPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToIRSelectPort_name(iclParser::ToIRSelectPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTckPort_def(iclParser::TckPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTckPort_tail(iclParser::TckPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTckPort_items(iclParser::TckPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTckPort_name(iclParser::TckPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTckPort_def(iclParser::ToTckPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTckPort_tail(iclParser::ToTckPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTckPort_items(iclParser::ToTckPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTckPort_name(iclParser::ToTckPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_def(iclParser::ClockPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_name(iclParser::ClockPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_tail(iclParser::ClockPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_items(iclParser::ClockPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_item(iclParser::ClockPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockPort_diffPort(iclParser::ClockPort_diffPortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_def(iclParser::ToClockPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_name(iclParser::ToClockPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_tail(iclParser::ToClockPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_items(iclParser::ToClockPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_item(iclParser::ToClockPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToClockPort_source(iclParser::ToClockPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFreqMultiplier_def(iclParser::FreqMultiplier_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFreqDivider_def(iclParser::FreqDivider_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDifferentialInvOf_def(iclParser::DifferentialInvOf_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPeriod_def(iclParser::Period_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTunit(iclParser::TunitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrstPort_def(iclParser::TrstPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrstPort_tail(iclParser::TrstPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrstPort_items(iclParser::TrstPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrstPort_name(iclParser::TrstPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_def(iclParser::ToTrstPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_name(iclParser::ToTrstPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_tail(iclParser::ToTrstPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_items(iclParser::ToTrstPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_item(iclParser::ToTrstPort_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToTrstPort_source(iclParser::ToTrstPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddressPort_def(iclParser::AddressPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddressPort_tail(iclParser::AddressPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddressPort_items(iclParser::AddressPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddressPort_name(iclParser::AddressPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteEnPort_def(iclParser::WriteEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteEnPort_tail(iclParser::WriteEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteEnPort_items(iclParser::WriteEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteEnPort_name(iclParser::WriteEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadEnPort_def(iclParser::ReadEnPort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadEnPort_tail(iclParser::ReadEnPort_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadEnPort_items(iclParser::ReadEnPort_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadEnPort_name(iclParser::ReadEnPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_def(iclParser::Instance_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_module(iclParser::Instance_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_tail(iclParser::Instance_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_items(iclParser::Instance_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_item(iclParser::Instance_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInputPort_connection(iclParser::InputPort_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllowBroadcast_def(iclParser::AllowBroadcast_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllowBroadcast_items(iclParser::AllowBroadcast_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInputPort_name(iclParser::InputPort_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInputPort_source(iclParser::InputPort_sourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_override(iclParser::Parameter_overrideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_addressValue(iclParser::Instance_addressValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_def(iclParser::ScanRegister_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_name(iclParser::ScanRegister_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_tail(iclParser::ScanRegister_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_items(iclParser::ScanRegister_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_item(iclParser::ScanRegister_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_scanInSource(iclParser::ScanRegister_scanInSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_defaultLoadValue(iclParser::ScanRegister_defaultLoadValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_captureSource(iclParser::ScanRegister_captureSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_resetValue(iclParser::ScanRegister_resetValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanRegister_refEnum(iclParser::ScanRegister_refEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_or_enum(iclParser::Number_or_enumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_or_enum(iclParser::Signal_or_enumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_def(iclParser::DataRegister_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_name(iclParser::DataRegister_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_tail(iclParser::DataRegister_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_items(iclParser::DataRegister_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_item(iclParser::DataRegister_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_type(iclParser::DataRegister_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_common(iclParser::DataRegister_commonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_resetValue(iclParser::DataRegister_resetValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_defaultLoadValue(iclParser::DataRegister_defaultLoadValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_refEnum(iclParser::DataRegister_refEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_selectable(iclParser::DataRegister_selectableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_writeEnSource(iclParser::DataRegister_writeEnSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_writeDataSource(iclParser::DataRegister_writeDataSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_addressable(iclParser::DataRegister_addressableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_addressValue(iclParser::DataRegister_addressValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_readCallBack(iclParser::DataRegister_readCallBackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_readCallBack_proc(iclParser::DataRegister_readCallBack_procContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIProc_arglist(iclParser::IProc_arglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_readDataSource(iclParser::DataRegister_readDataSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataRegister_writeCallBack(iclParser::DataRegister_writeCallBackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIProc_namespace(iclParser::IProc_namespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIProc_name(iclParser::IProc_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIProc_args(iclParser::IProc_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_namespace(iclParser::Sub_namespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRef_module_name(iclParser::Ref_module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicSignal_def(iclParser::LogicSignal_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicSignal_name(iclParser::LogicSignal_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr(iclParser::Logic_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_lvl1(iclParser::Logic_expr_lvl1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_and_or_or(iclParser::Logic_and_or_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_lvl2(iclParser::Logic_expr_lvl2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd_or_xor(iclParser::And_or_xorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_lvl3(iclParser::Logic_expr_lvl3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEq_or_neq(iclParser::Eq_or_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_lvl4(iclParser::Logic_expr_lvl4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_unary_expr(iclParser::Logic_unary_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_arg(iclParser::Logic_expr_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNeg_or_not(iclParser::Neg_or_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_paren(iclParser::Logic_expr_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_expr_num_arg(iclParser::Logic_expr_num_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanMux_def(iclParser::ScanMux_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanMux_selections(iclParser::ScanMux_selectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanMux_name(iclParser::ScanMux_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanMux_select(iclParser::ScanMux_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanMux_selection(iclParser::ScanMux_selectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataMux_def(iclParser::DataMux_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataMux_selections(iclParser::DataMux_selectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataMux_name(iclParser::DataMux_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataMux_select(iclParser::DataMux_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataMux_selection(iclParser::DataMux_selectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockMux_def(iclParser::ClockMux_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockMux_selections(iclParser::ClockMux_selectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockMux_name(iclParser::ClockMux_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockMux_select(iclParser::ClockMux_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockMux_selection(iclParser::ClockMux_selectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotScanGroup_def(iclParser::OneHotScanGroup_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotScanGroup_items(iclParser::OneHotScanGroup_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotScanGroup_name(iclParser::OneHotScanGroup_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotScanGroup_item(iclParser::OneHotScanGroup_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotDataGroup_def(iclParser::OneHotDataGroup_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotDataGroup_items(iclParser::OneHotDataGroup_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotDataGroup_name(iclParser::OneHotDataGroup_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotDataGroup_item(iclParser::OneHotDataGroup_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneHotDataGroup_portSource(iclParser::OneHotDataGroup_portSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink_def(iclParser::AccessLink_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLinkGeneric_def(iclParser::AccessLinkGeneric_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink_genericID(iclParser::AccessLink_genericIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_def(iclParser::AccessLink1149_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_stds(iclParser::AccessLink1149_stdsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink_name(iclParser::AccessLink_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdlEntity_name(iclParser::BsdlEntity_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdl_instr_refs(iclParser::Bsdl_instr_refsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdl_instr_ref(iclParser::Bsdl_instr_refContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdl_instr_selected_items(iclParser::Bsdl_instr_selected_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdl_instr_name(iclParser::Bsdl_instr_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsdl_instr_selected_item(iclParser::Bsdl_instr_selected_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_ScanInterface_names(iclParser::AccessLink1149_ScanInterface_namesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_ActiveSignal_name(iclParser::AccessLink1149_ActiveSignal_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_ActiveSignal_names(iclParser::AccessLink1149_ActiveSignal_namesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessLink1149_ScanInterface_name(iclParser::AccessLink1149_ScanInterface_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterface_def(iclParser::ScanInterface_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterface_items(iclParser::ScanInterface_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterface_name(iclParser::ScanInterface_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterface_item(iclParser::ScanInterface_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterfacePort_def(iclParser::ScanInterfacePort_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterfaceChain_def(iclParser::ScanInterfaceChain_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterfaceChain_items(iclParser::ScanInterfaceChain_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterfaceChain_name(iclParser::ScanInterfaceChain_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScanInterfaceChain_item(iclParser::ScanInterfaceChain_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultLoad_def(iclParser::DefaultLoad_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_def(iclParser::Alias_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_name(iclParser::Alias_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_tail(iclParser::Alias_tailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_items(iclParser::Alias_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_item(iclParser::Alias_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_iApplyEndState(iclParser::Alias_iApplyEndStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias_refEnum(iclParser::Alias_refEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_hier_data_signal(iclParser::Concat_hier_data_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitX_hier_data_signal(iclParser::X_hier_data_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHier_data_signal(iclParser::Hier_data_signalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHier_data_signal_instances(iclParser::Hier_data_signal_instancesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_def(iclParser::Enum_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_items(iclParser::Enum_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_name(iclParser::Enum_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_item(iclParser::Enum_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_symbol(iclParser::Enum_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_value(iclParser::Enum_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_def(iclParser::Parameter_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocalParameter_def(iclParser::LocalParameter_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_name(iclParser::Parameter_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_value(iclParser::Parameter_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcat_string(iclParser::Concat_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString_or_parm(iclParser::String_or_parmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_def(iclParser::Attribute_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_name(iclParser::Attribute_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_value(iclParser::Attribute_valueContext *ctx) override {
    return visitChildren(ctx);
  }


};

