/* Old func_XXXXXXXX names still called from C (extern "C") after the function got a real name in
   symbol_addrs.txt (parallel lanes, 2026-10-14). Cleanup: declare the real callee and drop the line. */
func_001089D0 = 0x001089D0; /* Save__9CFlagWorkPUc (CMenuMgr) */
func_0024F5C0 = 0x0024F5C0; /* Func24F5C0__15CTaskList24F5C0Pvi (CGameDBMgr) */
func_0024F2E8 = 0x0024F2E8; /* __nw__5CTaskUi (CGameDBMgr) */
func_00248E48 = 0x00248E48; /* Func248E48__FPCc (CMenuMgr) */
func_001A3840 = 0x001A3840; /* Select__11CStatusItemi (CMenuCommon) */
func_001A0C58 = 0x001A0C58; /* Release__19CStatusWinSub1A0A10 (CMenuMgr) */
/* Two names for one function after merging lanes 1 and 3: the alias is what the other
   unit calls; unify the class/declaration and drop the line. */
Func108700__15CFlagWork108700 = 0x00108700; /* = Func108700__9CFlagWork */
Func129D90__18CGameMainSub129D90 = 0x00129D90; /* = Func129D90__12CSndWorkReal */
Func130138__8CSvmWorkPCc = 0x00130138; /* = Init130138__8CSvmWorki */
Func1B4CD0__8CMenuMgri = 0x001B4CD0; /* = GetEntry0__17CMenuMgrSub1B4768i */
Func1B9B30__10CLayoutRes = 0x001B9B30; /* = Release__19CLayoutResSub1B8748 */
Func1B9B80__10CLayoutResi = 0x001B9B80; /* = Find__19CLayoutResSub1B8748PCc */
Func24B600__FPcPCci = 0x0024B600; /* = strncpy */
Func24F2E8__Fi = 0x0024F2E8; /* = __nw__5CTaskUi */
Func24F5C0__10CResMgr24FPvi = 0x0024F5C0; /* = Func24F5C0__15CTaskList24F5C0Pvi */
/* Old func_ names lane 2 calls, named by lane 1 (merge 2026-10-14) */
func_001456A8 = 0x001456A8; /* Func1456A8__Fi */
func_001884B0 = 0x001884B0; /* Clear1884B0__11CChrBodyWin */
func_0019C0F0 = 0x0019C0F0; /* Func19C0F0__20CStatusBaseSub19B8C8 */
/* Merge of lane 2 round 2 (2026-10-14): second names for one function */
Func193D68__14CMenuSub193D68 = 0x00193D68; /* = Func193D68__19CMenuAsksavequitWin */
Func289140__FPCc = 0x00289140; /* = atol */
/* Old func_ names lane 2 round 2 calls (extern "C"), named on main */
func_00108700 = 0x00108700; /* Func108700__9CFlagWork */
func_001087F8 = 0x001087F8; /* CopyFrom__9CFlagWorkP9CFlagWork */
func_00109158 = 0x00109158; /* GetStr__9CFlagWorki */
func_00129250 = 0x00129250; /* SetPlaying__12CSndWorkRealii */
func_00145808 = 0x00145808; /* FindFlagIdByName__FPCc */
func_0016C6D8 = 0x0016C6D8; /* FindInterfIndex__Fi */
func_00178938 = 0x00178938; /* SetUnk60__26CMenuLoadMemorialSub178778f */
func_00179578 = 0x00179578; /* SetUnk60__26CMenuLoadMemorialSub179568f */
func_00183090 = 0x00183090; /* GetCursorPos__27CMenuTutorSelectedSub182108PfT1 */
func_001971A0 = 0x001971A0; /* PageRow__15CMenuRecordListi */
func_001A0CF0 = 0x001A0CF0; /* Func1A0CF0__10CStatusWinPCc */
func_001A3378 = 0x001A3378; /* Func1A3378__11CStatusItem */
func_001A7658 = 0x001A7658; /* Func1A7658__14CMenuSub1A7658 */
func_001B4ED0 = 0x001B4ED0; /* Func1B4ED0__8CMenuMgri */
func_001B9B30 = 0x001B9B30; /* Release__19CLayoutResSub1B8748 */
func_0022D0A0 = 0x0022D0A0; /* Func22D0A0__Fi */
func_00237570 = 0x00237570; /* Func237570__Fi */
func_00237A88 = 0x00237A88; /* Func237A88__FPvi */
func_00237C30 = 0x00237C30; /* Func237C30__FPv */
func_00238158 = 0x00238158; /* Func238158__FPvi */
func_00248CC8 = 0x00248CC8; /* Func248CC8__8CPushBufiii */
func_002491A8 = 0x002491A8; /* Func2491A8__FPvPCciii */
func_00249248 = 0x00249248; /* Func249248__FPv */
func_00249348 = 0x00249348; /* Func249348__Fv */
func_0024A4C0 = 0x0024A4C0; /* Func24A4C0__FPCc */
func_0024A570 = 0x0024A570; /* Func24A570__FPCcPcT0T0 */
func_0024AF10 = 0x0024AF10; /* Func24AF10__FPvPCc */
func_0024AFE8 = 0x0024AFE8; /* Func24AFE8__FPCcPcii */
func_00251B88 = 0x00251B88; /* Func251B88__Fv */
/* Constructors named by the data split, called by lane 2 factories (in the next unit) by old name */
func_00173A68 = 0x00173A68; /* __9CMenuNews */
func_001900B0 = 0x001900B0; /* __17CMenuReviewResult */
func_00191E28 = 0x00191E28; /* __16CMenuReviewStart */
func_001AA118 = 0x001AA118; /* __13CMenuSysscr26 */
func_001AAB60 = 0x001AAB60; /* __13CMenuSysscr24 */
func_001AB280 = 0x001AB280; /* __13CMenuSysscr22 */
func_001ACCE8 = 0x001ACCE8; /* __13CMenuSysscr05 */
func_001AE488 = 0x001AE488; /* __13CMenuSysscr00 */
func_001AC820 = 0x001AC820; /* __13CMenuSysscr06 (CMenuSysscr07) */
Func145BD0__17CSysFlagSub145BD0 = 0x00145BD0; /* __11CResNameMgr (ISysFlag) */
func_001704F8 = 0x001704F8; /* __11CPhotoDBMgr (IAlbumMgr) */
/* Members of CModelAccResMgr whose units belong to other lanes (2026-10-14, vt lane 1): name
   these in symbol_addrs.txt with the owning unit and drop the lines. */
__9CModelTbl = 0x0010FF40;
_$_9CModelTbl = 0x0010FF88;
__10CMotionTbl = 0x00110AB0;
_$_10CMotionTbl = 0x00110AD0;
__14CSwingBoneRes2 = 0x00111748;
_$_14CSwingBoneRes2 = 0x00111760;
Init18A480__20CChrBodyWinSub18A410 = 0x0018A480; /* __16CMenuChildStatus (CChrBodyWin) */
func_001B2AB0 = 0x001B2AB0; /* __9CMenuBoot (CMenuLoad) */
Init17FD50__16CMenuTutorSelect = 0x0017FD50; /* __18CMenuTutorSelected (CMenuTutorSelect) */
__21CEventMesResSub13DD98 = 0x0013D910; /* member of CEventRes; CEventMesRes unit (other lane) */
_$_21CEventMesResSub13DD98 = 0x0013D958;
func_00245678 = 0x00245678; /* __builtin_vec_new (CMotionRes) */
func_00250840 = 0x00250840; /* Func250840__9CResCachePv (CGameResort) */
/* CMapEffObjRes workers built by CMapEffObj factories (that unit is another lane's): */
__18CMapEffCurtainWorkP10CMapEffObj = 0x0011D2D8;
__15CMapEffLeafWorkP10CMapEffObj = 0x0011ED80;
__14CMapEffFlyWorkP10CMapEffObj = 0x001207C0;
__15CMapEffRainWorkP10CMapEffObj = 0x001215B0;
__15CMapEffSnowWorkP10CMapEffObj = 0x00122440;
__19CMapEffAquariumWorkP10CMapEffObj = 0x00123538;
__17CMapEffBreathWorkP10CMapEffObj = 0x00125938;
__16CMapEffSwingWorkP10CMapEffObj = 0x00126610;
/* Lane vt2 (2026-10-14): old names of constructors in lane vt2's units, still called from other units */
Init1AD668__13CMenuSysscr03 = 0x001AD668; /* = __13CMenuSysscr02 */
Init192D38__12CMenuAsksave = 0x00192D38; /* = __16CMenuAsksavequit */
__27CMenuTutorSelectedSub184CF8 = 0x00184CF8; /* = __9CMenuExam */
func_0018AF98 = 0x0018AF98; /* __11CMenuCommon (CMenuChildStatus.cpp) */
Init1AE800__13CMenuSysscr00 = 0x001AE800; /* = __9CMenuSave */
__27CMenuTutorSelectedSub182098 = 0x00182070; /* = Init__27CMenuTutorSelectedSub182108 (constructor) */
Init146F60__11CResNameMgr = 0x00146F60; /* = __10CGameDBMgr */
/* Task library (0x24F2E8-0x24FA88), include/CProcess.h */
Func8__8CProcess = 0x0024FA80;
Init153410__18CGameMainRes153410i = 0x00153410; /* = __15CGameSeasonPrevi (CGameMain.cpp) */
Notify1__9CFlagWorki = 0x002932F0; /* empty inline virtual (CFlagWork slot 1) */
Notify2__9CFlagWorki = 0x002932F8; /* empty inline virtual (CFlagWork slot 2) */
func_00108320 = 0x00108320; /* __9CFlagWorkii (CMenuMgr.cpp) */
func_00108370 = 0x00108370; /* _$_9CFlagWork (CMenuMgr.cpp) */
func_00108A20 = 0x00108A20; /* Load__9CFlagWorkPUc (CMenuMgr.cpp) */
func_00108EA0 = 0x00108EA0; /* SetStr__9CFlagWorkiPCc (CNameDBMgr.cpp) */
/* merge vt1+vt2 (2026-10-14): old names still called across lanes */
func_001109D8 = 0x001109D8; /* Release__9CModelRes (CModelAccResMgr.cpp) */
/* Constructors in other lanes' units, called from lane vt3's C++ (2026-10-14) */
func_001AC488 = 0x001AC488; /* __13CMenuSysscr07 (CMenuSysscr08) */
Func17DF38__26CMenuLoadMemorialSub17DC50 = 0x0017DF38; /* = __16CMenuTutorSelect (CMenuLoadMemorial) */
Init191338__17CMenuReviewResult = 0x00191338; /* = __17CMenuReviewSelect (CMenuReviewResult) */
func_00194490 = 0x00194490; /* __11CMenuRecord (CMenuAsksavequit) */
func_00189270 = 0x00189270; /* _$_12CChrBodyData (CMenuSysscr31) */
func_0011CAE0 = 0x0011CAE0; /* __13CMapEffObjRes (CMapEffObjRes::Create in CMapEffRes.cpp) */
__11CFont25C230 = 0x0025C230; /* func_0025C230 (font object ctor, library) */
Init1691D0__10CInterfMgr = 0x001691D0; /* func_001691D0 (IInterfMgr unit) */
__12CSndWorkReal = 0x00128870; /* func_00128870 (CSndWorkReal unit) */
__9CEventObj = 0x00132270; /* func_00132270 (CEventObj unit) */
_$_9CEventObj = 0x001327F8; /* func_001327F8 (CEventObj unit) */
_$_12CSndWorkReal = 0x00128BB0; /* func_00128BB0 (CSndWorkReal unit) */
_$_9CSceneSet = 0x0012C4F0; /* func_0012C4F0 (CSceneSet unit) */
func_0012C6A8 = 0x0012C6A8; /* renamed by vt lane 1 (IAlbumMgr.cpp) */
func_0012C5F0 = 0x0012C5F0; /* renamed by vt lane 1 (IAlbumMgr.cpp) */
func_00108448 = 0x00108448; /* now Func108448__9CFlagWorkii (merge vt1-3) */
func_0010CD48 = 0x0010CD48; /* now StopEFontSe__Fv (merge vt1-3) */
func_0010F6F8 = 0x0010F6F8; /* now Release__8CFaceRes (merge vt1-3) */
func_0010FC98 = 0x0010FC98; /* now Func10FC98__14CDiffMotionObj (merge vt1-3) */
func_00111128 = 0x00111128; /* now Find__10CMotionTbli (merge vt1-3) */
func_0012C578 = 0x0012C578; /* now InitA__9CSceneSeti (merge vt1-3) */
func_0012C630 = 0x0012C630; /* now InitB__9CSceneSeti (merge vt1-3) */
func_0012C6F8 = 0x0012C6F8; /* now SetSnd__9CSceneSetP12CSndWorkReal (merge vt1-3) */
func_0012C7E0 = 0x0012C7E0; /* now ReleaseSnd__9CSceneSet (merge vt1-3) */
func_00132208 = 0x00132208; /* now Release__9CEventRes (merge vt1-3) */
func_0013E668 = 0x0013E668; /* now __9CMovieObj (merge vt1-3) */
func_0013E6D8 = 0x0013E6D8; /* now _$_9CMovieObj (merge vt1-3) */
func_0012DFB0 = 0x0012DFB0; /* LoadFile__7CSvmResPCc (CEventRes), lane g1 */
Func10DBD8__8CFaceObj = 0x0010DBD8; /* = Func10DBD8__8CFaceObji (CCharaObj), lane g1 */
Func10DC80__8CFaceObj = 0x0010DC80; /* = Func10DC80__8CFaceObjPii (CCharaObj), lane g1 */
func_0010BF88 = 0x0010BF88; /* __10CEFontWork (g2) */
func_001B9D40 = 0x001B9D40; /* __10CLayoutObj (g2) */
func_001BD188 = 0x001BD188; /* __16CLayoutHourglass (g2) */
func_001BD1E0 = 0x001BD1E0; /* Load__16CLayoutHourglassP10CLayoutResPCc (g2) */
func_001B9D70 = 0x001B9D70; /* _$_10CLayoutObj (g2) */
/* lane g3: TArray constructors (linkonce template code) called from CSceneSet's constructor */
__6CDkArr = 0x00296578; /* func_00296578 */
__7CDkList = 0x002965F8; /* func_002965F8 */
func_001B8760 = 0x001B8760; /* Load__19CLayoutResSub1B8748PCc (CMiniGame6Res calls the old name) */
Func25CFC8__8CSndWorki = 0x0025CFC8; /* lane g3: library, func_0025CFC8 */
func_00196B50 = 0x00196B50; /* Func196B50__15CMenuRecordList (CCommandSelect calls the old name) */
/* lane g5: CMenuRecordWin is CStatusItem (0x1A3xxx); old names other units call */
Func1A39A8__14CMenuRecordWinPfPii = 0x001A39A8; /* = GetPos__11CStatusItemPfT1i */
Func1A3B58__14CMenuRecordWinPfPii = 0x001A3B58; /* = GetUnk10__11CStatusItemPfT1i */
func_001A36B0 = 0x001A36B0; /* = GetUnkE4__11CStatusItemi (CMenuSysscr27) */
func_001A3CF8 = 0x001A3CF8; /* = GetUnkC0__11CStatusItemPfT1i (CMenuCommon) */
func_001A4060 = 0x001A4060; /* = GetUnkEC__11CStatusItemi (CMenuCommon) */
func_00168DC8 = 0x00168DC8; /* = __10CInterfRes (CGameResort) */
Func1A0CF0__10CStatusWinPCc = 0x001A0CF0; /* = Find__19CStatusWinSub1A0A10PCc (D_002A5408 is a CStatusWinSub1A0A10) */
func_001A3DC8 = 0x001A3DC8; /* = SetUnkF0__11CStatusItemii */
func_001A3AF8 = 0x001A3AF8; /* = SetUnk60__11CStatusItemiff (CMenuSysscr27) */
func_0012D1C8 = 0x0012D1C8; /* = NewCharaResObj__Fv (ICharaResMgr) */
Func1A3740__14CMenuRecordWiniPCc = 0x001A3740; /* = SetText__11CStatusItemiPCc */
/* bss words the C code names but no asm references by symbol (r1) */
D_2FD890 = 0x002FD890;
D_2FD894 = 0x002FD894;
/* .bss globals that spimdisasm leaves unnamed (no D_ in undefined_syms_auto.txt) but C now
   references (lane r2, 2026-10-15) */
D_30E180 = 0x0030E180;
D_30E184 = 0x0030E184;
D_30E188 = 0x0030E188;
_ctype_ = 0x002EAE78; /* newlib ctype table (ro_tail); tolower() macro in Unit204500 */
D_310D9C = 0x00310D9C; /* .bss word before D_310DA0, unnamed by spimdisasm (positive %lo) */
func_00111490 = 0x00111490; /* old name used by CCharaObj (interim merge 2026-10-15) */
func_001869C8 = 0x001869C8; /* LoadExamTex__FP8CExamTexPCc (CMenuCommon calls the old name) */
func_00196E90 = 0x00196E90; /* Func196E90__15CMenuRecordListi (CCommandBase calls the old name) */
/* CCharaObj::Func114050 / CallFunc114050 take a float (lane g4, 2026-10-15): old names */
Func114050__9CCharaObjii = 0x00114050; /* = Func114050__9CCharaObjiif */
CallFunc114050__9CCharaObji = 0x00114030; /* = CallFunc114050__9CCharaObjif */
Func1159A0__9CCharaObjii = 0x001159A0; /* = Func1159A0__9CCharaObjiif */
D_2FD9CC = 0x002FD9CC;
D_2FDA08 = 0x002FDA08;
D_316990 = 0x00316990;
D_316992 = 0x00316992;
func_0010D8F8 = 0x0010D8F8; /* old name still called from another unit (interim merge 2) */
func_00110868 = 0x00110868; /* old name still called from another unit (interim merge 2) */
func_001864A8 = 0x001864A8; /* Func1864A8__FPc (CCommandBase calls the old name) */
func_001795F8 = 0x001795F8; /* Update1795F8__26CMenuLoadMemorialSub179568 (CMenuCommon calls the old name) */
func_001789B8 = 0x001789B8; /* Update1789B8__26CMenuLoadMemorialSub178778 (CMenuCommon calls the old name) */
_$_11CFont25C230 = 0x0025C2C0; /* func_0025C2C0 (font object dtor, library) */
func_001A8E28 = 0x001A8E28; /* __13CMenuSysscr27 (CMenuSysscr31 calls the old name) */
func_00150D98 = 0x00150D98; /* Func150D98__10CGameMain2 (CGameResort calls the old name) */
func_0018B880 = 0x0018B880; /* = Func18B880__25CMenuChildStatusSub18B9E0Pcii */
D_2FDA0C = 0x002FDA0C;
func_001E91B8 = 0x001E91B8; /* __8CAppMain, called by old name from CMiniGame6Res (r1) */
func_00185AA0 = 0x00185AA0; /* old name still called from another unit (interim merge 3) */
func_00289118 = 0x00289118; /* old name still called from another unit (interim merge 3) */
func_0011BD00 = 0x0011BD00; /* __10CMapEffRes (CMapRes), lane g1 */
func_001829E8 = 0x001829E8; /* Func1829E8__27CMenuTutorSelectedSub182108i (CMenuMemorial, CMenuSave), lane g1 */
func_0011ADD0 = 0x0011ADD0; /* __7CMapObj (CSceneSet allocates 0x40 bytes and calls the constructor) */
/* EE soft-double libcalls named (lane g4, 2026-10-15): old names for extern "C" callers */
func_00284B98 = 0x00284B98; /* fptodp */
func_00285180 = 0x00285180; /* dpdiv */
func_002852C0 = 0x002852C0; /* dpcmp */
func_00285498 = 0x00285498; /* dptofp */
func_001153E8 = 0x001153E8; /* Func1153E8__9CCharaObj (CGameResort calls the old name) */
func_001A40C8 = 0x001A40C8; /* = Func1A40C8__11CStatusItem */
D_2FDA14 = 0x002FDA14;
D_2FDA28 = 0x002FDA28;
D_30E144 = 0x0030E144;
D_30E148 = 0x0030E148;
func_0010F348 = 0x0010F348; /* old name still called from another unit (merge interim 4) */
func_00110DC8 = 0x00110DC8; /* old name still called from another unit (merge interim 4) */
func_00112710 = 0x00112710; /* old name still called from another unit (merge interim 4) */
func_00115278 = 0x00115278; /* old name still called from another unit (merge interim 4) */
func_00119230 = 0x00119230; /* old name still called from another unit (merge interim 4) */
func_00127E98 = 0x00127E98; /* old name still called from another unit (merge interim 4) */
func_001A0A98 = 0x001A0A98; /* old name still called from another unit (merge interim 4) */
func_001B5FE0 = 0x001B5FE0; /* old name still called from another unit (merge interim 4) */
Func135A28__15CEventObj135A28 = 0x00135A28; /* Update135A28__9CEventObj (g2) */
__10CUnk29A558 = 0x0029A478; /* func_0029A478, TArray ctor in CMapDBExpr ctor (g2) */
func_001A72D8 = 0x001A72D8; /* = __14CMenuSub1A7658P10CUnk1A4298 (CMenuContinue) */
/* r4: raw .bss words used by Unit221008 (VU1 packet helpers) */
D_33DCFC = 0x0033DCFC;
D_33DD0C = 0x0033DD0C;
D_33DD20 = 0x0033DD20;
D_33DD24 = 0x0033DD24;
D_33DD2C = 0x0033DD2C;
func_00179198 = 0x00179198; /* old name still called from another unit (merge interim 5) */
/* .bss words lane r3 references by name (no asm symbol) */
D_33D704 = 0x0033D704;
D_33D6F0 = 0x0033D6F0;
D_33D6F4 = 0x0033D6F4;
D_33D990 = 0x0033D990;
D_33D994 = 0x0033D994;
D_33D998 = 0x0033D998;
D_33D9A4 = 0x0033D9A4;
D_33D9AC = 0x0033D9AC;
D_33D9BC = 0x0033D9BC;
D_33DB80 = 0x0033DB80;
D_33DB84 = 0x0033DB84;
D_33D9A0 = 0x0033D9A0;
D_33DCF0 = 0x0033DCF0;
D_33DCE4 = 0x0033DCE4;
D_33DCE8 = 0x0033DCE8;
func_0017D3B0 = 0x0017D3B0; /* Draw17D3B0__26CMenuLoadMemorialSub17D160 (CMenuRecord calls the old name) */
func_00118210 = 0x00118210; /* __8CMapAttr (CMapRes calls the old name) */
func_0018A410 = 0x0018A410; /* Close__20CChrBodyWinSub18A410 (CMenuChildStatus calls the old name) */
func_0018A1F0 = 0x0018A1F0; /* Draw18A1F0__15CChildStatusObj (CMenuChildStatus, CMenuSysscr27 call the old name) */
/* r4: raw .bss words of the Unit224D58 VU1 state */
D_33DE9C = 0x0033DE9C;
D_33DEA0 = 0x0033DEA0;
D_33DEAC = 0x0033DEAC;
D_33DEB4 = 0x0033DEB4;
D_33F5D0 = 0x0033F5D0;
D_33F5E8 = 0x0033F5E8;
D_33F610 = 0x0033F610;
D_33FE80 = 0x0033FE80;
D_3401D0 = 0x003401D0;
func_00118448 = 0x00118448; /* old name still called from another unit (merge interim 6) */
func_0017A370 = 0x0017A370; /* old name still called from another unit (merge interim 6) */
func_001866D0 = 0x001866D0; /* old name still called from another unit (merge interim 6) */
func_001884F0 = 0x001884F0; /* old name still called from another unit (merge interim 6) */
func_0019FA50 = 0x0019FA50; /* old name still called from another unit (merge interim 6) */
func_0019FC30 = 0x0019FC30; /* old name still called from another unit (merge interim 6) */
func_001A3E28 = 0x001A3E28; /* old name still called from another unit (merge interim 6) */
func_001A3EA8 = 0x001A3EA8; /* old name still called from another unit (merge interim 6) */
func_001974F8 = 0x001974F8; /* old name still called from another unit (merge g1 final) */
func_001976A0 = 0x001976A0; /* old name still called from another unit (merge g1 final) */
func_00197950 = 0x00197950; /* old name still called from another unit (merge g1 final) */
func_00197AE0 = 0x00197AE0; /* old name still called from another unit (merge g1 final) */
func_00197FA8 = 0x00197FA8; /* old name still called from another unit (merge g1 final) */
MemorialMenuFunc17B4A0__Fv = 0x0017B4A0; /* = Func17B4A0__26CMenuLoadMemorialSub17B3A0; CCommandSelect calls it extern "C" with this name (merge g1 final) */
Func24AB90__FPCcT0 = 0x0024AB90; /* C++ name CUserFlagMgr uses; Dk2497C0 defines it as func_0024AB90 */
Func24ABE0__FPcPCc = 0x0024ABE0; /* C++ name CUserFlagMgr uses; Dk2497C0 defines it as func_0024ABE0 */
func_00135BE0 = 0x00135BE0; /* PlayMovie135BE0__9CEventObjP12CEventObjUnk (g2), called from CDemoMain */
func_00150A70 = 0x00150A70; /* __9CGameMaini (CGameDBMgr calls the old name) */
Func171448__11CPhotoDBMgrPcii = 0x00171448; /* CPhotoDBMgr vtable slot 6 = GetName__20CPhotoDBMgrSub171448Pcii */
Parse1711A0__20CPhotoDBMgrSub1714C8P9CPhotoReciPc = 0x001711A0; /* PMF target in 0x170B18 (matched as CPhotoDBMgrSub1711A0::Parse) */
Parse171378__20CPhotoDBMgrSub1714C8P9CPhotoReciPc = 0x00171378; /* PMF target in 0x170B18 (matched as CPhotoDBMgrSub171378::Parse) */
_vt$11CStatusWinV = 0x002C1AE8; /* = _vt$10CStatusWin (CStatusWin.cpp calls the class CStatusWinV) */
Init__20CStatusBaseSub19C400i = 0x0019C400; /* = Init__20CStatusBaseSub19C400 (CStatusWin passes the new value) */
/* .bss words lane r5 references by name (no asm symbol) */
D_37CA8C = 0x0037CA8C;
D_37CA74 = 0x0037CA74;
D_37CA78 = 0x0037CA78;
D_386E24 = 0x00386E24;
D_388F28 = 0x00388F28;
D_38F004 = 0x0038F004;
func_00252E18 = 0x00252E18; /* old name still called from another unit (lane d2) */
func_00253048 = 0x00253048; /* old name still called from another unit (lane d2) */
func_002539A0 = 0x002539A0; /* old name still called from another unit (lane d2) */
func_00253A38 = 0x00253A38; /* old name still called from another unit (lane d2) */
func_002554E0 = 0x002554E0; /* old name still called from another unit (lane d2) */
func_00255A30 = 0x00255A30; /* old name still called from another unit (lane d2) */
func_00255E18 = 0x00255E18; /* old name still called from another unit (lane d2) */
func_00256260 = 0x00256260; /* old name still called from another unit (lane d2) */
func_00256648 = 0x00256648; /* old name still called from another unit (lane d2) */
func_00256668 = 0x00256668; /* old name still called from another unit (lane d2) */
func_002564B8 = 0x002564B8; /* old name still called from another unit (lane d2) */
func_002565B0 = 0x002565B0; /* old name still called from another unit (lane d2) */
func_00256930 = 0x00256930; /* old name still called from another unit (lane d2) */
func_00256988 = 0x00256988; /* old name still called from another unit (lane d2) */
/* d3: .bss words of the SDK libraries that spimdisasm left unnamed (lui 0x42 + negative %lo) */
D_41A800 = 0x0041A800; /* libcdvd: callback function */
D_41A804 = 0x0041A804; /* its $gp */
D_41A808 = 0x0041A808;
D_41A80C = 0x0041A80C;
D_41A810 = 0x0041A810;
D_41AAE8 = 0x0041AAE8;
D_41AAEC = 0x0041AAEC;
D_41AAF0 = 0x0041AAF0;
func_001170F0 = 0x001170F0; /* old name still called from another unit (merge interim 7) */
func_0012C4A8 = 0x0012C4A8; /* old name still called from another unit (merge interim 7) */
func_001BA0A0 = 0x001BA0A0; /* Reset__19CLayoutObjSub1BA0A0 (g2), called from CLayoutHourglass::Draw1BD420 */
func_001BBD08 = 0x001BBD08; /* Upload__11CLayoutDrawP15CLayoutImageRef (g2), called with (this, entry, a) from CLayoutObj::Func1BA210 */
D_38EF48 = 0x0038EF48;
D_38EF78 = 0x0038EF78;
D_38EF88 = 0x0038EF88;
D_38EF8C = 0x0038EF8C;
D_38EF98 = 0x0038EF98;
D_38EF9C = 0x0038EF9C;
D_38EFA0 = 0x0038EFA0;
D_38EFA4 = 0x0038EFA4;
D_38EFB0 = 0x0038EFB0;
D_38EFB4 = 0x0038EFB4;
D_38EFB8 = 0x0038EFB8;
D_38EFBC = 0x0038EFBC;
D_38EFC0 = 0x0038EFC0;
D_38EFC4 = 0x0038EFC4;
D_38EFC8 = 0x0038EFC8;
D_38EFCC = 0x0038EFCC;
D_38EFE4 = 0x0038EFE4;
D_388F2C = 0x00388F2C;
D_38EFA8 = 0x0038EFA8;
D_38EFAC = 0x0038EFAC;
func_0019B938 = 0x0019B938; /* = Reset19B938__20CStatusBaseSub19B8C8 (CMenuMgr) */
func_0025A060 = 0x0025A060; /* old name still called from another unit (lane d2) */
func_0025C438 = 0x0025C438; /* old name still called from another unit (lane d2) */
func_0025C488 = 0x0025C488; /* old name still called from another unit (lane d2) */
func_0025CEA0 = 0x0025CEA0; /* old name still called from another unit (lane d2) */
func_0025C910 = 0x0025C910; /* old name still called from another unit (lane d2) */
func_0025CE30 = 0x0025CE30; /* old name still called from another unit (lane d2) */
D_41A814 = 0x0041A814;
D_41A818 = 0x0041A818;
D_41C860 = 0x0041C860; /* .bss word before D_41C868 (libkernel thread-op queue semaphore), unnamed by spimdisasm (lane d4) */
D_420400 = 0x00420400; /* .bss word holding the gp value interrupt handlers run with (libkernel), unnamed by spimdisasm (lane d4) */
D_41D194 = 0x0041D194; /* .bss word before D_41D198 (libkernel), unnamed by spimdisasm (lane d4) */
/* lane L3: RTTI names (.rodata) used by the C typeinfo functions in src/Lib29*.cpp */
D_002D51F0 = 0x002D51F0;
D_002D5660 = 0x002D5660;
D_002D5EC8 = 0x002D5EC8;
D_002D8C98 = 0x002D8C98;
D_002D8E90 = 0x002D8E90;
D_002D8F08 = 0x002D8F08;
D_002D98E8 = 0x002D98E8;
D_002D9AC0 = 0x002D9AC0;
D_002DA038 = 0x002DA038;
D_002DA048 = 0x002DA048;
D_002DA430 = 0x002DA430;
D_002DA478 = 0x002DA478;
D_002DA520 = 0x002DA520;
D_002DA598 = 0x002DA598;
D_002DA638 = 0x002DA638;
D_002DA798 = 0x002DA798;
D_002DAA98 = 0x002DAA98;
D_002DAB20 = 0x002DAB20;
D_002DAD88 = 0x002DAD88;
D_002DB540 = 0x002DB540;
D_002DB5D0 = 0x002DB5D0;
D_002DBAB0 = 0x002DBAB0;
D_002DBB18 = 0x002DBB18;
D_002DBBA8 = 0x002DBBA8;
D_002DBC68 = 0x002DBC68;
D_002DBD20 = 0x002DBD20;
D_002DBDA8 = 0x002DBDA8;
D_002DBE28 = 0x002DBE28;
D_002DBE68 = 0x002DBE68;
D_002DD7C8 = 0x002DD7C8;
D_002DF0E8 = 0x002DF0E8;
D_002DF180 = 0x002DF180;
D_002DF1F8 = 0x002DF1F8;
D_002DF2D0 = 0x002DF2D0;
D_002DF358 = 0x002DF358;
D_002DF398 = 0x002DF398;
D_002DF3E8 = 0x002DF3E8;
D_002DF468 = 0x002DF468;
D_002DF4E8 = 0x002DF4E8;
D_002DF528 = 0x002DF528;
D_002DF578 = 0x002DF578;
D_002DF5F8 = 0x002DF5F8;
D_002DF678 = 0x002DF678;
D_002DF6B0 = 0x002DF6B0;
D_002DF700 = 0x002DF700;
D_002DF780 = 0x002DF780;
D_002DF800 = 0x002DF800;
D_002DF8B0 = 0x002DF8B0;
D_002DF930 = 0x002DF930;
D_002DF970 = 0x002DF970;
D_002DFB60 = 0x002DFB60;
D_002DFCA8 = 0x002DFCA8;
D_002DFD90 = 0x002DFD90;
D_002DFDA0 = 0x002DFDA0;
D_002E0BD8 = 0x002E0BD8;
D_002E0D40 = 0x002E0D40;
func_001B6570 = 0x001B6570; /* old name still called from another unit (merge interim 8) */
func_0025DBB8 = 0x0025DBB8; /* old name still called from another unit (merge interim 8) */
func_00280260 = 0x00280260; /* old name still called from another unit (merge interim 8) */
/* lane L2: soft-float subtract the compiler calls by name (func_00284E90, lane L1's unit); __fixdfdi's -a */
dpsub = 0x00284E90;
D_423F00 = 0x00423F00; /* Dk27C020 free-list head after D_423B00[64] (lane w1) */
D_424518 = 0x00424518; /* lane w2: libgcc dwarf_reg_size_table (0x284438 copy_reg), not a splat symbol */
dpmul = 0x00284EF8; /* lane w2: soft-float multiply the compiler calls by name (newlib _mprec_log10 0x292928) */
dpadd = 0x00284E38; /* lane w2: soft-float add the compiler calls by name (__floatdidf 0x287F98) */
litodp = 0x00285310; /* lane w2: soft-float int to double the compiler calls by name (__floatdidf 0x287F98) */
D_41D1A0 = 0x0041D1A0; /* lane w2: SIF cmd server register address (Dk2752B8 0x275398), not a splat symbol */
__muldi3 = 0x00281B20; /* lane w2: libgcc __muldi3 (func_00281B20, Dk280098), called by GCC for 64-bit multiplies in the C newlib units */
D_33D9A8 = 0x0033D9A8; /* lane x1: Unit21D820 0x21E4A0, not a splat symbol */
func_001513D0 = 0x001513D0; /* Func1513D0__9CGameMainiii (CGameSchedule) */
__udivdi3 = 0x002828C0; /* libgcc, called by compiled 64-bit division (lane cv, _vfprintf_r) */
__umoddi3 = 0x00282E40; /* libgcc */
dptoli = 0x002853C8; /* libgcc soft-float double to int the compiler calls by name (lane cv, _dtoa_r) */
__floatdidf = 0x00287F98; /* libgcc2 (func_00287F98), called by compiled long-to-double (lane cv, _strtod_r) */
__fixdfdi = 0x002930A0; /* libgcc2, double-to-long */
/* Lane sm: the kanji-select menus still call the list machine by its old name. */
func_001A73B0 = 0x001A73B0; /* = Update1A73B0__14CMenuSub1A7658 */
dptoul = 0x002854F0; /* = func_002854F0 (fp-bit __fixunsdfsi, the soft-float libcall for (u32)double) */
D_316200 = 0x00316200; /* lane z1: free Node20 list head right before D_316204 (Unit20A410 0x20B5A0) */
__8CSndWork = 0x0025C230; /* func_0025C230 (sound object ctor), CInterfMgr members (lane lb) */
_$_8CSndWork = 0x0025C2C0; /* func_0025C2C0 (sound object dtor), CInterfMgr members (lane lb) */
