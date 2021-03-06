﻿using CppSharp.AST;
using CppSharp.Generators;
using CppSharp.Passes;
using CppSharp.Types;

namespace CppSharp
{
    class Tizen : ILibrary
    {
        public void Setup(Driver driver)
        {
            var options = driver.Options;
            options.LibraryName = "Tizen";
            
            //options.GeneratorKind = LanguageGeneratorKind.CPlusPlusCLI;
            //options.OutputDir = "gen";

            options.GeneratorKind = LanguageGeneratorKind.CSharp;
            options.OutputDir = "../../../../HelloTizen/Tizen/src";

            options.IncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\osp\\");
            options.GenerateLibraryNamespace = false;

            options.Headers.Add("FBaseDataTypes.h");
            //options.Headers.Add("FAppApp.h");
            options.Headers.Add("FAppAppRegistry.h");
            //options.Headers.Add("FAppUiApp.h");

            options.LibraryDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\lib\\osp\\");
            options.Libraries.Add("libosp-uifw.so.1.2.1.0");
            options.Libraries.Add("libosp-appfw.so.1.2.1.0");

            // We appear to need these Clang built-in headers FIRST for size_t to defined.   And using the
            // "proper-way" of enabling built-in includes doesn't work, because the include path ends up
            // at the end of the list, which isn't early enough.   So, we do this manually.   This is
            // also depend on the Junction of these files directly into the output directory so that they
            // are available at runtime.   With these being hard-coded now that doesn't make sense anymore,
            // so I should just undo this.
            //
            // Debugging this was a pain, because options.Verbose didn't work for me.    I had to add
            // "-v" as a hardcoded setting in Parser.cpp.
            //
            // Why did I even have to venture into this messy place?   Why are the Tizen headers not defining
            // size_t, ptrdiff_t, etc?   Are they built into the compiler?   Do I need to pass some extra
            // settings into Clang which do something equivalent?    Or is using the built-in Clang headers
            // the recommended way of handling this?
            options.NoBuiltinIncludes = false;
            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\build\\vs2012\\lib\\lib\\clang\\3.4\\include");

            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\");
            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\linux\\");
            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\C++\\4.5.3\\");
            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\C++\\4.5.3\\tr1\\");
            options.SystemIncludeDirs.Add("C:\\SourceTreeProjects\\CppSharp\\examples\\Tizen\\tizen-sdk\\platforms\\tizen2.1\\rootstraps\\tizen-emulator-2.1.native\\usr\\include\\C++\\4.5.3\\i586-tizen-linux\\");

            options.TargetTriple = "i586-tizen-linux";
            options.MicrosoftMode = false;
            options.NoStandardIncludes = true;
            options.Verbose = true;
            
            /*
            options.Headers.Add("FSysIScreenEventListener.h");
            options.Headers.Add("FSysPowerManager.h");
            options.Headers.Add("FUiControl.h");

            options.Headers.Add("FUiContainer.h");

            options.Headers.Add("FUiCtrlButton.h");
            options.Headers.Add("FUiCtrlForm.h");
            options.Headers.Add("FUiCtrlFrame.h");
            options.Headers.Add("FUiCtrlIFormBackEventListener.h");
            options.Headers.Add("FUiCtrlPanel.h");
            options.Headers.Add("FUiIActionEventListener.h");
            options.Headers.Add("FUiScenesIFormFactory.h");
            options.Headers.Add("FUiScenesIPanelFactory.h");
            options.Headers.Add("FUiScenesISceneEventListener.h");
            options.Headers.Add("FUiWindow.h");

            options.Headers.Add("FBaseBuffer.h");
            options.Headers.Add("FBaseDataType.h");
            options.Headers.Add("FBaseObject.h");
            options.Headers.Add("FBaseString.h");
*/
        }

        public void Preprocess(Driver driver, Library lib)
        {
            // FBase.h is just an aggregrating header file, which also contains
            // a block-comment for the Base namespace.   We don't need to generate
            // any code for it.
            lib.IgnoreHeadersWithName("FBase.h");

            // We are mapping Tizen::Base::String to a standard .NET string class,
            // so don't need to generate any code for that either.
            //lib.IgnoreHeadersWithName("FBaseString.h");

            // Don't know why we are ignoring these.   Ask Joao.
            //lib.IgnoreHeadersWithName("FBaseObject.h");
            //lib.IgnoreHeadersWithName("FOspCompat.h");
            //lib.IgnoreClassWithName("Tizen::Base::Object");
        }

        public void Postprocess(Library lib)
        {

        }

        public void SetupPasses(Driver driver, PassBuilder p)
        {
            p.FunctionToInstanceMethod();
            p.FunctionToStaticMethod();
        }

        static class Program
        {
            public static void Main(string[] args)
            {
                ConsoleDriver.Run(new Tizen());
            }
        }
    }

    // Map Tizen's string class to a standard .NET string class.
    //[TypeMap("Tizen::Base::String")]
    //class StringMap : Types.Std.String
    //{
    //}

}
