
function Footer() {
    return (
        <div className="w-screen">
            <div className="w-full bg-[#009fe3] py-4 flex flex-col items-center text-white text-center space-y-2">
                <div className="flex items-center justify-center space-x-4">
                    <img
                        src="https://cocosolis.com/wp-content/uploads/SOS_logo-BG.svg"
                        alt="SOS Детски селища България"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/cocosolis-sos-gold-partners-2023.svg"
                        alt="Златен Партньор 2023"
                        className="h-8"
                    />
                </div>
                <p className="text-sm">
                    COCOSOLIS дарява по 1лв. от всеки закупен продукт на SOS детски селища.
                </p>
            </div>

            <div className="w-full bg-[#816c65] py-6 text-center text-white">
                <p className="text-lg mb-4">Гарантирано сигурно плащане с:</p>
                <div className="flex flex-wrap justify-center space-x-4">
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-visa.svg"
                        alt="Visa"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-mastercard.svg"
                        alt="Mastercard"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-discover.svg"
                        alt="Discover"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-paypal.svg"
                        alt="PayPal"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-amex.svg"
                        alt="American Express"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-gpay.svg"
                        alt="Google Pay"
                        className="h-8"
                    />
                    <img
                        src="https://cocosolis.com/wp-content/uploads/icon-payments-apple-pay.svg"
                        alt="Apple Pay"
                        className="h-8"
                    />
                </div>
            </div>

            <div className="w-full bg-[#816c65] border-t border-white py-10 px-4 text-white flex flex-col items-center">
                <div className="w-full max-w-5xl grid grid-cols-1 md:grid-cols-3 gap-8">
                    <div className="flex flex-col items-center md:items-start">
                        <h3 className="font-bold mb-4">Полезни връзки</h3>
                        <ul className="space-y-2 text-sm">
                            <li>Продукти</li>
                            <li>CLUB</li>
                            <li>Контакти</li>
                            <li>За нас</li>
                            <li>Правила за закупуване</li>
                            <li>Условия за ползване на сайта</li>
                            <li>Условия на Програмата за лоялност</li>
                            <li>Политика за бисквитки</li>
                            <li>Политика за връщане</li>
                            <li>Поръчка и доставка</li>
                            <li>Политика за защита на лични данни</li>
                        </ul>
                    </div>

                    <div className="flex flex-col items-center md:items-start">
                        <h3 className="font-bold mb-4">НЕКА БЪДЕМ ПРИЯТЕЛИ!</h3>
                        <p className="text-sm mb-4 text-center md:text-left">Абонирайте се, за да бъдете сред първите, които ще научат за нашите нови продукти и промоции:</p>
                        <input
                            type="email"
                            placeholder="твоят имейл адрес"
                            className="w-full px-4 py-2 mb-2 text-black"
                        />
                        <div className="flex items-start space-x-2 text-xs mb-4">
                            <input type="checkbox" />
                            <p>Съгласен/на съм предоставената от мен имейл да бъде използван, за да получавам известия за новости, подаръци и бъдещи промоции, свързани с продуктите COCOSOLIS, съгласно <a href="#" className="underline">Общите условия</a> и <a href="#" className="underline">Политика за личните данни</a>.</p>
                        </div>
                        <div className="w-full py-2 bg-[#daa48a] text-center text-[#816c65] cursor-pointer hover:bg-[#daa48a]">
                            ВЛЕЗ В КЛУБА
                        </div>
                    </div>

                    <div className="text-center md:text-left flex flex-col items-center md:items-start">
                        <h3 className="font-bold mb-4">Последвайте ни</h3>
                        <div className="flex justify-center md:justify-start space-x-4 mb-4">
                            <a href="#"><img src="https://cocosolis.com//wp-content/uploads/icon-social-media-facebook-footer-v0401.svg" alt="Facebook" className="h-6" /></a>
                            <a href="#"><img src="https://cocosolis.com//wp-content/uploads/icon-social-media-instagram-footer-v0401.svg" alt="Instagram" className="h-6" /></a>
                            <a href="#"><img src="https://cocosolis.com//wp-content/uploads/icon-social-media-tik-tok-footer-v0401.svg" alt="TikTok" className="h-6" /></a>
                        </div>
                        <p className="text-xs text-center md:text-left">Тагни ни и имa шанс да видиш своята снимка или видео в профила ни! #cocosolis</p>
                        <div className="mt-4">
                            <a href="#" className="flex items-center justify-center md:justify-start space-x-2">
                                <img src="https://adscout.io/images/logo/logo-circle.png" alt="AdScout" className="h-10" />
                                <span className="text-sm text-white">Препоръчай с AdScout</span>
                            </a>
                        </div>
                    </div>
                </div>
            </div>

            <div className="w-full bg-[#816c65] py-4 text-center text-white text-xs border-t border-white">
                <p>© 2016 - 2024 COCOSOLIS | All rights reserved</p>
            </div>
        </div>
    );
}

export default Footer;
