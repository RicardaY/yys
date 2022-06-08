#include "pch.h"
#include "atlbase.h"
#include "obj.h"

class MyDispatchDriver
{
public:
    IDispatch* p;
    MyDispatchDriver()
    {
        p = NULL;
    }
    MyDispatchDriver(IDispatch* lp)
    {
        if ((p = lp) != NULL)
            p->AddRef();
    }
    ~MyDispatchDriver() { if (p) p->Release(); }
    HRESULT GetIDOfName(LPCOLESTR lpsz, DISPID* pdispid)
    {
        HRESULT hr = -1;
        if (p == NULL) return hr;
        return p->GetIDsOfNames(IID_NULL, (LPOLESTR*)&lpsz, 1, LOCALE_USER_DEFAULT, pdispid);
    }
    HRESULT Invoke0(DISPID dispid, VARIANT* pvarRet = NULL)
    {
        HRESULT hr = -1;
        DISPPARAMS dispparams = { NULL, NULL, 0, 0};
        if (p == NULL) return hr;
        return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
    }
    HRESULT InvokeN(DISPID dispid, VARIANT* pvarParams, int nParams, VARIANT* pvarRet = NULL)
    {
        HRESULT hr = -1;
        DISPPARAMS dispparams = { pvarParams, NULL, nParams, 0};
        if (p == NULL) return hr;
        return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
    }
};

dmsoft::dmsoft()
{
    CLSID clsid;
    IUnknown * pUnknown = NULL;
    HRESULT hr;

    obj = NULL;
    hr = ::CLSIDFromProgID( L"dm.dmsoft", &clsid );
    if (FAILED(hr))
    {
        return;
    }

    hr = ::CoCreateInstance( clsid, NULL, CLSCTX_ALL, IID_IUnknown, (LPVOID *)&pUnknown);
    if (FAILED(hr))
    {
        return;
    }

    pUnknown->QueryInterface(IID_IDispatch, (void **)&obj);
    if (pUnknown) pUnknown->Release();
}

dmsoft::~dmsoft()
{
        if (obj) obj->Release();
}

long dmsoft::SetRowGapNoDict(long row_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(row_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetRowGapNoDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrEx(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindStrE(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::DisAssemble(const TCHAR * asm_code,LONGLONG base_addr,long is_64bit)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(asm_code);
    pn[1] = COleVariant(base_addr);
    pn[0] = COleVariant(is_64bit);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DisAssemble",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicExS(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_name);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicExS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::OcrEx(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"OcrEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetColor(long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetColor",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableFindPicMultithread(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableFindPicMultithread",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetEnv(long index,const TCHAR * name,const TCHAR * value)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(index);
    pn[1] = COleVariant(name);
    pn[0] = COleVariant(value);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetEnv",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindPic(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(pic_name);
    pn[4] = COleVariant(delta_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPic",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetMinColGap(long col_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(col_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMinColGap",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::StringToData(const TCHAR * string_value,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(string_value);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"StringToData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetCommandLine(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCommandLine",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::MiddleUp()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MiddleUp",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableFontSmooth()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableFontSmooth",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FreePic(const TCHAR * pic_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pic_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FreePic",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDisplayAcceler(long level)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(level);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDisplayAcceler",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::Ocr(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Ocr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetWindowTitle(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowTitle",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::LockDisplay(long locks)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(locks);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LockDisplay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetPath(const TCHAR * path)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(path);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetPath",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::BGR2RGB(const TCHAR * bgr_color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(bgr_color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"BGR2RGB",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::UnLoadDriver()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"UnLoadDriver",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetOsType()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetOsType",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetEnumWindowDelay(long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetEnumWindowDelay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindMulColor(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindMulColor",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadDataAddr(long hwnd,LONGLONG addr,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadDataAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetKeypadDelay(const TCHAR * tpe,long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetKeypadDelay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDiskModel(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDiskModel",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::AppendPicAddr(const TCHAR * pic_info,long addr,long size)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(pic_info);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(size);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AppendPicAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetSpecialWindow(long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetSpecialWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableMouseSync(long en,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(en);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableMouseSync",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyUpChar(const TCHAR * key_str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(key_str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyUpChar",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqCapture(long x1,long y1,long x2,long y2,long quality,long delay,long time)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(quality);
    pn[1] = COleVariant(delay);
    pn[0] = COleVariant(time);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqCapture",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::IsFolderExist(const TCHAR * folder)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(folder);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IsFolderExist",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetCursorShape()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCursorShape",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableIme(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableIme",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableKeypadPatch(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableKeypadPatch",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarLock(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarLock",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::Assemble(LONGLONG base_addr,long is_64bit)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(base_addr);
    pn[0] = COleVariant(is_64bit);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Assemble",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicMemE(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_info);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicMemE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FloatToData(float float_value)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(float_value);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FloatToData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetShowAsmErrorMsg(long show)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(show);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetShowAsmErrorMsg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindPicMem(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(pic_info);
    pn[4] = COleVariant(delta_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicMem",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrFastS(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(str);
    pn[3] = COleVariant(color);
    pn[2] = COleVariant(sim);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrFastS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarDrawLine(long hwnd,long x1,long y1,long x2,long y2,const TCHAR * color,long style,long width)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(hwnd);
    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(color);
    pn[1] = COleVariant(style);
    pn[0] = COleVariant(width);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarDrawLine",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyDown(long vk)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(vk);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyDown",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDiskReversion(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDiskReversion",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicSimEx(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,long sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_name);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSimEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::ReadFileData(const TCHAR * file_name,long start_pos,long end_pos)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(file_name);
    pn[1] = COleVariant(start_pos);
    pn[0] = COleVariant(end_pos);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadFileData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicSimE(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,long sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_name);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSimE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetRealPath(const TCHAR * path)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(path);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetRealPath",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::DmGuardLoadCustom(const TCHAR * tpe,const TCHAR * path)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(path);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DmGuardLoadCustom",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetClipboard()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetClipboard",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetLastError()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetLastError",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WaitKey(long key_code,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(key_code);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WaitKey",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LeaveCri()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LeaveCri",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Play(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Play",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetWordResultStr(const TCHAR * str,long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(str);
    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWordResultStr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarDrawPic(long hwnd,long x,long y,const TCHAR * pic,const TCHAR * trans_color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(pic);
    pn[0] = COleVariant(trans_color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarDrawPic",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetKeyState(long vk)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(vk);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetKeyState",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyDownChar(const TCHAR * key_str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(key_str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyDownChar",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LoadPicByte(long addr,long size,const TCHAR * name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(size);
    pn[0] = COleVariant(name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LoadPicByte",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WheelUp()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WheelUp",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::OpenProcess(long pid)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pid);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"OpenProcess",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::UseDict(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"UseDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ReadDataAddrToBin(long hwnd,LONGLONG addr,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadDataAddrToBin",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::IsDisplayDead(long x1,long y1,long x2,long y2,long t)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(x1);
    pn[3] = COleVariant(y1);
    pn[2] = COleVariant(x2);
    pn[1] = COleVariant(y2);
    pn[0] = COleVariant(t);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IsDisplayDead",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetUAC(long uac)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(uac);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetUAC",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetPicSize(const TCHAR * pic_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pic_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetPicSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WriteFile(const TCHAR * file_name,const TCHAR * content)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(content);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarPrintText(long hwnd,const TCHAR * text,const TCHAR * color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(text);
    pn[0] = COleVariant(color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarPrintText",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteData(long hwnd,const TCHAR * addr,const TCHAR * data)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(data);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::DoubleToData(double double_value)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(double_value);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DoubleToData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::ImageToBmp(const TCHAR * pic_name,const TCHAR * bmp_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(pic_name);
    pn[0] = COleVariant(bmp_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ImageToBmp",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetPointWindow(long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetPointWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

double dmsoft::ReadDouble(long hwnd,const TCHAR * addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadDouble",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.dblVal;
    }
    return 0.0;
}

long dmsoft::SendCommand(const TCHAR * cmd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(cmd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendCommand",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetCursorPos(long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCursorPos",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadIniPwd(const TCHAR * section,const TCHAR * key,const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(section);
    pn[2] = COleVariant(key);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadIniPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindDataEx(long hwnd,const TCHAR * addr_range,const TCHAR * data,long steps,long multi_thread,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(hwnd);
    pn[4] = COleVariant(addr_range);
    pn[3] = COleVariant(data);
    pn[2] = COleVariant(steps);
    pn[1] = COleVariant(multi_thread);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindDataEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WriteDataAddr(long hwnd,LONGLONG addr,const TCHAR * data)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(data);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteDataAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadData(long hwnd,const TCHAR * addr,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetWordLineHeightNoDict(long line_height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(line_height);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWordLineHeightNoDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqCancel()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqCancel",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableShareDict(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableShareDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetWordLineHeight(long line_height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(line_height);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWordLineHeight",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetNowDict()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetNowDict",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SendStringIme(const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendStringIme",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DeleteFolder(const TCHAR * folder_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(folder_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DeleteFolder",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetForegroundWindow()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetForegroundWindow",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetClientSize(long hwnd,long * width,long * height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[2] = COleVariant(hwnd);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetClientSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        *width = t0.lVal;
        *height = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DelEnv(long index,const TCHAR * name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DelEnv",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CreateFoobarRect(long hwnd,long x,long y,long w,long h)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(w);
    pn[0] = COleVariant(h);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CreateFoobarRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetClientSize(long hwnd,long width,long height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(width);
    pn[0] = COleVariant(height);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetClientSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindMultiColor(long x1,long y1,long x2,long y2,const TCHAR * first_color,const TCHAR * offset_color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(first_color);
    pn[4] = COleVariant(offset_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindMultiColor",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::delay(long mis)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(mis);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"delay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDictMem(long index,long addr,long size)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(index);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(size);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDictMem",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindMultiColorE(long x1,long y1,long x2,long y2,const TCHAR * first_color,const TCHAR * offset_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(first_color);
    pn[2] = COleVariant(offset_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindMultiColorE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetTime()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetTime",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDisplayInput(const TCHAR * mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDisplayInput",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindColor(long x1,long y1,long x2,long y2,const TCHAR * color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindColor",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SwitchBindWindow(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SwitchBindWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RightUp()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RightUp",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindStr(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(str);
    pn[3] = COleVariant(color);
    pn[2] = COleVariant(sim);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LeftClick()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LeftClick",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SendString(long hwnd,const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendString",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetNetTime()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetNetTime",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarFillRect(long hwnd,long x1,long y1,long x2,long y2,const TCHAR * color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(hwnd);
    pn[4] = COleVariant(x1);
    pn[3] = COleVariant(y1);
    pn[2] = COleVariant(x2);
    pn[1] = COleVariant(y2);
    pn[0] = COleVariant(color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarFillRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetWindowState(long hwnd,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWindowState",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RegEx(const TCHAR * code,const TCHAR * Ver,const TCHAR * ip)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(code);
    pn[1] = COleVariant(Ver);
    pn[0] = COleVariant(ip);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RegEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DmGuard(long en,const TCHAR * tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(en);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DmGuard",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetMouseSpeed(long speed)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(speed);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMouseSpeed",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetWindowRect(long hwnd,long * x1,long * y1,long * x2,long * y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;
    CComVariant t0,t1,t2,t3;

    VariantInit(&t0);
    VariantInit(&t1);
    VariantInit(&t2);
    VariantInit(&t3);

    pn[4] = COleVariant(hwnd);
    pn[3].vt = VT_BYREF|VT_VARIANT;
    pn[3].pvarVal = &t0;
    pn[2].vt = VT_BYREF|VT_VARIANT;
    pn[2].pvarVal = &t1;
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t2;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t3;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        *x1 = t0.lVal;
        *y1 = t1.lVal;
        *x2 = t2.lVal;
        *y2 = t3.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDisplayInfo()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDisplayInfo",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetWindowProcessId(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowProcessId",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableKeypadSync(long en,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(en);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableKeypadSync",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindString(long hwnd,const TCHAR * addr_range,const TCHAR * string_value,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr_range);
    pn[1] = COleVariant(string_value);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindString",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::CreateFoobarEllipse(long hwnd,long x,long y,long w,long h)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(w);
    pn[0] = COleVariant(h);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CreateFoobarEllipse",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteDoubleAddr(long hwnd,LONGLONG addr,double v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteDoubleAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetPicPwd(const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetPicPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::MoveDD(long dx,long dy)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(dx);
    pn[0] = COleVariant(dy);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveDD",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::AddDict(long index,const TCHAR * dict_info)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(dict_info);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AddDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SendStringIme2(long hwnd,const TCHAR * str,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(str);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendStringIme2",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::InitCri()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"InitCri",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FetchWord(long x1,long y1,long x2,long y2,const TCHAR * color,const TCHAR * word)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(word);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FetchWord",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::VirtualProtectEx(long hwnd,LONGLONG addr,long size,long tpe,long old_protect)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(addr);
    pn[2] = COleVariant(size);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(old_protect);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"VirtualProtectEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ClientToScreen(long hwnd,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[2] = COleVariant(hwnd);
    t0.vt = VT_I4;
    t0.lVal = *x;
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    t1.vt = VT_I4;
    t1.lVal = *y;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ClientToScreen",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LeftDown()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LeftDown",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetWindowState(long hwnd,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowState",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::Hex64(LONGLONG v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Hex64",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::RightDown()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RightDown",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetExcludeRegion(long tpe,const TCHAR * info)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(info);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetExcludeRegion",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RightClick()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RightClick",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableSpeedDx(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableSpeedDx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

LONGLONG dmsoft::GetModuleBaseAddr(long hwnd,const TCHAR * module_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(module_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetModuleBaseAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

long dmsoft::FindWindowByProcessId(long process_id,const TCHAR * class_name,const TCHAR * title_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(process_id);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(title_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindWindowByProcessId",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindShapeE(long x1,long y1,long x2,long y2,const TCHAR * offset_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(offset_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindShapeE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetResultPos(const TCHAR * str,long index,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[3] = COleVariant(str);
    pn[2] = COleVariant(index);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetResultPos",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindColorEx(long x1,long y1,long x2,long y2,const TCHAR * color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindColorEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WheelDown()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WheelDown",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqIsPosted()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqIsPosted",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LockMouseRect(long x1,long y1,long x2,long y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x1);
    pn[2] = COleVariant(y1);
    pn[1] = COleVariant(x2);
    pn[0] = COleVariant(y2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LockMouseRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarClearText(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarClearText",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CreateFoobarRoundRect(long hwnd,long x,long y,long w,long h,long rw,long rh)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(hwnd);
    pn[5] = COleVariant(x);
    pn[4] = COleVariant(y);
    pn[3] = COleVariant(w);
    pn[2] = COleVariant(h);
    pn[1] = COleVariant(rw);
    pn[0] = COleVariant(rh);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CreateFoobarRoundRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetInputDm(long input_dm,long rx,long ry)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(input_dm);
    pn[1] = COleVariant(rx);
    pn[0] = COleVariant(ry);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetInputDm",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDict(long index,long font_index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(font_index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetDictInfo(const TCHAR * str,const TCHAR * font_name,long font_size,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(str);
    pn[2] = COleVariant(font_name);
    pn[1] = COleVariant(font_size);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDictInfo",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::EnumWindowSuper(const TCHAR * spec1,long flag1,long type1,const TCHAR * spec2,long flag2,long type2,long sort)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(spec1);
    pn[5] = COleVariant(flag1);
    pn[4] = COleVariant(type1);
    pn[3] = COleVariant(spec2);
    pn[2] = COleVariant(flag2);
    pn[1] = COleVariant(type2);
    pn[0] = COleVariant(sort);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumWindowSuper",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WriteDataFromBin(long hwnd,const TCHAR * addr,long data,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(data);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteDataFromBin",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindInt(long hwnd,const TCHAR * addr_range,LONGLONG int_value_min,LONGLONG int_value_max,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(addr_range);
    pn[2] = COleVariant(int_value_min);
    pn[1] = COleVariant(int_value_max);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindInt",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FindWindowByProcess(const TCHAR * process_name,const TCHAR * class_name,const TCHAR * title_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(process_name);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(title_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindWindowByProcess",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetDmCount()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDmCount",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RegExNoMac(const TCHAR * code,const TCHAR * Ver,const TCHAR * ip)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(code);
    pn[1] = COleVariant(Ver);
    pn[0] = COleVariant(ip);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RegExNoMac",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetParam64ToPointer()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetParam64ToPointer",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FaqSend(const TCHAR * server,long handle,long request_type,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(server);
    pn[2] = COleVariant(handle);
    pn[1] = COleVariant(request_type);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqSend",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::EnumWindowByProcess(const TCHAR * process_name,const TCHAR * title,const TCHAR * class_name,long filter)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(process_name);
    pn[2] = COleVariant(title);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(filter);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumWindowByProcess",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetScreenHeight()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetScreenHeight",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetResultCount(const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetResultCount",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Is64Bit()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Is64Bit",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::AsmClear()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AsmClear",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LeftDoubleClick()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LeftDoubleClick",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarClose(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarClose",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindWindowSuper(const TCHAR * spec1,long flag1,long type1,const TCHAR * spec2,long flag2,long type2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(spec1);
    pn[4] = COleVariant(flag1);
    pn[3] = COleVariant(type1);
    pn[2] = COleVariant(spec2);
    pn[1] = COleVariant(flag2);
    pn[0] = COleVariant(type2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindWindowSuper",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqCaptureString(const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqCaptureString",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::HackSpeed(double rate)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(rate);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"HackSpeed",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::EnumIniKey(const TCHAR * section,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(section);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumIniKey",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindColorE(long x1,long y1,long x2,long y2,const TCHAR * color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindColorE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::DisableScreenSave()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DisableScreenSave",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindPicSim(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,long sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(pic_name);
    pn[4] = COleVariant(delta_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSim",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::StrStr(const TCHAR * s,const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(s);
    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"StrStr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DownCpu(long tpe,long rate)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(rate);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DownCpu",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::IsBind(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IsBind",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DecodeFile(const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DecodeFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetMinRowGap(long row_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(row_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMinRowGap",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetWordResultPos(const TCHAR * str,long index,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[3] = COleVariant(str);
    pn[2] = COleVariant(index);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWordResultPos",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CapturePng(long x1,long y1,long x2,long y2,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(x1);
    pn[3] = COleVariant(y1);
    pn[2] = COleVariant(x2);
    pn[1] = COleVariant(y2);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CapturePng",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CheckUAC()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CheckUAC",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindPicSimMem(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,long sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(pic_info);
    pn[4] = COleVariant(delta_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSimMem",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FreeProcessMemory(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FreeProcessMemory",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindDouble(long hwnd,const TCHAR * addr_range,double double_value_min,double double_value_max)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr_range);
    pn[1] = COleVariant(double_value_min);
    pn[0] = COleVariant(double_value_max);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindDouble",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

float dmsoft::ReadFloat(long hwnd,const TCHAR * addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadFloat",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.fltVal;
    }
    return 0.0f;
}

LONGLONG dmsoft::ReadInt(long hwnd,const TCHAR * addr,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadInt",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

long dmsoft::GetClientRect(long hwnd,long * x1,long * y1,long * x2,long * y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;
    CComVariant t0,t1,t2,t3;

    VariantInit(&t0);
    VariantInit(&t1);
    VariantInit(&t2);
    VariantInit(&t3);

    pn[4] = COleVariant(hwnd);
    pn[3].vt = VT_BYREF|VT_VARIANT;
    pn[3].pvarVal = &t0;
    pn[2].vt = VT_BYREF|VT_VARIANT;
    pn[2].pvarVal = &t1;
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t2;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t3;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetClientRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        *x1 = t0.lVal;
        *y1 = t1.lVal;
        *x2 = t2.lVal;
        *y2 = t3.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDir(long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDir",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableGetColorByCapture(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableGetColorByCapture",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::EnumWindow(long parent,const TCHAR * title,const TCHAR * class_name,long filter)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(parent);
    pn[2] = COleVariant(title);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(filter);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableFakeActive(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableFakeActive",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableMouseAccuracy(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableMouseAccuracy",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ScreenToClient(long hwnd,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[2] = COleVariant(hwnd);
    t0.vt = VT_I4;
    t0.lVal = *x;
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    t1.vt = VT_I4;
    t1.lVal = *y;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ScreenToClient",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDisplayDelay(long t)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(t);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDisplayDelay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteIni(const TCHAR * section,const TCHAR * key,const TCHAR * v,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(section);
    pn[2] = COleVariant(key);
    pn[1] = COleVariant(v);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteIni",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyPressChar(const TCHAR * key_str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(key_str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyPressChar",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindMultiColorEx(long x1,long y1,long x2,long y2,const TCHAR * first_color,const TCHAR * offset_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(first_color);
    pn[2] = COleVariant(offset_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindMultiColorEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FindShape(long x1,long y1,long x2,long y2,const TCHAR * offset_color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(offset_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindShape",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetBasePath()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetBasePath",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::BindWindow(long hwnd,const TCHAR * display,const TCHAR * mouse,const TCHAR * keypad,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(display);
    pn[2] = COleVariant(mouse);
    pn[1] = COleVariant(keypad);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"BindWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetScreen(long width,long height,long depth)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(width);
    pn[1] = COleVariant(height);
    pn[0] = COleVariant(depth);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetScreen",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetWindow(long hwnd,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetColorBGR(long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetColorBGR",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableRealKeypad(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableRealKeypad",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ClearDict(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ClearDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetExitThread(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetExitThread",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetDiskSerial(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDiskSerial",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SendPaste(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendPaste",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindPicSimMemE(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,long sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_info);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSimMemE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::MoveTo(long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveTo",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RegNoMac(const TCHAR * code,const TCHAR * Ver)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(code);
    pn[0] = COleVariant(Ver);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RegNoMac",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetWindowClass(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowClass",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetColorHSV(long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetColorHSV",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetCursorSpot()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCursorSpot",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetCpuUsage()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCpuUsage",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteStringAddr(long hwnd,LONGLONG addr,long tpe,const TCHAR * v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteStringAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrFastEx(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrFastEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindShapeEx(long x1,long y1,long x2,long y2,const TCHAR * offset_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(offset_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindShapeEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::Stop(long id)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(id);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Stop",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CmpColor(long x,long y,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CmpColor",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetColorNum(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetColorNum",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableKeypadMsg(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableKeypadMsg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqGetSize(long handle)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(handle);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqGetSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqCaptureFromFile(long x1,long y1,long x2,long y2,const TCHAR * file_name,long quality)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(quality);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqCaptureFromFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LoadPic(const TCHAR * pic_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pic_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LoadPic",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDisplayRefreshDelay(long t)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(t);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDisplayRefreshDelay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindNearestPos(const TCHAR * all_pos,long tpe,long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(all_pos);
    pn[2] = COleVariant(tpe);
    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindNearestPos",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicSimMemEx(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,long sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_info);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicSimMemEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::CopyFile(const TCHAR * src_file,const TCHAR * dst_file,long over)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(src_file);
    pn[1] = COleVariant(dst_file);
    pn[0] = COleVariant(over);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CopyFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetPath()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetPath",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetEnv(long index,const TCHAR * name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetEnv",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::UnBindWindow()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"UnBindWindow",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindStrFast(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(str);
    pn[3] = COleVariant(color);
    pn[2] = COleVariant(sim);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrFast",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetSystemInfo(const TCHAR * tpe,long method)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(method);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetSystemInfo",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::RGB2BGR(const TCHAR * rgb_color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(rgb_color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RGB2BGR",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::MoveR(long rx,long ry)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(rx);
    pn[0] = COleVariant(ry);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveR",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindPicE(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_name);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetProcessInfo(long pid)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pid);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetProcessInfo",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetLocale()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetLocale",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FaqPost(const TCHAR * server,long handle,long request_type,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(server);
    pn[2] = COleVariant(handle);
    pn[1] = COleVariant(request_type);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqPost",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetBindWindow()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetBindWindow",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::TerminateProcess(long pid)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pid);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"TerminateProcess",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnablePicCache(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnablePicCache",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindPicMemEx(long x1,long y1,long x2,long y2,const TCHAR * pic_info,const TCHAR * delta_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_info);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicMemEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetModuleSize(long hwnd,const TCHAR * module_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(module_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetModuleSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarUpdate(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarUpdate",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetID()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetID",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindDoubleEx(long hwnd,const TCHAR * addr_range,double double_value_min,double double_value_max,long steps,long multi_thread,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(hwnd);
    pn[5] = COleVariant(addr_range);
    pn[4] = COleVariant(double_value_min);
    pn[3] = COleVariant(double_value_max);
    pn[2] = COleVariant(steps);
    pn[1] = COleVariant(multi_thread);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindDoubleEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetWindowProcessPath(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowProcessPath",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WriteDouble(long hwnd,const TCHAR * addr,double v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteDouble",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteInt(long hwnd,const TCHAR * addr,long tpe,LONGLONG v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteInt",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableMouseMsg(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableMouseMsg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindWindow(const TCHAR * class_name,const TCHAR * title_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(title_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FreeScreenData(long handle)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(handle);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FreeScreenData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetColGapNoDict(long col_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(col_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetColGapNoDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::VirtualQueryEx(long hwnd,LONGLONG addr,long pmbi)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(pmbi);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"VirtualQueryEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindColorBlockEx(long x1,long y1,long x2,long y2,const TCHAR * color,double sim,long count,long width,long height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(count);
    pn[1] = COleVariant(width);
    pn[0] = COleVariant(height);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindColorBlockEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetWindowTransparent(long hwnd,long v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWindowTransparent",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableRealMouse(long en,long mousedelay,long mousestep)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(en);
    pn[1] = COleVariant(mousedelay);
    pn[0] = COleVariant(mousestep);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableRealMouse",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::EnumIniSection(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumIniSection",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::ExecuteCmd(const TCHAR * cmd,const TCHAR * current_dir,long time_out)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(cmd);
    pn[1] = COleVariant(current_dir);
    pn[0] = COleVariant(time_out);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ExecuteCmd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::MoveToEx(long x,long y,long w,long h)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(w);
    pn[0] = COleVariant(h);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveToEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindData(long hwnd,const TCHAR * addr_range,const TCHAR * data)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr_range);
    pn[0] = COleVariant(data);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarSetSave(long hwnd,const TCHAR * file_name,long en,const TCHAR * header)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(file_name);
    pn[1] = COleVariant(en);
    pn[0] = COleVariant(header);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarSetSave",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Delays(long min_s,long max_s)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(min_s);
    pn[0] = COleVariant(max_s);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Delays",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::MiddleDown()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MiddleDown",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetMac()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMac",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetFps()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetFps",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ActiveInputMethod(long hwnd,const TCHAR * id)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(id);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ActiveInputMethod",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Log(const TCHAR * info)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(info);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Log",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Capture(long x1,long y1,long x2,long y2,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(x1);
    pn[3] = COleVariant(y1);
    pn[2] = COleVariant(x2);
    pn[1] = COleVariant(y2);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Capture",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarTextRect(long hwnd,long x,long y,long w,long h)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(hwnd);
    pn[3] = COleVariant(x);
    pn[2] = COleVariant(y);
    pn[1] = COleVariant(w);
    pn[0] = COleVariant(h);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarTextRect",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::MiddleClick()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MiddleClick",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStringEx(long hwnd,const TCHAR * addr_range,const TCHAR * string_value,long tpe,long steps,long multi_thread,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(hwnd);
    pn[5] = COleVariant(addr_range);
    pn[4] = COleVariant(string_value);
    pn[3] = COleVariant(tpe);
    pn[2] = COleVariant(steps);
    pn[1] = COleVariant(multi_thread);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStringEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::EnumProcess(const TCHAR * name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumProcess",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetWordGap(long word_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(word_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWordGap",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

LONGLONG dmsoft::ReadIntAddr(long hwnd,LONGLONG addr,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadIntAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

long dmsoft::SetFindPicMultithreadCount(long count)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(count);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetFindPicMultithreadCount",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteIniPwd(const TCHAR * section,const TCHAR * key,const TCHAR * v,const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(section);
    pn[3] = COleVariant(key);
    pn[2] = COleVariant(v);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteIniPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::SelectFile()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SelectFile",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetScreenData(long x1,long y1,long x2,long y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x1);
    pn[2] = COleVariant(y1);
    pn[1] = COleVariant(x2);
    pn[0] = COleVariant(y2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetScreenData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CheckInputMethod(long hwnd,const TCHAR * id)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(id);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CheckInputMethod",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrFastExS(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrFastExS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::Md5(const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Md5",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetMemoryFindResultToFile(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMemoryFindResultToFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

float dmsoft::ReadFloatAddr(long hwnd,LONGLONG addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadFloatAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.fltVal;
    }
    return 0.0f;
}

long dmsoft::FoobarUnlock(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarUnlock",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetDictCount(long index)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(index);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDictCount",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindWindowEx(long parent,const TCHAR * class_name,const TCHAR * title_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(parent);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(title_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindWindowEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteIntAddr(long hwnd,LONGLONG addr,long tpe,LONGLONG v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteIntAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Reg(const TCHAR * code,const TCHAR * Ver)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(code);
    pn[0] = COleVariant(Ver);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Reg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CaptureGif(long x1,long y1,long x2,long y2,const TCHAR * file_name,long delay,long time)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(file_name);
    pn[1] = COleVariant(delay);
    pn[0] = COleVariant(time);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CaptureGif",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetSimMode(long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetSimMode",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DownloadFile(const TCHAR * url,const TCHAR * save_file,long timeout)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(url);
    pn[1] = COleVariant(save_file);
    pn[0] = COleVariant(timeout);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DownloadFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CapturePre(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CapturePre",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CreateFolder(const TCHAR * folder_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(folder_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CreateFolder",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::VirtualFreeEx(long hwnd,LONGLONG addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"VirtualFreeEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteFloat(long hwnd,const TCHAR * addr,float v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteFloat",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindColorBlock(long x1,long y1,long x2,long y2,const TCHAR * color,double sim,long count,long width,long height,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[11];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[10] = COleVariant(x1);
    pn[9] = COleVariant(y1);
    pn[8] = COleVariant(x2);
    pn[7] = COleVariant(y2);
    pn[6] = COleVariant(color);
    pn[5] = COleVariant(sim);
    pn[4] = COleVariant(count);
    pn[3] = COleVariant(width);
    pn[2] = COleVariant(height);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindColorBlock",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,11,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyUp(long vk)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(vk);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyUp",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteString(long hwnd,const TCHAR * addr,long tpe,const TCHAR * v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteString",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Int64ToInt32(LONGLONG v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Int64ToInt32",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarTextLineGap(long hwnd,long gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarTextLineGap",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::SelectDirectory()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SelectDirectory",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarSetTrans(long hwnd,long trans,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(trans);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarSetTrans",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::IsSurrpotVt()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IsSurrpotVt",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarSetFont(long hwnd,const TCHAR * font_name,long size,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(font_name);
    pn[1] = COleVariant(size);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarSetFont",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::OcrInFile(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(pic_name);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"OcrInFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::DmGuardParams(const TCHAR * cmd,const TCHAR * sub_cmd,const TCHAR * param)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(cmd);
    pn[1] = COleVariant(sub_cmd);
    pn[0] = COleVariant(param);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DmGuardParams",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::SortPosDistance(const TCHAR * all_pos,long tpe,long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(all_pos);
    pn[2] = COleVariant(tpe);
    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SortPosDistance",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::MatchPicName(const TCHAR * pic_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pic_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MatchPicName",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindFloatEx(long hwnd,const TCHAR * addr_range,float float_value_min,float float_value_max,long steps,long multi_thread,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(hwnd);
    pn[5] = COleVariant(addr_range);
    pn[4] = COleVariant(float_value_min);
    pn[3] = COleVariant(float_value_max);
    pn[2] = COleVariant(steps);
    pn[1] = COleVariant(multi_thread);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindFloatEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

LONGLONG dmsoft::VirtualAllocEx(long hwnd,LONGLONG addr,long size,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(size);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"VirtualAllocEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

long dmsoft::MoveWindow(long hwnd,long x,long y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(x);
    pn[0] = COleVariant(y);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::IsFileExist(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IsFileExist",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ReadDataToBin(long hwnd,const TCHAR * addr,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadDataToBin",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::EnumIniKeyPwd(const TCHAR * section,const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(section);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumIniKeyPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::EnumIniSectionPwd(const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumIniSectionPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindFloat(long hwnd,const TCHAR * addr_range,float float_value_min,float float_value_max)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr_range);
    pn[1] = COleVariant(float_value_min);
    pn[0] = COleVariant(float_value_max);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindFloat",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindStrFastE(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrFastE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetExactOcr(long exact_ocr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(exact_ocr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetExactOcr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LeftUp()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LeftUp",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetNetTimeSafe()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetNetTimeSafe",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FaqFetch()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqFetch",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::ExcludePos(const TCHAR * all_pos,long tpe,long x1,long y1,long x2,long y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(all_pos);
    pn[4] = COleVariant(tpe);
    pn[3] = COleVariant(x1);
    pn[2] = COleVariant(y1);
    pn[1] = COleVariant(x2);
    pn[0] = COleVariant(y2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ExcludePos",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EncodeFile(const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EncodeFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

double dmsoft::ReadDoubleAddr(long hwnd,LONGLONG addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadDoubleAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.dblVal;
    }
    return 0.0;
}

long dmsoft::GetForegroundFocus()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetForegroundFocus",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarStartGif(long hwnd,long x,long y,const TCHAR * pic_name,long repeat_limit,long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(hwnd);
    pn[4] = COleVariant(x);
    pn[3] = COleVariant(y);
    pn[2] = COleVariant(pic_name);
    pn[1] = COleVariant(repeat_limit);
    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarStartGif",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetWordGapNoDict(long word_gap)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(word_gap);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWordGapNoDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::Ver()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Ver",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetWindowSize(long hwnd,long width,long height)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(width);
    pn[0] = COleVariant(height);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWindowSize",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetScreenWidth()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetScreenWidth",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetAveHSV(long x1,long y1,long x2,long y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x1);
    pn[2] = COleVariant(y1);
    pn[1] = COleVariant(x2);
    pn[0] = COleVariant(y2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetAveHSV",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::WriteDataAddrFromBin(long hwnd,LONGLONG addr,long data,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(data);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteDataAddrFromBin",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetWordsNoDict(long x1,long y1,long x2,long y2,const TCHAR * color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[5];
    CComVariant vResult;

    pn[4] = COleVariant(x1);
    pn[3] = COleVariant(y1);
    pn[2] = COleVariant(x2);
    pn[1] = COleVariant(y2);
    pn[0] = COleVariant(color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWordsNoDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,5,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetLocale()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetLocale",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::IntToData(LONGLONG int_value,long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(int_value);
    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"IntToData",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::BindWindowEx(long hwnd,const TCHAR * display,const TCHAR * mouse,const TCHAR * keypad,const TCHAR * public_desc,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(hwnd);
    pn[4] = COleVariant(display);
    pn[3] = COleVariant(mouse);
    pn[2] = COleVariant(keypad);
    pn[1] = COleVariant(public_desc);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"BindWindowEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnableDisplayDebug(long enable_debug)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(enable_debug);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableDisplayDebug",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyPress(long vk)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(vk);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyPress",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::Beep(long fre,long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(fre);
    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Beep",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrWithFontEx(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,const TCHAR * font_name,long font_size,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(str);
    pn[4] = COleVariant(color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(font_name);
    pn[1] = COleVariant(font_size);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrWithFontEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::DisablePowerSave()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DisablePowerSave",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarDrawText(long hwnd,long x,long y,long w,long h,const TCHAR * text,const TCHAR * color,long align)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(hwnd);
    pn[6] = COleVariant(x);
    pn[5] = COleVariant(y);
    pn[4] = COleVariant(w);
    pn[3] = COleVariant(h);
    pn[2] = COleVariant(text);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(align);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarDrawText",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::AsmAdd(const TCHAR * asm_ins)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(asm_ins);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AsmAdd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrS(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[9];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[8] = COleVariant(x1);
    pn[7] = COleVariant(y1);
    pn[6] = COleVariant(x2);
    pn[5] = COleVariant(y2);
    pn[4] = COleVariant(str);
    pn[3] = COleVariant(color);
    pn[2] = COleVariant(sim);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,9,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::ReleaseRef()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReleaseRef",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetClipboard(const TCHAR * data)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(data);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetClipboard",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetMachineCodeNoMac()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMachineCodeNoMac",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::ShowScrMsg(long x1,long y1,long x2,long y2,const TCHAR * msg,const TCHAR * color)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(msg);
    pn[0] = COleVariant(color);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ShowScrMsg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::LockInput(long locks)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(locks);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"LockInput",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetScreenDataBmp(long x1,long y1,long x2,long y2,long * data,long * size)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetScreenDataBmp",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        *data = t0.lVal;
        *size = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadStringAddr(long hwnd,LONGLONG addr,long tpe,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadStringAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::DeleteFile(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DeleteFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CaptureJpg(long x1,long y1,long x2,long y2,const TCHAR * file_name,long quality)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(quality);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CaptureJpg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SendString2(long hwnd,const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SendString2",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetOsBuildNumber()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetOsBuildNumber",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetAveRGB(long x1,long y1,long x2,long y2)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(x1);
    pn[2] = COleVariant(y1);
    pn[1] = COleVariant(x2);
    pn[0] = COleVariant(y2);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetAveRGB",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetDict(long index,const TCHAR * dict_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(dict_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DeleteIniPwd(const TCHAR * section,const TCHAR * key,const TCHAR * file_name,const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(section);
    pn[2] = COleVariant(key);
    pn[1] = COleVariant(file_name);
    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DeleteIniPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetMousePointWindow()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMousePointWindow",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::MoveFile(const TCHAR * src_file,const TCHAR * dst_file)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(src_file);
    pn[0] = COleVariant(dst_file);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"MoveFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DeleteIni(const TCHAR * section,const TCHAR * key,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(section);
    pn[1] = COleVariant(key);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DeleteIni",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::EnumWindowByProcessId(long pid,const TCHAR * title,const TCHAR * class_name,long filter)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(pid);
    pn[2] = COleVariant(title);
    pn[1] = COleVariant(class_name);
    pn[0] = COleVariant(filter);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnumWindowByProcessId",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetCpuType()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCpuType",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetScreenDepth()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetScreenDepth",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindPicEx(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,double sim,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(x1);
    pn[6] = COleVariant(y1);
    pn[5] = COleVariant(x2);
    pn[4] = COleVariant(y2);
    pn[3] = COleVariant(pic_name);
    pn[2] = COleVariant(delta_color);
    pn[1] = COleVariant(sim);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

LONGLONG dmsoft::AsmCall(long hwnd,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AsmCall",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

CString dmsoft::GetCursorShapeEx(long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetCursorShapeEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

LONGLONG dmsoft::AsmCallEx(long hwnd,long mode,const TCHAR * base_addr)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(mode);
    pn[0] = COleVariant(base_addr);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AsmCallEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

long dmsoft::SetWindowText(long hwnd,const TCHAR * text)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(text);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetWindowText",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindStrWithFontE(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,const TCHAR * font_name,long font_size,long flag)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(str);
    pn[4] = COleVariant(color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(font_name);
    pn[1] = COleVariant(font_size);
    pn[0] = COleVariant(flag);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrWithFontE",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FoobarTextPrintDir(long hwnd,long dir)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(dir);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarTextPrintDir",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::WriteFloatAddr(long hwnd,LONGLONG addr,float v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(addr);
    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"WriteFloatAddr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DisableFontSmooth()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DisableFontSmooth",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FoobarStopGif(long hwnd,long x,long y,const TCHAR * pic_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(x);
    pn[1] = COleVariant(y);
    pn[0] = COleVariant(pic_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FoobarStopGif",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetFileLength(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetFileLength",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SpeedNormalGraphic(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SpeedNormalGraphic",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetAero(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetAero",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadIni(const TCHAR * section,const TCHAR * key,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(section);
    pn[1] = COleVariant(key);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadIni",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::FindPicS(long x1,long y1,long x2,long y2,const TCHAR * pic_name,const TCHAR * delta_color,double sim,long dir,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[10];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[9] = COleVariant(x1);
    pn[8] = COleVariant(y1);
    pn[7] = COleVariant(x2);
    pn[6] = COleVariant(y2);
    pn[5] = COleVariant(pic_name);
    pn[4] = COleVariant(delta_color);
    pn[3] = COleVariant(sim);
    pn[2] = COleVariant(dir);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindPicS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,10,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

CString dmsoft::GetMachineCode()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMachineCode",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetDPI()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetDPI",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetExportDict(long index,const TCHAR * dict_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(dict_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetExportDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetMouseDelay(const TCHAR * tpe,long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMouseDelay",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DmGuardExtract(const TCHAR * tpe,const TCHAR * path)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(path);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DmGuardExtract",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetShowErrorMsg(long show)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(show);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetShowErrorMsg",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::ShowTaskBarIcon(long hwnd,long is_show)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(hwnd);
    pn[0] = COleVariant(is_show);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ShowTaskBarIcon",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::SetDictPwd(const TCHAR * pwd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(pwd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetDictPwd",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadFile(const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadFile",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::GetWindowThreadId(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWindowThreadId",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindInputMethod(const TCHAR * id)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(id);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindInputMethod",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CheckFontSmooth()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CheckFontSmooth",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::CreateFoobarCustom(long hwnd,long x,long y,const TCHAR * pic,const TCHAR * trans_color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(hwnd);
    pn[4] = COleVariant(x);
    pn[3] = COleVariant(y);
    pn[2] = COleVariant(pic);
    pn[1] = COleVariant(trans_color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"CreateFoobarCustom",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetNetTimeByIp(const TCHAR * ip)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(ip);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetNetTimeByIp",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SaveDict(long index,const TCHAR * file_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(index);
    pn[0] = COleVariant(file_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SaveDict",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::FindIntEx(long hwnd,const TCHAR * addr_range,LONGLONG int_value_min,LONGLONG int_value_max,long tpe,long steps,long multi_thread,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[8];
    CComVariant vResult;

    pn[7] = COleVariant(hwnd);
    pn[6] = COleVariant(addr_range);
    pn[5] = COleVariant(int_value_min);
    pn[4] = COleVariant(int_value_max);
    pn[3] = COleVariant(tpe);
    pn[2] = COleVariant(steps);
    pn[1] = COleVariant(multi_thread);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindIntEx",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,8,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::SetMemoryHwndAsProcessId(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"SetMemoryHwndAsProcessId",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::GetWords(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWords",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::FaqRelease(long handle)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(handle);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FaqRelease",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::FindStrWithFont(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim,const TCHAR * font_name,long font_size,long flag,long * x,long * y)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[12];
    CComVariant vResult;
    CComVariant t0,t1;

    VariantInit(&t0);
    VariantInit(&t1);

    pn[11] = COleVariant(x1);
    pn[10] = COleVariant(y1);
    pn[9] = COleVariant(x2);
    pn[8] = COleVariant(y2);
    pn[7] = COleVariant(str);
    pn[6] = COleVariant(color);
    pn[5] = COleVariant(sim);
    pn[4] = COleVariant(font_name);
    pn[3] = COleVariant(font_size);
    pn[2] = COleVariant(flag);
    pn[1].vt = VT_BYREF|VT_VARIANT;
    pn[1].pvarVal = &t0;
    pn[0].vt = VT_BYREF|VT_VARIANT;
    pn[0].pvarVal = &t1;

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrWithFont",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,12,&vResult);
    if (SUCCEEDED(hr))
    {
        *x = t0.lVal;
        *y = t1.lVal;
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::EnterCri()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnterCri",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetMemoryUsage()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMemoryUsage",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetWordResultCount(const TCHAR * str)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(str);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetWordResultCount",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::GetMouseSpeed()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetMouseSpeed",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::KeyPressStr(const TCHAR * key_str,long delay)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(key_str);
    pn[0] = COleVariant(delay);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"KeyPressStr",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::Hex32(long v)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(v);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"Hex32",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::EnableBind(long en)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(en);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"EnableBind",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::DisableCloseDisplayAndSleep()
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    CComVariant vResult;


    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"DisableCloseDisplayAndSleep",&dispatch_id);
    }

    hr = spDisp.Invoke0(dispatch_id,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::ReadString(long hwnd,const TCHAR * addr,long tpe,long length)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[4];
    CComVariant vResult;

    pn[3] = COleVariant(hwnd);
    pn[2] = COleVariant(addr);
    pn[1] = COleVariant(tpe);
    pn[0] = COleVariant(length);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ReadString",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,4,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::ForceUnBindWindow(long hwnd)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(hwnd);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ForceUnBindWindow",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

long dmsoft::RunApp(const TCHAR * path,long mode)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(path);
    pn[0] = COleVariant(mode);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"RunApp",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

CString dmsoft::OcrExOne(long x1,long y1,long x2,long y2,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[6];
    CComVariant vResult;

    pn[5] = COleVariant(x1);
    pn[4] = COleVariant(y1);
    pn[3] = COleVariant(x2);
    pn[2] = COleVariant(y2);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"OcrExOne",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,6,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::AsmSetTimeout(long time_out,long param)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[2];
    CComVariant vResult;

    pn[1] = COleVariant(time_out);
    pn[0] = COleVariant(param);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"AsmSetTimeout",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,2,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

LONGLONG dmsoft::GetRemoteApiAddress(long hwnd,LONGLONG base_addr,const TCHAR * fun_name)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[3];
    CComVariant vResult;

    pn[2] = COleVariant(hwnd);
    pn[1] = COleVariant(base_addr);
    pn[0] = COleVariant(fun_name);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"GetRemoteApiAddress",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,3,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.llVal;
    }
    return 0;
}

CString dmsoft::FindStrExS(long x1,long y1,long x2,long y2,const TCHAR * str,const TCHAR * color,double sim)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[7];
    CComVariant vResult;

    pn[6] = COleVariant(x1);
    pn[5] = COleVariant(y1);
    pn[4] = COleVariant(x2);
    pn[3] = COleVariant(y2);
    pn[2] = COleVariant(str);
    pn[1] = COleVariant(color);
    pn[0] = COleVariant(sim);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"FindStrExS",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,7,&vResult);
    if (SUCCEEDED(hr))
    {
        return  CString(vResult.bstrVal);
    }
    return  _T("");
}

long dmsoft::ExitOs(long tpe)
{
    static DISPID dispatch_id = -1;
    MyDispatchDriver spDisp(obj);
    HRESULT hr;
    COleVariant pn[1];
    CComVariant vResult;

    pn[0] = COleVariant(tpe);

    if (dispatch_id == -1)
    {
        spDisp.GetIDOfName(L"ExitOs",&dispatch_id);
    }

    hr = spDisp.InvokeN(dispatch_id,pn,1,&vResult);
    if (SUCCEEDED(hr))
    {
        return vResult.lVal;
    }
    return 0;
}

