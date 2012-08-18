/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class InfoEvent : SipEvent {
  private HandleRef swigCPtr;

  internal InfoEvent(IntPtr cPtr, bool cMemoryOwn) : base(tinyWRAPPINVOKE.InfoEvent_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(InfoEvent obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~InfoEvent() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          tinyWRAPPINVOKE.delete_InfoEvent(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public tsip_info_event_type_t getType() {
    tsip_info_event_type_t ret = (tsip_info_event_type_t)tinyWRAPPINVOKE.InfoEvent_getType(swigCPtr);
    return ret;
  }

  public InfoSession getSession() {
    IntPtr cPtr = tinyWRAPPINVOKE.InfoEvent_getSession(swigCPtr);
    InfoSession ret = (cPtr == IntPtr.Zero) ? null : new InfoSession(cPtr, false);
    return ret;
  }

  public InfoSession takeSessionOwnership() {
    IntPtr cPtr = tinyWRAPPINVOKE.InfoEvent_takeSessionOwnership(swigCPtr);
    InfoSession ret = (cPtr == IntPtr.Zero) ? null : new InfoSession(cPtr, false);
    return ret;
  }

}

}