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
__8CSvmWork = 0x0012E608; /* func_0012E608 */
func_001AC488 = 0x001AC488; /* __13CMenuSysscr07 (CMenuSysscr08) */
Func17DF38__26CMenuLoadMemorialSub17DC50 = 0x0017DF38; /* = __16CMenuTutorSelect (CMenuLoadMemorial) */
Init191338__17CMenuReviewResult = 0x00191338; /* = __17CMenuReviewSelect (CMenuReviewResult) */
func_00194490 = 0x00194490; /* __11CMenuRecord (CMenuAsksavequit) */
func_00189270 = 0x00189270; /* _$_12CChrBodyData (CMenuSysscr31) */
func_0011CAE0 = 0x0011CAE0; /* __13CMapEffObjRes (CMapEffObjRes::Create in CMapEffRes.cpp) */
__11CFont25C230 = 0x0025C230; /* func_0025C230 (font object ctor, library) */
Init1691D0__10CInterfMgr = 0x001691D0; /* func_001691D0 (IInterfMgr unit) */
__12CSndWorkReal = 0x00128870; /* func_00128870 (CSndWorkReal unit) */
__9CSceneSet = 0x0012C4A8; /* func_0012C4A8 (CSceneSet unit) */
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
