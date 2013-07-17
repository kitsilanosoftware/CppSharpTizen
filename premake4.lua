project "Tizen"

  kind "ConsoleApp"
  language "C#"
  location "."
  debugdir "."
  
  files { "Tizen.cs", "./*.lua" }

  links { "CppSharp.AST", "CppSharp.Generator", "CppSharp.Parser" }


project "Tizen.Tests"

  kind     "ConsoleApp"
  language "C#"
  location "."
  
  dependson "Tizen"

  files
  {
      "*.lua"
  }
