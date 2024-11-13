function SubscriptionForm() {
    return (
        <div className="bg-[#876258] p-6 text-start text-white">
            <div className="ml-20 mr-20">
                <h2 className="text-lg mb-4">
                    Нека бъдем приятели! Абонирайте се, за да бъдете сред първите, които ще научат за нашите нови продукти и промоции:
                </h2>
                <input
                    type="email"
                    placeholder="твоят имейл адрес"
                    className="w-full p-3 text-gray-900 mb-4"
                />
                <p className="text-sm mb-2">
                    Моля, поставете отметка в квадратчето по-долу, за да можете да се присъедините.
                </p>
                <div className="flex items-start justify-center mb-4">
                    <input type="checkbox" id="consent" className="mr-2" />
                    <label htmlFor="consent" className="text-sm">
                        Съгласен/на съм предоставеният от мен имейл да бъде използван, за да получавам известия за новости, подаръци и бъдещи промоции, свързани с продуктите COCOSOLIS, съгласно{' '}
                        <a href="#" className="underline text-white">Общите условия за ползване на сайта</a> и{' '}
                        <a href="#" className="underline text-white">Политика за личните данни</a>.*
                    </label>
                </div>
                <button
                    className="w-full bg-[#d1a895] text-[#876258] py-3 rounded text-lg font-semibold"
                    disabled
                >
                    ВЛЕЗ В КЛУБА
                </button>
            </div>
        </div>
    );
}

export default SubscriptionForm;
