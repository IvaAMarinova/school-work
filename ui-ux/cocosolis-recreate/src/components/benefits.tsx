function Benefits() {
    return (
        <div className="flex flex-row items-center bg-[#f5d4c4]">
            <div className="w-1/2 p-8">
                <div className="space-y-6 ml-16">
                    <div className="flex items-start gap-4">
                        <div className="w-12 h-12 flex items-center justify-center rounded-full border-2 border-white bg-[#daa48a] p-2">
                            <img src="https://cocosolis.com/wp-content/uploads/icon-leaf-regular-white.svg" alt="Leaf Icon" className="w-8 h-8" />
                        </div>
                        <div>
                            <h3 className="text-lg font-semibold text-[#816c65]">Натурални и Био</h3>
                            <p className="text-[#816c65]">
                                Продуктите на COCOSOLIS са винаги натурални и създадени само с най-висококачествени био, студено пресовани масла.
                            </p>
                        </div>
                    </div>
                    <div className="flex items-start gap-4">
                        <div className="w-12 h-12 flex items-center justify-center rounded-full border-2 border-white bg-[#daa48a] p-2">
                            <img src="https://cocosolis.com/wp-content/uploads/icon-heart-solid-white.svg" alt="Heart Icon" className="w-8 h-8" />
                        </div>
                        <div>
                            <h3 className="text-lg font-semibold text-[#816c65]">Създадени с любов</h3>
                            <p className="text-[#816c65]">
                                Създадени с любов и уважение към хората и природата. Нежни към кожата. Притежаващи аромат, в който ще се влюбите.
                            </p>
                        </div>
                    </div>
                    <div className="flex items-start gap-4">
                        <div className="w-12 h-12 flex items-center justify-center rounded-full border-2 border-white bg-[#daa48a] p-2">
                            <img src="https://cocosolis.com/wp-content/uploads/icon-paw-solid-white.svg" alt="Paw Icon" className="w-8 h-8" />
                        </div>
                        <div>
                            <h3 className="text-lg font-semibold text-[#816c65]">С отношение</h3>
                            <p className="text-[#816c65]">
                                Без наличие на парабени, оцветители, минерални и синтетични масла и разбира се, без тестване върху животни.
                            </p>
                        </div>
                    </div>
                </div>
            </div>

            <div className="w-1/2">
                <img
                src="https://cocosolis.com/wp-content/uploads/home-benefits-image.jpg"
                alt="Product Image"
                className="w-screen h-[720px] object-cover"
                />
            </div>
        </div>
    );
}

export default Benefits;
