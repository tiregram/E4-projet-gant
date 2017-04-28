// Copyright 2014-2016 Allegorithmic, Inc. All Rights Reserved.
using UnrealBuildTool;

public class SubstanceEditor : ModuleRules
{
	public SubstanceEditor(TargetInfo Target)
	{
		// PCH file
		bEnforceIWYU = false;

		// include paths
		PrivateIncludePaths.Add("SubstanceEditor/Private");
		PrivateIncludePaths.Add("SubstanceCore/Private/include");
		PrivateIncludePaths.Add("SubstanceCore/Private/framework/include");

		// module dependencies
		PublicDependencyModuleNames.AddRange(new string[] {
				"AssetTools",
				"BlueprintGraph",
				"ContentBrowser",
				"Core",
				"CoreUObject",
				"DesktopPlatform",
				"EditorStyle",
				"EditorWidgets",
				"Engine",
				"InputCore",
				"KismetCompiler",
				"LevelEditor",
				"MainFrame",
				"PropertyEditor",
				"RenderCore",
				"RHI",
				"ShaderCore",
				"SubstanceCore",
				"TextureEditor",
				"UnrealEd"
			});
			
		PrivateDependencyModuleNames.AddRange(new string[] {
                "AppFramework",
				"Slate",
                "SlateCore",
                "Projects",
				"WorkspaceMenuStructure"
        });
	}
}
