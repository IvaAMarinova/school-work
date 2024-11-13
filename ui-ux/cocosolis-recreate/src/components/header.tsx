import { useState, useEffect } from "react";
import { Search, CartSolid, User, Menu } from "@mynaui/icons-react";

interface HeaderProps {
    refs: {
        hair: React.RefObject<HTMLDivElement>;
        skin: React.RefObject<HTMLDivElement>;
        face: React.RefObject<HTMLDivElement>;
        bronze: React.RefObject<HTMLDivElement>;
        tan: React.RefObject<HTMLDivElement>;
        shine: React.RefObject<HTMLDivElement>;
        spf: React.RefObject<HTMLDivElement>;
    };
}

function Header({ refs }: HeaderProps) {
    const [showSecondHeader, setShowSecondHeader] = useState(false);
    const [activeSection, setActiveSection] = useState<string>("");

    useEffect(() => {
        const handleScroll = () => {
            setShowSecondHeader(window.scrollY > 100);
        };

        window.addEventListener("scroll", handleScroll);
        return () => {
            window.removeEventListener("scroll", handleScroll);
        };
    }, []);

    const scrollToSection = (sectionRef: React.RefObject<HTMLDivElement>, sectionName: string) => {
        setActiveSection(sectionName);
        if (sectionRef && sectionRef.current) {
            sectionRef.current.scrollIntoView({ behavior: 'smooth' });
        }
    };

    return (
        <header className="w-full">
            <div className="fixed top-0 w-full text-sm bg-[#DEBAA7] text-white p-2 text-center z-50">
                <span>БЕЗПЛАТНА ДОСТАВКА ДО 2 РАБОТНИ ДНИ</span>
            </div>

            <div className="fixed top-6 w-full bg-white border-b border-gray-300 px-4 py-2 lg:px-8 z-40">
                <div className="flex flex-row items-center justify-center w-full gap-4 mt-3">
                    <div className="header-logo">
                        <img src="https://cocosolis.com/wp-content/uploads/cocosolis-logo.svg" alt="COCOSOLIS" className="w-32" />
                    </div>

                    <nav className="hidden md:flex gap-6">
                        <span className="text-gray-700 uppercase">Начало</span>
                        <span className="text-gray-700 uppercase">Продукти</span>
                        <span className="text-gray-700 uppercase">CLUB</span>
                        <span className="text-gray-700 uppercase">За нас</span>
                        <span className="text-gray-700 uppercase">Контакти</span>
                    </nav>

                    <div className="flex items-center gap-4">
                        <Menu />
                        <Search />
                        <CartSolid className="text-[#816c65] text-xl" />
                        <User />
                        <span className="text-gray-700 uppercase">Влез в профил</span>
                    </div>
                </div>
            </div>

            {showSecondHeader && (
                <div className="fixed top-16 w-full mt-7 pt-3 pb-2 border-t bg-white border-b border-gray-300 z-30">
                    <nav className="flex justify-center gap-6 text-sm text-center text-gray-700 uppercase py-2">
                        <span
                            className={`cursor-pointer ${activeSection === "face" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.face, "face")}
                        >
                            Лице
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "hair" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.hair, "hair")}
                        >
                            Коса
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "skin" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.skin, "skin")}
                        >
                            Кожа
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "bronze" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.bronze, "bronze")}
                        >
                            Автобронзанти
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "shine" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.shine, "shine")}
                        >
                            Блясък
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "tan" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.tan, "tan")}
                        >
                            Тен
                        </span>
                        <span
                            className={`cursor-pointer ${activeSection === "spf" ? "font-bold" : ""}`}
                            onClick={() => scrollToSection(refs.spf, "spf")}
                        >
                            SPF
                        </span>
                    </nav>
                </div>
            )}
        </header>
    );
}

export default Header;
