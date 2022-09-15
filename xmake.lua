-- 项目信息 --
set_project("RssAnalyser")
set_languages("c99", "cxx11")
set_xmakever("2.5.7")

add_rules("mode.debug", "mode.release")

--外部依赖 --
--使用镜像加速依赖包的下载
function mirror(url)
    return url:gsub("github.com", "hub.fastgit.org")
end
--tinyxml2 | https://github.com/leethomason/tinyxml2 |解析xml|Zlib license
add_requires("tinyxml2")

-- 构建目标 --
-- 导入头文件
add_includedirs("/src/include")
-- 静态库
target("LibRssAnalyser")
set_kind("static")
add_packages("tinyxml2")
add_files("src/LibRssAnalyser.cpp")
-- 测试程序
target("RssAnalyser")
set_kind("binary")
add_packages("tinyxml2", {links = {}})
add_deps("LibRssAnalyser")
add_files("test/RssAnalyser.cpp")