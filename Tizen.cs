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
            options.Headers.Add("FAppApp.h");
            options.GeneratorKind = LanguageGeneratorKind.CSharp;
            options.IncludeDirs.Add("../../../examples/Tizen/osp");
            options.GenerateLibraryNamespace = false;
            options.OutputDir = "gen_csharp";
        }

        public void Preprocess(Driver driver, Library lib)
        {
            lib.IgnoreHeadersWithName("FBase.h");
            lib.IgnoreHeadersWithName("FBaseString.h");
            lib.IgnoreHeadersWithName("FBaseObject.h");
            lib.IgnoreHeadersWithName("FOspCompat.h");

            lib.IgnoreClassWithName("Tizen::Base::Object");
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

    [TypeMap("Tizen::Base::String")]
    class StringMap : Types.Std.String
    {
        
    }
}
