import os;
import sys;
import subprocess;
import platform;
import requests;
from tqdm import tqdm;

class Vulkan:
    vulkandownloadpath = "../Thirdparty/VulkanSDK/";
    vulkanversion = "1.2.198.1";
    filename = "";

    @classmethod
    def Installed(cls) :
        vulkansdk = os.environ.get("VULKAN_SDK")
        if(vulkansdk == None) :
            print("Vulkan SDK is not installed on this machine");
            return False;
        else :
            print(f"Vulkan SDK is located under {vulkansdk}");
            return True;
    
    @classmethod
    def Install(cls) :

        vurl = "";
        vpath = ""; 

        if(platform.system() == "Windows") :
            vurl = f"https://sdk.lunarg.com/sdk/download/{cls.vulkanversion}/windows/VulkanSDK-{cls.vulkanversion}-Installer.exe";
            vpath = f"{cls.vulkandownloadpath}/VulkanSDK-{cls.vulkanversion}-Installer.exe";
            
        if(platform.system() == "Linux") : 
            vurl = f"https://sdk.lunarg.com/sdk/download/{cls.vulkanversion}/linux/vulkansdk-linux-x86_64-{cls.vulkanversion}-Installer.tar.gz";
            vpath = f"{cls.vulkandownloadpath}/VulkanSDK-{cls.vulkanversion}-Installer.tar.gz";

        if(platform.system() == "Darwin") :
            vurl = f"https://sdk.lunarg.com/sdk/download/{cls.vulkanversion}/mac/vulkansdk-macos-{cls.vulkanversion}-Installer.dmg";
            vpath = f"{cls.vulkandownloadpath}/VulkanSDK-{cls.vulkanversion}-Installer.dmg";

        print("Downloading Vulkan SDK installer...");
        cls.Download(vurl, vpath);
        os.startfile(os.path.abspath(vpath));

        print("Install vulkan and run this script again.");
        quit();

    @classmethod
    def Download(cls, url, filename) :
        resp = requests.get(url, stream=True)
        total = int(resp.headers.get("content-length", 0))
        with open(filename, "wb") as file, tqdm(
            desc=filename,
            total=total,
            unit="iB",
            unit_scale=True,
            unit_divisor=1024,
        ) as bar :
            for data in resp.iter_content(chunk_size=1024) :
                size = file.write(data);
                bar.update(size);

class Premake:
    binpath = "../Thirdparty/premake-core/bin";

    @classmethod
    def Built(cls) :
        if(os.path.abspath(cls.binpath) == False) :
            print("Premake is not built/generated");
            return False;
        else :
            print("Premake is built/generated");
            return True;

    @classmethod
    def Build(cls) :
        scriptdir = os.getcwd();

        if(platform.system() == "Windows") :
            os.chdir("../Thirdparty/premake-core");
            subprocess.call([os.path.abspath("Bootstrap.bat")]);
            os.chdir(scriptdir);

        if(platform.system() == "Linux") : 
            os.chdir("../Thirdparty/premake-core");
            subprocess.call([os.path.abspath("make -f Bootstrap.mak linux")]);
            os.chdir(scriptdir);

        if(platform.system() == "Darwin") :
            os.chdir("../Thirdparty/premake-core");
            subprocess.call([os.path.abspath("make -f Bootstrap.mak osx")]);
            os.chdir(scriptdir);

    @classmethod
    def Generate(cls) :
        if(platform.system() == "Windows") : 
            subprocess.call([os.path.abspath("_vs2022.bat")]);
            
        if(platform.system() == "Linux") : 
            subprocess.call([os.path.abspath("_makefile.sh")]);

        if(platform.system() == "Darwin") : 
            subprocess.call([os.path.abspath("_xcode.sh")]);

if(Vulkan.Installed() == False) :
    Vulkan.Install();

if(Premake.Built() == False) :
    Premake.Build();

Premake.Generate();