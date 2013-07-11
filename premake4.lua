project "Tizen"

  kind "ConsoleApp"
  language "C#"
  location "."
  debugdir "."
  
  files { "Tizen.cs", "./*.lua" }

  links { "Bridge", "Generator", "Parser" }


project "Tizen.Tests"

  kind     "ConsoleApp"
  language "C#"
  location "."
  
  dependson "Tizen"

  files
  {
      "*.lua"
  }
